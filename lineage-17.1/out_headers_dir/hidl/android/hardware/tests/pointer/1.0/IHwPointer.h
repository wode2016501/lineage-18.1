#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IHWPOINTER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IHWPOINTER_H

#include <android/hardware/tests/pointer/1.0/IPointer.h>

#include <android/hidl/base/1.0/BnHwBase.h>
#include <android/hidl/base/1.0/BpHwBase.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace tests {
namespace pointer {
namespace V1_0 {
::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IPointer::Ada *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IPointer::Ada &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IPointer::Bob *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IPointer::Bob &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IPointer::Cin *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IPointer::Cin &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IPointer::Dom *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IPointer::Dom &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedReferenceFromParcel(
        ::android::hardware::tests::pointer::V1_0::IPointer::Ptr *obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle, size_t parentOffset);

::android::status_t writeEmbeddedReferenceToParcel(
        const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr &obj,
        ::android::hardware::Parcel *,
        size_t parentHandle, size_t parentOffset);

}  // namespace V1_0
}  // namespace pointer
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IHWPOINTER_H
