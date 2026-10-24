#pragma once

#include <binder/IInterface.h>
#include <android/media/IAudioRecord.h>
#include <android/media/BnAudioRecord.h>
#include <binder/Delegate.h>


namespace android {
namespace media {
class BnAudioRecord : public ::android::BnInterface<IAudioRecord> {
public:
  static constexpr uint32_t TRANSACTION_start = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_stop = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getActiveMicrophones = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_setPreferredMicrophoneDirection = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_setPreferredMicrophoneFieldDimension = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnAudioRecord();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAudioRecord

class IAudioRecordDelegator : public BnAudioRecord {
public:
  explicit IAudioRecordDelegator(const ::android::sp<IAudioRecord> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IAudioRecord> getImpl() { return _aidl_delegate; }
  ::android::binder::Status start(int32_t event, int32_t triggerSession) override {
    return _aidl_delegate->start(event, triggerSession);
  }
  ::android::binder::Status stop() override {
    return _aidl_delegate->stop();
  }
  ::android::binder::Status getActiveMicrophones(::std::vector<::android::media::MicrophoneInfo>* activeMicrophones) override {
    return _aidl_delegate->getActiveMicrophones(activeMicrophones);
  }
  ::android::binder::Status setPreferredMicrophoneDirection(int32_t direction) override {
    return _aidl_delegate->setPreferredMicrophoneDirection(direction);
  }
  ::android::binder::Status setPreferredMicrophoneFieldDimension(float zoom) override {
    return _aidl_delegate->setPreferredMicrophoneFieldDimension(zoom);
  }
private:
  ::android::sp<IAudioRecord> _aidl_delegate;
};  // class IAudioRecordDelegator
}  // namespace media
}  // namespace android
