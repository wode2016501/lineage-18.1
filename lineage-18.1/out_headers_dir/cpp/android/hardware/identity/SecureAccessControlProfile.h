#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_SECURE_ACCESS_CONTROL_PROFILE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_SECURE_ACCESS_CONTROL_PROFILE_H_

#include <android/hardware/identity/Certificate.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class SecureAccessControlProfile : public ::android::Parcelable {
public:
  inline bool operator!=(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac)!=std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator<(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac)<std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator<=(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac)<=std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator==(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac)==std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator>(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac)>std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  inline bool operator>=(const SecureAccessControlProfile& rhs) const {
    return std::tie(id, readerCertificate, userAuthenticationRequired, timeoutMillis, secureUserId, mac)>=std::tie(rhs.id, rhs.readerCertificate, rhs.userAuthenticationRequired, rhs.timeoutMillis, rhs.secureUserId, rhs.mac);
  }
  int32_t id;
  ::android::hardware::identity::Certificate readerCertificate;
  bool userAuthenticationRequired;
  int64_t timeoutMillis;
  int64_t secureUserId;
  ::std::vector<uint8_t> mac;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class SecureAccessControlProfile

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_SECURE_ACCESS_CONTROL_PROFILE_H_
