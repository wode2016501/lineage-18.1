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
#include <aidl/android/media/TranscodingRequestParcel.h>
namespace aidl {
namespace android {
namespace media {
class TranscodingJobParcel {
public:
  static const char* descriptor;

  int32_t jobId;
  ::aidl::android::media::TranscodingRequestParcel request;
  int32_t awaitNumberOfJobs;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
