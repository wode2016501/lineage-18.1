#pragma once

#include "aidl/android/bluetooth/IBluetoothA2dpSink.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BnBluetoothA2dpSink : public ::ndk::BnCInterface<IBluetoothA2dpSink> {
public:
  BnBluetoothA2dpSink();
  virtual ~BnBluetoothA2dpSink();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
