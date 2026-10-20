#ifndef AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_DIRECTIONALITY_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_DIRECTIONALITY_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace tests {

namespace extension {

namespace vibrator {

enum class Directionality : int32_t {
  NONE = 0,
  TRANSVERSE = 1,
  LONGITUDINAL = 2,
};

static inline std::string toString(Directionality val) {
  switch(val) {
  case Directionality::NONE:
    return "NONE";
  case Directionality::TRANSVERSE:
    return "TRANSVERSE";
  case Directionality::LONGITUDINAL:
    return "LONGITUDINAL";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace vibrator

}  // namespace extension

}  // namespace tests

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::tests::extension::vibrator::Directionality, 3> enum_values<::android::hardware::tests::extension::vibrator::Directionality> = {
  ::android::hardware::tests::extension::vibrator::Directionality::NONE,
  ::android::hardware::tests::extension::vibrator::Directionality::TRANSVERSE,
  ::android::hardware::tests::extension::vibrator::Directionality::LONGITUDINAL,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_DIRECTIONALITY_H_
