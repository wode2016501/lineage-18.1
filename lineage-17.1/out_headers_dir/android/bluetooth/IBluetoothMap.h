#pragma once

#include <android/bluetooth/bluetooth_device.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace bluetooth {
class IBluetoothMapDelegator;

class IBluetoothMap : public ::android::IInterface {
public:
  typedef IBluetoothMapDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothMap)
  virtual ::android::binder::Status getState(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getClient(::android::bluetooth::BluetoothDevice* _aidl_return) = 0;
  virtual ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isConnected(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
};  // class IBluetoothMap

class IBluetoothMapDefault : public IBluetoothMap {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getState(int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getClient(::android::bluetooth::BluetoothDevice* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isConnected(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& /*states*/, ::std::vector<::android::bluetooth::BluetoothDevice>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t /*priority*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothMapDefault
}  // namespace bluetooth
}  // namespace android
