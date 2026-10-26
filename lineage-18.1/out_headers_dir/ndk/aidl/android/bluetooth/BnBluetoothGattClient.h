#pragma once

#include "aidl/android/bluetooth/IBluetoothGattClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothGattClient : public ::ndk::BnCInterface<IBluetoothGattClient> {
public:
  BnBluetoothGattClient();
  virtual ~BnBluetoothGattClient();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
