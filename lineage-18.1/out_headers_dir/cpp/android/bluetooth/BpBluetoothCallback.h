#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothCallback.h>

namespace android {

namespace bluetooth {

class BpBluetoothCallback : public ::android::BpInterface<IBluetoothCallback> {
public:
  explicit BpBluetoothCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothCallback() = default;
  ::android::binder::Status onBluetoothStateChange(int32_t prevState, int32_t newState) override;
};  // class BpBluetoothCallback

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_CALLBACK_H_
