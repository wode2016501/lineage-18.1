#pragma once

#include "aidl/IEmpty.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BnEmpty : public ::ndk::BnCInterface<IEmpty> {
public:
  BnEmpty();
  virtual ~BnEmpty();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace aidl
