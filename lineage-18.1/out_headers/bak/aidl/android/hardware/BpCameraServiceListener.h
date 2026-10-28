#pragma once

#include "aidl/android/hardware/ICameraServiceListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BpCameraServiceListener : public ::ndk::BpCInterface<ICameraServiceListener> {
public:
  BpCameraServiceListener(const ::ndk::SpAIBinder& binder);
  virtual ~BpCameraServiceListener();

  ::ndk::ScopedAStatus onStatusChanged(int32_t in_status, const std::string& in_cameraId) override;
  ::ndk::ScopedAStatus onPhysicalCameraStatusChanged(int32_t in_status, const std::string& in_cameraId, const std::string& in_physicalCameraId) override;
  ::ndk::ScopedAStatus onTorchStatusChanged(int32_t in_status, const std::string& in_cameraId) override;
  ::ndk::ScopedAStatus onCameraAccessPrioritiesChanged() override;
  ::ndk::ScopedAStatus onCameraOpened(const std::string& in_cameraId, const std::string& in_clientPackageId) override;
  ::ndk::ScopedAStatus onCameraClosed(const std::string& in_cameraId) override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
