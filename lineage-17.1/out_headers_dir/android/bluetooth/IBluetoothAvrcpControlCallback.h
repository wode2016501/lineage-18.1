#pragma once

#include <android/bluetooth/bluetooth_avrcp_media_attr.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {
namespace bluetooth {
class IBluetoothAvrcpControlCallbackDelegator;

class IBluetoothAvrcpControlCallback : public ::android::IInterface {
public:
  typedef IBluetoothAvrcpControlCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothAvrcpControlCallback)
  virtual ::android::binder::Status OnRegistered(int32_t status, int32_t id) = 0;
  virtual ::android::binder::Status OnConnectionState(bool rc_connect, bool bt_connect, const ::android::String16& device_address) = 0;
  virtual ::android::binder::Status OnTrackChanged(const ::android::String16& device_address, const ::android::bluetooth::BluetoothAvrcpMediaAttr& track_info) = 0;
  virtual ::android::binder::Status OnSetAbsVolumeRequest(const ::android::String16& device_address, int32_t abs_vol, int32_t label) = 0;
  virtual ::android::binder::Status OnRegisterForAbsVolumeCallbackRequest(const ::android::String16& device_address, int32_t label) = 0;
};  // class IBluetoothAvrcpControlCallback

class IBluetoothAvrcpControlCallbackDefault : public IBluetoothAvrcpControlCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnRegistered(int32_t /*status*/, int32_t /*id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnConnectionState(bool /*rc_connect*/, bool /*bt_connect*/, const ::android::String16& /*device_address*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnTrackChanged(const ::android::String16& /*device_address*/, const ::android::bluetooth::BluetoothAvrcpMediaAttr& /*track_info*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnSetAbsVolumeRequest(const ::android::String16& /*device_address*/, int32_t /*abs_vol*/, int32_t /*label*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnRegisterForAbsVolumeCallbackRequest(const ::android::String16& /*device_address*/, int32_t /*label*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothAvrcpControlCallbackDefault
}  // namespace bluetooth
}  // namespace android
