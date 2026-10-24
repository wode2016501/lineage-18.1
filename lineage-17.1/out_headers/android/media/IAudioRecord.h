#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <media/MicrophoneInfo.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace media {
class IAudioRecordDelegator;

class IAudioRecord : public ::android::IInterface {
public:
  typedef IAudioRecordDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(AudioRecord)
  virtual ::android::binder::Status start(int32_t event, int32_t triggerSession) = 0;
  virtual ::android::binder::Status stop() = 0;
  virtual ::android::binder::Status getActiveMicrophones(::std::vector<::android::media::MicrophoneInfo>* activeMicrophones) = 0;
  virtual ::android::binder::Status setPreferredMicrophoneDirection(int32_t direction) = 0;
  virtual ::android::binder::Status setPreferredMicrophoneFieldDimension(float zoom) = 0;
};  // class IAudioRecord

class IAudioRecordDefault : public IAudioRecord {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status start(int32_t /*event*/, int32_t /*triggerSession*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stop() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getActiveMicrophones(::std::vector<::android::media::MicrophoneInfo>* /*activeMicrophones*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPreferredMicrophoneDirection(int32_t /*direction*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPreferredMicrophoneFieldDimension(float /*zoom*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAudioRecordDefault
}  // namespace media
}  // namespace android
