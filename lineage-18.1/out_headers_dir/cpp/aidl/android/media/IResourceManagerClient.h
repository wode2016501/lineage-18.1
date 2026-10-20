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
namespace media {
class IResourceManagerClient : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IResourceManagerClient();
  virtual ~IResourceManagerClient();



  static std::shared_ptr<IResourceManagerClient> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IResourceManagerClient>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IResourceManagerClient>* instance);
  static bool setDefaultImpl(std::shared_ptr<IResourceManagerClient> impl);
  static const std::shared_ptr<IResourceManagerClient>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus reclaimResource(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getName(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IResourceManagerClient> default_impl;
};
class IResourceManagerClientDefault : public IResourceManagerClient {
public:
  ::ndk::ScopedAStatus reclaimResource(bool* _aidl_return) override;
  ::ndk::ScopedAStatus getName(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
