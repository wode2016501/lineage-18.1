#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_IHWSAFEUNION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_IHWSAFEUNION_H

#include <android/hardware/tests/safeunion/1.0/ISafeUnion.h>

#include <android/hardware/tests/safeunion/1.0/BnHwOtherInterface.h>
#include <android/hardware/tests/safeunion/1.0/BpHwOtherInterface.h>
#include <android/hidl/base/1.0/BnHwBase.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <android/hidl/safe_union/1.0/hwtypes.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace tests {
namespace safeunion {
namespace V1_0 {
::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::J &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::LargeSafeUnion &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::InterfaceTypeSafeUnion &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::safeunion::V1_0::ISafeUnion::HandleTypeSafeUnion &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V1_0
}  // namespace safeunion
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_SAFEUNION_V1_0_IHWSAFEUNION_H
