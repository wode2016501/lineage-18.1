#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <limits.h>
#include <pthread.h>

#include <gui/SurfaceComposerClient.h>
#include <gui/Surface.h>
#include <ui/DisplayInfo.h>
#include <android/native_window.h>

// Android NDK 媒体库与图像结构
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <media/NdkMediaExtractor.h>
#include <media/NdkImageReader.h>
#include <media/NdkImage.h>

// 🚀 引入底层 C++ AudioTrack
#include <media/AudioTrack.h>

// OpenGL / EGL 核心头文件
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>

// ImGui 核心与后端
#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"

using namespace android;

// ---- 强制在全局补充底层缺少的所有扩展宏（彻底解决 Undeclared 报错） ----
#ifndef GL_TEXTURE_EXTERNAL_OES
#define GL_TEXTURE_EXTERNAL_OES 0x8D65
#endif

// 🚀 声明底层的函数指针类型（移到全局，防止在函数内声明 block 报错）
typedef void (*PFNGLEGLIMAGETARGETTEXTURE2DOESPROC)(GLenum target, void *image);

// ---- 全局配置与状态变量 ----
int win_width = 1280;
int win_height = 720;
bool gIsPlaying = true;

// EGL 环境全局变量
EGLDisplay g_EglDisplay = EGL_NO_DISPLAY;
EGLSurface g_EglSurface = EGL_NO_SURFACE;
EGLContext g_EglContext = EGL_NO_CONTEXT;

// 视频组件句柄
AMediaCodec *videoCodec = nullptr;
AMediaCodec *audioCodec = nullptr;
AImageReader *gImageReader = nullptr;
ANativeWindow *gReaderWindow = nullptr;

// 纹理、FBO 与 OES 转换着色器全局变量
GLuint gOesTextureId = 0;   // 接收 ImageReader 原始数据的 OES 外部纹理句柄
GLuint gVideoTextureId = 0; // 最终提供给 ImGui::Image 使用的标准常规 2D 纹理
GLuint gBlitFboId = 0;      // 转换使用的离屏帧缓冲区 (FBO)
GLuint gOesShaderProg = 0;  // 转换着色器程序
GLuint gQuadVao = 0;
GLuint gQuadVbo = 0;

// ---- 极简 OES 纹理中转着色器源码 ----
const char *OES_VERTEX_SHADER = R"glsl(
    #version 300 es
    layout (location = 0) in vec2 aPos;
    layout (location = 1) in vec2 aTexCoords;
    out vec2 TexCoords;
    void main() {
        TexCoords = aTexCoords;
        gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
    }
)glsl";

const char *OES_FRAGMENT_SHADER = R"glsl(
    #version 300 es
    #extension GL_OES_EGL_image_external_essl3 : require
    precision mediump float;
    out vec4 FragColor;
    in vec2 TexCoords;
    uniform samplerExternalOES uOesTexture;
    void main() {
        FragColor = texture(uOesTexture, TexCoords);
    }
)glsl";

int64_t getNowUs()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int64_t)tv.tv_sec * 1000000ll + tv.tv_usec;
}

// 音频线程参数传递结构体
struct AudioThreadArgs
{
    int fd;
    off_t fileSize;
    sp<AudioTrack> nativeAudioTrack;
};

