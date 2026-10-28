#pragma once

#include "aidl/android/media/IAudioTrackCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnAudioTrackCallback : public ::ndk::BnCInterface<IAudioTrackCallback> {
public:
  BnAudioTrackCallback();
  virtual ~BnAudioTrackCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
