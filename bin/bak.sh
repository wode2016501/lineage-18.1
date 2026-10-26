#find . -type d  -name 'include' -print0   | tar -czvf include.tar.gz --null -T -
#find . -type f \( -name '*.aidl' -o -name '*.h'  -o -name '*.hal' \) -print0   | tar -czvf headers.tar.gz --null -T -
find .  \( -name '*.aidl' -o -name '*.h'  -o -name '*.hal' -o -name '*.proto' -o -name 'include' \) -print0   | tar -czvf bak.tar.gz --null -T -

