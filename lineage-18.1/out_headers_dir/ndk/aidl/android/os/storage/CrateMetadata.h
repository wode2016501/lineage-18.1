#pragma once
#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
namespace aidl {
namespace android {
namespace os {
namespace storage {
class CrateMetadata {
public:
  static const char* descriptor;

  int32_t uid;
  std::string packageName;
  std::string id;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace storage
}  // namespace os
}  // namespace android
}  // namespace aidl
