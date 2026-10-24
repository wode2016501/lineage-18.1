#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {
namespace hardware {
class ICameraServiceListenerDelegator;

class ICameraServiceListener : public ::android::IInterface {
public:
  typedef ICameraServiceListenerDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(CameraServiceListener)
  enum : int32_t { STATUS_NOT_PRESENT = 0 };
  enum : int32_t { STATUS_PRESENT = 1 };
  enum : int32_t { STATUS_ENUMERATING = 2 };
  enum : int32_t { STATUS_NOT_AVAILABLE = -2 };
  enum : int32_t { STATUS_UNKNOWN = -1 };
  enum : int32_t { TORCH_STATUS_NOT_AVAILABLE = 0 };
  enum : int32_t { TORCH_STATUS_AVAILABLE_OFF = 1 };
  enum : int32_t { TORCH_STATUS_AVAILABLE_ON = 2 };
  enum : int32_t { TORCH_STATUS_UNKNOWN = -1 };
  virtual ::android::binder::Status onStatusChanged(int32_t status, const ::android::String16& cameraId) = 0;
  virtual ::android::binder::Status onTorchStatusChanged(int32_t status, const ::android::String16& cameraId) = 0;
  virtual ::android::binder::Status onCameraAccessPrioritiesChanged() = 0;
  virtual ::android::binder::Status onCameraOpened(const ::android::String16& cameraId, const ::android::String16& clientPackageId) = 0;
  virtual ::android::binder::Status onCameraClosed(const ::android::String16& cameraId) = 0;
};  // class ICameraServiceListener

class ICameraServiceListenerDefault : public ICameraServiceListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onStatusChanged(int32_t /*status*/, const ::android::String16& /*cameraId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onTorchStatusChanged(int32_t /*status*/, const ::android::String16& /*cameraId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onCameraAccessPrioritiesChanged() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onCameraOpened(const ::android::String16& /*cameraId*/, const ::android::String16& /*clientPackageId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onCameraClosed(const ::android::String16& /*cameraId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraServiceListenerDefault
}  // namespace hardware
}  // namespace android
