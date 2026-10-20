#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_LE_I_ADVERTISING_SET_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_LE_I_ADVERTISING_SET_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace bluetooth {

namespace le {

class IAdvertisingSetCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AdvertisingSetCallback)
  virtual ::android::binder::Status onAdvertisingSetStarted(int32_t advertiserId, int32_t tx_power, int32_t status) = 0;
  virtual ::android::binder::Status onOwnAddressRead(int32_t advertiserId, int32_t addressType, const ::android::String16& address) = 0;
  virtual ::android::binder::Status onAdvertisingSetStopped(int32_t advertiserId) = 0;
  virtual ::android::binder::Status onAdvertisingEnabled(int32_t advertiserId, bool enable, int32_t status) = 0;
  virtual ::android::binder::Status onAdvertisingDataSet(int32_t advertiserId, int32_t status) = 0;
  virtual ::android::binder::Status onScanResponseDataSet(int32_t advertiserId, int32_t status) = 0;
  virtual ::android::binder::Status onAdvertisingParametersUpdated(int32_t advertiserId, int32_t tx_power, int32_t status) = 0;
  virtual ::android::binder::Status onPeriodicAdvertisingParametersUpdated(int32_t advertiserId, int32_t status) = 0;
  virtual ::android::binder::Status onPeriodicAdvertisingDataSet(int32_t advertiserId, int32_t status) = 0;
  virtual ::android::binder::Status onPeriodicAdvertisingEnabled(int32_t advertiserId, bool enable, int32_t status) = 0;
};  // class IAdvertisingSetCallback

class IAdvertisingSetCallbackDefault : public IAdvertisingSetCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onAdvertisingSetStarted(int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onOwnAddressRead(int32_t, int32_t, const ::android::String16&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAdvertisingSetStopped(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAdvertisingEnabled(int32_t, bool, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAdvertisingDataSet(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onScanResponseDataSet(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onAdvertisingParametersUpdated(int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPeriodicAdvertisingParametersUpdated(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPeriodicAdvertisingDataSet(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPeriodicAdvertisingEnabled(int32_t, bool, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAdvertisingSetCallbackDefault

}  // namespace le

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_LE_I_ADVERTISING_SET_CALLBACK_H_
