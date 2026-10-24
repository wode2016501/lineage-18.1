#pragma once

#include <android/bluetooth/IBluetoothAvrcpControlCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android::bluetooth {
class IBluetoothAvrcpControlCallback;
}  // namespace android::bluetooth
namespace android {
namespace bluetooth {
class IBluetoothAvrcpControlDelegator;

class IBluetoothAvrcpControl : public ::android::IInterface {
public:
  typedef IBluetoothAvrcpControlDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothAvrcpControl)
  virtual ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothAvrcpControlCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Unregister(int32_t id) = 0;
  virtual ::android::binder::Status UnregisterAll() = 0;
  virtual ::android::binder::Status Enable(int32_t id, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Disable(int32_t id, bool* _aidl_return) = 0;
  virtual ::android::binder::Status SendPassThroughCommand(int32_t id, const ::android::String16& device_address, int32_t key_code, bool key_pressed, bool* _aidl_return) = 0;
  virtual ::android::binder::Status SetAbsVolumeResponse(int32_t id, const ::android::String16& device_address, int32_t abs_vol, int32_t label, bool* _aidl_return) = 0;
  virtual ::android::binder::Status RegisterForAbsVolumeCallbackResponse(int32_t id, const ::android::String16& device_address, int32_t response_type, int32_t abs_vol, int32_t label, bool* _aidl_return) = 0;
};  // class IBluetoothAvrcpControl

class IBluetoothAvrcpControlDefault : public IBluetoothAvrcpControl {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothAvrcpControlCallback>& /*callback*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Unregister(int32_t /*id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterAll() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Enable(int32_t /*id*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Disable(int32_t /*id*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status SendPassThroughCommand(int32_t /*id*/, const ::android::String16& /*device_address*/, int32_t /*key_code*/, bool /*key_pressed*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status SetAbsVolumeResponse(int32_t /*id*/, const ::android::String16& /*device_address*/, int32_t /*abs_vol*/, int32_t /*label*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status RegisterForAbsVolumeCallbackResponse(int32_t /*id*/, const ::android::String16& /*device_address*/, int32_t /*response_type*/, int32_t /*abs_vol*/, int32_t /*label*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothAvrcpControlDefault
}  // namespace bluetooth
}  // namespace android
