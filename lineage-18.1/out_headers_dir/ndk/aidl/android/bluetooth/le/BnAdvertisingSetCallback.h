#pragma once

#include "aidl/android/bluetooth/le/IAdvertisingSetCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
namespace le {
class BnAdvertisingSetCallback : public ::ndk::BnCInterface<IAdvertisingSetCallback> {
public:
  BnAdvertisingSetCallback();
  virtual ~BnAdvertisingSetCallback();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace le
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
