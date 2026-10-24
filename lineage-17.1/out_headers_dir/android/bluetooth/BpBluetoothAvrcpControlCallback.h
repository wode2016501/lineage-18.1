#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothAvrcpControlCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothAvrcpControlCallback : public ::android::BpInterface<IBluetoothAvrcpControlCallback> {
public:
  explicit BpBluetoothAvrcpControlCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothAvrcpControlCallback() = default;
  ::android::binder::Status OnRegistered(int32_t status, int32_t id) override;
  ::android::binder::Status OnConnectionState(bool rc_connect, bool bt_connect, const ::android::String16& device_address) override;
  ::android::binder::Status OnTrackChanged(const ::android::String16& device_address, const ::android::bluetooth::BluetoothAvrcpMediaAttr& track_info) override;
  ::android::binder::Status OnSetAbsVolumeRequest(const ::android::String16& device_address, int32_t abs_vol, int32_t label) override;
  ::android::binder::Status OnRegisterForAbsVolumeCallbackRequest(const ::android::String16& device_address, int32_t label) override;
};  // class BpBluetoothAvrcpControlCallback
}  // namespace bluetooth
}  // namespace android
