#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {
namespace adbroot {
class IADBRootServiceDelegator;

class IADBRootService : public ::android::IInterface {
public:
  typedef IADBRootServiceDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(ADBRootService)
  virtual ::android::binder::Status setEnabled(bool enabled) = 0;
  virtual ::android::binder::Status getEnabled(bool* _aidl_return) = 0;
};  // class IADBRootService

class IADBRootServiceDefault : public IADBRootService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setEnabled(bool /*enabled*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getEnabled(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IADBRootServiceDefault
}  // namespace adbroot
}  // namespace android
