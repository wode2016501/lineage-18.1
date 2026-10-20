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
namespace content {
namespace pm {
class PackageChangeEvent {
public:
  static const char* descriptor;

  std::string packageName;
  int64_t version;
  int64_t lastUpdateTimeMillis;
  bool newInstalled;
  bool dataRemoved;
  bool isDeleted;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace pm
}  // namespace content
}  // namespace android
}  // namespace aidl
