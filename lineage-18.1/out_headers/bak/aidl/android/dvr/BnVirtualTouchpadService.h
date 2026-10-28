#pragma once

#include "aidl/android/dvr/IVirtualTouchpadService.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace dvr {
class BnVirtualTouchpadService : public ::ndk::BnCInterface<IVirtualTouchpadService> {
public:
  BnVirtualTouchpadService();
  virtual ~BnVirtualTouchpadService();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace dvr
}  // namespace android
}  // namespace aidl
