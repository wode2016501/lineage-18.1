#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothA2dpSource.h>

namespace android {
namespace bluetooth {
class BpBluetoothA2dpSource : public ::android::BpInterface<IBluetoothA2dpSource> {
public:
  explicit BpBluetoothA2dpSource(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothA2dpSource() = default;
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothA2dpSourceCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status Unregister() override;
  ::android::binder::Status Enable(const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codec_priorities, bool* _aidl_return) override;
  ::android::binder::Status Disable(bool* _aidl_return) override;
  ::android::binder::Status Connect(const ::android::String16& device_address, bool* _aidl_return) override;
  ::android::binder::Status Disconnect(const ::android::String16& device_address, bool* _aidl_return) override;
  ::android::binder::Status ConfigCodec(const ::android::String16& device_address, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codec_preferences, bool* _aidl_return) override;
};  // class BpBluetoothA2dpSource
}  // namespace bluetooth
}  // namespace android
