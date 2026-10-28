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
namespace gui {
enum class DropInputMode : int32_t {
  NONE = 0,
  ALL = 1,
};

static inline std::string toString(DropInputMode val) {
  switch(val) {
  case DropInputMode::NONE:
    return "NONE";
  case DropInputMode::ALL:
    return "ALL";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace gui
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::gui::DropInputMode, 2> enum_values<aidl::android::gui::DropInputMode> = {
  aidl::android::gui::DropInputMode::NONE,
  aidl::android::gui::DropInputMode::ALL,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
