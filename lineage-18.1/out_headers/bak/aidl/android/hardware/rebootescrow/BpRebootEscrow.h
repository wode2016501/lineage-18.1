#pragma once

#include "aidl/android/hardware/rebootescrow/IRebootEscrow.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace rebootescrow {
class BpRebootEscrow : public ::ndk::BpCInterface<IRebootEscrow> {
public:
  BpRebootEscrow(const ::ndk::SpAIBinder& binder);
  virtual ~BpRebootEscrow();

  ::ndk::ScopedAStatus storeKey(const std::vector<int8_t>& in_kek) override;
  ::ndk::ScopedAStatus retrieveKey(std::vector<int8_t>* _aidl_return) override;
};
}  // namespace rebootescrow
}  // namespace hardware
}  // namespace android
}  // namespace aidl
