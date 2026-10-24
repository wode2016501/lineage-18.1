#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothPbap.h>
#include <android/bluetooth/BnBluetoothPbap.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothPbap : public ::android::BnInterface<IBluetoothPbap> {
public:
  static constexpr uint32_t TRANSACTION_getConnectedDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getDevicesMatchingConnectionStates = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnBluetoothPbap();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothPbap

class IBluetoothPbapDelegator : public BnBluetoothPbap {
public:
  explicit IBluetoothPbapDelegator(const ::android::sp<IBluetoothPbap> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothPbap> getImpl() { return _aidl_delegate; }
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override {
    return _aidl_delegate->getConnectedDevices(_aidl_return);
  }
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override {
    return _aidl_delegate->getDevicesMatchingConnectionStates(states, _aidl_return);
  }
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getConnectionState(device, _aidl_return);
  }
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device) override {
    return _aidl_delegate->disconnect(device);
  }
private:
  ::android::sp<IBluetoothPbap> _aidl_delegate;
};  // class IBluetoothPbapDelegator
}  // namespace bluetooth
}  // namespace android
