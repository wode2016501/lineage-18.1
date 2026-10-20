#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IHWIMPORTRULES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IHWIMPORTRULES_H

#include <android/hardware/tests/bar/1.0/IImportRules.h>

#include <android/hardware/tests/bar/1.0/hwtypes.h>
#include <android/hardware/tests/foo/1.0/BnHwFooCallback.h>
#include <android/hardware/tests/foo/1.0/BpHwFooCallback.h>
#include <android/hardware/tests/foo/1.0/hwtypes.h>
#include <android/hidl/base/1.0/BnHwBase.h>
#include <android/hidl/base/1.0/BpHwBase.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace tests {
namespace bar {
namespace V1_0 {
::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::tests::bar::V1_0::IImportRules::Outer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::tests::bar::V1_0::IImportRules::Outer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V1_0
}  // namespace bar
}  // namespace tests
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IHWIMPORTRULES_H
