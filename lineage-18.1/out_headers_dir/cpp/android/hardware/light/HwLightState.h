#ifndef AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_HW_LIGHT_STATE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_HW_LIGHT_STATE_H_

#include <android/hardware/light/BrightnessMode.h>
#include <android/hardware/light/FlashMode.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace light {

class HwLightState : public ::android::Parcelable {
public:
  inline bool operator!=(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode)!=std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator<(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode)<std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator<=(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode)<=std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator==(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode)==std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator>(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode)>std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator>=(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode)>=std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  int32_t color;
  ::android::hardware::light::FlashMode flashMode;
  int32_t flashOnMs;
  int32_t flashOffMs;
  ::android::hardware::light::BrightnessMode brightnessMode;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class HwLightState

}  // namespace light

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_HW_LIGHT_STATE_H_
