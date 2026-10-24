// dear imgui: standalone example application for Android + OpenGL ES 3

// Learn about Dear ImGui:
// - FAQ                  https://dearimgui.com/faq
// - Getting Started      https://dearimgui.com/getting-started
// - Documentation        https://dearimgui.com/docs (same as your local docs/ folder).
// - Introduction, links and more at the top of imgui.cpp

#include "imgui.h"
#include "imgui_impl_android.h"
#include "imgui_impl_opengl3.h"
#include <android/log.h>
// #include <android_native_app_glue.h>
#include <android/asset_manager.h>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include <string>
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
using namespace android;
ANativeWindow *window = nullptr;
int win_width = 1280;
int win_height = 720;

// Data
static EGLDisplay g_EglDisplay = EGL_NO_DISPLAY;
static EGLSurface g_EglSurface = EGL_NO_SURFACE;
static EGLContext g_EglContext = EGL_NO_CONTEXT;
// static struct android_app*  g_App = nullptr;
static bool g_Initialized = false;
static char g_LogTag[] = "ImGuiExample";
static std::string g_IniFilename = "";

// Forward declarations of helper functions
static void Init(struct android_app *app);
/*static void Shutdown();
static void MainLoopStep();
static int ShowSoftKeyboardInput();
static int PollUnicodeChars();*/

