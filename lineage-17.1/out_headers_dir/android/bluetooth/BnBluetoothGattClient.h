#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothGattClient.h>
#include <android/bluetooth/BnBluetoothGattClient.h>
#include <android/bluetooth/BnBluetoothGattClientCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothGattClient : public ::android::BnInterface<IBluetoothGattClient> {
public:
  static constexpr uint32_t TRANSACTION_RegisterClient = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_UnregisterClient = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_UnregisterAll = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnBluetoothGattClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothGattClient

class IBluetoothGattClientDelegator : public BnBluetoothGattClient {
public:
  explicit IBluetoothGattClientDelegator(const ::android::sp<IBluetoothGattClient> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothGattClient> getImpl() { return _aidl_delegate; }
  ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothGattClientCallback>& callback, bool* _aidl_return) override {
    ::android::sp<::android::bluetooth::IBluetoothGattClientCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::bluetooth::IBluetoothGattClientCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->RegisterClient(_callback, _aidl_return);
  }
  ::android::binder::Status UnregisterClient(int32_t client_id) override {
    return _aidl_delegate->UnregisterClient(client_id);
  }
  ::android::binder::Status UnregisterAll() override {
    return _aidl_delegate->UnregisterAll();
  }
private:
  ::android::sp<IBluetoothGattClient> _aidl_delegate;
};  // class IBluetoothGattClientDelegator
}  // namespace bluetooth
}  // namespace android
