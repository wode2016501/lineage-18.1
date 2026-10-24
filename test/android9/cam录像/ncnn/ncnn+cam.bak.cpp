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
// ==========================================
AImageReader* g_yoloReader = nullptr;
ANativeWindow* g_yoloWindow = nullptr;
ACaptureSessionOutput* g_yoloOutput = nullptr;
ACameraOutputTarget* g_yoloTarget = nullptr;
ncnn::Net g_yolov5; // 腾讯 NCNN 网络实例

// 💡 已经为你锁定 640x640 静态尺寸（与你的 PNNX 模型完美对齐）
const int YOLO_WIDTH = 640;
const int YOLO_HEIGHT = 640;
const int DETECTION_INTERVAL_MS = 1000; // 💡 扫描时延控制：1000毫秒（1秒跑一次 YOLO）

// ==========================================
// ⭐ 已为你对齐：AImageReader 硬件拦截回调与 YOLO 推理
// ==========================================
void onYoloFrameAvailable(void* context, AImageReader* reader) {
	 (void)context; // 💡 加上这一行，显式消除未使用参数的警告
    static auto last_detect_time = std::chrono::steady_clock::now();
    auto now = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - last_detect_time).count();

    AImage* image = nullptr;
    media_status_t status = AImageReader_acquireNextImage(reader, &image);
    if (status != AMEDIA_OK || image == nullptr) return; 

    // 定频跳帧拦截（1秒）
    if (duration < DETECTION_INTERVAL_MS) { 
        AImage_delete(image);
        return;
    }
    last_detect_time = now;

    uint8_t* y_data = nullptr;
    int y_len = 0;
    AImage_getPlaneData(image, 0, &y_data, &y_len);

    if (y_data != nullptr) {
        ncnn::Mat in = ncnn::Mat::from_pixels(y_data, ncnn::Mat::PIXEL_GRAY, YOLO_WIDTH, YOLO_HEIGHT);
        
        ncnn::Extractor ex = g_yolov5.create_extractor();
        ex.input("in0", in);   
        ncnn::Mat out;
        ex.extract("out0", out); 

        bool person_detected = false;
        
        // 🔍 针对新版 Ultralytics YOLOv5/v8 导出的 NCNN 矩阵深度解析：
        // 此时 out 的维度往往是 c=1, h=5, w=8400 (或者是 h=8400, w=5，取决于PNNX规整程度)
        // 5个属性通常排布在通道/行上，具体为：row(0)=x, row(1)=y, row(2)=w, row(3)=h, row(4)=人(person)的得分
        
        if (out.h == 5 || out.c == 5) {
            // 情况 A：属性在行(h)或通道(c)上，一共有 out.w 个锚框预测点
            int num_anchors = out.w;
            
            // 直接定位到第 4 行（即第 5 个属性：人的置信度得分分数线）
            // 如果 PNNX 把 5 压进了通道 c，则用 out.channel(4)；如果在行，则用 out.row(4)
            const float* score_ptr = (out.c == 5) ? (const float*)out.channel(4) : out.row(4);
            
            for (int i = 0; i < num_anchors; i++) {
                float class_score = score_ptr[i]; // 纯粹的人体分类得分
                
                // 新版去除了独立的 box_score，这边的得分直接就是最终置信度
                if (class_score > 0.65f) { // 强力门限阈值限制 0.65
                    person_detected = true;
                    break; 
                }
            }
        } 
        else if (out.w == 5) {
            // 情况 B：如果 PNNX 做了转置，每行代表一个锚框，宽(w)代表 5 个属性
            int num_anchors = out.h;
            for (int i = 0; i < num_anchors; i++) {
                const float* row_ptr = out.row(i);
                float class_score = row_ptr[4]; // 第 5 个元素是得分
                
                if (class_score > 0.65f) {
                    person_detected = true;
                    break;
                }
            }
        }
        else {
            // 情况 C：兜底普适解析（防止维度出现其他变形）
            float* data_ptr = (float*)out.data;
            int total_elements = out.w * out.h * out.c;
            // 假设每 5 个数一组，最后一位是得分
            for (int i = 4; i < total_elements; i += 5) {
                if (data_ptr[i] > 0.65f) {
                    person_detected = true;
                    break;
                }
            }
        }

        if (person_detected) {
            printf("有人\n"); 
            fflush(stdout);
        }
    }
    AImage_delete(image); 
}

