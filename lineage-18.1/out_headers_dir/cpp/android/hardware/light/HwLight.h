#ifndef AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_HW_LIGHT_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_HW_LIGHT_H_

#include <android/hardware/light/LightType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace light {

class HwLight : public ::android::Parcelable {
public:
  inline bool operator!=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type)!=std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator<(const HwLight& rhs) const {
    return std::tie(id, ordinal, type)<std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator<=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type)<=std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator==(const HwLight& rhs) const {
    return std::tie(id, ordinal, type)==std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator>(const HwLight& rhs) const {
    return std::tie(id, ordinal, type)>std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator>=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type)>=std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  int32_t id;
  int32_t ordinal;
  ::android::hardware::light::LightType type;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class HwLight

}  // namespace light

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_HW_LIGHT_H_