/*
// Main code
static void handleAppCmd(struct android_app* app, int32_t appCmd)
{
    switch (appCmd)
    {
    case APP_CMD_SAVE_STATE:
        break;
    case APP_CMD_INIT_WINDOW:
        Init(app);
        break;
    case APP_CMD_TERM_WINDOW:
        Shutdown();
        break;
    case APP_CMD_GAINED_FOCUS:
    case APP_CMD_LOST_FOCUS:
        break;
    }
}

static int32_t handleInputEvent(struct android_app* app, AInputEvent* inputEvent)
{
    return ImGui_ImplAndroid_HandleInputEvent(inputEvent);
}

void android_main(struct android_app* app)
{
    app->onAppCmd = handleAppCmd;
    app->onInputEvent = handleInputEvent;

    while (true)
    {
        int out_events;
        struct android_poll_source* out_data;

        // Poll all events. If the app is not visible, this loop blocks until g_Initialized == true.
        while (ALooper_pollOnce(g_Initialized ? 0 : -1, nullptr, &out_events, (void**)&out_data) >= 0)
        {
            // Process one event
            if (out_data != nullptr)
                out_data->process(app, out_data);

            // Exit the app by returning from within the infinite loop
            if (app->destroyRequested != 0)
            {
                // shutdown() should have been called already while processing the
                // app command APP_CMD_TERM_WINDOW. But we play save here
                if (!g_Initialized)
                    Shutdown();

                return;
            }
        }

        // Initiate a new frame
        MainLoopStep();
    }
}*/
void Init(ANativeWindow *window)
{
    if (g_Initialized)
        return;

    ANativeWindow_acquire(window);

    // Initialize EGL
    {
        g_EglDisplay = eglGetDisplay(EGL_DEFAULT_DISPLAY);
        if (g_EglDisplay == EGL_NO_DISPLAY)
            __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s", "eglGetDisplay(EGL_DEFAULT_DISPLAY) returned EGL_NO_DISPLAY");

        if (eglInitialize(g_EglDisplay, 0, 0) != EGL_TRUE)
            __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s", "eglInitialize() returned with an error");

        // 【核心修复】：必须显式指定 EGL_ALPHA_SIZE 为 8
        const EGLint egl_attributes[] = {
            EGL_RED_SIZE, 8,
            EGL_GREEN_SIZE, 8,
            EGL_BLUE_SIZE, 8,
            EGL_ALPHA_SIZE, 8, // 👈 【关键行】开启 8 位 Alpha 混合通道
            EGL_DEPTH_SIZE, 24,
            EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
            EGL_NONE};

        EGLint num_configs = 0;
        if (eglChooseConfig(g_EglDisplay, egl_attributes, nullptr, 0, &num_configs) != EGL_TRUE)
            __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s", "eglChooseConfig() returned with an error");
        if (num_configs == 0)
            __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s", "eglChooseConfig() returned 0 matching config");

        // Get the first matching config
        EGLConfig egl_config;
        eglChooseConfig(g_EglDisplay, egl_attributes, &egl_config, 1, &num_configs);

        EGLint egl_format;
        eglGetConfigAttrib(g_EglDisplay, egl_config, EGL_NATIVE_VISUAL_ID, &egl_format);

        // 强制窗口缓冲区格式为匹配的 RGBA_8888 格式
        ANativeWindow_setBuffersGeometry(window, 0, 0, egl_format);

        const EGLint egl_context_attributes[] = {EGL_CONTEXT_CLIENT_VERSION, 3, EGL_NONE};
        g_EglContext = eglCreateContext(g_EglDisplay, egl_config, EGL_NO_CONTEXT, egl_context_attributes);

        if (g_EglContext == EGL_NO_CONTEXT)
            __android_log_print(ANDROID_LOG_ERROR, g_LogTag, "%s", "eglCreateContext() returned EGL_NO_CONTEXT");

        g_EglSurface = eglCreateWindowSurface(g_EglDisplay, egl_config, window, nullptr);
        eglMakeCurrent(g_EglDisplay, g_EglSurface, g_EglSurface, g_EglContext);
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();

    io.IniFilename = g_IniFilename.c_str();

    // Setup Dear ImGui style
    ImGuiStyle &style = ImGui::GetStyle();
    ImGui::StyleColorsDark();

    style.FrameRounding = 3.0f;
    style.GrabRounding = 3.0f;

    // Setup Platform/Renderer backends
    ImGui_ImplAndroid_Init(window);
    ImGui_ImplOpenGL3_Init("#version 300 es");

    // Setup scaling
    float main_scale = 2.0f;
    style.ScaleAllSizes(main_scale);
    style.FontScaleDpi = main_scale;

    // 取消注释默认字体
    io.Fonts->AddFontDefault();

    g_Initialized = true;
}

void MainLoopStep()
{
    ImGuiIO &io = ImGui::GetIO();
    if (g_EglDisplay == EGL_NO_DISPLAY)
        return;

    // Our state
    // (we use static, which essentially makes the variable globals, as a convenience to keep the example code easy to follow)
    static bool show_demo_window = true;
    static bool show_another_window = false;
    static ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Poll Unicode characters via JNI
    // FIXME: do not call this every frame because of JNI overhead

    // Open on-screen (soft) input if requested by Dear ImGui
    static bool WantTextInputLast = false;
    // if (io.WantTextInput && !WantTextInputLast)
    //     ShowSoftKeyboardInput();
    WantTextInputLast = io.WantTextInput;

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame();
    ImGui::NewFrame();

    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);

    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
        ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);             // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float *)&clear_color); // Edit 3 floats representing a color

        if (ImGui::Button("Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        ImGui::End();
    }

    // 3. Show another simple window.
    if (show_another_window)
    {
        ImGui::Begin("Another Window", &show_another_window); // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me"))
            show_another_window = false;
        ImGui::End();
    }

    // Rendering
    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    eglSwapBuffers(g_EglDisplay, g_EglSurface);
}

void Shutdown()
{
    if (!g_Initialized)
        return;

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();
    ImGui::DestroyContext();

    if (g_EglDisplay != EGL_NO_DISPLAY)
    {
        eglMakeCurrent(g_EglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);

        if (g_EglContext != EGL_NO_CONTEXT)
            eglDestroyContext(g_EglDisplay, g_EglContext);

        if (g_EglSurface != EGL_NO_SURFACE)
            eglDestroySurface(g_EglDisplay, g_EglSurface);

        eglTerminate(g_EglDisplay);
    }

    g_EglDisplay = EGL_NO_DISPLAY;
    g_EglContext = EGL_NO_CONTEXT;
    g_EglSurface = EGL_NO_SURFACE;
    ANativeWindow_release(window);

    g_Initialized = false;
}

// Helper functions

// Unfortunately, there is no way to show the on-screen input from native code.
// Therefore, we call ShowSoftKeyboardInput() of the main activity implemented in MainActivity.kt via JNI.
/*static int ShowSoftKeyboardInput()
{
    JavaVM* java_vm = g_App->activity->vm;
    JNIEnv* java_env = nullptr;

    jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;

    jni_return = java_vm->AttachCurrentThread(&java_env, nullptr);
    if (jni_return != JNI_OK)
        return -2;

    jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
    if (native_activity_clazz == nullptr)
        return -3;

    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, "showSoftInput", "()V");
    if (method_id == nullptr)
        return -4;

    java_env->CallVoidMethod(g_App->activity->clazz, method_id);

    jni_return = java_vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;

    return 0;
}*/

