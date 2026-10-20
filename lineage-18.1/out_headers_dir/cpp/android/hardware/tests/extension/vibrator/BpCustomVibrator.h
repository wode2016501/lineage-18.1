#ifndef AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_BP_CUSTOM_VIBRATOR_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_BP_CUSTOM_VIBRATOR_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/tests/extension/vibrator/ICustomVibrator.h>

namespace android {

namespace hardware {

namespace tests {

namespace extension {

namespace vibrator {

class BpCustomVibrator : public ::android::BpInterface<ICustomVibrator> {
public:
  explicit BpCustomVibrator(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCustomVibrator() = default;
  ::android::binder::Status getVendorCapabilities(int32_t* _aidl_return) override;
  ::android::binder::Status setDirectionality(::android::hardware::tests::extension::vibrator::Directionality directionality) override;
  ::android::binder::Status perform(::android::hardware::tests::extension::vibrator::VendorEffect effect, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback, int32_t* _aidl_return) override;
};  // class BpCustomVibrator

}  // namespace vibrator

}  // namespace extension

}  // namespace tests

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_BP_CUSTOM_VIBRATOR_H_
