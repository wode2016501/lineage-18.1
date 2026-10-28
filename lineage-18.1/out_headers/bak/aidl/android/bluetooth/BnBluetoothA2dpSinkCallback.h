#pragma once

#include "aidl/android/bluetooth/IBluetoothA2dpSinkCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothA2dpSinkCallback : public ::ndk::BnCInterface<IBluetoothA2dpSinkCallback> {
public:
  BnBluetoothA2dpSinkCallback();
  virtual ~BnBluetoothA2dpSinkCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
