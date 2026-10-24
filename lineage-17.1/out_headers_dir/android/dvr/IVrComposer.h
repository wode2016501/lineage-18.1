#pragma once

#include <android/dvr/IVrComposerCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android::dvr {
class IVrComposerCallback;
}  // namespace android::dvr
namespace android {
namespace dvr {
class IVrComposerDelegator;

class IVrComposer : public ::android::IInterface {
public:
  typedef IVrComposerDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(VrComposer)
  static const ::android::String16& SERVICE_NAME();
  virtual ::android::binder::Status registerObserver(const ::android::sp<::android::dvr::IVrComposerCallback>& callback) = 0;
  virtual ::android::binder::Status clearObserver() = 0;
};  // class IVrComposer

class IVrComposerDefault : public IVrComposer {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status registerObserver(const ::android::sp<::android::dvr::IVrComposerCallback>& /*callback*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clearObserver() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVrComposerDefault
}  // namespace dvr
}  // namespace android
