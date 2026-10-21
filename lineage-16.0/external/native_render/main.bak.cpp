
#include <stdio.h>
#include <unistd.h>
#include <gui/Surface.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/ISurfaceComposer.h>
#include <ui/DisplayInfo.h>
// 引入 NDK 相机核心头文件
#include <camera/NdkCameraManager.h>
#include <camera/NdkCameraDevice.h>
#include <camera/NdkCameraCaptureSession.h>

// 引入 NDK 硬编码与媒体混流器头文件
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <media/NdkMediaMuxer.h>


#include <gui/SurfaceComposerClient.h>
#include <gui/ISurfaceComposer.h>
#include <ui/Rect.h>
#include <binder/ProcessState.h>






#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>

// 引入 AAudio 音频采集头文件
#include <aaudio/AAudio.h>
// 引入原有的 NDK 头文件
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <media/NdkMediaMuxer.h>

// [新增] 音频相关的全局变量
AMediaCodec* audio_encoder = nullptr;
AAudioStream* audio_stream = nullptr;
ssize_t audioTrackIndex = -1;
ssize_t videoTrackIndex = -1; // 原来的 trackIndex 变更为 videoTrackIndex

// 确保音视频两个轨道都添加完毕后才启动 Muxer 的控制变量
bool videoTrackAdded = false;
bool audioTrackAdded = false;
bool muxerStarted = false;

// 保持原有的信号和全局变量不变...
extern AMediaMuxer* muxer;
extern AMediaCodec* encoder; // 视频编码器
extern int running;

// ====================================================
// 🎯 [新增步骤] 初始化音频编码器 (AAC)
// ====================================================
bool initAudioEncoder(int sampleRate, int channelCount, int bitrate) {
    AMediaFormat* audioFormat = AMediaFormat_new();
    AMediaFormat_setString(audioFormat, AMEDIAFORMAT_KEY_MIME, "audio/mp4a-latm"); // AAC 编码
    AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_SAMPLE_RATE, sampleRate);
    AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_CHANNEL_COUNT, channelCount);
    AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_BIT_RATE, bitrate);
    // AAC-LC 规格对应 2
    AMediaFormat_setInt32(audioFormat, "aac-profile", 2); 

    audio_encoder = AMediaCodec_createEncoderByType("audio/mp4a-latm");
    if (!audio_encoder) {
        printf("错误: 无法创建音频 AAC 编码器\n");
        return false;
    }

    media_status_t status = AMediaCodec_configure(audio_encoder, audioFormat, nullptr, nullptr, AMEDIACODEC_CONFIGURE_FLAG_ENCODE);
    AMediaFormat_delete(audioFormat);

    if (status != AMEDIA_OK) {
        printf("错误: 音频编码器配置失败!\n");
        return false;
    }

    AMediaCodec_start(audio_encoder);
    return true;
}

// ====================================================
// 🎯 [新增步骤] 初始化 AAudio 麦克风录制流
// ====================================================
bool initAAudio(int sampleRate, int channelCount) {
    AAudioStreamBuilder* builder = nullptr;
    aaudio_result_t result = AAudio_createStreamBuilder(&builder);
    if (result != AAUDIO_OK) return false;

    // 配置为麦克风输入流
    AAudioStreamBuilder_setDirection(builder, AAUDIO_DIRECTION_INPUT);
    AAudioStreamBuilder_setSampleRate(builder, sampleRate);
    AAudioStreamBuilder_setChannelCount(builder, channelCount);
    // 使用 16位 PCM 采样格式
    AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_I16);
    // 录音通常采用语音唤醒或录音机源
    AAudioStreamBuilder_setInputPreset(builder, AAUDIO_INPUT_PRESET_VOICE_RECOGNITION);

    result = AAudioStreamBuilder_openStream(builder, &audio_stream);
    AAudioStreamBuilder_delete(builder);

    if (result != AAUDIO_OK) {
        printf("错误: 无法打开 AAudio 麦克风流! 错误码: %d\n", result);
        return false;
    }

    // 启动音频硬件采集
    result = AAudioStream_requestStart(audio_stream);
    return result == AAUDIO_OK;
}

