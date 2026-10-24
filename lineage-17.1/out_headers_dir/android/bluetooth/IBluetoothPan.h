#pragma once

#include <android/bluetooth/bluetooth_device.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace bluetooth {
class IBluetoothPanDelegator;

class IBluetoothPan : public ::android::IInterface {
public:
  typedef IBluetoothPanDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothPan)
  virtual ::android::binder::Status isTetheringOn(bool* _aidl_return) = 0;
  virtual ::android::binder::Status setBluetoothTethering(bool value, const ::android::String16& pkgName) = 0;
  virtual ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
};  // class IBluetoothPan

class IBluetoothPanDefault : public IBluetoothPan {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status isTetheringOn(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setBluetoothTethering(bool /*value*/, const ::android::String16& /*pkgName*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
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
};  // class IBluetoothPanDefault
}  // namespace bluetooth
}  // namespace android
