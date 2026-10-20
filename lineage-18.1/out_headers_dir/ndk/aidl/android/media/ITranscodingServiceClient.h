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
#include <aidl/android/media/TranscodingErrorCode.h>
#include <aidl/android/media/TranscodingJobParcel.h>
#include <aidl/android/media/TranscodingResultParcel.h>

namespace aidl {
namespace android {
namespace media {
class ITranscodingServiceClient : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ITranscodingServiceClient();
  virtual ~ITranscodingServiceClient();



  static std::shared_ptr<ITranscodingServiceClient> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ITranscodingServiceClient>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ITranscodingServiceClient>* instance);
  static bool setDefaultImpl(std::shared_ptr<ITranscodingServiceClient> impl);
  static const std::shared_ptr<ITranscodingServiceClient>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus getName(std::string* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus onTranscodingFinished(int32_t in_jobId, const ::aidl::android::media::TranscodingResultParcel& in_result) = 0;
  virtual ::ndk::ScopedAStatus onTranscodingFailed(int32_t in_jobId, ::aidl::android::media::TranscodingErrorCode in_errorCode) = 0;
  virtual ::ndk::ScopedAStatus onAwaitNumberOfJobsChanged(int32_t in_jobId, int32_t in_oldAwaitNumber, int32_t in_newAwaitNumber) = 0;
  virtual ::ndk::ScopedAStatus onProgressUpdate(int32_t in_jobId, int32_t in_progress) = 0;
private:
  static std::shared_ptr<ITranscodingServiceClient> default_impl;
};
class ITranscodingServiceClientDefault : public ITranscodingServiceClient {
public:
  ::ndk::ScopedAStatus getName(std::string* _aidl_return) override;
  ::ndk::ScopedAStatus onTranscodingFinished(int32_t in_jobId, const ::aidl::android::media::TranscodingResultParcel& in_result) override;
  ::ndk::ScopedAStatus onTranscodingFailed(int32_t in_jobId, ::aidl::android::media::TranscodingErrorCode in_errorCode) override;
  ::ndk::ScopedAStatus onAwaitNumberOfJobsChanged(int32_t in_jobId, int32_t in_oldAwaitNumber, int32_t in_newAwaitNumber) override;
  ::ndk::ScopedAStatus onProgressUpdate(int32_t in_jobId, int32_t in_progress) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
