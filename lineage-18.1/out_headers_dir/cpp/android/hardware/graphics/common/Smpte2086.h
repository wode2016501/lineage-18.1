#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_SMPTE2086_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_SMPTE2086_H_

#include <android/hardware/graphics/common/XyColor.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class Smpte2086 : public ::android::Parcelable {
public:
  inline bool operator!=(const Smpte2086& rhs) const {
    return std::tie(primaryRed, primaryGreen, primaryBlue, whitePoint, maxLuminance, minLuminance)!=std::tie(rhs.primaryRed, rhs.primaryGreen, rhs.primaryBlue, rhs.whitePoint, rhs.maxLuminance, rhs.minLuminance);
  }
  inline bool operator<(const Smpte2086& rhs) const {
    return std::tie(primaryRed, primaryGreen, primaryBlue, whitePoint, maxLuminance, minLuminance)<std::tie(rhs.primaryRed, rhs.primaryGreen, rhs.primaryBlue, rhs.whitePoint, rhs.maxLuminance, rhs.minLuminance);
  }
  inline bool operator<=(const Smpte2086& rhs) const {
    return std::tie(primaryRed, primaryGreen, primaryBlue, whitePoint, maxLuminance, minLuminance)<=std::tie(rhs.primaryRed, rhs.primaryGreen, rhs.primaryBlue, rhs.whitePoint, rhs.maxLuminance, rhs.minLuminance);
  }
  inline bool operator==(const Smpte2086& rhs) const {
    return std::tie(primaryRed, primaryGreen, primaryBlue, whitePoint, maxLuminance, minLuminance)==std::tie(rhs.primaryRed, rhs.primaryGreen, rhs.primaryBlue, rhs.whitePoint, rhs.maxLuminance, rhs.minLuminance);
  }
  inline bool operator>(const Smpte2086& rhs) const {
    return std::tie(primaryRed, primaryGreen, primaryBlue, whitePoint, maxLuminance, minLuminance)>std::tie(rhs.primaryRed, rhs.primaryGreen, rhs.primaryBlue, rhs.whitePoint, rhs.maxLuminance, rhs.minLuminance);
  }
  inline bool operator>=(const Smpte2086& rhs) const {
    return std::tie(primaryRed, primaryGreen, primaryBlue, whitePoint, maxLuminance, minLuminance)>=std::tie(rhs.primaryRed, rhs.primaryGreen, rhs.primaryBlue, rhs.whitePoint, rhs.maxLuminance, rhs.minLuminance);
  }
  ::android::hardware::graphics::common::XyColor primaryRed;
  ::android::hardware::graphics::common::XyColor primaryGreen;
  ::android::hardware::graphics::common::XyColor primaryBlue;
  ::android::hardware::graphics::common::XyColor whitePoint;
  float maxLuminance;
  float minLuminance;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class Smpte2086

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_SMPTE2086_H_
