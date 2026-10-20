#pragma once

#include "aidl/android/hardware/ISensorPrivacyManager.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BnSensorPrivacyManager : public ::ndk::BnCInterface<ISensorPrivacyManager> {
public:
  BnSensorPrivacyManager();
  virtual ~BnSensorPrivacyManager();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
