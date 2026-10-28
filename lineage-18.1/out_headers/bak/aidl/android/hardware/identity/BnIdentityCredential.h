#pragma once

#include "aidl/android/hardware/identity/IIdentityCredential.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace identity {
class BnIdentityCredential : public ::ndk::BnCInterface<IIdentityCredential> {
public:
  BnIdentityCredential();
  virtual ~BnIdentityCredential();
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace identity
}  // namespace hardware
}  // namespace android
}  // namespace aidl
