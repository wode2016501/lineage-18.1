#pragma once

#include "aidl/android/hardware/ICameraClient.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
class BpCameraClient : public ::ndk::BpCInterface<ICameraClient> {
public:
  BpCameraClient(const ::ndk::SpAIBinder& binder);
  virtual ~BpCameraClient();

};
}  // namespace hardware
}  // namespace android
}  // namespace aidl
