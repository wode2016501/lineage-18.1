#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {
namespace bluetooth {
class IBluetoothLowEnergyCallbackDelegator;

class IBluetoothLowEnergyCallback : public ::android::IInterface {
public:
  typedef IBluetoothLowEnergyCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothLowEnergyCallback)
  virtual ::android::binder::Status OnClientRegistered(int32_t status, int32_t client_id) = 0;
  virtual ::android::binder::Status OnConnectionState(int32_t status, int32_t client_id, const ::android::String16& address, bool connected) = 0;
  virtual ::android::binder::Status OnMtuChanged(int32_t status, const ::android::String16& address, int32_t mtu) = 0;
};  // class IBluetoothLowEnergyCallback

class IBluetoothLowEnergyCallbackDefault : public IBluetoothLowEnergyCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnClientRegistered(int32_t /*status*/, int32_t /*client_id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnConnectionState(int32_t /*status*/, int32_t /*client_id*/, const ::android::String16& /*address*/, bool /*connected*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnMtuChanged(int32_t /*status*/, const ::android::String16& /*address*/, int32_t /*mtu*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothLowEnergyCallbackDefault
}  // namespace bluetooth
}  // namespace android
