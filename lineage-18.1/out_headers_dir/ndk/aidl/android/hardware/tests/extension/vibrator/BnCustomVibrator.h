#pragma once

#include "aidl/android/hardware/tests/extension/vibrator/ICustomVibrator.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace tests {
namespace extension {
namespace vibrator {
class BnCustomVibrator : public ::ndk::BnCInterface<ICustomVibrator> {
public:
  BnCustomVibrator();
  virtual ~BnCustomVibrator();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace vibrator
}  // namespace extension
}  // namespace tests
}  // namespace hardware
}  // namespace android
}  // namespace aidl
