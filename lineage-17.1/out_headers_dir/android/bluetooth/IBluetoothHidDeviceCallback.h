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
class IBluetoothHidDeviceCallbackDelegator;

class IBluetoothHidDeviceCallback : public ::android::IInterface {
public:
  typedef IBluetoothHidDeviceCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothHidDeviceCallback)
  virtual ::android::binder::Status onAppStatusChanged(const ::android::bluetooth::BluetoothDevice& device, bool registered) = 0;
  virtual ::android::binder::Status onConnectionStateChanged(const ::android::bluetooth::BluetoothDevice& device, int32_t state) = 0;
  virtual ::android::binder::Status onGetReport(const ::android::bluetooth::BluetoothDevice& device, int8_t type, int8_t id, int32_t bufferSize) = 0;
  virtual ::android::binder::Status onSetReport(const ::android::bluetooth::BluetoothDevice& device, int8_t type, int8_t id, const ::std::vector<uint8_t>& data) = 0;
  virtual ::android::binder::Status onSetProtocol(const ::android::bluetooth::BluetoothDevice& device, int8_t protocol) = 0;
  virtual ::android::binder::Status onInterruptData(const ::android::bluetooth::BluetoothDevice& device, int8_t reportId, const ::std::vector<uint8_t>& data) = 0;
  virtual ::android::binder::Status onVirtualCableUnplug(const ::android::bluetooth::BluetoothDevice& device) = 0;
};  // class IBluetoothHidDeviceCallback

class IBluetoothHidDeviceCallbackDefault : public IBluetoothHidDeviceCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onAppStatusChanged(const ::android::bluetooth::BluetoothDevice& /*device*/, bool /*registered*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onConnectionStateChanged(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t /*state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onGetReport(const ::android::bluetooth::BluetoothDevice& /*device*/, int8_t /*type*/, int8_t /*id*/, int32_t /*bufferSize*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onSetReport(const ::android::bluetooth::BluetoothDevice& /*device*/, int8_t /*type*/, int8_t /*id*/, const ::std::vector<uint8_t>& /*data*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onSetProtocol(const ::android::bluetooth::BluetoothDevice& /*device*/, int8_t /*protocol*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onInterruptData(const ::android::bluetooth::BluetoothDevice& /*device*/, int8_t /*reportId*/, const ::std::vector<uint8_t>& /*data*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onVirtualCableUnplug(const ::android::bluetooth::BluetoothDevice& /*device*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothHidDeviceCallbackDefault
}  // namespace bluetooth
}  // namespace android
