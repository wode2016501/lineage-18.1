#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace os {
class IPermissionControllerDelegator;

class IPermissionController : public ::android::IInterface {
public:
  typedef IPermissionControllerDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(PermissionController)
  virtual ::android::binder::Status checkPermission(const ::android::String16& permission, int32_t pid, int32_t uid, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getPackagesForUid(int32_t uid, ::std::vector<::android::String16>* _aidl_return) = 0;
  virtual ::android::binder::Status isRuntimePermission(const ::android::String16& permission, bool* _aidl_return) = 0;
};  // class IPermissionController

class IPermissionControllerDefault : public IPermissionController {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status checkPermission(const ::android::String16& /*permission*/, int32_t /*pid*/, int32_t /*uid*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPackagesForUid(int32_t /*uid*/, ::std::vector<::android::String16>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isRuntimePermission(const ::android::String16& /*permission*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IPermissionControllerDefault
}  // namespace os
}  // namespace android
