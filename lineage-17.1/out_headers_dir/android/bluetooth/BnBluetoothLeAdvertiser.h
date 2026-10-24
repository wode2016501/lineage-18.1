#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothLeAdvertiser.h>
#include <android/bluetooth/BnBluetoothLeAdvertiser.h>
#include <android/bluetooth/BnBluetoothLeAdvertiserCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothLeAdvertiser : public ::android::BnInterface<IBluetoothLeAdvertiser> {
public:
  static constexpr uint32_t TRANSACTION_RegisterAdvertiser = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_UnregisterAdvertiser = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_UnregisterAll = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_StartMultiAdvertising = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_StopMultiAdvertising = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnBluetoothLeAdvertiser();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothLeAdvertiser

class IBluetoothLeAdvertiserDelegator : public BnBluetoothLeAdvertiser {
public:
  explicit IBluetoothLeAdvertiserDelegator(const ::android::sp<IBluetoothLeAdvertiser> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothLeAdvertiser> getImpl() { return _aidl_delegate; }
  ::android::binder::Status RegisterAdvertiser(const ::android::sp<::android::bluetooth::IBluetoothLeAdvertiserCallback>& callback, bool* _aidl_return) override {
    ::android::sp<::android::bluetooth::IBluetoothLeAdvertiserCallbackDelegator> _callback;
    if (callback) {
      _callback = ::android::sp<::android::bluetooth::IBluetoothLeAdvertiserCallbackDelegator>::cast(delegate(callback));
    }
    return _aidl_delegate->RegisterAdvertiser(_callback, _aidl_return);
  }
  ::android::binder::Status UnregisterAdvertiser(int32_t advertiser_id) override {
    return _aidl_delegate->UnregisterAdvertiser(advertiser_id);
  }
  ::android::binder::Status UnregisterAll() override {
    return _aidl_delegate->UnregisterAll();
  }
  ::android::binder::Status StartMultiAdvertising(int32_t advertiser_id, const ::android::bluetooth::AdvertiseData& advertise_data, const ::android::bluetooth::AdvertiseData& scan_response, const ::android::bluetooth::AdvertiseSettings& settings, bool* _aidl_return) override {
    return _aidl_delegate->StartMultiAdvertising(advertiser_id, advertise_data, scan_response, settings, _aidl_return);
  }
  ::android::binder::Status StopMultiAdvertising(int32_t advertiser_id, bool* _aidl_return) override {
    return _aidl_delegate->StopMultiAdvertising(advertiser_id, _aidl_return);
  }
private:
  ::android::sp<IBluetoothLeAdvertiser> _aidl_delegate;
};  // class IBluetoothLeAdvertiserDelegator
}  // namespace bluetooth
}  // namespace android
