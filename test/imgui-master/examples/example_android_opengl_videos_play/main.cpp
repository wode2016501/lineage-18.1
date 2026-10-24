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
#include <android/hardware_buffer.h>

#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <media/NdkMediaExtractor.h>
#include <media/NdkImageReader.h>
#include <media/NdkImage.h>

#include <media/AudioTrack.h>

#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>

#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"

using namespace android;

#ifndef GL_TEXTURE_EXTERNAL_OES
#define GL_TEXTURE_EXTERNAL_OES 0x8D65
#endif

#ifndef EGL_NATIVE_BUFFER_ANDROID
#define EGL_NATIVE_BUFFER_ANDROID 0x3140
#endif

// 全局函数指针类型
typedef void (*PFNGLEGLIMAGETARGETTEXTURE2DOESPROC)(GLenum target, void *image);
//typedef EGLClientBuffer (*PFNEGLGETNATIVECLIENTBUFFERANDROIDPROC)(AHardwareBuffer *buffer);

// ---- 全局状态 ----
int  win_width   = 1280;   // 窗口（ImGui 渲染目标）尺寸
int  win_height  = 720;
int  video_width  = 1280;  // 视频真实尺寸（探测后更新）
int  video_height = 720;
bool gIsPlaying = true;

EGLDisplay g_EglDisplay = EGL_NO_DISPLAY;
EGLSurface g_EglSurface = EGL_NO_SURFACE;
EGLContext g_EglContext = EGL_NO_CONTEXT;

AMediaCodec   *videoCodec   = nullptr;
AMediaCodec   *audioCodec   = nullptr;
AImageReader  *gImageReader = nullptr;
ANativeWindow *gReaderWindow = nullptr;

GLuint gOesTextureId   = 0;
GLuint gVideoTextureId = 0;
GLuint gBlitFboId      = 0;
GLuint gOesShaderProg  = 0;
GLuint gQuadVao        = 0;
GLuint gQuadVbo        = 0;

// ---- 着色器：在顶点阶段翻转 Y ----
const char *OES_VERTEX_SHADER = R"glsl(
#version 300 es
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoords;
out vec2 TexCoords;
void main() {
    // ImageReader 硬件 buffer 原点在左下；翻转 Y 让 gVideoTextureId 视觉正向
    TexCoords = vec2(aTexCoords.x, 1.0 - aTexCoords.y);
    gl_Position = vec4(aPos.x, aPos.y, 0.0, 1.0);
}
)glsl";

const char *OES_FRAGMENT_SHADER = R"glsl(
#version 300 es
#extension GL_OES_EGL_image_external_essl3 : require
precision mediump float;
out vec4 FragColor;
in  vec2 TexCoords;
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

struct AudioThreadArgs
{
    int fd;
    off_t fileSize;
    sp<AudioTrack> nativeAudioTrack;
};

// ================= 音频线程（修复 fd 泄漏） =================
void *audio_thread_func(void *arg)
{
    printf("[音频线程] 启动...\n");
    AudioThreadArgs *args = (AudioThreadArgs *)arg;

    int extractorFd = dup(args->fd);
    AMediaExtractor *audioExtractor = AMediaExtractor_new();
    AMediaExtractor_setDataSourceFd(audioExtractor, extractorFd, 0, args->fileSize);

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
        close(extractorFd);
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
                        AMediaCodec_queueInputBuffer(audioCodec, inIdx, 0, 0, 0,
                                                     AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
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
                    AMediaCodec_queueInputBuffer(audioCodec, inIdx, 0, 0, 0,
                                                 AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
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
                    args->nativeAudioTrack->write(pcmBuf + aInfo.offset, aInfo.size);
            }
            AMediaCodec_releaseOutputBuffer(audioCodec, outAIdx, false);
        }
    }
    AMediaExtractor_delete(audioExtractor);
    close(extractorFd);
    delete args;
    printf("[音频线程] 安全退出。\n");
    return nullptr;
}

