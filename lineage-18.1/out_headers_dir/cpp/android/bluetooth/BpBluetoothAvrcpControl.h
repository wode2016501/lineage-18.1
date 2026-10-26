#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_AVRCP_CONTROL_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_AVRCP_CONTROL_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothAvrcpControl.h>

namespace android {

namespace bluetooth {

class BpBluetoothAvrcpControl : public ::android::BpInterface<IBluetoothAvrcpControl> {
public:
  explicit BpBluetoothAvrcpControl(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothAvrcpControl() = default;
  ::android::binder::Status Register(const ::android::sp<::android::bluetooth::IBluetoothAvrcpControlCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status Unregister(int32_t id) override;
  ::android::binder::Status UnregisterAll() override;
  ::android::binder::Status Enable(int32_t id, bool* _aidl_return) override;
  ::android::binder::Status Disable(int32_t id, bool* _aidl_return) override;
  ::android::binder::Status SendPassThroughCommand(int32_t id, const ::android::String16& device_address, int32_t key_code, bool key_pressed, bool* _aidl_return) override;
  ::android::binder::Status SetAbsVolumeResponse(int32_t id, const ::android::String16& device_address, int32_t abs_vol, int32_t label, bool* _aidl_return) override;
  ::android::binder::Status RegisterForAbsVolumeCallbackResponse(int32_t id, const ::android::String16& device_address, int32_t response_type, int32_t abs_vol, int32_t label, bool* _aidl_return) override;
};  // class BpBluetoothAvrcpControl

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_AVRCP_CONTROL_H_
