#pragma once

#include <binder/IInterface.h>
#include <android/os/IIncidentCompanion.h>
#include <android/os/BnIncidentAuthListener.h>
#include <android/os/BnIncidentCompanion.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
class BnIncidentCompanion : public ::android::BnInterface<IIncidentCompanion> {
public:
  static constexpr uint32_t TRANSACTION_authorizeReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_cancelAuthorization = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_sendReportReadyBroadcast = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getPendingReports = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_approveReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_denyReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getIncidentReportList = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getIncidentReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_deleteIncidentReports = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_deleteAllIncidentReports = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  explicit BnIncidentCompanion();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIncidentCompanion

class IIncidentCompanionDelegator : public BnIncidentCompanion {
public:
  explicit IIncidentCompanionDelegator(const ::android::sp<IIncidentCompanion> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IIncidentCompanion> getImpl() { return _aidl_delegate; }
  ::android::binder::Status authorizeReport(int32_t callingUid, const ::android::String16& callingPackage, const ::android::String16& receiverClass, const ::android::String16& reportId, int32_t flags, const ::android::sp<::android::os::IIncidentAuthListener>& callback) override {
    ::android::sp<::android::os::IIncidentAuthListenerDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::os::IIncidentAuthListenerDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->authorizeReport(callingUid, callingPackage, receiverClass, reportId, flags, _callback);
  }
  ::android::binder::Status cancelAuthorization(const ::android::sp<::android::os::IIncidentAuthListener>& callback) override {
    ::android::sp<::android::os::IIncidentAuthListenerDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::os::IIncidentAuthListenerDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->cancelAuthorization(_callback);
  }
  ::android::binder::Status sendReportReadyBroadcast(const ::android::String16& pkg, const ::android::String16& cls) override {
    return _aidl_delegate->sendReportReadyBroadcast(pkg, cls);
  }
  ::android::binder::Status getPendingReports(::std::vector<::android::String16>* _aidl_return) override {
    return _aidl_delegate->getPendingReports(_aidl_return);
  }
  ::android::binder::Status approveReport(const ::android::String16& uri) override {
    return _aidl_delegate->approveReport(uri);
  }
  ::android::binder::Status denyReport(const ::android::String16& uri) override {
    return _aidl_delegate->denyReport(uri);
  }
  ::android::binder::Status getIncidentReportList(const ::android::String16& pkg, const ::android::String16& cls, ::std::vector<::android::String16>* _aidl_return) override {
    return _aidl_delegate->getIncidentReportList(pkg, cls, _aidl_return);
  }
  ::android::binder::Status getIncidentReport(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id, ::android::os::IncidentManager::IncidentReport* _aidl_return) override {
    return _aidl_delegate->getIncidentReport(pkg, cls, id, _aidl_return);
  }
  ::android::binder::Status deleteIncidentReports(const ::android::String16& pkg, const ::android::String16& cls, const ::android::String16& id) override {
    return _aidl_delegate->deleteIncidentReports(pkg, cls, id);
  }
  ::android::binder::Status deleteAllIncidentReports(const ::android::String16& pkg) override {
    return _aidl_delegate->deleteAllIncidentReports(pkg);
  }
private:
  ::android::sp<IIncidentCompanion> _aidl_delegate;
};  // class IIncidentCompanionDelegator
}  // namespace os
}  // namespace android
