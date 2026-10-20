#ifndef AIDL_GENERATED_ANDROID_MEDIA_I_CAPTURE_STATE_LISTENER_H_
#define AIDL_GENERATED_ANDROID_MEDIA_I_CAPTURE_STATE_LISTENER_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace media {

class ICaptureStateListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(CaptureStateListener)
  virtual ::android::binder::Status setCaptureState(bool active) = 0;
};  // class ICaptureStateListener

class ICaptureStateListenerDefault : public ICaptureStateListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setCaptureState(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICaptureStateListenerDefault

}  // namespace media

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_MEDIA_I_CAPTURE_STATE_LISTENER_H_
