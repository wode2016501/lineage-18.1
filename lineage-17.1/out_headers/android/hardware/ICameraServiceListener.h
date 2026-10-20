#ifndef AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_SERVICE_LISTENER_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_SERVICE_LISTENER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

class ICameraServiceListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CameraServiceListener)
  enum  : int32_t {
    STATUS_NOT_PRESENT = 0,
    STATUS_PRESENT = 1,
    STATUS_ENUMERATING = 2,
    STATUS_NOT_AVAILABLE = -2,
    STATUS_UNKNOWN = -1,
    TORCH_STATUS_NOT_AVAILABLE = 0,
    TORCH_STATUS_AVAILABLE_OFF = 1,
    TORCH_STATUS_AVAILABLE_ON = 2,
    TORCH_STATUS_UNKNOWN = -1,
  };
  virtual ::android::binder::Status onStatusChanged(int32_t status, const ::android::String16& cameraId) = 0;
  virtual ::android::binder::Status onTorchStatusChanged(int32_t status, const ::android::String16& cameraId) = 0;
  virtual ::android::binder::Status onCameraAccessPrioritiesChanged() = 0;
  virtual ::android::binder::Status onCameraOpened(const ::android::String16& cameraId, const ::android::String16& clientPackageId) = 0;
  virtual ::android::binder::Status onCameraClosed(const ::android::String16& cameraId) = 0;
};  // class ICameraServiceListener

class ICameraServiceListenerDefault : public ICameraServiceListener {
public:
  ::android::IBinder* onAsBinder() override;
  ::android::binder::Status onStatusChanged(int32_t status, const ::android::String16& cameraId) override;
  ::android::binder::Status onTorchStatusChanged(int32_t status, const ::android::String16& cameraId) override;
  ::android::binder::Status onCameraAccessPrioritiesChanged() override;
  ::android::binder::Status onCameraOpened(const ::android::String16& cameraId, const ::android::String16& clientPackageId) override;
  ::android::binder::Status onCameraClosed(const ::android::String16& cameraId) override;

};

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_I_CAMERA_SERVICE_LISTENER_H_
