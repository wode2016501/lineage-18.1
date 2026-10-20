#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V2_0_HWTYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V2_0_HWTYPES_H

#include <android/hardware/tests/memory/2.0/types.h>


#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace tests {
namespace memory {
namespace V2_0 {
::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::memory::V2_0::TwoMemory &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::memory::V2_0::TwoMemory &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V2_0
}  // namespace memory
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MEMORY_V2_0_HWTYPES_H
