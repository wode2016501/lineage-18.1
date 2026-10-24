#pragma once

#include <android/bluetooth/bluetooth_a2dp_codec_config.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace bluetooth {
class IBluetoothA2dpSourceCallbackDelegator;

class IBluetoothA2dpSourceCallback : public ::android::IInterface {
public:
  typedef IBluetoothA2dpSourceCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothA2dpSourceCallback)
  virtual ::android::binder::Status OnRegistered(int32_t status) = 0;
  virtual ::android::binder::Status OnConnectionState(const ::android::String16& device_address, int32_t state) = 0;
  virtual ::android::binder::Status OnAudioState(const ::android::String16& device_address, int32_t state) = 0;
  virtual ::android::binder::Status OnAudioConfig(const ::android::String16& device_address, const ::android::bluetooth::BluetoothA2dpCodecConfig& codec_config, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codecs_local_capabilities, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codecs_selectable_capabilities) = 0;
};  // class IBluetoothA2dpSourceCallback

class IBluetoothA2dpSourceCallbackDefault : public IBluetoothA2dpSourceCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnRegistered(int32_t /*status*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnConnectionState(const ::android::String16& /*device_address*/, int32_t /*state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnAudioState(const ::android::String16& /*device_address*/, int32_t /*state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnAudioConfig(const ::android::String16& /*device_address*/, const ::android::bluetooth::BluetoothA2dpCodecConfig& /*codec_config*/, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& /*codecs_local_capabilities*/, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& /*codecs_selectable_capabilities*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothA2dpSourceCallbackDefault
}  // namespace bluetooth
}  // namespace android
