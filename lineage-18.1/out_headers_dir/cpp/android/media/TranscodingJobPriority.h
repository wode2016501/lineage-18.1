#ifndef AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_JOB_PRIORITY_H_
#define AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_JOB_PRIORITY_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class TranscodingJobPriority : int32_t {
  kUnspecified = 0,
  kLow = 1,
  kNormal = 21,
  kHigh = 31,
};

static inline std::string toString(TranscodingJobPriority val) {
  switch(val) {
  case TranscodingJobPriority::kUnspecified:
    return "kUnspecified";
  case TranscodingJobPriority::kLow:
    return "kLow";
  case TranscodingJobPriority::kNormal:
    return "kNormal";
  case TranscodingJobPriority::kHigh:
    return "kHigh";
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
constexpr inline std::array<::android::media::TranscodingJobPriority, 4> enum_values<::android::media::TranscodingJobPriority> = {
  ::android::media::TranscodingJobPriority::kUnspecified,
  ::android::media::TranscodingJobPriority::kLow,
  ::android::media::TranscodingJobPriority::kNormal,
  ::android::media::TranscodingJobPriority::kHigh,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_JOB_PRIORITY_H_
