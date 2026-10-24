#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothLeScanner.h>
#include <android/bluetooth/BnBluetoothLeScanner.h>
#include <android/bluetooth/BnBluetoothLeScannerCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothLeScanner : public ::android::BnInterface<IBluetoothLeScanner> {
public:
  static constexpr uint32_t TRANSACTION_RegisterScanner = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_UnregisterScanner = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_UnregisterAll = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_StartScan = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_StopScan = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnBluetoothLeScanner();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothLeScanner

class IBluetoothLeScannerDelegator : public BnBluetoothLeScanner {
public:
  explicit IBluetoothLeScannerDelegator(const ::android::sp<IBluetoothLeScanner> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothLeScanner> getImpl() { return _aidl_delegate; }
  ::android::binder::Status RegisterScanner(const ::android::sp<::android::bluetooth::IBluetoothLeScannerCallback>& callback, bool* _aidl_return) override {
    ::android::sp<::android::bluetooth::IBluetoothLeScannerCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::bluetooth::IBluetoothLeScannerCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->RegisterScanner(_callback, _aidl_return);
  }
  ::android::binder::Status UnregisterScanner(int32_t scanner_id) override {
    return _aidl_delegate->UnregisterScanner(scanner_id);
  }
  ::android::binder::Status UnregisterAll() override {
    return _aidl_delegate->UnregisterAll();
  }
  ::android::binder::Status StartScan(int32_t client_id, const ::android::bluetooth::ScanSettings& settings, const ::std::vector<::android::bluetooth::ScanFilter>& filters, bool* _aidl_return) override {
    return _aidl_delegate->StartScan(client_id, settings, filters, _aidl_return);
  }
  ::android::binder::Status StopScan(int32_t client_id, bool* _aidl_return) override {
    return _aidl_delegate->StopScan(client_id, _aidl_return);
  }
private:
  ::android::sp<IBluetoothLeScanner> _aidl_delegate;
};  // class IBluetoothLeScannerDelegator
}  // namespace bluetooth
}  // namespace android
