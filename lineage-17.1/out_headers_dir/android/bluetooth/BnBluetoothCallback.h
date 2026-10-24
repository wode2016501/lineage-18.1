#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothCallback.h>
#include <android/bluetooth/BnBluetoothCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothCallback : public ::android::BnInterface<IBluetoothCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnBluetoothStateChange = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnScanEnableChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_OnDeviceConnectionStateChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_OnSspRequest = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_OnGetBondedDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_OnBondStateChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_OnGetRemoteDeviceProperties = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_OnDeviceFound = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  explicit BnBluetoothCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothCallback

class IBluetoothCallbackDelegator : public BnBluetoothCallback {
public:
  explicit IBluetoothCallbackDelegator(const ::android::sp<IBluetoothCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnBluetoothStateChange(int32_t prev_state, int32_t new_state) override {
    return _aidl_delegate->OnBluetoothStateChange(prev_state, new_state);
  }
  ::android::binder::Status OnScanEnableChanged(bool scan_enabled) override {
    return _aidl_delegate->OnScanEnableChanged(scan_enabled);
  }
  ::android::binder::Status OnDeviceConnectionStateChanged(const ::android::String16& device_address, bool connected) override {
    return _aidl_delegate->OnDeviceConnectionStateChanged(device_address, connected);
  }
  ::android::binder::Status OnSspRequest(const ::android::String16& device_address, const ::android::String16& device_name, int32_t cod, int32_t pairing_variant, int32_t pass_key) override {
    return _aidl_delegate->OnSspRequest(device_address, device_name, cod, pairing_variant, pass_key);
  }
  ::android::binder::Status OnGetBondedDevices(int32_t status, const ::std::vector<::android::String16>& device_addresses) override {
    return _aidl_delegate->OnGetBondedDevices(status, device_addresses);
  }
  ::android::binder::Status OnBondStateChanged(int32_t status, const ::android::String16& device_address, int32_t state) override {
    return _aidl_delegate->OnBondStateChanged(status, device_address, state);
  }
  ::android::binder::Status OnGetRemoteDeviceProperties(int32_t status, const ::android::String16& device_address, const ::android::bluetooth::BluetoothRemoteDeviceProps& props) override {
    return _aidl_delegate->OnGetRemoteDeviceProperties(status, device_address, props);
  }
  ::android::binder::Status OnDeviceFound(const ::android::bluetooth::BluetoothRemoteDeviceProps& props) override {
    return _aidl_delegate->OnDeviceFound(props);
  }
private:
  ::android::sp<IBluetoothCallback> _aidl_delegate;
};  // class IBluetoothCallbackDelegator
}  // namespace bluetooth
}  // namespace android
