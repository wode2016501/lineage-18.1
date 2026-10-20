#ifndef AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_CLIENT_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_CLIENT_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

class ICameraClient : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CameraClient)
};  // class ICameraClient

class ICameraClientDefault : public ICameraClient {
public:
  ::android::IBinder* onAsBinder() override;
  
};

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_CLIENT_H_