// ================= 视频线程（修复 dup/lseek 混用） =================
void *video_decode_thread_func(void *arg)
{
    printf("[视频解码线程] 启动...\n");
    int srcFd = *(int *)arg;
    int fd = dup(srcFd);                       // 用独立 fd，避免影响主线程
    off_t fileSize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    AMediaExtractor *videoExtractor = AMediaExtractor_new();
    AMediaExtractor_setDataSourceFd(videoExtractor, fd, 0, fileSize);

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
                        AMediaCodec_queueInputBuffer(videoCodec, inIdx, 0, 0, 0,
                                                     AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
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
                    AMediaCodec_queueInputBuffer(videoCodec, inIdx, 0, 0, 0,
                                                 AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                videoInputEOS = true;
            }
        }

        ssize_t outVIdx = AMediaCodec_dequeueOutputBuffer(videoCodec, &vInfo, 1000);
        if (outVIdx >= 0)
        {
            if (vInfo.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM)
                videoOutputEOS = true;

            int64_t elapsedTimeUs = getNowUs() - startTimeUs;
            int64_t sleepTimeUs   = vInfo.presentationTimeUs - elapsedTimeUs;
            if (sleepTimeUs > 0)
                usleep(sleepTimeUs);

            AMediaCodec_releaseOutputBuffer(videoCodec, outVIdx, true);
        }
    }
    AMediaExtractor_delete(videoExtractor);
    close(fd);
    printf("[视频解码线程] 安全退出。\n");
    return nullptr;
}

// ================= 初始化纹理与 FBO =================
void initVideoTextures()
{
    // 1. OES 外部纹理
    glGenTextures(1, &gOesTextureId);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, gOesTextureId);
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // 2. 2D 目标纹理 —— 用真实视频尺寸
    glGenTextures(1, &gVideoTextureId);
    glBindTexture(GL_TEXTURE_2D, gVideoTextureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, video_width, video_height,
                 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // 3. FBO
    glGenFramebuffers(1, &gBlitFboId);
    glBindFramebuffer(GL_FRAMEBUFFER, gBlitFboId);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
                           GL_TEXTURE_2D, gVideoTextureId, 0);
    GLenum st = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (st != GL_FRAMEBUFFER_COMPLETE)
        printf("[FBO] INCOMPLETE: 0x%x\n", st);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    // 4. Shader
    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &OES_VERTEX_SHADER, NULL);
    glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &OES_FRAGMENT_SHADER, NULL);
    glCompileShader(fs);

    gOesShaderProg = glCreateProgram();
    glAttachShader(gOesShaderProg, vs);
    glAttachShader(gOesShaderProg, fs);
    glLinkProgram(gOesShaderProg);
    glDeleteShader(vs);
    glDeleteShader(fs);

    // 5. 全屏 quad
    float quadVertices[] = {
        -1.0f,  1.0f, 0.0f, 0.0f,
        -1.0f, -1.0f, 0.0f, 1.0f,
         1.0f, -1.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, 0.0f, 0.0f,
         1.0f, -1.0f, 1.0f, 1.0f,
         1.0f,  1.0f, 1.0f, 0.0f,
    };
    glGenVertexArrays(1, &gQuadVao);
    glGenBuffers(1, &gQuadVbo);
    glBindVertexArray(gQuadVao);
    glBindBuffer(GL_ARRAY_BUFFER, gQuadVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float),
                          (void *)(2 * sizeof(float)));
    glBindVertexArray(0);
}

