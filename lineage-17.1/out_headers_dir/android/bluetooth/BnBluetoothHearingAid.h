#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothHearingAid.h>
#include <android/bluetooth/BnBluetoothHearingAid.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothHearingAid : public ::android::BnInterface<IBluetoothHearingAid> {
public:
  static constexpr uint32_t TRANSACTION_connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getConnectedDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getDevicesMatchingConnectionStates = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_setActiveDevice = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getActiveDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_setPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_getPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_adjustVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_setVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_getHiSyncId = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_getDeviceSide = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_getDeviceMode = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  explicit BnBluetoothHearingAid();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothHearingAid

class IBluetoothHearingAidDelegator : public BnBluetoothHearingAid {
public:
  explicit IBluetoothHearingAidDelegator(const ::android::sp<IBluetoothHearingAid> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothHearingAid> getImpl() { return _aidl_delegate; }
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
  ::android::binder::Status setActiveDevice(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->setActiveDevice(device, _aidl_return);
  }
  ::android::binder::Status getActiveDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override {
    return _aidl_delegate->getActiveDevices(_aidl_return);
  }
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) override {
    return _aidl_delegate->setPriority(device, priority, _aidl_return);
  }
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getPriority(device, _aidl_return);
  }
  ::android::binder::Status adjustVolume(int32_t direction) override {
    return _aidl_delegate->adjustVolume(direction);
  }
  ::android::binder::Status setVolume(int32_t volume) override {
    return _aidl_delegate->setVolume(volume);
  }
  ::android::binder::Status getVolume(int32_t* _aidl_return) override {
    return _aidl_delegate->getVolume(_aidl_return);
  }
  ::android::binder::Status getHiSyncId(const ::android::bluetooth::BluetoothDevice& device, int64_t* _aidl_return) override {
    return _aidl_delegate->getHiSyncId(device, _aidl_return);
  }
  ::android::binder::Status getDeviceSide(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getDeviceSide(device, _aidl_return);
  }
  ::android::binder::Status getDeviceMode(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getDeviceMode(device, _aidl_return);
  }
private:
  ::android::sp<IBluetoothHearingAid> _aidl_delegate;
};  // class IBluetoothHearingAidDelegator
}  // namespace bluetooth
}  // namespace android
