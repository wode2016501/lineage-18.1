#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_PRESENCE_DETECTION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_PRESENCE_DETECTION_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class PresenceDetection : public ::android::Parcelable {
public:
  inline bool operator!=(const PresenceDetection& rhs) const {
    return std::tie(isOccupantDetected, detectionDurationMillis)!=std::tie(rhs.isOccupantDetected, rhs.detectionDurationMillis);
  }
  inline bool operator<(const PresenceDetection& rhs) const {
    return std::tie(isOccupantDetected, detectionDurationMillis)<std::tie(rhs.isOccupantDetected, rhs.detectionDurationMillis);
  }
  inline bool operator<=(const PresenceDetection& rhs) const {
    return std::tie(isOccupantDetected, detectionDurationMillis)<=std::tie(rhs.isOccupantDetected, rhs.detectionDurationMillis);
  }
  inline bool operator==(const PresenceDetection& rhs) const {
    return std::tie(isOccupantDetected, detectionDurationMillis)==std::tie(rhs.isOccupantDetected, rhs.detectionDurationMillis);
  }
  inline bool operator>(const PresenceDetection& rhs) const {
    return std::tie(isOccupantDetected, detectionDurationMillis)>std::tie(rhs.isOccupantDetected, rhs.detectionDurationMillis);
  }
  inline bool operator>=(const PresenceDetection& rhs) const {
    return std::tie(isOccupantDetected, detectionDurationMillis)>=std::tie(rhs.isOccupantDetected, rhs.detectionDurationMillis);
  }
  bool isOccupantDetected;
  int64_t detectionDurationMillis;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class PresenceDetection

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_PRESENCE_DETECTION_H_
