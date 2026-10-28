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
#include <aidl/android/media/MediaResourceSubType.h>
#include <aidl/android/media/MediaResourceType.h>
namespace aidl {
namespace android {
namespace media {
class MediaResourceParcel {
public:
  static const char* descriptor;

  ::aidl::android::media::MediaResourceType type;
  ::aidl::android::media::MediaResourceSubType subType;
  std::vector<int8_t> id;
  int64_t value = 0L;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
