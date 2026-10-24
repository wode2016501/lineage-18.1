#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothPan.h>

namespace android {
namespace bluetooth {
class BpBluetoothPan : public ::android::BpInterface<IBluetoothPan> {
public:
  explicit BpBluetoothPan(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothPan() = default;
  ::android::binder::Status isTetheringOn(bool* _aidl_return) override;
  ::android::binder::Status setBluetoothTethering(bool value, const ::android::String16& pkgName) override;
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
};  // class BpBluetoothPan
}  // namespace bluetooth
}  // namespace android
