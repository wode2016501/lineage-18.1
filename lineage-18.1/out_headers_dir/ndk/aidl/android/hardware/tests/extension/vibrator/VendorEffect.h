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
enum class VendorEffect : int32_t {
  CRACKLE = 0,
  WIGGLE = 1,
};

static inline std::string toString(VendorEffect val) {
  switch(val) {
  case VendorEffect::CRACKLE:
    return "CRACKLE";
  case VendorEffect::WIGGLE:
    return "WIGGLE";
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
constexpr inline std::array<aidl::android::hardware::tests::extension::vibrator::VendorEffect, 2> enum_values<aidl::android::hardware::tests::extension::vibrator::VendorEffect> = {
  aidl::android::hardware::tests::extension::vibrator::VendorEffect::CRACKLE,
  aidl::android::hardware::tests::extension::vibrator::VendorEffect::WIGGLE,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
