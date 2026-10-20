#ifndef AIDL_GENERATED_ANDROID_MEDIA_BN_MEDIA_TRANSCODING_SERVICE_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BN_MEDIA_TRANSCODING_SERVICE_H_

#include <binder/IInterface.h>
#include <android/media/IMediaTranscodingService.h>

namespace android {

namespace media {

class BnMediaTranscodingService : public ::android::BnInterface<IMediaTranscodingService> {
public:
  explicit BnMediaTranscodingService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnMediaTranscodingService

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BN_MEDIA_TRANSCODING_SERVICE_H_
