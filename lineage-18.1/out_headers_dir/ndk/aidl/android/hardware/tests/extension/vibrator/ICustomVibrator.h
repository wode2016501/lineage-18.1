#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/hardware/tests/extension/vibrator/Directionality.h>
#include <aidl/android/hardware/tests/extension/vibrator/VendorEffect.h>
#include <aidl/android/hardware/vibrator/IVibratorCallback.h>

namespace aidl {
namespace android {
namespace hardware {
namespace tests {
namespace extension {
namespace vibrator {
class ICustomVibrator : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  ICustomVibrator();
  virtual ~ICustomVibrator();


  enum : int32_t {
    CAP_VENDOR_DIRECTIONALITY = 1,
  };

  static std::shared_ptr<ICustomVibrator> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<ICustomVibrator>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<ICustomVibrator>* instance);
  static bool setDefaultImpl(std::shared_ptr<ICustomVibrator> impl);
  static const std::shared_ptr<ICustomVibrator>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus getVendorCapabilities(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus setDirectionality(::aidl::android::hardware::tests::extension::vibrator::Directionality in_directionality) = 0;
  virtual ::ndk::ScopedAStatus perform(::aidl::android::hardware::tests::extension::vibrator::VendorEffect in_effect, const std::shared_ptr<::aidl::android::hardware::vibrator::IVibratorCallback>& in_callback, int32_t* _aidl_return) = 0;
private:
  static std::shared_ptr<ICustomVibrator> default_impl;
};
class ICustomVibratorDefault : public ICustomVibrator {
public:
  ::ndk::ScopedAStatus getVendorCapabilities(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus setDirectionality(::aidl::android::hardware::tests::extension::vibrator::Directionality in_directionality) override;
  ::ndk::ScopedAStatus perform(::aidl::android::hardware::tests::extension::vibrator::VendorEffect in_effect, const std::shared_ptr<::aidl::android::hardware::vibrator::IVibratorCallback>& in_callback, int32_t* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace vibrator
}  // namespace extension
}  // namespace tests
}  // namespace hardware
}  // namespace android
}  // namespace aidl
