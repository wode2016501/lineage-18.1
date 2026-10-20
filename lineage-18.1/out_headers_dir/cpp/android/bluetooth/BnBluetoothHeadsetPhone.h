#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_HEADSET_PHONE_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_HEADSET_PHONE_H_

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothHeadsetPhone.h>

namespace android {

namespace bluetooth {

class BnBluetoothHeadsetPhone : public ::android::BnInterface<IBluetoothHeadsetPhone> {
public:
  explicit BnBluetoothHeadsetPhone();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothHeadsetPhone

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_HEADSET_PHONE_H_
