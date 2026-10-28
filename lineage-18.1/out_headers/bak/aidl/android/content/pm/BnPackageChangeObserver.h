#pragma once

#include "aidl/android/content/pm/IPackageChangeObserver.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace content {
namespace pm {
class BnPackageChangeObserver : public ::ndk::BnCInterface<IPackageChangeObserver> {
public:
  BnPackageChangeObserver();
  virtual ~BnPackageChangeObserver();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace pm
}  // namespace content
}  // namespace android
}  // namespace aidl
