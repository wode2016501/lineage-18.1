#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IDumpstateToken.h>

namespace android {
namespace os {
class BpDumpstateToken : public ::android::BpInterface<IDumpstateToken> {
public:
  explicit BpDumpstateToken(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDumpstateToken() = default;
};  // class BpDumpstateToken
}  // namespace os
}  // namespace android
