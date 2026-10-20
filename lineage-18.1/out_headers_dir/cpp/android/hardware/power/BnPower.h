#ifndef AIDL_GENERATED_ANDROID_HARDWARE_POWER_BN_POWER_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_POWER_BN_POWER_H_

#include <binder/IInterface.h>
#include <android/hardware/power/IPower.h>

namespace android {

namespace hardware {

namespace power {

class BnPower : public ::android::BnInterface<IPower> {
public:
  explicit BnPower();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnPower

}  // namespace power

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_POWER_BN_POWER_H_
