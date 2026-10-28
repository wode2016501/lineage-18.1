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
namespace camera2 {
class ICameraOfflineSession : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ICameraOfflineSession();
  virtual ~ICameraOfflineSession();



  static std::shared_ptr<ICameraOfflineSession> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ICameraOfflineSession>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ICameraOfflineSession>* instance);
  static bool setDefaultImpl(std::shared_ptr<ICameraOfflineSession> impl);
  static const std::shared_ptr<ICameraOfflineSession>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus disconnect() = 0;
private:
  static std::shared_ptr<ICameraOfflineSession> default_impl;
};
class ICameraOfflineSessionDefault : public ICameraOfflineSession {
public:
  ::ndk::ScopedAStatus disconnect() override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace camera2
}  // namespace hardware
}  // namespace android
}  // namespace aidl
