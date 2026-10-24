#pragma once

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
