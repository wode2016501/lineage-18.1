#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothA2dpSinkCallback.h>
#include <android/bluetooth/BnBluetoothA2dpSinkCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothA2dpSinkCallback : public ::android::BnInterface<IBluetoothA2dpSinkCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_OnAudioState = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_OnAudioConfig = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnBluetoothA2dpSinkCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothA2dpSinkCallback

class IBluetoothA2dpSinkCallbackDelegator : public BnBluetoothA2dpSinkCallback {
public:
  explicit IBluetoothA2dpSinkCallbackDelegator(const ::android::sp<IBluetoothA2dpSinkCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothA2dpSinkCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnRegistered(int32_t status) override {
    return _aidl_delegate->OnRegistered(status);
  }
  ::android::binder::Status OnConnectionState(const ::android::String16& device_address, int32_t state) override {
    return _aidl_delegate->OnConnectionState(device_address, state);
  }
  ::android::binder::Status OnAudioState(const ::android::String16& device_address, int32_t state) override {
    return _aidl_delegate->OnAudioState(device_address, state);
  }
  ::android::binder::Status OnAudioConfig(const ::android::String16& device_address, int32_t sample_rate, int32_t channel_count) override {
    return _aidl_delegate->OnAudioConfig(device_address, sample_rate, channel_count);
  }
private:
  ::android::sp<IBluetoothA2dpSinkCallback> _aidl_delegate;
};  // class IBluetoothA2dpSinkCallbackDelegator
}  // namespace bluetooth
}  // namespace android
