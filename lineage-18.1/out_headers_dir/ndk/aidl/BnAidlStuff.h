#pragma once

#include "aidl/IAidlStuff.h"

#include <android/binder_ibinder.h>

namespace aidl {
class BnAidlStuff : public ::ndk::BnCInterface<IAidlStuff> {
public:
  BnAidlStuff();
  virtual ~BnAidlStuff();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace aidl
