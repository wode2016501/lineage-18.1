#pragma once

#include "aidl/android/bluetooth/IBluetoothHeadsetPhone.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothHeadsetPhone : public ::ndk::BnCInterface<IBluetoothHeadsetPhone> {
public:
  BnBluetoothHeadsetPhone();
  virtual ~BnBluetoothHeadsetPhone();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
