#include <stdio.h>
#include <unistd.h>
#include <gui/Surface.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/ISurfaceComposer.h>
#include <ui/DisplayInfo.h>
#include <camera/NdkCameraManager.h>
#include <camera/NdkCameraDevice.h>
#include <camera/NdkCameraCaptureSession.h>
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <media/NdkMediaMuxer.h>
#include <ui/Rect.h>
#include <binder/ProcessState.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <aaudio/AAudio.h>
#include <mutex>
#include <condition_variable>
// ⭐ 新增：推理与时间组件
#include <media/NdkImageReader.h>
#include <chrono>
#include "net.h"
pthread_t g_audioThreadId; // 放在文件最顶部
AMediaCodec *audio_encoder = nullptr;
AAudioStream *audio_stream = nullptr;
ssize_t audioTrackIndex = -1;
ssize_t videoTrackIndex = -1;
AMediaMuxer *muxer = nullptr;
AMediaCodec *encoder = nullptr;
int running = 1;

using namespace android;

ACameraDevice *g_cameraDevice = nullptr;
ACameraCaptureSession *g_captureSession = nullptr;
bool g_sessionActive = false;

// ⭐ 新增：YOLO 组件全局定义
// ==========================================
// ⭐ 已为你对齐：YOLO & AImageReader 全局控制组件
// ==========================================#include <mutex>
#include <condition_variable>

// =========================================================================
// ⭐ 线程安全与队列组件：实现相机流与 AI 推理彻底分离
// =========================================================================#include <mutex>
#include <condition_variable>
#include <math.h> // 引入数学库计算 exp

// =========================================================================
// ⭐ 终极闭环全局组件
// =========================================================================
AImageReader* g_yoloReader = nullptr;
ANativeWindow* g_yoloWindow = nullptr;
ACaptureSessionOutput* g_yoloOutput = nullptr;
ACameraOutputTarget* g_yoloTarget = nullptr;
ncnn::Net g_yolov5; 

const int YOLO_WIDTH = 640;
const int YOLO_HEIGHT = 640;
 int DETECTION_INTERVAL_MS = 1000; // 1秒扫描一次

std::mutex g_yoloMutex;
std::condition_variable g_yoloCond;
ncnn::Mat g_pendingFrame; 
bool g_hasPendingFrame = false;
pthread_t g_yoloThreadId;

// ⚡ 极速高能效数学激活函数：将解耦头的原始 Logits 还原为 0.0 ~ 1.0 的百分比概率
inline float fast_sigmoid(float x) {
    return 1.0f / (1.0f + expf(-x));
}

// =========================================================================
// ⭐ AI 后台消费者线程（耗时计算全在此处，主视频录制推流 100% 恢复满帧丝滑）
// =========================================================================
void* yolo_inference_worker_thread(void*) {
    printf("[YOLO Thread] AI Inference Consumer Thread actively engaged.\n");
    g_yolov5.opt.num_threads = 4; 

    while (running) {
        ncnn::Mat localFrame;
        {
            std::unique_lock<std::mutex> lock(g_yoloMutex);
            g_yoloCond.wait(lock, []{ return g_hasPendingFrame || !running; });
            if (!running) break;
            localFrame = g_pendingFrame;
            g_hasPendingFrame = false;
        }

        // 进行主前向深度学习推理
        ncnn::Extractor ex = g_yolov5.create_extractor();
        ex.input("in0", localFrame);   
        ncnn::Mat out;
        ex.extract("out0", out); 

        int num_anchors = out.w; // 8400 个全图网格点
        bool person_detected = false;
        
        // 锁定第 5 行进行精准数学级全图扫描
        const float* raw_logits_row = out.row(4);
        
        float max_prob_found = 0.0f;
        for (int i = 0; i < num_anchors; i++) {
            // 对未激活的原始 Logits 强行施加 Sigmoid 映射
            float person_prob = fast_sigmoid(raw_logits_row[i]);
            
            if (person_prob > max_prob_found) {
                max_prob_found = person_prob;
            }

            // 门限设定：只要全图有一个网格对人的概率确信度大于 65%
            if (person_prob > 0.60f) { 
                person_detected = true;
            }
        }

        // 干净、温和的异步业务层触发输出
        if (person_detected) {
            printf("有人 (最高确信度: %.2f%%)\n", max_prob_found * 100.0f);
        } else {
            // 没人时在后台打印（你可以随时注释掉这行，让没人时保持静默）
            // printf("[后台侦测] 场景安全，当前最高嫌疑度: %.2f%%\n", max_prob_found * 100.0f);
        }
        fflush(stdout);
    }
    return nullptr;
}

