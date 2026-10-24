#pragma once

#include <android/dvr/parcelable_composer_frame.h>
#include <android/dvr/parcelable_unique_fd.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {
namespace dvr {
class IVrComposerCallbackDelegator;

class IVrComposerCallback : public ::android::IInterface {
public:
  typedef IVrComposerCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(VrComposerCallback)
  virtual ::android::binder::Status onNewFrame(const ::android::dvr::ParcelableComposerFrame& frame, ::android::dvr::ParcelableUniqueFd* _aidl_return) = 0;
};  // class IVrComposerCallback

class IVrComposerCallbackDefault : public IVrComposerCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onNewFrame(const ::android::dvr::ParcelableComposerFrame& /*frame*/, ::android::dvr::ParcelableUniqueFd* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVrComposerCallbackDefault
}  // namespace dvr
}  // namespace android
