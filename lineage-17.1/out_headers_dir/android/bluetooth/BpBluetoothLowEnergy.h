#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothLowEnergy.h>

namespace android {
namespace bluetooth {
class BpBluetoothLowEnergy : public ::android::BpInterface<IBluetoothLowEnergy> {
public:
  explicit BpBluetoothLowEnergy(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothLowEnergy() = default;
  ::android::binder::Status RegisterClient(const ::android::sp<::android::bluetooth::IBluetoothLowEnergyCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status UnregisterClient(int32_t client_if) override;
  ::android::binder::Status UnregisterAll() override;
  ::android::binder::Status Connect(int32_t client_id, const ::android::String16& address, bool is_direct, bool* _aidl_return) override;
  ::android::binder::Status Disconnect(int32_t client_id, const ::android::String16& address, bool* _aidl_return) override;
  ::android::binder::Status SetMtu(int32_t client_id, const ::android::String16& address, int32_t mtu, bool* _aidl_return) override;
};  // class BpBluetoothLowEnergy
}  // namespace bluetooth
}  // namespace android
