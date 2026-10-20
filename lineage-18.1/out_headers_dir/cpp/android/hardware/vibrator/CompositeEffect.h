#ifndef AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_COMPOSITE_EFFECT_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_COMPOSITE_EFFECT_H_

#include <android/hardware/vibrator/CompositePrimitive.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace vibrator {

class CompositeEffect : public ::android::Parcelable {
public:
  inline bool operator!=(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale)!=std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator<(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale)<std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator<=(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale)<=std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator==(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale)==std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator>(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale)>std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator>=(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale)>=std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  int32_t delayMs;
  ::android::hardware::vibrator::CompositePrimitive primitive;
  float scale;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class CompositeEffect

}  // namespace vibrator

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_COMPOSITE_EFFECT_H_
