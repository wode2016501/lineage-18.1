#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IHWFOO_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IHWFOO_H

#include <android/hardware/tests/foo/1.0/IFoo.h>

#include <android/hardware/tests/foo/1.0/BnHwFooCallback.h>
#include <android/hardware/tests/foo/1.0/BpHwFooCallback.h>
#include <android/hardware/tests/foo/1.0/BnHwMyTypes.h>
#include <android/hardware/tests/foo/1.0/BpHwMyTypes.h>
#include <android/hardware/tests/foo/1.0/BnHwSimple.h>
#include <android/hardware/tests/foo/1.0/BpHwSimple.h>
#include <android/hardware/tests/foo/1.0/BnHwTheirTypes.h>
#include <android/hardware/tests/foo/1.0/BpHwTheirTypes.h>
#include <android/hardware/tests/foo/1.0/hwtypes.h>
#include <android/hidl/base/1.0/BnHwBase.h>
#include <android/hidl/base/1.0/BpHwBase.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace tests {
namespace foo {
namespace V1_0 {
::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::Goober &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::Goober &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::Quux &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::Quux &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5 &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5 &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3 &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3 &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::MyHandle &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::MyHandle &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::Everything &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::Everything &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V1_0
}  // namespace foo
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IHWFOO_H
