#include <stdio.h>
#include <unistd.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/Surface.h>
#include <ui/DisplayInfo.h>
#include <android/native_window.h>
#include <media/NdkMediaCodec.h>
#include <media/NdkMediaFormat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace android;
AMediaCodec *decoder = nullptr;
int runing = 1;
// 定义屏幕宽高（也可以通过 getDisplayInfo 动态获取）
int width = 1080;
int height = 720;
int tcp_connect(char *ip, int port)
{
    int client_socket;
    struct sockaddr_in server_addr;
    int ret;
    if(ip == NULL || port < 50){
        printf("ip or port error\n");
        exit(1);
    }
    // 设置服务器地址和端口

    // 创建Socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1)
    {
        perror("Socket创建失败");
        exit(EXIT_FAILURE);
    }
    printf("客户端Socket创建成功\n");

    // 配置服务器地址信息
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // 连接到服务器
    ret = connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1)
    {
        perror("连接服务器失败");
        close(client_socket);
        exit(EXIT_FAILURE);
    }
    printf("成功连接到服务器 %s:%d\n", ip, port);
    return client_socket;
}

void *thread_func(void *arg)
{
    while (runing)
    {
        // out
        AMediaCodecBufferInfo info;
        // 获取已解码完毕的缓冲区索引
        ssize_t outputBufIndex = AMediaCodec_dequeueOutputBuffer(decoder, &info, 10000);
        if (outputBufIndex >= 0)
        {
            // 关键点：第二个参数传 true，MediaCodec 会自动把图像渲染到绑定的 ANativeWindow 上
            AMediaCodec_releaseOutputBuffer(decoder, outputBufIndex, true);
        }
        /*else if (outputBufIndex == AMEDIACODEC_INFO_OUTPUT_FORMAT_CHANGED)
        {
            // 视频格式改变（如旋转或分辨率改变）
            AMediaFormat *format = AMediaCodec_getOutputFormat(decoder);
            // 可在此处获取更新后的宽高
            AMediaFormat_delete(format);
        }*/
    }
    return nullptr;
}
size_t read_data_all(int client_socket, char *buffer, int size)
{
    size_t total_read = size;
    while (total_read > 0)
    {
        ssize_t bytes_read = read(client_socket, buffer, total_read);
        if (bytes_read < 1)
        {
            perror("读取数据失败");
            return -1;
        }
        total_read -= bytes_read;
        buffer += bytes_read;
    }
    total_read = size;
    return total_read;
}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }
    int client_socket = tcp_connect(argv[1], atoi(argv[2]));
    // 这里的宽度、高度和 CSD (SPS/PPS) 需要根据你的 H.264 视频流实际情况填写
    int videoWidth = 1920;  // 替换为你的视频流宽度
    int videoHeight = 1080; // 替换为你的视频流高度
    if (read_data_all(client_socket, (char *)&videoWidth, sizeof(int)) != sizeof(int))
    {
        printf("读取视频宽度失败\n");
        close(client_socket);
        return 1;
    }
    if (read_data_all(client_socket, (char *)&videoHeight, sizeof(int)) != sizeof(int))
    {
        printf("读取视频高度失败\n");
        close(client_socket);
        return 1;
    }
    printf("视频宽度: %d, 视频高度: %d\n", videoWidth, videoHeight);
    printf("--- Native Surface Color Switch Demo Start ---\n");
    // 1. 初始化 SurfaceComposerClient
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    status_t err = client->initCheck();
    if (err != NO_ERROR)
    {
        fprintf(stderr, "错误: 无法初始化 SurfaceComposerClient, 状态码: %d\n", err);
        close(client_socket);
        return 1;
    }

    // 2. 创建 SurfaceControl
    // 注意：高版本 Android 建议在最后的参数中指定需要的 flags
    sp<SurfaceControl> surfaceControl = client->createSurface(
        String8("CameraNativePreview"),
        width /* / 2 */,
        height /* / 2*/,
        PIXEL_FORMAT_RGBA_8888,
        0);

    if (surfaceControl == nullptr)
    {
        fprintf(stderr, "错误: 创建 surfaceControl 失败\n");
        close(client_socket);
        return 1;
    }

    // 3. 设置图层属性并使其可见
    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF) // 绝对顶层
        .setPosition(surfaceControl, 0, 0 /*1440 - height / 2*/)
        .setAlpha(surfaceControl, 1.0f) // 设置为不透明，方便观察纯色切换
        .show(surfaceControl)
        .apply();

    // 4. 获取本地 Surface 与 ANativeWindow 指针
    sp<Surface> previewSurface = surfaceControl->getSurface();
    if (previewSurface == nullptr)
    {
        fprintf(stderr, "错误: 获取 previewSurface 失败\n");
        close(client_socket);
        return 1;
    }

    ANativeWindow *window = previewSurface.get();
    if (window == nullptr)
    {
        fprintf(stderr, "错误: 转换 ANativeWindow 失败\n");
        close(client_socket);
        return 1;
    }

    // 2. 创建 H.264 (AVC) 解码器
    // "video/avc" 是 H.264 的标准 MIME 类型
    decoder = AMediaCodec_createDecoderByType("video/avc");
    if (decoder == nullptr)
    {
        printf("错误处理：手机不支持 H.264 硬解（极少见）");
        close(client_socket);
        return 1;
    }

    // 3. 配置视频格式 (MediaFormat)

    AMediaFormat *format = AMediaFormat_new();
    AMediaFormat_setString(format, AMEDIAFORMAT_KEY_MIME, "video/avc");
    // 修改后：
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_WIDTH, videoWidth);
    AMediaFormat_setInt32(format, AMEDIAFORMAT_KEY_HEIGHT, videoHeight);
    // 注意：如果你的 H.264 是 H.264 裸流（Annex-B 格式），通常需要在 format 中
    // 通过 AMediaFormat_setBuffer 设置 csd-0 (SPS) 和 csd-1 (PPS) 才能正常解码。

    // 4. 将 ANativeWindow 绑定到解码器，实现直接渲染
    // 第三个参数传入 window，第四个参数为加密控制（一般填 0）
    media_status_t status = AMediaCodec_configure(decoder, format, window, nullptr, 0);

    if (status != AMEDIA_OK)
    {
        // 错误处理：配置失败
        AMediaFormat_delete(format);
        AMediaCodec_delete(decoder);
        close(client_socket);
        return 2;
    }

    // 5. 释放不再需要的 format 结构体
    AMediaFormat_delete(format);
    // 6. 启动解码器
    AMediaCodec_start(decoder);

    // ====== 至此，解码器已成功绑定 window 并准备就绪 ======
    // 创建线程
    pthread_t thread;
    pthread_create(&thread, NULL, thread_func, NULL);
    int size = 0;
    size_t dataSize = 0;
    while (runing)
    {
        // input
        //  获取可用的输入缓冲区索引（超时时间设为 10000 微秒）
        ssize_t inputBufIndex = AMediaCodec_dequeueInputBuffer(decoder, 10000);
        if (inputBufIndex >= 0)
        {
            size_t outBufSize;
            // 获取实际的缓冲区指针
            uint8_t *inputBuf = AMediaCodec_getInputBuffer(decoder, inputBufIndex, &outBufSize);
            if (inputBuf != nullptr)
            {
                if (read_data_all(client_socket, (char *)&size, sizeof(size)) != sizeof(int))
                    break;
                if (read_data_all(client_socket, (char *)inputBuf, size) != size)
                    break;
            }
            dataSize = size;
            // TODO: 将你的 H.264 帧数据复制到 inputBuf 中，并记录实际大小 dataSize
            // memcpy(inputBuf, yourH264Data, dataSize);
            uint64_t presentationTimeUs = 0; // getPresentTimeUs(); // 获取当前时间戳
            // 将缓冲区送回解码器
            AMediaCodec_queueInputBuffer(decoder, inputBufIndex, 0, dataSize, presentationTimeUs, 0);
        }
    }
    runing=0;
    pthread_join(thread, NULL);
    // 7. 释放资源
    AMediaCodec_stop(decoder);
    AMediaCodec_delete(decoder);
    close(client_socket);
    return 0;
}
