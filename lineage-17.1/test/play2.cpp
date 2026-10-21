#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <limits.h>

#include <gui/SurfaceComposerClient.h>
#include <gui/Surface.h>
#include <ui/DisplayInfo.h>
#include <android/native_window.h>

#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <media/NdkMediaExtractor.h>

// 🚀 引入真正的底层 C++ AudioTrack
#include <media/AudioTrack.h>
// 添加多线程
#include <pthread.h>

using namespace android;

int win_width = 1280;
int win_height = 720;
AMediaCodec *videoCodec = nullptr;
AMediaCodec *audioCodec = nullptr;

// 线程全局退出标志
bool gIsPlaying = true;

int64_t getNowUs()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int64_t)tv.tv_sec * 1000000ll + tv.tv_usec;
}

// 定义音频线程需要的参数结构体
struct AudioThreadArgs
{
    int fd;
    off_t fileSize;
    sp<AudioTrack> nativeAudioTrack;
};

// 🎵 音频独立线程：负责音频的 Extractor 读取、解码 Input 和 Output 刷新
void *audio_thread_func(void *arg)
{
    printf("[音频线程] 启动...\n");
    AudioThreadArgs *args = (AudioThreadArgs *)arg;

    // 1. 音频线程创建自己独立的 Extractor (使用 dup 复制文件描述符避免冲突)
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
        fprintf(stderr, "[音频线程] 未找到音频轨！\n");
        AMediaExtractor_delete(audioExtractor);
        delete args;
        return nullptr;
    }

    AMediaCodecBufferInfo aInfo;
    bool audioInputEOS = false;
    bool audioOutputEOS = false;

    while (gIsPlaying && !audioOutputEOS)
    {
        // ---- 1. 音频 Input 提取与入队 ----
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
            { // 媒体流结束
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(audioCodec, 1000);
                if (inIdx >= 0)
                {
                    AMediaCodec_queueInputBuffer(audioCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                }
                audioInputEOS = true;
            }
        }

        // ---- 2. 音频 Output 刷新与播放 ----
        ssize_t outAIdx = AMediaCodec_dequeueOutputBuffer(audioCodec, &aInfo, 1000);
        if (outAIdx >= 0)
        {
            if (aInfo.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM)
            {
                audioOutputEOS = true;
            }

            if (aInfo.size > 0 && args->nativeAudioTrack != nullptr)
            {
                size_t outBufSize;
                uint8_t *pcmBuf = AMediaCodec_getOutputBuffer(audioCodec, outAIdx, &outBufSize);
                if (pcmBuf != nullptr)
                {
                    // 写入 C++ AudioTrack 硬件播放 (此处采用同步阻塞写入)
                    args->nativeAudioTrack->write(pcmBuf + aInfo.offset, aInfo.size);
                }
            }
            AMediaCodec_releaseOutputBuffer(audioCodec, outAIdx, false);
        }
    }

    printf("[音频线程] 结束退出。\n");
    AMediaExtractor_delete(audioExtractor);
    delete args;
    return nullptr;
}

