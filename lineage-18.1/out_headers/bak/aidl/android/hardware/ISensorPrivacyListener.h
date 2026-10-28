#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace hardware {
class ISensorPrivacyListener : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ISensorPrivacyListener();
  virtual ~ISensorPrivacyListener();



  static std::shared_ptr<ISensorPrivacyListener> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ISensorPrivacyListener>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ISensorPrivacyListener>* instance);
  static bool setDefaultImpl(std::shared_ptr<ISensorPrivacyListener> impl);
  static const std::shared_ptr<ISensorPrivacyListener>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onSensorPrivacyChanged(bool in_enabled) = 0;
private:
  static std::shared_ptr<ISensorPrivacyListener> default_impl;
};
class ISensorPrivacyListenerDefault : public ISensorPrivacyListener {
public:
  ::ndk::ScopedAStatus onSensorPrivacyChanged(bool in_enabled) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
