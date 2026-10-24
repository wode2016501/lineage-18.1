#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothLeScannerCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothLeScannerCallback : public ::android::BpInterface<IBluetoothLeScannerCallback> {
public:
  explicit BpBluetoothLeScannerCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothLeScannerCallback() = default;
  ::android::binder::Status OnScannerRegistered(int32_t status, int32_t client_id) override;
  ::android::binder::Status OnScanResult(const ::android::bluetooth::ScanResult& scan_result) override;
};  // class BpBluetoothLeScannerCallback
}  // namespace bluetooth
}  // namespace android
