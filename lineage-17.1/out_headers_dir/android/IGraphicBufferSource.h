#pragma once

#include <android/IOMXNode.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {
class IOMXNode;
}  // namespace android
namespace android {
class IGraphicBufferSourceDelegator;

class IGraphicBufferSource : public ::android::IInterface {
public:
  typedef IGraphicBufferSourceDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(GraphicBufferSource)
  virtual ::android::binder::Status configure(const ::android::sp<::android::IOMXNode>& omxNode, int32_t dataSpace) = 0;
  virtual ::android::binder::Status setSuspend(bool suspend, int64_t suspendTimeUs) = 0;
  virtual ::android::binder::Status setRepeatPreviousFrameDelayUs(int64_t repeatAfterUs) = 0;
  virtual ::android::binder::Status setMaxFps(float maxFps) = 0;
  virtual ::android::binder::Status setTimeLapseConfig(double fps, double captureFps) = 0;
  virtual ::android::binder::Status setStartTimeUs(int64_t startTimeUs) = 0;
  virtual ::android::binder::Status setStopTimeUs(int64_t stopTimeUs) = 0;
  virtual ::android::binder::Status getStopTimeOffsetUs(int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status setColorAspects(int32_t aspects) = 0;
  virtual ::android::binder::Status setTimeOffsetUs(int64_t timeOffsetsUs) = 0;
  virtual ::android::binder::Status signalEndOfInputStream() = 0;
};  // class IGraphicBufferSource

class IGraphicBufferSourceDefault : public IGraphicBufferSource {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status configure(const ::android::sp<::android::IOMXNode>& /*omxNode*/, int32_t /*dataSpace*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setSuspend(bool /*suspend*/, int64_t /*suspendTimeUs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setRepeatPreviousFrameDelayUs(int64_t /*repeatAfterUs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setMaxFps(float /*maxFps*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setTimeLapseConfig(double /*fps*/, double /*captureFps*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setStartTimeUs(int64_t /*startTimeUs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setStopTimeUs(int64_t /*stopTimeUs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getStopTimeOffsetUs(int64_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setColorAspects(int32_t /*aspects*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setTimeOffsetUs(int64_t /*timeOffsetsUs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status signalEndOfInputStream() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IGraphicBufferSourceDefault
}  // namespace android
