#pragma once

#include "aidl/android/content/pm/IPackageManagerNative.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace content {
namespace pm {
class BnPackageManagerNative : public ::ndk::BnCInterface<IPackageManagerNative> {
public:
  BnPackageManagerNative();
  virtual ~BnPackageManagerNative();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace pm
}  // namespace content
}  // namespace android
}  // namespace aidl
