cmake_minimum_required(VERSION 3.22.1)
project(imgui_surfaceflinger_demo C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 强制为可执行文件加上位置无关代码支持，防止特定环境报错
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    .
    ../../                  
    ../../backends          
)

set(SOURCE_FILES
    ../main.cpp             
    ../../imgui.cpp
    ../../imgui_draw.cpp
    ../../imgui_widgets.cpp
    ../../imgui_tables.cpp
    ../../imgui_demo.cpp
    ../../backends/imgui_impl_android.cpp
    ../../backends/imgui_impl_opengl3.cpp
)

add_executable(imgui_sf_window ${SOURCE_FILES})

# 🚀 补全你的媒体解码与音频所需的本地底层库 (mediandk, audioclient, binder 等)
target_link_libraries(imgui_sf_window
    gui
    ui
    utils
    binder
    android
    EGL
    GLESv3
    log
    mediandk
    audioclient
)

