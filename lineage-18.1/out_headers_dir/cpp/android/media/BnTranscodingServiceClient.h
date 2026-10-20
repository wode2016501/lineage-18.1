#ifndef AIDL_GENERATED_ANDROID_MEDIA_BN_TRANSCODING_SERVICE_CLIENT_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BN_TRANSCODING_SERVICE_CLIENT_H_

#include <binder/IInterface.h>
#include <android/media/ITranscodingServiceClient.h>

namespace android {

namespace media {

class BnTranscodingServiceClient : public ::android::BnInterface<ITranscodingServiceClient> {
public:
  explicit BnTranscodingServiceClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnTranscodingServiceClient

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BN_TRANSCODING_SERVICE_CLIENT_H_
