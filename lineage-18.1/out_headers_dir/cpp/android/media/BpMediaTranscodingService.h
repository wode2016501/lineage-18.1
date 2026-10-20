#ifndef AIDL_GENERATED_ANDROID_MEDIA_BP_MEDIA_TRANSCODING_SERVICE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BP_MEDIA_TRANSCODING_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IMediaTranscodingService.h>

namespace android {

namespace media {

class BpMediaTranscodingService : public ::android::BpInterface<IMediaTranscodingService> {
public:
  explicit BpMediaTranscodingService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpMediaTranscodingService() = default;
  ::android::binder::Status registerClient(const ::android::sp<::android::media::ITranscodingServiceClient>& client, const ::android::String16& opPackageName, int32_t clientUid, int32_t clientPid, int32_t* _aidl_return) override;
  ::android::binder::Status unregisterClient(int32_t clientId, bool* _aidl_return) override;
  ::android::binder::Status getNumOfClients(int32_t* _aidl_return) override;
  ::android::binder::Status submitRequest(int32_t clientId, const ::android::media::TranscodingRequestParcel& request, ::android::media::TranscodingJobParcel* job, int32_t* _aidl_return) override;
  ::android::binder::Status cancelJob(int32_t clientId, int32_t jobId, bool* _aidl_return) override;
  ::android::binder::Status getJobWithId(int32_t jobId, ::android::media::TranscodingJobParcel* job, bool* _aidl_return) override;
};  // class BpMediaTranscodingService

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BP_MEDIA_TRANSCODING_SERVICE_H_
