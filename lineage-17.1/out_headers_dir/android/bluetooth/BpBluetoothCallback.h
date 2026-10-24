#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothCallback : public ::android::BpInterface<IBluetoothCallback> {
public:
  explicit BpBluetoothCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothCallback() = default;
  ::android::binder::Status OnBluetoothStateChange(int32_t prev_state, int32_t new_state) override;
  ::android::binder::Status OnScanEnableChanged(bool scan_enabled) override;
  ::android::binder::Status OnDeviceConnectionStateChanged(const ::android::String16& device_address, bool connected) override;
  ::android::binder::Status OnSspRequest(const ::android::String16& device_address, const ::android::String16& device_name, int32_t cod, int32_t pairing_variant, int32_t pass_key) override;
  ::android::binder::Status OnGetBondedDevices(int32_t status, const ::std::vector<::android::String16>& device_addresses) override;
  ::android::binder::Status OnBondStateChanged(int32_t status, const ::android::String16& device_address, int32_t state) override;
  ::android::binder::Status OnGetRemoteDeviceProperties(int32_t status, const ::android::String16& device_address, const ::android::bluetooth::BluetoothRemoteDeviceProps& props) override;
  ::android::binder::Status OnDeviceFound(const ::android::bluetooth::BluetoothRemoteDeviceProps& props) override;
};  // class BpBluetoothCallback
}  // namespace bluetooth
}  // namespace android
