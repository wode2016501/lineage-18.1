#ifndef AIDL_GENERATED_ANDROID_CONTENT_PM_I_PACKAGE_MANAGER_NATIVE_H_
#define AIDL_GENERATED_ANDROID_CONTENT_PM_I_PACKAGE_MANAGER_NATIVE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace content {

namespace pm {

class IPackageManagerNative : public ::android::IInterface {
public:
DECLARE_META_INTERFACE(PackageManagerNative)
virtual ::android::binder::Status getNamesForUids(const ::std::vector<int32_t>& uids, ::std::vector<::std::string>* _aidl_return) = 0;
virtual ::android::binder::Status getInstallerForPackage(const ::android::String16& packageName, ::std::string* _aidl_return) = 0;
virtual ::android::binder::Status getVersionCodeForPackage(const ::android::String16& packageName, int64_t* _aidl_return) = 0;
enum Call {
  GETNAMESFORUIDS = ::android::IBinder::FIRST_CALL_TRANSACTION + 0,
  GETINSTALLERFORPACKAGE = ::android::IBinder::FIRST_CALL_TRANSACTION + 1,
  GETVERSIONCODEFORPACKAGE = ::android::IBinder::FIRST_CALL_TRANSACTION + 2,
};
};  // class IPackageManagerNative

}  // namespace pm

}  // namespace content

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_CONTENT_PM_I_PACKAGE_MANAGER_NATIVE_H_
