#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <android/log.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#define TAG "scrcpy_c_networking"

#include <android/native_window.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/ISurfaceComposer.h>
#include <gui/Surface.h> // 必须引入此头文件以支持 Surface 转换
#include <ui/Rect.h>
#include <ui/DisplayInfo.h>
#include <binder/ProcessState.h>

// 功能未实现
#include <aaudio/AAudio.h>
#include <stdio.h>
int runing = 1;
// Android 9 底层系统定义的 REMOTE_SUBMIX 音频源
#define ANDROID_AUDIO_SOURCE_REMOTE_SUBMIX 8
int aserver_fd = -1;
fd_set awd_set, ard_set;
int amaxfd = 0;
int aclient_count = 0;
int aclient_max = 10;
int *aclient_arr = 0;
void settcp(int client_fd)
{
    // 1. 设置发送超时 (例如 1 秒)
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(client_fd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout)); // 设置接收超时 (例如 1 秒)
}
int client_connect(int server_fd)
{
    struct sockaddr_in6 client_addr;
    int addrlen = sizeof(struct sockaddr_in6);
    int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
    if (client_fd < 0)
    {
        printf("客户端连接失败\n");
        return -1;
    }
    int is_v6_loopback = (IN6_IS_ADDR_LOOPBACK(&client_addr.sin6_addr));

    // 情况 B：IPv4 映射到 IPv6 的本地回环地址，即 "::ffff:127.0.0.1"
    int is_v4_mapped_loopback = (IN6_IS_ADDR_V4MAPPED(&client_addr.sin6_addr) &&
                                 client_addr.sin6_addr.s6_addr[12] == 127 &&
                                 client_addr.sin6_addr.s6_addr[13] == 0 &&
                                 client_addr.sin6_addr.s6_addr[14] == 0 &&
                                 client_addr.sin6_addr.s6_addr[15] == 1);

    if (is_v6_loopback || is_v4_mapped_loopback)
    {
        printf("⚠️ 拦截到本地回环地址连接（IPv4/IPv6），已自动断开。\n");
        close(client_fd);
        return -1;
    }
    settcp(client_fd);
    return client_fd;
}
int sendd(int client_fd, char *buf, int ssize)
{
    //  printf("sendd %d\n", ssize);
    int ret = 0;
    int size = 0;
    ret = ssize - size;
    while (ret > 0)
    {
        ret = write(client_fd, buf, ssize - size);
        if (ret < 1)
        {
            return -1;
        }
        buf += ret;
        size += ret;
        ret = ssize - size;
    }
    return size;
}
#include <media/AudioRecord.h>
#include <utils/String16.h>
#include <stdio.h>

using namespace android;
android::sp<android::AudioRecord> g_record = nullptr;
// 音频数据处理回调
void audio_callback(int event, void *user, void *info)
{
    // printf("audio_callback event=%d\n", event);
    if (event == AudioRecord::EVENT_MORE_DATA)
    {
        AudioRecord::Buffer *b = static_cast<AudioRecord::Buffer *>(info);
        if (b == nullptr || b->size == 0)
            return;
        if (aserver_fd > 0 && runing)
        {
            FD_ZERO(&awd_set);
            FD_ZERO(&ard_set);
            FD_SET(aserver_fd, &ard_set);
            amaxfd = aserver_fd;
            for (int i = 0; i < aclient_count; ++i)
            {
                FD_SET(aclient_arr[i], &awd_set);
                if (aclient_arr[i] > amaxfd)
                {
                    amaxfd = aclient_arr[i];
                }
            }
            struct timeval tv = {0, 0};
            int ret = select(amaxfd + 1, &ard_set, &awd_set, 0, &tv);
            if (ret < 0)
            {
                perror("错误 select()");
                return; // 继续回调
            }
            if (FD_ISSET(aserver_fd, &ard_set))
            {
                // printf("有新客户端连接\n");
                aclient_arr[aclient_count] = client_connect(aserver_fd);
                if (aclient_arr[aclient_count] > 0)
                {
                    aclient_count++;
                    if (aclient_count == aclient_max)
                    {
                        aclient_max *= 2;
                        aclient_arr = (int *)realloc(aclient_arr, sizeof(int) * aclient_max);
                        if (!aclient_arr)
                        {
                            runing = 0;
                            perror("错误 realloc()");
                        }
                    }
                    printf("声音客户端连接成功 fd=%d count=%d\n", aclient_arr[aclient_count-1], aclient_count);
                }
            }
            for (int i = 0; i < aclient_count; i++)
            {

                if (FD_ISSET(aclient_arr[i], &awd_set))
                {
                    int dataSizeInBytes = b->size;
                    int ret = sendd(aclient_arr[i], (char *)&dataSizeInBytes, sizeof(int));
                    if (ret == sizeof(int))
                    {
                        ret = sendd(aclient_arr[i], (char *)b->raw, dataSizeInBytes);
                        if (ret == dataSizeInBytes)
                            continue;
                    }
                    
                     fprintf(stderr, "TCP %d 声音客户端似乎断开了连接，发送失败还有%d。\n", aclient_arr[i], aclient_count-1 );
                    close(aclient_arr[i]);
                    memcpy(aclient_arr + i, aclient_arr + i + 1, sizeof(int) * (aclient_count - i - 1));
                    aclient_count--;
                    i--;
                }
            }
        }
        // =======================================================
        // b->raw 包含了截获到的全局系统 PCM 声音
        // b->size 是当前数据的字节大小
        // 【在这里处理你的音频数据】：例如发送到 TCP 网络 (port: 8000)
        // send(tcp_audio_socket, b->raw, b->size, 0);
        // =======================================================
    }
}

