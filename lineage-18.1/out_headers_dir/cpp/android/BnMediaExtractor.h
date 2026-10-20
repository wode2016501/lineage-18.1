#ifndef AIDL_GENERATED_ANDROID_BN_MEDIA_EXTRACTOR_H_
#define AIDL_GENERATED_ANDROID_BN_MEDIA_EXTRACTOR_H_

#include <binder/IInterface.h>
#include <android/IMediaExtractor.h>

namespace android {

class BnMediaExtractor : public ::android::BnInterface<IMediaExtractor> {
public:
  explicit BnMediaExtractor();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnMediaExtractor

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BN_MEDIA_EXTRACTOR_H_
