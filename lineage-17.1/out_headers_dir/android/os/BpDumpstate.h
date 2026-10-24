#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IDumpstate.h>

namespace android {
namespace os {
class BpDumpstate : public ::android::BpInterface<IDumpstate> {
public:
  explicit BpDumpstate(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDumpstate() = default;
  ::android::binder::Status setListener(const ::std::string& name, const ::android::sp<::android::os::IDumpstateListener>& listener, bool getSectionDetails, ::android::sp<::android::os::IDumpstateToken>* _aidl_return) override;
  ::android::binder::Status startBugreport(int32_t callingUid, const ::std::string& callingPackage, ::android::base::unique_fd bugreportFd, ::android::base::unique_fd screenshotFd, int32_t bugreportMode, const ::android::sp<::android::os::IDumpstateListener>& listener) override;
  ::android::binder::Status cancelBugreport() override;
};  // class BpDumpstate
}  // namespace os
}  // namespace android
