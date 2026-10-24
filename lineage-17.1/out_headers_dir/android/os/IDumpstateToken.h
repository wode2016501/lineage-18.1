#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {
namespace os {
class IDumpstateTokenDelegator;

class IDumpstateToken : public ::android::IInterface {
public:
  typedef IDumpstateTokenDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(DumpstateToken)
};  // class IDumpstateToken

class IDumpstateTokenDefault : public IDumpstateToken {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
};  // class IDumpstateTokenDefault
}  // namespace os
}  // namespace android
