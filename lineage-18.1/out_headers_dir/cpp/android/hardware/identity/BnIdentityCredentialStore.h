#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_IDENTITY_CREDENTIAL_STORE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_IDENTITY_CREDENTIAL_STORE_H_

#include <binder/IInterface.h>
#include <android/hardware/identity/IIdentityCredentialStore.h>

namespace android {

namespace hardware {

namespace identity {

class BnIdentityCredentialStore : public ::android::BnInterface<IIdentityCredentialStore> {
public:
  explicit BnIdentityCredentialStore();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIdentityCredentialStore

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_IDENTITY_CREDENTIAL_STORE_H_
