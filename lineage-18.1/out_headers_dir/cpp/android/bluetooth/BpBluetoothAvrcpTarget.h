#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_AVRCP_TARGET_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_AVRCP_TARGET_H_

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
  ::android::binder::Status sendVolumeChanged(int32_t volume) override;
};  // class BpBluetoothAvrcpTarget

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_AVRCP_TARGET_H_
