#pragma once

#include "aidl/IAidlStuff.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BpAidlStuff : public ::ndk::BpCInterface<IAidlStuff> {
public:
  BpAidlStuff(const ::ndk::SpAIBinder& binder);
  virtual ~BpAidlStuff();

  ::ndk::ScopedAStatus callLocal() override;
  ::ndk::ScopedAStatus call(int32_t in_idx) override;
};
}  // namespace aidl
