#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothLowEnergy.h>
#include <android/bluetooth/BnBluetoothLowEnergy.h>
#include <android/bluetooth/BnBluetoothLowEnergyCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothLowEnergy : public ::android::BnInterface<IBluetoothLowEnergy> {
public:
  static constexpr uint32_t TRANSACTION_RegisterClient = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_UnregisterClient = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_UnregisterAll = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_Connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_Disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_SetMtu = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnBluetoothLowEnergy();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothLowEnergy

class IBluetoothLowEnergyDelegator : public BnBluetoothLowEnergy {
public:
  explicit IBluetoothLowEnergyDelegator(const ::android::sp<IBluetoothLowEnergy> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothLowEnergy> getImpl() { return _aidl_delegate; }
  ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothLowEnergyCallback>& callback, bool* _aidl_return) override {
    ::android::sp<::android::bluetooth::IBluetoothLowEnergyCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::bluetooth::IBluetoothLowEnergyCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->RegisterClient(_callback, _aidl_return);
  }
  ::android::binder::Status UnregisterClient(int32_t client_if) override {
    return _aidl_delegate->UnregisterClient(client_if);
  }
  ::android::binder::Status UnregisterAll() override {
    return _aidl_delegate->UnregisterAll();
  }
  ::android::binder::Status Connect(int32_t client_id, const ::android::String16& address, bool is_direct, bool* _aidl_return) override {
    return _aidl_delegate->Connect(client_id, address, is_direct, _aidl_return);
  }
  ::android::binder::Status Disconnect(int32_t client_id, const ::android::String16& address, bool* _aidl_return) override {
    return _aidl_delegate->Disconnect(client_id, address, _aidl_return);
  }
  ::android::binder::Status SetMtu(int32_t client_id, const ::android::String16& address, int32_t mtu, bool* _aidl_return) override {
    return _aidl_delegate->SetMtu(client_id, address, mtu, _aidl_return);
  }
private:
  ::android::sp<IBluetoothLowEnergy> _aidl_delegate;
};  // class IBluetoothLowEnergyDelegator
}  // namespace bluetooth
}  // namespace android
