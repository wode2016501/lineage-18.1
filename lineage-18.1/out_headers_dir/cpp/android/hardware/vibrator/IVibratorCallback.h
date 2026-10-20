#ifndef AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_I_VIBRATOR_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_I_VIBRATOR_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace vibrator {

class IVibratorCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VibratorCallback)
  virtual ::android::binder::Status onComplete() = 0;
};  // class IVibratorCallback

class IVibratorCallbackDefault : public IVibratorCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onComplete() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVibratorCallbackDefault

}  // namespace vibrator

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_I_VIBRATOR_CALLBACK_H_
