#ifndef AIDL_GENERATED_ANDROID_DVR_I_VR_COMPOSER_H_
#define AIDL_GENERATED_ANDROID_DVR_I_VR_COMPOSER_H_

#include <android/dvr/IVrComposerCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace dvr {

class IVrComposer : public ::android::IInterface {
public:
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
  ::android::binder::Status registerObserver(const ::android::sp<::android::dvr::IVrComposerCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clearObserver() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVrComposerDefault

}  // namespace dvr

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_DVR_I_VR_COMPOSER_H_
