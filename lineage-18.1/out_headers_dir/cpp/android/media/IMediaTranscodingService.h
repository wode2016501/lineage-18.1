#ifndef AIDL_GENERATED_ANDROID_MEDIA_I_MEDIA_TRANSCODING_SERVICE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_I_MEDIA_TRANSCODING_SERVICE_H_

#include <android/media/ITranscodingServiceClient.h>
#include <android/media/TranscodingJobParcel.h>
#include <android/media/TranscodingRequestParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

class IMediaTranscodingService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(MediaTranscodingService)
  enum  : int32_t {
    ERROR_PERMISSION_DENIED = 1,
    ERROR_ALREADY_EXISTS = 2,
    ERROR_ILLEGAL_ARGUMENT = 3,
    ERROR_DISCONNECTED = 4,
    ERROR_TIMED_OUT = 5,
    ERROR_DISABLED = 6,
    ERROR_INVALID_OPERATION = 7,
    USE_CALLING_UID = -1,
    USE_CALLING_PID = -1,
  };
  virtual ::android::binder::Status registerClient(const ::android::sp<::android::media::ITranscodingServiceClient>& client, const ::android::String16& opPackageName, int32_t clientUid, int32_t clientPid, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status unregisterClient(int32_t clientId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getNumOfClients(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status submitRequest(int32_t clientId, const ::android::media::TranscodingRequestParcel& request, ::android::media::TranscodingJobParcel* job, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status cancelJob(int32_t clientId, int32_t jobId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getJobWithId(int32_t jobId, ::android::media::TranscodingJobParcel* job, bool* _aidl_return) = 0;
};  // class IMediaTranscodingService

class IMediaTranscodingServiceDefault : public IMediaTranscodingService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status registerClient(const ::android::sp<::android::media::ITranscodingServiceClient>&, const ::android::String16&, int32_t, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status unregisterClient(int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getNumOfClients(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status submitRequest(int32_t, const ::android::media::TranscodingRequestParcel&, ::android::media::TranscodingJobParcel*, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancelJob(int32_t, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getJobWithId(int32_t, ::android::media::TranscodingJobParcel*, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IMediaTranscodingServiceDefault

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_I_MEDIA_TRANSCODING_SERVICE_H_
