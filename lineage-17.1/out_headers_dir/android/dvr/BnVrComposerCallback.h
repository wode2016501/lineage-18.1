#pragma once

#include <binder/IInterface.h>
#include <android/dvr/IVrComposerCallback.h>
#include <android/dvr/BnVrComposerCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace dvr {
class BnVrComposerCallback : public ::android::BnInterface<IVrComposerCallback> {
public:
  static constexpr uint32_t TRANSACTION_onNewFrame = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnVrComposerCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVrComposerCallback

class IVrComposerCallbackDelegator : public BnVrComposerCallback {
public:
  explicit IVrComposerCallbackDelegator(const ::android::sp<IVrComposerCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IVrComposerCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onNewFrame(const ::android::dvr::ParcelableComposerFrame& frame, ::android::dvr::ParcelableUniqueFd* _aidl_return) override {
    return _aidl_delegate->onNewFrame(frame, _aidl_return);
  }
private:
  ::android::sp<IVrComposerCallback> _aidl_delegate;
};  // class IVrComposerCallbackDelegator
}  // namespace dvr
}  // namespace android
