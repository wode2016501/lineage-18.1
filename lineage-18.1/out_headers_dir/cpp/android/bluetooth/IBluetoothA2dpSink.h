#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_A2DP_SINK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_A2DP_SINK_H_

#include <android/bluetooth/IBluetoothA2dpSinkCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace bluetooth {

class IBluetoothA2dpSink : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BluetoothA2dpSink)
  virtual ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothA2dpSinkCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Unregister() = 0;
  virtual ::android::binder::Status Enable(bool* _aidl_return) = 0;
  virtual ::android::binder::Status Disable(bool* _aidl_return) = 0;
  virtual ::android::binder::Status Connect(const ::android::String16& device_address, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Disconnect(const ::android::String16& device_address, bool* _aidl_return) = 0;
  virtual ::android::binder::Status SetAudioFocusState(int32_t state, bool* _aidl_return) = 0;
  virtual ::android::binder::Status SetAudioTrackGain(float gain, bool* _aidl_return) = 0;
};  // class IBluetoothA2dpSink

class IBluetoothA2dpSinkDefault : public IBluetoothA2dpSink {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothA2dpSinkCallback>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Unregister() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Enable(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Disable(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Connect(const ::android::String16&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Disconnect(const ::android::String16&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status SetAudioFocusState(int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status SetAudioTrackGain(float, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothA2dpSinkDefault

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_A2DP_SINK_H_
