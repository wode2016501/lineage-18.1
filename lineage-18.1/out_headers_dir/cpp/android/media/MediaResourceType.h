#ifndef AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_TYPE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_TYPE_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class MediaResourceType : int32_t {
  kUnspecified = 0,
  kSecureCodec = 1,
  kNonSecureCodec = 2,
  kGraphicMemory = 3,
  kCpuBoost = 4,
  kBattery = 5,
  kDrmSession = 6,
};

static inline std::string toString(MediaResourceType val) {
  switch(val) {
  case MediaResourceType::kUnspecified:
    return "kUnspecified";
  case MediaResourceType::kSecureCodec:
    return "kSecureCodec";
  case MediaResourceType::kNonSecureCodec:
    return "kNonSecureCodec";
  case MediaResourceType::kGraphicMemory:
    return "kGraphicMemory";
  case MediaResourceType::kCpuBoost:
    return "kCpuBoost";
  case MediaResourceType::kBattery:
    return "kBattery";
  case MediaResourceType::kDrmSession:
    return "kDrmSession";
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
constexpr inline std::array<::android::media::MediaResourceType, 7> enum_values<::android::media::MediaResourceType> = {
  ::android::media::MediaResourceType::kUnspecified,
  ::android::media::MediaResourceType::kSecureCodec,
  ::android::media::MediaResourceType::kNonSecureCodec,
  ::android::media::MediaResourceType::kGraphicMemory,
  ::android::media::MediaResourceType::kCpuBoost,
  ::android::media::MediaResourceType::kBattery,
  ::android::media::MediaResourceType::kDrmSession,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_MEDIA_RESOURCE_TYPE_H_
