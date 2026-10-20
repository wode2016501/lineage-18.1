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
class IBluetoothStateChangeCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBluetoothStateChangeCallback();
  virtual ~IBluetoothStateChangeCallback();



  static std::shared_ptr<IBluetoothStateChangeCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothStateChangeCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothStateChangeCallback>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBluetoothStateChangeCallback> impl);
  static const std::shared_ptr<IBluetoothStateChangeCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onBluetoothStateChange(bool in_on) = 0;
private:
  static std::shared_ptr<IBluetoothStateChangeCallback> default_impl;
};
class IBluetoothStateChangeCallbackDefault : public IBluetoothStateChangeCallback {
public:
  ::ndk::ScopedAStatus onBluetoothStateChange(bool in_on) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
