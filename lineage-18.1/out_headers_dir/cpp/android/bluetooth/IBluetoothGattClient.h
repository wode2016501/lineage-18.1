#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_GATT_CLIENT_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_GATT_CLIENT_H_

#include <android/bluetooth/IBluetoothGattClientCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace bluetooth {

class IBluetoothGattClient : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BluetoothGattClient)
  virtual ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothGattClientCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status UnregisterClient(int32_t client_id) = 0;
  virtual ::android::binder::Status UnregisterAll() = 0;
};  // class IBluetoothGattClient

class IBluetoothGattClientDefault : public IBluetoothGattClient {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothGattClientCallback>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterClient(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterAll() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothGattClientDefault

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_GATT_CLIENT_H_
