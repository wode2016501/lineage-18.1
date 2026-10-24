#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <camera/CameraMetadata.h>
#include <camera/camera2/CaptureRequest.h>
#include <camera/camera2/OutputConfiguration.h>
#include <camera/camera2/SessionConfiguration.h>
#include <camera/camera2/SubmitInfo.h>
#include <cstdint>
#include <gui/view/Surface.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace hardware {
namespace camera2 {
class ICameraDeviceUserDelegator;

class ICameraDeviceUser : public ::android::IInterface {
public:
  typedef ICameraDeviceUserDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(CameraDeviceUser)
  enum : int32_t { NO_IN_FLIGHT_REPEATING_FRAMES = -1 };
  enum : int32_t { NORMAL_MODE = 0 };
  enum : int32_t { CONSTRAINED_HIGH_SPEED_MODE = 1 };
  enum : int32_t { VENDOR_MODE_START = 32768 };
  enum : int32_t { TEMPLATE_PREVIEW = 1 };
  enum : int32_t { TEMPLATE_STILL_CAPTURE = 2 };
  enum : int32_t { TEMPLATE_RECORD = 3 };
  enum : int32_t { TEMPLATE_VIDEO_SNAPSHOT = 4 };
  enum : int32_t { TEMPLATE_ZERO_SHUTTER_LAG = 5 };
  enum : int32_t { TEMPLATE_MANUAL = 6 };
  virtual ::android::binder::Status disconnect() = 0;
  virtual ::android::binder::Status submitRequest(const ::android::hardware::camera2::CaptureRequest& request, bool streaming, ::android::hardware::camera2::utils::SubmitInfo* _aidl_return) = 0;
  virtual ::android::binder::Status submitRequestList(const ::std::vector<::android::hardware::camera2::CaptureRequest>& requestList, bool streaming, ::android::hardware::camera2::utils::SubmitInfo* _aidl_return) = 0;
  virtual ::android::binder::Status cancelRequest(int32_t requestId, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status beginConfigure() = 0;
  virtual ::android::binder::Status endConfigure(int32_t operatingMode, const ::android::hardware::camera2::impl::CameraMetadataNative& sessionParams) = 0;
  virtual ::android::binder::Status isSessionConfigurationSupported(const ::android::hardware::camera2::params::SessionConfiguration& sessionConfiguration, bool* _aidl_return) = 0;
  virtual ::android::binder::Status deleteStream(int32_t streamId) = 0;
  virtual ::android::binder::Status createStream(const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status createInputStream(int32_t width, int32_t height, int32_t format, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getInputSurface(::android::view::Surface* _aidl_return) = 0;
  virtual ::android::binder::Status createDefaultRequest(int32_t templateId, ::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) = 0;
  virtual ::android::binder::Status getCameraInfo(::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) = 0;
  virtual ::android::binder::Status waitUntilIdle() = 0;
  virtual ::android::binder::Status flush(int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status prepare(int32_t streamId) = 0;
  virtual ::android::binder::Status tearDown(int32_t streamId) = 0;
  virtual ::android::binder::Status prepare2(int32_t maxCount, int32_t streamId) = 0;
  virtual ::android::binder::Status updateOutputConfiguration(int32_t streamId, const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration) = 0;
  virtual ::android::binder::Status finalizeOutputConfigurations(int32_t streamId, const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration) = 0;
};  // class ICameraDeviceUser

class ICameraDeviceUserDefault : public ICameraDeviceUser {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status disconnect() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status submitRequest(const ::android::hardware::camera2::CaptureRequest& /*request*/, bool /*streaming*/, ::android::hardware::camera2::utils::SubmitInfo* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status submitRequestList(const ::std::vector<::android::hardware::camera2::CaptureRequest>& /*requestList*/, bool /*streaming*/, ::android::hardware::camera2::utils::SubmitInfo* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancelRequest(int32_t /*requestId*/, int64_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status beginConfigure() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status endConfigure(int32_t /*operatingMode*/, const ::android::hardware::camera2::impl::CameraMetadataNative& /*sessionParams*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isSessionConfigurationSupported(const ::android::hardware::camera2::params::SessionConfiguration& /*sessionConfiguration*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status deleteStream(int32_t /*streamId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createStream(const ::android::hardware::camera2::params::OutputConfiguration& /*outputConfiguration*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createInputStream(int32_t /*width*/, int32_t /*height*/, int32_t /*format*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getInputSurface(::android::view::Surface* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createDefaultRequest(int32_t /*templateId*/, ::android::hardware::camera2::impl::CameraMetadataNative* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraInfo(::android::hardware::camera2::impl::CameraMetadataNative* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status waitUntilIdle() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status flush(int64_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status prepare(int32_t /*streamId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tearDown(int32_t /*streamId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status prepare2(int32_t /*maxCount*/, int32_t /*streamId*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status updateOutputConfiguration(int32_t /*streamId*/, const ::android::hardware::camera2::params::OutputConfiguration& /*outputConfiguration*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status finalizeOutputConfigurations(int32_t /*streamId*/, const ::android::hardware::camera2::params::OutputConfiguration& /*outputConfiguration*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraDeviceUserDefault
}  // namespace camera2
}  // namespace hardware
}  // namespace android
