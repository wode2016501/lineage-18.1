#pragma once

#include <binder/IInterface.h>
#include <android/os/IDumpstateToken.h>
#include <android/os/BnDumpstateToken.h>
#include <binder/Delegate.h>


namespace android {
namespace os {
class BnDumpstateToken : public ::android::BnInterface<IDumpstateToken> {
public:
  explicit BnDumpstateToken();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDumpstateToken

class IDumpstateTokenDelegator : public BnDumpstateToken {
public:
  explicit IDumpstateTokenDelegator(const ::android::sp<IDumpstateToken> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IDumpstateToken> getImpl() { return _aidl_delegate; }
private:
  ::android::sp<IDumpstateToken> _aidl_delegate;
};  // class IDumpstateTokenDelegator
}  // namespace os
}  // namespace android
