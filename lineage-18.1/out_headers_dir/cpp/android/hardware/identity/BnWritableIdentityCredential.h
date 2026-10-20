#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_WRITABLE_IDENTITY_CREDENTIAL_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_WRITABLE_IDENTITY_CREDENTIAL_H_

#include <binder/IInterface.h>
#include <android/hardware/identity/IWritableIdentityCredential.h>

namespace android {

namespace hardware {

namespace identity {

class BnWritableIdentityCredential : public ::android::BnInterface<IWritableIdentityCredential> {
public:
  explicit BnWritableIdentityCredential();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnWritableIdentityCredential

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BN_WRITABLE_IDENTITY_CREDENTIAL_H_
