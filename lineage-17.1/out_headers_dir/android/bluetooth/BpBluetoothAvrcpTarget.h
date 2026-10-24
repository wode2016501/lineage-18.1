#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothAvrcpTarget.h>

namespace android {
namespace bluetooth {
class BpBluetoothAvrcpTarget : public ::android::BpInterface<IBluetoothAvrcpTarget> {
public:
  explicit BpBluetoothAvrcpTarget(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothAvrcpTarget() = default;
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothAvrcpTargetCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status Unregister(int32_t id) override;
  ::android::binder::Status UnregisterAll() override;
  ::android::binder::Status Enable(bool* _aidl_return) override;
  ::android::binder::Status Disable(bool* _aidl_return) override;
  ::android::binder::Status GetPlayStatusResponse(const ::android::String16& addr, int32_t play_status, int32_t song_len, int32_t song_pos, bool* _aidl_return) override;
  ::android::binder::Status ListPlayerAppAttrResponse(const ::android::String16& addr, const ::std::vector<int32_t>& attrs, bool* _aidl_return) override;
  ::android::binder::Status GetPlayerAppValueResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpIntValue>& values, bool* _aidl_return) override;
  ::android::binder::Status GetPlayerAppAttrTextResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& attrs, bool* _aidl_return) override;
  ::android::binder::Status GetPlayerAppValueTextResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& values, bool* _aidl_return) override;
  ::android::binder::Status GetElementAttrResponse(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpStringValue>& attrs, bool* _aidl_return) override;
  ::android::binder::Status SetPlayerAppValueResponse(const ::android::String16& addr, int32_t rsp_status, bool* _aidl_return) override;
  ::android::binder::Status RegisterNotificationResponse(int32_t event_id, int32_t type, const ::android::bluetooth::BluetoothAvrcpRegisterNotificationResponse& param, bool* _aidl_return) override;
  ::android::binder::Status SetVolume(int32_t volume, bool* _aidl_return) override;
};  // class BpBluetoothAvrcpTarget
}  // namespace bluetooth
}  // namespace android
