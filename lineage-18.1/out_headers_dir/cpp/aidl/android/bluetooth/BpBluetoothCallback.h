#pragma once

#include "aidl/android/bluetooth/IBluetoothCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothCallback : public ::ndk::BpCInterface<IBluetoothCallback> {
public:
  BpBluetoothCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothCallback();

  ::ndk::ScopedAStatus onBluetoothStateChange(int32_t in_prevState, int32_t in_newState) override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
