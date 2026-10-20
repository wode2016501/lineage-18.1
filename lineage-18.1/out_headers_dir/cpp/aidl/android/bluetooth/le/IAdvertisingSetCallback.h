#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace bluetooth {
namespace le {
class IAdvertisingSetCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IAdvertisingSetCallback();
  virtual ~IAdvertisingSetCallback();



  static std::shared_ptr<IAdvertisingSetCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IAdvertisingSetCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IAdvertisingSetCallback>* instance);
  static bool setDefaultImpl(std::shared_ptr<IAdvertisingSetCallback> impl);
  static const std::shared_ptr<IAdvertisingSetCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onAdvertisingSetStarted(int32_t in_advertiserId, int32_t in_tx_power, int32_t in_status) = 0;
  virtual ::ndk::ScopedAStatus onOwnAddressRead(int32_t in_advertiserId, int32_t in_addressType, const std::string& in_address) = 0;
  virtual ::ndk::ScopedAStatus onAdvertisingSetStopped(int32_t in_advertiserId) = 0;
  virtual ::ndk::ScopedAStatus onAdvertisingEnabled(int32_t in_advertiserId, bool in_enable, int32_t in_status) = 0;
  virtual ::ndk::ScopedAStatus onAdvertisingDataSet(int32_t in_advertiserId, int32_t in_status) = 0;
  virtual ::ndk::ScopedAStatus onScanResponseDataSet(int32_t in_advertiserId, int32_t in_status) = 0;
  virtual ::ndk::ScopedAStatus onAdvertisingParametersUpdated(int32_t in_advertiserId, int32_t in_tx_power, int32_t in_status) = 0;
  virtual ::ndk::ScopedAStatus onPeriodicAdvertisingParametersUpdated(int32_t in_advertiserId, int32_t in_status) = 0;
  virtual ::ndk::ScopedAStatus onPeriodicAdvertisingDataSet(int32_t in_advertiserId, int32_t in_status) = 0;
  virtual ::ndk::ScopedAStatus onPeriodicAdvertisingEnabled(int32_t in_advertiserId, bool in_enable, int32_t in_status) = 0;
private:
  static std::shared_ptr<IAdvertisingSetCallback> default_impl;
};
class IAdvertisingSetCallbackDefault : public IAdvertisingSetCallback {
public:
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
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace le
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
