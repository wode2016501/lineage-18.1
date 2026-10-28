#pragma once

#include "aidl/android/hardware/vibrator/IVibratorCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace vibrator {
class BpVibratorCallback : public ::ndk::BpCInterface<IVibratorCallback> {
public:
  BpVibratorCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpVibratorCallback();

  ::ndk::ScopedAStatus onComplete() override;
};
}  // namespace vibrator
}  // namespace hardware
}  // namespace android
}  // namespace aidl
