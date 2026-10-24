#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothLeScanner.h>

namespace android {
namespace bluetooth {
class BpBluetoothLeScanner : public ::android::BpInterface<IBluetoothLeScanner> {
public:
  explicit BpBluetoothLeScanner(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothLeScanner() = default;
  ::android::binder::Status RegisterScanner(const ::android::sp<::android::bluetooth::IBluetoothLeScannerCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status UnregisterScanner(int32_t scanner_id) override;
  ::android::binder::Status UnregisterAll() override;
  ::android::binder::Status StartScan(int32_t client_id, const ::android::bluetooth::ScanSettings& settings, const ::std::vector<::android::bluetooth::ScanFilter>& filters, bool* _aidl_return) override;
  ::android::binder::Status StopScan(int32_t client_id, bool* _aidl_return) override;
};  // class BpBluetoothLeScanner
}  // namespace bluetooth
}  // namespace android