void sigal_handler(int) {
	printf("sigal_handler\n");
	running = 0;
}

void onDeviceDisconnected(void *, ACameraDevice *) { printf("Camera Disconnected!\n"); }
void onDeviceError(void *, ACameraDevice *, int error) { printf("Camera Error: %d\n", error); }
ACameraDevice_StateCallbacks cameraDeviceCallbacks = {nullptr, onDeviceDisconnected, onDeviceError};

void onSessionActive(void *, ACameraCaptureSession *) { g_sessionActive = true; printf("Capture Session Active!\n"); }
void onSessionReady(void *, ACameraCaptureSession *) {}
void onSessionClosed(void *, ACameraCaptureSession *) {}
ACameraCaptureSession_stateCallbacks sessionCallbacks = {nullptr, onSessionClosed, onSessionReady, onSessionActive};

bool initAudioEncoder(int sampleRate, int channelCount, int bitrate) {
	AMediaFormat *audioFormat = AMediaFormat_new();
	AMediaFormat_setString(audioFormat, AMEDIAFORMAT_KEY_MIME, "audio/mp4a-latm");
	AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_SAMPLE_RATE, sampleRate);
	AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_CHANNEL_COUNT, channelCount);
	AMediaFormat_setInt32(audioFormat, AMEDIAFORMAT_KEY_BIT_RATE, bitrate);
	AMediaFormat_setInt32(audioFormat, "aac-profile", 2);
	audio_encoder = AMediaCodec_createEncoderByType("audio/mp4a-latm");
	if (!audio_encoder) return false;
	media_status_t status = AMediaCodec_configure(audio_encoder, audioFormat, nullptr, nullptr, AMEDIACODEC_CONFIGURE_FLAG_ENCODE);
	AMediaFormat_delete(audioFormat);
	if (status != AMEDIA_OK) return false;
	AMediaCodec_start(audio_encoder);
	return true;
}

bool initAAudio(int sampleRate, int channelCount) {
	AAudioStreamBuilder *builder = nullptr;
	aaudio_result_t result = AAudio_createStreamBuilder(&builder);
	if (result != AAUDIO_OK) return false;
	AAudioStreamBuilder_setDirection(builder, AAUDIO_DIRECTION_INPUT);
	AAudioStreamBuilder_setSampleRate(builder, sampleRate);
	AAudioStreamBuilder_setChannelCount(builder, channelCount);
	AAudioStreamBuilder_setFormat(builder, AAUDIO_FORMAT_PCM_I16);
	AAudioStreamBuilder_setInputPreset(builder, AAUDIO_INPUT_PRESET_VOICE_RECOGNITION);
	result = AAudioStreamBuilder_openStream(builder, &audio_stream);
	AAudioStreamBuilder_delete(builder);
	if (result != AAUDIO_OK) return false;
	return AAudioStream_requestStart(audio_stream) == AAUDIO_OK;
}

