#ifndef AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BP_VIBRATOR_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BP_VIBRATOR_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/vibrator/IVibratorCallback.h>

namespace android {

namespace hardware {

namespace vibrator {

class BpVibratorCallback : public ::android::BpInterface<IVibratorCallback> {
public:
  explicit BpVibratorCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVibratorCallback() = default;
  ::android::binder::Status onComplete() override;
};  // class BpVibratorCallback

}  // namespace vibrator

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_BP_VIBRATOR_CALLBACK_H_
