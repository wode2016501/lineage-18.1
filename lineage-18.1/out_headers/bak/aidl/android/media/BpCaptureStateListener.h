#pragma once

#include "aidl/android/media/ICaptureStateListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace media {
class BpCaptureStateListener : public ::ndk::BpCInterface<ICaptureStateListener> {
public:
  BpCaptureStateListener(const ::ndk::SpAIBinder& binder);
  virtual ~BpCaptureStateListener();

  ::ndk::ScopedAStatus setCaptureState(bool in_active) override;
};
}  // namespace media
}  // namespace android
}  // namespace aidl
