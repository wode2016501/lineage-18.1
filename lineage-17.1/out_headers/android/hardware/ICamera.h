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
  ::android::IBinder* onAsBinder() override;
  ::android::binder::Status disconnect() override;

};

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_H_
