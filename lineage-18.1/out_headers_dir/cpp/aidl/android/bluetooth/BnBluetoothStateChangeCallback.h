#pragma once

#include "aidl/android/bluetooth/IBluetoothStateChangeCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothStateChangeCallback : public ::ndk::BnCInterface<IBluetoothStateChangeCallback> {
public:
  BnBluetoothStateChangeCallback();
  virtual ~BnBluetoothStateChangeCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