// ============ 关键修复：EGLImage 建立 → OES → 2D 纹理 ============
void updateVideoTextureForImGui()
{
    if (gImageReader == nullptr) return;

    AImage *image = nullptr;
    media_status_t status = AImageReader_acquireLatestImage(gImageReader, &image);
    if (status != AMEDIA_OK || image == nullptr) return;

    AHardwareBuffer *hardwareBuffer = nullptr;
    AImage_getHardwareBuffer(image, &hardwareBuffer);
    if (hardwareBuffer == nullptr) { AImage_delete(image); return; }

    // 动态加载扩展
    // 用头文件里的 PFNEGLGETNATIVECLIENTBUFFERANDROIDPROC（不再自己 typedef）
    static PFNEGLGETNATIVECLIENTBUFFERANDROIDPROC eglGetNativeClientBufferANDROID =
        (PFNEGLGETNATIVECLIENTBUFFERANDROIDPROC)
            eglGetProcAddress("eglGetNativeClientBufferANDROID");
    static PFNGLEGLIMAGETARGETTEXTURE2DOESPROC glEGLImageTargetTexture2DOES =
        (PFNGLEGLIMAGETARGETTEXTURE2DOESPROC)
            eglGetProcAddress("glEGLImageTargetTexture2DOES");

    if (eglGetNativeClientBufferANDROID == nullptr ||
        glEGLImageTargetTexture2DOES == nullptr)
    {
        static bool warned = false;
        if (!warned) { printf("[GL] 扩展缺失: eglGetNativeClientBufferANDROID / glEGLImageTargetTexture2DOES\n"); warned = true; }
        AImage_delete(image); return;
    }

    // 🔧 修复 1：必须走 eglGetNativeClientBufferANDROID
    EGLClientBuffer clientBuffer = eglGetNativeClientBufferANDROID(hardwareBuffer);
    if (clientBuffer == nullptr)
    {
        static bool warned = false;
        if (!warned) { printf("[EGL] eglGetNativeClientBufferANDROID == nullptr\n"); warned = true; }
        AImage_delete(image); return;
    }

    // 🔧 修复 2：用 g_EglDisplay，不用 eglGetCurrentDisplay()
    const EGLint attrs[] = { EGL_NONE };
    // ✅ 修复：核心版 eglCreateImage 允许 attrs 传 nullptr（无额外属性）
EGLImage eglImage = eglCreateImage(g_EglDisplay, EGL_NO_CONTEXT,
                                   EGL_NATIVE_BUFFER_ANDROID, clientBuffer, nullptr);
    // 🔧 修复 3：检查结果
    if (eglImage == EGL_NO_IMAGE)
    {
        static bool warned = false;
        if (!warned) { printf("[EGL] eglCreateImage 失败: 0x%x\n", eglGetError()); warned = true; }
        AImage_delete(image); return;
    }

    GLint oldFbo;
    GLint oldView[4];
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &oldFbo);
    glGetIntegerv(GL_VIEWPORT, oldView);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, gOesTextureId);
    glEGLImageTargetTexture2DOES(GL_TEXTURE_EXTERNAL_OES, (void *)eglImage);

    glBindFramebuffer(GL_FRAMEBUFFER, gBlitFboId);
    glViewport(0, 0, video_width, video_height);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(gOesShaderProg);
    glUniform1i(glGetUniformLocation(gOesShaderProg, "uOesTexture"), 0);
    glBindVertexArray(gQuadVao);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, oldFbo);
    glViewport(oldView[0], oldView[1], oldView[2], oldView[3]);
    glUseProgram(0);

    eglDestroyImage(g_EglDisplay, eglImage);
    AImage_delete(image);
}

