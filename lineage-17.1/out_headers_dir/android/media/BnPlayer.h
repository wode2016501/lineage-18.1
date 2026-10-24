#pragma once

#include <binder/IInterface.h>
#include <android/media/IPlayer.h>
#include <android/media/BnPlayer.h>
#include <binder/Delegate.h>


namespace android {
namespace media {
class BnPlayer : public ::android::BnInterface<IPlayer> {
public:
  static constexpr uint32_t TRANSACTION_start = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_pause = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_stop = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_setVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_setPan = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setStartDelayMs = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_applyVolumeShaper = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  explicit BnPlayer();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnPlayer

class IPlayerDelegator : public BnPlayer {
public:
  explicit IPlayerDelegator(const ::android::sp<IPlayer> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IPlayer> getImpl() { return _aidl_delegate; }
  ::android::binder::Status start() override {
    return _aidl_delegate->start();
  }
  ::android::binder::Status pause() override {
    return _aidl_delegate->pause();
  }
  ::android::binder::Status stop() override {
    return _aidl_delegate->stop();
  }
  ::android::binder::Status setVolume(float vol) override {
    return _aidl_delegate->setVolume(vol);
  }
  ::android::binder::Status setPan(float pan) override {
    return _aidl_delegate->setPan(pan);
  }
  ::android::binder::Status setStartDelayMs(int32_t delayMs) override {
    return _aidl_delegate->setStartDelayMs(delayMs);
  }
  ::android::binder::Status applyVolumeShaper(const ::android::media::VolumeShaper::Configuration& configuration, const ::android::media::VolumeShaper::Operation& operation) override {
    return _aidl_delegate->applyVolumeShaper(configuration, operation);
  }
private:
  ::android::sp<IPlayer> _aidl_delegate;
};  // class IPlayerDelegator
}  // namespace media
}  // namespace android
