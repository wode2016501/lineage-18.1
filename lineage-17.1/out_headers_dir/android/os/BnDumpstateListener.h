#pragma once

#include <binder/IInterface.h>
#include <android/os/IDumpstateListener.h>
#include <android/os/BnDumpstateListener.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
class BnDumpstateListener : public ::android::BnInterface<IDumpstateListener> {
public:
  static constexpr uint32_t TRANSACTION_onProgress = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onError = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onFinished = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onProgressUpdated = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onMaxProgressUpdated = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onSectionComplete = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnDumpstateListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDumpstateListener

class IDumpstateListenerDelegator : public BnDumpstateListener {
public:
  explicit IDumpstateListenerDelegator(const ::android::sp<IDumpstateListener> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IDumpstateListener> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onProgress(int32_t progress) override {
    return _aidl_delegate->onProgress(progress);
  }
  ::android::binder::Status onError(int32_t errorCode) override {
    return _aidl_delegate->onError(errorCode);
  }
  ::android::binder::Status onFinished() override {
    return _aidl_delegate->onFinished();
  }
  ::android::binder::Status onProgressUpdated(int32_t progress) override {
    return _aidl_delegate->onProgressUpdated(progress);
  }
  ::android::binder::Status onMaxProgressUpdated(int32_t maxProgress) override {
    return _aidl_delegate->onMaxProgressUpdated(maxProgress);
  }
  ::android::binder::Status onSectionComplete(const ::std::string& name, int32_t status, int32_t size, int32_t durationMs) override {
    return _aidl_delegate->onSectionComplete(name, status, size, durationMs);
  }
private:
  ::android::sp<IDumpstateListener> _aidl_delegate;
};  // class IDumpstateListenerDelegator
}  // namespace os
}  // namespace android
