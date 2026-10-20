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
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::TranscodingJobPriority, 4> enum_values<aidl::android::media::TranscodingJobPriority> = {
  aidl::android::media::TranscodingJobPriority::kUnspecified,
  aidl::android::media::TranscodingJobPriority::kLow,
  aidl::android::media::TranscodingJobPriority::kNormal,
  aidl::android::media::TranscodingJobPriority::kHigh,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
