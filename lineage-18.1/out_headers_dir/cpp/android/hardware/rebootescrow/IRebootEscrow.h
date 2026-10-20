#ifndef AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_I_REBOOT_ESCROW_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_I_REBOOT_ESCROW_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace rebootescrow {

class IRebootEscrow : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(RebootEscrow)
  virtual ::android::binder::Status storeKey(const ::std::vector<uint8_t>& kek) = 0;
  virtual ::android::binder::Status retrieveKey(::std::vector<uint8_t>* _aidl_return) = 0;
};  // class IRebootEscrow

class IRebootEscrowDefault : public IRebootEscrow {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status storeKey(const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status retrieveKey(::std::vector<uint8_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IRebootEscrowDefault

}  // namespace rebootescrow

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_REBOOTESCROW_I_REBOOT_ESCROW_H_
