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
#include <aidl/android/content/pm/IPackageChangeObserver.h>

namespace aidl {
namespace android {
namespace content {
namespace pm {
class IPackageManagerNative : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IPackageManagerNative();
  virtual ~IPackageManagerNative();


  enum : int32_t {
    LOCATION_SYSTEM = 1,
    LOCATION_VENDOR = 2,
    LOCATION_PRODUCT = 4,
  };

  static std::shared_ptr<IPackageManagerNative> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IPackageManagerNative>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IPackageManagerNative>* instance);
  static bool setDefaultImpl(std::shared_ptr<IPackageManagerNative> impl);
  static const std::shared_ptr<IPackageManagerNative>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus getNamesForUids(const std::vector<int32_t>& in_uids, std::vector<std::string>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInstallerForPackage(const std::string& in_packageName, std::string* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getVersionCodeForPackage(const std::string& in_packageName, int64_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus isAudioPlaybackCaptureAllowed(const std::vector<std::string>& in_packageNames, std::vector<bool>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getLocationFlags(const std::string& in_packageName, int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getTargetSdkVersionForPackage(const std::string& in_packageName, int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getModuleMetadataPackageName(std::string* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getAllPackages(std::vector<std::string>* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus registerPackageChangeObserver(const std::shared_ptr<::aidl::android::content::pm::IPackageChangeObserver>& in_observer) = 0;
  virtual ::ndk::ScopedAStatus unregisterPackageChangeObserver(const std::shared_ptr<::aidl::android::content::pm::IPackageChangeObserver>& in_observer) = 0;
private:
  static std::shared_ptr<IPackageManagerNative> default_impl;
};
class IPackageManagerNativeDefault : public IPackageManagerNative {
public:
  ::ndk::ScopedAStatus getNamesForUids(const std::vector<int32_t>& in_uids, std::vector<std::string>* _aidl_return) override;
  ::ndk::ScopedAStatus getInstallerForPackage(const std::string& in_packageName, std::string* _aidl_return) override;
  ::ndk::ScopedAStatus getVersionCodeForPackage(const std::string& in_packageName, int64_t* _aidl_return) override;
  ::ndk::ScopedAStatus isAudioPlaybackCaptureAllowed(const std::vector<std::string>& in_packageNames, std::vector<bool>* _aidl_return) override;
  ::ndk::ScopedAStatus getLocationFlags(const std::string& in_packageName, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getTargetSdkVersionForPackage(const std::string& in_packageName, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getModuleMetadataPackageName(std::string* _aidl_return) override;
  ::ndk::ScopedAStatus getAllPackages(std::vector<std::string>* _aidl_return) override;
  ::ndk::ScopedAStatus registerPackageChangeObserver(const std::shared_ptr<::aidl::android::content::pm::IPackageChangeObserver>& in_observer) override;
  ::ndk::ScopedAStatus unregisterPackageChangeObserver(const std::shared_ptr<::aidl::android::content::pm::IPackageChangeObserver>& in_observer) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace pm
}  // namespace content
}  // namespace android
}  // namespace aidl
