#pragma once

#include "aidl/android/dvr/IVrComposer.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace dvr {
class BnVrComposer : public ::ndk::BnCInterface<IVrComposer> {
public:
  BnVrComposer();
  virtual ~BnVrComposer();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace dvr
}  // namespace android
}  // namespace aidl
