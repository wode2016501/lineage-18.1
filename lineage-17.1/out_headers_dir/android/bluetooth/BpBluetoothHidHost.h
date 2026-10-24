#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothHidHost.h>

namespace android {
namespace bluetooth {
class BpBluetoothHidHost : public ::android::BpInterface<IBluetoothHidHost> {
public:
  explicit BpBluetoothHidHost(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothHidHost() = default;
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) override;
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status getProtocolMode(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status virtualUnplug(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status setProtocolMode(const ::android::bluetooth::BluetoothDevice& device, int32_t protocolMode, bool* _aidl_return) override;
  ::android::binder::Status getReport(const ::android::bluetooth::BluetoothDevice& device, int8_t reportType, int8_t reportId, int32_t bufferSize, bool* _aidl_return) override;
  ::android::binder::Status setReport(const ::android::bluetooth::BluetoothDevice& device, int8_t reportType, const ::android::String16& report, bool* _aidl_return) override;
  ::android::binder::Status sendData(const ::android::bluetooth::BluetoothDevice& device, const ::android::String16& report, bool* _aidl_return) override;
  ::android::binder::Status getIdleTime(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status setIdleTime(const ::android::bluetooth::BluetoothDevice& device, int8_t idleTime, bool* _aidl_return) override;
};  // class BpBluetoothHidHost
}  // namespace bluetooth
}  // namespace android
