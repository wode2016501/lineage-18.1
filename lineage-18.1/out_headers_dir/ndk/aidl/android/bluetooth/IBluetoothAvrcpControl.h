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
#include <aidl/android/bluetooth/IBluetoothAvrcpControlCallback.h>

namespace aidl {
namespace android {
namespace bluetooth {
class IBluetoothAvrcpControl : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBluetoothAvrcpControl();
  virtual ~IBluetoothAvrcpControl();



  static std::shared_ptr<IBluetoothAvrcpControl> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothAvrcpControl>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothAvrcpControl>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBluetoothAvrcpControl> impl);
  static const std::shared_ptr<IBluetoothAvrcpControl>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus Register(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothAvrcpControlCallback>& in_callback, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus Unregister(int32_t in_id) = 0;
  virtual ::ndk::ScopedAStatus UnregisterAll() = 0;
  virtual ::ndk::ScopedAStatus Enable(int32_t in_id, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus Disable(int32_t in_id, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus SendPassThroughCommand(int32_t in_id, const std::string& in_device_address, int32_t in_key_code, bool in_key_pressed, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus SetAbsVolumeResponse(int32_t in_id, const std::string& in_device_address, int32_t in_abs_vol, int32_t in_label, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus RegisterForAbsVolumeCallbackResponse(int32_t in_id, const std::string& in_device_address, int32_t in_response_type, int32_t in_abs_vol, int32_t in_label, bool* _aidl_return) = 0;
private:
  static std::shared_ptr<IBluetoothAvrcpControl> default_impl;
};
class IBluetoothAvrcpControlDefault : public IBluetoothAvrcpControl {
public:
  ::ndk::ScopedAStatus Register(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothAvrcpControlCallback>& in_callback, bool* _aidl_return) override;
  ::ndk::ScopedAStatus Unregister(int32_t in_id) override;
  ::ndk::ScopedAStatus UnregisterAll() override;
  ::ndk::ScopedAStatus Enable(int32_t in_id, bool* _aidl_return) override;
  ::ndk::ScopedAStatus Disable(int32_t in_id, bool* _aidl_return) override;
  ::ndk::ScopedAStatus SendPassThroughCommand(int32_t in_id, const std::string& in_device_address, int32_t in_key_code, bool in_key_pressed, bool* _aidl_return) override;
  ::ndk::ScopedAStatus SetAbsVolumeResponse(int32_t in_id, const std::string& in_device_address, int32_t in_abs_vol, int32_t in_label, bool* _aidl_return) override;
  ::ndk::ScopedAStatus RegisterForAbsVolumeCallbackResponse(int32_t in_id, const std::string& in_device_address, int32_t in_response_type, int32_t in_abs_vol, int32_t in_label, bool* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
