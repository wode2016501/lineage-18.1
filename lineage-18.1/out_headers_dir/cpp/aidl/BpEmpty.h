#pragma once

#include "aidl/IEmpty.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BpEmpty : public ::ndk::BpCInterface<IEmpty> {
public:
  BpEmpty(const ::ndk::SpAIBinder& binder);
  virtual ~BpEmpty();

};
}  // namespace aidl