// Unfortunately, the native KeyEvent implementation has no getUnicodeChar() function.
// Therefore, we implement the processing of KeyEvents in MainActivity.kt and poll
// the resulting Unicode characters here via JNI and send them to Dear ImGui.
/*static int PollUnicodeChars()
{
    JavaVM* java_vm = g_App->activity->vm;
    JNIEnv* java_env = nullptr;

    jint jni_return = java_vm->GetEnv((void**)&java_env, JNI_VERSION_1_6);
    if (jni_return == JNI_ERR)
        return -1;

    jni_return = java_vm->AttachCurrentThread(&java_env, nullptr);
    if (jni_return != JNI_OK)
        return -2;

    jclass native_activity_clazz = java_env->GetObjectClass(g_App->activity->clazz);
    if (native_activity_clazz == nullptr)
        return -3;

    jmethodID method_id = java_env->GetMethodID(native_activity_clazz, "pollUnicodeChar", "()I");
    if (method_id == nullptr)
        return -4;

    // Send the actual characters to Dear ImGui
    ImGuiIO& io = ImGui::GetIO();
    jint unicode_character;
    while ((unicode_character = java_env->CallIntMethod(g_App->activity->clazz, method_id)) != 0)
        io.AddInputCharacter(unicode_character);

    jni_return = java_vm->DetachCurrentThread();
    if (jni_return != JNI_OK)
        return -5;

    return 0;
}*/
#include <unistd.h> // 用于 usleep

