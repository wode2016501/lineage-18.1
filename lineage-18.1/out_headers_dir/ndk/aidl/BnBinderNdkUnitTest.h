#pragma once

#include "aidl/IBinderNdkUnitTest.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BnBinderNdkUnitTest : public ::ndk::BnCInterface<IBinderNdkUnitTest> {
public:
  BnBinderNdkUnitTest();
  virtual ~BnBinderNdkUnitTest();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace aidl
