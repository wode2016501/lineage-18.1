#pragma once

#include <binder/IInterface.h>
#include <android/dvr/IVrComposer.h>
#include <android/dvr/BnVrComposer.h>
#include <android/dvr/BnVrComposerCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace dvr {
class BnVrComposer : public ::android::BnInterface<IVrComposer> {
public:
  static constexpr uint32_t TRANSACTION_registerObserver = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_clearObserver = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnVrComposer();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVrComposer

class IVrComposerDelegator : public BnVrComposer {
public:
  explicit IVrComposerDelegator(const ::android::sp<IVrComposer> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IVrComposer> getImpl() { return _aidl_delegate; }
  ::android::binder::Status registerObserver(const ::android::sp<::android::dvr::IVrComposerCallback>& callback) override {
    ::android::sp<::android::dvr::IVrComposerCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::dvr::IVrComposerCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->registerObserver(_callback);
  }
  ::android::binder::Status clearObserver() override {
    return _aidl_delegate->clearObserver();
  }
private:
  ::android::sp<IVrComposer> _aidl_delegate;
};  // class IVrComposerDelegator
}  // namespace dvr
}  // namespace android
