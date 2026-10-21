
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

// ... 后面 main() 函数逻辑保持原封不动 ...
int main() {
    printf("[Native Commandline Recorder] Booting... [Android 9/LineageOS 16]\n");
    signal(SIGINT, sigal_handler);
        int width = 1920;
    int height = 1080;
    // ----------------------------------------------------
    // 阶段一：向 SurfaceFlinger 强行索要用于显示的预览窗口
    // ----------------------------------------------------
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    client->initCheck();
    sp<IBinder> dtoken = SurfaceComposerClient::getBuiltInDisplay(ISurfaceComposer::eDisplayIdMain);
    DisplayInfo dinfo;
    SurfaceComposerClient::getDisplayInfo(dtoken, &dinfo);

    // 创建一半屏幕大小的相机底层悬浮预览窗
    sp<SurfaceControl> surfaceControl = client->createSurface(String8("CameraNativePreview"), width , height , PIXEL_FORMAT_RGBA_8888, 0);
    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF).setPosition(surfaceControl, 0, 0).show(surfaceControl).apply();
    
    // 拿到可供 NDK 注入预览的总线窗口指针
    sp<Surface> previewSurface = surfaceControl->getSurface();
    ANativeWindow* previewWindow = previewSurface.get();

    // ----------------------------------------------------
    // 阶段二：配置高通硬编码器 (MediaCodec) 以及封装器 (Muxer)
    // ----------------------------------------------------

    int bitrate = 2000000; // 对应命令行输入的 2M 码率

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
    int fd = open("/sdcard/native_record.mp4", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    muxer = AMediaMuxer_new(fd, AMEDIAMUXER_OUTPUT_FORMAT_MPEG_4);

    // 启动编码器
    AMediaCodec_start(encoder);

    // ----------------------------------------------------
    // 阶段三：调用 NDK Camera2 打通底层硬件通道
    // ----------------------------------------------------
    ACameraManager* cameraManager = ACameraManager_create();
    
    // 打开 0 号后置摄像头
    ACameraManager_openCamera(cameraManager, "0", &cameraDeviceCallbacks, &g_cameraDevice);

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
    ssize_t trackIndex = -1;
    AMediaCodecBufferInfo info;
    bool muxerStarted = false;

    printf("Muxer loop pulling engaged! Monitoring Qualcomm Hardware pipelines...\n");
    
    // 【核心修复】：超时时间改为 10000 微秒（10毫秒），绝对不要用 -1
    // 结合 running 标志位，确保能随时响应退出
    while (running) {
        ssize_t status = AMediaCodec_dequeueOutputBuffer(encoder, &info, 10000);
        
        if (running == 0) {
            printf("[Muxer] Exit signal detected. Breaking loop...\n");
            break;
        }

        if (status >= 0) {
            size_t bufSize;
            uint8_t* buffer = AMediaCodec_getOutputBuffer(encoder, status, &bufSize);

            // 1. 拦截配置帧 (SPS/PPS)
            if (info.flags & AMEDIACODEC_BUFFER_FLAG_CODEC_CONFIG) {
                if (!muxerStarted) {
                    AMediaFormat* codecFormat = AMediaCodec_getOutputFormat(encoder);
                    trackIndex = AMediaMuxer_addTrack(muxer, codecFormat);
                    AMediaMuxer_start(muxer);
                    muxerStarted = true;
                    AMediaFormat_delete(codecFormat);
                    printf("[Muxer] Activated MP4 container via CODEC_CONFIG.\n");
                }
            } 
            
            // 2. 只有当 Muxer 真正启动后，才允许写入有效数据
            if (muxerStarted && trackIndex >= 0 && info.size > 0) {
                media_status_t writeStatus = AMediaMuxer_writeSampleData(muxer, trackIndex, buffer, &info);
                if (writeStatus == AMEDIA_OK) {
                    // printf("[Muxer] Wrote packet size: %d, PTS: %lld\n", info.size, info.presentationTimeUs);
                }
            }
            
            // 3. 【铁律】：必须释放缓冲区给高通硬编管线
            AMediaCodec_releaseOutputBuffer(encoder, status, false);
            
            if (info.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM) {
                printf("[Status] ---> Encountered Hardware End of Stream (EOS)!\n");
                break;
            }
        } 
        else if (status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
            // 【针对格式错乱的终极修复】：标准的格式改变拦截，addTrack 后必须立刻 start！
            if (!muxerStarted) {
                AMediaFormat* codecFormat = AMediaCodec_getOutputFormat(encoder);
                trackIndex = AMediaMuxer_addTrack(muxer, codecFormat);
                AMediaMuxer_start(muxer);
                muxerStarted = true;
                AMediaFormat_delete(codecFormat);
                printf("[Muxer] Activated MP4 container via FORMAT_CHANGED.\n");
            }
        } 
        else if (status == AMEDIACODEC_INFO_TRY_AGAIN_LATER) {
            // 硬件管线中暂时没有可用的编码帧，稍微休眠 2ms 缓解 CPU 轮询压力
            usleep(2000);
        } 
        else {
            printf("[Status] Unhandled MediaCodec Status Code: %ld\n", status);
        }
    }

    // ----------------------------------------------------
    // 阶段五：资源完全逆序安全释放
    // ----------------------------------------------------
    printf("Stopping recording... Cleaning up native structures.\n");
    
    // 1. 先切断 Camera 采集源头输入
    if (g_captureSession) {
        ACameraCaptureSession_stopRepeating(g_captureSession);
        ACameraCaptureSession_close(g_captureSession);
    }
    if (g_cameraDevice) {
        ACameraDevice_close(g_cameraDevice);
    }

    // 2. 再停止并销毁编码器
    if (encoder) {
        AMediaCodec_stop(encoder);
        AMediaCodec_delete(encoder);
    }

    // 3. 最后在没有任何流干扰的干净状态下，关闭复用器生成 moov 头
    if (muxer) {
        if (muxerStarted) {
            media_status_t close_status = AMediaMuxer_stop(muxer);
            if (close_status != AMEDIA_OK) {
                printf("错误AMediaMuxer_stop ret=%d\n", close_status);
            } else {
                printf("AMediaMuxer_stop 成功！MP4 完美闭合。\n");
            }
        }
        AMediaMuxer_delete(muxer);
    }
    
    close(fd);
    printf("Done! Output file saved to /sdcard/native_record.mp4\n");
    return 0;
}