// ====================================================
// 🎯 [新增步骤] 独立的音频采集与硬编码异步线程
// ====================================================
void* audio_polling_thread(void* /*arg*/) {
    printf("[Audio Thread] Pipeline active. Capturing Microphone...\n");
    
    const int SAMPLES_PER_FRAME = 1024;
    int channelCount = 1;
    int bufferSizeSamples = SAMPLES_PER_FRAME * channelCount;
    int16_t* pcmBuffer = new int16_t[bufferSizeSamples];

    while (running) {
        int64_t timeoutNanoseconds = 20 * 1000000; 
        aaudio_result_t framesRead = AAudioStream_read(audio_stream, pcmBuffer, SAMPLES_PER_FRAME, timeoutNanoseconds);

        if (framesRead < 0) {
            usleep(10000);
            continue;
        }

        if (framesRead > 0) {
            ssize_t inputBufIdx = AMediaCodec_dequeueInputBuffer(audio_encoder, 10000);
            if (inputBufIdx >= 0) {
                size_t bufSize;
                uint8_t* codecInputBuf = AMediaCodec_getInputBuffer(audio_encoder, inputBufIdx, &bufSize);
                
                int bytesToCopy = framesRead * channelCount * sizeof(int16_t);
                if (bytesToCopy > (int)bufSize) bytesToCopy = bufSize;

                memcpy(codecInputBuf, pcmBuffer, bytesToCopy);

                 //【核心修改】：直接获取系统当前单调时钟的高精度时间戳（微秒）
                struct timespec ts;
                clock_gettime(CLOCK_MONOTONIC, &ts);
                int64_t currentPtsUs = (int64_t)ts.tv_sec * 1000000LL + (int64_t)ts.tv_nsec / 1000LL;

                AMediaCodec_queueInputBuffer(audio_encoder, inputBufIdx, 0, bytesToCopy, currentPtsUs, 0);
            }
        }
    }

    // 结束流
    ssize_t inputBufIdx = AMediaCodec_dequeueInputBuffer(audio_encoder, 10000);
    if (inputBufIdx >= 0) {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        int64_t currentPtsUs = (int64_t)ts.tv_sec * 1000000LL + (int64_t)ts.tv_nsec / 1000LL;
        AMediaCodec_queueInputBuffer(audio_encoder, inputBufIdx, 0, 0, currentPtsUs, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
    }

    delete[] pcmBuffer;
    printf("[Audio Thread] Exited safely.\n");
    return nullptr;
}







AMediaMuxer* muxer=0;
AMediaCodec* encoder=0;
int running=1;
void sigal_handler(int )
{
    printf("sigal_handler\n");
    running = 0;
}

using namespace android;

// 定义全局状态监听变量，用于拦截底层驱动事件
ACameraDevice* g_cameraDevice = nullptr;
ACameraCaptureSession* g_captureSession = nullptr;
bool g_sessionActive = false;

// ==========================================
// 🎯 终极绝杀：直接注销掉变量名，只留类型（如 void*，不写 context）
// ==========================================
void onDeviceDisconnected(void* /*context*/, ACameraDevice* /*device*/) { 
    printf("Camera Disconnected!\n"); 
}

void onDeviceError(void* /*context*/, ACameraDevice* /*device*/, int error) { 
    printf("Camera Error: %d\n", error); // error 被使用了，所以保留名字
}

ACameraDevice_StateCallbacks cameraDeviceCallbacks = { nullptr, onDeviceDisconnected, onDeviceError };

void onSessionActive(void* /*context*/, ACameraCaptureSession* /*session*/) { 
    g_sessionActive = true; 
    printf("Capture Session Active!\n"); 
}

void onSessionReady(void* /*context*/, ACameraCaptureSession* /*session*/) {}

void onSessionClosed(void* /*context*/, ACameraCaptureSession* /*session*/) {}

ACameraCaptureSession_stateCallbacks sessionCallbacks = { nullptr, onSessionClosed, onSessionReady, onSessionActive };


void* sh_thread(void* arg) {
    const char  *shfile=( const char *)arg;
    char cmd[1255];
    sprintf(cmd,"sh %s",shfile);
    system(cmd);
    running=0;
    return NULL;
}

// ... 后面 main() 函数逻辑保持原封不动 ...
int main(int argc,char **argv) {
    const char  *sh_file=NULL;//"/sdcard/status.sh"
   const char  *file="/sdcard/native_record.mp4";
       int bitrate = 2000000; // 对应命令行输入的 2M 码率
           int width = 1920;
    int height = 1080;
     if(argc >1)
        file=argv[1];
        if(argc >2)
         bitrate=atoi(argv[2]);
                if(argc >3)
         sh_file=argv[3];
   // int64_t g_first_pts_us = -1; // 自动记录第一帧的绝对时间基准
    if( bitrate<100000)
    bitrate = 2000000; 
    if(argc >1&&strstr(argv[1],"-h")){
      printf("%s [file.mp4] [bitrate: 默认:2000000] [file.sh 测试空间大小 电压。。 返回退出]\n",argv[0]);
      return 0;
    }
        int fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if(fd<0){
        printf("创建文件`%s`错误: %s (errno=%d)\n", file, strerror(errno), errno);
        return fd;
    }
    if(sh_file){
         pthread_t shThread;
         pthread_create(&shThread, nullptr, sh_thread, (void *)sh_file);
    }

        // ----------------------------------------------------
    // 阶段二（补充）：初始化音频硬编码器和 AAudio 驱动
    // ----------------------------------------------------
    int audioSampleRate = 44100;
    int audioChannels = 1; // 单声道录音
    int audioBitrate = 64000; // 64kbps AAC 足够清晰

    if (!initAudioEncoder(audioSampleRate, audioChannels, audioBitrate) ||
        !initAAudio(audioSampleRate, audioChannels)) {
        printf("音频链路组装失败，将退回纯视频录制模式！\n");
    }

    printf("[Native Commandline Recorder] Booting... [Android 9/LineageOS 16]\n保存文件： %s\n",file);
     
    signal(SIGINT, sigal_handler);

    // ----------------------------------------------------
    // 阶段一：向 SurfaceFlinger 强行索要用于显示的预览窗口
    // ----------------------------------------------------
    
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    if(client ==NULL){
        fprintf(stderr,"错误1\n");
        return 1;
    }
    
    client->initCheck();
    sp<IBinder> dtoken = SurfaceComposerClient::getBuiltInDisplay(ISurfaceComposer::eDisplayIdMain);
    DisplayInfo dinfo;
    SurfaceComposerClient::getDisplayInfo(dtoken, &dinfo);

    // 创建一半屏幕大小的相机底层悬浮预览窗
    sp<SurfaceControl> surfaceControl = client->createSurface(String8("CameraNativePreview"), width/2 , height/2 , PIXEL_FORMAT_RGBA_8888, 0);
    if(surfaceControl ==NULL){
        fprintf(stderr,"错误2\n");
        return 1;
    }
    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF).setPosition(surfaceControl, 0, 1440 - height/2).setAlpha(surfaceControl, 0.6f) .show(surfaceControl).apply();
    
    // 拿到可供 NDK 注入预览的总线窗口指针
    sp<Surface> previewSurface = surfaceControl->getSurface();
        if( previewSurface ==NULL){
        fprintf(stderr,"错误3\n");
        return 1;
    }
    ANativeWindow* previewWindow = previewSurface.get();
        if( previewWindow ==NULL){
        fprintf(stderr,"错误4\n");
        return 1;
    }
    // ----------------------------------------------------
    // 阶段二：配置高通硬编码器 (MediaCodec) 以及封装器 (Muxer)
    // ----------------------------------------------------



    AMediaFormat* format = AMediaFormat_new();
    AMediaFormat_setString(format, AMEDIAFORMAT_KEY_MIME, "video/avc"); // H.264
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_WIDTH, width);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_HEIGHT, height);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_BIT_RATE, bitrate);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_FRAME_RATE, 30);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_I_FRAME_INTERVAL, 1);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_COLOR_FORMAT, 0x7F000100); // COLOR_FormatSurface 硬件通道
    // 找到你的阶段二 AMediaFormat 配置位置，补上/修正这两行：
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_COLOR_FORMAT, 2130708361); // 2130708361 对应 COLOR_FormatSurface 物理常数
    
    // 🎯 [核心补充] 显式告诉高通驱动：这是一个专供底层硬件直接注入（而不是 CPU 写入）的硬编流
    AMediaFormat_setInt32(format, "android.generic.index", 1); 

    // 注入你要求的特殊编码层级
    AMediaFormat_setInt32(format, "profile", 8);       // Profile=8 (High Profile)
    AMediaFormat_setInt32(format, "level", 65536);     // Level=65536 (Level 5.1)

     encoder = AMediaCodec_createEncoderByType("video/avc");
    int ret=AMediaCodec_configure(encoder, format, nullptr, nullptr, AMEDIACODEC_CONFIGURE_FLAG_ENCODE);
  if (ret != AMEDIA_OK) {
    printf("错误 AMediaCodec_configure");
  }
    // 极其关键：获取硬编码器的输入 Surface 句柄，用于直接丢给相机 HAL
    ANativeWindow* encoderWindow = nullptr;
    AMediaCodec_createInputSurface(encoder, &encoderWindow);

    // 准备录像输出的 MP4 容器

    muxer = AMediaMuxer_new(fd, AMEDIAMUXER_OUTPUT_FORMAT_MPEG_4);

    // 启动编码器
    AMediaCodec_start(encoder);
   
    // ----------------------------------------------------
    // 阶段三：调用 NDK Camera2 打通底层硬件通道
    // ----------------------------------------------------
    ACameraManager* cameraManager = ACameraManager_create();
    
    // 打开 0 号后置摄像头
    camera_status_t status1=
    ACameraManager_openCamera(cameraManager, "0", &cameraDeviceCallbacks, &g_cameraDevice);
