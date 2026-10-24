#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothLowEnergyCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothLowEnergyCallback : public ::android::BpInterface<IBluetoothLowEnergyCallback> {
public:
  explicit BpBluetoothLowEnergyCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothLowEnergyCallback() = default;
  ::android::binder::Status OnClientRegistered(int32_t status, int32_t client_id) override;
  ::android::binder::Status OnConnectionState(int32_t status, int32_t client_id, const ::android::String16& address, bool connected) override;
  ::android::binder::Status OnMtuChanged(int32_t status, const ::android::String16& address, int32_t mtu) override;
};  // class BpBluetoothLowEnergyCallback
}  // namespace bluetooth
}  // namespace android
