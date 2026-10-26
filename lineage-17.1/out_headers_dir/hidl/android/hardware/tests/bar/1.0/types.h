#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tests {
namespace bar {
namespace V1_0 {

// Forward declaration for forward reference support:
struct Def;

struct Def final {
    ::android::hardware::hidl_vec<::android::hardware::hidl_string> vs __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::tests::bar::V1_0::Def, vs) == 0, "wrong offset");
static_assert(sizeof(::android::hardware::tests::bar::V1_0::Def) == 16, "wrong size");
static_assert(__alignof(::android::hardware::tests::bar::V1_0::Def) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::Def& o);
static inline bool operator==(const ::android::hardware::tests::bar::V1_0::Def& lhs, const ::android::hardware::tests::bar::V1_0::Def& rhs);
static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::Def& lhs, const ::android::hardware::tests::bar::V1_0::Def& rhs);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::Def& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".vs = ";
    os += ::android::hardware::toString(o.vs);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::bar::V1_0::Def& lhs, const ::android::hardware::tests::bar::V1_0::Def& rhs) {
    if (lhs.vs != rhs.vs) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::Def& lhs, const ::android::hardware::tests::bar::V1_0::Def& rhs){
    return !(lhs == rhs);
}


}  // namespace V1_0
}  // namespace bar
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_TYPES_H
