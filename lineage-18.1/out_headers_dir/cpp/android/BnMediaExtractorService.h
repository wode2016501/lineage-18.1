#ifndef AIDL_GENERATED_ANDROID_BN_MEDIA_EXTRACTOR_SERVICE_H_
#define AIDL_GENERATED_ANDROID_BN_MEDIA_EXTRACTOR_SERVICE_H_

#include <binder/IInterface.h>
#include <android/IMediaExtractorService.h>

namespace android {

class BnMediaExtractorService : public ::android::BnInterface<IMediaExtractorService> {
public:
  explicit BnMediaExtractorService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnMediaExtractorService

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BN_MEDIA_EXTRACTOR_SERVICE_H_
