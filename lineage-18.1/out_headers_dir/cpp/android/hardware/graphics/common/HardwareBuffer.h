#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_HARDWARE_BUFFER_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_HARDWARE_BUFFER_H_

#include <android/hardware/common/NativeHandle.h>
#include <android/hardware/graphics/common/HardwareBufferDescription.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class HardwareBuffer : public ::android::Parcelable {
public:
  inline bool operator!=(const HardwareBuffer& rhs) const {
    return std::tie(description, handle)!=std::tie(rhs.description, rhs.handle);
  }
  inline bool operator<(const HardwareBuffer& rhs) const {
    return std::tie(description, handle)<std::tie(rhs.description, rhs.handle);
  }
  inline bool operator<=(const HardwareBuffer& rhs) const {
    return std::tie(description, handle)<=std::tie(rhs.description, rhs.handle);
  }
  inline bool operator==(const HardwareBuffer& rhs) const {
    return std::tie(description, handle)==std::tie(rhs.description, rhs.handle);
  }
  inline bool operator>(const HardwareBuffer& rhs) const {
    return std::tie(description, handle)>std::tie(rhs.description, rhs.handle);
  }
  inline bool operator>=(const HardwareBuffer& rhs) const {
    return std::tie(description, handle)>=std::tie(rhs.description, rhs.handle);
  }
  ::android::hardware::graphics::common::HardwareBufferDescription description;
  ::android::hardware::common::NativeHandle handle;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class HardwareBuffer

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_HARDWARE_BUFFER_H_
