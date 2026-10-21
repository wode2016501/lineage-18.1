#include <stdio.h>
#include <unistd.h>
#include <gui/Surface.h>
#include <gui/SurfaceComposerClient.h>
// 1. 修复第一个错误：必须显式引入这个头文件，才能获取 ISurfaceComposer::eDisplayIdMain 的定义
#include <gui/ISurfaceComposer.h> 
#include <ui/DisplayInfo.h>
#include <ui/GraphicBuffer.h>
// 2. 修复 ANativeWindow 函数调用的标准 NativeWindow NDK 头文件
#include <android/native_window.h> 

using namespace android;

int main() {
    printf("Starting Native Surface Composer Client... [Android 9 Fixed]\n");

    // 1. 初始化与 SurfaceFlinger 的底层 Binder 通信
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    status_t err = client->initCheck();
    if (err != NO_ERROR) {
        printf("Error: SurfaceComposerClient init failed: %d\n", err);
        return -1;
    }

    // 2. 获取主显示屏（Display）的 Token
    sp<IBinder> dtoken = SurfaceComposerClient::getBuiltInDisplay(ISurfaceComposer::eDisplayIdMain);
    if (dtoken == nullptr) {
        printf("Error: Could not get BuiltInDisplay token.\n");
        return -1;
    }

    // 3. 获取屏幕的真实物理分辨率
    DisplayInfo dinfo;
    err = SurfaceComposerClient::getDisplayInfo(dtoken, &dinfo);
    if (err != NO_ERROR) {
        printf("Error: getDisplayInfo failed.\n");
        return -1;
    }
    printf("Screen Resolution: %dx%d, Orientation: %d\n", dinfo.w, dinfo.h, dinfo.orientation);

    // 4. 在屏幕最上层创建一个原生 Surface 窗口
    sp<SurfaceControl> surfaceControl = client->createSurface(
        String8("NativePreviewSurface"),
        dinfo.w / 2,  // 宽度设置为屏幕的一半
        dinfo.h / 2,  // 高度设置为屏幕的一半
        PIXEL_FORMAT_RGBA_8888,
        0
    );

    if (surfaceControl == nullptr || !surfaceControl->isValid()) {
        printf("Error: createSurface failed.\n");
        return -1;
    }

    // 5. 设置这个原生窗口的显示层级（Z-Order），让它强行悬浮在最上层
    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF) // 设置为最大层级
     .setPosition(surfaceControl, dinfo.w / 4, dinfo.h / 4) // 置于屏幕中央
     .show(surfaceControl)
     .apply();

    // 6. 获取 Surface 强引用指针
    sp<Surface> surface = surfaceControl->getSurface();

    printf("Surface created successfully! Drawing standard color pixels for 5 seconds...\n");

    // 7. 测试循环：修改为使用表面强引用的 Surface::ANativeWindow_Buffer 锁控制机制
    ANativeWindow_Buffer buffer;
    for (int i = 0; i < 100; i++) {
        // 修复第二、三个错误：在底层，C++层直接使用 surface 的 lock 接口控制图像总线流
        if (surface->lock(&buffer, nullptr) == NO_ERROR) {
            uint32_t* pixels = (uint32_t*)buffer.bits;
            
            // 顺着步长（stride）强行把屏幕涂红/绿交替
            uint32_t color = (i % 2 == 0) ? 0xFF0000FF : 0xFF00FF00; // RGBA 格式
            for (int y = 0; y < buffer.height; y++) {
                for (int x = 0; x < buffer.width; x++) {
                    pixels[y * buffer.stride + x] = color;
                }
            }
            // 解锁并推送到硬件合成器
            surface->unlockAndPost();
        }
        usleep(50000); // 50ms 刷新率
    }

    printf("Exiting... Clearing Native Window.\n");
    return 0;
}

