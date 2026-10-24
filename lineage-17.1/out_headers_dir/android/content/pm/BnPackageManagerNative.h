#pragma once

#include <binder/IInterface.h>
#include <android/content/pm/IPackageManagerNative.h>
#include <android/content/pm/BnPackageManagerNative.h>
#include <binder/Delegate.h>


namespace android {
namespace content {
namespace pm {
class BnPackageManagerNative : public ::android::BnInterface<IPackageManagerNative> {
public:
  static constexpr uint32_t TRANSACTION_getNamesForUids = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getInstallerForPackage = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getVersionCodeForPackage = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_isAudioPlaybackCaptureAllowed = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getLocationFlags = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getTargetSdkVersionForPackage = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getModuleMetadataPackageName = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  explicit BnPackageManagerNative();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnPackageManagerNative

class IPackageManagerNativeDelegator : public BnPackageManagerNative {
public:
  explicit IPackageManagerNativeDelegator(const ::android::sp<IPackageManagerNative> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IPackageManagerNative> getImpl() { return _aidl_delegate; }
  ::android::binder::Status getNamesForUids(const ::std::vector<int32_t>& uids, ::std::vector<::std::string>* _aidl_return) override {
    return _aidl_delegate->getNamesForUids(uids, _aidl_return);
  }
  ::android::binder::Status getInstallerForPackage(const ::android::String16& packageName, ::std::string* _aidl_return) override {
    return _aidl_delegate->getInstallerForPackage(packageName, _aidl_return);
  }
  ::android::binder::Status getVersionCodeForPackage(const ::android::String16& packageName, int64_t* _aidl_return) override {
    return _aidl_delegate->getVersionCodeForPackage(packageName, _aidl_return);
  }
  ::android::binder::Status isAudioPlaybackCaptureAllowed(const ::std::vector<::std::string>& packageNames, ::std::vector<bool>* _aidl_return) override {
    return _aidl_delegate->isAudioPlaybackCaptureAllowed(packageNames, _aidl_return);
  }
  ::android::binder::Status getLocationFlags(const ::std::string& packageName, int32_t* _aidl_return) override {
    return _aidl_delegate->getLocationFlags(packageName, _aidl_return);
  }
  ::android::binder::Status getTargetSdkVersionForPackage(const ::android::String16& packageName, int32_t* _aidl_return) override {
    return _aidl_delegate->getTargetSdkVersionForPackage(packageName, _aidl_return);
  }
  ::android::binder::Status getModuleMetadataPackageName(::std::string* _aidl_return) override {
    return _aidl_delegate->getModuleMetadataPackageName(_aidl_return);
  }
private:
  ::android::sp<IPackageManagerNative> _aidl_delegate;
};  // class IPackageManagerNativeDelegator
}  // namespace pm
}  // namespace content
}  // namespace android
