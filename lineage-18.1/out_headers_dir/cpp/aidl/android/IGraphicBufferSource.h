#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/IOMXNode.h>

namespace aidl {
namespace android {
class IGraphicBufferSource : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IGraphicBufferSource();
  virtual ~IGraphicBufferSource();



  static std::shared_ptr<IGraphicBufferSource> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IGraphicBufferSource>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IGraphicBufferSource>* instance);
  static bool setDefaultImpl(std::shared_ptr<IGraphicBufferSource> impl);
  static const std::shared_ptr<IGraphicBufferSource>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus configure(const std::shared_ptr<::aidl::android::IOMXNode>& in_omxNode, int32_t in_dataSpace) = 0;
  virtual ::ndk::ScopedAStatus setSuspend(bool in_suspend, int64_t in_suspendTimeUs) = 0;
  virtual ::ndk::ScopedAStatus setRepeatPreviousFrameDelayUs(int64_t in_repeatAfterUs) = 0;
  virtual ::ndk::ScopedAStatus setMaxFps(float in_maxFps) = 0;
  virtual ::ndk::ScopedAStatus setTimeLapseConfig(double in_fps, double in_captureFps) = 0;
  virtual ::ndk::ScopedAStatus setStartTimeUs(int64_t in_startTimeUs) = 0;
  virtual ::ndk::ScopedAStatus setStopTimeUs(int64_t in_stopTimeUs) = 0;
  virtual ::ndk::ScopedAStatus getStopTimeOffsetUs(int64_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setColorAspects(int32_t in_aspects) = 0;
  virtual ::ndk::ScopedAStatus setTimeOffsetUs(int64_t in_timeOffsetsUs) = 0;
  virtual ::ndk::ScopedAStatus signalEndOfInputStream() = 0;
private:
  static std::shared_ptr<IGraphicBufferSource> default_impl;
};
class IGraphicBufferSourceDefault : public IGraphicBufferSource {
public:
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
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace android
}  // namespace aidl
