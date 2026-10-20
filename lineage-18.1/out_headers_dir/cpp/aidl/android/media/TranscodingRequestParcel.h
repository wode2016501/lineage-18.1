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
#include <aidl/android/media/TranscodingJobPriority.h>
#include <aidl/android/media/TranscodingType.h>
namespace aidl {
namespace android {
namespace media {
class TranscodingRequestParcel {
public:
  static const char* descriptor;

  std::string fileName;
  ::aidl::android::media::TranscodingType transcodingType;
  ::ndk::ScopedFileDescriptor inFd;
  ::ndk::ScopedFileDescriptor outFd;
  ::aidl::android::media::TranscodingJobPriority priority;
  bool requestUpdate;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
