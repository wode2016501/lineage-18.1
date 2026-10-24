#pragma once

#include <android/bluetooth/scan_result.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {
namespace bluetooth {
class IBluetoothLeScannerCallbackDelegator;

class IBluetoothLeScannerCallback : public ::android::IInterface {
public:
  typedef IBluetoothLeScannerCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothLeScannerCallback)
  virtual ::android::binder::Status OnScannerRegistered(int32_t status, int32_t client_id) = 0;
  virtual ::android::binder::Status OnScanResult(const ::android::bluetooth::ScanResult& scan_result) = 0;
};  // class IBluetoothLeScannerCallback

class IBluetoothLeScannerCallbackDefault : public IBluetoothLeScannerCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnScannerRegistered(int32_t /*status*/, int32_t /*client_id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnScanResult(const ::android::bluetooth::ScanResult& /*scan_result*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothLeScannerCallbackDefault
}  // namespace bluetooth
}  // namespace android
