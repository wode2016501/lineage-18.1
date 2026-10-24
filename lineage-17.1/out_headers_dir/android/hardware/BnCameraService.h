#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ICameraService.h>
#include <android/hardware/BnCameraService.h>
#include <android/hardware/BnCameraServiceListener.h>
#include <android/hardware/camera2/BnCameraDeviceCallbacks.h>
#include <android/hardware/camera2/BnCameraDeviceUser.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
class BnCameraService : public ::android::BnInterface<ICameraService> {
public:
  static constexpr uint32_t TRANSACTION_getNumberOfCameras = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getCameraInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_connectDevice = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_connectLegacy = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_addListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_removeListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_getCameraCharacteristics = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_getCameraVendorTagDescriptor = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_getCameraVendorTagCache = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getLegacyParameters = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_supportsCameraApi = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_isHiddenPhysicalCamera = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_setTorchMode = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_notifySystemEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_notifyDeviceStateChange = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  explicit BnCameraService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraService

class ICameraServiceDelegator : public BnCameraService {
public:
  explicit ICameraServiceDelegator(const ::android::sp<ICameraService> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ICameraService> getImpl() { return _aidl_delegate; }
  ::android::binder::Status getNumberOfCameras(int32_t type, int32_t* _aidl_return) override {
    return _aidl_delegate->getNumberOfCameras(type, _aidl_return);
  }
  ::android::binder::Status getCameraInfo(int32_t cameraId, ::android::hardware::CameraInfo* _aidl_return) override {
    return _aidl_delegate->getCameraInfo(cameraId, _aidl_return);
  }
  ::android::binder::Status connect(const ::android::sp<::android::hardware::ICameraClient>& client, int32_t cameraId, const ::android::String16& opPackageName, int32_t clientUid, int32_t clientPid, ::android::sp<::android::hardware::ICamera>* _aidl_return) override {
    return _aidl_delegate->connect(client, cameraId, opPackageName, clientUid, clientPid, _aidl_return);
  }
  ::android::binder::Status connectDevice(const ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacks>& callbacks, const ::android::String16& cameraId, const ::android::String16& opPackageName, int32_t clientUid, ::android::sp<::android::hardware::camera2::ICameraDeviceUser>* _aidl_return) override {
    ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacksDelegator> _callbacks;
    if (callbacks) {
      _callbacks = ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacksDelegator>::cast(delegate(callbacks));
    }
    auto _status = _aidl_delegate->connectDevice(_callbacks, cameraId, opPackageName, clientUid, _aidl_return);
    if (*_aidl_return) {
      *_aidl_return = ::android::sp<::android::hardware::camera2::ICameraDeviceUserDelegator>::cast(delegate(*_aidl_return));
    }
    return _status;
  }
  ::android::binder::Status connectLegacy(const ::android::sp<::android::hardware::ICameraClient>& client, int32_t cameraId, int32_t halVersion, const ::android::String16& opPackageName, int32_t clientUid, ::android::sp<::android::hardware::ICamera>* _aidl_return) override {
    return _aidl_delegate->connectLegacy(client, cameraId, halVersion, opPackageName, clientUid, _aidl_return);
  }
  ::android::binder::Status addListener(const ::android::sp<::android::hardware::ICameraServiceListener>& listener, ::std::vector<::android::hardware::CameraStatus>* _aidl_return) override {
    ::android::sp<::android::hardware::ICameraServiceListenerDelegator> _listener;
    if (listener) {
      _listener = ::android::sp<::android::hardware::ICameraServiceListenerDelegator>::cast(delegate(listener));
    }
    return _aidl_delegate->addListener(_listener, _aidl_return);
  }
  ::android::binder::Status removeListener(const ::android::sp<::android::hardware::ICameraServiceListener>& listener) override {
    ::android::sp<::android::hardware::ICameraServiceListenerDelegator> _listener;
    if (listener) {
      _listener = ::android::sp<::android::hardware::ICameraServiceListenerDelegator>::cast(delegate(listener));
    }
    return _aidl_delegate->removeListener(_listener);
  }
  ::android::binder::Status getCameraCharacteristics(const ::android::String16& cameraId, ::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) override {
    return _aidl_delegate->getCameraCharacteristics(cameraId, _aidl_return);
  }
  ::android::binder::Status getCameraVendorTagDescriptor(::android::hardware::camera2::params::VendorTagDescriptor* _aidl_return) override {
    return _aidl_delegate->getCameraVendorTagDescriptor(_aidl_return);
  }
  ::android::binder::Status getCameraVendorTagCache(::android::hardware::camera2::params::VendorTagDescriptorCache* _aidl_return) override {
    return _aidl_delegate->getCameraVendorTagCache(_aidl_return);
  }
  ::android::binder::Status getLegacyParameters(int32_t cameraId, ::android::String16* _aidl_return) override {
    return _aidl_delegate->getLegacyParameters(cameraId, _aidl_return);
  }
  ::android::binder::Status supportsCameraApi(const ::android::String16& cameraId, int32_t apiVersion, bool* _aidl_return) override {
    return _aidl_delegate->supportsCameraApi(cameraId, apiVersion, _aidl_return);
  }
  ::android::binder::Status isHiddenPhysicalCamera(const ::android::String16& cameraId, bool* _aidl_return) override {
    return _aidl_delegate->isHiddenPhysicalCamera(cameraId, _aidl_return);
  }
  ::android::binder::Status setTorchMode(const ::android::String16& cameraId, bool enabled, const ::android::sp<::android::IBinder>& clientBinder) override {
    return _aidl_delegate->setTorchMode(cameraId, enabled, clientBinder);
  }
  ::android::binder::Status notifySystemEvent(int32_t eventId, const ::std::vector<int32_t>& args) override {
    return _aidl_delegate->notifySystemEvent(eventId, args);
  }
  ::android::binder::Status notifyDeviceStateChange(int64_t newState) override {
    return _aidl_delegate->notifyDeviceStateChange(newState);
  }
private:
  ::android::sp<ICameraService> _aidl_delegate;
};  // class ICameraServiceDelegator
}  // namespace hardware
}  // namespace android
