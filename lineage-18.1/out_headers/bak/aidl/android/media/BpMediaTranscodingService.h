#pragma once

#include "aidl/android/media/IMediaTranscodingService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpMediaTranscodingService : public ::ndk::BpCInterface<IMediaTranscodingService> {
public:
  BpMediaTranscodingService(const ::ndk::SpAIBinder& binder);
  virtual ~BpMediaTranscodingService();

  ::ndk::ScopedAStatus registerClient(const std::shared_ptr<::aidl::android::media::ITranscodingServiceClient>& in_client, const std::string& in_opPackageName, int32_t in_clientUid, int32_t in_clientPid, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus unregisterClient(int32_t in_clientId, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getNumOfClients(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus submitRequest(int32_t in_clientId, const ::aidl::android::media::TranscodingRequestParcel& in_request, ::aidl::android::media::TranscodingJobParcel* out_job, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus cancelJob(int32_t in_clientId, int32_t in_jobId, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getJobWithId(int32_t in_jobId, ::aidl::android::media::TranscodingJobParcel* out_job, bool* _aidl_return) override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
