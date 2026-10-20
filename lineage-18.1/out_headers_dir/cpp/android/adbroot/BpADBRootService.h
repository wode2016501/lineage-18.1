#ifndef AIDL_GENERATED_ANDROID_ADBROOT_BP_A_D_B_ROOT_SERVICE_H_
#define AIDL_GENERATED_ANDROID_ADBROOT_BP_A_D_B_ROOT_SERVICE_H_

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

#endif  // AIDL_GENERATED_ANDROID_ADBROOT_BP_A_D_B_ROOT_SERVICE_H_
