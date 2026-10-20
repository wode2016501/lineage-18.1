#pragma once

#include "aidl/android/bluetooth/IBluetoothGattClientCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothGattClientCallback : public ::ndk::BpCInterface<IBluetoothGattClientCallback> {
public:
  BpBluetoothGattClientCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothGattClientCallback();

  ::ndk::ScopedAStatus OnClientRegistered(int32_t in_status, int32_t in_client_id) override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
