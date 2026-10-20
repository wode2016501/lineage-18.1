#pragma once

#include "aidl/android/IOMXNode.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
class BnOMXNode : public ::ndk::BnCInterface<IOMXNode> {
public:
  BnOMXNode();
  virtual ~BnOMXNode();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace android
}  // namespace aidl
