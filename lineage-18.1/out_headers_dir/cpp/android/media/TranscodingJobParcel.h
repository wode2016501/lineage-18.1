#ifndef AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_JOB_PARCEL_H_
#define AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_JOB_PARCEL_H_

#include <android/media/TranscodingRequestParcel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace media {

class TranscodingJobParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TranscodingJobParcel& rhs) const {
    return std::tie(jobId, request, awaitNumberOfJobs)!=std::tie(rhs.jobId, rhs.request, rhs.awaitNumberOfJobs);
  }
  inline bool operator<(const TranscodingJobParcel& rhs) const {
    return std::tie(jobId, request, awaitNumberOfJobs)<std::tie(rhs.jobId, rhs.request, rhs.awaitNumberOfJobs);
  }
  inline bool operator<=(const TranscodingJobParcel& rhs) const {
    return std::tie(jobId, request, awaitNumberOfJobs)<=std::tie(rhs.jobId, rhs.request, rhs.awaitNumberOfJobs);
  }
  inline bool operator==(const TranscodingJobParcel& rhs) const {
    return std::tie(jobId, request, awaitNumberOfJobs)==std::tie(rhs.jobId, rhs.request, rhs.awaitNumberOfJobs);
  }
  inline bool operator>(const TranscodingJobParcel& rhs) const {
    return std::tie(jobId, request, awaitNumberOfJobs)>std::tie(rhs.jobId, rhs.request, rhs.awaitNumberOfJobs);
  }
  inline bool operator>=(const TranscodingJobParcel& rhs) const {
    return std::tie(jobId, request, awaitNumberOfJobs)>=std::tie(rhs.jobId, rhs.request, rhs.awaitNumberOfJobs);
  }
  int32_t jobId;
  ::android::media::TranscodingRequestParcel request;
  int32_t awaitNumberOfJobs;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class TranscodingJobParcel

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_JOB_PARCEL_H_
