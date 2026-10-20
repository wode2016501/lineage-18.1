#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_AWARENESS_STATUS_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_AWARENESS_STATUS_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

enum class OccupantAwarenessStatus : int8_t {
  READY = 0,
  NOT_SUPPORTED = 1,
  NOT_INITIALIZED = 2,
  FAILURE = 3,
};

static inline std::string toString(OccupantAwarenessStatus val) {
  switch(val) {
  case OccupantAwarenessStatus::READY:
    return "READY";
  case OccupantAwarenessStatus::NOT_SUPPORTED:
    return "NOT_SUPPORTED";
  case OccupantAwarenessStatus::NOT_INITIALIZED:
    return "NOT_INITIALIZED";
  case OccupantAwarenessStatus::FAILURE:
    return "FAILURE";
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
constexpr inline std::array<::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus, 4> enum_values<::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus> = {
  ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus::READY,
  ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus::NOT_SUPPORTED,
  ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus::NOT_INITIALIZED,
  ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus::FAILURE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_OCCUPANT_AWARENESS_STATUS_H_
