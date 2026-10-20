#!/bin/bash

# 建立输出目录
OUT_DIR="$(pwd)/out_headers"
mkdir -p "$OUT_DIR"

echo "=== 开始利用本地 17.1 源码与系统工具生成 .h 文件 ==="

# 封装 hidl-gen 转换函数
generate_hidl() {
    local interface=$1
    echo "正在转换 HIDL -> C++ 头文件: $interface"
    hidl-gen -o "$OUT_DIR" \
             -Lc++-headers \
             -r android.hardware:hardware/interfaces \
             -r android.hidl:system/libhidl/transport \
             "$interface"
}

# 1. 批量提取你的脚本所需的全局 HAL 核心类
generate_hidl android.hidl.manager@1.0
generate_hidl android.hidl.manager@1.1
generate_hidl android.hidl.base@1.0
generate_hidl android.hardware.graphics.common@1.0
generate_hidl android.hardware.graphics.common@1.1
generate_hidl android.hardware.media@1.0
generate_hidl android.hardware.graphics.bufferqueue@1.0

echo "=== 开始利用 aidl 转换原生跨进程接口 ==="

# 2. 批量将系统核心的 .aidl 接口转换为 C++ 头文件
find frameworks/native/libs/binder/ -name "*.aidl" | while read -r aidl_file; do
    aidl --lang=cpp -o "$OUT_DIR" -h "$OUT_DIR" -I frameworks/native/libs/binder/aidl "$aidl_file" 
done

find frameworks/av/camera/ -name "*.aidl" | while read -r aidl_file; do
    aidl --lang=cpp -o "$OUT_DIR" -h "$OUT_DIR" -I frameworks/av/camera/aidl "$aidl_file" 
done

# 确保在你的工作目录下
cd /media/wode/ec61acb7-033a-45dd-93e8-6a5ee077741d/lineage-17.1

# 1. 强行补齐缺失的 graphics.common@1.2 头文件
hidl-gen -o ./out_headers \
         -Lc++-headers \
         -r android.hardware:hardware/interfaces \
         -r android.hidl:system/libhidl/transport \
         android.hardware.graphics.common@1.2

# 2. 【安全起见】把可能用到的其他 graphics 1.2 变体也顺便生成了
hidl-gen -o ./out_headers \
         -Lc++-headers \
         -r android.hardware:hardware/interfaces \
         -r android.hidl:system/libhidl/transport \
         android.hardware.graphics.mapper@3.0 2>/dev/null
# 确保在你的工作目录下
cd /media/wode/ec61acb7-033a-45dd-93e8-6a5ee077741d/lineage-17.1

# 1. 强行生成全新的 graphics.bufferqueue@2.0 头文件
hidl-gen -o ./out_headers \
         -Lc++-headers \
         -r android.hardware:hardware/interfaces \
         -r android.hidl:system/libhidl/transport \
         android.hardware.graphics.bufferqueue@2.0

# 2. 【安全起见】把经常和它配套使用的另一个 2.0 缓冲区核心类也顺便生成了，防止它下一步报错
hidl-gen -o ./out_headers \
         -Lc++-headers \
         -r android.hardware:hardware/interfaces \
         -r android.hidl:system/libhidl/transport \
         android.hardware.graphics.bufferqueue@1.0 2>/dev/null

echo "=== 🎉 转换完成！所有 Soong 动态头文件已输出至: $OUT_DIR ==="
