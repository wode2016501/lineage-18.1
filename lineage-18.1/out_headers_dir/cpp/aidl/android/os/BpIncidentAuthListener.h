#pragma once

#include "aidl/android/os/IIncidentAuthListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BpIncidentAuthListener : public ::ndk::BpCInterface<IIncidentAuthListener> {
public:
  BpIncidentAuthListener(const ::ndk::SpAIBinder& binder);
  virtual ~BpIncidentAuthListener();

  ::ndk::ScopedAStatus onReportApproved() override;
  ::ndk::ScopedAStatus onReportDenied() override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
