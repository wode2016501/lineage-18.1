#pragma once

#include <binder/IInterface.h>
#include <android/os/storaged/IStoragedPrivate.h>
#include <android/os/storaged/BnStoragedPrivate.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
namespace storaged {
class BnStoragedPrivate : public ::android::BnInterface<IStoragedPrivate> {
public:
  static constexpr uint32_t TRANSACTION_dumpUids = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_dumpPerfHistory = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnStoragedPrivate();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnStoragedPrivate

class IStoragedPrivateDelegator : public BnStoragedPrivate {
public:
  explicit IStoragedPrivateDelegator(const ::android::sp<IStoragedPrivate> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IStoragedPrivate> getImpl() { return _aidl_delegate; }
  ::android::binder::Status dumpUids(::std::vector<::android::os::storaged::UidInfo>* _aidl_return) override {
    return _aidl_delegate->dumpUids(_aidl_return);
  }
  ::android::binder::Status dumpPerfHistory(::std::vector<int32_t>* _aidl_return) override {
    return _aidl_delegate->dumpPerfHistory(_aidl_return);
  }
private:
  ::android::sp<IStoragedPrivate> _aidl_delegate;
};  // class IStoragedPrivateDelegator
}  // namespace storaged
}  // namespace os
}  // namespace android
