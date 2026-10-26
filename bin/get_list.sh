test -f default.xml||exec echo '去https://github.com/LineageOS/android 下载对应 default.xml'
echo 'default=" --depth 1 -b lineage-17.1 https://github.com"' >k.sh
echo 'aosp="--depth 1 -b android-10.0.0_r41 https://android.googlesource.com"' >>k.sh
echo 'pdk=' >>k.sh
cat wlist | while read a; do
    # 找到匹配的行
    line=$(grep "<project path=\"$a\"" default.xml)
    if [ -n "$line" ]; then
        # 分别提取 path, name, remote, revision 属性的值
        path=$(echo "$line" | sed -n 's/.*path="\([^"]*\)".*/\1/p')
        name=$(echo "$line" | sed -n 's/.*name="\([^"]*\)".*/\1/p')
        remote=$(echo "$line" | sed -n 's/.*remote="\([^"]*\)".*/\1/p')
        groups=$(echo "$line" | sed -n 's/.*groups="\([^"]*\)".*/\1/p')
        
        # 打印输出，如果没有 remote 或 revision，就打印空白
        echo "echo git clone  \$${remote:-default}/$name.git \$${groups:-none}  $path"
    else
        echo " "
    fi
done >>k.sh
sh k.sh
rm k.sh

