#pragma once

#include "aidl/android/hardware/ISensorPrivacyListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BnSensorPrivacyListener : public ::ndk::BnCInterface<ISensorPrivacyListener> {
public:
  BnSensorPrivacyListener();
  virtual ~BnSensorPrivacyListener();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
