#pragma once

#include "aidl/IBinderStabilityTest.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BpBinderStabilityTest : public ::ndk::BpCInterface<IBinderStabilityTest> {
public:
  BpBinderStabilityTest(const ::ndk::SpAIBinder& binder);
  virtual ~BpBinderStabilityTest();

  ::ndk::ScopedAStatus sendBinder(const ::ndk::SpAIBinder& in_binder) override;
  ::ndk::ScopedAStatus sendAndCallBinder(const ::ndk::SpAIBinder& in_binder) override;
  ::ndk::ScopedAStatus returnNoStabilityBinder(::ndk::SpAIBinder* _aidl_return) override;
  ::ndk::ScopedAStatus returnLocalStabilityBinder(::ndk::SpAIBinder* _aidl_return) override;
  ::ndk::ScopedAStatus returnVintfStabilityBinder(::ndk::SpAIBinder* _aidl_return) override;
  ::ndk::ScopedAStatus returnVendorStabilityBinder(::ndk::SpAIBinder* _aidl_return) override;
};
}  // namespace aidl
