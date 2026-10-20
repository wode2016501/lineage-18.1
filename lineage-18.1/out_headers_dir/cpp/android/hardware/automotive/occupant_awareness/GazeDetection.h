#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_GAZE_DETECTION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_GAZE_DETECTION_H_

#include <android/hardware/automotive/occupant_awareness/ConfidenceLevel.h>
#include <android/hardware/automotive/occupant_awareness/VehicleRegion.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class GazeDetection : public ::android::Parcelable {
public:
  inline bool operator!=(const GazeDetection& rhs) const {
    return std::tie(gazeConfidence, headPosition, headAngleUnitVector, gazeAngleUnitVector, gazeTarget, customGazeTarget, timeOnTargetMillis)!=std::tie(rhs.gazeConfidence, rhs.headPosition, rhs.headAngleUnitVector, rhs.gazeAngleUnitVector, rhs.gazeTarget, rhs.customGazeTarget, rhs.timeOnTargetMillis);
  }
  inline bool operator<(const GazeDetection& rhs) const {
    return std::tie(gazeConfidence, headPosition, headAngleUnitVector, gazeAngleUnitVector, gazeTarget, customGazeTarget, timeOnTargetMillis)<std::tie(rhs.gazeConfidence, rhs.headPosition, rhs.headAngleUnitVector, rhs.gazeAngleUnitVector, rhs.gazeTarget, rhs.customGazeTarget, rhs.timeOnTargetMillis);
  }
  inline bool operator<=(const GazeDetection& rhs) const {
    return std::tie(gazeConfidence, headPosition, headAngleUnitVector, gazeAngleUnitVector, gazeTarget, customGazeTarget, timeOnTargetMillis)<=std::tie(rhs.gazeConfidence, rhs.headPosition, rhs.headAngleUnitVector, rhs.gazeAngleUnitVector, rhs.gazeTarget, rhs.customGazeTarget, rhs.timeOnTargetMillis);
  }
  inline bool operator==(const GazeDetection& rhs) const {
    return std::tie(gazeConfidence, headPosition, headAngleUnitVector, gazeAngleUnitVector, gazeTarget, customGazeTarget, timeOnTargetMillis)==std::tie(rhs.gazeConfidence, rhs.headPosition, rhs.headAngleUnitVector, rhs.gazeAngleUnitVector, rhs.gazeTarget, rhs.customGazeTarget, rhs.timeOnTargetMillis);
  }
  inline bool operator>(const GazeDetection& rhs) const {
    return std::tie(gazeConfidence, headPosition, headAngleUnitVector, gazeAngleUnitVector, gazeTarget, customGazeTarget, timeOnTargetMillis)>std::tie(rhs.gazeConfidence, rhs.headPosition, rhs.headAngleUnitVector, rhs.gazeAngleUnitVector, rhs.gazeTarget, rhs.customGazeTarget, rhs.timeOnTargetMillis);
  }
  inline bool operator>=(const GazeDetection& rhs) const {
    return std::tie(gazeConfidence, headPosition, headAngleUnitVector, gazeAngleUnitVector, gazeTarget, customGazeTarget, timeOnTargetMillis)>=std::tie(rhs.gazeConfidence, rhs.headPosition, rhs.headAngleUnitVector, rhs.gazeAngleUnitVector, rhs.gazeTarget, rhs.customGazeTarget, rhs.timeOnTargetMillis);
  }
  ::android::hardware::automotive::occupant_awareness::ConfidenceLevel gazeConfidence;
  ::std::vector<double> headPosition;
  ::std::vector<double> headAngleUnitVector;
  ::std::vector<double> gazeAngleUnitVector;
  ::android::hardware::automotive::occupant_awareness::VehicleRegion gazeTarget;
  ::android::String16 customGazeTarget;
  int64_t timeOnTargetMillis;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class GazeDetection

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_GAZE_DETECTION_H_
