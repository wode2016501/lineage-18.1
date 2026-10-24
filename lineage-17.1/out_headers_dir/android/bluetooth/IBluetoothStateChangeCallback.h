#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {
namespace bluetooth {
class IBluetoothStateChangeCallbackDelegator;

class IBluetoothStateChangeCallback : public ::android::IInterface {
public:
  typedef IBluetoothStateChangeCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothStateChangeCallback)
  virtual ::android::binder::Status onBluetoothStateChange(bool on) = 0;
};  // class IBluetoothStateChangeCallback

class IBluetoothStateChangeCallbackDefault : public IBluetoothStateChangeCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onBluetoothStateChange(bool /*on*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothStateChangeCallbackDefault
}  // namespace bluetooth
}  // namespace android
