#pragma once

#include "aidl/android/hardware/camera2/ICameraOfflineSession.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace camera2 {
class BpCameraOfflineSession : public ::ndk::BpCInterface<ICameraOfflineSession> {
public:
  BpCameraOfflineSession(const ::ndk::SpAIBinder& binder);
  virtual ~BpCameraOfflineSession();

  ::ndk::ScopedAStatus disconnect() override;
};
}  // namespace camera2
}  // namespace hardware
}  // namespace android
}  // namespace aidl
