#ifndef AIDL_GENERATED_ANDROID_HARDWARE_POWER_BP_POWER_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_POWER_BP_POWER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/power/IPower.h>

namespace android {

namespace hardware {

namespace power {

class BpPower : public ::android::BpInterface<IPower> {
public:
  explicit BpPower(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPower() = default;
  ::android::binder::Status setMode(::android::hardware::power::Mode type, bool enabled) override;
  ::android::binder::Status isModeSupported(::android::hardware::power::Mode type, bool* _aidl_return) override;
  ::android::binder::Status setBoost(::android::hardware::power::Boost type, int32_t durationMs) override;
  ::android::binder::Status isBoostSupported(::android::hardware::power::Boost type, bool* _aidl_return) override;
};  // class BpPower

}  // namespace power

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_POWER_BP_POWER_H_
