#pragma once

#include "aidl/android/bluetooth/IBluetoothA2dpSinkCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothA2dpSinkCallback : public ::ndk::BpCInterface<IBluetoothA2dpSinkCallback> {
public:
  BpBluetoothA2dpSinkCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothA2dpSinkCallback();

  ::ndk::ScopedAStatus OnRegistered(int32_t in_status) override;
  ::ndk::ScopedAStatus OnConnectionState(const std::string& in_device_address, int32_t in_state) override;
  ::ndk::ScopedAStatus OnAudioState(const std::string& in_device_address, int32_t in_state) override;
  ::ndk::ScopedAStatus OnAudioConfig(const std::string& in_device_address, int32_t in_sample_rate, int32_t in_channel_count) override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
