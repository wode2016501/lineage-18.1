#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_AVRCP_TARGET_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_AVRCP_TARGET_H_

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothAvrcpTarget.h>

namespace android {

namespace bluetooth {

class BnBluetoothAvrcpTarget : public ::android::BnInterface<IBluetoothAvrcpTarget> {
public:
  explicit BnBluetoothAvrcpTarget();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothAvrcpTarget

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_AVRCP_TARGET_H_
