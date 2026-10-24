#include <android/hardware/ICameraServiceProxy.h>
#include <android/hardware/BpCameraServiceProxy.h>
namespace android {
namespace hardware {
DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(CameraServiceProxy, "android.hardware.ICameraServiceProxy")
}  // namespace hardware
}  // namespace android
#include <android/hardware/BpCameraServiceProxy.h>
#include <android/hardware/BnCameraServiceProxy.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {
namespace hardware {

BpCameraServiceProxy::BpCameraServiceProxy(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ICameraServiceProxy>(_aidl_impl){
}

::android::binder::Status BpCameraServiceProxy::pingForUserUpdate() {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnCameraServiceProxy::TRANSACTION_pingForUserUpdate, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ICameraServiceProxy::getDefaultImpl())) {
     return ICameraServiceProxy::getDefaultImpl()->pingForUserUpdate();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpCameraServiceProxy::notifyCameraState(const ::android::String16& cameraId, int32_t facing, int32_t newCameraState, const ::android::String16& clientName, int32_t apiLevel) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeString16(cameraId);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(facing);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(newCameraState);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeString16(clientName);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(apiLevel);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnCameraServiceProxy::TRANSACTION_notifyCameraState, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && ICameraServiceProxy::getDefaultImpl())) {
     return ICameraServiceProxy::getDefaultImpl()->notifyCameraState(cameraId, facing, newCameraState, clientName, apiLevel);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace hardware
}  // namespace android
#include <android/hardware/BnCameraServiceProxy.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {
namespace hardware {

BnCameraServiceProxy::BnCameraServiceProxy()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnCameraServiceProxy::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnCameraServiceProxy::TRANSACTION_pingForUserUpdate:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(pingForUserUpdate());
  }
  break;
  case BnCameraServiceProxy::TRANSACTION_notifyCameraState:
  {
    ::android::String16 in_cameraId;
    int32_t in_facing;
    int32_t in_newCameraState;
    ::android::String16 in_clientName;
    int32_t in_apiLevel;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readString16(&in_cameraId);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_facing);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_newCameraState);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readString16(&in_clientName);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_apiLevel);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(notifyCameraState(in_cameraId, in_facing, in_newCameraState, in_clientName, in_apiLevel));
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeOverParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

}  // namespace hardware
}  // namespace android
