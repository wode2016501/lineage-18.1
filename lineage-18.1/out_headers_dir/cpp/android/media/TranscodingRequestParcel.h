#ifndef AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_REQUEST_PARCEL_H_
#define AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_REQUEST_PARCEL_H_

#include <android/media/TranscodingJobPriority.h>
#include <android/media/TranscodingType.h>
#include <binder/Parcel.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <string>
#include <tuple>

namespace android {

namespace media {

class TranscodingRequestParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const TranscodingRequestParcel& rhs) const {
    return std::tie(fileName, transcodingType, inFd, outFd, priority, requestUpdate)!=std::tie(rhs.fileName, rhs.transcodingType, rhs.inFd, rhs.outFd, rhs.priority, rhs.requestUpdate);
  }
  inline bool operator<(const TranscodingRequestParcel& rhs) const {
    return std::tie(fileName, transcodingType, inFd, outFd, priority, requestUpdate)<std::tie(rhs.fileName, rhs.transcodingType, rhs.inFd, rhs.outFd, rhs.priority, rhs.requestUpdate);
  }
  inline bool operator<=(const TranscodingRequestParcel& rhs) const {
    return std::tie(fileName, transcodingType, inFd, outFd, priority, requestUpdate)<=std::tie(rhs.fileName, rhs.transcodingType, rhs.inFd, rhs.outFd, rhs.priority, rhs.requestUpdate);
  }
  inline bool operator==(const TranscodingRequestParcel& rhs) const {
    return std::tie(fileName, transcodingType, inFd, outFd, priority, requestUpdate)==std::tie(rhs.fileName, rhs.transcodingType, rhs.inFd, rhs.outFd, rhs.priority, rhs.requestUpdate);
  }
  inline bool operator>(const TranscodingRequestParcel& rhs) const {
    return std::tie(fileName, transcodingType, inFd, outFd, priority, requestUpdate)>std::tie(rhs.fileName, rhs.transcodingType, rhs.inFd, rhs.outFd, rhs.priority, rhs.requestUpdate);
  }
  inline bool operator>=(const TranscodingRequestParcel& rhs) const {
    return std::tie(fileName, transcodingType, inFd, outFd, priority, requestUpdate)>=std::tie(rhs.fileName, rhs.transcodingType, rhs.inFd, rhs.outFd, rhs.priority, rhs.requestUpdate);
  }
  ::std::string fileName;
  ::android::media::TranscodingType transcodingType;
  ::android::os::ParcelFileDescriptor inFd;
  ::android::os::ParcelFileDescriptor outFd;
  ::android::media::TranscodingJobPriority priority;
  bool requestUpdate;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) override final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const override final;
};  // class TranscodingRequestParcel

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_TRANSCODING_REQUEST_PARCEL_H_
