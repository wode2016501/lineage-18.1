#ifndef AIDL_GENERATED_ANDROID_MEDIA_BN_RESOURCE_MANAGER_CLIENT_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BN_RESOURCE_MANAGER_CLIENT_H_

#include <binder/IInterface.h>
#include <android/media/IResourceManagerClient.h>

namespace android {

namespace media {

class BnResourceManagerClient : public ::android::BnInterface<IResourceManagerClient> {
public:
  explicit BnResourceManagerClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnResourceManagerClient

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BN_RESOURCE_MANAGER_CLIENT_H_
