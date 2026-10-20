#!/bin/bash
echo "=== 开始利用高版本 SDK 30.0.3 aidl 转换原生跨进程接口 ==="
# 6. 批量将系统核心的 .aidl 接口转换为 C++ 头文件（已彻底去掉 2>/dev/null，暴露出所有细节）
# 3. 显式指定高版本 SDK 30.0.3 的 aidl 编译器路径
AIDL_CMD="/opt/android-sdk/build-tools/30.0.3/aidl"
OUT_DIR="out_headers_dir/ndk"
mkdir -p "$OUT_DIR"
aidlinc="$(find hardware frameworks -type d -name  aidl |awk '{printf " -I"$1}')"
echo >k.sh
find . -name "*.aidl"|strings | while read -r aidl_file; do
    echo $AIDL_CMD --lang=ndk \
	    --structured \
              --stability vintf \
              -o "$OUT_DIR" \
              -h "$OUT_DIR" \
             "$aidlinc" \
	     "$aidl_file" "||" $AIDL_CMD --lang=ndk \
	    --structured  \
              -o "$OUT_DIR" \
              -h "$OUT_DIR" \
             "$aidlinc" \
	     "$aidl_file"   >>k.sh
done

OUT_DIR="out_headers_dir/cpp"
mkdir -p "$OUT_DIR"

find . -name "*.aidl"|strings | while read -r aidl_file; do
    echo $AIDL_CMD --lang=cpp \
	    --structured \
              --stability vintf \
              -o "$OUT_DIR" \
              -h "$OUT_DIR" \
             "$aidlinc" \
	     "$aidl_file" "||" $AIDL_CMD --lang=cpp \
	    --structured  \
              -o "$OUT_DIR" \
              -h "$OUT_DIR" \
             "$aidlinc" \
	     "$aidl_file"   >>k.sh
done
sh k.sh
echo "=== 🎉 转换完成！所有 18.1 动态头文件已输出至: $OUT_DIR ==="
exit



