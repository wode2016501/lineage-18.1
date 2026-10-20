#pragma once

#include "aidl/android/bluetooth/le/IAdvertisingSetCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
namespace le {
class BpAdvertisingSetCallback : public ::ndk::BpCInterface<IAdvertisingSetCallback> {
public:
  BpAdvertisingSetCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpAdvertisingSetCallback();

  ::ndk::ScopedAStatus onAdvertisingSetStarted(int32_t in_advertiserId, int32_t in_tx_power, int32_t in_status) override;
  ::ndk::ScopedAStatus onOwnAddressRead(int32_t in_advertiserId, int32_t in_addressType, const std::string& in_address) override;
  ::ndk::ScopedAStatus onAdvertisingSetStopped(int32_t in_advertiserId) override;
  ::ndk::ScopedAStatus onAdvertisingEnabled(int32_t in_advertiserId, bool in_enable, int32_t in_status) override;
  ::ndk::ScopedAStatus onAdvertisingDataSet(int32_t in_advertiserId, int32_t in_status) override;
  ::ndk::ScopedAStatus onScanResponseDataSet(int32_t in_advertiserId, int32_t in_status) override;
  ::ndk::ScopedAStatus onAdvertisingParametersUpdated(int32_t in_advertiserId, int32_t in_tx_power, int32_t in_status) override;
  ::ndk::ScopedAStatus onPeriodicAdvertisingParametersUpdated(int32_t in_advertiserId, int32_t in_status) override;
  ::ndk::ScopedAStatus onPeriodicAdvertisingDataSet(int32_t in_advertiserId, int32_t in_status) override;
  ::ndk::ScopedAStatus onPeriodicAdvertisingEnabled(int32_t in_advertiserId, bool in_enable, int32_t in_status) override;
};
}  // namespace le
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