int main(int argc, char *argv[])
{
    printf("--- Pure C++ Player (720p + Native AudioTrack) Start ---\n");

    if (argc < 2)
    {
        fprintf(stderr, "[错误] 请指定视频文件路径！\n");
        return 1;
    }

    const char *video_path = argv[1];
    int fd = open(video_path, O_RDONLY);
    if (fd < 0)
    {
        fprintf(stderr, "[错误] 无法打开文件: %s\n", video_path);
        return 1;
    }
    off_t fileSize = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    // 1. 初始化 SurfaceFlinger 720p 窗口
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    sp<SurfaceControl> surfaceControl = client->createSurface(String8("PureCpp720pWindow"), win_width, win_height, PIXEL_FORMAT_RGBA_8888, 0);

    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF).setPosition(surfaceControl, 0, 200).setSize(surfaceControl, win_width, win_height).show(surfaceControl).apply();
    ANativeWindow *window = surfaceControl->getSurface().get();

    // 2. 主线程初始化用于【视频】的 Extractor 分离器
    AMediaExtractor *videoExtractor = AMediaExtractor_new();
    AMediaExtractor_setDataSourceFd(videoExtractor, fd, 0, fileSize);

    sp<AudioTrack> nativeAudioTrack = nullptr;
    int videoTrackIdx = -1;
    int audioTrackIdx = -1;

    int numTracks = AMediaExtractor_getTrackCount(videoExtractor);
    for (int i = 0; i < numTracks; i++)
    {
        AMediaFormat *trackFormat = AMediaExtractor_getTrackFormat(videoExtractor, i);
        const char *mime = nullptr;
        AMediaFormat_getString(trackFormat, AMEDIAFORMAT_KEY_MIME, &mime);

        if (mime != nullptr)
        {
            if (strncmp(mime, "video/", 6) == 0 && videoTrackIdx == -1)
            {
                videoTrackIdx = i;
                AMediaExtractor_selectTrack(videoExtractor, i);
                videoCodec = AMediaCodec_createDecoderByType(mime);
                AMediaCodec_configure(videoCodec, trackFormat, window, NULL, 0);
            }
            else if (strncmp(mime, "audio/", 6) == 0 && audioTrackIdx == -1)
            {
                audioTrackIdx = i;
                // 注意：主线程的 videoExtractor 不需要 select 音频轨
                audioCodec = AMediaCodec_createDecoderByType(mime);
                AMediaCodec_configure(audioCodec, trackFormat, NULL, NULL, 0);

                int32_t sampleRate = 44100;
                int32_t channelCount = 2;
                AMediaFormat_getInt32(trackFormat, AMEDIAFORMAT_KEY_SAMPLE_RATE, &sampleRate);
                AMediaFormat_getInt32(trackFormat, AMEDIAFORMAT_KEY_CHANNEL_COUNT, &channelCount);

                audio_channel_mask_t channelMask = (channelCount == 1) ? AUDIO_CHANNEL_OUT_MONO : AUDIO_CHANNEL_OUT_STEREO;

                nativeAudioTrack = new AudioTrack(
                    AUDIO_STREAM_MUSIC, (uint32_t)sampleRate, AUDIO_FORMAT_PCM_16_BIT,
                    channelMask, 0, AUDIO_OUTPUT_FLAG_NONE, nullptr, nullptr, 0);

                if (nativeAudioTrack != nullptr && nativeAudioTrack->initCheck() == NO_ERROR)
                {
                    nativeAudioTrack->start();
                    printf("[音频] 原生 C++ AudioTrack 准备就绪。\n");
                }
            }
        }
        AMediaFormat_delete(trackFormat);
    }

    if (videoCodec)
        AMediaCodec_start(videoCodec);
    if (audioCodec)
        AMediaCodec_start(audioCodec);

    // 3. 🚀 创建并启动音频独立的子线程
    pthread_t audioThread;
    if (audioCodec && nativeAudioTrack != nullptr)
    {
        AudioThreadArgs *args = new AudioThreadArgs();
        args->fd = fd;
        args->fileSize = fileSize;
        args->nativeAudioTrack = nativeAudioTrack;
        pthread_create(&audioThread, nullptr, audio_thread_func, args);
    }

    // 4. 📺 【主线程】全权负责：视频数据 Input 读取 + 视频 Output 刷新显示
    AMediaCodecBufferInfo vInfo;
    bool videoInputEOS = (videoCodec == nullptr);
    bool videoOutputEOS = (videoCodec == nullptr);
    int64_t startTimeUs = getNowUs();

    printf("[主线程] 开始刷新视频...\n");
    while (gIsPlaying && !videoOutputEOS)
    {

        // ---- 4.1 视频 Input 提取入队 ----
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
            { // 提取器结束
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(videoCodec, 1000);
                if (inIdx >= 0)
                {
                    AMediaCodec_queueInputBuffer(videoCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                }
                videoInputEOS = true;
            }
        }

        // ---- 4.2 视频 Output 刷新渲染（带音视频同步控制） ----
        if (videoCodec)
        {
            ssize_t outVIdx = AMediaCodec_dequeueOutputBuffer(videoCodec, &vInfo, 1000);
            if (outVIdx >= 0)
            {
                if (vInfo.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM)
                {
                    videoOutputEOS = true;
                    gIsPlaying = false; // 通知音频线程也退出
                }
                // 基于系统时间的简易同步：计算视频帧渲染应该等待的延迟
                int64_t elapsedTimeUs = getNowUs() - startTimeUs;
                int64_t sleepTimeUs = vInfo.presentationTimeUs - elapsedTimeUs;
                if (sleepTimeUs > 0)
                {
                    usleep(sleepTimeUs);
                }
                // 刷新渲染到 Surface
                AMediaCodec_releaseOutputBuffer(videoCodec, outVIdx, true);
            }
        }
    }
    // 5. 资源释放与线程回收
    gIsPlaying = false;
    if (audioCodec && nativeAudioTrack != nullptr)
    {
        pthread_join(audioThread, nullptr);
    }
    printf("--- 播放结束，释放资源 ---\n");
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
    {
        nativeAudioTrack->stop();
    }
    AMediaExtractor_delete(videoExtractor);
    close(fd);
    return 0;
}