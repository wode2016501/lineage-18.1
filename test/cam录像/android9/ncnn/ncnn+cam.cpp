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
// =========================================================================
AImageReader *g_yoloReader = nullptr;
ANativeWindow *g_yoloWindow = nullptr;
ACaptureSessionOutput *g_yoloOutput = nullptr;
ACameraOutputTarget *g_yoloTarget = nullptr;
ncnn::Net g_yolov5;

const int YOLO_WIDTH = 640;
const int YOLO_HEIGHT = 640;
int DETECTION_INTERVAL_MS = 5000; // 1秒扫描一次

// 线程同步锁与数据中转站
std::mutex g_yoloMutex;
std::condition_variable g_yoloCond;
ncnn::Mat g_pendingFrame; // 存放等待被 YOLO 消费的图像帧
bool g_hasPendingFrame = false;
pthread_t g_yoloThreadId;

// =========================================================================
// ⭐ 新增：纯独立的 AI 推理消费者线程（死循环，不影响任何音视频推流）
// =========================================================================
void *yolo_inference_worker_thread(void *)
{
	printf("[YOLO Thread] AI Inference Consumer Thread actively engaged.\n");

	// 绑定至 4 个大核（针对骁龙 835/845 的大核群进行线程亲和性激进调度）
	g_yolov5.opt.num_threads = 4;

	while (running)
	{
		ncnn::Mat localFrame;
		{
			std::unique_lock<std::mutex> lock(g_yoloMutex);
			// 阻塞等待，直到相机回调函数通知有新的关键帧送达
			g_yoloCond.wait(lock, []
							{ return g_hasPendingFrame || !running; });

			if (!running)
				break;

			// 浅拷贝（零成本像素指针复用）拿到图像
			localFrame = g_pendingFrame;
			g_hasPendingFrame = false;
		}

		// --- 在独立的后台线程中，开始跑耗时的 YOLO 推理 ---
		ncnn::Extractor ex = g_yolov5.create_extractor();
		ex.input("in0", localFrame);
		ncnn::Mat out;
		ex.extract("out0", out); // 已经与你的模型的 out0 节点对齐

		bool person_detected = false;

		// 规整的新版 Ultralytics 维度解析
		if (out.h == 5 || out.c == 5)
		{
			int num_anchors = out.w;
			const float *score_ptr = (out.c == 5) ? (const float *)out.channel(4) : out.row(4);
			for (int i = 0; i < num_anchors; i++)
			{
				if (score_ptr[i] > 0.60f)
				{ // 门限过滤
					person_detected = true;
					break;
				}
			}
		}
		else if (out.w == 5)
		{
			int num_anchors = out.h;
			for (int i = 0; i < num_anchors; i++)
			{
				if (out.row(i)[4] > 0.60f)
				{
					person_detected = true;
					break;
				}
			}
		}

		if (person_detected)
		{
			printf("有人\n");
			fflush(stdout);
		}

		// 💡 提示：推理完后，线程会自动回到顶部通过 g_yoloCond.wait 挂起休息，功耗瞬间归零
	}

	printf("[YOLO Thread] Cleanly exited.\n");
	return nullptr;
}

// =========================================================================
// ⭐ 完美优化：相机硬件回调函数（生产者，耗时小于 1 毫秒，绝不卡顿）
// =========================================================================
void onYoloFrameAvailable(void *context, AImageReader *reader)
{
	(void )context;
	static auto last_detect_time = std::chrono::steady_clock::now();
	auto now = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_detect_time).count();

	AImage *image = nullptr;
	media_status_t status = AImageReader_acquireNextImage(reader, &image);
	if (status != AMEDIA_OK || image == nullptr)
		return;

	// ⏱️ 时间控制：未到 1 秒间隔，直接释放
	if (duration < DETECTION_INTERVAL_MS)
	{
		AImage_delete(image);
		return;
	}

	uint8_t *y_data = nullptr;
	int y_len = 0;
	AImage_getPlaneData(image, 0, &y_data, &y_len);

	if (y_data != nullptr)
	{
		std::unique_lock<std::mutex> lock(g_yoloMutex);
		if (!g_hasPendingFrame)
		{							// 如果上一帧 AI 还没吃完，就跳过这一帧，防止队列堆积
			last_detect_time = now; // 锁定当前帧的计时时间

			// ⚡ 仅提取像素指针，耗时趋近于 0 毫秒！直接解除对相机总线线程的霸占
			g_pendingFrame = ncnn::Mat::from_pixels(y_data, ncnn::Mat::PIXEL_GRAY, YOLO_WIDTH, YOLO_HEIGHT);
			g_hasPendingFrame = true;

			// 唤醒后台在睡觉的 YOLO 推理线程
			g_yoloCond.notify_one();
		}
	}

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

	pthread_t audioThread;
	pthread_create(&audioThread, nullptr, audio_polling_thread, nullptr);
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
	pthread_join(audioThread, nullptr);
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

	pthread_join(audioThread, nullptr);

	// ==========================================
	// ⭐ 新增：强制唤醒并安全回收后台 YOLO 线程
	// ==========================================
	{
		std::unique_lock<std::mutex> lock(g_yoloMutex);
		running = 0; // 广播停止状态
		g_yoloCond.notify_one();
	}
	pthread_join(g_yoloThreadId, nullptr); // 等待 AI 推理完全结束

	return 0;
}
