#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothGattClientCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothGattClientCallback : public ::android::BpInterface<IBluetoothGattClientCallback> {
public:
  explicit BpBluetoothGattClientCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothGattClientCallback() = default;
  ::android::binder::Status OnClientRegistered(int32_t status, int32_t client_id) override;
};  // class BpBluetoothGattClientCallback
}  // namespace bluetooth
}  // namespace android
