#ifndef AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BN_VIBRATOR_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BN_VIBRATOR_H_

#include <binder/IInterface.h>
#include <android/hardware/vibrator/IVibrator.h>

namespace android {

namespace hardware {

namespace vibrator {

class BnVibrator : public ::android::BnInterface<IVibrator> {
public:
  explicit BnVibrator();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVibrator

}  // namespace vibrator

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BN_VIBRATOR_H_
