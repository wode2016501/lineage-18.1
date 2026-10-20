#ifndef AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_CERTIFICATE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_CERTIFICATE_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace identity {

class Certificate : public ::android::Parcelable {
public:
  inline bool operator!=(const Certificate& rhs) const {
    return std::tie(encodedCertificate)!=std::tie(rhs.encodedCertificate);
  }
  inline bool operator<(const Certificate& rhs) const {
    return std::tie(encodedCertificate)<std::tie(rhs.encodedCertificate);
  }
  inline bool operator<=(const Certificate& rhs) const {
    return std::tie(encodedCertificate)<=std::tie(rhs.encodedCertificate);
  }
  inline bool operator==(const Certificate& rhs) const {
    return std::tie(encodedCertificate)==std::tie(rhs.encodedCertificate);
  }
  inline bool operator>(const Certificate& rhs) const {
    return std::tie(encodedCertificate)>std::tie(rhs.encodedCertificate);
  }
  inline bool operator>=(const Certificate& rhs) const {
    return std::tie(encodedCertificate)>=std::tie(rhs.encodedCertificate);
  }
  ::std::vector<uint8_t> encodedCertificate;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class Certificate

}  // namespace identity

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_IDENTITY_CERTIFICATE_H_