// 🎵 音频独立后台线程：负责提取、解码与同步硬件写入播放
void *audio_thread_func(void *arg)
{
    printf("[音频线程] 启动...\n");
    AudioThreadArgs *args = (AudioThreadArgs *)arg;

    AMediaExtractor *audioExtractor = AMediaExtractor_new();
    AMediaExtractor_setDataSourceFd(audioExtractor, dup(args->fd), 0, args->fileSize);

    int audioTrackIdx = -1;
    int numTracks = AMediaExtractor_getTrackCount(audioExtractor);
    for (int i = 0; i < numTracks; i++)
    {
        AMediaFormat *trackFormat = AMediaExtractor_getTrackFormat(audioExtractor, i);
        const char *mime = nullptr;
        AMediaFormat_getString(trackFormat, AMEDIAFORMAT_KEY_MIME, &mime);
        if (mime != nullptr && strncmp(mime, "audio/", 6) == 0)
        {
            audioTrackIdx = i;
            AMediaExtractor_selectTrack(audioExtractor, i);
            AMediaFormat_delete(trackFormat);
            break;
        }
        AMediaFormat_delete(trackFormat);
    }

    if (audioTrackIdx == -1)
    {
        AMediaExtractor_delete(audioExtractor);
        delete args;
        return nullptr;
    }

    AMediaCodecBufferInfo aInfo;
    bool audioInputEOS = false;
    bool audioOutputEOS = false;

    while (gIsPlaying && !audioOutputEOS)
    {
        if (!audioInputEOS)
        {
            int activeTrack = AMediaExtractor_getSampleTrackIndex(audioExtractor);
            if (activeTrack == audioTrackIdx)
            {
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(audioCodec, 1000);
                if (inIdx >= 0)
                {
                    size_t bufSize;
                    uint8_t *buf = AMediaCodec_getInputBuffer(audioCodec, inIdx, &bufSize);
                    ssize_t sampleSize = AMediaExtractor_readSampleData(audioExtractor, buf, bufSize);
                    if (sampleSize < 0)
                    {
                        AMediaCodec_queueInputBuffer(audioCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                        audioInputEOS = true;
                    }
                    else
                    {
                        int64_t pts = AMediaExtractor_getSampleTime(audioExtractor);
                        AMediaCodec_queueInputBuffer(audioCodec, inIdx, 0, sampleSize, pts, 0);
                        AMediaExtractor_advance(audioExtractor);
                    }
                }
            }
            else if (activeTrack == -1)
            {
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(audioCodec, 1000);
                if (inIdx >= 0)
                    AMediaCodec_queueInputBuffer(audioCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                audioInputEOS = true;
            }
        }

        ssize_t outAIdx = AMediaCodec_dequeueOutputBuffer(audioCodec, &aInfo, 1000);
        if (outAIdx >= 0)
        {
            if (aInfo.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM)
                audioOutputEOS = true;
            if (aInfo.size > 0 && args->nativeAudioTrack != nullptr)
            {
                size_t outBufSize;
                uint8_t *pcmBuf = AMediaCodec_getOutputBuffer(audioCodec, outAIdx, &outBufSize);
                if (pcmBuf != nullptr)
                {
                    args->nativeAudioTrack->write(pcmBuf + aInfo.offset, aInfo.size);
                }
            }
            AMediaCodec_releaseOutputBuffer(audioCodec, outAIdx, false);
        }
    }
    AMediaExtractor_delete(audioExtractor);
    delete args;
    printf("[音频线程] 安全退出。\n");
    return nullptr;
}

// 📺 视频解码后台线程：负责提取、解码并根据 PTS 控制时间同步发送至 ImageReader
void *video_decode_thread_func(void *arg)
{
    printf("[视频解码线程] 启动...\n");
    int fd = *(int *)arg;
    off_t fileSize = lseek(fd, 0, SEEK_END);

    AMediaExtractor *videoExtractor = AMediaExtractor_new();
    AMediaExtractor_setDataSourceFd(videoExtractor, dup(fd), 0, fileSize);

    int videoTrackIdx = -1;
    int numTracks = AMediaExtractor_getTrackCount(videoExtractor);
    for (int i = 0; i < numTracks; i++)
    {
        AMediaFormat *trackFormat = AMediaExtractor_getTrackFormat(videoExtractor, i);
        const char *mime = nullptr;
        AMediaFormat_getString(trackFormat, AMEDIAFORMAT_KEY_MIME, &mime);
        if (mime != nullptr && strncmp(mime, "video/", 6) == 0)
        {
            videoTrackIdx = i;
            AMediaExtractor_selectTrack(videoExtractor, i);
            AMediaFormat_delete(trackFormat);
            break;
        }
        AMediaFormat_delete(trackFormat);
    }

    AMediaCodecBufferInfo vInfo;
    bool videoInputEOS = false;
    bool videoOutputEOS = false;
    int64_t startTimeUs = getNowUs();

    while (gIsPlaying && !videoOutputEOS)
    {
        if (!videoInputEOS)
        {
            int activeTrack = AMediaExtractor_getSampleTrackIndex(videoExtractor);
            if (activeTrack == videoTrackIdx)
            {
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(videoCodec, 1000);
                if (inIdx >= 0)
                {
                    size_t bufSize;
                    uint8_t *buf = AMediaCodec_getInputBuffer(videoCodec, inIdx, &bufSize);
                    ssize_t sampleSize = AMediaExtractor_readSampleData(videoExtractor, buf, bufSize);
                    if (sampleSize < 0)
                    {
                        AMediaCodec_queueInputBuffer(videoCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                        videoInputEOS = true;
                    }
                    else
                    {
                        int64_t pts = AMediaExtractor_getSampleTime(videoExtractor);
                        AMediaCodec_queueInputBuffer(videoCodec, inIdx, 0, sampleSize, pts, 0);
                        AMediaExtractor_advance(videoExtractor);
                    }
                }
            }
            else if (activeTrack == -1)
            {
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(videoCodec, 1000);
                if (inIdx >= 0)
                    AMediaCodec_queueInputBuffer(videoCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                videoInputEOS = true;
            }
        }

        ssize_t outVIdx = AMediaCodec_dequeueOutputBuffer(videoCodec, &vInfo, 1000);
        if (outVIdx >= 0)
        {
            if (vInfo.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM)
                videoOutputEOS = true;

            // 基于系统时间的简易音视频同步延迟
            int64_t elapsedTimeUs = getNowUs() - startTimeUs;
            int64_t sleepTimeUs = vInfo.presentationTimeUs - elapsedTimeUs;
            if (sleepTimeUs > 0)
                usleep(sleepTimeUs);

            // 冲入绑定的 AImageReader 窗口虚拟流
            AMediaCodec_releaseOutputBuffer(videoCodec, outVIdx, true);
        }
    }
    AMediaExtractor_delete(videoExtractor);
    printf("[视频解码线程] 安全退出。\n");
    return nullptr;
}

// 初始化 OpenGL 与 视频接收/转换 中间件
void initVideoTextures()
{
    // 1. 生成原始外部 OES 硬件纹理
    glGenTextures(1, &gOesTextureId);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, gOesTextureId);
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // 2. 生成供 ImGui 直接绘制的标准常规 2D 目标空纹理
    glGenTextures(1, &gVideoTextureId);
    glBindTexture(GL_TEXTURE_2D, gVideoTextureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, win_width, win_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // 3. 配置关联的帧缓冲区 FBO
    glGenFramebuffers(1, &gBlitFboId);
    glBindFramebuffer(GL_FRAMEBUFFER, gBlitFboId);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, gVideoTextureId, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    // 4. 实时编译底层中转 Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &OES_VERTEX_SHADER, NULL);
    glCompileShader(vertexShader);
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &OES_FRAGMENT_SHADER, NULL);
    glCompileShader(fragmentShader);
    gOesShaderProg = glCreateProgram();
    glAttachShader(gOesShaderProg, vertexShader);
    glAttachShader(gOesShaderProg, fragmentShader);
    glLinkProgram(gOesShaderProg);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    // 5. 组装全屏矩形画板顶点
    float quadVertices[] = {
        // 位置(x,y)   // 纹理坐标(s,t)
        -1.0f, 1.0f, 0.0f, 0.0f,  // 左上
        -1.0f, -1.0f, 0.0f, 1.0f, // 左下
        1.0f, -1.0f, 1.0f, 1.0f,  // 右下
        -1.0f, 1.0f, 0.0f, 0.0f,  // 左上
        1.0f, -1.0f, 1.0f, 1.0f,  // 右下
        1.0f, 1.0f, 1.0f, 0.0f    // 右上
    };
    glGenVertexArrays(1, &gQuadVao);
    glGenBuffers(1, &gQuadVbo);
    glBindVertexArray(gQuadVao);
    glBindBuffer(GL_ARRAY_BUFFER, gQuadVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)(2 * sizeof(float)));
    glBindVertexArray(0);
}
// 【主循环高频驱动】零拷贝提取 AImageReader 原始流，并通过 Shader 将画面安全抹写到 2D 纹理中
void updateVideoTextureForImGui()
{
    if (gImageReader == nullptr)
        return;
    AImage *image = nullptr;
    // 🚀 修复点 1：完全移除了由于网页拷贝产生的非法符号 'ℑ'，换回纯正的标准 ℑ 指针
    media_status_t status = AImageReader_acquireLatestImage(gImageReader, &image);
    if (status == AMEDIA_OK && image != nullptr)
    {
        AHardwareBuffer *hardwareBuffer = nullptr;
        AImage_getHardwareBuffer(image, &hardwareBuffer);
        if (hardwareBuffer != nullptr)
        {
            EGLDisplay eglDisplay = eglGetCurrentDisplay();
            EGLint attrs[] = {EGL_NONE};
            EGLImage eglImage = eglCreateImage(eglDisplay, EGL_NO_CONTEXT, EGL_NATIVE_BUFFER_ANDROID, (EGLClientBuffer)hardwareBuffer, nullptr);
            if (eglImage != EGL_NO_IMAGE)
            {
                // 🚀 修复点 2：将 glGetIntegerv 的第二个参数修正为数组指针（GLint oldView[4]），解决参数不匹配报错
                GLint oldFbo;
                GLint oldView[4];
                glGetIntegerv(GL_FRAMEBUFFER_BINDING, &oldFbo);
                glGetIntegerv(GL_VIEWPORT, oldView);
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_EXTERNAL_OES, gOesTextureId);
                // 🚀 修复点 3：重写了内建块作用域中的扩展加载语法，使用全局声明的 PFNGLEGLIMAGETARGETTEXTURE2DOESPROC 类型转义
                static PFNGLEGLIMAGETARGETTEXTURE2DOESPROC glEGLImageTargetTexture2DOES =
                    (PFNGLEGLIMAGETARGETTEXTURE2DOESPROC)eglGetProcAddress("glEGLImageTargetTexture2DOES");
                if (glEGLImageTargetTexture2DOES != nullptr)
                {
                    glEGLImageTargetTexture2DOES(GL_TEXTURE_EXTERNAL_OES, (void *)eglImage);
                }
                // 让 GPU 把 OES 外部纹理作为源画到 FBO 绑定的 2D 目标纹理上
                glBindFramebuffer(GL_FRAMEBUFFER, gBlitFboId);
                glViewport(0, 0, win_width, win_height);
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                glUseProgram(gOesShaderProg);
                glUniform1i(glGetUniformLocation(gOesShaderProg, "uOesTexture"), 0);
                glBindVertexArray(gQuadVao);
                glDrawArrays(GL_TRIANGLES, 0, 6);
                // 完整回复现场状态，确保 ImGui 自身状态机不受破坏
                glBindVertexArray(0);
                glBindTexture(GL_TEXTURE_EXTERNAL_OES, 0);
                glBindFramebuffer(GL_FRAMEBUFFER, oldFbo);
                glViewport(oldView[0], oldView[1], oldView[2], oldView[3]);
                eglDestroyImage(eglDisplay, eglImage);
            }
        }
        AImage_delete(image);
    }
}
// 真正实现 Init 函数以建立完整的 OpenGL 渲染器
void Init(ANativeWindow *window)
{
    printf("[EGL] 初始化 Native OpenGL 上下文环境...\n");
    g_EglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    EGLint major, minor;
    eglInitialize(g_EglDisplay, &major, &minor);
    const EGLint configAttribs[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_BLUE_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_RED_SIZE, 8, EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE};
    EGLConfig config;
    EGLint numConfigs;
    eglChooseConfig(g_EglDisplay, configAttribs, &config, 1, &numConfigs);
    EGLint format;
    eglGetConfigAttrib(g_EglDisplay, config, EGL_NATIVE_VISUAL_ID, &format);
    ANativeWindow_setBuffersGeometry(window, 0, 0, format);
    g_EglSurface = eglCreateWindowSurface(g_EglDisplay, config, window, nullptr);
    const EGLint contextAttribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
    g_EglContext = eglCreateContext(g_EglDisplay, config, EGL_NO_CONTEXT, contextAttribs);
    eglMakeCurrent(g_EglDisplay, g_EglSurface, g_EglSurface, g_EglContext);
    printf("[EGL] OpenGL ES 3.0 跑通。开始接驳 ImGui...\n");
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplAndroid_Init(window);
    ImGui_ImplOpenGL3_Init("#version 300 es");
    printf("[ImGui] 初始化完毕。\n");
}
int main(int argc, char **argv)
{
    printf("--- Pure C++ Player with ImGui Embedded Start ---\n");
    if (argc < 2)
    {
        fprintf(stderr, "[错误] 请指定视频文件路径！\n");
        return 1;
    }
    const char *video_path = argv[1];
    int fd = open(video_path, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "[错误] 无法打开指定视频: %s\n", video_path);
        return 1;
    }
    off_t fileSize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    // 1. 初始化 SurfaceFlinger 720p 窗口
    sp client = new SurfaceComposerClient();
    uint32_t flags = 0;
    sp surfaceControl = client->createSurface(String8("PureCpp720pWindow"), win_width, win_height, PIXEL_FORMAT_RGBA_8888, flags);
    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF).setPosition(surfaceControl, 0, 200).setSize(surfaceControl, win_width, win_height);
