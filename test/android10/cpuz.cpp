#include <stdio.h>
#include <unistd.h>
#include <gui/SurfaceComposerClient.h>
#include <gui/Surface.h>
#include <ui/DisplayInfo.h>
#include <android/native_window.h>
#include <cmath>

// 引入 FreeType
#include <ft2build.h>
#include FT_FREETYPE_H
#include <sys/sysinfo.h>
using namespace android;

int width = 400;
int height = 22;

FT_Library library;
FT_Face face;

// 初始化字体 (确保只在 main 开始时调用一次)
bool init_font()
{
    if (FT_Init_FreeType(&library))
        return false;
    // 尽量选择 Roboto-Regular 这种轻量非中文字体，文件极小，内存几乎不增加
    if (FT_New_Face(library, "/system/fonts/Roboto-Regular.ttf", 0, &face))
    {
        return false;
    }
    // 窗口高度是 22，我们将字高设为 16 像素，留出上下边距
    FT_Set_Pixel_Sizes(face, 0, 16);
    return true;
}
/*void draw_text_to_buffer(uint32_t *bits, int stride, const char *text, uint32_t text_color)
{
 //   int pen_x = 5; // 靠左留出 5 像素边距
    int pen_y = 4; // 靠上留出几像素对齐

    // 拆解文字颜色的 RGBA 分量 (假设小端序 ABGR/RGBA 格式，我们根据实际情况拆分)
    // 这里以常规 RGBA 为例，提取出 R, G, B 分量
    uint8_t text_r = (text_color >> 24) & 0xFF;
    uint8_t text_g = (text_color >> 16) & 0xFF;
    uint8_t text_b = (text_color >> 8) & 0xFF;
    uint8_t text_a = text_color & 0xFF; // 通常为 0xFF 不透明
    FT_Pos pen_x = 5 << 6;
    int baseline = 4 + (face->size->metrics.ascender >> 6);

    for (int i = 0; text[i]; i++)
    {
        if (FT_Load_Char(face, (unsigned char)text[i],
                         FT_LOAD_RENDER | FT_LOAD_TARGET_LIGHT))
            continue;

        FT_GlyphSlot slot = face->glyph;
        FT_Bitmap *bm = &slot->bitmap;

        int gx = (int)((pen_x + 32) >> 6) + slot->bitmap_left;
        int gy = baseline - slot->bitmap_top;

        for (int y = 0; y < bm->rows; y++)
        {
            int py = gy + y;
            if (py < 0 || py >= height)
                continue;
            const uint8_t *src = bm->buffer + y * bm->pitch; // ★ pitch
            uint32_t *line = bits + py * stride;
            for (int x = 0; x < bm->width; x++)
            {
                uint8_t a = src[x];
                if (!a)
                    continue;
                int px = gx + x;
                if (px < 0 || px >= width)
                    continue;
                if (a == 255)
                {
                    line[px] = text_color;
                    continue;
                }
                uint32_t bg = line[px];
                uint8_t br = (bg >> 24) & 0xFF, bgc = (bg >> 16) & 0xFF,
                        bb = (bg >> 8) & 0xFF;
                uint8_t r = (text_r * a + br * (255 - a) + 127) / 255;
                uint8_t g = (text_g * a + bgc * (255 - a) + 127) / 255;
                uint8_t b = (text_b * a + bb * (255 - a) + 127) / 255;
                line[px] = (r << 24) | (g << 16) | (b << 8) | 0xFF;
            }
        }
        pen_x += slot->advance.x; // ★ 保留亚像素
    }
}*/
// 绘制一整行文本到指定的 bits 中
void draw_text_to_buffer(uint32_t *bits, int stride, const char *text, uint32_t text_color)
{
    int pen_x = 5; // 靠左留出 5 像素边距
    int pen_y = 4; // 靠上留出几像素对齐

    // 拆解文字颜色的 RGBA 分量 (假设小端序 ABGR/RGBA 格式，我们根据实际情况拆分)
    // 这里以常规 RGBA 为例，提取出 R, G, B 分量
    uint8_t text_r = (text_color >> 24) & 0xFF;
    uint8_t text_g = (text_color >> 16) & 0xFF;
    uint8_t text_b = (text_color >> 8) & 0xFF;
    uint8_t text_a = text_color & 0xFF; // 通常为 0xFF 不透明

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (FT_Load_Char(face, text[i], FT_LOAD_RENDER))
            continue;

        FT_GlyphSlot slot = face->glyph;
        FT_Bitmap *bitmap = &slot->bitmap;

        int glyph_top = pen_y + 12 - slot->bitmap_top;

        for (int y = 0; y < bitmap->rows; y++)
        {
            int pixel_y = glyph_top + y;
            if (pixel_y >= height || pixel_y < 0)
                continue;

            uint32_t *line = bits + (pixel_y * stride);

            for (int x = 0; x < bitmap->width; x++)
            {
                int pixel_x = pen_x + slot->bitmap_left + x;
                if (pixel_x >= width || pixel_x < 0)
                    continue;

                // 获取 FreeType 的抗锯齿灰度值 (0 - 255)
                uint8_t font_alpha = bitmap->buffer[y * bitmap->width + x];
                if (font_alpha == 0)
                    continue; // 完全透明的地方不用管

                if (font_alpha == 255)
                {
                    // 核心区域，直接覆盖为文字颜色
                    line[pixel_x] = text_color;
                }
                else
                {
                    // --- 核心修复：边缘过渡区域，进行 Alpha 混合 ---
                    uint32_t bg_pixel = line[pixel_x];

                    // 拆解当前位置原本的背景色
                    uint8_t bg_r = (bg_pixel >> 24) & 0xFF;
                    uint8_t bg_g = (bg_pixel >> 16) & 0xFF;
                    uint8_t bg_b = (bg_pixel >> 8) & 0xFF;
                    uint8_t bg_a = bg_pixel & 0xFF;

                    // 计算混合权重 (0.0 ~ 1.0 映射到 0 ~ 255)
                    // 使用整数运算加速：混合后颜色 = (文字 * alpha + 背景 * (255 - alpha)) / 255
                    uint8_t out_r = (text_r * font_alpha + bg_r * (255 - font_alpha)) / 255;
                    uint8_t out_g = (text_g * font_alpha + bg_g * (255 - font_alpha)) / 255;
                    uint8_t out_b = (text_b * font_alpha + bg_b * (255 - font_alpha)) / 255;

                    // 维持原背景的透明度或者设为不透明
                    uint8_t out_a = bg_a;

                    // 重新组合像素写入 Buffer (请根据你手机的真实通道顺序微调，这里对应 0xRRGGBBAA)
                    line[pixel_x] = (out_r << 24) | (out_g << 16) | (out_b << 8) | out_a;
                }
            }
        }
        pen_x += (slot->advance.x >> 6); // 画笔右移
    }
}
int get_ram_busy(void)
{
    struct sysinfo si;
    unsigned long long total, avail;

    if (sysinfo(&si) != 0)
        return -1;

    total = (unsigned long long)si.totalram * si.mem_unit;
    avail = ((unsigned long long)si.freeram + si.bufferram) * si.mem_unit;

    if (total == 0 || avail > total)
        return -1;

    return (int)((total - avail) * 100 / total);
}

