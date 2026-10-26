#ifndef AIDL_GENERATED_ANDROID_OS_BP_DUMPSTATE_H_
#define AIDL_GENERATED_ANDROID_OS_BP_DUMPSTATE_H_

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
  ::android::binder::Status startBugreport(int32_t callingUid, const ::std::string& callingPackage, ::android::base::unique_fd bugreportFd, ::android::base::unique_fd screenshotFd, int32_t bugreportMode, const ::android::sp<::android::os::IDumpstateListener>& listener, bool isScreenshotRequested) override;
  ::android::binder::Status cancelBugreport() override;
};  // class BpDumpstate

}  // namespace os

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_OS_BP_DUMPSTATE_H_
