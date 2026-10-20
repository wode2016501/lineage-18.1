#ifndef AIDL_GENERATED_ANDROID_MEDIA_BN_CAPTURE_STATE_LISTENER_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BN_CAPTURE_STATE_LISTENER_H_

#include <binder/IInterface.h>
#include <android/media/ICaptureStateListener.h>

namespace android {

namespace media {

class BnCaptureStateListener : public ::android::BnInterface<ICaptureStateListener> {
public:
  explicit BnCaptureStateListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCaptureStateListener

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BN_CAPTURE_STATE_LISTENER_H_
