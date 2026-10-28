#pragma once

#include "aidl/android/os/IStoraged.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BpStoraged : public ::ndk::BpCInterface<IStoraged> {
public:
  BpStoraged(const ::ndk::SpAIBinder& binder);
  virtual ~BpStoraged();

  ::ndk::ScopedAStatus onUserStarted(int32_t in_userId) override;
  ::ndk::ScopedAStatus onUserStopped(int32_t in_userId) override;
  ::ndk::ScopedAStatus getRecentPerf(int32_t* _aidl_return) override;
};
}  // namespace os
}  // namespace android
}  // namespace aidl
