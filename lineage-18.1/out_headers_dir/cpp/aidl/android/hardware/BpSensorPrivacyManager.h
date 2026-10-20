#pragma once

#include "aidl/android/hardware/ISensorPrivacyManager.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BpSensorPrivacyManager : public ::ndk::BpCInterface<ISensorPrivacyManager> {
public:
  BpSensorPrivacyManager(const ::ndk::SpAIBinder& binder);
  virtual ~BpSensorPrivacyManager();

  ::ndk::ScopedAStatus addSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& in_listener) override;
  ::ndk::ScopedAStatus removeSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& in_listener) override;
  ::ndk::ScopedAStatus isSensorPrivacyEnabled(bool* _aidl_return) override;
  ::ndk::ScopedAStatus setSensorPrivacy(bool in_enable) override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
