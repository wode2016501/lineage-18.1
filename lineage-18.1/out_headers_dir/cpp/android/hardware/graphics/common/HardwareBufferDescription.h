#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_HARDWARE_BUFFER_DESCRIPTION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_HARDWARE_BUFFER_DESCRIPTION_H_

#include <android/hardware/graphics/common/BufferUsage.h>
#include <android/hardware/graphics/common/PixelFormat.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class HardwareBufferDescription : public ::android::Parcelable {
public:
  inline bool operator!=(const HardwareBufferDescription& rhs) const {
    return std::tie(width, height, layers, format, usage, stride)!=std::tie(rhs.width, rhs.height, rhs.layers, rhs.format, rhs.usage, rhs.stride);
  }
  inline bool operator<(const HardwareBufferDescription& rhs) const {
    return std::tie(width, height, layers, format, usage, stride)<std::tie(rhs.width, rhs.height, rhs.layers, rhs.format, rhs.usage, rhs.stride);
  }
  inline bool operator<=(const HardwareBufferDescription& rhs) const {
    return std::tie(width, height, layers, format, usage, stride)<=std::tie(rhs.width, rhs.height, rhs.layers, rhs.format, rhs.usage, rhs.stride);
  }
  inline bool operator==(const HardwareBufferDescription& rhs) const {
    return std::tie(width, height, layers, format, usage, stride)==std::tie(rhs.width, rhs.height, rhs.layers, rhs.format, rhs.usage, rhs.stride);
  }
  inline bool operator>(const HardwareBufferDescription& rhs) const {
    return std::tie(width, height, layers, format, usage, stride)>std::tie(rhs.width, rhs.height, rhs.layers, rhs.format, rhs.usage, rhs.stride);
  }
  inline bool operator>=(const HardwareBufferDescription& rhs) const {
    return std::tie(width, height, layers, format, usage, stride)>=std::tie(rhs.width, rhs.height, rhs.layers, rhs.format, rhs.usage, rhs.stride);
  }
  int32_t width;
  int32_t height;
  int32_t layers;
  ::android::hardware::graphics::common::PixelFormat format;
  ::android::hardware::graphics::common::BufferUsage usage;
  int32_t stride;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class HardwareBufferDescription

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_HARDWARE_BUFFER_DESCRIPTION_H_
