#pragma once

#include "aidl/android/IGraphicBufferSource.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
class BpGraphicBufferSource : public ::ndk::BpCInterface<IGraphicBufferSource> {
public:
  BpGraphicBufferSource(const ::ndk::SpAIBinder& binder);
  virtual ~BpGraphicBufferSource();

  ::ndk::ScopedAStatus configure(const std::shared_ptr<::aidl::android::IOMXNode>& in_omxNode, int32_t in_dataSpace) override;
  ::ndk::ScopedAStatus setSuspend(bool in_suspend, int64_t in_suspendTimeUs) override;
  ::ndk::ScopedAStatus setRepeatPreviousFrameDelayUs(int64_t in_repeatAfterUs) override;
  ::ndk::ScopedAStatus setMaxFps(float in_maxFps) override;
  ::ndk::ScopedAStatus setTimeLapseConfig(double in_fps, double in_captureFps) override;
  ::ndk::ScopedAStatus setStartTimeUs(int64_t in_startTimeUs) override;
  ::ndk::ScopedAStatus setStopTimeUs(int64_t in_stopTimeUs) override;
  ::ndk::ScopedAStatus getStopTimeOffsetUs(int64_t* _aidl_return) override;
  ::ndk::ScopedAStatus setColorAspects(int32_t in_aspects) override;
  ::ndk::ScopedAStatus setTimeOffsetUs(int64_t in_timeOffsetsUs) override;
  ::ndk::ScopedAStatus signalEndOfInputStream() override;
};
}  // namespace android
}  // namespace aidl
