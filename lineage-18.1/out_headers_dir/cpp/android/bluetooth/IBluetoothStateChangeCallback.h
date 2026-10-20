#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_STATE_CHANGE_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_STATE_CHANGE_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace bluetooth {

class IBluetoothStateChangeCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BluetoothStateChangeCallback)
  virtual ::android::binder::Status onBluetoothStateChange(bool on) = 0;
};  // class IBluetoothStateChangeCallback

class IBluetoothStateChangeCallbackDefault : public IBluetoothStateChangeCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onBluetoothStateChange(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothStateChangeCallbackDefault

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_STATE_CHANGE_CALLBACK_H_
