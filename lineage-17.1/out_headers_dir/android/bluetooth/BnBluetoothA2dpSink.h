#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothA2dpSink.h>
#include <android/bluetooth/BnBluetoothA2dpSink.h>
#include <android/bluetooth/BnBluetoothA2dpSinkCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothA2dpSink : public ::android::BnInterface<IBluetoothA2dpSink> {
public:
  static constexpr uint32_t TRANSACTION_Register = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_Unregister = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_Enable = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_Disable = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_Connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_Disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_SetAudioFocusState = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_SetAudioTrackGain = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  explicit BnBluetoothA2dpSink();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothA2dpSink

class IBluetoothA2dpSinkDelegator : public BnBluetoothA2dpSink {
public:
  explicit IBluetoothA2dpSinkDelegator(const ::android::sp<IBluetoothA2dpSink> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothA2dpSink> getImpl() { return _aidl_delegate; }
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothA2dpSinkCallback>& callback, bool* _aidl_return) override {
    ::android::sp<::android::bluetooth::IBluetoothA2dpSinkCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::bluetooth::IBluetoothA2dpSinkCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->Register(_callback, _aidl_return);
  }
  ::android::binder::Status Unregister() override {
    return _aidl_delegate->Unregister();
  }
  ::android::binder::Status Enable(bool* _aidl_return) override {
    return _aidl_delegate->Enable(_aidl_return);
  }
  ::android::binder::Status Disable(bool* _aidl_return) override {
    return _aidl_delegate->Disable(_aidl_return);
  }
  ::android::binder::Status Connect(const ::android::String16& device_address, bool* _aidl_return) override {
    return _aidl_delegate->Connect(device_address, _aidl_return);
  }
  ::android::binder::Status Disconnect(const ::android::String16& device_address, bool* _aidl_return) override {
    return _aidl_delegate->Disconnect(device_address, _aidl_return);
  }
  ::android::binder::Status SetAudioFocusState(int32_t state, bool* _aidl_return) override {
    return _aidl_delegate->SetAudioFocusState(state, _aidl_return);
  }
  ::android::binder::Status SetAudioTrackGain(float gain, bool* _aidl_return) override {
    return _aidl_delegate->SetAudioTrackGain(gain, _aidl_return);
  }
private:
  ::android::sp<IBluetoothA2dpSink> _aidl_delegate;
};  // class IBluetoothA2dpSinkDelegator
}  // namespace bluetooth
}  // namespace android
