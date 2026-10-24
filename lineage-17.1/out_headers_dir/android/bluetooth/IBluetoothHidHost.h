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
class IBluetoothHidHostDelegator;

class IBluetoothHidHost : public ::android::IInterface {
public:
  typedef IBluetoothHidHostDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothHidHost)
  virtual ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getProtocolMode(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status virtualUnplug(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setProtocolMode(const ::android::bluetooth::BluetoothDevice& device, int32_t protocolMode, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getReport(const ::android::bluetooth::BluetoothDevice& device, int8_t reportType, int8_t reportId, int32_t bufferSize, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setReport(const ::android::bluetooth::BluetoothDevice& device, int8_t reportType, const ::android::String16& report, bool* _aidl_return) = 0;
  virtual ::android::binder::Status sendData(const ::android::bluetooth::BluetoothDevice& device, const ::android::String16& report, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getIdleTime(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setIdleTime(const ::android::bluetooth::BluetoothDevice& device, int8_t idleTime, bool* _aidl_return) = 0;
};  // class IBluetoothHidHost

class IBluetoothHidHostDefault : public IBluetoothHidHost {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
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
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t /*priority*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getProtocolMode(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status virtualUnplug(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setProtocolMode(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t /*protocolMode*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getReport(const ::android::bluetooth::BluetoothDevice& /*device*/, int8_t /*reportType*/, int8_t /*reportId*/, int32_t /*bufferSize*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setReport(const ::android::bluetooth::BluetoothDevice& /*device*/, int8_t /*reportType*/, const ::android::String16& /*report*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status sendData(const ::android::bluetooth::BluetoothDevice& /*device*/, const ::android::String16& /*report*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getIdleTime(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setIdleTime(const ::android::bluetooth::BluetoothDevice& /*device*/, int8_t /*idleTime*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothHidHostDefault
}  // namespace bluetooth
}  // namespace android