bool inject_submix_audio_route()
{
    Vector<AudioMix> mixes;
    AudioMix mix;

    // 1. 配置混音路由规则
    mix.mCriteria.clear();
    AudioMixMatchCriterion criterion;
    criterion.mValue.mUsage = AUDIO_USAGE_MEDIA;  // 匹配所有媒体声音
    criterion.mRule = RULE_MATCH_ATTRIBUTE_USAGE; // 规则：按 Usage 匹配
    mix.mCriteria.add(criterion);

    mix.mMixType = MIX_TYPE_PLAYERS;                  // 劫持播放端
    mix.mRouteFlags = MIX_ROUTE_FLAG_LOOP_BACK;       // 设置为回放环回模式 (Loopback)
    mix.mDeviceType = AUDIO_DEVICE_OUT_REMOTE_SUBMIX; // 强制目标输出指向 submix
    mix.mDeviceAddress = String8("0");
    mix.mFormat.sample_rate = 44100;
    mix.mFormat.channel_mask = AUDIO_CHANNEL_OUT_STEREO;
    mix.mFormat.format = AUDIO_FORMAT_PCM_16_BIT;

    mixes.add(mix);

    // 2. 强行注入系统底层（此接口需要后台拥有系统特权或 Root 进程才能执行成功）
    status_t status = AudioSystem::registerPolicyMixes(mixes, true);
    if (status != NO_ERROR)
    {
        printf("【警告】向系统注入 Submix 路由失败，错误码: %d。如果没有这条路由，回调将无法触发声音！\n", status);
        return false;
    }

    printf("【成功】已成功向系统强制注入 Submix 路由桥梁。\n");
    return true;
}
extern "C" int native_start_system_audio_capture_v2(int bit)
{
    if (!inject_submix_audio_route())
    {
        return -1;
    }
    audio_source_t inputSource = AUDIO_SOURCE_REMOTE_SUBMIX; // 8
    uint32_t sampleRate = 48100;
    if(bit>0)sampleRate=bit;
        
    audio_format_t format = AUDIO_FORMAT_PCM_16_BIT;
    audio_channel_mask_t channelMask = AUDIO_CHANNEL_IN_STEREO;

    // 1. 尝试伪造系统关键进程环境
    String16 opPackageName("com.android.shell");

    // 在 Android 10 源码下，AudioRecord 支持传入指定的 UID 和 PID
    // 1013 是 AID_MEDIA (系统媒体服务权限)，2000 是 AID_SHELL
    uid_t fake_uid = 1013;
    pid_t fake_pid = getpid();

    // 2. 使用 Android 10 完整的底层构造函数
    g_record = new AudioRecord(
        inputSource,
        sampleRate,
        format,
        channelMask,
        opPackageName,
        0,              // frameCount
        audio_callback, // 回调
        nullptr,        // user data
        0,              // notificationFrames
        AUDIO_SESSION_ALLOCATE,
        AudioRecord::TRANSFER_CALLBACK,
        AUDIO_INPUT_FLAG_NONE,
        fake_uid, // 强行注入合法系统的 UID 绕过 Policy 拦截
        fake_pid);

    if (g_record == nullptr || g_record->initCheck() != NO_ERROR)
    {
        printf("初始化底层 AudioRecord 失败！\n");
        return -1;
    }

    status_t status = g_record->start();
    if (status != NO_ERROR)
    {
        printf("启动底层 AudioRecord 失败，错误码: %d\n", status);
        return -1;
    }
    // 在 record->start() 之后打印这行，看看系统到底给你分配了几个声道
    printf("系统实际录音通道数: %d, 帧大小: %zu 字节 %d hz\n", g_record->channelCount(), g_record->frameSize(),g_record->getSampleRate());

    printf("成功通过底层 AudioRecord 激活系统声音通路，等待声音输入...\n");
    aclient_arr = (int *)malloc(sizeof(int) * aclient_max);
    if (!aclient_arr)
    {
        perror("错误 malloc()");
        return -1;
    }
    return 0;
}

