#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#include <gui/SurfaceComposerClient.h>
#include <gui/Surface.h>
#include <ui/DisplayInfo.h>
#include <android/native_window.h>

#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <media/NdkMediaExtractor.h>

#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>

using namespace android;

int win_width = 1280;
int win_height = 720;

// OpenSL ES 核心全局变量
SLObjectItf engineObject = NULL;
SLEngineItf engineEngine = NULL;
SLObjectItf outputMixObject = NULL;
SLObjectItf bqPlayerObject = NULL;
SLPlayItf bqPlayerPlay = NULL;
SLAndroidSimpleBufferQueueItf bqPlayerBufferQueue = NULL;

// 拖动（Seek）控制全局变量
pthread_mutex_t seekMutex = PTHREAD_MUTEX_INITIALIZER;
int64_t seekTargetUs = -1;
bool isSeeking = false;
int64_t baseTimeOffsetUs = 0;
int64_t currentVideoPtsUs = 0;

int64_t getNowUs()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int64_t)tv.tv_sec * 1000000ll + tv.tv_usec;
}

// 异步键盘输入监听线程
void *inputThreadFunc(void *arg)
{
    char input[64];
    printf("\n========= 🎬 拖动控制交互已启用 =========\n");
    printf("你可以随时在当前终端输入并回车：\n");
    printf("1. 直接输入秒数跳转。例如: 60 (跳到第60秒)\n");
    printf("2. 快进快退。例如: +10 (快进10秒), -5 (快退5秒)\n");
    printf("=========================================\n\n");

    while (true)
    {
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            input[strcspn(input, "\n")] = 0;
            if (strlen(input) == 0)
                continue;

            int64_t targetUs = -1;
            pthread_mutex_lock(&seekMutex);

            if (input[0] == '+' || input[0] == '-')
            {
                long long deltaSeconds = atoll(input);
                printf("[控制] 尝试相对跳转 %lld 秒...\n", deltaSeconds);
                seekTargetUs = -2 - deltaSeconds;
            }
            else
            {
                long long absoluteSeconds = atoll(input);
                if (absoluteSeconds >= 0)
                {
                    targetUs = absoluteSeconds * 1000000ll;
                    printf("[控制] 尝试跳转到绝对位置: %lld 秒\n", absoluteSeconds);
                    seekTargetUs = targetUs;
                }
            }
            pthread_mutex_unlock(&seekMutex);
        }
    }
    return NULL;
}

