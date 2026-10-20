#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_CONFIDENCE_LEVEL_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_CONFIDENCE_LEVEL_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

enum class ConfidenceLevel : int8_t {
  NONE = 0,
  LOW = 1,
  HIGH = 2,
  MAX = 3,
};

static inline std::string toString(ConfidenceLevel val) {
  switch(val) {
  case ConfidenceLevel::NONE:
    return "NONE";
  case ConfidenceLevel::LOW:
    return "LOW";
  case ConfidenceLevel::HIGH:
    return "HIGH";
  case ConfidenceLevel::MAX:
    return "MAX";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::automotive::occupant_awareness::ConfidenceLevel, 4> enum_values<::android::hardware::automotive::occupant_awareness::ConfidenceLevel> = {
  ::android::hardware::automotive::occupant_awareness::ConfidenceLevel::NONE,
  ::android::hardware::automotive::occupant_awareness::ConfidenceLevel::LOW,
  ::android::hardware::automotive::occupant_awareness::ConfidenceLevel::HIGH,
  ::android::hardware::automotive::occupant_awareness::ConfidenceLevel::MAX,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_CONFIDENCE_LEVEL_H_
