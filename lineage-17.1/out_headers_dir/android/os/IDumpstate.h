#pragma once

#include <android-base/unique_fd.h>
#include <android/os/IDumpstateListener.h>
#include <android/os/IDumpstateToken.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>

namespace android::os {
class IDumpstateListener;
class IDumpstateToken;
}  // namespace android::os
namespace android {
namespace os {
class IDumpstateDelegator;

class IDumpstate : public ::android::IInterface {
public:
  typedef IDumpstateDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(Dumpstate)
  enum : int32_t { BUGREPORT_MODE_FULL = 0 };
  enum : int32_t { BUGREPORT_MODE_INTERACTIVE = 1 };
  enum : int32_t { BUGREPORT_MODE_REMOTE = 2 };
  enum : int32_t { BUGREPORT_MODE_WEAR = 3 };
  enum : int32_t { BUGREPORT_MODE_TELEPHONY = 4 };
  enum : int32_t { BUGREPORT_MODE_WIFI = 5 };
  enum : int32_t { BUGREPORT_MODE_DEFAULT = 6 };
  virtual ::android::binder::Status setListener(const ::std::string& name, const ::android::sp<::android::os::IDumpstateListener>& listener, bool getSectionDetails, ::android::sp<::android::os::IDumpstateToken>* _aidl_return) = 0;
  virtual ::android::binder::Status startBugreport(int32_t callingUid, const ::std::string& callingPackage, ::android::base::unique_fd bugreportFd, ::android::base::unique_fd screenshotFd, int32_t bugreportMode, const ::android::sp<::android::os::IDumpstateListener>& listener) = 0;
  virtual ::android::binder::Status cancelBugreport() = 0;
};  // class IDumpstate

class IDumpstateDefault : public IDumpstate {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setListener(const ::std::string& /*name*/, const ::android::sp<::android::os::IDumpstateListener>& /*listener*/, bool /*getSectionDetails*/, ::android::sp<::android::os::IDumpstateToken>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startBugreport(int32_t /*callingUid*/, const ::std::string& /*callingPackage*/, ::android::base::unique_fd /*bugreportFd*/, ::android::base::unique_fd /*screenshotFd*/, int32_t /*bugreportMode*/, const ::android::sp<::android::os::IDumpstateListener>& /*listener*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancelBugreport() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IDumpstateDefault
}  // namespace os
}  // namespace android
