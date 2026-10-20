#ifndef AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_BN_CUSTOM_VIBRATOR_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_BN_CUSTOM_VIBRATOR_H_

#include <binder/IInterface.h>
#include <android/hardware/tests/extension/vibrator/ICustomVibrator.h>

namespace android {

namespace hardware {

namespace tests {

namespace extension {

namespace vibrator {

class BnCustomVibrator : public ::android::BnInterface<ICustomVibrator> {
public:
  explicit BnCustomVibrator();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCustomVibrator

}  // namespace vibrator

}  // namespace extension

}  // namespace tests

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_BN_CUSTOM_VIBRATOR_H_
