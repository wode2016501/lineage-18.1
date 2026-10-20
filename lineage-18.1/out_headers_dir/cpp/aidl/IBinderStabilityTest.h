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

namespace aidl {
class IBinderStabilityTest : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBinderStabilityTest();
  virtual ~IBinderStabilityTest();



  static std::shared_ptr<IBinderStabilityTest> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBinderStabilityTest>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBinderStabilityTest>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBinderStabilityTest> impl);
  static const std::shared_ptr<IBinderStabilityTest>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus sendBinder(const ::ndk::SpAIBinder& in_binder) = 0;
  virtual ::ndk::ScopedAStatus sendAndCallBinder(const ::ndk::SpAIBinder& in_binder) = 0;
  virtual ::ndk::ScopedAStatus returnNoStabilityBinder(::ndk::SpAIBinder* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus returnLocalStabilityBinder(::ndk::SpAIBinder* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus returnVintfStabilityBinder(::ndk::SpAIBinder* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus returnVendorStabilityBinder(::ndk::SpAIBinder* _aidl_return) = 0;
private:
  static std::shared_ptr<IBinderStabilityTest> default_impl;
};
class IBinderStabilityTestDefault : public IBinderStabilityTest {
public:
  ::ndk::ScopedAStatus sendBinder(const ::ndk::SpAIBinder& in_binder) override;
  ::ndk::ScopedAStatus sendAndCallBinder(const ::ndk::SpAIBinder& in_binder) override;
  ::ndk::ScopedAStatus returnNoStabilityBinder(::ndk::SpAIBinder* _aidl_return) override;
  ::ndk::ScopedAStatus returnLocalStabilityBinder(::ndk::SpAIBinder* _aidl_return) override;
  ::ndk::ScopedAStatus returnVintfStabilityBinder(::ndk::SpAIBinder* _aidl_return) override;
  ::ndk::ScopedAStatus returnVendorStabilityBinder(::ndk::SpAIBinder* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace aidl
