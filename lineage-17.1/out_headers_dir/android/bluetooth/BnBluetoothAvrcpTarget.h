#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothAvrcpTarget.h>
#include <android/bluetooth/BnBluetoothAvrcpTarget.h>
#include <android/bluetooth/BnBluetoothAvrcpTargetCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothAvrcpTarget : public ::android::BnInterface<IBluetoothAvrcpTarget> {
public:
  static constexpr uint32_t TRANSACTION_Register = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_Unregister = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_UnregisterAll = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_Enable = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_Disable = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_GetPlayStatusResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_ListPlayerAppAttrResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_GetPlayerAppValueResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_GetPlayerAppAttrTextResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_GetPlayerAppValueTextResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_GetElementAttrResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_SetPlayerAppValueResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_RegisterNotificationResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_SetVolume = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  explicit BnBluetoothAvrcpTarget();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothAvrcpTarget

class IBluetoothAvrcpTargetDelegator : public BnBluetoothAvrcpTarget {
public:
  explicit IBluetoothAvrcpTargetDelegator(const ::android::sp<IBluetoothAvrcpTarget> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothAvrcpTarget> getImpl() { return _aidl_delegate; }
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothAvrcpTargetCallback>& callback, bool* _aidl_return) override {
    ::android::sp<::android::bluetooth::IBluetoothAvrcpTargetCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::bluetooth::IBluetoothAvrcpTargetCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->Register(_callback, _aidl_return);
  }
  ::android::binder::Status Unregister(int32_t id) override {
    return _aidl_delegate->Unregister(id);
  }
  ::android::binder::Status UnregisterAll() override {
    return _aidl_delegate->UnregisterAll();
  }
  ::android::binder::Status Enable(bool* _aidl_return) override {
    return _aidl_delegate->Enable(_aidl_return);
  }
  ::android::binder::Status Disable(bool* _aidl_return) override {
    return _aidl_delegate->Disable(_aidl_return);
  }
  ::android::binder::Status GetPlayStatusResponse(const ::android::String16& addr, int32_t play_status, int32_t song_len, int32_t song_pos, bool* _aidl_return) override {
    return _aidl_delegate->GetPlayStatusResponse(addr, play_status, song_len, song_pos, _aidl_return);
  }
  ::android::binder::Status ListPlayerAppAttrResponse(const ::android::String16& addr, const ::std::vector<int32_t>& attrs, bool* _aidl_return) override {
    return _aidl_delegate->ListPlayerAppAttrResponse(addr, attrs, _aidl_return);
  }
  ::android::binder::Status GetPlayerAppValueResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpIntValue>& values, bool* _aidl_return) override {
    return _aidl_delegate->GetPlayerAppValueResponse(addr, values, _aidl_return);
  }
  ::android::binder::Status GetPlayerAppAttrTextResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& attrs, bool* _aidl_return) override {
    return _aidl_delegate->GetPlayerAppAttrTextResponse(addr, attrs, _aidl_return);
  }
  ::android::binder::Status GetPlayerAppValueTextResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& values, bool* _aidl_return) override {
    return _aidl_delegate->GetPlayerAppValueTextResponse(addr, values, _aidl_return);
  }
  ::android::binder::Status GetElementAttrResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& attrs, bool* _aidl_return) override {
    return _aidl_delegate->GetElementAttrResponse(addr, attrs, _aidl_return);
  }
  ::android::binder::Status SetPlayerAppValueResponse(const ::android::String16& addr, int32_t rsp_status, bool* _aidl_return) override {
    return _aidl_delegate->SetPlayerAppValueResponse(addr, rsp_status, _aidl_return);
  }
  ::android::binder::Status RegisterNotificationResponse(int32_t event_id, int32_t type, const ::android::bluetooth::BluetoothAvrcpRegisterNotificationResponse& param, bool* _aidl_return) override {
    return _aidl_delegate->RegisterNotificationResponse(event_id, type, param, _aidl_return);
  }
  ::android::binder::Status SetVolume(int32_t volume, bool* _aidl_return) override {
    return _aidl_delegate->SetVolume(volume, _aidl_return);
  }
private:
  ::android::sp<IBluetoothAvrcpTarget> _aidl_delegate;
};  // class IBluetoothAvrcpTargetDelegator
}  // namespace bluetooth
}  // namespace android
