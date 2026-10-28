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
class IBluetoothCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBluetoothCallback();
  virtual ~IBluetoothCallback();



  static std::shared_ptr<IBluetoothCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothCallback>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBluetoothCallback> impl);
  static const std::shared_ptr<IBluetoothCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onBluetoothStateChange(int32_t in_prevState, int32_t in_newState) = 0;
private:
  static std::shared_ptr<IBluetoothCallback> default_impl;
};
class IBluetoothCallbackDefault : public IBluetoothCallback {
public:
  ::ndk::ScopedAStatus onBluetoothStateChange(int32_t in_prevState, int32_t in_newState) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
