#ifndef AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_SUB_TYPE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_SUB_TYPE_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class MediaResourceSubType : int32_t {
  kUnspecifiedSubType = 0,
  kAudioCodec = 1,
  kVideoCodec = 2,
};

static inline std::string toString(MediaResourceSubType val) {
  switch(val) {
  case MediaResourceSubType::kUnspecifiedSubType:
    return "kUnspecifiedSubType";
  case MediaResourceSubType::kAudioCodec:
    return "kAudioCodec";
  case MediaResourceSubType::kVideoCodec:
    return "kVideoCodec";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::MediaResourceSubType, 3> enum_values<::android::media::MediaResourceSubType> = {
  ::android::media::MediaResourceSubType::kUnspecifiedSubType,
  ::android::media::MediaResourceSubType::kAudioCodec,
  ::android::media::MediaResourceSubType::kVideoCodec,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_SUB_TYPE_H_
