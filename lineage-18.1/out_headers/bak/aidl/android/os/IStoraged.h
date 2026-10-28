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
namespace os {
class IStoraged : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IStoraged();
  virtual ~IStoraged();



  static std::shared_ptr<IStoraged> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IStoraged>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IStoraged>* instance);
  static bool setDefaultImpl(std::shared_ptr<IStoraged> impl);
  static const std::shared_ptr<IStoraged>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onUserStarted(int32_t in_userId) = 0;
  virtual ::ndk::ScopedAStatus onUserStopped(int32_t in_userId) = 0;
  virtual ::ndk::ScopedAStatus getRecentPerf(int32_t* _aidl_return) = 0;
private:
  static std::shared_ptr<IStoraged> default_impl;
};
class IStoragedDefault : public IStoraged {
public:
  ::ndk::ScopedAStatus onUserStarted(int32_t in_userId) override;
  ::ndk::ScopedAStatus onUserStopped(int32_t in_userId) override;
  ::ndk::ScopedAStatus getRecentPerf(int32_t* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
