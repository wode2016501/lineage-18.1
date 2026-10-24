#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothPbap.h>

namespace android {
namespace bluetooth {
class BpBluetoothPbap : public ::android::BpInterface<IBluetoothPbap> {
public:
  explicit BpBluetoothPbap(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothPbap() = default;
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device) override;
};  // class BpBluetoothPbap
}  // namespace bluetooth
}  // namespace android
