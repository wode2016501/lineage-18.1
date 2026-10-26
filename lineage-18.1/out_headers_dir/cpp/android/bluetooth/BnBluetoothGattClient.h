#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_GATT_CLIENT_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_GATT_CLIENT_H_

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothGattClient.h>

namespace android {

namespace bluetooth {

class BnBluetoothGattClient : public ::android::BnInterface<IBluetoothGattClient> {
public:
  explicit BnBluetoothGattClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothGattClient

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_GATT_CLIENT_H_