int main(int argc, char **argv)
{
    // 1. 初始化 SurfaceFlinger 720p 窗口
    // 1. 初始化 SurfaceFlinger 窗口
    // 1. 初始化 SurfaceFlinger 720p 窗口
    sp<SurfaceComposerClient> client = new SurfaceComposerClient();

    // 在 Android 9 中，需要确保 flags 中没有 ISurfaceComposerClient::eOpaque (0x00000400)
    // 这里我们传入 0 即可，不要误传类似 ISurfaceComposerClient::eOpaque 的值
    uint32_t flags = 0;

    sp<SurfaceControl> surfaceControl = client->createSurface(
        String8("PureCpp720pWindow"),
        win_width,
        win_height,
        PIXEL_FORMAT_RGBA_8888, // 必须是带 Alpha 的格式
        flags);

    SurfaceComposerClient::Transaction t;
    t.setLayer(surfaceControl, 0x7FFFFFFF)
        .setPosition(surfaceControl, 0, 200)
        .setSize(surfaceControl, win_width, win_height);

// 【Android 9 核心修复】显式将不透明 Flag（0x02）清空
// setFlags 的三个参数分别是：(surfaceControl, 期望的值, 要修改的遮罩)
// 传入 0 和 0x02，代表强制将 eLayerOpaque 这一位设为 0（即非不透明状态）
#ifdef layer_state_t
    t.setFlags(surfaceControl, 0, layer_state_t::eLayerOpaque);
#else
    t.setFlags(surfaceControl, 0, 0x02);
#endif

    t.show(surfaceControl)
        .apply();

    ANativeWindow *window = surfaceControl->getSurface().get();
    if (window == nullptr)
        return -1;

    // 2. 初始化 EGL 和 ImGui
    Init(window);

    // 【重要】确保 ImGui 有默认字体，如果你的 Init 里全部注释了，请在 main 或 Init 里显式加上这一行
    /* if (ImGui::GetIO().Fonts->Fonts.empty())
     {
         ImGui::GetIO().Fonts->AddFont some Font... // 或者确保下文 Init 中的默认字体取消注释
     }*/

    // 3. 【核心修复】主渲染循环
    // 因为是独立二进制程序，我们需要用死循环保持它一直运行
    bool running = true;
    while (running)
    {
        // a. 开始 ImGui 新的一帧
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplAndroid_NewFrame();
        ImGui::NewFrame();

        // b. 编写你的 ImGui 界面测试窗口
        ImGui::SetNextWindowPos(ImVec2(10, 10), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(300, 200), ImGuiCond_FirstUseEver);

        ImGui::Begin("SurfaceFlinger ImGui Window");
        ImGui::Text("Hello from Native Executable!");
        if (ImGui::Button("Exit"))
        {
            running = false; // 点击按钮可以退出
        }
        ImGui::End();

        // c. 执行渲染计算
        ImGui::Render();

        // d. 设定 OpenGL 清屏颜色（设置为半透明或黑色，便于看清 UI）
        glViewport(0, 0, win_width, win_height);
        // 确保最后一个参数是 0.0f（代表完全透明清屏）
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // e. 将 ImGui 绘制数据渲染到 OpenGL
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // f. 【关键】交换双缓冲区，将画面真正推送到手机屏幕上
        eglSwapBuffers(g_EglDisplay, g_EglSurface);

        // g. 控制帧率，防止 CPU 100% 满载（大约 60 帧）
        usleep(16666);
    }

    // 4. 清理资源（可选）
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplAndroid_Shutdown();
    ImGui::DestroyContext();

    if (g_EglDisplay != EGL_NO_DISPLAY)
    {
        eglMakeCurrent(g_EglDisplay, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
        eglDestroyContext(g_EglDisplay, g_EglContext);
        eglDestroySurface(g_EglDisplay, g_EglSurface);
        eglTerminate(g_EglDisplay);
    }

    return 0;
}

int read_all(int fd, char *buf, int len)
{
    int n = len;
    while (n > 0)
    {
        int r = read(fd, buf, n);
        if (r < 1)
        {
            return -1;
        }
        buf += r;
        n -= r;
    }
    return len;
}
struct touch
{
    int id;
    int x;
    int y;
    int active;
};

void pthread_fun_mouse(void *arg)
{
    int id_count = 0;
    int fd = 0;
    int x = 0;
    int y = 0;
    int size = 0;
    char buf[16];
    struct touch touch;
    ImGuiIO &io = ImGui::GetIO();
    // 全局或静态变量，保存当前的鼠标模拟坐标
    static float g_SimulatedMouseX = 100.0f;
    static float g_SimulatedMouseY = 100.0f;
     char Button_Left = 0;
    int ret=0;
    while (1)
    {
         ret = read_all(fd, (char *)&size, sizeof(int));
        if (ret != sizeof(int))
        {
            break;
        }
        if (size != sizeof(struct touch))
        {
            ret =read_all(fd, buf, size);
            continue;
        }
        ret =read_all(fd, (char *)&touch, sizeof(struct touch));
        if (ret != sizeof(struct touch))
        {
            break;
        }
        if (touch.active == 0)
        {
            id_count++;
        }
        if (touch.active == 0 && touch.id == 0)
        {
            x = touch.x;
            y = touch.y;
        }
        if (touch.active == 1 && touch.id == 0)
        {
            g_SimulatedMouseX += touch.x - x;
            g_SimulatedMouseY += touch.y - y;
            io.AddMousePosEvent(g_SimulatedMouseX, g_SimulatedMouseY);
            x = touch.x;
            y = touch.y;
        }
        if (touch.active == 2)
        {
            id_count--;
        }
        // 在每帧的 ImGui::NewFrame() 之前注入给 ImGui
        // io.AddMousePosEvent(g_SimulatedMouseX, g_SimulatedMouseY);

        // 参数 0 代表鼠标左键 (ImGuiMouseButton_Left)
        // 参数 true 代表按下，false 代表松开
        if (id_count > 2 && Button_Left == 0)
        {
            Button_Left = 1;
            io.AddMouseButtonEvent(0, true);
        }
        if (id_count < 2 && Button_Left == 1)
        {
            Button_Left = 0;
            io.AddMouseButtonEvent(0, false);
        }
        /*  //功能缺失
                if (wheel_up_signal)
                {
                    // 注入垂直滚轮向上滚动 1 个单位
                    io.AddMouseWheelEvent(0.0f, 1.0f);
                }

                // 当接收到向下滚动信号
                if (wheel_down_signal)
                {
                    // 注入垂直滚轮向下滚动 1 个单位
                    io.AddMouseWheelEvent(0.0f, -1.0f);
                }
                    */
    }
    close(fd);
    return ;
}