static android::sp<android::IBinder> g_dpy = nullptr;

extern "C" int native_bind_display_to_surface(ANativeWindow *window, int width, int height)
{
    using namespace android;

    if (window == nullptr)
    {
        printf("window == nullptr\n");
        return -1;
    }

    // 1. Android 9 创建虚拟显示器
    sp<IBinder> dpy = SurfaceComposerClient::createDisplay(String8("my_display"), false);
    if (dpy == nullptr)
        return -1;

    // 2. 修复：使用 static_cast 替代 reinterpret_cast 进行安全的向下转型
    sp<Surface> surface = static_cast<Surface *>(window);
    if (surface == nullptr)
        return -1;

    sp<IGraphicBufferProducer> producer = surface->getIGraphicBufferProducer();
    if (producer == nullptr)
        return -1;

    // 3. Android 9 使用 Transaction 替代全局静态事务
    SurfaceComposerClient::Transaction t;

    t.setDisplaySurface(dpy, producer);

    Rect layerStackRect(0, 0, width, height);
    Rect displayRect(0, 0, width, height);

    t.setDisplayProjection(dpy, 0, layerStackRect, displayRect);
    t.setDisplayLayerStack(dpy, 0);
    // 4. 提交事务
    t.apply();

    // 保存 dpy 供 unbind 使用
    g_dpy = dpy;
    return 0;
}

extern "C" void native_unbind_display(void)
{
    using namespace android;

    if (g_dpy != nullptr)
    {
        SurfaceComposerClient::Transaction t;
        t.setDisplaySurface(g_dpy, nullptr);
        t.apply();

        SurfaceComposerClient::destroyDisplay(g_dpy);
        g_dpy = nullptr;
        printf("取消绑定\n");
    }
}