if (status1 != ACAMERA_OK) {
    printf("打开失败\n");
}
    // 创建相机的双路输出容器
    ACaptureSessionOutputContainer* outputContainer = nullptr;
    ACaptureSessionOutputContainer_create(&outputContainer);

    // 绑定第一路：屏幕预览流
    ACaptureSessionOutput* previewOutput = nullptr;
    ACaptureSessionOutput_create(previewWindow, &previewOutput);
    ACaptureSessionOutputContainer_add(outputContainer, previewOutput);

    // 绑定第二路：录制硬编流
    ACaptureSessionOutput* recordingOutput = nullptr;
    ACaptureSessionOutput_create(encoderWindow, &recordingOutput);
    ACaptureSessionOutputContainer_add(outputContainer, recordingOutput);

    // 创建捕获会话并激发会话
    ACameraDevice_createCaptureSession(g_cameraDevice, outputContainer, &sessionCallbacks, &g_captureSession);

    // 构建持续捕获请求 (RECORD 录像模板)
    ACaptureRequest* captureRequest = nullptr;
    ACameraDevice_createCaptureRequest(g_cameraDevice, TEMPLATE_RECORD, &captureRequest);

    // 明确捕获目标地址
    ACameraOutputTarget* previewTarget = nullptr;
    ACameraOutputTarget_create(previewWindow, &previewTarget);
    ACaptureRequest_addTarget(captureRequest, previewTarget);

    ACameraOutputTarget* recordingTarget = nullptr;
    ACameraOutputTarget_create(encoderWindow, &recordingTarget);
    int32_t fpsRange[2] = {30, 30};
