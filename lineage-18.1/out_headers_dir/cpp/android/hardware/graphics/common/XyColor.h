#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_XY_COLOR_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_XY_COLOR_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class XyColor : public ::android::Parcelable {
public:
  inline bool operator!=(const XyColor& rhs) const {
    return std::tie(x, y)!=std::tie(rhs.x, rhs.y);
  }
  inline bool operator<(const XyColor& rhs) const {
    return std::tie(x, y)<std::tie(rhs.x, rhs.y);
  }
  inline bool operator<=(const XyColor& rhs) const {
    return std::tie(x, y)<=std::tie(rhs.x, rhs.y);
  }
  inline bool operator==(const XyColor& rhs) const {
    return std::tie(x, y)==std::tie(rhs.x, rhs.y);
  }
  inline bool operator>(const XyColor& rhs) const {
    return std::tie(x, y)>std::tie(rhs.x, rhs.y);
  }
  inline bool operator>=(const XyColor& rhs) const {
    return std::tie(x, y)>=std::tie(rhs.x, rhs.y);
  }
  float x;
  float y;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class XyColor

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_XY_COLOR_H_
