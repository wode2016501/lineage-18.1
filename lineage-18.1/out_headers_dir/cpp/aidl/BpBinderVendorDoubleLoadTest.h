#pragma once

#include "aidl/IBinderVendorDoubleLoadTest.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BpBinderVendorDoubleLoadTest : public ::ndk::BpCInterface<IBinderVendorDoubleLoadTest> {
public:
  BpBinderVendorDoubleLoadTest(const ::ndk::SpAIBinder& binder);
  virtual ~BpBinderVendorDoubleLoadTest();

  ::ndk::ScopedAStatus RepeatString(const std::string& in_toRepeat, std::string* _aidl_return) override;
};
}  // namespace aidl
