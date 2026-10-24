#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothHidDeviceCallback.h>
#include <android/bluetooth/BnBluetoothHidDeviceCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothHidDeviceCallback : public ::android::BnInterface<IBluetoothHidDeviceCallback> {
public:
  static constexpr uint32_t TRANSACTION_onAppStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onConnectionStateChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onGetReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onSetReport = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onSetProtocol = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onInterruptData = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onVirtualCableUnplug = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  explicit BnBluetoothHidDeviceCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothHidDeviceCallback

class IBluetoothHidDeviceCallbackDelegator : public BnBluetoothHidDeviceCallback {
public:
  explicit IBluetoothHidDeviceCallbackDelegator(const ::android::sp<IBluetoothHidDeviceCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothHidDeviceCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onAppStatusChanged(const ::android::bluetooth::BluetoothDevice& device, bool registered) override {
    return _aidl_delegate->onAppStatusChanged(device, registered);
  }
  ::android::binder::Status onConnectionStateChanged(const ::android::bluetooth::BluetoothDevice& device, int32_t state) override {
    return _aidl_delegate->onConnectionStateChanged(device, state);
  }
  ::android::binder::Status onGetReport(const ::android::bluetooth::BluetoothDevice& device, int8_t type, int8_t id, int32_t bufferSize) override {
    return _aidl_delegate->onGetReport(device, type, id, bufferSize);
  }
  ::android::binder::Status onSetReport(const ::android::bluetooth::BluetoothDevice& device, int8_t type, int8_t id, const ::std::vector<uint8_t>& data) override {
    return _aidl_delegate->onSetReport(device, type, id, data);
  }
  ::android::binder::Status onSetProtocol(const ::android::bluetooth::BluetoothDevice& device, int8_t protocol) override {
    return _aidl_delegate->onSetProtocol(device, protocol);
  }
  ::android::binder::Status onInterruptData(const ::android::bluetooth::BluetoothDevice& device, int8_t reportId, const ::std::vector<uint8_t>& data) override {
    return _aidl_delegate->onInterruptData(device, reportId, data);
  }
  ::android::binder::Status onVirtualCableUnplug(const ::android::bluetooth::BluetoothDevice& device) override {
    return _aidl_delegate->onVirtualCableUnplug(device);
  }
private:
  ::android::sp<IBluetoothHidDeviceCallback> _aidl_delegate;
};  // class IBluetoothHidDeviceCallbackDelegator
}  // namespace bluetooth
}  // namespace android
