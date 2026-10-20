#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_STATE_CHANGE_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_STATE_CHANGE_CALLBACK_H_

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothStateChangeCallback.h>

namespace android {

namespace bluetooth {

class BnBluetoothStateChangeCallback : public ::android::BnInterface<IBluetoothStateChangeCallback> {
public:
  explicit BnBluetoothStateChangeCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothStateChangeCallback

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_STATE_CHANGE_CALLBACK_H_
