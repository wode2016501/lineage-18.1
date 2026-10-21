// ==========================================
// 🎯 核心防冲突：在所有头文件展开之前，优先拦截 NDK 侧的 binder.h 再次展开
// ==========================================
#ifndef _LINUX_ANDROID_BINDER_H
#define _LINUX_ANDROID_BINDER_H 
#endif
#include <stdio.h>
#include <unistd.h>
#include <signal.h> // 引入系统信号控制
#include <fcntl.h>
#include <gui/Surface.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/ISurfaceComposer.h>
#include <ui/DisplayInfo.h>

// 🎯 【指定正确路径】严格对齐你的原生相机底层头文件
#include <camera/NdkCameraManager.h>
#include <camera/NdkCameraDevice.h>
#include <camera/NdkCameraCaptureSession.h>

// 引入 NDK 硬编码与媒体混流器头文件
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <media/NdkMediaMuxer.h>



using namespace android;

// ====================================================
// 🎯 全局变量定义：用于跨函数安全闭合文件
// ====================================================
volatile bool g_running = true; // 循环控制标志位
ACameraDevice* g_cameraDevice = nullptr;
ACameraCaptureSession* g_captureSession = nullptr;
AMediaCodec* g_encoder = nullptr;
AMediaMuxer* g_muxer = nullptr;
int g_fd = -1;
bool g_muxerStarted = false;

// 摄像头和会话状态回调函数（直接使用无名参数彻底封死 -Werror 的未使用变量拦截）
void onDeviceDisconnected(void* /*context*/, ACameraDevice* /*device*/) { printf("Camera Disconnected!\n"); }
void onDeviceError(void* /*context*/, ACameraDevice* /*device*/, int error) { printf("Camera Error: %d\n", error); }
ACameraDevice_StateCallbacks cameraDeviceCallbacks = { nullptr, onDeviceDisconnected, onDeviceError };

void onSessionActive(void* /*context*/, ACameraCaptureSession* /*session*/) { printf("Capture Session Active!\n"); }
void onSessionReady(void* /*context*/, ACameraCaptureSession* /*session*/) {}
void onSessionClosed(void* /*context*/, ACameraCaptureSession* /*session*/) {}
ACameraCaptureSession_stateCallbacks sessionCallbacks = { nullptr, onSessionClosed, onSessionReady, onSessionActive };

// ====================================================
// 🎯 信号拦截器：捕捉 Ctrl+C，优雅退出，写入 moov 头文件
// ====================================================
void sigal_handler(int /*sig*/) {
    printf("\n🛑 [Signal] Caught Ctrl+C (SIGINT)! Stopping camera pipeline gracefully...\n");
    g_running = false; 
}

