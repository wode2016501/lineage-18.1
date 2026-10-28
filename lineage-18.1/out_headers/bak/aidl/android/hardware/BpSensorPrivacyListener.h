#pragma once

#include "aidl/android/hardware/ISensorPrivacyListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BpSensorPrivacyListener : public ::ndk::BpCInterface<ISensorPrivacyListener> {
public:
  BpSensorPrivacyListener(const ::ndk::SpAIBinder& binder);
  virtual ~BpSensorPrivacyListener();

  ::ndk::ScopedAStatus onSensorPrivacyChanged(bool in_enabled) override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
