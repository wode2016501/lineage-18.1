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
#include <aidl/android/hardware/ISensorPrivacyListener.h>

namespace aidl {
namespace android {
namespace hardware {
class ISensorPrivacyManager : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ISensorPrivacyManager();
  virtual ~ISensorPrivacyManager();



  static std::shared_ptr<ISensorPrivacyManager> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ISensorPrivacyManager>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ISensorPrivacyManager>* instance);
  static bool setDefaultImpl(std::shared_ptr<ISensorPrivacyManager> impl);
  static const std::shared_ptr<ISensorPrivacyManager>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus addSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& in_listener) = 0;
  virtual ::ndk::ScopedAStatus removeSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& in_listener) = 0;
  virtual ::ndk::ScopedAStatus isSensorPrivacyEnabled(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setSensorPrivacy(bool in_enable) = 0;
private:
  static std::shared_ptr<ISensorPrivacyManager> default_impl;
};
class ISensorPrivacyManagerDefault : public ISensorPrivacyManager {
public:
  ::ndk::ScopedAStatus addSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& in_listener) override;
  ::ndk::ScopedAStatus removeSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& in_listener) override;
  ::ndk::ScopedAStatus isSensorPrivacyEnabled(bool* _aidl_return) override;
  ::ndk::ScopedAStatus setSensorPrivacy(bool in_enable) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
