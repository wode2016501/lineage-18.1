#pragma once

#include "aidl/android/content/pm/IPackageManagerNative.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace content {
namespace pm {
class BpPackageManagerNative : public ::ndk::BpCInterface<IPackageManagerNative> {
public:
  BpPackageManagerNative(const ::ndk::SpAIBinder& binder);
  virtual ~BpPackageManagerNative();

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
};
}  // namespace pm
}  // namespace content
}  // namespace android
}  // namespace aidl
