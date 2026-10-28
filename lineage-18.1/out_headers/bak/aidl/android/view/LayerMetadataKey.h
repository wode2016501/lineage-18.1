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
namespace view {
enum class LayerMetadataKey : int32_t {
  METADATA_OWNER_UID = 1,
  METADATA_WINDOW_TYPE = 2,
  METADATA_TASK_ID = 3,
  METADATA_MOUSE_CURSOR = 4,
};

static inline std::string toString(LayerMetadataKey val) {
  switch(val) {
  case LayerMetadataKey::METADATA_OWNER_UID:
    return "METADATA_OWNER_UID";
  case LayerMetadataKey::METADATA_WINDOW_TYPE:
    return "METADATA_WINDOW_TYPE";
  case LayerMetadataKey::METADATA_TASK_ID:
    return "METADATA_TASK_ID";
  case LayerMetadataKey::METADATA_MOUSE_CURSOR:
    return "METADATA_MOUSE_CURSOR";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace view
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::view::LayerMetadataKey, 4> enum_values<aidl::android::view::LayerMetadataKey> = {
  aidl::android::view::LayerMetadataKey::METADATA_OWNER_UID,
  aidl::android::view::LayerMetadataKey::METADATA_WINDOW_TYPE,
  aidl::android::view::LayerMetadataKey::METADATA_TASK_ID,
  aidl::android::view::LayerMetadataKey::METADATA_MOUSE_CURSOR,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
