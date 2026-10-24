#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothLowEnergyCallback.h>
#include <android/bluetooth/BnBluetoothLowEnergyCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothLowEnergyCallback : public ::android::BnInterface<IBluetoothLowEnergyCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnClientRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_OnMtuChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnBluetoothLowEnergyCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothLowEnergyCallback

class IBluetoothLowEnergyCallbackDelegator : public BnBluetoothLowEnergyCallback {
public:
  explicit IBluetoothLowEnergyCallbackDelegator(const ::android::sp<IBluetoothLowEnergyCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothLowEnergyCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnClientRegistered(int32_t status, int32_t client_id) override {
    return _aidl_delegate->OnClientRegistered(status, client_id);
  }
  ::android::binder::Status OnConnectionState(int32_t status, int32_t client_id, const ::android::String16& address, bool connected) override {
    return _aidl_delegate->OnConnectionState(status, client_id, address, connected);
  }
  ::android::binder::Status OnMtuChanged(int32_t status, const ::android::String16& address, int32_t mtu) override {
    return _aidl_delegate->OnMtuChanged(status, address, mtu);
  }
private:
  ::android::sp<IBluetoothLowEnergyCallback> _aidl_delegate;
};  // class IBluetoothLowEnergyCallbackDelegator
}  // namespace bluetooth
}  // namespace android
