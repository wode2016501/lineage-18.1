#ifndef AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BN_VIBRATOR_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BN_VIBRATOR_CALLBACK_H_

#include <binder/IInterface.h>
#include <android/hardware/vibrator/IVibratorCallback.h>

namespace android {

namespace hardware {

namespace vibrator {

class BnVibratorCallback : public ::android::BnInterface<IVibratorCallback> {
public:
  explicit BnVibratorCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVibratorCallback

}  // namespace vibrator

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BN_VIBRATOR_CALLBACK_H_
