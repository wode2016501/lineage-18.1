#pragma once

#include <binder/IInterface.h>
#include <android/os/IPermissionController.h>
#include <android/os/BnPermissionController.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
class BnPermissionController : public ::android::BnInterface<IPermissionController> {
public:
  static constexpr uint32_t TRANSACTION_checkPermission = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getPackagesForUid = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_isRuntimePermission = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnPermissionController();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnPermissionController

class IPermissionControllerDelegator : public BnPermissionController {
public:
  explicit IPermissionControllerDelegator(const ::android::sp<IPermissionController> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IPermissionController> getImpl() { return _aidl_delegate; }
  ::android::binder::Status checkPermission(const ::android::String16& permission, int32_t pid, int32_t uid, bool* _aidl_return) override {
    return _aidl_delegate->checkPermission(permission, pid, uid, _aidl_return);
  }
  ::android::binder::Status getPackagesForUid(int32_t uid, ::std::vector<::android::String16>* _aidl_return) override {
    return _aidl_delegate->getPackagesForUid(uid, _aidl_return);
  }
  ::android::binder::Status isRuntimePermission(const ::android::String16& permission, bool* _aidl_return) override {
    return _aidl_delegate->isRuntimePermission(permission, _aidl_return);
  }
private:
  ::android::sp<IPermissionController> _aidl_delegate;
};  // class IPermissionControllerDelegator
}  // namespace os
}  // namespace android
