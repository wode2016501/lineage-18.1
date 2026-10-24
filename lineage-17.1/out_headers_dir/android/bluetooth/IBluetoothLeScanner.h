#pragma once

#include <android/bluetooth/IBluetoothLeScannerCallback.h>
#include <android/bluetooth/scan_filter.h>
#include <android/bluetooth/scan_settings.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android::bluetooth {
class IBluetoothLeScannerCallback;
}  // namespace android::bluetooth
namespace android {
namespace bluetooth {
class IBluetoothLeScannerDelegator;

class IBluetoothLeScanner : public ::android::IInterface {
public:
  typedef IBluetoothLeScannerDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothLeScanner)
  virtual ::android::binder::Status RegisterScanner(const ::android::sp<::android::bluetooth::IBluetoothLeScannerCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status UnregisterScanner(int32_t scanner_id) = 0;
  virtual ::android::binder::Status UnregisterAll() = 0;
  virtual ::android::binder::Status StartScan(int32_t client_id, const ::android::bluetooth::ScanSettings& settings, const ::std::vector<::android::bluetooth::ScanFilter>& filters, bool* _aidl_return) = 0;
  virtual ::android::binder::Status StopScan(int32_t client_id, bool* _aidl_return) = 0;
};  // class IBluetoothLeScanner

class IBluetoothLeScannerDefault : public IBluetoothLeScanner {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status RegisterScanner(const ::android::sp<::android::bluetooth::IBluetoothLeScannerCallback>& /*callback*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterScanner(int32_t /*scanner_id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterAll() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status StartScan(int32_t /*client_id*/, const ::android::bluetooth::ScanSettings& /*settings*/, const ::std::vector<::android::bluetooth::ScanFilter>& /*filters*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status StopScan(int32_t /*client_id*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothLeScannerDefault
}  // namespace bluetooth
}  // namespace android
