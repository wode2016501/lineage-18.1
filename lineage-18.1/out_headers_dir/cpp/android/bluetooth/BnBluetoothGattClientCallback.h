#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_GATT_CLIENT_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_GATT_CLIENT_CALLBACK_H_

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothGattClientCallback.h>

namespace android {

namespace bluetooth {

class BnBluetoothGattClientCallback : public ::android::BnInterface<IBluetoothGattClientCallback> {
public:
  explicit BnBluetoothGattClientCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothGattClientCallback

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_GATT_CLIENT_CALLBACK_H_
