#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_IDENTITY_CREDENTIAL_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_IDENTITY_CREDENTIAL_H_

#include <binder/IInterface.h>
#include <android/hardware/identity/IIdentityCredential.h>

namespace android {

namespace hardware {

namespace identity {

class BnIdentityCredential : public ::android::BnInterface<IIdentityCredential> {
public:
  explicit BnIdentityCredential();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIdentityCredential

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_IDENTITY_CREDENTIAL_H_
