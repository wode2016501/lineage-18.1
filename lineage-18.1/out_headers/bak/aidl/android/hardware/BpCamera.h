#pragma once

#include "aidl/android/hardware/ICamera.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BpCamera : public ::ndk::BpCInterface<ICamera> {
public:
  BpCamera(const ::ndk::SpAIBinder& binder);
  virtual ~BpCamera();

  ::ndk::ScopedAStatus disconnect() override;
};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
