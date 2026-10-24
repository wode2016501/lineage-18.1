#pragma once

#include <android/bluetooth/IBluetoothA2dpSourceCallback.h>
#include <android/bluetooth/bluetooth_a2dp_codec_config.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android::bluetooth {
class IBluetoothA2dpSourceCallback;
}  // namespace android::bluetooth
namespace android {
namespace bluetooth {
class IBluetoothA2dpSourceDelegator;

class IBluetoothA2dpSource : public ::android::IInterface {
public:
  typedef IBluetoothA2dpSourceDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothA2dpSource)
  virtual ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothA2dpSourceCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Unregister() = 0;
  virtual ::android::binder::Status Enable(const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codec_priorities, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Disable(bool* _aidl_return) = 0;
  virtual ::android::binder::Status Connect(const ::android::String16& device_address, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Disconnect(const ::android::String16& device_address, bool* _aidl_return) = 0;
  virtual ::android::binder::Status ConfigCodec(const ::android::String16& device_address, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& codec_preferences, bool* _aidl_return) = 0;
};  // class IBluetoothA2dpSource

class IBluetoothA2dpSourceDefault : public IBluetoothA2dpSource {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothA2dpSourceCallback>& /*callback*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Unregister() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Enable(const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& /*codec_priorities*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Disable(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Connect(const ::android::String16& /*device_address*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Disconnect(const ::android::String16& /*device_address*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ConfigCodec(const ::android::String16& /*device_address*/, const ::std::vector<::android::bluetooth::BluetoothA2dpCodecConfig>& /*codec_preferences*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothA2dpSourceDefault
}  // namespace bluetooth
}  // namespace android
