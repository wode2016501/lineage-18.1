#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
class ICameraServiceProxy : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ICameraServiceProxy();
  virtual ~ICameraServiceProxy();


  enum : int32_t {
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

  static std::shared_ptr<ICameraServiceProxy> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ICameraServiceProxy>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ICameraServiceProxy>* instance);
  static bool setDefaultImpl(std::shared_ptr<ICameraServiceProxy> impl);
  static const std::shared_ptr<ICameraServiceProxy>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus pingForUserUpdate() = 0;
  virtual ::ndk::ScopedAStatus notifyCameraState(const std::string& in_cameraId, int32_t in_facing, int32_t in_newCameraState, const std::string& in_clientName, int32_t in_apiLevel) = 0;
private:
  static std::shared_ptr<ICameraServiceProxy> default_impl;
};
class ICameraServiceProxyDefault : public ICameraServiceProxy {
public:
  ::ndk::ScopedAStatus pingForUserUpdate() override;
  ::ndk::ScopedAStatus notifyCameraState(const std::string& in_cameraId, int32_t in_facing, int32_t in_newCameraState, const std::string& in_clientName, int32_t in_apiLevel) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
