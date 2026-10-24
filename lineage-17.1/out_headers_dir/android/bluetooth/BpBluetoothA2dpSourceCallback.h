#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothA2dpSourceCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothA2dpSourceCallback : public ::android::BpInterface<IBluetoothA2dpSourceCallback> {
public:
  explicit BpBluetoothA2dpSourceCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothA2dpSourceCallback() = default;
  ::android::binder::Status OnRegistered(int32_t status) override;
  ::android::binder::Status OnConnectionState(const ::android::String16& device_address, int32_t state) override;
  ::android::binder::Status OnAudioState(const ::android::String16& device_address, int32_t state) override;
  ::android::binder::Status OnAudioConfig(const ::android::String16& device_address, const ::android::bluetooth::BluetoothA2dpCodecConfig& codec_config, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codecs_local_capabilities, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codecs_selectable_capabilities) override;
};  // class BpBluetoothA2dpSourceCallback
}  // namespace bluetooth
}  // namespace android
