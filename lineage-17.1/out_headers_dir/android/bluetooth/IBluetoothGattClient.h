#pragma once

#include <android/bluetooth/IBluetoothGattClientCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android::bluetooth {
class IBluetoothGattClientCallback;
}  // namespace android::bluetooth
namespace android {
namespace bluetooth {
class IBluetoothGattClientDelegator;

class IBluetoothGattClient : public ::android::IInterface {
public:
  typedef IBluetoothGattClientDelegator DefaultDelegator;
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
  ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothGattClientCallback>& /*callback*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterClient(int32_t /*client_id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterAll() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothGattClientDefault
}  // namespace bluetooth
}  // namespace android
