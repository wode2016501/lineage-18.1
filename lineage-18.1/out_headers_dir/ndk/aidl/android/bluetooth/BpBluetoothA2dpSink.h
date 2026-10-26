#pragma once

#include "aidl/android/bluetooth/IBluetoothA2dpSink.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothA2dpSink : public ::ndk::BpCInterface<IBluetoothA2dpSink> {
public:
  BpBluetoothA2dpSink(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothA2dpSink();

  ::ndk::ScopedAStatus Register(const std::shared_ptr<::aidl::android::bluetooth::IBluetoothA2dpSinkCallback>& in_callback, bool* _aidl_return) override;
  ::ndk::ScopedAStatus Unregister() override;
  ::ndk::ScopedAStatus Enable(bool* _aidl_return) override;
  ::ndk::ScopedAStatus Disable(bool* _aidl_return) override;
  ::ndk::ScopedAStatus Connect(const std::string& in_device_address, bool* _aidl_return) override;
  ::ndk::ScopedAStatus Disconnect(const std::string& in_device_address, bool* _aidl_return) override;
  ::ndk::ScopedAStatus SetAudioFocusState(int32_t in_state, bool* _aidl_return) override;
  ::ndk::ScopedAStatus SetAudioTrackGain(float in_gain, bool* _aidl_return) override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
