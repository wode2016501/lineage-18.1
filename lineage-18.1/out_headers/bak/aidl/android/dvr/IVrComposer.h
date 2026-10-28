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
#include <aidl/android/dvr/IVrComposerCallback.h>

namespace aidl {
namespace android {
namespace dvr {
class IVrComposer : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IVrComposer();
  virtual ~IVrComposer();

  static const char* SERVICE_NAME;


  static std::shared_ptr<IVrComposer> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IVrComposer>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IVrComposer>* instance);
  static bool setDefaultImpl(std::shared_ptr<IVrComposer> impl);
  static const std::shared_ptr<IVrComposer>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus registerObserver(const std::shared_ptr<::aidl::android::dvr::IVrComposerCallback>& in_callback) = 0;
  virtual ::ndk::ScopedAStatus clearObserver() = 0;
private:
  static std::shared_ptr<IVrComposer> default_impl;
};
class IVrComposerDefault : public IVrComposer {
public:
  ::ndk::ScopedAStatus registerObserver(const std::shared_ptr<::aidl::android::dvr::IVrComposerCallback>& in_callback) override;
  ::ndk::ScopedAStatus clearObserver() override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace dvr
}  // namespace android
}  // namespace aidl
