#pragma once

#include "aidl/android/bluetooth/IBluetoothGattClientCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothGattClientCallback : public ::ndk::BnCInterface<IBluetoothGattClientCallback> {
public:
  BnBluetoothGattClientCallback();
  virtual ~BnBluetoothGattClientCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
