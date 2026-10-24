#pragma once

#include <binder/IInterface.h>
#include <android/os/IStoraged.h>
#include <android/os/BnStoraged.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
class BnStoraged : public ::android::BnInterface<IStoraged> {
public:
  static constexpr uint32_t TRANSACTION_onUserStarted = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onUserStopped = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getRecentPerf = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnStoraged();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnStoraged

class IStoragedDelegator : public BnStoraged {
public:
  explicit IStoragedDelegator(const ::android::sp<IStoraged> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IStoraged> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onUserStarted(int32_t userId) override {
    return _aidl_delegate->onUserStarted(userId);
  }
  ::android::binder::Status onUserStopped(int32_t userId) override {
    return _aidl_delegate->onUserStopped(userId);
  }
  ::android::binder::Status getRecentPerf(int32_t* _aidl_return) override {
    return _aidl_delegate->getRecentPerf(_aidl_return);
  }
private:
  ::android::sp<IStoraged> _aidl_delegate;
};  // class IStoragedDelegator
}  // namespace os
}  // namespace android
