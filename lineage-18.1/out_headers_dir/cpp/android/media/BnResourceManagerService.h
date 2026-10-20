#ifndef AIDL_GENERATED_ANDROID_MEDIA_BN_RESOURCE_MANAGER_SERVICE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BN_RESOURCE_MANAGER_SERVICE_H_

#include <binder/IInterface.h>
#include <android/media/IResourceManagerService.h>

namespace android {

namespace media {

class BnResourceManagerService : public ::android::BnInterface<IResourceManagerService> {
public:
  explicit BnResourceManagerService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnResourceManagerService

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BN_RESOURCE_MANAGER_SERVICE_H_
