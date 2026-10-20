#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BP_IDENTITY_CREDENTIAL_STORE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BP_IDENTITY_CREDENTIAL_STORE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/identity/IIdentityCredentialStore.h>

namespace android {

namespace hardware {

namespace identity {

class BpIdentityCredentialStore : public ::android::BpInterface<IIdentityCredentialStore> {
public:
  explicit BpIdentityCredentialStore(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIdentityCredentialStore() = default;
  ::android::binder::Status getHardwareInformation(::android::hardware::identity::HardwareInformation* _aidl_return) override;
  ::android::binder::Status createCredential(const ::std::string& docType, bool testCredential, ::android::sp<::android::hardware::identity::IWritableIdentityCredential>* _aidl_return) override;
  ::android::binder::Status getCredential(::android::hardware::identity::CipherSuite cipherSuite, const ::std::vector<uint8_t>& credentialData, ::android::sp<::android::hardware::identity::IIdentityCredential>* _aidl_return) override;
};  // class BpIdentityCredentialStore

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BP_IDENTITY_CREDENTIAL_STORE_H_