void *audio_polling_thread(void *) {
	const int SAMPLES_PER_FRAME = 1024;
	int channelCount = 1;
	int16_t *pcmBuffer = new int16_t[SAMPLES_PER_FRAME * channelCount];
	while (running) {
		aaudio_result_t framesRead = AAudioStream_read(audio_stream, pcmBuffer, SAMPLES_PER_FRAME, 20000000);
		if (framesRead > 0) {
			ssize_t inputBufIdx = AMediaCodec_dequeueInputBuffer(audio_encoder, 10000);
			if (inputBufIdx >= 0) {
				size_t bufSize;
				uint8_t *codecInputBuf = AMediaCodec_getInputBuffer(audio_encoder, inputBufIdx, &bufSize);
				int bytesToCopy = framesRead * channelCount * sizeof(int16_t);
				if (bytesToCopy > (int)bufSize) bytesToCopy = bufSize;
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

void *sh_thread(void *arg) {
	char cmd[1255];
	sprintf(cmd, "sh %s", (const char *)arg);
	system(cmd);
	running = 0;
	return nullptr;
}

void settcp(int client_fd) {
	struct timeval timeout = {1, 0};
	setsockopt(client_fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
}

int client_connect(int server_fd) {
	struct sockaddr_in6 client_addr;
	int addrlen = sizeof(struct sockaddr_in6);
	int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
	if (client_fd < 0) return -1;
	if (IN6_IS_ADDR_LOOPBACK(&client_addr.sin6_addr) || 
	   (IN6_IS_ADDR_V4MAPPED(&client_addr.sin6_addr) && client_addr.sin6_addr.s6_addr[12] == 127)) {
		close(client_fd);
		return -1;
	}
	settcp(client_fd);
	return client_fd;
}

int sendd(int client_fd, char *buf, int ssize) {
	int ret = 0, size = 0;
	while ((ssize - size) > 0) {
		ret = write(client_fd, buf, ssize - size);
		if (ret < 1) return -1;
		buf += ret; size += ret;
	}
	return size;
}
int main(int argc, char **argv) {
	signal(SIGPIPE, SIG_IGN);
	int port = 10000;
	const char *sh_file = nullptr;
	const char *file = "/sdcard/native_record.mp4";
	int bitrate = 2000000, width = 1920, height = 1080;
	char bbuffer[255];
	int *Width = (int *)bbuffer; int *Height = (int *)(bbuffer + 4);
	*Height = height; *Width = width;
	int *sps_size = (int *)(bbuffer + 8); char *sps_buf = bbuffer + 12;
	int client_max = 10, client_count = 0;
	int *client_arr = (int *)malloc(sizeof(int) * client_max);
	fd_set wd_set, rd_set; int maxfd = 0; size_t size = 0;

	if (argc > 1) file = argv[1];
	if (argc > 2) bitrate = atoi(argv[2]);
	if (argc > 3) sh_file = argv[3];

	int fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd < 0) { free(client_arr); return fd; }
	if (sh_file) { pthread_t shThread; pthread_create(&shThread, nullptr, sh_thread, (void *)sh_file); }

	signal(SIGINT, sigal_handler);
	struct sockaddr_in6 server_addr;
	int server_fd = socket(AF_INET6, SOCK_STREAM, 0);
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin6_family = AF_INET6; server_addr.sin6_addr = in6addr_any; server_addr.sin6_port = htons(port);
	int opt = 1; setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	int v6only = 0; setsockopt(server_fd, IPPROTO_IPV6, IPV6_V6ONLY, &v6only, sizeof(v6only));
	bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(server_fd, 1);

	sp<SurfaceComposerClient> client = new SurfaceComposerClient();
	client->initCheck();
// Android 9 中使用 ISurfaceComposer::eDisplayIdMain 代表主屏幕
sp<IBinder> dtoken = SurfaceComposerClient::getBuiltInDisplay(ISurfaceComposer::eDisplayIdMain);
	
	DisplayInfo dinfo; SurfaceComposerClient::getDisplayInfo(dtoken, &dinfo);
	sp<SurfaceControl> surfaceControl = client->createSurface(String8("CameraNativePreview"), width / 2, height / 2, PIXEL_FORMAT_RGBA_8888, 0);
	
	SurfaceComposerClient::Transaction t;
	t.setLayerStack(surfaceControl, 0).setLayer(surfaceControl, 0x7FFFFFFF).setPosition(surfaceControl, 0, 960 - height / 2)
	 .setAlpha(surfaceControl, 0.65f).show(surfaceControl).apply();

	sp<Surface> previewSurface = surfaceControl->getSurface();
	ANativeWindow *previewWindow = previewSurface.get();

	AMediaFormat *format = AMediaFormat_new();
	AMediaFormat_setString(format, AMEDIAFORMAT_KEY_MIME, "video/avc");
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_WIDTH, width); AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_HEIGHT, height);
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_BIT_RATE, bitrate); AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_FRAME_RATE, 30);
	AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_I_FRAME_INTERVAL, 1); AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_COLOR_FORMAT, 2130708361);
	encoder = AMediaCodec_createEncoderByType("video/avc");
	AMediaCodec_configure(encoder, format, nullptr, nullptr, AMEDIACODEC_CONFIGURE_FLAG_ENCODE);
	ANativeWindow *encoderWindow = nullptr; AMediaCodec_createInputSurface(encoder, &encoderWindow);
	muxer = AMediaMuxer_new(fd, AMEDIAMUXER_OUTPUT_FORMAT_MPEG_4);
	AMediaCodec_start(encoder); AMediaFormat_delete(format);
	initAudioEncoder(44100, 1, 64000); initAAudio(44100, 1);

	// ⭐ NCNN 加载
	g_yolov5.opt.lightmode = true; g_yolov5.opt.num_threads = 4; g_yolov5.opt.use_vulkan_compute = false;
	g_yolov5.load_param("yolov5_opt.param"); g_yolov5.load_model("yolov5_opt.bin");

	// ⭐ ImageReader
	AImageReader_new(YOLO_WIDTH, YOLO_HEIGHT, AIMAGE_FORMAT_YUV_420_888, 2, &g_yoloReader);
	AImageReader_getWindow(g_yoloReader, &g_yoloWindow);
	ACaptureSessionOutput_create(g_yoloWindow, &g_yoloOutput); ACameraOutputTarget_create(g_yoloWindow, &g_yoloTarget);
	AImageReader_ImageListener listener = {nullptr, onYoloFrameAvailable};
	AImageReader_setImageListener(g_yoloReader, &listener);

	ACameraManager *cameraManager = ACameraManager_create();
	while (1) { if (ACameraManager_openCamera(cameraManager, "0", &cameraDeviceCallbacks, &g_cameraDevice) == ACAMERA_OK) break; sleep(1); }

	ACaptureSessionOutputContainer *outputContainer = nullptr; ACaptureSessionOutputContainer_create(&outputContainer);
	ACaptureSessionOutput *previewOutput = nullptr; ACaptureSessionOutput_create(previewWindow, &previewOutput); ACaptureSessionOutputContainer_add(outputContainer, previewOutput);
	ACaptureSessionOutput *recordingOutput = nullptr; ACaptureSessionOutput_create(encoderWindow, &recordingOutput); ACaptureSessionOutputContainer_add(outputContainer, recordingOutput);
	if (g_yoloOutput) ACaptureSessionOutputContainer_add(outputContainer, g_yoloOutput);

	ACameraDevice_createCaptureSession(g_cameraDevice, outputContainer, &sessionCallbacks, &g_captureSession);
	ACaptureRequest *captureRequest = nullptr; ACameraDevice_createCaptureRequest(g_cameraDevice, TEMPLATE_RECORD, &captureRequest);
	ACameraOutputTarget *previewTarget = nullptr; ACameraOutputTarget_create(previewWindow, &previewTarget); ACaptureRequest_addTarget(captureRequest, previewTarget);
	ACameraOutputTarget *recordingTarget = nullptr; ACameraOutputTarget_create(encoderWindow, &recordingTarget); ACaptureRequest_addTarget(captureRequest, recordingTarget);
	if (g_yoloTarget) ACaptureRequest_addTarget(captureRequest, g_yoloTarget);

	ACameraCaptureSession_setRepeatingRequest(g_captureSession, nullptr, 1, &captureRequest, nullptr);

	pthread_t audioThread; pthread_create(&audioThread, nullptr, audio_polling_thread, nullptr);
	AMediaCodecBufferInfo v_info, a_info; uint8_t *nalu_data = nullptr; int client_fd = 0, out_size = 0; uint8_t *buffer = nullptr; struct timeval tv = {0, 0};

	while (running) {
		ssize_t v_status = AMediaCodec_dequeueOutputBuffer(encoder, &v_info, 20000);
		if (v_status >= 0) {
			buffer = AMediaCodec_getOutputBuffer(encoder, v_status, &size);
			if (videoTrackIndex >= 0 && v_info.size > 0) {
				FD_ZERO(&wd_set); FD_ZERO(&rd_set); FD_SET(server_fd, &rd_set); maxfd = server_fd;
				for (int i = 0; i < client_count; ++i) { FD_SET(client_arr[i], &wd_set); if (client_arr[i] > maxfd) maxfd = client_arr[i]; }
				if (select(maxfd + 1, &rd_set, &wd_set, nullptr, &tv) >= 0) {
					nalu_data = buffer + v_info.offset;
					if ((nalu_data[4] & 0x1f) == 5 && FD_ISSET(server_fd, &rd_set)) {
						client_fd = client_connect(server_fd);
						if (client_fd >= 0) {
							out_size = 8; sendd(client_fd, (char *)bbuffer, out_size);
							client_arr[client_count++] = client_fd;
						}
					}
					for (int i = 0; i < client_count; i++) {
						if (FD_ISSET(client_arr[i], &wd_set)) {
							out_size = v_info.size; if (client_fd == client_arr[i]) out_size += *sps_size;
							sendd(client_arr[i], (char *)&out_size, sizeof(int));
							if (client_fd == client_arr[i]) { sendd(client_arr[i], sps_buf, *sps_size); client_fd = 0; }
							sendd(client_arr[i], (char *)nalu_data, v_info.size);
						}
					}
				}
				AMediaMuxer_writeSampleData(muxer, videoTrackIndex, buffer, &v_info);
			}
			AMediaCodec_releaseOutputBuffer(encoder, v_status, false);
		}
		if (v_status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
			AMediaFormat *fmt = AMediaCodec_getOutputFormat(encoder); char *p = nullptr;
			if (AMediaFormat_getBuffer(fmt, "csd-0", (void **)&p, &size) && p) { memcpy(sps_buf, p, size); *sps_size = size; }
			if (AMediaFormat_getBuffer(fmt, "csd-1", (void **)&p, &size) && p) { memcpy(sps_buf + *sps_size, p, size); *sps_size += size; }
			if (videoTrackIndex < 0) { videoTrackIndex = AMediaMuxer_addTrack(muxer, fmt); AMediaFormat_delete(fmt); if (audioTrackIndex >= 0) AMediaMuxer_start(muxer); }
		}
		ssize_t a_status = AMediaCodec_dequeueOutputBuffer(audio_encoder, &a_info, 20000);
		if (a_status >= 0) {
			uint8_t *buf_a = AMediaCodec_getOutputBuffer(audio_encoder, a_status, &size);
			if (audioTrackIndex >= 0 && a_info.size > 0) AMediaMuxer_writeSampleData(muxer, audioTrackIndex, buf_a, &a_info);
			AMediaCodec_releaseOutputBuffer(audio_encoder, a_status, false);
		} else if (a_status == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED) {
			AMediaFormat *fmt = AMediaCodec_getOutputFormat(audio_encoder);
			if (audioTrackIndex < 0) { audioTrackIndex = AMediaMuxer_addTrack(muxer, fmt); AMediaFormat_delete(fmt); if (videoTrackIndex >= 0) AMediaMuxer_start(muxer); }
		}
	}
	pthread_join(audioThread, nullptr);
	if (audio_stream) { AAudioStream_requestStop(audio_stream); AAudioStream_close(audio_stream); }
	if (audio_encoder) { AMediaCodec_stop(audio_encoder); AMediaCodec_delete(audio_encoder); }
	if (g_captureSession) { ACameraCaptureSession_stopRepeating(g_captureSession); ACameraCaptureSession_close(g_captureSession); }
	
	if (g_yoloReader) { AImageReader_setImageListener(g_yoloReader, nullptr); AImageReader_delete(g_yoloReader); }
	
	// ⭐ 已经为你修复：把 _destroy 修改为了标准的 _free
	if (g_yoloTarget) ACameraOutputTarget_free(g_yoloTarget);
	if (g_yoloOutput) ACaptureSessionOutput_free(g_yoloOutput);

	if (g_cameraDevice) ACameraDevice_close(g_cameraDevice);
	if (encoder) { AMediaCodec_stop(encoder); AMediaCodec_delete(encoder); }
	if (muxer) { AMediaMuxer_stop(muxer); AMediaMuxer_delete(muxer); }
	if (client_arr) { for (int i = 0; i < client_count; ++i) close(client_arr[i]); free(client_arr); }
	close(server_fd); close(fd);
	return 0;
}

