OUT_DIR="$(pwd)/out_headers_dir"
echo okok
mkdir -p "$OUT_DIR"
inc="$(find *  -name "*.aidl" |sed 's#android/.*##g'|grep '/$'|sort -u|sed 's#/$##g'|sed 's#^#-I #g'|tr '\n' ' ')"


# 2. 批量将系统核心的 .aidl 接口转换为 C++ 头文件
find  -name "*.aidl" | while read -r aidl_file; do
aidl --lang=cpp -o "$OUT_DIR" -h "$OUT_DIR" $inc "$aidl_file"|| echo aidl --lang=cpp -o "$OUT_DIR" -h "$OUT_DIR" $inc "$aidl_file"
done
