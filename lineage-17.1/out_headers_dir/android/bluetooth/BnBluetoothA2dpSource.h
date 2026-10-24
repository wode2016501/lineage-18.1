#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothA2dpSource.h>
#include <android/bluetooth/BnBluetoothA2dpSource.h>
#include <android/bluetooth/BnBluetoothA2dpSourceCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothA2dpSource : public ::android::BnInterface<IBluetoothA2dpSource> {
public:
  static constexpr uint32_t TRANSACTION_Register = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_Unregister = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_Enable = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_Disable = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_Connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_Disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_ConfigCodec = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  explicit BnBluetoothA2dpSource();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothA2dpSource

class IBluetoothA2dpSourceDelegator : public BnBluetoothA2dpSource {
public:
  explicit IBluetoothA2dpSourceDelegator(const ::android::sp<IBluetoothA2dpSource> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothA2dpSource> getImpl() { return _aidl_delegate; }
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothA2dpSourceCallback>& callback, bool* _aidl_return) override {
    ::android::sp<::android::bluetooth::IBluetoothA2dpSourceCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::bluetooth::IBluetoothA2dpSourceCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->Register(_callback, _aidl_return);
  }
  ::android::binder::Status Unregister() override {
    return _aidl_delegate->Unregister();
  }
  ::android::binder::Status Enable(const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codec_priorities, bool* _aidl_return) override {
    return _aidl_delegate->Enable(codec_priorities, _aidl_return);
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
  ::android::binder::Status ConfigCodec(const ::android::String16& device_address, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codec_preferences, bool* _aidl_return) override {
    return _aidl_delegate->ConfigCodec(device_address, codec_preferences, _aidl_return);
  }
private:
  ::android::sp<IBluetoothA2dpSource> _aidl_delegate;
};  // class IBluetoothA2dpSourceDelegator
}  // namespace bluetooth
}  // namespace android