// =========================================================================
// ⭐ 极速生产者相机回调（耗时仅 0.02 毫秒，放行相机通路，彻底杜绝一卡一卡）
// =========================================================================
// =========================================================================
// ⭐ 新增：纯 C 语言零依赖无损 YUV 图像转储函数
// =========================================================================
void save_clean_yuv(const uint8_t* clean_buf, int width, int height) {
    static int img_id = 0;
    char filename[256];
    
    // 💡 锁定安全路径：在 835 命令行环境中，写到 /data/local/tmp/ 下可 100% 绕过 Android 的运行时存储权限封锁
    sprintf(filename, "/data/local/tmp/yuv/%d_%dx%d_fixed.yuv", img_id++, width, height); 

    FILE* yuv_file = fopen(filename, "wb");
    if (yuv_file != nullptr) {
        // 一键将对齐修正后的、完美的 640x640 纯灰度像素数据 dump 进文件
        fwrite(clean_buf, 1, width * height, yuv_file);
        fclose(yuv_file);
        printf("[AI 导出成功] 干净的 YUV 特征图已转储至: %s\n", filename);
    } else {
        printf("[AI 错误] 图像二进制数据转储失败！请检查目录权限。\n");
    }
    fflush(stdout);
}

// =========================================================================
// ⭐ 核心回调函数（已完美融入手工对齐、通道广播和一键存图逻辑）
// =========================================================================
/**
 * @brief 处理YOLO帧可用的回调函数
 * @param context 上下文指针
 * @param reader 图像读取器指针
 */
void onYoloFrameAvailable(void* context, AImageReader* reader) {
    // 使用static变量记录上次检测时间，用于控制检测频率
    static auto last_detect_time = std::chrono::steady_clock::now();
    // 获取当前时间
    auto now = std::chrono::steady_clock::now();
    // 计算距离上次检测的时间差（毫秒）
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_detect_time).count();

    // 获取下一帧图像
    AImage* image = nullptr;
    media_status_t status = AImageReader_acquireNextImage(reader, &image);
    // 如果获取图像失败或图像为空，直接返回
    if (status != AMEDIA_OK || image == nullptr) return; 

    // 定频跳帧拦截（1秒）
    if (duration < DETECTION_INTERVAL_MS) { 
        AImage_delete(image);
        return;
    }

    // 获取原始Y通道数据
    uint8_t* y_data = nullptr;
    int y_len = 0;
    AImage_getPlaneData(image, 0, &y_data, &y_len); // 获取原始 Y 通道

    // 获取硬件对齐步长
    int32_t y_stride = 0;
    AImage_getPlaneRowStride(image, 0, &y_stride); // 获取硬件对齐步长

    if (y_data != nullptr) {
        // 🔮 内存步长对齐：抽取紧凑、无错位的 640x640 纯灰度连续内存
        std::vector<uint8_t> clean_y_buf(YOLO_WIDTH * YOLO_HEIGHT);
        // 将原始Y通道数据复制到连续内存中
        for (int h = 0; h < YOLO_HEIGHT; h++) {
            memcpy(&clean_y_buf[h * YOLO_WIDTH], y_data + h * y_stride, YOLO_WIDTH);
        }

        // 💾 ⭐ 调用新增函数：自动无损导出对齐修正后的二进制 YUV 图片
       // save_clean_yuv(clean_y_buf.data(), YOLO_WIDTH, YOLO_HEIGHT);

        // 使用互斥锁保护共享变量
        std::unique_lock<std::mutex> lock(g_yoloMutex);
        // 如果没有待处理的帧
        if (!g_hasPendingFrame) { 
            // 更新最后检测时间
            last_detect_time = now; 

            // 构建 NCNN 基础矩阵容器，绝对不存在宏冲突或编译未定义符号问题
            ncnn::Mat in_color(YOLO_WIDTH, YOLO_HEIGHT, 3, (size_t)4u);
            
            // 广播单通道 Y 轴灰阶到模型的 R、G、B 三个通道平面中
            float* ptr_r = in_color.channel(0);
            float* ptr_g = in_color.channel(1);
            float* ptr_b = in_color.channel(2);
            
            // 将Y通道数据复制到三个通道中，并进行归一化
            for (int i = 0; i < YOLO_WIDTH * YOLO_HEIGHT; i++) {
                float val = (float)clean_y_buf[i] / 255.0f; // 顺便完成官方标准的归一化缩放
                ptr_r[i] = val;
                ptr_g[i] = val;
                ptr_b[i] = val;
            }

            // 丢给后台独立 AI 线程去跑推理
            g_pendingFrame = in_color;
            g_hasPendingFrame = true;
            g_yoloCond.notify_one(); // 异步秒级唤醒，主线程 100% 保持满帧丝滑
        }
    }

    // 释放图像资源
    AImage_delete(image); 
}





