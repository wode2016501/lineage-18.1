#pragma once

#include <binder/IInterface.h>
#include <android/IGraphicBufferSource.h>
#include <android/BnGraphicBufferSource.h>
#include <binder/Delegate.h>


namespace android {
class BnGraphicBufferSource : public ::android::BnInterface<IGraphicBufferSource> {
public:
  static constexpr uint32_t TRANSACTION_configure = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_setSuspend = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_setRepeatPreviousFrameDelayUs = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_setMaxFps = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_setTimeLapseConfig = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setStartTimeUs = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_setStopTimeUs = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getStopTimeOffsetUs = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_setColorAspects = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_setTimeOffsetUs = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_signalEndOfInputStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  explicit BnGraphicBufferSource();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnGraphicBufferSource

class IGraphicBufferSourceDelegator : public BnGraphicBufferSource {
public:
  explicit IGraphicBufferSourceDelegator(const ::android::sp<IGraphicBufferSource> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IGraphicBufferSource> getImpl() { return _aidl_delegate; }
  ::android::binder::Status configure(const ::android::sp<::android::IOMXNode>& omxNode, int32_t dataSpace) override {
    return _aidl_delegate->configure(omxNode, dataSpace);
  }
  ::android::binder::Status setSuspend(bool suspend, int64_t suspendTimeUs) override {
    return _aidl_delegate->setSuspend(suspend, suspendTimeUs);
  }
  ::android::binder::Status setRepeatPreviousFrameDelayUs(int64_t repeatAfterUs) override {
    return _aidl_delegate->setRepeatPreviousFrameDelayUs(repeatAfterUs);
  }
  ::android::binder::Status setMaxFps(float maxFps) override {
    return _aidl_delegate->setMaxFps(maxFps);
  }
  ::android::binder::Status setTimeLapseConfig(double fps, double captureFps) override {
    return _aidl_delegate->setTimeLapseConfig(fps, captureFps);
  }
  ::android::binder::Status setStartTimeUs(int64_t startTimeUs) override {
    return _aidl_delegate->setStartTimeUs(startTimeUs);
  }
  ::android::binder::Status setStopTimeUs(int64_t stopTimeUs) override {
    return _aidl_delegate->setStopTimeUs(stopTimeUs);
  }
  ::android::binder::Status getStopTimeOffsetUs(int64_t* _aidl_return) override {
    return _aidl_delegate->getStopTimeOffsetUs(_aidl_return);
  }
  ::android::binder::Status setColorAspects(int32_t aspects) override {
    return _aidl_delegate->setColorAspects(aspects);
  }
  ::android::binder::Status setTimeOffsetUs(int64_t timeOffsetsUs) override {
    return _aidl_delegate->setTimeOffsetUs(timeOffsetsUs);
  }
  ::android::binder::Status signalEndOfInputStream() override {
    return _aidl_delegate->signalEndOfInputStream();
  }
private:
  ::android::sp<IGraphicBufferSource> _aidl_delegate;
};  // class IGraphicBufferSourceDelegator
}  // namespace android
