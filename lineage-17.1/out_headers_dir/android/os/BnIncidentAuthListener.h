#pragma once

#include <binder/IInterface.h>
#include <android/os/IIncidentAuthListener.h>
#include <android/os/BnIncidentAuthListener.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
class BnIncidentAuthListener : public ::android::BnInterface<IIncidentAuthListener> {
public:
  static constexpr uint32_t TRANSACTION_onReportApproved = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onReportDenied = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnIncidentAuthListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIncidentAuthListener

class IIncidentAuthListenerDelegator : public BnIncidentAuthListener {
public:
  explicit IIncidentAuthListenerDelegator(const ::android::sp<IIncidentAuthListener> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IIncidentAuthListener> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onReportApproved() override {
    return _aidl_delegate->onReportApproved();
  }
  ::android::binder::Status onReportDenied() override {
    return _aidl_delegate->onReportDenied();
  }
private:
  ::android::sp<IIncidentAuthListener> _aidl_delegate;
};  // class IIncidentAuthListenerDelegator
}  // namespace os
}  // namespace android
