#pragma once

#include "aidl/android/content/pm/IPackageChangeObserver.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace content {
namespace pm {
class BpPackageChangeObserver : public ::ndk::BpCInterface<IPackageChangeObserver> {
public:
  BpPackageChangeObserver(const ::ndk::SpAIBinder& binder);
  virtual ~BpPackageChangeObserver();

  ::ndk::ScopedAStatus onPackageChanged(const ::aidl::android::content::pm::PackageChangeEvent& in_event) override;
};
}  // namespace pm
}  // namespace content
}  // namespace android
}  // namespace aidl
