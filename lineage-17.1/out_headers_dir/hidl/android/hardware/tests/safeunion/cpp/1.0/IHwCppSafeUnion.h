#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_CPP_V1_0_IHWCPPSAFEUNION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_CPP_V1_0_IHWCPPSAFEUNION_H

#include <android/hardware/tests/safeunion/cpp/1.0/ICppSafeUnion.h>

#include <android/hidl/base/1.0/BnHwBase.h>
#include <android/hidl/base/1.0/BpHwBase.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace tests {
namespace safeunion {
namespace cpp {
namespace V1_0 {
::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion::PointerFmqSafeUnion &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion::PointerFmqSafeUnion &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion::FmqSafeUnion &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::safeunion::cpp::V1_0::ICppSafeUnion::FmqSafeUnion &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V1_0
}  // namespace cpp
}  // namespace safeunion
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_CPP_V1_0_IHWCPPSAFEUNION_H
