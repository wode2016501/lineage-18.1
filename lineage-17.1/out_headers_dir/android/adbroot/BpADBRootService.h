#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/adbroot/IADBRootService.h>

namespace android {
namespace adbroot {
class BpADBRootService : public ::android::BpInterface<IADBRootService> {
public:
  explicit BpADBRootService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpADBRootService() = default;
  ::android::binder::Status setEnabled(bool enabled) override;
  ::android::binder::Status getEnabled(bool* _aidl_return) override;
};  // class BpADBRootService
}  // namespace adbroot
}  // namespace android
