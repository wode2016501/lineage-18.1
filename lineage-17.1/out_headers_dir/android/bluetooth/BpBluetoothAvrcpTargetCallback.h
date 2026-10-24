#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothAvrcpTargetCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothAvrcpTargetCallback : public ::android::BpInterface<IBluetoothAvrcpTargetCallback> {
public:
  explicit BpBluetoothAvrcpTargetCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothAvrcpTargetCallback() = default;
  ::android::binder::Status OnRegistered(int32_t status) override;
  ::android::binder::Status OnGetRemoteFeatures(const ::android::String16& addr, int32_t features) override;
  ::android::binder::Status OnGetPlayStatus(const ::android::String16& addr) override;
  ::android::binder::Status OnListPlayerAppAttr(const ::android::String16& addr) override;
  ::android::binder::Status OnListPlayerAppValues(const ::android::String16& addr, int32_t attr_id) override;
  ::android::binder::Status OnGetPlayerAppValue(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) override;
  ::android::binder::Status OnGetPlayerAppAttrsText(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) override;
  ::android::binder::Status OnGetPlayerAppValuesText(const ::android::String16& addr, int32_t attr_id, const ::std::vector<int32_t>& values) override;
  ::android::binder::Status OnSetPlayerAppValue(const ::android::String16& addr, const ::std::vector<::android::bluetooth::BluetoothAvrcpIntValue>& values) override;
  ::android::binder::Status OnGetElementAttrs(const ::android::String16& addr, const ::std::vector<int32_t>& attrs) override;
  ::android::binder::Status OnRegisterNotification(const ::android::String16& addr, int32_t event_id, int32_t param) override;
  ::android::binder::Status OnVolumeChange(const ::android::String16& addr, int32_t volume, int32_t ctype) override;
  ::android::binder::Status OnPassThroughCommand(const ::android::String16& addr, int32_t id, int32_t key_state) override;
};  // class BpBluetoothAvrcpTargetCallback
}  // namespace bluetooth
}  // namespace android
