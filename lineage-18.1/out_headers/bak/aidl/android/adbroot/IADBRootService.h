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
namespace adbroot {
class IADBRootService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IADBRootService();
  virtual ~IADBRootService();



  static std::shared_ptr<IADBRootService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IADBRootService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IADBRootService>* instance);
  static bool setDefaultImpl(std::shared_ptr<IADBRootService> impl);
  static const std::shared_ptr<IADBRootService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus setEnabled(bool in_enabled) = 0;
  virtual ::ndk::ScopedAStatus getEnabled(bool* _aidl_return) = 0;
private:
  static std::shared_ptr<IADBRootService> default_impl;
};
class IADBRootServiceDefault : public IADBRootService {
public:
  ::ndk::ScopedAStatus setEnabled(bool in_enabled) override;
  ::ndk::ScopedAStatus getEnabled(bool* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace adbroot
}  // namespace android
}  // namespace aidl
