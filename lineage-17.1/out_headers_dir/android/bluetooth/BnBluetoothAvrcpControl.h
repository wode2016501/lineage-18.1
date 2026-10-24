#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothAvrcpControl.h>
#include <android/bluetooth/BnBluetoothAvrcpControl.h>
#include <android/bluetooth/BnBluetoothAvrcpControlCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothAvrcpControl : public ::android::BnInterface<IBluetoothAvrcpControl> {
public:
  static constexpr uint32_t TRANSACTION_Register = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_Unregister = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_UnregisterAll = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_Enable = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_Disable = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_SendPassThroughCommand = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_SetAbsVolumeResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_RegisterForAbsVolumeCallbackResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  explicit BnBluetoothAvrcpControl();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothAvrcpControl

class IBluetoothAvrcpControlDelegator : public BnBluetoothAvrcpControl {
public:
  explicit IBluetoothAvrcpControlDelegator(const ::android::sp<IBluetoothAvrcpControl> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothAvrcpControl> getImpl() { return _aidl_delegate; }
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothAvrcpControlCallback>& callback, bool* _aidl_return) override {
    ::android::sp<::android::bluetooth::IBluetoothAvrcpControlCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::bluetooth::IBluetoothAvrcpControlCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->Register(_callback, _aidl_return);
  }
  ::android::binder::Status Unregister(int32_t id) override {
    return _aidl_delegate->Unregister(id);
  }
  ::android::binder::Status UnregisterAll() override {
    return _aidl_delegate->UnregisterAll();
  }
  ::android::binder::Status Enable(int32_t id, bool* _aidl_return) override {
    return _aidl_delegate->Enable(id, _aidl_return);
  }
  ::android::binder::Status Disable(int32_t id, bool* _aidl_return) override {
    return _aidl_delegate->Disable(id, _aidl_return);
  }
  ::android::binder::Status SendPassThroughCommand(int32_t id, const ::android::String16& device_address, int32_t key_code, bool key_pressed, bool* _aidl_return) override {
    return _aidl_delegate->SendPassThroughCommand(id, device_address, key_code, key_pressed, _aidl_return);
  }
  ::android::binder::Status SetAbsVolumeResponse(int32_t id, const ::android::String16& device_address, int32_t abs_vol, int32_t label, bool* _aidl_return) override {
    return _aidl_delegate->SetAbsVolumeResponse(id, device_address, abs_vol, label, _aidl_return);
  }
  ::android::binder::Status RegisterForAbsVolumeCallbackResponse(int32_t id, const ::android::String16& device_address, int32_t response_type, int32_t abs_vol, int32_t label, bool* _aidl_return) override {
    return _aidl_delegate->RegisterForAbsVolumeCallbackResponse(id, device_address, response_type, abs_vol, label, _aidl_return);
  }
private:
  ::android::sp<IBluetoothAvrcpControl> _aidl_delegate;
};  // class IBluetoothAvrcpControlDelegator
}  // namespace bluetooth
}  // namespace android
