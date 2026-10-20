#pragma once

#include "aidl/android/hardware/light/ILights.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace light {
class BnLights : public ::ndk::BnCInterface<ILights> {
public:
  BnLights();
  virtual ~BnLights();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace light
}  // namespace hardware
}  // namespace android
}  // namespace aidl
