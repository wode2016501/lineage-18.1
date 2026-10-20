#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V2_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V2_0_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tests {
namespace memory {
namespace V2_0 {

// Forward declaration for forward reference support:
struct TwoMemory;

struct TwoMemory final {
    ::android::hardware::hidl_memory mem1 __attribute__ ((aligned(8)));
    ::android::hardware::hidl_memory mem2 __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::tests::memory::V2_0::TwoMemory, mem1) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::tests::memory::V2_0::TwoMemory, mem2) == 40, "wrong offset");
static_assert(sizeof(::android::hardware::tests::memory::V2_0::TwoMemory) == 80, "wrong size");
static_assert(__alignof(::android::hardware::tests::memory::V2_0::TwoMemory) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::tests::memory::V2_0::TwoMemory& o);
// operator== and operator!= are not generated for TwoMemory

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::memory::V2_0::TwoMemory& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".mem1 = ";
    os += ::android::hardware::toString(o.mem1);
    os += ", .mem2 = ";
    os += ::android::hardware::toString(o.mem2);
    os += "}"; return os;
}

// operator== and operator!= are not generated for TwoMemory


}  // namespace V2_0
}  // namespace memory
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V2_0_TYPES_H
