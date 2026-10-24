#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothA2dpSink.h>

namespace android {
namespace bluetooth {
class BpBluetoothA2dpSink : public ::android::BpInterface<IBluetoothA2dpSink> {
public:
  explicit BpBluetoothA2dpSink(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothA2dpSink() = default;
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothA2dpSinkCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status Unregister() override;
  ::android::binder::Status Enable(bool* _aidl_return) override;
  ::android::binder::Status Disable(bool* _aidl_return) override;
  ::android::binder::Status Connect(const ::android::String16& device_address, bool* _aidl_return) override;
  ::android::binder::Status Disconnect(const ::android::String16& device_address, bool* _aidl_return) override;
  ::android::binder::Status SetAudioFocusState(int32_t state, bool* _aidl_return) override;
  ::android::binder::Status SetAudioTrackGain(float gain, bool* _aidl_return) override;
};  // class BpBluetoothA2dpSink
}  // namespace bluetooth
}  // namespace android
