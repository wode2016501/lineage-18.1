#ifndef AIDL_GENERATED_ANDROID_MEDIA_I_RESOURCE_MANAGER_SERVICE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_I_RESOURCE_MANAGER_SERVICE_H_

#include <android/media/IResourceManagerClient.h>
#include <android/media/MediaResourceParcel.h>
#include <android/media/MediaResourcePolicyParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace media {

class IResourceManagerService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ResourceManagerService)
  static const ::std::string& kPolicySupportsMultipleSecureCodecs();
  static const ::std::string& kPolicySupportsSecureWithNonSecureCodec();
  virtual ::android::binder::Status config(const ::std::vector<::android::media::MediaResourcePolicyParcel>& policies) = 0;
  virtual ::android::binder::Status addResource(int32_t pid, int32_t uid, int64_t clientId, const ::android::sp<::android::media::IResourceManagerClient>& client, const ::std::vector<::android::media::MediaResourceParcel>& resources) = 0;
  virtual ::android::binder::Status removeResource(int32_t pid, int64_t clientId, const ::std::vector<::android::media::MediaResourceParcel>& resources) = 0;
  virtual ::android::binder::Status removeClient(int32_t pid, int64_t clientId) = 0;
  virtual ::android::binder::Status reclaimResource(int32_t callingPid, const ::std::vector<::android::media::MediaResourceParcel>& resources, bool* _aidl_return) = 0;
  virtual ::android::binder::Status overridePid(int32_t originalPid, int32_t newPid) = 0;
  virtual ::android::binder::Status markClientForPendingRemoval(int32_t pid, int64_t clientId) = 0;
  virtual ::android::binder::Status reclaimResourcesFromClientsPendingRemoval(int32_t pid) = 0;
};  // class IResourceManagerService

class IResourceManagerServiceDefault : public IResourceManagerService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status config(const ::std::vector<::android::media::MediaResourcePolicyParcel>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addResource(int32_t, int32_t, int64_t, const ::android::sp<::android::media::IResourceManagerClient>&, const ::std::vector<::android::media::MediaResourceParcel>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeResource(int32_t, int64_t, const ::std::vector<::android::media::MediaResourceParcel>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeClient(int32_t, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reclaimResource(int32_t, const ::std::vector<::android::media::MediaResourceParcel>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status overridePid(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status markClientForPendingRemoval(int32_t, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reclaimResourcesFromClientsPendingRemoval(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IResourceManagerServiceDefault

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_I_RESOURCE_MANAGER_SERVICE_H_
