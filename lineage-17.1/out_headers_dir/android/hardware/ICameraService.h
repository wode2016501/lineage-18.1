#pragma once

#include <android/hardware/ICamera.h>
#include <android/hardware/ICameraClient.h>
#include <android/hardware/ICameraServiceListener.h>
#include <android/hardware/camera2/ICameraDeviceCallbacks.h>
#include <android/hardware/camera2/ICameraDeviceUser.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <camera/CameraBase.h>
#include <camera/CameraMetadata.h>
#include <camera/VendorTagDescriptor.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android::hardware {
class ICamera;
class ICameraClient;
class ICameraServiceListener;
}  // namespace android::hardware
namespace android::hardware::camera2 {
class ICameraDeviceCallbacks;
class ICameraDeviceUser;
}  // namespace android::hardware::camera2
namespace android {
namespace hardware {
class ICameraServiceDelegator;

class ICameraService : public ::android::IInterface {
public:
  typedef ICameraServiceDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(CameraService)
  enum : int32_t { ERROR_PERMISSION_DENIED = 1 };
  enum : int32_t { ERROR_ALREADY_EXISTS = 2 };
  enum : int32_t { ERROR_ILLEGAL_ARGUMENT = 3 };
  enum : int32_t { ERROR_DISCONNECTED = 4 };
  enum : int32_t { ERROR_TIMED_OUT = 5 };
  enum : int32_t { ERROR_DISABLED = 6 };
  enum : int32_t { ERROR_CAMERA_IN_USE = 7 };
  enum : int32_t { ERROR_MAX_CAMERAS_IN_USE = 8 };
  enum : int32_t { ERROR_DEPRECATED_HAL = 9 };
  enum : int32_t { ERROR_INVALID_OPERATION = 10 };
  enum : int32_t { CAMERA_TYPE_BACKWARD_COMPATIBLE = 0 };
  enum : int32_t { CAMERA_TYPE_ALL = 1 };
  enum : int32_t { USE_CALLING_UID = -1 };
  enum : int32_t { USE_CALLING_PID = -1 };
  enum : int32_t { CAMERA_HAL_API_VERSION_UNSPECIFIED = -1 };
  enum : int32_t { API_VERSION_1 = 1 };
  enum : int32_t { API_VERSION_2 = 2 };
  enum : int32_t { EVENT_NONE = 0 };
  enum : int32_t { EVENT_USER_SWITCHED = 1 };
  enum : int32_t { DEVICE_STATE_NORMAL = 0 };
  enum : int32_t { DEVICE_STATE_BACK_COVERED = 1 };
  enum : int32_t { DEVICE_STATE_FRONT_COVERED = 2 };
  enum : int32_t { DEVICE_STATE_FOLDED = 4 };
  enum : int32_t { DEVICE_STATE_LAST_FRAMEWORK_BIT = -2147483648 };
  virtual ::android::binder::Status getNumberOfCameras(int32_t type, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getCameraInfo(int32_t cameraId, ::android::hardware::CameraInfo* _aidl_return) = 0;
  virtual ::android::binder::Status connect(const ::android::sp<::android::hardware::ICameraClient>& client, int32_t cameraId, const ::android::String16& opPackageName, int32_t clientUid, int32_t clientPid, ::android::sp<::android::hardware::ICamera>* _aidl_return) = 0;
  virtual ::android::binder::Status connectDevice(const ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacks>& callbacks, const ::android::String16& cameraId, const ::android::String16& opPackageName, int32_t clientUid, ::android::sp<::android::hardware::camera2::ICameraDeviceUser>* _aidl_return) = 0;
  virtual ::android::binder::Status connectLegacy(const ::android::sp<::android::hardware::ICameraClient>& client, int32_t cameraId, int32_t halVersion, const ::android::String16& opPackageName, int32_t clientUid, ::android::sp<::android::hardware::ICamera>* _aidl_return) = 0;
  virtual ::android::binder::Status addListener(const ::android::sp<::android::hardware::ICameraServiceListener>& listener, ::std::vector<::android::hardware::CameraStatus>* _aidl_return) = 0;
  virtual ::android::binder::Status removeListener(const ::android::sp<::android::hardware::ICameraServiceListener>& listener) = 0;
  virtual ::android::binder::Status getCameraCharacteristics(const ::android::String16& cameraId, ::android::hardware::camera2::impl::CameraMetadataNative* _aidl_return) = 0;
  virtual ::android::binder::Status getCameraVendorTagDescriptor(::android::hardware::camera2::params::VendorTagDescriptor* _aidl_return) = 0;
  virtual ::android::binder::Status getCameraVendorTagCache(::android::hardware::camera2::params::VendorTagDescriptorCache* _aidl_return) = 0;
  virtual ::android::binder::Status getLegacyParameters(int32_t cameraId, ::android::String16* _aidl_return) = 0;
  virtual ::android::binder::Status supportsCameraApi(const ::android::String16& cameraId, int32_t apiVersion, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isHiddenPhysicalCamera(const ::android::String16& cameraId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setTorchMode(const ::android::String16& cameraId, bool enabled, const ::android::sp<::android::IBinder>& clientBinder) = 0;
  virtual ::android::binder::Status notifySystemEvent(int32_t eventId, const ::std::vector<int32_t>& args) = 0;
  virtual ::android::binder::Status notifyDeviceStateChange(int64_t newState) = 0;
};  // class ICameraService

class ICameraServiceDefault : public ICameraService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getNumberOfCameras(int32_t /*type*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraInfo(int32_t /*cameraId*/, ::android::hardware::CameraInfo* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connect(const ::android::sp<::android::hardware::ICameraClient>& /*client*/, int32_t /*cameraId*/, const ::android::String16& /*opPackageName*/, int32_t /*clientUid*/, int32_t /*clientPid*/, ::android::sp<::android::hardware::ICamera>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connectDevice(const ::android::sp<::android::hardware::camera2::ICameraDeviceCallbacks>& /*callbacks*/, const ::android::String16& /*cameraId*/, const ::android::String16& /*opPackageName*/, int32_t /*clientUid*/, ::android::sp<::android::hardware::camera2::ICameraDeviceUser>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connectLegacy(const ::android::sp<::android::hardware::ICameraClient>& /*client*/, int32_t /*cameraId*/, int32_t /*halVersion*/, const ::android::String16& /*opPackageName*/, int32_t /*clientUid*/, ::android::sp<::android::hardware::ICamera>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status addListener(const ::android::sp<::android::hardware::ICameraServiceListener>& /*listener*/, ::std::vector<::android::hardware::CameraStatus>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeListener(const ::android::sp<::android::hardware::ICameraServiceListener>& /*listener*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraCharacteristics(const ::android::String16& /*cameraId*/, ::android::hardware::camera2::impl::CameraMetadataNative* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraVendorTagDescriptor(::android::hardware::camera2::params::VendorTagDescriptor* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCameraVendorTagCache(::android::hardware::camera2::params::VendorTagDescriptorCache* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLegacyParameters(int32_t /*cameraId*/, ::android::String16* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status supportsCameraApi(const ::android::String16& /*cameraId*/, int32_t /*apiVersion*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isHiddenPhysicalCamera(const ::android::String16& /*cameraId*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setTorchMode(const ::android::String16& /*cameraId*/, bool /*enabled*/, const ::android::sp<::android::IBinder>& /*clientBinder*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status notifySystemEvent(int32_t /*eventId*/, const ::std::vector<int32_t>& /*args*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status notifyDeviceStateChange(int64_t /*newState*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ICameraServiceDefault
}  // namespace hardware
}  // namespace android
