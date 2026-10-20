#ifndef AIDL_GENERATED_ANDROID_MEDIA_I_TRANSCODING_SERVICE_CLIENT_H_
#define AIDL_GENERATED_ANDROID_MEDIA_I_TRANSCODING_SERVICE_CLIENT_H_

#include <android/media/TranscodingErrorCode.h>
#include <android/media/TranscodingResultParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

class ITranscodingServiceClient : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(TranscodingServiceClient)
  virtual ::android::binder::Status getName(::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status onTranscodingFinished(int32_t jobId, const ::android::media::TranscodingResultParcel& result) = 0;
  virtual ::android::binder::Status onTranscodingFailed(int32_t jobId, ::android::media::TranscodingErrorCode errorCode) = 0;
  virtual ::android::binder::Status onAwaitNumberOfJobsChanged(int32_t jobId, int32_t oldAwaitNumber, int32_t newAwaitNumber) = 0;
  virtual ::android::binder::Status onProgressUpdate(int32_t jobId, int32_t progress) = 0;
};  // class ITranscodingServiceClient

class ITranscodingServiceClientDefault : public ITranscodingServiceClient {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getName(::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onTranscodingFinished(int32_t, const ::android::media::TranscodingResultParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onTranscodingFailed(int32_t, ::android::media::TranscodingErrorCode) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAwaitNumberOfJobsChanged(int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onProgressUpdate(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ITranscodingServiceClientDefault

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_I_TRANSCODING_SERVICE_CLIENT_H_
