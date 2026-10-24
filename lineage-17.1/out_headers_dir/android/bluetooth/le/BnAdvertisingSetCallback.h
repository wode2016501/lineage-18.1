#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/le/IAdvertisingSetCallback.h>
#include <android/bluetooth/le/BnAdvertisingSetCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
namespace le {
class BnAdvertisingSetCallback : public ::android::BnInterface<IAdvertisingSetCallback> {
public:
  static constexpr uint32_t TRANSACTION_onAdvertisingSetStarted = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onOwnAddressRead = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onAdvertisingSetStopped = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onAdvertisingEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onAdvertisingDataSet = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onScanResponseDataSet = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onAdvertisingParametersUpdated = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_onPeriodicAdvertisingParametersUpdated = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_onPeriodicAdvertisingDataSet = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_onPeriodicAdvertisingEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  explicit BnAdvertisingSetCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAdvertisingSetCallback

class IAdvertisingSetCallbackDelegator : public BnAdvertisingSetCallback {
public:
  explicit IAdvertisingSetCallbackDelegator(const ::android::sp<IAdvertisingSetCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IAdvertisingSetCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onAdvertisingSetStarted(int32_t advertiserId, int32_t tx_power, int32_t status) override {
    return _aidl_delegate->onAdvertisingSetStarted(advertiserId, tx_power, status);
  }
  ::android::binder::Status onOwnAddressRead(int32_t advertiserId, int32_t addressType, const ::android::String16& address) override {
    return _aidl_delegate->onOwnAddressRead(advertiserId, addressType, address);
  }
  ::android::binder::Status onAdvertisingSetStopped(int32_t advertiserId) override {
    return _aidl_delegate->onAdvertisingSetStopped(advertiserId);
  }
  ::android::binder::Status onAdvertisingEnabled(int32_t advertiserId, bool enable, int32_t status) override {
    return _aidl_delegate->onAdvertisingEnabled(advertiserId, enable, status);
  }
  ::android::binder::Status onAdvertisingDataSet(int32_t advertiserId, int32_t status) override {
    return _aidl_delegate->onAdvertisingDataSet(advertiserId, status);
  }
  ::android::binder::Status onScanResponseDataSet(int32_t advertiserId, int32_t status) override {
    return _aidl_delegate->onScanResponseDataSet(advertiserId, status);
  }
  ::android::binder::Status onAdvertisingParametersUpdated(int32_t advertiserId, int32_t tx_power, int32_t status) override {
    return _aidl_delegate->onAdvertisingParametersUpdated(advertiserId, tx_power, status);
  }
  ::android::binder::Status onPeriodicAdvertisingParametersUpdated(int32_t advertiserId, int32_t status) override {
    return _aidl_delegate->onPeriodicAdvertisingParametersUpdated(advertiserId, status);
  }
  ::android::binder::Status onPeriodicAdvertisingDataSet(int32_t advertiserId, int32_t status) override {
    return _aidl_delegate->onPeriodicAdvertisingDataSet(advertiserId, status);
  }
  ::android::binder::Status onPeriodicAdvertisingEnabled(int32_t advertiserId, bool enable, int32_t status) override {
    return _aidl_delegate->onPeriodicAdvertisingEnabled(advertiserId, enable, status);
  }
private:
  ::android::sp<IAdvertisingSetCallback> _aidl_delegate;
};  // class IAdvertisingSetCallbackDelegator
}  // namespace le
}  // namespace bluetooth
}  // namespace android
