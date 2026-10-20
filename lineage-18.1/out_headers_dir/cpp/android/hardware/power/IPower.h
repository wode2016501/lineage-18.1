#ifndef AIDL_GENERATED_ANDROID_HARDWARE_POWER_I_POWER_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_POWER_I_POWER_H_

#include <android/hardware/power/Boost.h>
#include <android/hardware/power/Mode.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace power {

class IPower : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Power)
  virtual ::android::binder::Status setMode(::android::hardware::power::Mode type, bool enabled) = 0;
  virtual ::android::binder::Status isModeSupported(::android::hardware::power::Mode type, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setBoost(::android::hardware::power::Boost type, int32_t durationMs) = 0;
  virtual ::android::binder::Status isBoostSupported(::android::hardware::power::Boost type, bool* _aidl_return) = 0;
};  // class IPower

class IPowerDefault : public IPower {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setMode(::android::hardware::power::Mode, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isModeSupported(::android::hardware::power::Mode, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setBoost(::android::hardware::power::Boost, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isBoostSupported(::android::hardware::power::Boost, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IPowerDefault

}  // namespace power

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_POWER_I_POWER_H_
