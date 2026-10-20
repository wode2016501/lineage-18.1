#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_GATT_CLIENT_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_GATT_CLIENT_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace bluetooth {

class IBluetoothGattClientCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BluetoothGattClientCallback)
  virtual ::android::binder::Status OnClientRegistered(int32_t status, int32_t client_id) = 0;
};  // class IBluetoothGattClientCallback

class IBluetoothGattClientCallbackDefault : public IBluetoothGattClientCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnClientRegistered(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothGattClientCallbackDefault

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_GATT_CLIENT_CALLBACK_H_