void Init(ANativeWindow *window)
{
    printf("[EGL] 初始化...\n");
    g_EglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    EGLint major, minor;
    eglInitialize(g_EglDisplay, &major, &minor);
    const EGLint configAttribs[] = {
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT,
        EGL_BLUE_SIZE, 8, EGL_GREEN_SIZE, 8, EGL_RED_SIZE, 8, EGL_ALPHA_SIZE, 8,
        EGL_DEPTH_SIZE, 16,
        EGL_NONE};
    EGLConfig config; EGLint numConfigs;
    eglChooseConfig(g_EglDisplay, configAttribs, &config, 1, &numConfigs);
    if (numConfigs == 0) { printf("[EGL] 未找到 config\n"); return; }

    EGLint format;
    eglGetConfigAttrib(g_EglDisplay, config, EGL_NATIVE_VISUAL_ID, &format);
    ANativeWindow_setBuffersGeometry(window, 0, 0, format);

    g_EglSurface = eglCreateWindowSurface(g_EglDisplay, config, window, nullptr);
    const EGLint contextAttribs[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
    g_EglContext = eglCreateContext(g_EglDisplay, config, EGL_NO_CONTEXT, contextAttribs);
    eglMakeCurrent(g_EglDisplay, g_EglSurface, g_EglSurface, g_EglContext);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplAndroid_Init(window);
    ImGui_ImplOpenGL3_Init("#version 300 es");
}

// ================= 主函数 =================
int main(int argc, char **argv)
{
    printf("--- Pure C++ Player Start ---\n");
    if (argc < 2) { fprintf(stderr, "[错误] 请指定视频文件路径\n"); return 1; }

    const char *video_path = argv[1];
    int fd = open(video_path, O_RDONLY);
    if (fd < 0) { fprintf(stderr, "[错误] 无法打开 %s\n", video_path); return 1; }
    off_t fileSize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    // ========== 阶段 A：先探测轨道，拿到真实分辨率 ==========
    AMediaFormat *videoFormat = nullptr;
    AMediaFormat *audioFormat = nullptr;
    int videoTrackIdx = -1, audioTrackIdx = -1;

    {
        AMediaExtractor *probe = AMediaExtractor_new();
        AMediaExtractor_setDataSourceFd(probe, dup(fd), 0, fileSize);
        int numTracks = AMediaExtractor_getTrackCount(probe);
        for (int i = 0; i < numTracks; i++)
        {
            AMediaFormat *fmt = AMediaExtractor_getTrackFormat(probe, i);
            const char *mime = nullptr;
            AMediaFormat_getString(fmt, AMEDIAFORMAT_KEY_MIME, &mime);
            if (mime != nullptr && strncmp(mime, "video/", 6) == 0 && videoTrackIdx == -1)
            {
                videoTrackIdx = i;
                videoFormat = fmt;
                int32_t w = 0, h = 0;
                AMediaFormat_getInt32(fmt, AMEDIAFORMAT_KEY_WIDTH,  &w);
                AMediaFormat_getInt32(fmt, AMEDIAFORMAT_KEY_HEIGHT, &h);
                if (w > 0 && h > 0) { video_width = w; video_height = h; }
                printf("[探测] 视频 %dx%d\n", video_width, video_height);
                videoCodec = AMediaCodec_createDecoderByType(mime);
            }
            else if (mime != nullptr && strncmp(mime, "audio/", 6) == 0 && audioTrackIdx == -1)
            {
                audioTrackIdx = i;
                audioFormat = fmt;
                audioCodec = AMediaCodec_createDecoderByType(mime);
            }
            else
            {
                AMediaFormat_delete(fmt);
            }
        }
        AMediaExtractor_delete(probe);
    }

    // ========== 阶段 B：创建 SurfaceFlinger 窗口 ==========
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    sp<SurfaceControl> surfaceControl = client->createSurface(
        String8("PureCpp720pWindow"), win_width, win_height, PIXEL_FORMAT_RGBA_8888, 0);
    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF)
     .setPosition(surfaceControl, 0, 200)
     .setSize(surfaceControl, win_width, win_height);
#ifdef layer_state_t
    t.setFlags(surfaceControl, 0, layer_state_t::eLayerOpaque);
#else
    t.setFlags(surfaceControl, 0, 0x02);
#endif
    t.show(surfaceControl).apply();
    ANativeWindow *window = surfaceControl->getSurface().get();
    if (window == nullptr) return -1;

    // ========== 阶段 C：EGL + 纹理 + ImageReader（用真实视频尺寸） ==========
    Init(window);
    initVideoTextures();

    media_status_t imgSt = AImageReader_newWithUsage(
        video_width, video_height, AIMAGE_FORMAT_PRIVATE,
        AHARDWAREBUFFER_USAGE_GPU_SAMPLED_IMAGE, 3, &gImageReader);
    if (imgSt != AMEDIA_OK || gImageReader == nullptr)
    {
        fprintf(stderr, "[错误] AImageReader 创建失败 (%d)\n", imgSt);
        return 1;
    }
    AImageReader_getWindow(gImageReader, &gReaderWindow);
    ANativeWindow_acquire(gReaderWindow);

    // ========== 阶段 D：配置 codec / AudioTrack ==========
    sp<AudioTrack> nativeAudioTrack = nullptr;

    if (videoCodec && videoFormat)
    {
        media_status_t cs = AMediaCodec_configure(videoCodec, videoFormat, gReaderWindow, NULL, 0);
        if (cs != AMEDIA_OK)
            printf("[错误] video codec configure 失败: %d\n", cs);
        AMediaFormat_delete(videoFormat);
    }

    if (audioCodec && audioFormat)
    {
        media_status_t cs = AMediaCodec_configure(audioCodec, audioFormat, NULL, NULL, 0);
        if (cs != AMEDIA_OK)
            printf("[错误] audio codec configure 失败: %d\n", cs);

        int32_t sampleRate = 44100, channelCount = 2;
        AMediaFormat_getInt32(audioFormat, AMEDIAFORMAT_KEY_SAMPLE_RATE,   &sampleRate);
        AMediaFormat_getInt32(audioFormat, AMEDIAFORMAT_KEY_CHANNEL_COUNT, &channelCount);
        audio_channel_mask_t mask = (channelCount == 1)
            ? AUDIO_CHANNEL_OUT_MONO : AUDIO_CHANNEL_OUT_STEREO;
        nativeAudioTrack = new AudioTrack(
            AUDIO_STREAM_MUSIC, (uint32_t)sampleRate, AUDIO_FORMAT_PCM_16_BIT,
            mask, 0, AUDIO_OUTPUT_FLAG_NONE, nullptr, nullptr, 0);
        if (nativeAudioTrack != nullptr && nativeAudioTrack->initCheck() == NO_ERROR)
            nativeAudioTrack->start();
        AMediaFormat_delete(audioFormat);
    }

    if (videoCodec) AMediaCodec_start(videoCodec);
    if (audioCodec) AMediaCodec_start(audioCodec);

    // ========== 阶段 E：启动后台线程 ==========
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
        pthread_create(&videoThread, nullptr, video_decode_thread_func, &fd);

    // ========== 阶段 F：ImGui 渲染循环 ==========
    bool running = true;
    while (running)
    {
        updateVideoTextureForImGui();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplAndroid_NewFrame();
        ImGui::NewFrame();

        ImGui::SetNextWindowPos(ImVec2(30, 30), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(640, 480), ImGuiCond_FirstUseEver);
        ImGui::Begin("SurfaceFlinger ImGui Player Window");

        ImGui::Text("Engine: %dx%d  Window: %dx%d",
                    video_width, video_height, win_width, win_height);

        if (gVideoTextureId != 0)
        {
            float aspect = (float)video_width / (float)video_height;
            ImVec2 imgSize(560.0f, 560.0f / aspect);
            ImGui::Image((ImTextureID)(intptr_t)gVideoTextureId, imgSize);
        }
        else
        {
            ImGui::Text("Loading video stream...");
        }

        if (ImGui::Button("Exit Video Player"))
            running = false;
        ImGui::End();

        ImGui::Render();
        glViewport(0, 0, win_width, win_height);
        glClearColor(0.1f, 0.1f, 0.1f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        eglSwapBuffers(g_EglDisplay, g_EglSurface);
        usleep(16666);
    }

    // ========== 阶段 G：清理 ==========
    gIsPlaying = false;
    if (audioCodec && nativeAudioTrack != nullptr) pthread_join(audioThread, nullptr);
    if (videoCodec) pthread_join(videoThread, nullptr);

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();
    ImGui::DestroyContext();

    if (videoCodec) { AMediaCodec_stop(videoCodec); AMediaCodec_delete(videoCodec); }
    if (audioCodec) { AMediaCodec_stop(audioCodec); AMediaCodec_delete(audioCodec); }
    if (nativeAudioTrack != nullptr) nativeAudioTrack->stop();

    if (gReaderWindow) ANativeWindow_release(gReaderWindow);
    if (gImageReader) AImageReader_delete(gImageReader);

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