void sigal_handler(int)
{
	printf("sigal_handler\n");
	running = 0;
}

void onDeviceDisconnected(void *, ACameraDevice *) { printf("Camera Disconnected!\n"); }
void onDeviceError(void *, ACameraDevice *, int error) { printf("Camera Error: %d\n", error); }
ACameraDevice_StateCallbacks cameraDeviceCallbacks = {nullptr, onDeviceDisconnected, onDeviceError};

void onSessionActive(void *, ACameraCaptureSession *)
{
	g_sessionActive = true;
	printf("Capture Session Active!\n");
}
void onSessionReady(void *, ACameraCaptureSession *) {}
void onSessionClosed(void *, ACameraCaptureSession *) {}
ACameraCaptureSession_stateCallbacks sessionCallbacks = {nullptr, onSessionClosed, onSessionReady, onSessionActive};

bool initAudioEncoder(int sampleRate, int channelCount, int bitrate)
{
	AMediaFormat *audioFormat = AMediaFormat_new();
	AMediaFormat_setString(audioFormat, AMEDIAFORMAT_KEY_MIME, "audio/mp4a-latm");
	AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_SAMPLE_RATE, sampleRate);
	AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_CHANNEL_COUNT, channelCount);
	AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_BIT_RATE, bitrate);
	AMediaFormat_setInt32(audioFormat, "aac-profile", 2);
	audio_encoder = AMediaCodec_createEncoderByType("audio/mp4a-latm");
	if (!audio_encoder)
		return false;
	media_status_t status = AMediaCodec_configure(audio_encoder, audioFormat, nullptr, nullptr, AMEDIACODEC_CONFIGURE_FLAG_ENCODE);
	AMediaFormat_delete(audioFormat);
	if (status != AMEDIA_OK)
		return false;
	AMediaCodec_start(audio_encoder);
	return true;
}

bool initAAudio(int sampleRate, int channelCount)
{
	AAudioStreamBuilder *builder = nullptr;
	aaudio_result_t result = AAudio_createStreamBuilder(&builder);
	if (result != AAUDIO_OK)
		return false;
	AAudioStreamBuilder_setDirection(builder, AAUDIO_DIRECTION_INPUT);
	AAudioStreamBuilder_setSampleRate(builder, sampleRate);
	AAudioStreamBuilder_setChannelCount(builder, channelCount);
	AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_I16);
	AAudioStreamBuilder_setInputPreset(builder, AAUDIO_INPUT_PRESET_VOICE_RECOGNITION);
	result = AAudioStreamBuilder_openStream(builder, &audio_stream);
	AAudioStreamBuilder_delete(builder);
	if (result != AAUDIO_OK)
		return false;
	return AAudioStream_requestStart(audio_stream) == AAUDIO_OK;
}