ACaptureRequest_setEntry_i32(captureRequest, 
    ACAMERA_CONTROL_AE_TARGET_FPS_RANGE, 2, fpsRange);
    ACaptureRequest_addTarget(captureRequest, recordingTarget);

    // 让高通 ISP 管道全速循环运转
    ACameraCaptureSession_setRepeatingRequest(g_captureSession, nullptr, 1, &captureRequest, nullptr);

    printf("Camera pipeline coupled! Recording and Previewing for 10 seconds...\n");

    // ----------------------------------------------------
    // 阶段四：底层的音视频多路异步复用抽离循环 (Muxer loop)
    // ----------------------------------------------------
      // ----------------------------------------------------
    // 阶段四：【终极重构】高通底层硬编数据高频无损抽离循环
    // ----------------------------------------------------
       // ----------------------------------------------------
    // 阶段四：【透视重构】高通底层状态全裸露与时间硬控循环
    // ----------------------------------------------------
        // ----------------------------------------------------
    // 阶段四：【完美修复版】高通底层状态精准拦截与逃逸循环
    // ----------------------------------------------------
   // ssize_t trackIndex = -1;
        // ----------------------------------------------------
    // 阶段四：【多流合一】音视频高低频硬件混合复用循环
    // ----------------------------------------------------
    pthread_t audioThread;
    pthread_create(&audioThread, nullptr, audio_polling_thread, nullptr);
        // ----------------------------------------------------
    // 阶段四：【多流合一】全自动时间戳对齐归零合并循环
    // ----------------------------------------------------
    AMediaCodecBufferInfo v_info;
    AMediaCodecBufferInfo a_info;

    printf("Dual-pipeline Muxer Loop pulling engaged! Monitoring Video & Audio...\n");

    while (running) {


        // ==========================================
        // 2. 消费 Camera2 视频硬编码器输出的 H.264 数据帧
        // ==========================================
        ssize_t v_status = AMediaCodec_dequeueOutputBuffer(encoder, &v_info,20000);
        if (v_status >= 0) {
            size_t size;
            uint8_t* buffer = AMediaCodec_getOutputBuffer(encoder, v_status, &size);
           /* if (v_info.flags & AMEDIACODEC_BUFFER_FLAG_CODEC_CONFIG) {
    // 配置帧，跳过，不写入 muxer
    AMediaCodec_releaseOutputBuffer(encoder, v_status, false);
    continue;
}*/
            if (muxerStarted && videoTrackIndex >= 0 && v_info.size > 0) {
                AMediaMuxer_writeSampleData(muxer, videoTrackIndex, buffer, &v_info);
            }
            AMediaCodec_releaseOutputBuffer(encoder, v_status, false);
        } 
        else if (v_status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
            if (!videoTrackAdded) {
                AMediaFormat* format = AMediaCodec_getOutputFormat(encoder);
                videoTrackIndex = AMediaMuxer_addTrack(muxer, format);
                videoTrackAdded = true;
                AMediaFormat_delete(format);
                printf("[Muxer] Video Track Added via FORMAT_CHANGED.\n");
                if (audioTrackAdded && !muxerStarted) {
                    AMediaMuxer_start(muxer);
                    muxerStarted = true;
                    printf("[Muxer] Both Tracks Armed! Muxer started safely.\n");
                }
            }
        }
                // ==========================================
        // 1. 消费音频硬编码器输出的 AAC 数据帧
        // ==========================================
        ssize_t a_status = AMediaCodec_dequeueOutputBuffer(audio_encoder, &a_info, 20000);
        if (a_status >= 0) {
            size_t size;
            uint8_t* buffer = AMediaCodec_getOutputBuffer(audio_encoder, a_status, &size);
            
            if (muxerStarted && audioTrackIndex >= 0 && a_info.size > 0) {
                AMediaMuxer_writeSampleData(muxer, audioTrackIndex, buffer, &a_info);
            }
            AMediaCodec_releaseOutputBuffer(audio_encoder, a_status, false);
        } 
        else if (a_status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
            if (!audioTrackAdded) {
                AMediaFormat* format = AMediaCodec_getOutputFormat(audio_encoder);
                audioTrackIndex = AMediaMuxer_addTrack(muxer, format);
                audioTrackAdded = true;
                AMediaFormat_delete(format);
                printf("[Muxer] Audio Track Added via FORMAT_CHANGED.\n");
                if (videoTrackAdded && !muxerStarted) {
                    AMediaMuxer_start(muxer);
                    muxerStarted = true;
                    printf("[Muxer] Both Tracks Armed! Muxer started safely.\n");
                }
            }
        }

        if (running == 0) break;
    }


    // ----------------------------------------------------
    // 阶段五：资源完全逆序安全释放
    // ----------------------------------------------------
       // ----------------------------------------------------
    // 阶段五：资源完全逆序安全释放 (加入音频彻底清理)
    // ----------------------------------------------------
    printf("Stopping recording... Cleaning up native structures.\n");
    
    // 1. 回收音频采集异步线程
    pthread_join(audioThread, nullptr);
    // 2. 停止并释放音频硬件流和音频编码器
    if (audio_stream) {
        AAudioStream_requestStop(audio_stream);
        AAudioStream_close(audio_stream);
    }
    if (audio_encoder) {
        AMediaCodec_stop(audio_encoder);
        AMediaCodec_delete(audio_encoder);
    }

    // 3. 停止 Camera 采集会话与原有视频逻辑
    if (g_captureSession) {
        ACameraCaptureSession_stopRepeating(g_captureSession);
        ACameraCaptureSession_close(g_captureSession);
    }
    if (g_cameraDevice) {
        ACameraDevice_close(g_cameraDevice);
    }
    if (encoder) {
        AMediaCodec_stop(encoder);
        AMediaCodec_delete(encoder);
    }

    // 4. 彻底安全的闭合 Muxer 写入 moov 索引
    if (muxer) {
        if (muxerStarted) {
            media_status_t close_status = AMediaMuxer_stop(muxer);
            if (close_status != AMEDIA_OK) {
                printf("错误AMediaMuxer_stop ret=%d\n", close_status);
            } else {
                printf("AMediaMuxer_stop 成功！音视频双轨 MP4 完美闭合。\n");
            }
        }
        AMediaMuxer_delete(muxer);
    }
    
    close(fd);
    printf("保存文件到%s\n",file);
    return 0;
}
