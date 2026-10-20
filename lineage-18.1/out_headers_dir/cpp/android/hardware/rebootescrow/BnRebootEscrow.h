#ifndef AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_BN_REBOOT_ESCROW_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_BN_REBOOT_ESCROW_H_

#include <binder/IInterface.h>
#include <android/hardware/rebootescrow/IRebootEscrow.h>

namespace android {

namespace hardware {

namespace rebootescrow {

class BnRebootEscrow : public ::android::BnInterface<IRebootEscrow> {
public:
  explicit BnRebootEscrow();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnRebootEscrow

}  // namespace rebootescrow

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_BN_REBOOT_ESCROW_H_
