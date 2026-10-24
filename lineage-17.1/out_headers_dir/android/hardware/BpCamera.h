#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/ICamera.h>

namespace android {
namespace hardware {
class BpCamera : public ::android::BpInterface<ICamera> {
public:
  explicit BpCamera(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCamera() = default;
  ::android::binder::Status disconnect() override;
};  // class BpCamera
}  // namespace hardware
}  // namespace android
