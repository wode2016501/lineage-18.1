#ifndef AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_ERROR_CODE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_ERROR_CODE_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class TranscodingErrorCode : int32_t {
  kUnknown = 0,
  kUnsupported = 1,
  kDecoderError = 2,
  kEncoderError = 3,
  kExtractorError = 4,
  kMuxerError = 5,
  kInvalidBitstream = 6,
};

static inline std::string toString(TranscodingErrorCode val) {
  switch(val) {
  case TranscodingErrorCode::kUnknown:
    return "kUnknown";
  case TranscodingErrorCode::kUnsupported:
    return "kUnsupported";
  case TranscodingErrorCode::kDecoderError:
    return "kDecoderError";
  case TranscodingErrorCode::kEncoderError:
    return "kEncoderError";
  case TranscodingErrorCode::kExtractorError:
    return "kExtractorError";
  case TranscodingErrorCode::kMuxerError:
    return "kMuxerError";
  case TranscodingErrorCode::kInvalidBitstream:
    return "kInvalidBitstream";
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
constexpr inline std::array<::android::media::TranscodingErrorCode, 7> enum_values<::android::media::TranscodingErrorCode> = {
  ::android::media::TranscodingErrorCode::kUnknown,
  ::android::media::TranscodingErrorCode::kUnsupported,
  ::android::media::TranscodingErrorCode::kDecoderError,
  ::android::media::TranscodingErrorCode::kEncoderError,
  ::android::media::TranscodingErrorCode::kExtractorError,
  ::android::media::TranscodingErrorCode::kMuxerError,
  ::android::media::TranscodingErrorCode::kInvalidBitstream,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_ERROR_CODE_H_
