#pragma once

#include "aidl/android/hardware/light/ILights.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace light {
class BpLights : public ::ndk::BpCInterface<ILights> {
public:
  BpLights(const ::ndk::SpAIBinder& binder);
  virtual ~BpLights();

  ::ndk::ScopedAStatus setLightState(int32_t in_id, const ::aidl::android::hardware::light::HwLightState& in_state) override;
  ::ndk::ScopedAStatus getLights(std::vector<::aidl::android::hardware::light::HwLight>* _aidl_return) override;
};
}  // namespace light
}  // namespace hardware
}  // namespace android
}  // namespace aidl
