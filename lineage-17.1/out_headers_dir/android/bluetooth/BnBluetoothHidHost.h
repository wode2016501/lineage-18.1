#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothHidHost.h>
#include <android/bluetooth/BnBluetoothHidHost.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothHidHost : public ::android::BnInterface<IBluetoothHidHost> {
public:
  static constexpr uint32_t TRANSACTION_connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getConnectedDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getDevicesMatchingConnectionStates = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getProtocolMode = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_virtualUnplug = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_setProtocolMode = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_setReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_sendData = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_getIdleTime = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_setIdleTime = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  explicit BnBluetoothHidHost();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothHidHost

class IBluetoothHidHostDelegator : public BnBluetoothHidHost {
public:
  explicit IBluetoothHidHostDelegator(const ::android::sp<IBluetoothHidHost> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothHidHost> getImpl() { return _aidl_delegate; }
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
  ::android::binder::Status getProtocolMode(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->getProtocolMode(device, _aidl_return);
  }
  ::android::binder::Status virtualUnplug(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->virtualUnplug(device, _aidl_return);
  }
  ::android::binder::Status setProtocolMode(const ::android::bluetooth::BluetoothDevice& device, int32_t protocolMode, bool* _aidl_return) override {
    return _aidl_delegate->setProtocolMode(device, protocolMode, _aidl_return);
  }
  ::android::binder::Status getReport(const ::android::bluetooth::BluetoothDevice& device, int8_t reportType, int8_t reportId, int32_t bufferSize, bool* _aidl_return) override {
    return _aidl_delegate->getReport(device, reportType, reportId, bufferSize, _aidl_return);
  }
  ::android::binder::Status setReport(const ::android::bluetooth::BluetoothDevice& device, int8_t reportType, const ::android::String16& report, bool* _aidl_return) override {
    return _aidl_delegate->setReport(device, reportType, report, _aidl_return);
  }
  ::android::binder::Status sendData(const ::android::bluetooth::BluetoothDevice& device, const ::android::String16& report, bool* _aidl_return) override {
    return _aidl_delegate->sendData(device, report, _aidl_return);
  }
  ::android::binder::Status getIdleTime(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->getIdleTime(device, _aidl_return);
  }
  ::android::binder::Status setIdleTime(const ::android::bluetooth::BluetoothDevice& device, int8_t idleTime, bool* _aidl_return) override {
    return _aidl_delegate->setIdleTime(device, idleTime, _aidl_return);
  }
private:
  ::android::sp<IBluetoothHidHost> _aidl_delegate;
};  // class IBluetoothHidHostDelegator
}  // namespace bluetooth
}  // namespace android
