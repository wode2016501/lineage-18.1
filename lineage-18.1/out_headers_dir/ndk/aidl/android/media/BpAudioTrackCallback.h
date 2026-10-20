#pragma once

#include "aidl/android/media/IAudioTrackCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpAudioTrackCallback : public ::ndk::BpCInterface<IAudioTrackCallback> {
public:
  BpAudioTrackCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpAudioTrackCallback();

  ::ndk::ScopedAStatus onCodecFormatChanged(const std::vector<int8_t>& in_audioMetadata) override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
