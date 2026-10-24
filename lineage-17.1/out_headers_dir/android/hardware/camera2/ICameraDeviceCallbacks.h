#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <camera/CameraMetadata.h>
#include <camera/CaptureResult.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace hardware {
namespace camera2 {
class ICameraDeviceCallbacksDelegator;

class ICameraDeviceCallbacks : public ::android::IInterface {
public:
  typedef ICameraDeviceCallbacksDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(CameraDeviceCallbacks)
  enum : int32_t { ERROR_CAMERA_INVALID_ERROR = -1 };
  enum : int32_t { ERROR_CAMERA_DISCONNECTED = 0 };
  enum : int32_t { ERROR_CAMERA_DEVICE = 1 };
  enum : int32_t { ERROR_CAMERA_SERVICE = 2 };
  enum : int32_t { ERROR_CAMERA_REQUEST = 3 };
  enum : int32_t { ERROR_CAMERA_RESULT = 4 };
  enum : int32_t { ERROR_CAMERA_BUFFER = 5 };
  enum : int32_t { ERROR_CAMERA_DISABLED = 6 };
  virtual ::android::binder::Status onDeviceError(int32_t errorCode, const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras) = 0;
  virtual ::android::binder::Status onDeviceIdle() = 0;
  virtual ::android::binder::Status onCaptureStarted(const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras, int64_t timestamp) = 0;
  virtual ::android::binder::Status onResultReceived(const ::android::hardware::camera2::impl::CameraMetadataNative& result, const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras, const ::std::vector<::android::hardware::camera2::impl::PhysicalCaptureResultInfo>& physicalCaptureResultInfos) = 0;
  virtual ::android::binder::Status onPrepared(int32_t streamId) = 0;
  virtual ::android::binder::Status onRepeatingRequestError(int64_t lastFrameNumber, int32_t repeatingRequestId) = 0;
  virtual ::android::binder::Status onRequestQueueEmpty() = 0;
};  // class ICameraDeviceCallbacks

class ICameraDeviceCallbacksDefault : public ICameraDeviceCallbacks {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onDeviceError(int32_t /*errorCode*/, const ::android::hardware::camera2::impl::CaptureResultExtras& /*resultExtras*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onDeviceIdle() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onCaptureStarted(const ::android::hardware::camera2::impl::CaptureResultExtras& /*resultExtras*/, int64_t /*timestamp*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onResultReceived(const ::android::hardware::camera2::impl::CameraMetadataNative& /*result*/, const ::android::hardware::camera2::impl::CaptureResultExtras& /*resultExtras*/, const ::std::vector<::android::hardware::camera2::impl::PhysicalCaptureResultInfo>& /*physicalCaptureResultInfos*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPrepared(int32_t /*streamId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onRepeatingRequestError(int64_t /*lastFrameNumber*/, int32_t /*repeatingRequestId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onRequestQueueEmpty() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraDeviceCallbacksDefault
}  // namespace camera2
}  // namespace hardware
}  // namespace android
