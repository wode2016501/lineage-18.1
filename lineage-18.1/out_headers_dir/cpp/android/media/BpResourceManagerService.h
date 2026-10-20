#ifndef AIDL_GENERATED_ANDROID_MEDIA_BP_RESOURCE_MANAGER_SERVICE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BP_RESOURCE_MANAGER_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IResourceManagerService.h>

namespace android {

namespace media {

class BpResourceManagerService : public ::android::BpInterface<IResourceManagerService> {
public:
  explicit BpResourceManagerService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpResourceManagerService() = default;
  ::android::binder::Status config(const ::std::vector<::android::media::MediaResourcePolicyParcel>& policies) override;
  ::android::binder::Status addResource(int32_t pid, int32_t uid, int64_t clientId, const ::android::sp<::android::media::IResourceManagerClient>& client, const ::std::vector<::android::media::MediaResourceParcel>& resources) override;
  ::android::binder::Status removeResource(int32_t pid, int64_t clientId, const ::std::vector<::android::media::MediaResourceParcel>& resources) override;
  ::android::binder::Status removeClient(int32_t pid, int64_t clientId) override;
  ::android::binder::Status reclaimResource(int32_t callingPid, const ::std::vector<::android::media::MediaResourceParcel>& resources, bool* _aidl_return) override;
  ::android::binder::Status overridePid(int32_t originalPid, int32_t newPid) override;
  ::android::binder::Status markClientForPendingRemoval(int32_t pid, int64_t clientId) override;
  ::android::binder::Status reclaimResourcesFromClientsPendingRemoval(int32_t pid) override;
};  // class BpResourceManagerService

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BP_RESOURCE_MANAGER_SERVICE_H_
