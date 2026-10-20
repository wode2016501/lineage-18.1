#ifndef AIDL_GENERATED_ANDROID_MEDIA_BP_CAPTURE_STATE_LISTENER_H_
#define AIDL_GENERATED_ANDROID_MEDIA_BP_CAPTURE_STATE_LISTENER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/media/ICaptureStateListener.h>

namespace android {

namespace media {

class BpCaptureStateListener : public ::android::BpInterface<ICaptureStateListener> {
public:
  explicit BpCaptureStateListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCaptureStateListener() = default;
  ::android::binder::Status setCaptureState(bool active) override;
};  // class BpCaptureStateListener

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_BP_CAPTURE_STATE_LISTENER_H_
