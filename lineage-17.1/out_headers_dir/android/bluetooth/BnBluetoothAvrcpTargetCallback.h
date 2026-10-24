#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothAvrcpTargetCallback.h>
#include <android/bluetooth/BnBluetoothAvrcpTargetCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothAvrcpTargetCallback : public ::android::BnInterface<IBluetoothAvrcpTargetCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnGetRemoteFeatures = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_OnGetPlayStatus = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_OnListPlayerAppAttr = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_OnListPlayerAppValues = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_OnGetPlayerAppValue = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_OnGetPlayerAppAttrsText = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_OnGetPlayerAppValuesText = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_OnSetPlayerAppValue = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_OnGetElementAttrs = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_OnRegisterNotification = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_OnVolumeChange = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_OnPassThroughCommand = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  explicit BnBluetoothAvrcpTargetCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothAvrcpTargetCallback

class IBluetoothAvrcpTargetCallbackDelegator : public BnBluetoothAvrcpTargetCallback {
public:
  explicit IBluetoothAvrcpTargetCallbackDelegator(const ::android::sp<IBluetoothAvrcpTargetCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothAvrcpTargetCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnRegistered(int32_t status) override {
    return _aidl_delegate->OnRegistered(status);
  }
  ::android::binder::Status OnGetRemoteFeatures(const ::android::String16& addr, int32_t features) override {
    return _aidl_delegate->OnGetRemoteFeatures(addr, features);
  }
  ::android::binder::Status OnGetPlayStatus(const ::android::String16& addr) override {
    return _aidl_delegate->OnGetPlayStatus(addr);
  }
  ::android::binder::Status OnListPlayerAppAttr(const ::android::String16& addr) override {
    return _aidl_delegate->OnListPlayerAppAttr(addr);
  }
  ::android::binder::Status OnListPlayerAppValues(const ::android::String16& addr, int32_t attr_id) override {
    return _aidl_delegate->OnListPlayerAppValues(addr, attr_id);
  }
  ::android::binder::Status OnGetPlayerAppValue(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) override {
    return _aidl_delegate->OnGetPlayerAppValue(addr, attrs);
  }
  ::android::binder::Status OnGetPlayerAppAttrsText(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) override {
    return _aidl_delegate->OnGetPlayerAppAttrsText(addr, attrs);
  }
  ::android::binder::Status OnGetPlayerAppValuesText(const ::android::String16& addr, int32_t attr_id, const ::std::vector<int32_t>& values) override {
    return _aidl_delegate->OnGetPlayerAppValuesText(addr, attr_id, values);
  }
  ::android::binder::Status OnSetPlayerAppValue(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpIntValue>& values) override {
    return _aidl_delegate->OnSetPlayerAppValue(addr, values);
  }
  ::android::binder::Status OnGetElementAttrs(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) override {
    return _aidl_delegate->OnGetElementAttrs(addr, attrs);
  }
  ::android::binder::Status OnRegisterNotification(const ::android::String16& addr, int32_t event_id, int32_t param) override {
    return _aidl_delegate->OnRegisterNotification(addr, event_id, param);
  }
  ::android::binder::Status OnVolumeChange(const ::android::String16& addr, int32_t volume, int32_t ctype) override {
    return _aidl_delegate->OnVolumeChange(addr, volume, ctype);
  }
  ::android::binder::Status OnPassThroughCommand(const ::android::String16& addr, int32_t id, int32_t key_state) override {
    return _aidl_delegate->OnPassThroughCommand(addr, id, key_state);
  }
private:
  ::android::sp<IBluetoothAvrcpTargetCallback> _aidl_delegate;
};  // class IBluetoothAvrcpTargetCallbackDelegator
}  // namespace bluetooth
}  // namespace android
