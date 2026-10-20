#ifndef AIDL_GENERATED_ANDROID_OS_BP_DUMPSTATE_LISTENER_H_
#define AIDL_GENERATED_ANDROID_OS_BP_DUMPSTATE_LISTENER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IDumpstateListener.h>

namespace android {

namespace os {

class BpDumpstateListener : public ::android::BpInterface<IDumpstateListener> {
public:
  explicit BpDumpstateListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDumpstateListener() = default;
  ::android::binder::Status onProgress(int32_t progress) override;
  ::android::binder::Status onError(int32_t errorCode) override;
  ::android::binder::Status onFinished() override;
  ::android::binder::Status onScreenshotTaken(bool success) override;
  ::android::binder::Status onUiIntensiveBugreportDumpsFinished(const ::android::String16& callingPackage) override;
};  // class BpDumpstateListener

}  // namespace os

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_OS_BP_DUMPSTATE_LISTENER_H_