#ifdef layer_state_t
    t.setFlags(surfaceControl, 0, layer_state_t::eLayerOpaque);
#else
    t.setFlags(surfaceControl, 0, 0x02);
#endif
    t.show(surfaceControl).apply();
    ANativeWindow *window = surfaceControl->getSurface().get();
    if (window == nullptr)
        return -1;
    // 2. 挂载 EGL 与底层中间绘制组件
    Init(window);
    initVideoTextures();
    // 3. 构建 hardware 级高效率 AImageReader 采集介质
    media_status_t imgReaderStatus = AImageReader_newWithUsage(
        win_width, win_height, AIMAGE_FORMAT_PRIVATE,
        AHARDWAREBUFFER_USAGE_GPU_SAMPLED_IMAGE, 3, &gImageReader);
    if (imgReaderStatus == AMEDIA_OK && gImageReader != nullptr)
    {
        AImageReader_getWindow(gImageReader, &gReaderWindow);
    }
    else
    {
        fprintf(stderr, "[错误] 无法顺利构建 AImageReader\n");
        return 1;
    }
    // 探测并绑定音视频轨道
    AMediaExtractor *extractor = AMediaExtractor_new();
    AMediaExtractor_setDataSourceFd(extractor, fd, 0, fileSize);
    // 🚀 修复点 4：强制显式声明 sp 的模板参数类型，彻底解决 sp 无法自动推导的链接阻碍
    sp<AudioTrack> nativeAudioTrack = nullptr; //  正确形式

    int videoTrackIdx = -1;
    int audioTrackIdx = -1;
    int numTracks = AMediaExtractor_getTrackCount(extractor);
    for (int i = 0; i < numTracks; i++)
    {
        AMediaFormat *trackFormat = AMediaExtractor_getTrackFormat(extractor, i);
        const char *mime = nullptr;
        AMediaFormat_getString(trackFormat, AMEDIAFORMAT_KEY_MIME, &mime);
        if (mime != nullptr)
        {
            if (strncmp(mime, "video/", 6) == 0 && videoTrackIdx == -1)
            {
                videoTrackIdx = i;
                videoCodec = AMediaCodec_createDecoderByType(mime);
                AMediaCodec_configure(videoCodec, trackFormat, gReaderWindow, NULL, 0);
            }
            else if (strncmp(mime, "audio/", 6) == 0 && audioTrackIdx == -1)
            {
                audioTrackIdx = i;
                audioCodec = AMediaCodec_createDecoderByType(mime);
                AMediaCodec_configure(audioCodec, trackFormat, NULL, NULL, 0);
                int32_t sampleRate = 44100;
                int32_t channelCount = 2;
                AMediaFormat_getInt32(trackFormat, AMEDIAFORMAT_KEY_SAMPLE_RATE, &sampleRate);
                AMediaFormat_getInt32(trackFormat, AMEDIAFORMAT_KEY_CHANNEL_COUNT, &channelCount);
                audio_channel_mask_t channelMask = (channelCount == 1) ? AUDIO_CHANNEL_OUT_MONO : AUDIO_CHANNEL_OUT_STEREO;
                nativeAudioTrack = new AudioTrack(AUDIO_STREAM_MUSIC, (uint32_t)sampleRate, AUDIO_FORMAT_PCM_16_BIT, channelMask, 0, AUDIO_OUTPUT_FLAG_NONE, nullptr, nullptr, 0);
                if (nativeAudioTrack != nullptr && nativeAudioTrack->initCheck() == NO_ERROR)
                {
                    nativeAudioTrack->start();
                }
            }
        }
        AMediaFormat_delete(trackFormat);
    }
    AMediaExtractor_delete(extractor);
    if (videoCodec)
        AMediaCodec_start(videoCodec);
    if (audioCodec)
        AMediaCodec_start(audioCodec);
    // 🚀 开启后台解码线程
    pthread_t audioThread, videoThread;
    if (audioCodec && nativeAudioTrack != nullptr)
    {
        AudioThreadArgs *aArgs = new AudioThreadArgs();
        aArgs->fd = fd;
        aArgs->fileSize = fileSize;
        aArgs->nativeAudioTrack = nativeAudioTrack;
        pthread_create(&audioThread, nullptr, audio_thread_func, aArgs);
    }
    if (videoCodec)
    {
        pthread_create(&videoThread, nullptr, video_decode_thread_func, &fd);
    }
    // 4. 主 UI 渲染循环
    bool running = true;
    while (running)
    {
        // 渲染前通过中转着色器更新 2D 纹理画面
        updateVideoTextureForImGui();
        // 建立 ImGui 环境
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplAndroid_NewFrame();
        ImGui::NewFrame();
        ImGui::SetNextWindowPos(ImVec2(30, 30), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(640, 480), ImGuiCond_FirstUseEver);
        ImGui::Begin("SurfaceFlinger ImGui Player Window");
        ImGui::Text("Player Engine Status: Accelerated GPU Zero-Copy Active.");
        // 将标准 2D 目标纹理直接投射到 ImGui 内部窗口中
        if (gVideoTextureId != 0)
        {
            ImGui::Image((ImTextureID)(intptr_t)gVideoTextureId, ImVec2(560, 315));
        }
        else
        {
            ImGui::Text("Loading video stream...");
        }
        if (ImGui::Button("Exit Video Player"))
        {
            running = false;
        }
        ImGui::End();
        // 收集渲染顶点并清屏
        ImGui::Render();
        glViewport(0, 0, win_width, win_height);
        glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // 刷新至当前渲染缓冲管线
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        // 双缓冲区物理显示交换
        eglSwapBuffers(g_EglDisplay, g_EglSurface);
        // 60Hz 帧率限制保护
        usleep(16666);
    }
    // 5. 完善的各组件释放收尾
    gIsPlaying = false;
    if (audioCodec && nativeAudioTrack != nullptr)
        pthread_join(audioThread, nullptr);
    if (videoCodec)
        pthread_join(videoThread, nullptr);
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();
    ImGui::DestroyContext();
    if (videoCodec)
    {
        AMediaCodec_stop(videoCodec);
        AMediaCodec_delete(videoCodec);
    }
    if (audioCodec)
    {
        AMediaCodec_stop(audioCodec);
        AMediaCodec_delete(audioCodec);
    }
    if (nativeAudioTrack != nullptr)
        nativeAudioTrack->stop();
    if (gImageReader)
        AImageReader_delete(gImageReader);
    glDeleteTextures(1, &gOesTextureId);
    glDeleteTextures(1, &gVideoTextureId);
    glDeleteFramebuffers(1, &gBlitFboId);
    glDeleteProgram(gOesShaderProg);
    glDeleteVertexArrays(1, &gQuadVao);
    glDeleteBuffers(1, &gQuadVbo);
    close(fd);
    if (g_EglDisplay != EGL_NO_DISPLAY)
    {
        eglMakeCurrent(g_EglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        eglDestroyContext(g_EglDisplay, g_EglContext);
        eglDestroySurface(g_EglDisplay, g_EglSurface);
        eglTerminate(g_EglDisplay);
    }
    printf("--- Player Engine Shutdown Success. ---\n");
    return 0;
}