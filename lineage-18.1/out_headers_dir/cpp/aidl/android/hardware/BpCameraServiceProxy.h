#pragma once

#include "aidl/android/hardware/ICameraServiceProxy.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BpCameraServiceProxy : public ::ndk::BpCInterface<ICameraServiceProxy> {
public:
  BpCameraServiceProxy(const ::ndk::SpAIBinder& binder);
  virtual ~BpCameraServiceProxy();

  ::ndk::ScopedAStatus pingForUserUpdate() override;
  ::ndk::ScopedAStatus notifyCameraState(const std::string& in_cameraId, int32_t in_facing, int32_t in_newCameraState, const std::string& in_clientName, int32_t in_apiLevel) override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
