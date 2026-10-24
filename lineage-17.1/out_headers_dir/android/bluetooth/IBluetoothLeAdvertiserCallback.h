#pragma once

#include <android/bluetooth/advertise_settings.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {
namespace bluetooth {
class IBluetoothLeAdvertiserCallbackDelegator;

class IBluetoothLeAdvertiserCallback : public ::android::IInterface {
public:
  typedef IBluetoothLeAdvertiserCallbackDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothLeAdvertiserCallback)
  virtual ::android::binder::Status OnAdvertiserRegistered(int32_t status, int32_t advertiser_id) = 0;
  virtual ::android::binder::Status OnMultiAdvertiseCallback(int32_t status, bool is_start, const ::android::bluetooth::AdvertiseSettings& settings) = 0;
};  // class IBluetoothLeAdvertiserCallback

class IBluetoothLeAdvertiserCallbackDefault : public IBluetoothLeAdvertiserCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnAdvertiserRegistered(int32_t /*status*/, int32_t /*advertiser_id*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnMultiAdvertiseCallback(int32_t /*status*/, bool /*is_start*/, const ::android::bluetooth::AdvertiseSettings& /*settings*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothLeAdvertiserCallbackDefault
}  // namespace bluetooth
}  // namespace android