void usage(int i, char *p)
{
    printf("Usage: %s -ap <port> -vp <port> -ab <bitrate> -vb <bitrate> -s <widthxheight>\n", p);
    exit(i);
}
static int parse_resolution(const char *s, int *w, int *h)
{
    return sscanf(s, "%dx%d", w, h) == 2;
}
int main(int argc, char **argv)
{
    // 忽略 SIGPIPE 信号，防止客户端断开时程序闪退
    signal(SIGPIPE, SIG_IGN);
    char buffer[255];
    int client_max = 10;
    int client_count = 0;
    int bitrate = 8000000; // 8M
    int abitrate = 48000; //48k
    int port = 9999;
    int aport = 9998;
    int *Width = (int *)buffer;
    *Width = 1920;
    int *Height = (int *)(buffer + 4);
    *Height = 1080;
    int ap = 0, vp = 0, ab = 0, vb = 0, xwidth = 0, xheight = 0, ret;
    for (int i = 1; i < argc; i++)
    {
        const char *arg = argv[i];
        if (!strcmp(arg, "-ap") || !strcmp(arg, "-vp"))
        {
            if (i + 1 >= argc)
            { /* 缺参数 */
                usage(1, argv[0]);
            }
            ret = atoi(argv[++i]);
            if (!strcmp(arg, "-ap"))
                ap = ret;
            else
                vp = ret;
            continue;
        }
        if (!strcmp(arg, "-ab") || !strcmp(arg, "-vb"))
        {
            if (i + 1 >= argc)
                usage(2, argv[0]);
            ret = atoi(argv[++i]);
            if (!strcmp(arg, "-ab"))
                ab = ret;
            else
                vb = ret;
            continue;
        }
        if (!strcmp(arg, "-s"))
        {
            if (i + 1 >= argc)
                usage(3, argv[0]);
            if (!parse_resolution(argv[++i], &xwidth, &xheight))
                usage(4, argv[0]);
            continue;
        }
        if (!strcmp(arg, "-h") || !strcmp(arg, "--help"))
        {
            usage(5, argv[0]);
            continue;
        }
        fprintf(stderr, "未知参数: %s\n", arg);
        usage(6, argv[0]);
    }

    if (ap > 0)
    {
        aport = ap;
    }
    if (vp > 0)
    {
        port = vp;
    }
    if (vb > 0)
    {
        bitrate = vb;
    }
      if (ab > 0)
    {
        abitrate = ab;
    }
    if (xwidth > 0 && xheight > 0)
    {
        *Width = xwidth;
        *Height = xheight;
    }
    printf(" ==============%dX%d  port: %d bitrate: %d============ \n", *Width, *Height, port, bitrate);
    int *sps_size = (int *)(buffer + 8);
    char *sps_buf = buffer + 12;
    int *client_arr = (int *)malloc(sizeof(int) * client_max);
    ANativeWindow *window = nullptr;
    struct sockaddr_in6 server_addr; //, client_addr;
    int addrlen = sizeof(struct sockaddr_in6);
    // printf("开始监听端口 %d\n", port);
    int server_fd = socket(AF_INET6, SOCK_STREAM, 0); // 创建套接字
    if (server_fd < 0)
    {
        perror("socket");
        return -1;
    }
    memset(&server_addr, 0, addrlen);
    server_addr.sin6_family = AF_INET6;
    server_addr.sin6_addr = in6addr_any; // 绑定到所有可用的网络接口
    server_addr.sin6_port = htons(port); // 绑定到指定的端口
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); // 设置 SO_REUSEADDR 选项
    // ⚠️ 关键修改 3：关闭 IPV6_V6ONLY 选项（允许该 IPv6 Socket 接收 IPv4 连接）
    int v6only = 0;
    if (setsockopt(server_fd, IPPROTO_IPV6, IPV6_V6ONLY, &v6only, sizeof(v6only)) < 0)
    {
        perror("关闭 IPV6_V6ONLY 失败");
        close(server_fd);
        return 1;
    }
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind");
        close(server_fd);
        return -1;
    }
    if (listen(server_fd, 1) < 0)
    {
        perror("listen");
        close(server_fd);
        return -1;
    }
    aserver_fd = socket(AF_INET6, SOCK_STREAM, 0); // 创建套接字
    if (aserver_fd < 0)
    {
        perror("a: socket");
        return -1;
    }
    server_addr.sin6_port = htons(aport); // 绑定到指定的端口
    opt = 1;
    setsockopt(aserver_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)); // 设置 SO_REUSEADDR 选项
    // ⚠️ 关键修改 3：关闭 IPV6_V6ONLY 选项（允许该 IPv6 Socket 接收 IPv4 连接）
    v6only = 0;
    if (setsockopt(aserver_fd, IPPROTO_IPV6, IPV6_V6ONLY, &v6only, sizeof(v6only)) < 0)
    {
        perror("关闭 IPV6_V6ONLY 失败");
        close(aserver_fd);
        close(server_fd);
        return 1;
    }
    if (bind(aserver_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("bind");
        close(aserver_fd);
        close(server_fd);
        return -1;
    }
    if (listen(aserver_fd, 1) < 0)
    {
        perror("listen");
        close(aserver_fd);
        close(server_fd);
        return -1;
    }

    ret = native_start_system_audio_capture_v2(abitrate); // native_start_system_audio_capture();
    if (ret == -1)
    {
        printf("native_start_system_audio_capture failed\n");
        close(server_fd);
        close(aserver_fd);
        return -1;
    }

    AMediaCodec *codec = AMediaCodec_createEncoderByType("video/avc");
    if (!codec)
    {
        printf("AMediaCodec_createEncoderByType failed\n");
        close(server_fd);
        close(aserver_fd);
        return -1;
    }

    AMediaFormat *format = AMediaFormat_new();
    AMediaFormat_setString(format, AMEDIAFORMAT_KEY_MIME, "video/avc");
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_WIDTH, *Width);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_HEIGHT, *Height);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_BIT_RATE, bitrate);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_FRAME_RATE, 60); // 60fps
    // max-fps
    //  AMediaFormat_setFloat(format, "max-fps-to-encoder", 60.0f);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_I_FRAME_INTERVAL, 1);      // 关键：I 帧间隔为 1 秒
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_COLOR_FORMAT, 2130708361); // COLOR_FormatSurface
    AMediaFormat_setInt32(format, "profile", 8);                              // H.264 Baseline Profile
    AMediaFormat_setInt32(format, "level", 65536);                            // H.264 Level 3.1
    AMediaFormat_setInt32(format, "vendor.qti-ext-dec-picture-order.enable", 1);
    AMediaFormat_setInt32(format, "low-latency", 1);
    media_status_t status = AMediaCodec_configure(codec, format, nullptr, nullptr, AMEDIACODEC_CONFIGURE_FLAG_ENCODE);
    if (status != AMEDIA_OK)
    {
        AMediaCodec_delete(codec);
        fprintf(stderr, "AMediaCodec_configure 失败\n");
        close(server_fd);
        close(aserver_fd);
        return 0;
    }
    AMediaFormat_delete(format);

    // 3. 【核心修复】：直接让 AMediaCodec 在 C 层创建 Input Surface (ANativeWindow)
    // 这样创建出来的 Window 内部天生携带着完美的、由多媒体框架初始化的 BufferQueue
    status = AMediaCodec_createInputSurface(codec, &window);
    if (status != AMEDIA_OK || !window)
    {
        fprintf(stderr, "AMediaCodec_createInputSurface 失败\n");
        AMediaCodec_delete(codec);
        close(server_fd);
        close(aserver_fd);
        return -1;
    }

    // 4. 启动编码器
    status = AMediaCodec_start(codec);
    if (status != AMEDIA_OK)
    {
        ANativeWindow_release(window);
        AMediaCodec_delete(codec);
        fprintf(stderr, "AMediaCodec_start 失败\n");
        close(server_fd);
        close(aserver_fd);
        return -1;
    }
    int client_fd = 0;
    int no_client_fd = 0;
    fd_set wd_set, rd_set;
    int maxfd = 0;
    ssize_t buf_idx = 0;
    uint8_t *buf = 0;
    uint8_t *nalu_data = 0;
    size_t outx = 0;
    int out_size; // 4bit
    *sps_size = 0;
    AMediaCodecBufferInfo info;
    while (runing)
    {
        if (client_count == 0)
        {

            if (g_dpy != nullptr)
                native_unbind_display();
            client_fd = client_connect(server_fd);
            if (client_fd < 0)
            {
                continue;
            }
            out_size = 8; // 8bit
            ret = sendd(client_fd, buffer, out_size);
            if (ret != out_size)
            {
                fprintf(stderr, "TCP %d 客户端发送失败。\n", client_fd);
                close(client_fd);
                continue;
            }
            if (g_dpy == nullptr)
            {
                printf("绑定显示\n");
                ret = native_bind_display_to_surface(window, *Width, *Height);
                if (ret < 0)
                {
                    fprintf(stderr, "native_bind_display_to_surface 失败\n");
                    close(client_fd);
                    continue;
                }
            }
            client_arr[client_count++] = client_fd;
            printf("客户端连接成功 fd=%d count=%d\n", client_fd, client_count);
            no_client_fd = client_fd;
            client_fd = 0;
        }
        buf_idx = AMediaCodec_dequeueOutputBuffer(codec, &info, 20000);
        if (buf_idx >= 0)
        {
            buf = AMediaCodec_getOutputBuffer(codec, buf_idx, &outx);
            if (buf && info.size > 0)
            {
                FD_ZERO(&wd_set);
                FD_ZERO(&rd_set);
                FD_SET(server_fd, &rd_set);
                maxfd = server_fd;
                for (int i = 0; i < client_count; ++i)
                {
                    FD_SET(client_arr[i], &wd_set);
                    if (client_arr[i] > maxfd)
                    {
                        maxfd = client_arr[i];
                    }
                }
                ret = select(maxfd + 1, &rd_set, &wd_set, 0, 0);
                if (ret < 0)
                {
                    perror("错误 select()");
                    break;
                }
                nalu_data = buf + info.offset;
                //  out_size = info.size;
                if ((nalu_data[4] & 0x1f) == 5)
                {
                    if (no_client_fd)
                    {
                        client_fd = no_client_fd;
                        no_client_fd = 0;
                    }
                    // printf("是I帧 %#x\n",nalu_data[4]);
                    if (FD_ISSET(server_fd, &rd_set))
                    {
                        // printf("有新客户端连接\n");
                        client_fd = client_connect(server_fd);
                        if (client_fd < 0)
                        {
                            continue;
                        }

                        out_size = 8;
                        ret = sendd(client_fd, buffer, out_size);
                        if (ret != out_size)
                        {
                            fprintf(stderr, "TCP %d 客户端发送失败。\n", client_fd);
                            close(client_fd);
                            continue;
                        }
                        client_arr[client_count++] = client_fd;
                        if (client_count == client_max)
                        {
                            client_max *= 2;
                            client_arr = (int *)realloc(client_arr, sizeof(int) * client_max);
                            if (!client_arr)
                                break;
                        }
                        printf("客户端连接成功 fd=%d count=%d\n", client_fd, client_count);
                    }
                }
                for (int i = 0; i < client_count; i++)
                {

                    if (FD_ISSET(client_arr[i], &wd_set))
                    {
                        if (no_client_fd == client_arr[i])
                            continue;
                        out_size = info.size;
                        if (client_fd == client_arr[i])
                        {
                            out_size += *sps_size;
                        }
                        ret = sendd(client_arr[i], (char *)&out_size, sizeof(int));
                        if (ret != sizeof(int))
                        {
                            fprintf(stderr, "TCP %d 客户端似乎断开了连接，发送失败还有%d。\n", client_arr[i], client_count - 1);
                            close(client_arr[i]);
                            memcpy(client_arr + i, client_arr + i + 1, sizeof(int) * (client_count - i - 1));
                            client_count--;
                            i--;
                            continue;
                        }
                        if (client_fd == client_arr[i])
                        {
                            printf("发送SPS PPS\n");
                            ret = sendd(client_arr[i], sps_buf, *sps_size);
                            if (ret != *sps_size)
                            {
                                fprintf(stderr, "TCP %d 客户端似乎断开了连接，发送失败还有%d。\n", client_arr[i], client_count - 1);
                                close(client_arr[i]);
                                memcpy(client_arr + i, client_arr + i + 1, sizeof(int) * (client_count - i - 1));
                                client_count--;
                                i--;
                                continue;
                            }
                            client_fd = 0;
                        }
                        ret = sendd(client_arr[i], (char *)nalu_data, info.size);
                        if (ret != info.size)
                        {
                            fprintf(stderr, "TCP %d 客户端似乎断开了连接，发送失败还有%d。\n", client_arr[i], client_count - 1);
                            close(client_arr[i]);
                            memcpy(client_arr + i, client_arr + i + 1, sizeof(int) * (client_count - i - 1));
                            client_count--;
                            i--;
                            continue;
                        }
                    }
                }
            }
            AMediaCodec_releaseOutputBuffer(codec, buf_idx, false);
        }
        if (buf_idx == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED)
        {
            out_size = 0;
            AMediaFormat *format = AMediaCodec_getOutputFormat(codec);
            // printf("C++ 捕获编码格式改变: %s\n", AMediaFormat_toString(format));
            //  【核心修复】：提取 H.264 的首要配置帧（SPS 和 PPS）

            buf = (uint8_t *)sps_buf;
            char *p = 0;
            // 从 format 中提取 csd-0 (SPS) 和 csd-1 (PPS)
            if (AMediaFormat_getBuffer(format, "csd-0", (void **)&p, &outx) && p)
            {
                memcpy((void *)buf, (void *)p, outx);
                buf += outx;
                *sps_size = 0;
                *sps_size += outx;
                printf("成功保存  SPS 配置帧，大小: %zu", outx);
            }

            if (AMediaFormat_getBuffer(format, "csd-1", (void **)&p, &outx) && p)
            {
                memcpy(buf, p, outx);
                *sps_size += outx;
                printf("  成功保存 PPS 配置帧，大小: %zu  总大小%d\n", outx, *sps_size);
            }
            AMediaFormat_delete(format);
        }
    }
    for (int i = 0; i < client_count; i++)
    {
        close(client_arr[i]);
    }
    if (codec)
    {
        AMediaCodec_stop(codec);
        AMediaCodec_delete(codec);
    }
    if (window)
        ANativeWindow_release(window);
    close(server_fd);
    close(aserver_fd);
}
