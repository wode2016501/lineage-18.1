#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothLeAdvertiserCallback.h>

namespace android {
namespace bluetooth {
class BpBluetoothLeAdvertiserCallback : public ::android::BpInterface<IBluetoothLeAdvertiserCallback> {
public:
  explicit BpBluetoothLeAdvertiserCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothLeAdvertiserCallback() = default;
  ::android::binder::Status OnAdvertiserRegistered(int32_t status, int32_t advertiser_id) override;
  ::android::binder::Status OnMultiAdvertiseCallback(int32_t status, bool is_start, const ::android::bluetooth::AdvertiseSettings& settings) override;
};  // class BpBluetoothLeAdvertiserCallback
}  // namespace bluetooth
}  // namespace android
