#include <stdio.h>
#include <unistd.h>
#include <android/gui/DropInputMode.h>
// 在引入 gui 头文件之前，显式结束任何可能存在的 ui 污染，确保在全局作用域展开
#include <gui/SurfaceComposerClient.h>
#include <gui/Surface.h>


#include <ui/DisplayInfo.h>
#include <android/native_window.h>

using namespace android;
using namespace android;

// 定义屏幕宽高（也可以通过 getDisplayInfo 动态获取）
int width = 1440;
int height = 2280;

int main() {
    printf("--- Native Surface Color Switch Demo Start ---\n");

    // 1. 初始化 SurfaceComposerClient
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    status_t err = client->initCheck();
    if (err != NO_ERROR) {
        fprintf(stderr, "错误: 无法初始化 SurfaceComposerClient, 状态码: %d\n", err);
        return 1;
    }

    // 2. 创建 SurfaceControl
    // 注意：高版本 Android 建议在最后的参数中指定需要的 flags 
    sp<SurfaceControl> surfaceControl = client->createSurface(
        String8("CameraNativePreview"), 
        width /* / 2 */, 
        height /* / 2*/, 
        PIXEL_FORMAT_RGBA_8888, 
        0
    );

    if (surfaceControl == nullptr) {
        fprintf(stderr, "错误: 创建 surfaceControl 失败\n");
        return 1;
    }

    // 3. 设置图层属性并使其可见
    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF) // 绝对顶层
     .setPosition(surfaceControl, 0,0 /*1440 - height / 2*/)
     .setAlpha(surfaceControl, 1.0f)        // 设置为不透明，方便观察纯色切换
     .show(surfaceControl)
     .apply();

    // 4. 获取本地 Surface 与 ANativeWindow 指针
    sp<Surface> previewSurface = surfaceControl->getSurface();
    if (previewSurface == nullptr) {
        fprintf(stderr, "错误: 获取 previewSurface 失败\n");
        return 1;
    }

    ANativeWindow* window = previewSurface.get();
    if (window == nullptr) {
        fprintf(stderr, "错误: 转换 ANativeWindow 失败\n");
        return 1;
    }

    // 5. 进入红绿交替循环（即使 Java 停止了，这里依然会强制刷新）
    printf("开始红绿交替刷新，按 Ctrl+C 可退出 adb 运行...\n");
    bool isRed = true;
    ANativeWindow_Buffer buffer;

    while (true) {
        // 锁定 Window 的 Buffer（这一步会向 SurfaceFlinger 申请一个新的 Buffer）
        if (ANativeWindow_lock(window, &buffer, nullptr) == 0) {
            
            // 获取图层的实际物理数据行宽（注意：stride 往往 >= width）
            uint32_t* line = (uint32_t*)buffer.bits;
            
            // 根据状态决定当前填充 红色 还是 绿色
            // RGBA 格式对应的 16 进制：0xFF0000FF(红) / 0xFF00FF00(绿) (取决于大端小端，通常底层为 ABGR)
            uint32_t color = isRed ? 0xFF0000FF : 0xFF00FF00; 

            // 逐像素填充每一行
            for (int y = 0; y < buffer.height; y++) {
                for (int x = 0; x < buffer.width; x++) {
                    line[x] = color;
                }
                line += buffer.stride; // 移动到下一行
            }

            // 解锁并提交 Buffer，此时 SurfaceFlinger 会立刻刷新屏幕
            ANativeWindow_unlockAndPost(window);

            // 状态取反，等待下一次切换
            isRed = !isRed;
        } else {
            fprintf(stderr, "警告: 锁定 ANativeWindow 失败\n");
        }

        // 每隔 1 秒切换一次颜色
        sleep(1);
    }

    return 0;
}

