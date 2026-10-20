#pragma once

#include "aidl/android/media/ITranscodingServiceClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpTranscodingServiceClient : public ::ndk::BpCInterface<ITranscodingServiceClient> {
public:
  BpTranscodingServiceClient(const ::ndk::SpAIBinder& binder);
  virtual ~BpTranscodingServiceClient();

  ::ndk::ScopedAStatus getName(std::string* _aidl_return) override;
  ::ndk::ScopedAStatus onTranscodingFinished(int32_t in_jobId, const ::aidl::android::media::TranscodingResultParcel& in_result) override;
  ::ndk::ScopedAStatus onTranscodingFailed(int32_t in_jobId, ::aidl::android::media::TranscodingErrorCode in_errorCode) override;
  ::ndk::ScopedAStatus onAwaitNumberOfJobsChanged(int32_t in_jobId, int32_t in_oldAwaitNumber, int32_t in_newAwaitNumber) override;
  ::ndk::ScopedAStatus onProgressUpdate(int32_t in_jobId, int32_t in_progress) override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
