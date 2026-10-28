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
#include <aidl/android/content/pm/PackageChangeEvent.h>

namespace aidl {
namespace android {
namespace content {
namespace pm {
class IPackageChangeObserver : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IPackageChangeObserver();
  virtual ~IPackageChangeObserver();



  static std::shared_ptr<IPackageChangeObserver> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IPackageChangeObserver>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IPackageChangeObserver>* instance);
  static bool setDefaultImpl(std::shared_ptr<IPackageChangeObserver> impl);
  static const std::shared_ptr<IPackageChangeObserver>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onPackageChanged(const ::aidl::android::content::pm::PackageChangeEvent& in_event) = 0;
private:
  static std::shared_ptr<IPackageChangeObserver> default_impl;
};
class IPackageChangeObserverDefault : public IPackageChangeObserver {
public:
  ::ndk::ScopedAStatus onPackageChanged(const ::aidl::android::content::pm::PackageChangeEvent& in_event) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace pm
}  // namespace content
}  // namespace android
}  // namespace aidl
