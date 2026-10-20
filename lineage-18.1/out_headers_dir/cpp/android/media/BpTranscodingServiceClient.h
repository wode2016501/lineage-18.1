#ifndef AIDL_GENERATED_ANDROID_MEDIA_BP_TRANSCODING_SERVICE_CLIENT_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BP_TRANSCODING_SERVICE_CLIENT_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/ITranscodingServiceClient.h>

namespace android {

namespace media {

class BpTranscodingServiceClient : public ::android::BpInterface<ITranscodingServiceClient> {
public:
  explicit BpTranscodingServiceClient(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpTranscodingServiceClient() = default;
  ::android::binder::Status getName(::std::string* _aidl_return) override;
  ::android::binder::Status onTranscodingFinished(int32_t jobId, const ::android::media::TranscodingResultParcel& result) override;
  ::android::binder::Status onTranscodingFailed(int32_t jobId, ::android::media::TranscodingErrorCode errorCode) override;
  ::android::binder::Status onAwaitNumberOfJobsChanged(int32_t jobId, int32_t oldAwaitNumber, int32_t newAwaitNumber) override;
  ::android::binder::Status onProgressUpdate(int32_t jobId, int32_t progress) override;
};  // class BpTranscodingServiceClient

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BP_TRANSCODING_SERVICE_CLIENT_H_
