#pragma once

#include "aidl/android/os/IDumpstateListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BnDumpstateListener : public ::ndk::BnCInterface<IDumpstateListener> {
public:
  BnDumpstateListener();
  virtual ~BnDumpstateListener();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace os
}  // namespace android
}  // namespace aidl
