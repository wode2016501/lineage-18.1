#ifndef AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_TYPE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_TYPE_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class TranscodingType : int32_t {
  kUnknown = 0,
  kVideoTranscoding = 1,
  kImageTranscoding = 2,
};

static inline std::string toString(TranscodingType val) {
  switch(val) {
  case TranscodingType::kUnknown:
    return "kUnknown";
  case TranscodingType::kVideoTranscoding:
    return "kVideoTranscoding";
  case TranscodingType::kImageTranscoding:
    return "kImageTranscoding";
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
constexpr inline std::array<::android::media::TranscodingType, 3> enum_values<::android::media::TranscodingType> = {
  ::android::media::TranscodingType::kUnknown,
  ::android::media::TranscodingType::kVideoTranscoding,
  ::android::media::TranscodingType::kImageTranscoding,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_TYPE_H_
