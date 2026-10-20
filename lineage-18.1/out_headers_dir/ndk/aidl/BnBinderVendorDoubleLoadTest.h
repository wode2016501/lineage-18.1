#pragma once

#include "aidl/IBinderVendorDoubleLoadTest.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BnBinderVendorDoubleLoadTest : public ::ndk::BnCInterface<IBinderVendorDoubleLoadTest> {
public:
  BnBinderVendorDoubleLoadTest();
  virtual ~BnBinderVendorDoubleLoadTest();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace aidl
