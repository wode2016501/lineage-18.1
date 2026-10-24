#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {
namespace hardware {
class ICameraDelegator;

class ICamera : public ::android::IInterface {
public:
  typedef ICameraDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(Camera)
  virtual ::android::binder::Status disconnect() = 0;
};  // class ICamera

class ICameraDefault : public ICamera {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status disconnect() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraDefault
}  // namespace hardware
}  // namespace android
