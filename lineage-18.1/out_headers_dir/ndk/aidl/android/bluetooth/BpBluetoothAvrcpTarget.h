#pragma once

#include "aidl/android/bluetooth/IBluetoothAvrcpTarget.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothAvrcpTarget : public ::ndk::BpCInterface<IBluetoothAvrcpTarget> {
public:
  BpBluetoothAvrcpTarget(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothAvrcpTarget();

  ::ndk::ScopedAStatus sendVolumeChanged(int32_t in_volume) override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
