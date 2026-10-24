#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {
namespace bluetooth {
class IBluetoothGattClientCallbackDelegator;

class IBluetoothGattClientCallback : public ::android::IInterface {
public:
  typedef IBluetoothGattClientCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothGattClientCallback)
  virtual ::android::binder::Status OnClientRegistered(int32_t status, int32_t client_id) = 0;
};  // class IBluetoothGattClientCallback

class IBluetoothGattClientCallbackDefault : public IBluetoothGattClientCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnClientRegistered(int32_t /*status*/, int32_t /*client_id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothGattClientCallbackDefault
}  // namespace bluetooth
}  // namespace android
