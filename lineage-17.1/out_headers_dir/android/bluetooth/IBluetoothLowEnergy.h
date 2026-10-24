#pragma once

#include <android/bluetooth/IBluetoothLowEnergyCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android::bluetooth {
class IBluetoothLowEnergyCallback;
}  // namespace android::bluetooth
namespace android {
namespace bluetooth {
class IBluetoothLowEnergyDelegator;

class IBluetoothLowEnergy : public ::android::IInterface {
public:
  typedef IBluetoothLowEnergyDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothLowEnergy)
  virtual ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothLowEnergyCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status UnregisterClient(int32_t client_if) = 0;
  virtual ::android::binder::Status UnregisterAll() = 0;
  virtual ::android::binder::Status Connect(int32_t client_id, const ::android::String16& address, bool is_direct, bool* _aidl_return) = 0;
  virtual ::android::binder::Status Disconnect(int32_t client_id, const ::android::String16& address, bool* _aidl_return) = 0;
  virtual ::android::binder::Status SetMtu(int32_t client_id, const ::android::String16& address, int32_t mtu, bool* _aidl_return) = 0;
};  // class IBluetoothLowEnergy

class IBluetoothLowEnergyDefault : public IBluetoothLowEnergy {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothLowEnergyCallback>& /*callback*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterClient(int32_t /*client_if*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterAll() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Connect(int32_t /*client_id*/, const ::android::String16& /*address*/, bool /*is_direct*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status Disconnect(int32_t /*client_id*/, const ::android::String16& /*address*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status SetMtu(int32_t /*client_id*/, const ::android::String16& /*address*/, int32_t /*mtu*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothLowEnergyDefault
}  // namespace bluetooth
}  // namespace android
