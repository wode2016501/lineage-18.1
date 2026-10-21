#include <android/hardware/ICameraServiceListener.h>
#include <android/hardware/BpCameraServiceListener.h>

namespace android {

namespace hardware {

IMPLEMENT_META_INTERFACE(CameraServiceListener, "android.hardware.ICameraServiceListener")

}  // namespace hardware

}  // namespace android
#include <android/hardware/BpCameraServiceListener.h>
#include <binder/Parcel.h>

namespace android {

namespace hardware {

BpCameraServiceListener::BpCameraServiceListener(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ICameraServiceListener>(_aidl_impl){
}

::android::binder::Status BpCameraServiceListener::onStatusChanged(int32_t status, const ::android::String16& cameraId) {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeInt32(status);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeString16(cameraId);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraServiceListener::ONSTATUSCHANGED, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

::android::binder::Status BpCameraServiceListener::onTorchStatusChanged(int32_t status, const ::android::String16& cameraId) {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeInt32(status);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeString16(cameraId);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraServiceListener::ONTORCHSTATUSCHANGED, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

}  // namespace hardware

}  // namespace android
#include <android/hardware/BnCameraServiceListener.h>
#include <binder/Parcel.h>

namespace android {

namespace hardware {

::android::status_t BnCameraServiceListener::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
::android::status_t _aidl_ret_status = ::android::OK;
switch (_aidl_code) {
case Call::ONSTATUSCHANGED:
{
int32_t in_status;
::android::String16 in_cameraId;
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
_aidl_ret_status = _aidl_data.readInt32(&in_status);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
_aidl_ret_status = _aidl_data.readString16(&in_cameraId);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
::android::binder::Status _aidl_status(onStatusChanged(in_status, in_cameraId));
}
break;
case Call::ONTORCHSTATUSCHANGED:
{
int32_t in_status;
::android::String16 in_cameraId;
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
_aidl_ret_status = _aidl_data.readInt32(&in_status);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
_aidl_ret_status = _aidl_data.readString16(&in_cameraId);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
::android::binder::Status _aidl_status(onTorchStatusChanged(in_status, in_cameraId));
}
break;
default:
{
_aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
}
break;
}
if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
_aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
}
return _aidl_ret_status;
}

}  // namespace hardware

}  // namespace android
