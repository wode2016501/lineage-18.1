#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <array>
#include <android/binder_enums.h>
namespace aidl {
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
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::TranscodingErrorCode, 7> enum_values<aidl::android::media::TranscodingErrorCode> = {
  aidl::android::media::TranscodingErrorCode::kUnknown,
  aidl::android::media::TranscodingErrorCode::kUnsupported,
  aidl::android::media::TranscodingErrorCode::kDecoderError,
  aidl::android::media::TranscodingErrorCode::kEncoderError,
  aidl::android::media::TranscodingErrorCode::kExtractorError,
  aidl::android::media::TranscodingErrorCode::kMuxerError,
  aidl::android::media::TranscodingErrorCode::kInvalidBitstream,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
