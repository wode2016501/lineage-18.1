#pragma once

#include "aidl/android/hardware/tests/extension/vibrator/ICustomVibrator.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace tests {
namespace extension {
namespace vibrator {
class BpCustomVibrator : public ::ndk::BpCInterface<ICustomVibrator> {
public:
  BpCustomVibrator(const ::ndk::SpAIBinder& binder);
  virtual ~BpCustomVibrator();

  ::ndk::ScopedAStatus getVendorCapabilities(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus setDirectionality(::aidl::android::hardware::tests::extension::vibrator::Directionality in_directionality) override;
  ::ndk::ScopedAStatus perform(::aidl::android::hardware::tests::extension::vibrator::VendorEffect in_effect, const std::shared_ptr<::aidl::android::hardware::vibrator::IVibratorCallback>& in_callback, int32_t* _aidl_return) override;
};
}  // namespace vibrator
}  // namespace extension
}  // namespace tests
}  // namespace hardware
}  // namespace android
}  // namespace aidl
