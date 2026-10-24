#pragma once

#include <binder/IInterface.h>
#include <android/adbroot/IADBRootService.h>
#include <android/adbroot/BnADBRootService.h>
#include <binder/Delegate.h>


namespace android {
namespace adbroot {
class BnADBRootService : public ::android::BnInterface<IADBRootService> {
public:
  static constexpr uint32_t TRANSACTION_setEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnADBRootService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnADBRootService

class IADBRootServiceDelegator : public BnADBRootService {
public:
  explicit IADBRootServiceDelegator(const ::android::sp<IADBRootService> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IADBRootService> getImpl() { return _aidl_delegate; }
  ::android::binder::Status setEnabled(bool enabled) override {
    return _aidl_delegate->setEnabled(enabled);
  }
  ::android::binder::Status getEnabled(bool* _aidl_return) override {
    return _aidl_delegate->getEnabled(_aidl_return);
  }
private:
  ::android::sp<IADBRootService> _aidl_delegate;
};  // class IADBRootServiceDelegator
}  // namespace adbroot
}  // namespace android
