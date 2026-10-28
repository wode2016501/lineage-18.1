#pragma once

#include "aidl/android/hardware/rebootescrow/IRebootEscrow.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace rebootescrow {
class BnRebootEscrow : public ::ndk::BnCInterface<IRebootEscrow> {
public:
  BnRebootEscrow();
  virtual ~BnRebootEscrow();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace rebootescrow
}  // namespace hardware
}  // namespace android
}  // namespace aidl
