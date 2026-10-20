#pragma once

#include "aidl/android/hardware/ICamera.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BnCamera : public ::ndk::BnCInterface<ICamera> {
public:
  BnCamera();
  virtual ~BnCamera();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
