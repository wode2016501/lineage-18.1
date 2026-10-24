#pragma once

#include <binder/IInterface.h>
#include <android/hardware/camera2/ICameraDeviceUser.h>
#include <android/hardware/camera2/BnCameraDeviceUser.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
namespace camera2 {
class BnCameraDeviceUser : public ::android::BnInterface<ICameraDeviceUser> {
public:
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_submitRequest = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_submitRequestList = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_cancelRequest = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_beginConfigure = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_endConfigure = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_isSessionConfigurationSupported = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_deleteStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_createStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_createInputStream = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getInputSurface = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_createDefaultRequest = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_getCameraInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_waitUntilIdle = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_flush = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_prepare = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_tearDown = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_prepare2 = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_updateOutputConfiguration = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_finalizeOutputConfigurations = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  explicit BnCameraDeviceUser();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraDeviceUser

class ICameraDeviceUserDelegator : public BnCameraDeviceUser {
public:
  explicit ICameraDeviceUserDelegator(const ::android::sp<ICameraDeviceUser> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ICameraDeviceUser> getImpl() { return _aidl_delegate; }
  ::android::binder::Status disconnect() override {
    return _aidl_delegate->disconnect();
  }
  ::android::binder::Status submitRequest(const ::android::hardware::camera2::CaptureRequest& request, bool streaming, ::android::hardware::camera2::utils::SubmitInfo* _aidl_return) override {
    return _aidl_delegate->submitRequest(request, streaming, _aidl_return);
  }
  ::android::binder::Status submitRequestList(const ::std::vector<::android::hardware::camera2::CaptureRequest>& requestList, bool streaming, ::android::hardware::camera2::utils::SubmitInfo* _aidl_return) override {
    return _aidl_delegate->submitRequestList(requestList, streaming, _aidl_return);
  }
  ::android::binder::Status cancelRequest(int32_t requestId, int64_t* _aidl_return) override {
    return _aidl_delegate->cancelRequest(requestId, _aidl_return);
  }
  ::android::binder::Status beginConfigure() override {
    return _aidl_delegate->beginConfigure();
  }
  ::android::binder::Status endConfigure(int32_t operatingMode, const ::android::hardware::camera2::impl::CameraMetadataNative& sessionParams) override {
    return _aidl_delegate->endConfigure(operatingMode, sessionParams);
  }
  ::android::binder::Status isSessionConfigurationSupported(const ::android::hardware::camera2::params::SessionConfiguration& sessionConfiguration, bool* _aidl_return) override {
    return _aidl_delegate->isSessionConfigurationSupported(sessionConfiguration, _aidl_return);
  }
  ::android::binder::Status deleteStream(int32_t streamId) override {
    return _aidl_delegate->deleteStream(streamId);
  }
  ::android::binder::Status createStream(const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration, int32_t* _aidl_return) override {
    return _aidl_delegate->createStream(outputConfiguration, _aidl_return);
  }
  ::android::binder::Status createInputStream(int32_t width, int32_t height, int32_t format, int32_t* _aidl_return) override {
    return _aidl_delegate->createInputStream(width, height, format, _aidl_return);
  }
  ::android::binder::Status getInputSurface(::android::view::Surface* _aidl_return) override {
    return _aidl_delegate->getInputSurface(_aidl_return);
  }
  ::android::binder::Status createDefaultRequest(int32_t templateId, ::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) override {
    return _aidl_delegate->createDefaultRequest(templateId, _aidl_return);
  }
  ::android::binder::Status getCameraInfo(::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) override {
    return _aidl_delegate->getCameraInfo(_aidl_return);
  }
  ::android::binder::Status waitUntilIdle() override {
    return _aidl_delegate->waitUntilIdle();
  }
  ::android::binder::Status flush(int64_t* _aidl_return) override {
    return _aidl_delegate->flush(_aidl_return);
  }
  ::android::binder::Status prepare(int32_t streamId) override {
    return _aidl_delegate->prepare(streamId);
  }
  ::android::binder::Status tearDown(int32_t streamId) override {
    return _aidl_delegate->tearDown(streamId);
  }
  ::android::binder::Status prepare2(int32_t maxCount, int32_t streamId) override {
    return _aidl_delegate->prepare2(maxCount, streamId);
  }
  ::android::binder::Status updateOutputConfiguration(int32_t streamId, const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration) override {
    return _aidl_delegate->updateOutputConfiguration(streamId, outputConfiguration);
  }
  ::android::binder::Status finalizeOutputConfigurations(int32_t streamId, const ::android::hardware::camera2::params::OutputConfiguration& outputConfiguration) override {
    return _aidl_delegate->finalizeOutputConfigurations(streamId, outputConfiguration);
  }
private:
  ::android::sp<ICameraDeviceUser> _aidl_delegate;
};  // class ICameraDeviceUserDelegator
}  // namespace camera2
}  // namespace hardware
}  // namespace android
