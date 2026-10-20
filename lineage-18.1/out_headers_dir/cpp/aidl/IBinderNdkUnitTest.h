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
#include <aidl/android/os/IEmpty.h>

namespace aidl {
class IBinderNdkUnitTest : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBinderNdkUnitTest();
  virtual ~IBinderNdkUnitTest();



  static std::shared_ptr<IBinderNdkUnitTest> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBinderNdkUnitTest>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBinderNdkUnitTest>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBinderNdkUnitTest> impl);
  static const std::shared_ptr<IBinderNdkUnitTest>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus takeInterface(const std::shared_ptr<::aidl::android::os::IEmpty>& in_test) = 0;
  virtual ::ndk::ScopedAStatus forceFlushCommands() = 0;
private:
  static std::shared_ptr<IBinderNdkUnitTest> default_impl;
};
class IBinderNdkUnitTestDefault : public IBinderNdkUnitTest {
public:
  ::ndk::ScopedAStatus takeInterface(const std::shared_ptr<::aidl::android::os::IEmpty>& in_test) override;
  ::ndk::ScopedAStatus forceFlushCommands() override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace aidl
