#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {
class IOMXNodeDelegator;

class IOMXNode : public ::android::IInterface {
public:
  typedef IOMXNodeDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(OMXNode)
};  // class IOMXNode

class IOMXNodeDefault : public IOMXNode {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
};  // class IOMXNodeDefault
}  // namespace android
