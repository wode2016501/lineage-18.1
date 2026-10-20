#ifndef AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_VERIFICATION_TOKEN_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_VERIFICATION_TOKEN_H_

#include <android/hardware/keymaster/SecurityLevel.h>
#include <android/hardware/keymaster/Timestamp.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace keymaster {

class VerificationToken : public ::android::Parcelable {
public:
  inline bool operator!=(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac)!=std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator<(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac)<std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator<=(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac)<=std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator==(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac)==std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator>(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac)>std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  inline bool operator>=(const VerificationToken& rhs) const {
    return std::tie(challenge, timestamp, securityLevel, mac)>=std::tie(rhs.challenge, rhs.timestamp, rhs.securityLevel, rhs.mac);
  }
  int64_t challenge;
  ::android::hardware::keymaster::Timestamp timestamp;
  ::android::hardware::keymaster::SecurityLevel securityLevel;
  ::std::vector<uint8_t> mac;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class VerificationToken

}  // namespace keymaster

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_VERIFICATION_TOKEN_H_
