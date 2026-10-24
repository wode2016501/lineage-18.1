#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothMap.h>

namespace android {
namespace bluetooth {
class BpBluetoothMap : public ::android::BpInterface<IBluetoothMap> {
public:
  explicit BpBluetoothMap(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothMap() = default;
  ::android::binder::Status getState(int32_t* _aidl_return) override;
  ::android::binder::Status getClient(::android::bluetooth::BluetoothDevice* _aidl_return) override;
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status isConnected(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) override;
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
};  // class BpBluetoothMap
}  // namespace bluetooth
}  // namespace android