bool initOpenSLES(int sampleRate, int channels)
{
    SLresult result;
    result = slCreateEngine(&engineObject, 0, NULL, 0, NULL, NULL);
    if (result != SL_RESULT_SUCCESS)
        return false;
    result = (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
    if (result != SL_RESULT_SUCCESS)
        return false;
    result = (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineEngine);
    if (result != SL_RESULT_SUCCESS)
        return false;

    result = (*engineEngine)->CreateOutputMix(engineEngine, &outputMixObject, 0, NULL, NULL);
    if (result != SL_RESULT_SUCCESS)
        return false;
    result = (*outputMixObject)->Realize(outputMixObject, SL_BOOLEAN_FALSE);
    if (result != SL_RESULT_SUCCESS)
        return false;

    SLDataLocator_AndroidSimpleBufferQueue loc_bufq = {SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE, 2};
    SLuint32 slSampleRate = SL_SAMPLINGRATE_44_1;
    if (sampleRate == 48000)
        slSampleRate = SL_SAMPLINGRATE_48;

    SLDataFormat_PCM format_pcm = {
        SL_DATAFORMAT_PCM, (SLuint32)channels, slSampleRate,
        SL_PCMSAMPLEFORMAT_FIXED_16, SL_PCMSAMPLEFORMAT_FIXED_16,
        (channels == 1) ? SL_SPEAKER_FRONT_CENTER : (SL_SPEAKER_FRONT_LEFT | SL_SPEAKER_FRONT_RIGHT),
        SL_BYTEORDER_LITTLEENDIAN};
    SLDataSource audioSrc = {&loc_bufq, &format_pcm};
    SLDataLocator_OutputMix loc_outmix = {SL_DATALOCATOR_OUTPUTMIX, outputMixObject};
    SLDataSink audioSnk = {&loc_outmix, NULL};

    // 🚀 【修复1】修改为指针数组形式，匹配 C 接口函数参数要求
    const SLInterfaceID ids[] = {SL_IID_BUFFERQUEUE};
    const SLboolean req[] = {SL_BOOLEAN_TRUE};
    result = (*engineEngine)->CreateAudioPlayer(engineEngine, &bqPlayerObject, &audioSrc, &audioSnk, 1, ids, req);
    if (result != SL_RESULT_SUCCESS)
        return false;
    result = (*bqPlayerObject)->Realize(bqPlayerObject, SL_BOOLEAN_FALSE);
    if (result != SL_RESULT_SUCCESS)
        return false;

    (*bqPlayerObject)->GetInterface(bqPlayerObject, SL_IID_PLAY, &bqPlayerPlay);
    (*bqPlayerObject)->GetInterface(bqPlayerObject, SL_IID_BUFFERQUEUE, &bqPlayerBufferQueue);

    (*bqPlayerPlay)->SetPlayState(bqPlayerPlay, SL_PLAYSTATE_PLAYING);
    return true;
}

int main(int argc, char *argv[])
{
    printf("--- Pure C++ Player (720p + OpenSL Audio + Seek) Start ---\n");

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

    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    sp<SurfaceControl> surfaceControl = client->createSurface(String8("PureCpp720pWindow"), win_width, win_height, PIXEL_FORMAT_RGBA_8888, 0);

    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF).setPosition(surfaceControl, 100, 200).setSize(surfaceControl, win_width, win_height).show(surfaceControl).apply();
    ANativeWindow *window = surfaceControl->getSurface().get();

    AMediaExtractor *extractor = AMediaExtractor_new();
    AMediaExtractor_setDataSourceFd(extractor, fd, 0, fileSize);

    AMediaCodec *videoCodec = nullptr;
    AMediaCodec *audioCodec = nullptr;
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

                int32_t sampleRate = 44100, channelCount = 2;
                AMediaFormat_getInt32(trackFormat, AMEDIAFORMAT_KEY_SAMPLE_RATE, &sampleRate);
                AMediaFormat_getInt32(trackFormat, AMEDIAFORMAT_KEY_CHANNEL_COUNT, &channelCount);
                initOpenSLES(sampleRate, channelCount);
            }
        }
        AMediaFormat_delete(trackFormat);
    }

    if (videoCodec)
        AMediaCodec_start(videoCodec);
    if (audioCodec)
        AMediaCodec_start(audioCodec);

    pthread_t inputThread;
    pthread_create(&inputThread, NULL, inputThreadFunc, NULL);

    AMediaCodecBufferInfo vInfo, aInfo;
    bool isPlaying = true;
    bool videoEOS = (videoCodec == nullptr);
    bool audioEOS = (audioCodec == nullptr);
    int64_t startTimeUs = getNowUs();

    while (isPlaying && (!videoEOS || !audioEOS))
    {

        pthread_mutex_lock(&seekMutex);
        if (seekTargetUs != -1)
        {
            int64_t realTargetUs = seekTargetUs;

            if (seekTargetUs < -1)
            {
                int64_t deltaSeconds = -(seekTargetUs + 2);
                realTargetUs = currentVideoPtsUs + (deltaSeconds * 1000000ll);
                if (realTargetUs < 0)
                    realTargetUs = 0;
            }

            // 修复 %lld 对应的类型警告，强转为 long long
            printf("[引擎] 正在执行 Seek 至 %lld ms...\n", (long long)(realTargetUs / 1000));

            // 🚀 【修复2】使用 Android 10 标准宏：AMEDIAEXTRACTOR_SEEK_PREVIOUS_SYNC
            AMediaExtractor_seekTo(extractor, realTargetUs, AMEDIAEXTRACTOR_SEEK_PREVIOUS_SYNC);

            if (videoCodec)
                AMediaCodec_flush(videoCodec);
            if (audioCodec)
                AMediaCodec_flush(audioCodec);
            if (bqPlayerBufferQueue)
                (*bqPlayerBufferQueue)->Clear(bqPlayerBufferQueue);

            baseTimeOffsetUs = realTargetUs;
            startTimeUs = getNowUs();

            videoEOS = (videoCodec == nullptr);
            audioEOS = (audioCodec == nullptr);
            seekTargetUs = -1;
        }
        pthread_mutex_unlock(&seekMutex);

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
        if (videoCodec)
        {
            ssize_t outVIdx = AMediaCodec_dequeueOutputBuffer(videoCodec, &vInfo, 1000);
            if (outVIdx >= 0)
            {
                if (vInfo.flags & AMEDIACODEC_BUFFER_FLAG_END_OF_STREAM)
                    isPlaying = false;
                currentVideoPtsUs = vInfo.presentationTimeUs;
                int64_t elapsedTimeUs = getNowUs() - startTimeUs;
                int64_t targetTimeUs = vInfo.presentationTimeUs - baseTimeOffsetUs;
                int64_t sleepTimeUs = targetTimeUs - elapsedTimeUs;
                if (sleepTimeUs > 0)
                    usleep(sleepTimeUs);
                AMediaCodec_releaseOutputBuffer(videoCodec, outVIdx, true);
            }
        }
        if (audioCodec && bqPlayerBufferQueue != NULL)
        {
            ssize_t outAIdx = AMediaCodec_dequeueOutputBuffer(audioCodec, &aInfo, 1000);
            if (outAIdx >= 0)
            {
                size_t outBufSize;
                uint8_t *pcmBuf = AMediaCodec_getOutputBuffer(audioCodec, outAIdx, &outBufSize);
                if (pcmBuf != nullptr && aInfo.size > 0)
                {
                    (*bqPlayerBufferQueue)->Enqueue(bqPlayerBufferQueue, pcmBuf + aInfo.offset, aInfo.size);
                    usleep(8000);
                }
                AMediaCodec_releaseOutputBuffer(audioCodec, outAIdx, false);
            }
        }
    }
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
    if (bqPlayerObject)
        (*bqPlayerObject)->Destroy(bqPlayerObject);
    if (outputMixObject)
        (*outputMixObject)->Destroy(outputMixObject);
    if (engineObject)
        (*engineObject)->Destroy(engineObject);
    AMediaExtractor_delete(extractor);
    close(fd);
    printf("播放圆满结束！\n");
    return 0;
}