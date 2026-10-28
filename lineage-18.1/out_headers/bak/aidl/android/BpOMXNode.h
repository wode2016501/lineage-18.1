#pragma once

#include "aidl/android/IOMXNode.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
class BpOMXNode : public ::ndk::BpCInterface<IOMXNode> {
public:
  BpOMXNode(const ::ndk::SpAIBinder& binder);
  virtual ~BpOMXNode();

};
}  // namespace android
}  // namespace aidl
