#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/ICameraClient.h>

namespace android {
namespace hardware {
class BpCameraClient : public ::android::BpInterface<ICameraClient> {
public:
  explicit BpCameraClient(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpCameraClient() = default;
};  // class BpCameraClient
}  // namespace hardware
}  // namespace android
