#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_DETECTION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_DETECTION_H_

#include <android/hardware/automotive/occupant_awareness/DriverMonitoringDetection.h>
#include <android/hardware/automotive/occupant_awareness/GazeDetection.h>
#include <android/hardware/automotive/occupant_awareness/PresenceDetection.h>
#include <android/hardware/automotive/occupant_awareness/Role.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class OccupantDetection : public ::android::Parcelable {
public:
  inline bool operator!=(const OccupantDetection& rhs) const {
    return std::tie(role, presenceData, gazeData, attentionData)!=std::tie(rhs.role, rhs.presenceData, rhs.gazeData, rhs.attentionData);
  }
  inline bool operator<(const OccupantDetection& rhs) const {
    return std::tie(role, presenceData, gazeData, attentionData)<std::tie(rhs.role, rhs.presenceData, rhs.gazeData, rhs.attentionData);
  }
  inline bool operator<=(const OccupantDetection& rhs) const {
    return std::tie(role, presenceData, gazeData, attentionData)<=std::tie(rhs.role, rhs.presenceData, rhs.gazeData, rhs.attentionData);
  }
  inline bool operator==(const OccupantDetection& rhs) const {
    return std::tie(role, presenceData, gazeData, attentionData)==std::tie(rhs.role, rhs.presenceData, rhs.gazeData, rhs.attentionData);
  }
  inline bool operator>(const OccupantDetection& rhs) const {
    return std::tie(role, presenceData, gazeData, attentionData)>std::tie(rhs.role, rhs.presenceData, rhs.gazeData, rhs.attentionData);
  }
  inline bool operator>=(const OccupantDetection& rhs) const {
    return std::tie(role, presenceData, gazeData, attentionData)>=std::tie(rhs.role, rhs.presenceData, rhs.gazeData, rhs.attentionData);
  }
  ::android::hardware::automotive::occupant_awareness::Role role;
  ::std::vector<::android::hardware::automotive::occupant_awareness::PresenceDetection> presenceData;
  ::std::vector<::android::hardware::automotive::occupant_awareness::GazeDetection> gazeData;
  ::std::vector<::android::hardware::automotive::occupant_awareness::DriverMonitoringDetection> attentionData;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class OccupantDetection

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_DETECTION_H_
