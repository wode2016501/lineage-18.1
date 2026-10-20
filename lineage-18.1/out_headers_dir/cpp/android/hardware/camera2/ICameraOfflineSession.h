#ifndef AIDL_GENERATED_ANDROID_HARDWARE_CAMERA2_I_CAMERA_OFFLINE_SESSION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_CAMERA2_I_CAMERA_OFFLINE_SESSION_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace camera2 {

class ICameraOfflineSession : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CameraOfflineSession)
  virtual ::android::binder::Status disconnect() = 0;
};  // class ICameraOfflineSession

class ICameraOfflineSessionDefault : public ICameraOfflineSession {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status disconnect() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraOfflineSessionDefault

}  // namespace camera2

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_CAMERA2_I_CAMERA_OFFLINE_SESSION_H_
