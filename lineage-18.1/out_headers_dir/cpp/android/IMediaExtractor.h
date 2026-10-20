#ifndef AIDL_GENERATED_ANDROID_I_MEDIA_EXTRACTOR_H_
#define AIDL_GENERATED_ANDROID_I_MEDIA_EXTRACTOR_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

class IMediaExtractor : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(MediaExtractor)
};  // class IMediaExtractor

class IMediaExtractorDefault : public IMediaExtractor {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
};  // class IMediaExtractorDefault

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_I_MEDIA_EXTRACTOR_H_
