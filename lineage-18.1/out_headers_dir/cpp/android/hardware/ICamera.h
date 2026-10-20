#ifndef AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

class ICamera : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Camera)
  virtual ::android::binder::Status disconnect() = 0;
};  // class ICamera

class ICameraDefault : public ICamera {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status disconnect() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraDefault

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_H_
