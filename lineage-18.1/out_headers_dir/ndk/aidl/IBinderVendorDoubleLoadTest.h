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
class IBinderVendorDoubleLoadTest : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBinderVendorDoubleLoadTest();
  virtual ~IBinderVendorDoubleLoadTest();



  static std::shared_ptr<IBinderVendorDoubleLoadTest> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBinderVendorDoubleLoadTest>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBinderVendorDoubleLoadTest>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBinderVendorDoubleLoadTest> impl);
  static const std::shared_ptr<IBinderVendorDoubleLoadTest>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus RepeatString(const std::string& in_toRepeat, std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IBinderVendorDoubleLoadTest> default_impl;
};
class IBinderVendorDoubleLoadTestDefault : public IBinderVendorDoubleLoadTest {
public:
  ::ndk::ScopedAStatus RepeatString(const std::string& in_toRepeat, std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace aidl
