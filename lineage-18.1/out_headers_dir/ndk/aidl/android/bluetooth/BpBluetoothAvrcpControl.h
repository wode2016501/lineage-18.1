#pragma once

#include "aidl/android/bluetooth/IBluetoothAvrcpControl.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothAvrcpControl : public ::ndk::BpCInterface<IBluetoothAvrcpControl> {
public:
  BpBluetoothAvrcpControl(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothAvrcpControl();

  ::ndk::ScopedAStatus Register(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothAvrcpControlCallback>& in_callback, bool* _aidl_return) override;
  ::ndk::ScopedAStatus Unregister(int32_t in_id) override;
  ::ndk::ScopedAStatus UnregisterAll() override;
  ::ndk::ScopedAStatus Enable(int32_t in_id, bool* _aidl_return) override;
  ::ndk::ScopedAStatus Disable(int32_t in_id, bool* _aidl_return) override;
  ::ndk::ScopedAStatus SendPassThroughCommand(int32_t in_id, const std::string& in_device_address, int32_t in_key_code, bool in_key_pressed, bool* _aidl_return) override;
  ::ndk::ScopedAStatus SetAbsVolumeResponse(int32_t in_id, const std::string& in_device_address, int32_t in_abs_vol, int32_t in_label, bool* _aidl_return) override;
  ::ndk::ScopedAStatus RegisterForAbsVolumeCallbackResponse(int32_t in_id, const std::string& in_device_address, int32_t in_response_type, int32_t in_abs_vol, int32_t in_label, bool* _aidl_return) override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