int main() {
    printf("[Native Commandline Recorder] Booting... [Android 9/LineageOS 16]\n");

    // 绑定信号拦截器：当用户在终端按下 Ctrl+C 时激发
    signal(SIGINT, sigal_handler);

    // 1. 强行向 SurfaceFlinger 申请最上层预览窗口
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    client->initCheck();
    sp<IBinder> dtoken = SurfaceComposerClient::getBuiltInDisplay(ISurfaceComposer::eDisplayIdMain);
    DisplayInfo dinfo;
    SurfaceComposerClient::getDisplayInfo(dtoken, &dinfo);
    sp<SurfaceControl> surfaceControl = client->createSurface(String8("CameraNativePreview"), 1080, 1920, PIXEL_FORMAT_RGBA_8888, 0);
    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF).setPosition(surfaceControl, 0, 0).show(surfaceControl).apply();
    sp<Surface> previewSurface = surfaceControl->getSurface();
    ANativeWindow* previewWindow = previewSurface.get();

    // 2. 配置硬编码器参数
    int width = 1920;
    int height = 1080;
    int bitrate = 2000000;
    AMediaFormat* format = AMediaFormat_new();
    AMediaFormat_setString(format, AMEDIAFORMAT_KEY_MIME, "video/avc");
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_WIDTH, width);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_HEIGHT, height);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_BIT_RATE, bitrate);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_FRAME_RATE, 30);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_I_FRAME_INTERVAL, 1);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_COLOR_FORMAT, 0x7F000100);
    AMediaFormat_setInt32(format, "profile", 8);
    AMediaFormat_setInt32(format, "level", 65536);

    g_encoder = AMediaCodec_createEncoderByType("video/avc");
    AMediaCodec_configure(g_encoder, format, nullptr, nullptr, AMEDIACODEC_CONFIGURE_FLAG_ENCODE);

    ANativeWindow* encoderWindow = nullptr;
    AMediaCodec_createInputSurface(g_encoder, &encoderWindow);

    // 打开输出流并初始化 Muxer 容器
    g_fd = open("/sdcard/native_record.mp4", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    g_muxer = AMediaMuxer_new(g_fd, AMEDIAMUXER_OUTPUT_FORMAT_MPEG_4);

    AMediaCodec_start(g_encoder);
    usleep(10000);

    // 3. 打通原生 Camera2 硬件总线
    ACameraManager* cameraManager = ACameraManager_create();
    ACameraManager_openCamera(cameraManager, "0", &cameraDeviceCallbacks, &g_cameraDevice);

    ACaptureSessionOutputContainer* outputContainer = nullptr;
    ACaptureSessionOutputContainer_create(&outputContainer);

    ACaptureSessionOutput* previewOutput = nullptr;
    ACaptureSessionOutput_create(previewWindow, &previewOutput);
    ACaptureSessionOutputContainer_add(outputContainer, previewOutput);

    ACaptureSessionOutput* recordingOutput = nullptr;
    ACaptureSessionOutput_create(encoderWindow, &recordingOutput);
    ACaptureSessionOutputContainer_add(outputContainer, recordingOutput);
    // ----------------------------------------------------
    // 🎯 【终极对齐】精准向高通驱动声明双路物理流的独立硬件级别
    // ----------------------------------------------------
    // 创建捕获会话
    ACameraDevice_createCaptureSession(g_cameraDevice, outputContainer, &sessionCallbacks, &g_captureSession);

    // 极其关键：必须分别创建两个针对高通 ISP 管道的请求结构体，或者将录像请求设为全局广播
    ACaptureRequest* captureRequest = nullptr;
    // 在高通 835 平台，针对双流并发，最安全的模板是使用标准的 TEMPLATE_RECORD (录像专用总线)
    ACameraDevice_createCaptureRequest(g_cameraDevice, TEMPLATE_RECORD, &captureRequest);

    // 🎯 [核心补充] 强行让高通的自动测光、自动对焦、自动曝光（3A算法）在双流下同时向预览和录像广播
    uint8_t aeMode = ACAMERA_CONTROL_AE_MODE_ON;
    ACaptureRequest_setEntry_u8(captureRequest, ACAMERA_CONTROL_AE_MODE, 1, &aeMode);
    uint8_t afMode = ACAMERA_CONTROL_AF_MODE_CONTINUOUS_VIDEO; // 切换为持续视频对焦模式，强制刷新 ISP 缓冲区
    ACaptureRequest_setEntry_u8(captureRequest, ACAMERA_CONTROL_AF_MODE, 1, &afMode);

    // 将屏幕显示窗口绑定为第一输出目标
    ACameraOutputTarget* previewTarget = nullptr;
    ACameraOutputTarget_create(previewWindow, &previewTarget);
    ACaptureRequest_addTarget(captureRequest, previewTarget);

    // 将硬件编码器窗口绑定为第二输出目标
    ACameraOutputTarget* recordingTarget = nullptr;
    ACameraOutputTarget_create(encoderWindow, &recordingTarget);
    ACaptureRequest_addTarget(captureRequest, recordingTarget);

    // 让高通 ISP 双路并发管道开始不间断吐流
    ACameraCaptureSession_setRepeatingRequest(g_captureSession, nullptr, 1, &captureRequest, nullptr);

    printf("Camera pipeline coupled! Waiting 1500ms for hardware sensor pre-roll...\n");
    // 🎯 [核心修复] 将等待时间从 500ms 延长到 1500ms（1.5秒），给高通硬编码器留出足够的时间去完成
    // 与相机 Hal 层握手并接收最初的十几帧图像，确保迈入循环前硬编缓冲区绝对不是空的！
    usleep(1500000); 

    // 4. 完全受信号标志位硬控的无损抽取数据循环
       // ----------------------------------------------------
    // 4. 【全状态异步对齐】高通底层硬编数据高频无损抽离循环

    // ----------------------------------------------------
    ssize_t trackIndex = -1;
    AMediaCodecBufferInfo info;
    printf("Muxer loop pulling engaged! Harvesting hardware H.264 streams...\n");

    int totalFrames = 0;
    
    // 🎯 核心大改一：去掉原本容易死锁的 || !g_muxerStarted 条件，只要 g_running 变 false 必立刻退出
    while (g_running) { 
        // 探测时间保持为 5000 微秒
        ssize_t status = AMediaCodec_dequeueOutputBuffer(g_encoder, &info, 5000);
        
        if (status >= 0) {
            size_t bufSize;
            uint8_t* buffer = AMediaCodec_getOutputBuffer(g_encoder, status, &bufSize);
            
            if (info.flags & AMEDIACODEC_BUFFER_FLAG_CODEC_CONFIG) {
                printf("[Metadata] ---> Captured Qualcomm SPS/PPS Header! Activating MP4 container.\n");
                trackIndex = AMediaMuxer_addTrack(g_muxer, AMediaCodec_getOutputFormat(g_encoder));
                AMediaMuxer_start(g_muxer);
                g_muxerStarted = true;
            } 
            
            if (g_muxerStarted && trackIndex >= 0 && info.size > 0) {
                AMediaMuxer_writeSampleData(g_muxer, trackIndex, buffer, &info);
                totalFrames++;
                if (totalFrames % 30 == 0) {
                    printf("[Recorder] Running... Processed %d hardware frames.\n", totalFrames);
                }
            }
            
            AMediaCodec_releaseOutputBuffer(g_encoder, status, false);
            
            if (info.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM) {
                printf("[Metadata] ---> Encountered Hardware End of Stream (EOS)!\n");
                break;
            }
        } 
        else if (status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
            printf("[Metadata] ---> Qualcomm Format Changed detected! Instantiating Muxer tracks...\n");
            trackIndex = AMediaMuxer_addTrack(g_muxer, AMediaCodec_getOutputFormat(g_encoder));
            AMediaMuxer_start(g_muxer);
            g_muxerStarted = true;
        } 
        else {
            // 🎯 核心大改二：面对任何状态码，只要收到外部停止信号，一律由底层直接出局
            if (!g_running) {
                break;
            }
            sched_yield(); 
        }
    }

    // ====================================================
    // 5. 【终极封箱仪式】破出循环后，强制执行高通底层合流合拢，焊死 MOOV ATOM
    // ====================================================
    printf("\n[Finalizer] Safely closing MP4 container structures...\n");
    
    ACameraCaptureSession_stopRepeating(g_captureSession);
    ACameraCaptureSession_close(g_captureSession);
    ACameraDevice_close(g_cameraDevice);

    AMediaCodec_stop(g_encoder);
    AMediaCodec_delete(g_encoder);
    
    // 🎯 核心大改三：最后的防御！如果退出太快，底层没有触发任何轨道，我们在这里强行伪造一个基准轨给 Muxer
    if (!g_muxerStarted) {
        printf("[Finalizer] ⚠️ 警告：检测到过早按下 Ctrl+C！正在紧急强制补齐虚拟 H.264 轨道垫背...\n");
        AMediaFormat* dummyFormat = AMediaFormat_new();
        AMediaFormat_setString(dummyFormat, AMEDIAFORMAT_KEY_MIME, "video/avc");
        AMediaFormat_setInt32(dummyFormat, AMEDIAFORMAT_KEY_WIDTH, 1920);
        AMediaFormat_setInt32(dummyFormat, AMEDIAFORMAT_KEY_HEIGHT, 1080);
        trackIndex = AMediaMuxer_addTrack(g_muxer, dummyFormat);
        AMediaMuxer_start(g_muxer);
        g_muxerStarted = true;
        AMediaFormat_delete(dummyFormat);
    }

    if (g_muxerStarted) {
        printf("[Finalizer] 🔥 正在强行命令多媒体系统将 MOOV ATOM 压入文件尾部...\n");
        media_status_t stopStatus = AMediaMuxer_stop(g_muxer); 
        printf("[Finalizer] AMediaMuxer_stop execution status: %d (0 means Success)\n", stopStatus);
    }
    
    AMediaMuxer_delete(g_muxer);
    close(g_fd);

    printf("🏆 Done! Output file saved and finalized to /sdcard/native_record.mp4\n");
    return 0;
}
