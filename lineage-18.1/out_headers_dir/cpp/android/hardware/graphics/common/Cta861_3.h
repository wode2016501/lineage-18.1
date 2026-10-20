#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_CTA861_3_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_CTA861_3_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class Cta861_3 : public ::android::Parcelable {
public:
  inline bool operator!=(const Cta861_3& rhs) const {
    return std::tie(maxContentLightLevel, maxFrameAverageLightLevel)!=std::tie(rhs.maxContentLightLevel, rhs.maxFrameAverageLightLevel);
  }
  inline bool operator<(const Cta861_3& rhs) const {
    return std::tie(maxContentLightLevel, maxFrameAverageLightLevel)<std::tie(rhs.maxContentLightLevel, rhs.maxFrameAverageLightLevel);
  }
  inline bool operator<=(const Cta861_3& rhs) const {
    return std::tie(maxContentLightLevel, maxFrameAverageLightLevel)<=std::tie(rhs.maxContentLightLevel, rhs.maxFrameAverageLightLevel);
  }
  inline bool operator==(const Cta861_3& rhs) const {
    return std::tie(maxContentLightLevel, maxFrameAverageLightLevel)==std::tie(rhs.maxContentLightLevel, rhs.maxFrameAverageLightLevel);
  }
  inline bool operator>(const Cta861_3& rhs) const {
    return std::tie(maxContentLightLevel, maxFrameAverageLightLevel)>std::tie(rhs.maxContentLightLevel, rhs.maxFrameAverageLightLevel);
  }
  inline bool operator>=(const Cta861_3& rhs) const {
    return std::tie(maxContentLightLevel, maxFrameAverageLightLevel)>=std::tie(rhs.maxContentLightLevel, rhs.maxFrameAverageLightLevel);
  }
  float maxContentLightLevel;
  float maxFrameAverageLightLevel;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class Cta861_3

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_CTA861_3_H_
