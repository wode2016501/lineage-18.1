#ifndef AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_TIMESTAMP_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_TIMESTAMP_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace keymaster {

class Timestamp : public ::android::Parcelable {
public:
  inline bool operator!=(const Timestamp& rhs) const {
    return std::tie(milliSeconds)!=std::tie(rhs.milliSeconds);
  }
  inline bool operator<(const Timestamp& rhs) const {
    return std::tie(milliSeconds)<std::tie(rhs.milliSeconds);
  }
  inline bool operator<=(const Timestamp& rhs) const {
    return std::tie(milliSeconds)<=std::tie(rhs.milliSeconds);
  }
  inline bool operator==(const Timestamp& rhs) const {
    return std::tie(milliSeconds)==std::tie(rhs.milliSeconds);
  }
  inline bool operator>(const Timestamp& rhs) const {
    return std::tie(milliSeconds)>std::tie(rhs.milliSeconds);
  }
  inline bool operator>=(const Timestamp& rhs) const {
    return std::tie(milliSeconds)>=std::tie(rhs.milliSeconds);
  }
  int64_t milliSeconds;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class Timestamp

}  // namespace keymaster

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_KEYMASTER_TIMESTAMP_H_
