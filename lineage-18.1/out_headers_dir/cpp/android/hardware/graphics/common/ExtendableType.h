#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_EXTENDABLE_TYPE_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_EXTENDABLE_TYPE_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class ExtendableType : public ::android::Parcelable {
public:
  inline bool operator!=(const ExtendableType& rhs) const {
    return std::tie(name, value)!=std::tie(rhs.name, rhs.value);
  }
  inline bool operator<(const ExtendableType& rhs) const {
    return std::tie(name, value)<std::tie(rhs.name, rhs.value);
  }
  inline bool operator<=(const ExtendableType& rhs) const {
    return std::tie(name, value)<=std::tie(rhs.name, rhs.value);
  }
  inline bool operator==(const ExtendableType& rhs) const {
    return std::tie(name, value)==std::tie(rhs.name, rhs.value);
  }
  inline bool operator>(const ExtendableType& rhs) const {
    return std::tie(name, value)>std::tie(rhs.name, rhs.value);
  }
  inline bool operator>=(const ExtendableType& rhs) const {
    return std::tie(name, value)>=std::tie(rhs.name, rhs.value);
  }
  ::std::string name;
  int64_t value = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class ExtendableType

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_EXTENDABLE_TYPE_H_
