#pragma once

#include "aidl/android/hardware/ICameraClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BnCameraClient : public ::ndk::BnCInterface<ICameraClient> {
public:
  BnCameraClient();
  virtual ~BnCameraClient();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
