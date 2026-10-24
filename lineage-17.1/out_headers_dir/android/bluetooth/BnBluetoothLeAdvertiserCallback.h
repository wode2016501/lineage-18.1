#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothLeAdvertiserCallback.h>
#include <android/bluetooth/BnBluetoothLeAdvertiserCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothLeAdvertiserCallback : public ::android::BnInterface<IBluetoothLeAdvertiserCallback> {
public:
  static constexpr uint32_t TRANSACTION_OnAdvertiserRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnMultiAdvertiseCallback = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnBluetoothLeAdvertiserCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothLeAdvertiserCallback

class IBluetoothLeAdvertiserCallbackDelegator : public BnBluetoothLeAdvertiserCallback {
public:
  explicit IBluetoothLeAdvertiserCallbackDelegator(const ::android::sp<IBluetoothLeAdvertiserCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothLeAdvertiserCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status OnAdvertiserRegistered(int32_t status, int32_t advertiser_id) override {
    return _aidl_delegate->OnAdvertiserRegistered(status, advertiser_id);
  }
  ::android::binder::Status OnMultiAdvertiseCallback(int32_t status, bool is_start, const ::android::bluetooth::AdvertiseSettings& settings) override {
    return _aidl_delegate->OnMultiAdvertiseCallback(status, is_start, settings);
  }
private:
  ::android::sp<IBluetoothLeAdvertiserCallback> _aidl_delegate;
};  // class IBluetoothLeAdvertiserCallbackDelegator
}  // namespace bluetooth
}  // namespace android
