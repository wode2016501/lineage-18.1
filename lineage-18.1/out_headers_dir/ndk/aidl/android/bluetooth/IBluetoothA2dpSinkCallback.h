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
class IBluetoothA2dpSinkCallback : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBluetoothA2dpSinkCallback();
  virtual ~IBluetoothA2dpSinkCallback();



  static std::shared_ptr<IBluetoothA2dpSinkCallback> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothA2dpSinkCallback>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothA2dpSinkCallback>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBluetoothA2dpSinkCallback> impl);
  static const std::shared_ptr<IBluetoothA2dpSinkCallback>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus OnRegistered(int32_t in_status) = 0;
  virtual ::ndk::ScopedAStatus OnConnectionState(const std::string& in_device_address, int32_t in_state) = 0;
  virtual ::ndk::ScopedAStatus OnAudioState(const std::string& in_device_address, int32_t in_state) = 0;
  virtual ::ndk::ScopedAStatus OnAudioConfig(const std::string& in_device_address, int32_t in_sample_rate, int32_t in_channel_count) = 0;
private:
  static std::shared_ptr<IBluetoothA2dpSinkCallback> default_impl;
};
class IBluetoothA2dpSinkCallbackDefault : public IBluetoothA2dpSinkCallback {
public:
  ::ndk::ScopedAStatus OnRegistered(int32_t in_status) override;
  ::ndk::ScopedAStatus OnConnectionState(const std::string& in_device_address, int32_t in_state) override;
  ::ndk::ScopedAStatus OnAudioState(const std::string& in_device_address, int32_t in_state) override;
  ::ndk::ScopedAStatus OnAudioConfig(const std::string& in_device_address, int32_t in_sample_rate, int32_t in_channel_count) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
