#ifndef AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_HARDWARE_AUTH_TOKEN_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_HARDWARE_AUTH_TOKEN_H_

#include <android/hardware/keymaster/HardwareAuthenticatorType.h>
#include <android/hardware/keymaster/Timestamp.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace keymaster {

class HardwareAuthToken : public ::android::Parcelable {
public:
  inline bool operator!=(const HardwareAuthToken& rhs) const {
    return std::tie(challenge, userId, authenticatorId, authenticatorType, timestamp, mac)!=std::tie(rhs.challenge, rhs.userId, rhs.authenticatorId, rhs.authenticatorType, rhs.timestamp, rhs.mac);
  }
  inline bool operator<(const HardwareAuthToken& rhs) const {
    return std::tie(challenge, userId, authenticatorId, authenticatorType, timestamp, mac)<std::tie(rhs.challenge, rhs.userId, rhs.authenticatorId, rhs.authenticatorType, rhs.timestamp, rhs.mac);
  }
  inline bool operator<=(const HardwareAuthToken& rhs) const {
    return std::tie(challenge, userId, authenticatorId, authenticatorType, timestamp, mac)<=std::tie(rhs.challenge, rhs.userId, rhs.authenticatorId, rhs.authenticatorType, rhs.timestamp, rhs.mac);
  }
  inline bool operator==(const HardwareAuthToken& rhs) const {
    return std::tie(challenge, userId, authenticatorId, authenticatorType, timestamp, mac)==std::tie(rhs.challenge, rhs.userId, rhs.authenticatorId, rhs.authenticatorType, rhs.timestamp, rhs.mac);
  }
  inline bool operator>(const HardwareAuthToken& rhs) const {
    return std::tie(challenge, userId, authenticatorId, authenticatorType, timestamp, mac)>std::tie(rhs.challenge, rhs.userId, rhs.authenticatorId, rhs.authenticatorType, rhs.timestamp, rhs.mac);
  }
  inline bool operator>=(const HardwareAuthToken& rhs) const {
    return std::tie(challenge, userId, authenticatorId, authenticatorType, timestamp, mac)>=std::tie(rhs.challenge, rhs.userId, rhs.authenticatorId, rhs.authenticatorType, rhs.timestamp, rhs.mac);
  }
  int64_t challenge;
  int64_t userId;
  int64_t authenticatorId;
  ::android::hardware::keymaster::HardwareAuthenticatorType authenticatorType;
  ::android::hardware::keymaster::Timestamp timestamp;
  ::std::vector<uint8_t> mac;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class HardwareAuthToken

}  // namespace keymaster

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_HARDWARE_AUTH_TOKEN_H_
