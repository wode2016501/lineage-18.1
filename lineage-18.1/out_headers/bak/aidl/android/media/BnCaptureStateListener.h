#pragma once

#include "aidl/android/media/ICaptureStateListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BnCaptureStateListener : public ::ndk::BnCInterface<ICaptureStateListener> {
public:
  BnCaptureStateListener();
  virtual ~BnCaptureStateListener();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace media
}  // namespace android
}  // namespace aidl
