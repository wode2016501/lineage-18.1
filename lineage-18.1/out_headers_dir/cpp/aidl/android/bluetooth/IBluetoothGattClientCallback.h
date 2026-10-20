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
class IBluetoothGattClientCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBluetoothGattClientCallback();
  virtual ~IBluetoothGattClientCallback();



  static std::shared_ptr<IBluetoothGattClientCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothGattClientCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothGattClientCallback>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBluetoothGattClientCallback> impl);
  static const std::shared_ptr<IBluetoothGattClientCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus OnClientRegistered(int32_t in_status, int32_t in_client_id) = 0;
private:
  static std::shared_ptr<IBluetoothGattClientCallback> default_impl;
};
class IBluetoothGattClientCallbackDefault : public IBluetoothGattClientCallback {
public:
  ::ndk::ScopedAStatus OnClientRegistered(int32_t in_status, int32_t in_client_id) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
