#pragma once

#include "aidl/android/os/IIncidentAuthListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BnIncidentAuthListener : public ::ndk::BnCInterface<IIncidentAuthListener> {
public:
  BnIncidentAuthListener();
  virtual ~BnIncidentAuthListener();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace os
}  // namespace android
}  // namespace aidl
