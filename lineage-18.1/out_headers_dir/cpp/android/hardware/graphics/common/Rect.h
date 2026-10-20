#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_RECT_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_RECT_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class Rect : public ::android::Parcelable {
public:
  inline bool operator!=(const Rect& rhs) const {
    return std::tie(left, top, right, bottom)!=std::tie(rhs.left, rhs.top, rhs.right, rhs.bottom);
  }
  inline bool operator<(const Rect& rhs) const {
    return std::tie(left, top, right, bottom)<std::tie(rhs.left, rhs.top, rhs.right, rhs.bottom);
  }
  inline bool operator<=(const Rect& rhs) const {
    return std::tie(left, top, right, bottom)<=std::tie(rhs.left, rhs.top, rhs.right, rhs.bottom);
  }
  inline bool operator==(const Rect& rhs) const {
    return std::tie(left, top, right, bottom)==std::tie(rhs.left, rhs.top, rhs.right, rhs.bottom);
  }
  inline bool operator>(const Rect& rhs) const {
    return std::tie(left, top, right, bottom)>std::tie(rhs.left, rhs.top, rhs.right, rhs.bottom);
  }
  inline bool operator>=(const Rect& rhs) const {
    return std::tie(left, top, right, bottom)>=std::tie(rhs.left, rhs.top, rhs.right, rhs.bottom);
  }
  int32_t left;
  int32_t top;
  int32_t right;
  int32_t bottom;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class Rect

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_RECT_H_
