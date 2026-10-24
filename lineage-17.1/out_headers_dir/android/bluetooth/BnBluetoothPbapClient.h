#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothPbapClient.h>
#include <android/bluetooth/BnBluetoothPbapClient.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothPbapClient : public ::android::BnInterface<IBluetoothPbapClient> {
public:
  static constexpr uint32_t TRANSACTION_connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getConnectedDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getDevicesMatchingConnectionStates = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  explicit BnBluetoothPbapClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothPbapClient

class IBluetoothPbapClientDelegator : public BnBluetoothPbapClient {
public:
  explicit IBluetoothPbapClientDelegator(const ::android::sp<IBluetoothPbapClient> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothPbapClient> getImpl() { return _aidl_delegate; }
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->connect(device, _aidl_return);
  }
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->disconnect(device, _aidl_return);
  }
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override {
    return _aidl_delegate->getConnectedDevices(_aidl_return);
  }
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override {
    return _aidl_delegate->getDevicesMatchingConnectionStates(states, _aidl_return);
  }
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getConnectionState(device, _aidl_return);
  }
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) override {
    return _aidl_delegate->setPriority(device, priority, _aidl_return);
  }
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getPriority(device, _aidl_return);
  }
private:
  ::android::sp<IBluetoothPbapClient> _aidl_delegate;
};  // class IBluetoothPbapClientDelegator
}  // namespace bluetooth
}  // namespace android
