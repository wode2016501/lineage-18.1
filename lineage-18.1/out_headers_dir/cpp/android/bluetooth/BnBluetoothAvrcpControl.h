#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_AVRCP_CONTROL_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_AVRCP_CONTROL_H_

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothAvrcpControl.h>

namespace android {

namespace bluetooth {

class BnBluetoothAvrcpControl : public ::android::BnInterface<IBluetoothAvrcpControl> {
public:
  explicit BnBluetoothAvrcpControl();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothAvrcpControl

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_AVRCP_CONTROL_H_
