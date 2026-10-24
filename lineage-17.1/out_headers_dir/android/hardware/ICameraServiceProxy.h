#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {
namespace hardware {
class ICameraServiceProxyDelegator;

class ICameraServiceProxy : public ::android::IInterface {
public:
  typedef ICameraServiceProxyDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(CameraServiceProxy)
  enum : int32_t { CAMERA_STATE_OPEN = 0 };
  enum : int32_t { CAMERA_STATE_ACTIVE = 1 };
  enum : int32_t { CAMERA_STATE_IDLE = 2 };
  enum : int32_t { CAMERA_STATE_CLOSED = 3 };
  enum : int32_t { CAMERA_FACING_BACK = 0 };
  enum : int32_t { CAMERA_FACING_FRONT = 1 };
  enum : int32_t { CAMERA_FACING_EXTERNAL = 2 };
  enum : int32_t { CAMERA_API_LEVEL_1 = 1 };
  enum : int32_t { CAMERA_API_LEVEL_2 = 2 };
  virtual ::android::binder::Status pingForUserUpdate() = 0;
  virtual ::android::binder::Status notifyCameraState(const ::android::String16& cameraId, int32_t facing, int32_t newCameraState, const ::android::String16& clientName, int32_t apiLevel) = 0;
};  // class ICameraServiceProxy

class ICameraServiceProxyDefault : public ICameraServiceProxy {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status pingForUserUpdate() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status notifyCameraState(const ::android::String16& /*cameraId*/, int32_t /*facing*/, int32_t /*newCameraState*/, const ::android::String16& /*clientName*/, int32_t /*apiLevel*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraServiceProxyDefault
}  // namespace hardware
}  // namespace android
