#ifndef AIDL_GENERATED_ANDROID_MEDIA_BP_RESOURCE_MANAGER_CLIENT_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BP_RESOURCE_MANAGER_CLIENT_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IResourceManagerClient.h>

namespace android {

namespace media {

class BpResourceManagerClient : public ::android::BpInterface<IResourceManagerClient> {
public:
  explicit BpResourceManagerClient(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpResourceManagerClient() = default;
  ::android::binder::Status reclaimResource(bool* _aidl_return) override;
  ::android::binder::Status getName(::std::string* _aidl_return) override;
};  // class BpResourceManagerClient

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BP_RESOURCE_MANAGER_CLIENT_H_