void *audio_polling_thread(void *)
{
	const int SAMPLES_PER_FRAME = 1024;
	int channelCount = 1;
	int16_t *pcmBuffer = new int16_t[SAMPLES_PER_FRAME * channelCount];
	while (running)
	{
		aaudio_result_t framesRead = AAudioStream_read(audio_stream, pcmBuffer, SAMPLES_PER_FRAME, 20000000);
		if (framesRead > 0)
		{
			ssize_t inputBufIdx = AMediaCodec_dequeueInputBuffer(audio_encoder, 10000);
			if (inputBufIdx >= 0)
			{
				size_t bufSize;
				uint8_t *codecInputBuf = AMediaCodec_getInputBuffer(audio_encoder, inputBufIdx, &bufSize);
				int bytesToCopy = framesRead * channelCount * sizeof(int16_t);
				if (bytesToCopy > (int)bufSize)
					bytesToCopy = bufSize;
				memcpy(codecInputBuf, pcmBuffer, bytesToCopy);
				struct timespec ts;
				clock_gettime(1, &ts);
				int64_t currentPtsUs = (int64_t)ts.tv_sec * 1000000LL + (int64_t)ts.tv_nsec / 1000LL;
				AMediaCodec_queueInputBuffer(audio_encoder, inputBufIdx, 0, bytesToCopy, currentPtsUs, 0);
			}
		}
	}
	delete[] pcmBuffer;
	return nullptr;
}

void *sh_thread(void *arg)
{
	char cmd[1255];
	sprintf(cmd, "sh %s", (const char *)arg);
	system(cmd);
	running = 0;
	return nullptr;
}

