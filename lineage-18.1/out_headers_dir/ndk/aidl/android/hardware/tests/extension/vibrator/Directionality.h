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
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::tests::extension::vibrator::Directionality, 3> enum_values<aidl::android::hardware::tests::extension::vibrator::Directionality> = {
  aidl::android::hardware::tests::extension::vibrator::Directionality::NONE,
  aidl::android::hardware::tests::extension::vibrator::Directionality::TRANSVERSE,
  aidl::android::hardware::tests::extension::vibrator::Directionality::LONGITUDINAL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
