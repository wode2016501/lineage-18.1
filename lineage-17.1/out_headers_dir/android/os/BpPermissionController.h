#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IPermissionController.h>

namespace android {
namespace os {
class BpPermissionController : public ::android::BpInterface<IPermissionController> {
public:
  explicit BpPermissionController(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPermissionController() = default;
  ::android::binder::Status checkPermission(const ::android::String16& permission, int32_t pid, int32_t uid, bool* _aidl_return) override;
  ::android::binder::Status getPackagesForUid(int32_t uid, ::std::vector<::android::String16>* _aidl_return) override;
  ::android::binder::Status isRuntimePermission(const ::android::String16& permission, bool* _aidl_return) override;
};  // class BpPermissionController
}  // namespace os
}  // namespace android
