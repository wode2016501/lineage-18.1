#pragma once

#include "aidl/android/dvr/IVirtualTouchpadService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace dvr {
class BpVirtualTouchpadService : public ::ndk::BpCInterface<IVirtualTouchpadService> {
public:
  BpVirtualTouchpadService(const ::ndk::SpAIBinder& binder);
  virtual ~BpVirtualTouchpadService();

  ::ndk::ScopedAStatus attach() override;
  ::ndk::ScopedAStatus detach() override;
  ::ndk::ScopedAStatus touch(int32_t in_touchpad, float in_x, float in_y, float in_pressure) override;
  ::ndk::ScopedAStatus buttonState(int32_t in_touchpad, int32_t in_buttons) override;
  ::ndk::ScopedAStatus scroll(int32_t in_touchpad, float in_x, float in_y) override;
};
}  // namespace dvr
}  // namespace android
}  // namespace aidl
