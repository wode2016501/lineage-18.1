#pragma once

#include "aidl/android/bluetooth/IBluetoothAvrcpControl.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothAvrcpControl : public ::ndk::BnCInterface<IBluetoothAvrcpControl> {
public:
  BnBluetoothAvrcpControl();
  virtual ~BnBluetoothAvrcpControl();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
