#pragma once

#include <android/bluetooth/IBluetoothAvrcpTargetCallback.h>
#include <android/bluetooth/bluetooth_avrcp_int_value.h>
#include <android/bluetooth/bluetooth_avrcp_register_notification_response.h>
#include <android/bluetooth/bluetooth_avrcp_string_value.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android::bluetooth {
class IBluetoothAvrcpTargetCallback;
}  // namespace android::bluetooth
namespace android {
namespace bluetooth {
class IBluetoothAvrcpTargetDelegator;

class IBluetoothAvrcpTarget : public ::android::IInterface {
public:
  typedef IBluetoothAvrcpTargetDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothAvrcpTarget)
  virtual ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothAvrcpTargetCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Unregister(int32_t id) = 0;
  virtual ::android::binder::Status UnregisterAll() = 0;
  virtual ::android::binder::Status Enable(bool* _aidl_return) = 0;
  virtual ::android::binder::Status Disable(bool* _aidl_return) = 0;
  virtual ::android::binder::Status GetPlayStatusResponse(const ::android::String16& addr, int32_t play_status, int32_t song_len, int32_t song_pos, bool* _aidl_return) = 0;
  virtual ::android::binder::Status ListPlayerAppAttrResponse(const ::android::String16& addr, const ::std::vector<int32_t>& attrs, bool* _aidl_return) = 0;
  virtual ::android::binder::Status GetPlayerAppValueResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpIntValue>& values, bool* _aidl_return) = 0;
  virtual ::android::binder::Status GetPlayerAppAttrTextResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& attrs, bool* _aidl_return) = 0;
  virtual ::android::binder::Status GetPlayerAppValueTextResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& values, bool* _aidl_return) = 0;
  virtual ::android::binder::Status GetElementAttrResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& attrs, bool* _aidl_return) = 0;
  virtual ::android::binder::Status SetPlayerAppValueResponse(const ::android::String16& addr, int32_t rsp_status, bool* _aidl_return) = 0;
  virtual ::android::binder::Status RegisterNotificationResponse(int32_t event_id, int32_t type, const ::android::bluetooth::BluetoothAvrcpRegisterNotificationResponse& param, bool* _aidl_return) = 0;
  virtual ::android::binder::Status SetVolume(int32_t volume, bool* _aidl_return) = 0;
};  // class IBluetoothAvrcpTarget

class IBluetoothAvrcpTargetDefault : public IBluetoothAvrcpTarget {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothAvrcpTargetCallback>& /*callback*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Unregister(int32_t /*id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterAll() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Enable(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Disable(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status GetPlayStatusResponse(const ::android::String16& /*addr*/, int32_t /*play_status*/, int32_t /*song_len*/, int32_t /*song_pos*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ListPlayerAppAttrResponse(const ::android::String16& /*addr*/, const ::std::vector<int32_t>& /*attrs*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status GetPlayerAppValueResponse(const ::android::String16& /*addr*/, const ::std::vector<::android::bluetooth::BluetoothAvrcpIntValue>& /*values*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status GetPlayerAppAttrTextResponse(const ::android::String16& /*addr*/, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& /*attrs*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status GetPlayerAppValueTextResponse(const ::android::String16& /*addr*/, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& /*values*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status GetElementAttrResponse(const ::android::String16& /*addr*/, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& /*attrs*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status SetPlayerAppValueResponse(const ::android::String16& /*addr*/, int32_t /*rsp_status*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status RegisterNotificationResponse(int32_t /*event_id*/, int32_t /*type*/, const ::android::bluetooth::BluetoothAvrcpRegisterNotificationResponse& /*param*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status SetVolume(int32_t /*volume*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothAvrcpTargetDefault
}  // namespace bluetooth
}  // namespace android
