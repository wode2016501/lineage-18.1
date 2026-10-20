#ifndef AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_RESULT_PARCEL_H_
#define AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_RESULT_PARCEL_H_

#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>

namespace android {

namespace media {

class TranscodingResultParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TranscodingResultParcel& rhs) const {
    return std::tie(jobId, actualBitrateBps)!=std::tie(rhs.jobId, rhs.actualBitrateBps);
  }
  inline bool operator<(const TranscodingResultParcel& rhs) const {
    return std::tie(jobId, actualBitrateBps)<std::tie(rhs.jobId, rhs.actualBitrateBps);
  }
  inline bool operator<=(const TranscodingResultParcel& rhs) const {
    return std::tie(jobId, actualBitrateBps)<=std::tie(rhs.jobId, rhs.actualBitrateBps);
  }
  inline bool operator==(const TranscodingResultParcel& rhs) const {
    return std::tie(jobId, actualBitrateBps)==std::tie(rhs.jobId, rhs.actualBitrateBps);
  }
  inline bool operator>(const TranscodingResultParcel& rhs) const {
    return std::tie(jobId, actualBitrateBps)>std::tie(rhs.jobId, rhs.actualBitrateBps);
  }
  inline bool operator>=(const TranscodingResultParcel& rhs) const {
    return std::tie(jobId, actualBitrateBps)>=std::tie(rhs.jobId, rhs.actualBitrateBps);
  }
  int32_t jobId;
  int32_t actualBitrateBps;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class TranscodingResultParcel

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_RESULT_PARCEL_H_
