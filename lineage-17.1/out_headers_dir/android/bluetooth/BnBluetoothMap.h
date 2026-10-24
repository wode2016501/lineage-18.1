#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothMap.h>
#include <android/bluetooth/BnBluetoothMap.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothMap : public ::android::BnInterface<IBluetoothMap> {
public:
  static constexpr uint32_t TRANSACTION_getState = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getClient = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_isConnected = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getConnectedDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getDevicesMatchingConnectionStates = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_setPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  explicit BnBluetoothMap();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothMap

class IBluetoothMapDelegator : public BnBluetoothMap {
public:
  explicit IBluetoothMapDelegator(const ::android::sp<IBluetoothMap> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothMap> getImpl() { return _aidl_delegate; }
  ::android::binder::Status getState(int32_t* _aidl_return) override {
    return _aidl_delegate->getState(_aidl_return);
  }
  ::android::binder::Status getClient(::android::bluetooth::BluetoothDevice* _aidl_return) override {
    return _aidl_delegate->getClient(_aidl_return);
  }
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->connect(device, _aidl_return);
  }
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->disconnect(device, _aidl_return);
  }
  ::android::binder::Status isConnected(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->isConnected(device, _aidl_return);
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
  ::android::sp<IBluetoothMap> _aidl_delegate;
};  // class IBluetoothMapDelegator
}  // namespace bluetooth
}  // namespace android
