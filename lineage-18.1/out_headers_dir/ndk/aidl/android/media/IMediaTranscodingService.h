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
#include <aidl/android/media/ITranscodingServiceClient.h>
#include <aidl/android/media/TranscodingJobParcel.h>
#include <aidl/android/media/TranscodingRequestParcel.h>

namespace aidl {
namespace android {
namespace media {
class IMediaTranscodingService : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IMediaTranscodingService();
  virtual ~IMediaTranscodingService();


  enum : int32_t {
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

  static std::shared_ptr<IMediaTranscodingService> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IMediaTranscodingService>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IMediaTranscodingService>* instance);
  static bool setDefaultImpl(std::shared_ptr<IMediaTranscodingService> impl);
  static const std::shared_ptr<IMediaTranscodingService>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus registerClient(const std::shared_ptr<::aidl::android::media::ITranscodingServiceClient>& in_client, const std::string& in_opPackageName, int32_t in_clientUid, int32_t in_clientPid, int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus unregisterClient(int32_t in_clientId, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getNumOfClients(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus submitRequest(int32_t in_clientId, const ::aidl::android::media::TranscodingRequestParcel& in_request, ::aidl::android::media::TranscodingJobParcel* out_job, int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus cancelJob(int32_t in_clientId, int32_t in_jobId, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getJobWithId(int32_t in_jobId, ::aidl::android::media::TranscodingJobParcel* out_job, bool* _aidl_return) = 0;
private:
  static std::shared_ptr<IMediaTranscodingService> default_impl;
};
class IMediaTranscodingServiceDefault : public IMediaTranscodingService {
public:
  ::ndk::ScopedAStatus registerClient(const std::shared_ptr<::aidl::android::media::ITranscodingServiceClient>& in_client, const std::string& in_opPackageName, int32_t in_clientUid, int32_t in_clientPid, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus unregisterClient(int32_t in_clientId, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getNumOfClients(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus submitRequest(int32_t in_clientId, const ::aidl::android::media::TranscodingRequestParcel& in_request, ::aidl::android::media::TranscodingJobParcel* out_job, int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus cancelJob(int32_t in_clientId, int32_t in_jobId, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getJobWithId(int32_t in_jobId, ::aidl::android::media::TranscodingJobParcel* out_job, bool* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
