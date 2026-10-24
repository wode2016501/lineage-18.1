#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/le/IAdvertisingSetCallback.h>

namespace android {
namespace bluetooth {
namespace le {
class BpAdvertisingSetCallback : public ::android::BpInterface<IAdvertisingSetCallback> {
public:
  explicit BpAdvertisingSetCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAdvertisingSetCallback() = default;
  ::android::binder::Status onAdvertisingSetStarted(int32_t advertiserId, int32_t tx_power, int32_t status) override;
  ::android::binder::Status onOwnAddressRead(int32_t advertiserId, int32_t addressType, const ::android::String16& address) override;
  ::android::binder::Status onAdvertisingSetStopped(int32_t advertiserId) override;
  ::android::binder::Status onAdvertisingEnabled(int32_t advertiserId, bool enable, int32_t status) override;
  ::android::binder::Status onAdvertisingDataSet(int32_t advertiserId, int32_t status) override;
  ::android::binder::Status onScanResponseDataSet(int32_t advertiserId, int32_t status) override;
  ::android::binder::Status onAdvertisingParametersUpdated(int32_t advertiserId, int32_t tx_power, int32_t status) override;
  ::android::binder::Status onPeriodicAdvertisingParametersUpdated(int32_t advertiserId, int32_t status) override;
  ::android::binder::Status onPeriodicAdvertisingDataSet(int32_t advertiserId, int32_t status) override;
  ::android::binder::Status onPeriodicAdvertisingEnabled(int32_t advertiserId, bool enable, int32_t status) override;
};  // class BpAdvertisingSetCallback
}  // namespace le
}  // namespace bluetooth
}  // namespace android
