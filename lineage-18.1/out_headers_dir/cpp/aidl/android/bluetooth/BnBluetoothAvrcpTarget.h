#pragma once

#include "aidl/android/bluetooth/IBluetoothAvrcpTarget.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothAvrcpTarget : public ::ndk::BnCInterface<IBluetoothAvrcpTarget> {
public:
  BnBluetoothAvrcpTarget();
  virtual ~BnBluetoothAvrcpTarget();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
