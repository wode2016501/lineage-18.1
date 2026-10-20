#ifndef AIDL_GENERATED_ANDROID_MEDIA_BN_AUDIO_TRACK_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BN_AUDIO_TRACK_CALLBACK_H_

#include <binder/IInterface.h>
#include <android/media/IAudioTrackCallback.h>

namespace android {

namespace media {

class BnAudioTrackCallback : public ::android::BnInterface<IAudioTrackCallback> {
public:
  explicit BnAudioTrackCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAudioTrackCallback

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BN_AUDIO_TRACK_CALLBACK_H_
