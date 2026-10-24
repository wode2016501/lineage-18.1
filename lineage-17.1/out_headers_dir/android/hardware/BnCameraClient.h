#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ICameraClient.h>
#include <android/hardware/BnCameraClient.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
class BnCameraClient : public ::android::BnInterface<ICameraClient> {
public:
  explicit BnCameraClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraClient

class ICameraClientDelegator : public BnCameraClient {
public:
  explicit ICameraClientDelegator(const ::android::sp<ICameraClient> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ICameraClient> getImpl() { return _aidl_delegate; }
private:
  ::android::sp<ICameraClient> _aidl_delegate;
};  // class ICameraClientDelegator
}  // namespace hardware
}  // namespace android
