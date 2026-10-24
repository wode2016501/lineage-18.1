#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothGattClientCallback.h>
#include <android/bluetooth/BnBluetoothGattClientCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothGattClientCallback : public ::android::BnInterface<IBluetoothGattClientCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnClientRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnBluetoothGattClientCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothGattClientCallback

class IBluetoothGattClientCallbackDelegator : public BnBluetoothGattClientCallback {
public:
  explicit IBluetoothGattClientCallbackDelegator(const ::android::sp<IBluetoothGattClientCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothGattClientCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnClientRegistered(int32_t status, int32_t client_id) override {
    return _aidl_delegate->OnClientRegistered(status, client_id);
  }
private:
  ::android::sp<IBluetoothGattClientCallback> _aidl_delegate;
};  // class IBluetoothGattClientCallbackDelegator
}  // namespace bluetooth
}  // namespace android
