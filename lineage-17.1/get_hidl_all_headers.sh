# 2. 扫描并精准转换所有接口
OUT_DIR=out_headers_dir/hidl
mkdir -p "$OUT_DIR"
find system/libhidl/transport/ hardware/interfaces/ -name "*.hal" | while read -r hal_file; do
    # 直接从 .hal 文件内部提取真实的 package 定义（例如：package android.hidl.manager@1.0;）
    raw_package=$(grep -E "^package " "$hal_file" | sed -E 's/package (.*);/\1/')
    
    if [ -n "$raw_package" ]; then
        echo "正在提取并转换: $raw_package"
        
        # 统一执行转换
                hidl-gen -o "$OUT_DIR" \
                 -Lc++-headers \
                 -r android.hardware:hardware/interfaces \
                 -r android.hidl:system/libhidl/transport \
                 "$raw_package"
    fi
done 
