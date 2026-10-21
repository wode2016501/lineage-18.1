获得版本a.xml
https://github.com/LineageOS/android/raw/refs/heads/lineage-18.0/default.xml

clang-21+
```bash
:/data/.wode/src # sed -n '145,152p' /data/.wode/data/com.termux/files/usr/include/c++/v1/__memory/allocator_traits.h                                                                                                                                         

template <class _Tp, class _Up, bool = __has_rebind_other_v<_Tp, _Up> >
struct __allocator_traits_rebind {
//  static_assert(__has_rebind_other_v<_Tp, _Up>, "This allocator has to implement rebind");
static_assert(true, "Disable strict rebind check");  
//using type _LIBCPP_NODEBUG = typename _Tp::template rebind<_Up>::other;
using type _LIBCPP_NODEBUG = _Tp; 
};
:/data/.wode/src #
linux:
android-gcc

Termux: 
cp xbin/* /system/xbin/ -a
```
修改clang*cfg对应版本

-resource-dir=/data/.wode/data/com.termux/files/usr/lib/clang/



sed -i 's/^using ::\([a-zA-Z0-9_]*\);$/using ::\1 __attribute__((using_if_exists));/' \
    external/libcxx/include/cmath
