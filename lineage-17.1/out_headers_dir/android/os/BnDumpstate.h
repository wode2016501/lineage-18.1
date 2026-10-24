#pragma once

#include <binder/IInterface.h>
#include <android/os/IDumpstate.h>
#include <android/os/BnDumpstate.h>
#include <android/os/BnDumpstateListener.h>
#include <android/os/BnDumpstateToken.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
class BnDumpstate : public ::android::BnInterface<IDumpstate> {
public:
  static constexpr uint32_t TRANSACTION_setListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_startBugreport = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_cancelBugreport = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnDumpstate();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDumpstate

class IDumpstateDelegator : public BnDumpstate {
public:
  explicit IDumpstateDelegator(const ::android::sp<IDumpstate> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IDumpstate> getImpl() { return _aidl_delegate; }
  ::android::binder::Status setListener(const ::std::string& name, const ::android::sp<::android::os::IDumpstateListener>& listener, bool getSectionDetails, ::android::sp<::android::os::IDumpstateToken>* _aidl_return) override {
    ::android::sp<::android::os::IDumpstateListenerDelegator> _listener;
    if (listener) {
      _listener = ::android::sp<::android::os::IDumpstateListenerDelegator>::cast(delegate(listener));
    }
    auto _status = _aidl_delegate->setListener(name, _listener, getSectionDetails, _aidl_return);
    if (*_aidl_return) {
      *_aidl_return = ::android::sp<::android::os::IDumpstateTokenDelegator>::cast(delegate(*_aidl_return));
    }
    return _status;
  }
  ::android::binder::Status startBugreport(int32_t callingUid, const ::std::string& callingPackage, ::android::base::unique_fd bugreportFd, ::android::base::unique_fd screenshotFd, int32_t bugreportMode, const ::android::sp<::android::os::IDumpstateListener>& listener) override {
    ::android::sp<::android::os::IDumpstateListenerDelegator> _listener;
    if (listener) {
      _listener = ::android::sp<::android::os::IDumpstateListenerDelegator>::cast(delegate(listener));
    }
    return _aidl_delegate->startBugreport(callingUid, callingPackage, std::move(bugreportFd), std::move(screenshotFd), bugreportMode, _listener);
  }
  ::android::binder::Status cancelBugreport() override {
    return _aidl_delegate->cancelBugreport();
  }
private:
  ::android::sp<IDumpstate> _aidl_delegate;
};  // class IDumpstateDelegator
}  // namespace os
}  // namespace android
