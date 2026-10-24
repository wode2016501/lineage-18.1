#pragma once

#include <android/bluetooth/bluetooth_remote_device_props.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace bluetooth {
class IBluetoothCallbackDelegator;

class IBluetoothCallback : public ::android::IInterface {
public:
  typedef IBluetoothCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothCallback)
  virtual ::android::binder::Status OnBluetoothStateChange(int32_t prev_state, int32_t new_state) = 0;
  virtual ::android::binder::Status OnScanEnableChanged(bool scan_enabled) = 0;
  virtual ::android::binder::Status OnDeviceConnectionStateChanged(const ::android::String16& device_address, bool connected) = 0;
  virtual ::android::binder::Status OnSspRequest(const ::android::String16& device_address, const ::android::String16& device_name, int32_t cod, int32_t pairing_variant, int32_t pass_key) = 0;
  virtual ::android::binder::Status OnGetBondedDevices(int32_t status, const ::std::vector<::android::String16>& device_addresses) = 0;
  virtual ::android::binder::Status OnBondStateChanged(int32_t status, const ::android::String16& device_address, int32_t state) = 0;
  virtual ::android::binder::Status OnGetRemoteDeviceProperties(int32_t status, const ::android::String16& device_address, const ::android::bluetooth::BluetoothRemoteDeviceProps& props) = 0;
  virtual ::android::binder::Status OnDeviceFound(const ::android::bluetooth::BluetoothRemoteDeviceProps& props) = 0;
};  // class IBluetoothCallback

class IBluetoothCallbackDefault : public IBluetoothCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnBluetoothStateChange(int32_t /*prev_state*/, int32_t /*new_state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnScanEnableChanged(bool /*scan_enabled*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnDeviceConnectionStateChanged(const ::android::String16& /*device_address*/, bool /*connected*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnSspRequest(const ::android::String16& /*device_address*/, const ::android::String16& /*device_name*/, int32_t /*cod*/, int32_t /*pairing_variant*/, int32_t /*pass_key*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnGetBondedDevices(int32_t /*status*/, const ::std::vector<::android::String16>& /*device_addresses*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnBondStateChanged(int32_t /*status*/, const ::android::String16& /*device_address*/, int32_t /*state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnGetRemoteDeviceProperties(int32_t /*status*/, const ::android::String16& /*device_address*/, const ::android::bluetooth::BluetoothRemoteDeviceProps& /*props*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnDeviceFound(const ::android::bluetooth::BluetoothRemoteDeviceProps& /*props*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothCallbackDefault
}  // namespace bluetooth
}  // namespace android
