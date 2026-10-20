#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_GATT_CLIENT_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_GATT_CLIENT_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothGattClientCallback.h>

namespace android {

namespace bluetooth {

class BpBluetoothGattClientCallback : public ::android::BpInterface<IBluetoothGattClientCallback> {
public:
  explicit BpBluetoothGattClientCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothGattClientCallback() = default;
  ::android::binder::Status OnClientRegistered(int32_t status, int32_t client_id) override;
};  // class BpBluetoothGattClientCallback

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_GATT_CLIENT_CALLBACK_H_
