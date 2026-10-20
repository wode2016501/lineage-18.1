#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_VEHICLE_REGION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_VEHICLE_REGION_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

enum class VehicleRegion : int32_t {
  UNKNOWN = 0,
  INSTRUMENT_CLUSTER = 1,
  REAR_VIEW_MIRROR = 2,
  LEFT_SIDE_MIRROR = 3,
  RIGHT_SIDE_MIRROR = 4,
  FORWARD_ROADWAY = 5,
  LEFT_ROADWAY = 6,
  RIGHT_ROADWAY = 7,
  HEAD_UNIT_DISPLAY = 8,
  CUSTOM_TARGET = 200,
};

static inline std::string toString(VehicleRegion val) {
  switch(val) {
  case VehicleRegion::UNKNOWN:
    return "UNKNOWN";
  case VehicleRegion::INSTRUMENT_CLUSTER:
    return "INSTRUMENT_CLUSTER";
  case VehicleRegion::REAR_VIEW_MIRROR:
    return "REAR_VIEW_MIRROR";
  case VehicleRegion::LEFT_SIDE_MIRROR:
    return "LEFT_SIDE_MIRROR";
  case VehicleRegion::RIGHT_SIDE_MIRROR:
    return "RIGHT_SIDE_MIRROR";
  case VehicleRegion::FORWARD_ROADWAY:
    return "FORWARD_ROADWAY";
  case VehicleRegion::LEFT_ROADWAY:
    return "LEFT_ROADWAY";
  case VehicleRegion::RIGHT_ROADWAY:
    return "RIGHT_ROADWAY";
  case VehicleRegion::HEAD_UNIT_DISPLAY:
    return "HEAD_UNIT_DISPLAY";
  case VehicleRegion::CUSTOM_TARGET:
    return "CUSTOM_TARGET";
  default:
    return std::to_string(static_cast<int32_t>(val));
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
constexpr inline std::array<::android::hardware::automotive::occupant_awareness::VehicleRegion, 10> enum_values<::android::hardware::automotive::occupant_awareness::VehicleRegion> = {
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::UNKNOWN,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::INSTRUMENT_CLUSTER,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::REAR_VIEW_MIRROR,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::LEFT_SIDE_MIRROR,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::RIGHT_SIDE_MIRROR,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::FORWARD_ROADWAY,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::LEFT_ROADWAY,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::RIGHT_ROADWAY,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::HEAD_UNIT_DISPLAY,
  ::android::hardware::automotive::occupant_awareness::VehicleRegion::CUSTOM_TARGET,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_VEHICLE_REGION_H_
