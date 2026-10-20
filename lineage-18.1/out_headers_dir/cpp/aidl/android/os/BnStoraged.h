#pragma once

#include "aidl/android/os/IStoraged.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace os {
class BnStoraged : public ::ndk::BnCInterface<IStoraged> {
public:
  BnStoraged();
  virtual ~BnStoraged();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace os
}  // namespace android
}  // namespace aidl
