#ifndef AIDL_GENERATED_ANDROID_DVR_I_VIRTUAL_TOUCHPAD_SERVICE_H_
#define AIDL_GENERATED_ANDROID_DVR_I_VIRTUAL_TOUCHPAD_SERVICE_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace dvr {

class IVirtualTouchpadService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VirtualTouchpadService)
  static const ::android::String16& SERVICE_NAME();
  virtual ::android::binder::Status attach() = 0;
  virtual ::android::binder::Status detach() = 0;
  virtual ::android::binder::Status touch(int32_t touchpad, float x, float y, float pressure) = 0;
  virtual ::android::binder::Status buttonState(int32_t touchpad, int32_t buttons) = 0;
  virtual ::android::binder::Status scroll(int32_t touchpad, float x, float y) = 0;
};  // class IVirtualTouchpadService

class IVirtualTouchpadServiceDefault : public IVirtualTouchpadService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status attach() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status detach() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status touch(int32_t, float, float, float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status buttonState(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status scroll(int32_t, float, float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVirtualTouchpadServiceDefault

}  // namespace dvr

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_DVR_I_VIRTUAL_TOUCHPAD_SERVICE_H_
