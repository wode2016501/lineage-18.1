#pragma once

#include "aidl/android/bluetooth/IBluetoothCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothCallback : public ::ndk::BnCInterface<IBluetoothCallback> {
public:
  BnBluetoothCallback();
  virtual ~BnBluetoothCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
