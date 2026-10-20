#ifndef AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_PLANE_LAYOUT_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_PLANE_LAYOUT_H_

#include <android/hardware/graphics/common/PlaneLayoutComponent.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <vector>

namespace android {

namespace hardware {

namespace graphics {

namespace common {

class PlaneLayout : public ::android::Parcelable {
public:
  inline bool operator!=(const PlaneLayout& rhs) const {
    return std::tie(components, offsetInBytes, sampleIncrementInBits, strideInBytes, widthInSamples, heightInSamples, totalSizeInBytes, horizontalSubsampling, verticalSubsampling)!=std::tie(rhs.components, rhs.offsetInBytes, rhs.sampleIncrementInBits, rhs.strideInBytes, rhs.widthInSamples, rhs.heightInSamples, rhs.totalSizeInBytes, rhs.horizontalSubsampling, rhs.verticalSubsampling);
  }
  inline bool operator<(const PlaneLayout& rhs) const {
    return std::tie(components, offsetInBytes, sampleIncrementInBits, strideInBytes, widthInSamples, heightInSamples, totalSizeInBytes, horizontalSubsampling, verticalSubsampling)<std::tie(rhs.components, rhs.offsetInBytes, rhs.sampleIncrementInBits, rhs.strideInBytes, rhs.widthInSamples, rhs.heightInSamples, rhs.totalSizeInBytes, rhs.horizontalSubsampling, rhs.verticalSubsampling);
  }
  inline bool operator<=(const PlaneLayout& rhs) const {
    return std::tie(components, offsetInBytes, sampleIncrementInBits, strideInBytes, widthInSamples, heightInSamples, totalSizeInBytes, horizontalSubsampling, verticalSubsampling)<=std::tie(rhs.components, rhs.offsetInBytes, rhs.sampleIncrementInBits, rhs.strideInBytes, rhs.widthInSamples, rhs.heightInSamples, rhs.totalSizeInBytes, rhs.horizontalSubsampling, rhs.verticalSubsampling);
  }
  inline bool operator==(const PlaneLayout& rhs) const {
    return std::tie(components, offsetInBytes, sampleIncrementInBits, strideInBytes, widthInSamples, heightInSamples, totalSizeInBytes, horizontalSubsampling, verticalSubsampling)==std::tie(rhs.components, rhs.offsetInBytes, rhs.sampleIncrementInBits, rhs.strideInBytes, rhs.widthInSamples, rhs.heightInSamples, rhs.totalSizeInBytes, rhs.horizontalSubsampling, rhs.verticalSubsampling);
  }
  inline bool operator>(const PlaneLayout& rhs) const {
    return std::tie(components, offsetInBytes, sampleIncrementInBits, strideInBytes, widthInSamples, heightInSamples, totalSizeInBytes, horizontalSubsampling, verticalSubsampling)>std::tie(rhs.components, rhs.offsetInBytes, rhs.sampleIncrementInBits, rhs.strideInBytes, rhs.widthInSamples, rhs.heightInSamples, rhs.totalSizeInBytes, rhs.horizontalSubsampling, rhs.verticalSubsampling);
  }
  inline bool operator>=(const PlaneLayout& rhs) const {
    return std::tie(components, offsetInBytes, sampleIncrementInBits, strideInBytes, widthInSamples, heightInSamples, totalSizeInBytes, horizontalSubsampling, verticalSubsampling)>=std::tie(rhs.components, rhs.offsetInBytes, rhs.sampleIncrementInBits, rhs.strideInBytes, rhs.widthInSamples, rhs.heightInSamples, rhs.totalSizeInBytes, rhs.horizontalSubsampling, rhs.verticalSubsampling);
  }
  ::std::vector<::android::hardware::graphics::common::PlaneLayoutComponent> components;
  int64_t offsetInBytes;
  int64_t sampleIncrementInBits;
  int64_t strideInBytes;
  int64_t widthInSamples;
  int64_t heightInSamples;
  int64_t totalSizeInBytes;
  int64_t horizontalSubsampling;
  int64_t verticalSubsampling;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class PlaneLayout

}  // namespace common

}  // namespace graphics

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_GRAPHICS_COMMON_PLANE_LAYOUT_H_
