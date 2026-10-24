#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {
namespace bluetooth {
class IBluetoothA2dpSinkCallbackDelegator;

class IBluetoothA2dpSinkCallback : public ::android::IInterface {
public:
  typedef IBluetoothA2dpSinkCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothA2dpSinkCallback)
  virtual ::android::binder::Status OnRegistered(int32_t status) = 0;
  virtual ::android::binder::Status OnConnectionState(const ::android::String16& device_address, int32_t state) = 0;
  virtual ::android::binder::Status OnAudioState(const ::android::String16& device_address, int32_t state) = 0;
  virtual ::android::binder::Status OnAudioConfig(const ::android::String16& device_address, int32_t sample_rate, int32_t channel_count) = 0;
};  // class IBluetoothA2dpSinkCallback

class IBluetoothA2dpSinkCallbackDefault : public IBluetoothA2dpSinkCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnRegistered(int32_t /*status*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnConnectionState(const ::android::String16& /*device_address*/, int32_t /*state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnAudioState(const ::android::String16& /*device_address*/, int32_t /*state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnAudioConfig(const ::android::String16& /*device_address*/, int32_t /*sample_rate*/, int32_t /*channel_count*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothA2dpSinkCallbackDefault
}  // namespace bluetooth
}  // namespace android
