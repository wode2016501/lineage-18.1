#ifndef AIDL_GENERATED_ANDROID_ADBROOT_BN_A_D_B_ROOT_SERVICE_H_
#define AIDL_GENERATED_ANDROID_ADBROOT_BN_A_D_B_ROOT_SERVICE_H_

#include <binder/IInterface.h>
#include <android/adbroot/IADBRootService.h>

namespace android {

namespace adbroot {

class BnADBRootService : public ::android::BnInterface<IADBRootService> {
public:
  explicit BnADBRootService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnADBRootService

}  // namespace adbroot

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_ADBROOT_BN_A_D_B_ROOT_SERVICE_H_
