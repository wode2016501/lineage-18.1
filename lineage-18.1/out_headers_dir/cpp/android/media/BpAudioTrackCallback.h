#ifndef AIDL_GENERATED_ANDROID_MEDIA_BP_AUDIO_TRACK_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BP_AUDIO_TRACK_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/IAudioTrackCallback.h>

namespace android {

namespace media {

class BpAudioTrackCallback : public ::android::BpInterface<IAudioTrackCallback> {
public:
  explicit BpAudioTrackCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAudioTrackCallback() = default;
  ::android::binder::Status onCodecFormatChanged(const ::std::vector<uint8_t>& audioMetadata) override;
};  // class BpAudioTrackCallback

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BP_AUDIO_TRACK_CALLBACK_H_
