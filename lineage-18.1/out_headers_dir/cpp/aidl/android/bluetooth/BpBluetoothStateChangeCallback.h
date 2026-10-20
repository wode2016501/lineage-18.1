#pragma once

#include "aidl/android/bluetooth/IBluetoothStateChangeCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothStateChangeCallback : public ::ndk::BpCInterface<IBluetoothStateChangeCallback> {
public:
  BpBluetoothStateChangeCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothStateChangeCallback();

  ::ndk::ScopedAStatus onBluetoothStateChange(bool in_on) override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
