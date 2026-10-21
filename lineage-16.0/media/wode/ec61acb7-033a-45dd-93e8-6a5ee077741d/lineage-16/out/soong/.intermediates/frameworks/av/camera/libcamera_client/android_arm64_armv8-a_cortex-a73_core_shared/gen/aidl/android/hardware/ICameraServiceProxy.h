#ifndef AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_SERVICE_PROXY_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_SERVICE_PROXY_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

class ICameraServiceProxy : public ::android::IInterface {
public:
DECLARE_META_INTERFACE(CameraServiceProxy)
enum  : int32_t {
  CAMERA_STATE_OPEN = 0,
  CAMERA_STATE_ACTIVE = 1,
  CAMERA_STATE_IDLE = 2,
  CAMERA_STATE_CLOSED = 3,
  CAMERA_FACING_BACK = 0,
  CAMERA_FACING_FRONT = 1,
  CAMERA_FACING_EXTERNAL = 2,
  CAMERA_API_LEVEL_1 = 1,
  CAMERA_API_LEVEL_2 = 2,
};
virtual ::android::binder::Status pingForUserUpdate() = 0;
virtual ::android::binder::Status notifyCameraState(const ::android::String16& cameraId, int32_t facing, int32_t newCameraState, const ::android::String16& clientName, int32_t apiLevel) = 0;
enum Call {
  PINGFORUSERUPDATE = ::android::IBinder::FIRST_CALL_TRANSACTION + 0,
  NOTIFYCAMERASTATE = ::android::IBinder::FIRST_CALL_TRANSACTION + 1,
};
};  // class ICameraServiceProxy

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_SERVICE_PROXY_H_
