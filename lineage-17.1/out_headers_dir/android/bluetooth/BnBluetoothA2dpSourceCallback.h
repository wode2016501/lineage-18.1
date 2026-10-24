#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothA2dpSourceCallback.h>
#include <android/bluetooth/BnBluetoothA2dpSourceCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothA2dpSourceCallback : public ::android::BnInterface<IBluetoothA2dpSourceCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_OnAudioState = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_OnAudioConfig = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnBluetoothA2dpSourceCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothA2dpSourceCallback

class IBluetoothA2dpSourceCallbackDelegator : public BnBluetoothA2dpSourceCallback {
public:
  explicit IBluetoothA2dpSourceCallbackDelegator(const ::android::sp<IBluetoothA2dpSourceCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothA2dpSourceCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnRegistered(int32_t status) override {
    return _aidl_delegate->OnRegistered(status);
  }
  ::android::binder::Status OnConnectionState(const ::android::String16& device_address, int32_t state) override {
    return _aidl_delegate->OnConnectionState(device_address, state);
  }
  ::android::binder::Status OnAudioState(const ::android::String16& device_address, int32_t state) override {
    return _aidl_delegate->OnAudioState(device_address, state);
  }
  ::android::binder::Status OnAudioConfig(const ::android::String16& device_address, const ::android::bluetooth::BluetoothA2dpCodecConfig& codec_config, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codecs_local_capabilities, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codecs_selectable_capabilities) override {
    return _aidl_delegate->OnAudioConfig(device_address, codec_config, codecs_local_capabilities, codecs_selectable_capabilities);
  }
private:
  ::android::sp<IBluetoothA2dpSourceCallback> _aidl_delegate;
};  // class IBluetoothA2dpSourceCallbackDelegator
}  // namespace bluetooth
}  // namespace android
