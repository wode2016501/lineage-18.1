#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ICameraServiceListener.h>
#include <android/hardware/BnCameraServiceListener.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
class BnCameraServiceListener : public ::android::BnInterface<ICameraServiceListener> {
public:
  static constexpr uint32_t TRANSACTION_onStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onTorchStatusChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onCameraAccessPrioritiesChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onCameraOpened = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onCameraClosed = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnCameraServiceListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraServiceListener

class ICameraServiceListenerDelegator : public BnCameraServiceListener {
public:
  explicit ICameraServiceListenerDelegator(const ::android::sp<ICameraServiceListener> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ICameraServiceListener> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onStatusChanged(int32_t status, const ::android::String16& cameraId) override {
    return _aidl_delegate->onStatusChanged(status, cameraId);
  }
  ::android::binder::Status onTorchStatusChanged(int32_t status, const ::android::String16& cameraId) override {
    return _aidl_delegate->onTorchStatusChanged(status, cameraId);
  }
  ::android::binder::Status onCameraAccessPrioritiesChanged() override {
    return _aidl_delegate->onCameraAccessPrioritiesChanged();
  }
  ::android::binder::Status onCameraOpened(const ::android::String16& cameraId, const ::android::String16& clientPackageId) override {
    return _aidl_delegate->onCameraOpened(cameraId, clientPackageId);
  }
  ::android::binder::Status onCameraClosed(const ::android::String16& cameraId) override {
    return _aidl_delegate->onCameraClosed(cameraId);
  }
private:
  ::android::sp<ICameraServiceListener> _aidl_delegate;
};  // class ICameraServiceListenerDelegator
}  // namespace hardware
}  // namespace android
