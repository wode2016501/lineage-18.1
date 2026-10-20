#ifndef AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_VIDEO_CODEC_TYPE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_VIDEO_CODEC_TYPE_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class TranscodingVideoCodecType : int32_t {
  kUnspecified = 0,
  kAvc = 1,
  kHevc = 2,
};

static inline std::string toString(TranscodingVideoCodecType val) {
  switch(val) {
  case TranscodingVideoCodecType::kUnspecified:
    return "kUnspecified";
  case TranscodingVideoCodecType::kAvc:
    return "kAvc";
  case TranscodingVideoCodecType::kHevc:
    return "kHevc";
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
constexpr inline std::array<::android::media::TranscodingVideoCodecType, 3> enum_values<::android::media::TranscodingVideoCodecType> = {
  ::android::media::TranscodingVideoCodecType::kUnspecified,
  ::android::media::TranscodingVideoCodecType::kAvc,
  ::android::media::TranscodingVideoCodecType::kHevc,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_VIDEO_CODEC_TYPE_H_