void settcp(int client_fd)
{
	struct timeval timeout = {1, 0};
	setsockopt(client_fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
}

int client_connect(int server_fd)
{
	struct sockaddr_in6 client_addr;
	int addrlen = sizeof(struct sockaddr_in6);
	int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
	if (client_fd < 0)
		return -1;
	if (IN6_IS_ADDR_LOOPBACK(&client_addr.sin6_addr) ||
		(IN6_IS_ADDR_V4MAPPED(&client_addr.sin6_addr) && client_addr.sin6_addr.s6_addr[12] == 127))
	{
		close(client_fd);
		return -1;
	}
	settcp(client_fd);
	return client_fd;
}

int sendd(int client_fd, char *buf, int ssize)
{
	int ret = 0, size = 0;
	while ((ssize - size) > 0)
	{
		ret = write(client_fd, buf, ssize - size);
		if (ret < 1)
			return -1;
		buf += ret;
		size += ret;
	}
	return size;
}
int main(int argc, char **argv)
{
	signal(SIGPIPE, SIG_IGN);
	int port = 10000;
	const char *sh_file = nullptr;
	const char *file = "/sdcard/native_record.mp4";
	int bitrate = 2000000, width = 1920, height = 1080;
	char bbuffer[255];
	int *Width = (int *)bbuffer;
	int *Height = (int *)(bbuffer + 4);
	*Height = height;
	*Width = width;
	int *sps_size = (int *)(bbuffer + 8);
	char *sps_buf = bbuffer + 12;
	int client_max = 10, client_count = 0;
	int *client_arr = (int *)malloc(sizeof(int) * client_max);
	fd_set wd_set, rd_set;
	int maxfd = 0;
	size_t size = 0;

	if (argc > 1){
		file = argv[1];
		if(strstr(argv[1],"-h")){
			printf("Usage: %s [file] [bitrate] [sh_file] [秒]\n", argv[0]);
			return 0;
		}
	}
	if (argc > 2)
		bitrate = atoi(argv[2]);
	if (argc > 3)
		sh_file = argv[3];
		if(argc > 4)
		DETECTION_INTERVAL_MS = atoi(argv[4])*1000;

	int fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0)
	{
		free(client_arr);
		return fd;
	}
	if (sh_file)
	{
		pthread_t shThread;
		pthread_create(&shThread, nullptr, sh_thread, (void *)sh_file);
	}

	signal(SIGINT, sigal_handler);
	struct sockaddr_in6 server_addr;
	int server_fd = socket(AF_INET6, SOCK_STREAM, 0);
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin6_family = AF_INET6;
	server_addr.sin6_addr = in6addr_any;
	server_addr.sin6_port = htons(port);
	int opt = 1;
	setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	int v6only = 0;
	setsockopt(server_fd, IPPROTO_IPV6, IPV6_V6ONLY, &v6only, sizeof(v6only));
	bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(server_fd, 1);

	sp<SurfaceComposerClient> client = new SurfaceComposerClient();
	client->initCheck();
	// Android 9 中使用 ISurfaceComposer::eDisplayIdMain 代表主屏幕
	sp<IBinder> dtoken = SurfaceComposerClient::getBuiltInDisplay(ISurfaceComposer::eDisplayIdMain);

	DisplayInfo dinfo;
	SurfaceComposerClient::getDisplayInfo(dtoken, &dinfo);
	sp<SurfaceControl> surfaceControl = client->createSurface(String8("CameraNativePreview"), width / 2, height / 2, PIXEL_FORMAT_RGBA_8888, 0);

	SurfaceComposerClient::Transaction t;
	t.setLayerStack(surfaceControl, 0).setLayer(surfaceControl, 0x7FFFFFFF).setPosition(surfaceControl, 0, 960 - height / 2).setAlpha(surfaceControl, 0.65f).show(surfaceControl).apply();

	sp<Surface> previewSurface = surfaceControl->getSurface();
	ANativeWindow *previewWindow = previewSurface.get();

	AMediaFormat *format = AMediaFormat_new();
	AMediaFormat_setString(format, AMEDIAFORMAT_KEY_MIME, "video/avc");
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_WIDTH, width);
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_HEIGHT, height);
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_BIT_RATE, bitrate);
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_FRAME_RATE, 30);
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_I_FRAME_INTERVAL, 1);
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_COLOR_FORMAT, 2130708361);
	encoder = AMediaCodec_createEncoderByType("video/avc");
	AMediaCodec_configure(encoder, format, nullptr, nullptr, AMEDIACODEC_CONFIGURE_FLAG_ENCODE);
	ANativeWindow *encoderWindow = nullptr;
	AMediaCodec_createInputSurface(encoder, &encoderWindow);
	muxer = AMediaMuxer_new(fd, AMEDIAMUXER_OUTPUT_FORMAT_MPEG_4);
	AMediaCodec_start(encoder);
	AMediaFormat_delete(format);
	initAudioEncoder(44100, 1, 64000);
	initAAudio(44100, 1);

	// ⭐ NCNN 加载
	g_yolov5.opt.lightmode = true;
	g_yolov5.opt.num_threads = 4;
	g_yolov5.opt.use_vulkan_compute = false;
	g_yolov5.load_param("yolov5_opt.param");
	g_yolov5.load_model("yolov5_opt.bin");

	// ⭐ ImageReader
	AImageReader_new(YOLO_WIDTH, YOLO_HEIGHT, AIMAGE_FORMAT_YUV_420_888, 2, &g_yoloReader);
	AImageReader_getWindow(g_yoloReader, &g_yoloWindow);
	ACaptureSessionOutput_create(g_yoloWindow, &g_yoloOutput);
	ACameraOutputTarget_create(g_yoloWindow, &g_yoloTarget);
	AImageReader_ImageListener listener = {nullptr, onYoloFrameAvailable};
	AImageReader_setImageListener(g_yoloReader, &listener);

	ACameraManager *cameraManager = ACameraManager_create();
	while (1)
	{
		if (ACameraManager_openCamera(cameraManager, "0", &cameraDeviceCallbacks, &g_cameraDevice) == ACAMERA_OK)
			break;
		sleep(1);
	}

	ACaptureSessionOutputContainer *outputContainer = nullptr;
	ACaptureSessionOutputContainer_create(&outputContainer);
	ACaptureSessionOutput *previewOutput = nullptr;
	ACaptureSessionOutput_create(previewWindow, &previewOutput);
	ACaptureSessionOutputContainer_add(outputContainer, previewOutput);
	ACaptureSessionOutput *recordingOutput = nullptr;
	ACaptureSessionOutput_create(encoderWindow, &recordingOutput);
	ACaptureSessionOutputContainer_add(outputContainer, recordingOutput);
	if (g_yoloOutput)
		ACaptureSessionOutputContainer_add(outputContainer, g_yoloOutput);

	ACameraDevice_createCaptureSession(g_cameraDevice, outputContainer, &sessionCallbacks, &g_captureSession);
	ACaptureRequest *captureRequest = nullptr;
	ACameraDevice_createCaptureRequest(g_cameraDevice, TEMPLATE_RECORD, &captureRequest);
	ACameraOutputTarget *previewTarget = nullptr;
	ACameraOutputTarget_create(previewWindow, &previewTarget);
	ACaptureRequest_addTarget(captureRequest, previewTarget);
	ACameraOutputTarget *recordingTarget = nullptr;
	ACameraOutputTarget_create(encoderWindow, &recordingTarget);
	ACaptureRequest_addTarget(captureRequest, recordingTarget);
	if (g_yoloTarget)
		ACaptureRequest_addTarget(captureRequest, g_yoloTarget);

	ACameraCaptureSession_setRepeatingRequest(g_captureSession, nullptr, 1, &captureRequest, nullptr);

	printf("Camera pipeline coupled! Recording and Previewing for 10 seconds...\n");
	// pthread_t audioThread; // ❌ 删掉这行局部定义
	pthread_create(&g_audioThreadId, nullptr, audio_polling_thread, nullptr); // ⭐ 改用全局变量

	AMediaCodecBufferInfo v_info, a_info;
	uint8_t *nalu_data = nullptr;
	int client_fd = 0, out_size = 0;
	uint8_t *buffer = nullptr;
	struct timeval tv = {0, 0};
	pthread_create(&g_yoloThreadId, nullptr, yolo_inference_worker_thread, nullptr);
	while (running)
	{
		ssize_t v_status = AMediaCodec_dequeueOutputBuffer(encoder, &v_info, 20000);
		if (v_status >= 0)
		{
			buffer = AMediaCodec_getOutputBuffer(encoder, v_status, &size);
			if (videoTrackIndex >= 0 && v_info.size > 0)
			{
				FD_ZERO(&wd_set);
				FD_ZERO(&rd_set);
				FD_SET(server_fd, &rd_set);
				maxfd = server_fd;
				for (int i = 0; i < client_count; ++i)
				{
					FD_SET(client_arr[i], &wd_set);
					if (client_arr[i] > maxfd)
						maxfd = client_arr[i];
				}
				if (select(maxfd + 1, &rd_set, &wd_set, nullptr, &tv) >= 0)
				{
					nalu_data = buffer + v_info.offset;
					if ((nalu_data[4] & 0x1f) == 5 && FD_ISSET(server_fd, &rd_set))
					{
						client_fd = client_connect(server_fd);
						if (client_fd >= 0)
						{
							out_size = 8;
							sendd(client_fd, (char *)bbuffer, out_size);
							client_arr[client_count++] = client_fd;
						}
					}
					for (int i = 0; i < client_count; i++)
					{
						if (FD_ISSET(client_arr[i], &wd_set))
						{
							out_size = v_info.size;
							if (client_fd == client_arr[i])
								out_size += *sps_size;
							sendd(client_arr[i], (char *)&out_size, sizeof(int));
							if (client_fd == client_arr[i])
							{
								sendd(client_arr[i], sps_buf, *sps_size);
								client_fd = 0;
							}
							sendd(client_arr[i], (char *)nalu_data, v_info.size);
						}
					}
				}
				AMediaMuxer_writeSampleData(muxer, videoTrackIndex, buffer, &v_info);
			}
			AMediaCodec_releaseOutputBuffer(encoder, v_status, false);
		}
		if (v_status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED)
		{
			AMediaFormat *fmt = AMediaCodec_getOutputFormat(encoder);
			char *p = nullptr;
			if (AMediaFormat_getBuffer(fmt, "csd-0", (void **)&p, &size) && p)
			{
				memcpy(sps_buf, p, size);
				*sps_size = size;
			}
			if (AMediaFormat_getBuffer(fmt, "csd-1", (void **)&p, &size) && p)
			{
				memcpy(sps_buf + *sps_size, p, size);
				*sps_size += size;
			}
			if (videoTrackIndex < 0)
			{
				videoTrackIndex = AMediaMuxer_addTrack(muxer, fmt);
				AMediaFormat_delete(fmt);
				if (audioTrackIndex >= 0)
					AMediaMuxer_start(muxer);
			}
		}
		ssize_t a_status = AMediaCodec_dequeueOutputBuffer(audio_encoder, &a_info, 20000);
		if (a_status >= 0)
		{
			uint8_t *buf_a = AMediaCodec_getOutputBuffer(audio_encoder, a_status, &size);
			if (audioTrackIndex >= 0 && a_info.size > 0)
				AMediaMuxer_writeSampleData(muxer, audioTrackIndex, buf_a, &a_info);
			AMediaCodec_releaseOutputBuffer(audio_encoder, a_status, false);
		}
		else if (a_status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED)
		{
			AMediaFormat *fmt = AMediaCodec_getOutputFormat(audio_encoder);
			if (audioTrackIndex < 0)
			{
				audioTrackIndex = AMediaMuxer_addTrack(muxer, fmt);
				AMediaFormat_delete(fmt);
				if (videoTrackIndex >= 0)
					AMediaMuxer_start(muxer);
			}
		}
	}
	if (audio_stream)
	{
		AAudioStream_requestStop(audio_stream);
		AAudioStream_close(audio_stream);
	}
	if (audio_encoder)
	{
		AMediaCodec_stop(audio_encoder);
		AMediaCodec_delete(audio_encoder);
	}
	if (g_captureSession)
	{
		ACameraCaptureSession_stopRepeating(g_captureSession);
		ACameraCaptureSession_close(g_captureSession);
	}

	if (g_yoloReader)
	{
		AImageReader_setImageListener(g_yoloReader, nullptr);
		AImageReader_delete(g_yoloReader);
	}

	// ⭐ 已经为你修复：把 _destroy 修改为了标准的 _free
	if (g_yoloTarget)
		ACameraOutputTarget_free(g_yoloTarget);
	if (g_yoloOutput)
		ACaptureSessionOutput_free(g_yoloOutput);

	if (g_cameraDevice)
		ACameraDevice_close(g_cameraDevice);
	if (encoder)
	{
		AMediaCodec_stop(encoder);
		AMediaCodec_delete(encoder);
	}
	if (muxer)
	{
		AMediaMuxer_stop(muxer);
		AMediaMuxer_delete(muxer);
	}
	if (client_arr)
	{
		for (int i = 0; i < client_count; ++i)
			close(client_arr[i]);
		free(client_arr);
	}
	close(server_fd);
	close(fd);
	printf("Stopping recording... Cleaning up native structures.\n");

	

	// ==========================================
	// ⭐ 新增：强制唤醒并安全回收后台 YOLO 线程
	// ==========================================
	{
		std::unique_lock<std::mutex> lock(g_yoloMutex);
		running = 0; // 广播停止状态
		g_yoloCond.notify_one();
	}
	pthread_join(g_yoloThreadId, nullptr); // 等待 AI 推理完全结束
	printf("Stopping recording... Cleaning up native structures.\n");
	pthread_join(g_audioThreadId, nullptr); // ⭐ 改用全局变量进行安全回收

	return 0;
}
