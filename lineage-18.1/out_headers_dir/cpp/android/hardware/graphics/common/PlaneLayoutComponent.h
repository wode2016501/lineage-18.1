#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_PLANE_LAYOUT_COMPONENT_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_PLANE_LAYOUT_COMPONENT_H_

#include <android/hardware/graphics/common/ExtendableType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class PlaneLayoutComponent : public ::android::Parcelable {
public:
  inline bool operator!=(const PlaneLayoutComponent& rhs) const {
    return std::tie(type, offsetInBits, sizeInBits)!=std::tie(rhs.type, rhs.offsetInBits, rhs.sizeInBits);
  }
  inline bool operator<(const PlaneLayoutComponent& rhs) const {
    return std::tie(type, offsetInBits, sizeInBits)<std::tie(rhs.type, rhs.offsetInBits, rhs.sizeInBits);
  }
  inline bool operator<=(const PlaneLayoutComponent& rhs) const {
    return std::tie(type, offsetInBits, sizeInBits)<=std::tie(rhs.type, rhs.offsetInBits, rhs.sizeInBits);
  }
  inline bool operator==(const PlaneLayoutComponent& rhs) const {
    return std::tie(type, offsetInBits, sizeInBits)==std::tie(rhs.type, rhs.offsetInBits, rhs.sizeInBits);
  }
  inline bool operator>(const PlaneLayoutComponent& rhs) const {
    return std::tie(type, offsetInBits, sizeInBits)>std::tie(rhs.type, rhs.offsetInBits, rhs.sizeInBits);
  }
  inline bool operator>=(const PlaneLayoutComponent& rhs) const {
    return std::tie(type, offsetInBits, sizeInBits)>=std::tie(rhs.type, rhs.offsetInBits, rhs.sizeInBits);
  }
  ::android::hardware::graphics::common::ExtendableType type;
  int64_t offsetInBits;
  int64_t sizeInBits;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class PlaneLayoutComponent

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_PLANE_LAYOUT_COMPONENT_H_
