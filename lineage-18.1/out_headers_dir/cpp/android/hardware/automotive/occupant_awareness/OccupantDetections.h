#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_DETECTIONS_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_DETECTIONS_H_

#include <android/hardware/automotive/occupant_awareness/OccupantDetection.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class OccupantDetections : public ::android::Parcelable {
public:
  inline bool operator!=(const OccupantDetections& rhs) const {
    return std::tie(timeStampMillis, detections)!=std::tie(rhs.timeStampMillis, rhs.detections);
  }
  inline bool operator<(const OccupantDetections& rhs) const {
    return std::tie(timeStampMillis, detections)<std::tie(rhs.timeStampMillis, rhs.detections);
  }
  inline bool operator<=(const OccupantDetections& rhs) const {
    return std::tie(timeStampMillis, detections)<=std::tie(rhs.timeStampMillis, rhs.detections);
  }
  inline bool operator==(const OccupantDetections& rhs) const {
    return std::tie(timeStampMillis, detections)==std::tie(rhs.timeStampMillis, rhs.detections);
  }
  inline bool operator>(const OccupantDetections& rhs) const {
    return std::tie(timeStampMillis, detections)>std::tie(rhs.timeStampMillis, rhs.detections);
  }
  inline bool operator>=(const OccupantDetections& rhs) const {
    return std::tie(timeStampMillis, detections)>=std::tie(rhs.timeStampMillis, rhs.detections);
  }
  int64_t timeStampMillis;
  ::std::vector<::android::hardware::automotive::occupant_awareness::OccupantDetection> detections;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class OccupantDetections

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_DETECTIONS_H_
