#ifndef AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_BP_REBOOT_ESCROW_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_BP_REBOOT_ESCROW_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/rebootescrow/IRebootEscrow.h>

namespace android {

namespace hardware {

namespace rebootescrow {

class BpRebootEscrow : public ::android::BpInterface<IRebootEscrow> {
public:
  explicit BpRebootEscrow(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpRebootEscrow() = default;
  ::android::binder::Status storeKey(const ::std::vector<uint8_t>& kek) override;
  ::android::binder::Status retrieveKey(::std::vector<uint8_t>* _aidl_return) override;
};  // class BpRebootEscrow

}  // namespace rebootescrow

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_BP_REBOOT_ESCROW_H_
