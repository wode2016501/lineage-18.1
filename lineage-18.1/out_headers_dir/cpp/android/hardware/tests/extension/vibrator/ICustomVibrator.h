#ifndef AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_I_CUSTOM_VIBRATOR_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_I_CUSTOM_VIBRATOR_H_

#include <android/hardware/tests/extension/vibrator/Directionality.h>
#include <android/hardware/tests/extension/vibrator/VendorEffect.h>
#include <android/hardware/vibrator/IVibratorCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace tests {

namespace extension {

namespace vibrator {

class ICustomVibrator : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CustomVibrator)
  enum  : int32_t {
    CAP_VENDOR_DIRECTIONALITY = 1,
  };
  virtual ::android::binder::Status getVendorCapabilities(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setDirectionality(::android::hardware::tests::extension::vibrator::Directionality directionality) = 0;
  virtual ::android::binder::Status perform(::android::hardware::tests::extension::vibrator::VendorEffect effect, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback, int32_t* _aidl_return) = 0;
};  // class ICustomVibrator

class ICustomVibratorDefault : public ICustomVibrator {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getVendorCapabilities(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setDirectionality(::android::hardware::tests::extension::vibrator::Directionality) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status perform(::android::hardware::tests::extension::vibrator::VendorEffect, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICustomVibratorDefault

}  // namespace vibrator

}  // namespace extension

}  // namespace tests

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_I_CUSTOM_VIBRATOR_H_
