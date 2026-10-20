#pragma once

#include "aidl/android/hardware/ICameraServiceListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BnCameraServiceListener : public ::ndk::BnCInterface<ICameraServiceListener> {
public:
  BnCameraServiceListener();
  virtual ~BnCameraServiceListener();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
