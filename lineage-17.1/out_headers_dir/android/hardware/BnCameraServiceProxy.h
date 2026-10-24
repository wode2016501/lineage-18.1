#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ICameraServiceProxy.h>
#include <android/hardware/BnCameraServiceProxy.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
class BnCameraServiceProxy : public ::android::BnInterface<ICameraServiceProxy> {
public:
  static constexpr uint32_t TRANSACTION_pingForUserUpdate = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_notifyCameraState = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnCameraServiceProxy();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraServiceProxy

class ICameraServiceProxyDelegator : public BnCameraServiceProxy {
public:
  explicit ICameraServiceProxyDelegator(const ::android::sp<ICameraServiceProxy> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ICameraServiceProxy> getImpl() { return _aidl_delegate; }
  ::android::binder::Status pingForUserUpdate() override {
    return _aidl_delegate->pingForUserUpdate();
  }
  ::android::binder::Status notifyCameraState(const ::android::String16& cameraId, int32_t facing, int32_t newCameraState, const ::android::String16& clientName, int32_t apiLevel) override {
    return _aidl_delegate->notifyCameraState(cameraId, facing, newCameraState, clientName, apiLevel);
  }
private:
  ::android::sp<ICameraServiceProxy> _aidl_delegate;
};  // class ICameraServiceProxyDelegator
}  // namespace hardware
}  // namespace android
