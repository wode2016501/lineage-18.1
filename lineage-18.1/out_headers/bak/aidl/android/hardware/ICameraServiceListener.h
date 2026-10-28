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
class ICameraServiceListener : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ICameraServiceListener();
  virtual ~ICameraServiceListener();


  enum : int32_t {
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

  static std::shared_ptr<ICameraServiceListener> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ICameraServiceListener>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ICameraServiceListener>* instance);
  static bool setDefaultImpl(std::shared_ptr<ICameraServiceListener> impl);
  static const std::shared_ptr<ICameraServiceListener>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onStatusChanged(int32_t in_status, const std::string& in_cameraId) = 0;
  virtual ::ndk::ScopedAStatus onPhysicalCameraStatusChanged(int32_t in_status, const std::string& in_cameraId, const std::string& in_physicalCameraId) = 0;
  virtual ::ndk::ScopedAStatus onTorchStatusChanged(int32_t in_status, const std::string& in_cameraId) = 0;
  virtual ::ndk::ScopedAStatus onCameraAccessPrioritiesChanged() = 0;
  virtual ::ndk::ScopedAStatus onCameraOpened(const std::string& in_cameraId, const std::string& in_clientPackageId) = 0;
  virtual ::ndk::ScopedAStatus onCameraClosed(const std::string& in_cameraId) = 0;
private:
  static std::shared_ptr<ICameraServiceListener> default_impl;
};
class ICameraServiceListenerDefault : public ICameraServiceListener {
public:
  ::ndk::ScopedAStatus onStatusChanged(int32_t in_status, const std::string& in_cameraId) override;
  ::ndk::ScopedAStatus onPhysicalCameraStatusChanged(int32_t in_status, const std::string& in_cameraId, const std::string& in_physicalCameraId) override;
  ::ndk::ScopedAStatus onTorchStatusChanged(int32_t in_status, const std::string& in_cameraId) override;
  ::ndk::ScopedAStatus onCameraAccessPrioritiesChanged() override;
  ::ndk::ScopedAStatus onCameraOpened(const std::string& in_cameraId, const std::string& in_clientPackageId) override;
  ::ndk::ScopedAStatus onCameraClosed(const std::string& in_cameraId) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
