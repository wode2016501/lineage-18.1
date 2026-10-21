#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>

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
AMediaExtractor *extractor=nullptr;
int64_t getNowUs()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int64_t)tv.tv_sec * 1000000ll + tv.tv_usec;
}

void *video_in_func(void *arg)
{
    return nullptr;
}
void *audio_in_func(void *arg)
{
    return nullptr;
}
void *audio_out_func(void *arg)
{
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

    // 2. 初始化 Extractor 分离器
    extractor = AMediaExtractor_new();
    AMediaExtractor_setDataSourceFd(extractor, fd, 0, fileSize);

    sp<AudioTrack> nativeAudioTrack = nullptr; // 用智能指针管理 AudioTrack 生命周期

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
                AMediaExtractor_selectTrack(extractor, i);
                videoCodec = AMediaCodec_createDecoderByType(mime);
                AMediaCodec_configure(videoCodec, trackFormat, window, NULL, 0);
            }
            else if (strncmp(mime, "audio/", 6) == 0 && audioTrackIdx == -1)
            {
                audioTrackIdx = i;
                AMediaExtractor_selectTrack(extractor, i);
                audioCodec = AMediaCodec_createDecoderByType(mime);
                AMediaCodec_configure(audioCodec, trackFormat, NULL, NULL, 0);

                int32_t sampleRate = 44100;
                int32_t channelCount = 2;
                AMediaFormat_getInt32(trackFormat, AMEDIAFORMAT_KEY_SAMPLE_RATE, &sampleRate);
                AMediaFormat_getInt32(trackFormat, AMEDIAFORMAT_KEY_CHANNEL_COUNT, &channelCount);

                // 根据通道数计算通道掩码
                audio_channel_mask_t channelMask = (channelCount == 1) ? AUDIO_CHANNEL_OUT_MONO : AUDIO_CHANNEL_OUT_STEREO;

                // 🚀 【完美契合 Android 10】强行创建原生 C++ AudioTrack 对象
                nativeAudioTrack = new AudioTrack(
                    AUDIO_STREAM_MUSIC,      // 流类型
                    (uint32_t)sampleRate,    // 采样率
                    AUDIO_FORMAT_PCM_16_BIT, // 16位采样
                    channelMask,             // 掩码
                    0,                       // 默认缓冲帧数
                    AUDIO_OUTPUT_FLAG_NONE,  // 默认标志位
                    nullptr, nullptr,        // 无回调（我们使用同步 write 写入模式）
                    0                        // 默认通知帧数
                );

                if (nativeAudioTrack != nullptr && nativeAudioTrack->initCheck() == NO_ERROR)
                {
                    nativeAudioTrack->start(); // 开启音轨硬件
                    printf("[音频] 原生 C++ AudioTrack 启动成功！采样率: %d, 通道: %d\n", sampleRate, channelCount);
                }
                else
                {
                    fprintf(stderr, "[错误] 底层 AudioTrack 初始化失败！\n");
                }
            }
        }
        AMediaFormat_delete(trackFormat);
    }

    if (videoCodec)
        AMediaCodec_start(videoCodec);
    if (audioCodec)
        AMediaCodec_start(audioCodec);

    // 3. 编解码播放主循环
    AMediaCodecBufferInfo vInfo, aInfo;
    bool isPlaying = true;
    bool videoEOS = (videoCodec == nullptr);
    bool audioEOS = (audioCodec == nullptr);
    int64_t startTimeUs = getNowUs();

    while (isPlaying && (!videoEOS || !audioEOS))
    {
        int activeTrack = AMediaExtractor_getSampleTrackIndex(extractor);
        if (activeTrack >= 0)
        {
            AMediaCodec *targetCodec = (activeTrack == videoTrackIdx) ? videoCodec : audioCodec;
            bool targetEOS = (activeTrack == videoTrackIdx) ? videoEOS : audioEOS;

            if (targetCodec && !targetEOS)
            {
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(targetCodec, 1000);
                if (inIdx >= 0)
                {
                    size_t bufSize;
                    uint8_t *buf = AMediaCodec_getInputBuffer(targetCodec, inIdx, &bufSize);
                    ssize_t sampleSize = AMediaExtractor_readSampleData(extractor, buf, bufSize);

                    if (sampleSize < 0)
                    {
                        AMediaCodec_queueInputBuffer(targetCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                        if (activeTrack == videoTrackIdx)
                            videoEOS = true;
                        if (activeTrack == audioTrackIdx)
                            audioEOS = true;
                    }
                    else
                    {
                        int64_t pts = AMediaExtractor_getSampleTime(extractor);
                        AMediaCodec_queueInputBuffer(targetCodec, inIdx, 0, sampleSize, pts, 0);
                        AMediaExtractor_advance(extractor);
                    }
                }
            }
        }
        else if (activeTrack == -1)
        {
            if (!videoEOS && videoCodec)
            {
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(videoCodec, 1000);
                if (inIdx >= 0)
                    AMediaCodec_queueInputBuffer(videoCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                videoEOS = true;
            }
            if (!audioEOS && audioCodec)
            {
                ssize_t inIdx = AMediaCodec_dequeueInputBuffer(audioCodec, 1000);
                if (inIdx >= 0)
                    AMediaCodec_queueInputBuffer(audioCodec, inIdx, 0, 0, 0, AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM);
                audioEOS = true;
            }
        }

        // 刷视频帧
        if (videoCodec)
        {
            ssize_t outVIdx = AMediaCodec_dequeueOutputBuffer(videoCodec, &vInfo, 1000);
            if (outVIdx >= 0)
            {
                if (vInfo.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM)
                    isPlaying = false;
                int64_t elapsedTimeUs = getNowUs() - startTimeUs;
                int64_t sleepTimeUs = vInfo.presentationTimeUs - elapsedTimeUs;
                if (sleepTimeUs > 0)
                    usleep(sleepTimeUs);
                AMediaCodec_releaseOutputBuffer(videoCodec, outVIdx, true);
            }
        }

        // 🚀 【原生输出】刷音频帧投递给 AudioTrack
        if (audioCodec && nativeAudioTrack != nullptr)
        {
            ssize_t outAIdx = AMediaCodec_dequeueOutputBuffer(audioCodec, &aInfo, 1000);
            if (outAIdx >= 0)
            {
                size_t outBufSize;
                uint8_t *pcmBuf = AMediaCodec_getOutputBuffer(audioCodec, outAIdx, &outBufSize);
                if (pcmBuf != nullptr && aInfo.size > 0)
                {
                    // 直接调用原生底层系统的 write 方法
                    nativeAudioTrack->write(pcmBuf + aInfo.offset, aInfo.size);
                }
                AMediaCodec_releaseOutputBuffer(audioCodec, outAIdx, false);
            }
        }
    }

    // 清理资源
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
        nativeAudioTrack.clear();
    }
    AMediaExtractor_delete(extractor);
    close(fd);
    printf("原生双硬解播放结束！\n");
    return 0;
}
