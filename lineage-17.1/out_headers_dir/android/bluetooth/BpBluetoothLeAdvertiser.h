#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothLeAdvertiser.h>

namespace android {
namespace bluetooth {
class BpBluetoothLeAdvertiser : public ::android::BpInterface<IBluetoothLeAdvertiser> {
public:
  explicit BpBluetoothLeAdvertiser(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothLeAdvertiser() = default;
  ::android::binder::Status RegisterAdvertiser(const ::android::sp<::android::bluetooth::IBluetoothLeAdvertiserCallback>& callback, bool* _aidl_return) override;
  ::android::binder::Status UnregisterAdvertiser(int32_t advertiser_id) override;
  ::android::binder::Status UnregisterAll() override;
  ::android::binder::Status StartMultiAdvertising(int32_t advertiser_id, const ::android::bluetooth::AdvertiseData& advertise_data, const ::android::bluetooth::AdvertiseData& scan_response, const ::android::bluetooth::AdvertiseSettings& settings, bool* _aidl_return) override;
  ::android::binder::Status StopMultiAdvertising(int32_t advertiser_id, bool* _aidl_return) override;
};  // class BpBluetoothLeAdvertiser
}  // namespace bluetooth
}  // namespace android
