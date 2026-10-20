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
class ICameraClient : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ICameraClient();
  virtual ~ICameraClient();



  static std::shared_ptr<ICameraClient> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ICameraClient>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ICameraClient>* instance);
  static bool setDefaultImpl(std::shared_ptr<ICameraClient> impl);
  static const std::shared_ptr<ICameraClient>& getDefaultImpl();
private:
  static std::shared_ptr<ICameraClient> default_impl;
};
class ICameraClientDefault : public ICameraClient {
public:
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
