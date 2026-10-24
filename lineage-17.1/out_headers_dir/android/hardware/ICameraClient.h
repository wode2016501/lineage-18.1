#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {
namespace hardware {
class ICameraClientDelegator;

class ICameraClient : public ::android::IInterface {
public:
  typedef ICameraClientDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(CameraClient)
};  // class ICameraClient

class ICameraClientDefault : public ICameraClient {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
};  // class ICameraClientDefault
}  // namespace hardware
}  // namespace android
