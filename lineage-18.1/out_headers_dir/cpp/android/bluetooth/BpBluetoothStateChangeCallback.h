#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_STATE_CHANGE_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_STATE_CHANGE_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothStateChangeCallback.h>

namespace android {

namespace bluetooth {

class BpBluetoothStateChangeCallback : public ::android::BpInterface<IBluetoothStateChangeCallback> {
public:
  explicit BpBluetoothStateChangeCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothStateChangeCallback() = default;
  ::android::binder::Status onBluetoothStateChange(bool on) override;
};  // class BpBluetoothStateChangeCallback

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_STATE_CHANGE_CALLBACK_H_
