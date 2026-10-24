#pragma once

#include <android/bluetooth/bluetooth_avrcp_int_value.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace bluetooth {
class IBluetoothAvrcpTargetCallbackDelegator;

class IBluetoothAvrcpTargetCallback : public ::android::IInterface {
public:
  typedef IBluetoothAvrcpTargetCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothAvrcpTargetCallback)
  virtual ::android::binder::Status OnRegistered(int32_t status) = 0;
  virtual ::android::binder::Status OnGetRemoteFeatures(const ::android::String16& addr, int32_t features) = 0;
  virtual ::android::binder::Status OnGetPlayStatus(const ::android::String16& addr) = 0;
  virtual ::android::binder::Status OnListPlayerAppAttr(const ::android::String16& addr) = 0;
  virtual ::android::binder::Status OnListPlayerAppValues(const ::android::String16& addr, int32_t attr_id) = 0;
  virtual ::android::binder::Status OnGetPlayerAppValue(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) = 0;
  virtual ::android::binder::Status OnGetPlayerAppAttrsText(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) = 0;
  virtual ::android::binder::Status OnGetPlayerAppValuesText(const ::android::String16& addr, int32_t attr_id, const ::std::vector<int32_t>& values) = 0;
  virtual ::android::binder::Status OnSetPlayerAppValue(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpIntValue>& values) = 0;
  virtual ::android::binder::Status OnGetElementAttrs(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) = 0;
  virtual ::android::binder::Status OnRegisterNotification(const ::android::String16& addr, int32_t event_id, int32_t param) = 0;
  virtual ::android::binder::Status OnVolumeChange(const ::android::String16& addr, int32_t volume, int32_t ctype) = 0;
  virtual ::android::binder::Status OnPassThroughCommand(const ::android::String16& addr, int32_t id, int32_t key_state) = 0;
};  // class IBluetoothAvrcpTargetCallback

class IBluetoothAvrcpTargetCallbackDefault : public IBluetoothAvrcpTargetCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnRegistered(int32_t /*status*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnGetRemoteFeatures(const ::android::String16& /*addr*/, int32_t /*features*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnGetPlayStatus(const ::android::String16& /*addr*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnListPlayerAppAttr(const ::android::String16& /*addr*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnListPlayerAppValues(const ::android::String16& /*addr*/, int32_t /*attr_id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnGetPlayerAppValue(const ::android::String16& /*addr*/, const ::std::vector<int32_t>& /*attrs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnGetPlayerAppAttrsText(const ::android::String16& /*addr*/, const ::std::vector<int32_t>& /*attrs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnGetPlayerAppValuesText(const ::android::String16& /*addr*/, int32_t /*attr_id*/, const ::std::vector<int32_t>& /*values*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnSetPlayerAppValue(const ::android::String16& /*addr*/, const ::std::vector<::android::bluetooth::BluetoothAvrcpIntValue>& /*values*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnGetElementAttrs(const ::android::String16& /*addr*/, const ::std::vector<int32_t>& /*attrs*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnRegisterNotification(const ::android::String16& /*addr*/, int32_t /*event_id*/, int32_t /*param*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnVolumeChange(const ::android::String16& /*addr*/, int32_t /*volume*/, int32_t /*ctype*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnPassThroughCommand(const ::android::String16& /*addr*/, int32_t /*id*/, int32_t /*key_state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothAvrcpTargetCallbackDefault
}  // namespace bluetooth
}  // namespace android
