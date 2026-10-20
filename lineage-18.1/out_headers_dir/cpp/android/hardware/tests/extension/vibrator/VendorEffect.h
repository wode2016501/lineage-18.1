#ifndef AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_VENDOR_EFFECT_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_VENDOR_EFFECT_H_

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

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
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::tests::extension::vibrator::VendorEffect, 2> enum_values<::android::hardware::tests::extension::vibrator::VendorEffect> = {
  ::android::hardware::tests::extension::vibrator::VendorEffect::CRACKLE,
  ::android::hardware::tests::extension::vibrator::VendorEffect::WIGGLE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_VIBRATOR_VENDOR_EFFECT_H_
