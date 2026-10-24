#pragma once

#include <android/bluetooth/IBluetoothLeAdvertiserCallback.h>
#include <android/bluetooth/advertise_data.h>
#include <android/bluetooth/advertise_settings.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android::bluetooth {
class IBluetoothLeAdvertiserCallback;
}  // namespace android::bluetooth
namespace android {
namespace bluetooth {
class IBluetoothLeAdvertiserDelegator;

class IBluetoothLeAdvertiser : public ::android::IInterface {
public:
  typedef IBluetoothLeAdvertiserDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothLeAdvertiser)
  virtual ::android::binder::Status RegisterAdvertiser(const ::android::sp<::android::bluetooth::IBluetoothLeAdvertiserCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status UnregisterAdvertiser(int32_t advertiser_id) = 0;
  virtual ::android::binder::Status UnregisterAll() = 0;
  virtual ::android::binder::Status StartMultiAdvertising(int32_t advertiser_id, const ::android::bluetooth::AdvertiseData& advertise_data, const ::android::bluetooth::AdvertiseData& scan_response, const ::android::bluetooth::AdvertiseSettings& settings, bool* _aidl_return) = 0;
  virtual ::android::binder::Status StopMultiAdvertising(int32_t advertiser_id, bool* _aidl_return) = 0;
};  // class IBluetoothLeAdvertiser

class IBluetoothLeAdvertiserDefault : public IBluetoothLeAdvertiser {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status RegisterAdvertiser(const ::android::sp<::android::bluetooth::IBluetoothLeAdvertiserCallback>& /*callback*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterAdvertiser(int32_t /*advertiser_id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status UnregisterAll() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status StartMultiAdvertising(int32_t /*advertiser_id*/, const ::android::bluetooth::AdvertiseData& /*advertise_data*/, const ::android::bluetooth::AdvertiseData& /*scan_response*/, const ::android::bluetooth::AdvertiseSettings& /*settings*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status StopMultiAdvertising(int32_t /*advertiser_id*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothLeAdvertiserDefault
}  // namespace bluetooth
}  // namespace android
