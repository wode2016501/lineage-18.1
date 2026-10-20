#pragma once

#include "aidl/IBinderStabilityTest.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BnBinderStabilityTest : public ::ndk::BnCInterface<IBinderStabilityTest> {
public:
  BnBinderStabilityTest();
  virtual ~BnBinderStabilityTest();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace aidl
