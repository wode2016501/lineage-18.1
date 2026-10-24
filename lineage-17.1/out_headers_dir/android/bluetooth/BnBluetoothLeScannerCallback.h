#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothLeScannerCallback.h>
#include <android/bluetooth/BnBluetoothLeScannerCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothLeScannerCallback : public ::android::BnInterface<IBluetoothLeScannerCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnScannerRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnScanResult = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnBluetoothLeScannerCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothLeScannerCallback

class IBluetoothLeScannerCallbackDelegator : public BnBluetoothLeScannerCallback {
public:
  explicit IBluetoothLeScannerCallbackDelegator(const ::android::sp<IBluetoothLeScannerCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothLeScannerCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnScannerRegistered(int32_t status, int32_t client_id) override {
    return _aidl_delegate->OnScannerRegistered(status, client_id);
  }
  ::android::binder::Status OnScanResult(const ::android::bluetooth::ScanResult& scan_result) override {
    return _aidl_delegate->OnScanResult(scan_result);
  }
private:
  ::android::sp<IBluetoothLeScannerCallback> _aidl_delegate;
};  // class IBluetoothLeScannerCallbackDelegator
}  // namespace bluetooth
}  // namespace android
