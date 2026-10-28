#pragma once

#include "aidl/android/hardware/camera2/ICameraOfflineSession.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace camera2 {
class BnCameraOfflineSession : public ::ndk::BnCInterface<ICameraOfflineSession> {
public:
  BnCameraOfflineSession();
  virtual ~BnCameraOfflineSession();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace camera2
}  // namespace hardware
}  // namespace android
}  // namespace aidl