int get_cpu_busy1(FILE *fp)
{
    fseek(fp, 0, SEEK_SET);
    static unsigned long long prev_idle = 0, prev_total = 0;
    unsigned long long user, nice, system, idle, iowait, irq, softirq;
    unsigned long long total, idle_all, total_diff, idle_diff;
    if (!fp)
        return -1;
    if (fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu",
               &user, &nice, &system, &idle, &iowait, &irq, &softirq) != 7)
    {
        fclose(fp);
        return -1;
    }

    idle_all = idle + iowait;
    total = user + nice + system + idle_all + irq + softirq;

    if (prev_total == 0)
    { // 首次调用，没有基准，返回 0
        prev_idle = idle_all;
        prev_total = total;
        return 0;
    }

    total_diff = total - prev_total;
    idle_diff = idle_all - prev_idle;
    prev_idle = idle_all;
    prev_total = total;

    if (total_diff == 0)
        return 0;

    // 繁忙率 = (总时间增量 - 空闲时间增量) / 总时间增量
    return (int)((total_diff - idle_diff) * 100 / total_diff);
}
int get_cpu_busy(FILE *fp)
{
    fseek(fp, 0, SEEK_SET);
    static unsigned long long prev_idle = 0, prev_total = 0;
    unsigned long long user, nice, system, idle, iowait, irq, softirq;
    unsigned long long total, idle_all, total_diff, idle_diff;

    if (!fp)
        return -1;
    if (fscanf(fp, "cpu %llu %llu %llu %llu %llu %llu %llu",
               &user, &nice, &system, &idle, &iowait, &irq, &softirq) != 7)
    {
        fclose(fp);
        return -1;
    }

    // 关键：将 iowait 与 idle 合并计算“非繁忙”时间
    idle_all = idle + iowait;
    total = user + nice + system + idle_all + irq + softirq;

    if (prev_total == 0)
    {
        prev_idle = idle_all;
        prev_total = total;
        return 0;
    }

    total_diff = total - prev_total;
    idle_diff = idle_all - prev_idle;
    prev_idle = idle_all;
    prev_total = total;

    if (total_diff == 0)
        return 0;

    // 繁忙率 = (总增量 - 非繁忙增量) / 总增量
    return (int)((total_diff - idle_diff) * 100 / total_diff);
}
int get_val(int fd)
{
    lseek(fd, 0, SEEK_SET);
    char buffer[64];
    int val = 0;
    if (read(fd, buffer, sizeof(buffer)) > 0)
    {
        sscanf(buffer, "%d", &val);
    }
    return val;
}
int running = 1;
void signal_handler(int sig)
{
    printf("\n收到信号 %d，正在退出...\n", sig);
    running = 0;
}
int main()
{
    signal(SIGINT, signal_handler);
    printf("--- Native Status Monitor Start pid: %d ---\n", getpid());

    if (!init_font())
    {
        fprintf(stderr, "错误: 无法初始化 FreeType 字体\n");
        return 1;
    }

    sp<SurfaceComposerClient> client = new SurfaceComposerClient();
    if (client->initCheck() != NO_ERROR)
        return 1;

    sp<SurfaceControl> surfaceControl = client->createSurface(
        String8("StatusOverlaySurface"), width, height, PIXEL_FORMAT_RGBA_8888, 0);
    if (surfaceControl == nullptr)
        return 1;

    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF)   // 绝对顶层
        .setPosition(surfaceControl, 100, 0) // 放置在屏幕顶端合适位置
        .setAlpha(surfaceControl, 1.0f)
        .show(surfaceControl)
        .apply();

    sp<Surface> previewSurface = surfaceControl->getSurface();
    ANativeWindow *window = previewSurface.get();
    ANativeWindow_Buffer buffer;

    char status_text[64];
    /*
    OnePlus6T:/ # cat  /sys/class/kgsl/kgsl-3d0/gpu_busy_percentage
0 %
OnePlus6T:/ # cat  /sys/class/kgsl/kgsl-3d0/gpuclk
710000000
OnePlus6T:/ # cat  /sys/class/kgsl/kgsl-3d0/clock_mhz
710
OnePlus6T:/ # cat  /sys/class/kgsl/kgsl-3d0/gpuclk
710000000
OnePlus6T:/ #
OnePlus6T:/ # cat  /sys/class/power_supply/battery/current_now
-317000
OnePlus6T:/ #
*/
    int fd_gpu_busy = open("/sys/class/kgsl/kgsl-3d0/gpu_busy_percentage", 0);
    int fd_gpu_mhz = open("/sys/class/kgsl/kgsl-3d0/clock_mhz", 0);
    int fd_battery_now = open("/sys/class/power_supply/battery/current_now", 0);
    FILE *fp_stat = fopen("/proc/stat", "r");
    int gpu_busy = 0;
    int gpu_mhz = 0;
    int battery_now = 0;
    int cpu_busy = 0;
    int ram_busy = 0;
    while (running)
    {
        if (ANativeWindow_lock(window, &buffer, nullptr) == 0)
        {
            uint32_t *bits = (uint32_t *)buffer.bits;

            // 1. 清屏：这里用半透明黑色背景 (0x80000000) 或者全透明 (0x00000000)
            // 这样你的状态栏文字就能完美悬浮在系统画面之上了
            uint32_t bg_color = 0xff000000; // 带一点黑色半透明遮罩
            for (int y = 0; y < buffer.height; y++)
            {
                uint32_t *line = bits + (y * buffer.stride);
                for (int x = 0; x < buffer.width; x++)
                {
                    line[x] = bg_color;
                }
            }
            if (fd_gpu_busy > 0)
            {
                gpu_busy = get_val(fd_gpu_busy);
            }
            if (fd_gpu_mhz > 0)
            {
                gpu_mhz = get_val(fd_gpu_mhz);
            }
            if (fd_battery_now > 0)
            {
                battery_now = get_val(fd_battery_now);
            }
            if (fp_stat != NULL)
            {
                cpu_busy = get_cpu_busy(fp_stat);
            }
            ram_busy = get_ram_busy();

            // 2. 模拟/获取 CPU 和 内存数据

            snprintf(status_text, sizeof(status_text), "CPU: %d%% GPU: %d%%,%dMhz RAM: %d%% BATT: %dmA", cpu_busy, gpu_busy,gpu_mhz, ram_busy, battery_now / 1000);
            // 3. 绘制文字 (绿色: 0xFF00FF00)
            draw_text_to_buffer(bits, buffer.stride, status_text, 0xFF00FF00);

            ANativeWindow_unlockAndPost(window);
        }
        sleep(1); // 每秒刷新一次
    }

    FT_Done_Face(face);
    FT_Done_FreeType(library);
    close(fd_gpu_busy);
    close(fd_gpu_mhz);
    close(fd_battery_now);
    fclose(fp_stat);
    return 0;
}
