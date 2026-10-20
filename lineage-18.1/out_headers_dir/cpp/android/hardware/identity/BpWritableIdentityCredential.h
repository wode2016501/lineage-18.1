#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BP_WRITABLE_IDENTITY_CREDENTIAL_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BP_WRITABLE_IDENTITY_CREDENTIAL_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/identity/IWritableIdentityCredential.h>

namespace android {

namespace hardware {

namespace identity {

class BpWritableIdentityCredential : public ::android::BpInterface<IWritableIdentityCredential> {
public:
  explicit BpWritableIdentityCredential(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpWritableIdentityCredential() = default;
  ::android::binder::Status getAttestationCertificate(const ::std::vector<uint8_t>& attestationApplicationId, const ::std::vector<uint8_t>& attestationChallenge, ::std::vector<::android::hardware::identity::Certificate>* _aidl_return) override;
  ::android::binder::Status startPersonalization(int32_t accessControlProfileCount, const ::std::vector<int32_t>& entryCounts) override;
  ::android::binder::Status addAccessControlProfile(int32_t id, const ::android::hardware::identity::Certificate& readerCertificate, bool userAuthenticationRequired, int64_t timeoutMillis, int64_t secureUserId, ::android::hardware::identity::SecureAccessControlProfile* _aidl_return) override;
  ::android::binder::Status beginAddEntry(const ::std::vector<int32_t>& accessControlProfileIds, const ::std::string& nameSpace, const ::std::string& name, int32_t entrySize) override;
  ::android::binder::Status addEntryValue(const ::std::vector<uint8_t>& content, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status finishAddingEntries(::std::vector<uint8_t>* credentialData, ::std::vector<uint8_t>* proofOfProvisioningSignature) override;
  ::android::binder::Status setExpectedProofOfProvisioningSize(int32_t expectedProofOfProvisioningSize) override;
};  // class BpWritableIdentityCredential

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_BP_WRITABLE_IDENTITY_CREDENTIAL_H_
