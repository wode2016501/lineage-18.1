#ifndef AIDL_GENERATED_ANDROID_BP_MEDIA_EXTRACTOR_H_
#define AIDL_GENERATED_ANDROID_BP_MEDIA_EXTRACTOR_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/IMediaExtractor.h>

namespace android {

class BpMediaExtractor : public ::android::BpInterface<IMediaExtractor> {
public:
  explicit BpMediaExtractor(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpMediaExtractor() = default;
};  // class BpMediaExtractor

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BP_MEDIA_EXTRACTOR_H_
