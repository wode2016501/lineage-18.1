#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace bluetooth {

class IBluetoothCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BluetoothCallback)
  virtual ::android::binder::Status onBluetoothStateChange(int32_t prevState, int32_t newState) = 0;
};  // class IBluetoothCallback

class IBluetoothCallbackDefault : public IBluetoothCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onBluetoothStateChange(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothCallbackDefault

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_CALLBACK_H_
