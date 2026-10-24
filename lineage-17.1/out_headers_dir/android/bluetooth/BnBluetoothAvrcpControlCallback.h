#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothAvrcpControlCallback.h>
#include <android/bluetooth/BnBluetoothAvrcpControlCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothAvrcpControlCallback : public ::android::BnInterface<IBluetoothAvrcpControlCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_OnTrackChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_OnSetAbsVolumeRequest = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_OnRegisterForAbsVolumeCallbackRequest = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnBluetoothAvrcpControlCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothAvrcpControlCallback

class IBluetoothAvrcpControlCallbackDelegator : public BnBluetoothAvrcpControlCallback {
public:
  explicit IBluetoothAvrcpControlCallbackDelegator(const ::android::sp<IBluetoothAvrcpControlCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothAvrcpControlCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnRegistered(int32_t status, int32_t id) override {
    return _aidl_delegate->OnRegistered(status, id);
  }
  ::android::binder::Status OnConnectionState(bool rc_connect, bool bt_connect, const ::android::String16& device_address) override {
    return _aidl_delegate->OnConnectionState(rc_connect, bt_connect, device_address);
  }
  ::android::binder::Status OnTrackChanged(const ::android::String16& device_address, const ::android::bluetooth::BluetoothAvrcpMediaAttr& track_info) override {
    return _aidl_delegate->OnTrackChanged(device_address, track_info);
  }
  ::android::binder::Status OnSetAbsVolumeRequest(const ::android::String16& device_address, int32_t abs_vol, int32_t label) override {
    return _aidl_delegate->OnSetAbsVolumeRequest(device_address, abs_vol, label);
  }
  ::android::binder::Status OnRegisterForAbsVolumeCallbackRequest(const ::android::String16& device_address, int32_t label) override {
    return _aidl_delegate->OnRegisterForAbsVolumeCallbackRequest(device_address, label);
  }
private:
  ::android::sp<IBluetoothAvrcpControlCallback> _aidl_delegate;
};  // class IBluetoothAvrcpControlCallbackDelegator
}  // namespace bluetooth
}  // namespace android
