#pragma once

#include "aidl/IBinderNdkUnitTest.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BpBinderNdkUnitTest : public ::ndk::BpCInterface<IBinderNdkUnitTest> {
public:
  BpBinderNdkUnitTest(const ::ndk::SpAIBinder& binder);
  virtual ~BpBinderNdkUnitTest();

  ::ndk::ScopedAStatus takeInterface(const std::shared_ptr<::aidl::android::os::IEmpty>& in_test) override;
  ::ndk::ScopedAStatus forceFlushCommands() override;
};
}  // namespace aidl
