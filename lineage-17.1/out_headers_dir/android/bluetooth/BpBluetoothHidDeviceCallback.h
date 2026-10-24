#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothHidDeviceCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothHidDeviceCallback : public ::android::BpInterface<IBluetoothHidDeviceCallback> {
public:
  explicit BpBluetoothHidDeviceCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothHidDeviceCallback() = default;
  ::android::binder::Status onAppStatusChanged(const ::android::bluetooth::BluetoothDevice& device, bool registered) override;
  ::android::binder::Status onConnectionStateChanged(const ::android::bluetooth::BluetoothDevice& device, int32_t state) override;
  ::android::binder::Status onGetReport(const ::android::bluetooth::BluetoothDevice& device, int8_t type, int8_t id, int32_t bufferSize) override;
  ::android::binder::Status onSetReport(const ::android::bluetooth::BluetoothDevice& device, int8_t type, int8_t id, const ::std::vector<uint8_t>& data) override;
  ::android::binder::Status onSetProtocol(const ::android::bluetooth::BluetoothDevice& device, int8_t protocol) override;
  ::android::binder::Status onInterruptData(const ::android::bluetooth::BluetoothDevice& device, int8_t reportId, const ::std::vector<uint8_t>& data) override;
  ::android::binder::Status onVirtualCableUnplug(const ::android::bluetooth::BluetoothDevice& device) override;
};  // class BpBluetoothHidDeviceCallback
}  // namespace bluetooth
}  // namespace android
