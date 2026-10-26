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
#include <aidl/android/bluetooth/IBluetoothA2dpSinkCallback.h>

namespace aidl {
namespace android {
namespace bluetooth {
class IBluetoothA2dpSink : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBluetoothA2dpSink();
  virtual ~IBluetoothA2dpSink();



  static std::shared_ptr<IBluetoothA2dpSink> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothA2dpSink>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothA2dpSink>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBluetoothA2dpSink> impl);
  static const std::shared_ptr<IBluetoothA2dpSink>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus Register(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothA2dpSinkCallback>& in_callback, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus Unregister() = 0;
  virtual ::ndk::ScopedAStatus Enable(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus Disable(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus Connect(const std::string& in_device_address, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus Disconnect(const std::string& in_device_address, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus SetAudioFocusState(int32_t in_state, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus SetAudioTrackGain(float in_gain, bool* _aidl_return) = 0;
private:
  static std::shared_ptr<IBluetoothA2dpSink> default_impl;
};
class IBluetoothA2dpSinkDefault : public IBluetoothA2dpSink {
public:
  ::ndk::ScopedAStatus Register(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothA2dpSinkCallback>& in_callback, bool* _aidl_return) override;
  ::ndk::ScopedAStatus Unregister() override;
  ::ndk::ScopedAStatus Enable(bool* _aidl_return) override;
  ::ndk::ScopedAStatus Disable(bool* _aidl_return) override;
  ::ndk::ScopedAStatus Connect(const std::string& in_device_address, bool* _aidl_return) override;
  ::ndk::ScopedAStatus Disconnect(const std::string& in_device_address, bool* _aidl_return) override;
  ::ndk::ScopedAStatus SetAudioFocusState(int32_t in_state, bool* _aidl_return) override;
  ::ndk::ScopedAStatus SetAudioTrackGain(float in_gain, bool* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
