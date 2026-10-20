#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_DRIVER_MONITORING_DETECTION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_DRIVER_MONITORING_DETECTION_H_

#include <android/hardware/automotive/occupant_awareness/ConfidenceLevel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class DriverMonitoringDetection : public ::android::Parcelable {
public:
  inline bool operator!=(const DriverMonitoringDetection& rhs) const {
    return std::tie(confidenceScore, isLookingOnRoad, gazeDurationMillis)!=std::tie(rhs.confidenceScore, rhs.isLookingOnRoad, rhs.gazeDurationMillis);
  }
  inline bool operator<(const DriverMonitoringDetection& rhs) const {
    return std::tie(confidenceScore, isLookingOnRoad, gazeDurationMillis)<std::tie(rhs.confidenceScore, rhs.isLookingOnRoad, rhs.gazeDurationMillis);
  }
  inline bool operator<=(const DriverMonitoringDetection& rhs) const {
    return std::tie(confidenceScore, isLookingOnRoad, gazeDurationMillis)<=std::tie(rhs.confidenceScore, rhs.isLookingOnRoad, rhs.gazeDurationMillis);
  }
  inline bool operator==(const DriverMonitoringDetection& rhs) const {
    return std::tie(confidenceScore, isLookingOnRoad, gazeDurationMillis)==std::tie(rhs.confidenceScore, rhs.isLookingOnRoad, rhs.gazeDurationMillis);
  }
  inline bool operator>(const DriverMonitoringDetection& rhs) const {
    return std::tie(confidenceScore, isLookingOnRoad, gazeDurationMillis)>std::tie(rhs.confidenceScore, rhs.isLookingOnRoad, rhs.gazeDurationMillis);
  }
  inline bool operator>=(const DriverMonitoringDetection& rhs) const {
    return std::tie(confidenceScore, isLookingOnRoad, gazeDurationMillis)>=std::tie(rhs.confidenceScore, rhs.isLookingOnRoad, rhs.gazeDurationMillis);
  }
  ::android::hardware::automotive::occupant_awareness::ConfidenceLevel confidenceScore;
  bool isLookingOnRoad;
  int64_t gazeDurationMillis;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class DriverMonitoringDetection

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_DRIVER_MONITORING_DETECTION_H_
