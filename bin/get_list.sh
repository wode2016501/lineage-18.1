test -f default.xml||exec echo '去https://github.com/LineageOS/android 下载对应 default.xml'
da="$(cat *.xml |grep -A 2 '<default' |grep -E '<default|remote='|grep 'revision='|awk -F'"' '{print $2}'|awk -F '/' '{print $3}'|tr -d '\n')"
ao="$(cat *.xml |grep -A 5 'remote.*name="aosp"' |grep "revision="|head -n 1|awk -F'"' '{print $2}'|awk -F '/' '{print $3}')"
echo 'default=" --depth 1 -b '"$da"' https://github.com"' >k.sh
echo 'aosp="--depth 1 -b '"$ao"' https://android.googlesource.com"' >>k.sh
echo 'pdk=' >>k.sh
cat wlist |sort -u| while read a; do
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

