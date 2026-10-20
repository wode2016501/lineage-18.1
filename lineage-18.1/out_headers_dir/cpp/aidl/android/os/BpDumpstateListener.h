#pragma once

#include "aidl/android/os/IDumpstateListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BpDumpstateListener : public ::ndk::BpCInterface<IDumpstateListener> {
public:
  BpDumpstateListener(const ::ndk::SpAIBinder& binder);
  virtual ~BpDumpstateListener();

  ::ndk::ScopedAStatus onProgress(int32_t in_progress) override;
  ::ndk::ScopedAStatus onError(int32_t in_errorCode) override;
  ::ndk::ScopedAStatus onFinished() override;
  ::ndk::ScopedAStatus onScreenshotTaken(bool in_success) override;
  ::ndk::ScopedAStatus onUiIntensiveBugreportDumpsFinished(const std::string& in_callingPackage) override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
