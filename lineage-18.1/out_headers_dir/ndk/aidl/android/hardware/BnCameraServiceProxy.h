#pragma once

#include "aidl/android/hardware/ICameraServiceProxy.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BnCameraServiceProxy : public ::ndk::BnCInterface<ICameraServiceProxy> {
public:
  BnCameraServiceProxy();
  virtual ~BnCameraServiceProxy();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
