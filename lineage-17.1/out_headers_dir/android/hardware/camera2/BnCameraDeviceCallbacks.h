#pragma once

#include <binder/IInterface.h>
#include <android/hardware/camera2/ICameraDeviceCallbacks.h>
#include <android/hardware/camera2/BnCameraDeviceCallbacks.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
namespace camera2 {
class BnCameraDeviceCallbacks : public ::android::BnInterface<ICameraDeviceCallbacks> {
public:
  static constexpr uint32_t TRANSACTION_onDeviceError = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onDeviceIdle = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onCaptureStarted = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onResultReceived = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onPrepared = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onRepeatingRequestError = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onRequestQueueEmpty = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  explicit BnCameraDeviceCallbacks();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraDeviceCallbacks

class ICameraDeviceCallbacksDelegator : public BnCameraDeviceCallbacks {
public:
  explicit ICameraDeviceCallbacksDelegator(const ::android::sp<ICameraDeviceCallbacks> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ICameraDeviceCallbacks> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onDeviceError(int32_t errorCode, const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras) override {
    return _aidl_delegate->onDeviceError(errorCode, resultExtras);
  }
  ::android::binder::Status onDeviceIdle() override {
    return _aidl_delegate->onDeviceIdle();
  }
  ::android::binder::Status onCaptureStarted(const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras, int64_t timestamp) override {
    return _aidl_delegate->onCaptureStarted(resultExtras, timestamp);
  }
  ::android::binder::Status onResultReceived(const ::android::hardware::camera2::impl::CameraMetadataNative& result, const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras, const ::std::vector<::android::hardware::camera2::impl::PhysicalCaptureResultInfo>& physicalCaptureResultInfos) override {
    return _aidl_delegate->onResultReceived(result, resultExtras, physicalCaptureResultInfos);
  }
  ::android::binder::Status onPrepared(int32_t streamId) override {
    return _aidl_delegate->onPrepared(streamId);
  }
  ::android::binder::Status onRepeatingRequestError(int64_t lastFrameNumber, int32_t repeatingRequestId) override {
    return _aidl_delegate->onRepeatingRequestError(lastFrameNumber, repeatingRequestId);
  }
  ::android::binder::Status onRequestQueueEmpty() override {
    return _aidl_delegate->onRequestQueueEmpty();
  }
private:
  ::android::sp<ICameraDeviceCallbacks> _aidl_delegate;
};  // class ICameraDeviceCallbacksDelegator
}  // namespace camera2
}  // namespace hardware
}  // namespace android
