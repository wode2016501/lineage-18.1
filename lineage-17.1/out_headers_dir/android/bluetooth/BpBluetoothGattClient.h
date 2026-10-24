#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothGattClient.h>

namespace android {
namespace bluetooth {
class BpBluetoothGattClient : public ::android::BpInterface<IBluetoothGattClient> {
public:
  explicit BpBluetoothGattClient(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothGattClient() = default;
  ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothGattClientCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status UnregisterClient(int32_t client_id) override;
  ::android::binder::Status UnregisterAll() override;
};  // class BpBluetoothGattClient
}  // namespace bluetooth
}  // namespace android
