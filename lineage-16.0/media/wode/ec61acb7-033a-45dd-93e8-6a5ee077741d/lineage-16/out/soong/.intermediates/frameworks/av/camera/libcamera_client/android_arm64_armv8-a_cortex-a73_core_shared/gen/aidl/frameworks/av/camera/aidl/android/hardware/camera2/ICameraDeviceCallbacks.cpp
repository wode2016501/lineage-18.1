#include <android/hardware/camera2/ICameraDeviceCallbacks.h>
#include <android/hardware/camera2/BpCameraDeviceCallbacks.h>

namespace android {

namespace hardware {

namespace camera2 {

IMPLEMENT_META_INTERFACE(CameraDeviceCallbacks, "android.hardware.camera2.ICameraDeviceCallbacks")

}  // namespace camera2

}  // namespace hardware

}  // namespace android
#include <android/hardware/camera2/BpCameraDeviceCallbacks.h>
#include <binder/Parcel.h>

namespace android {

namespace hardware {

namespace camera2 {

BpCameraDeviceCallbacks::BpCameraDeviceCallbacks(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<ICameraDeviceCallbacks>(_aidl_impl){
}

::android::binder::Status BpCameraDeviceCallbacks::onDeviceError(int32_t errorCode, const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras) {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeInt32(errorCode);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeParcelable(resultExtras);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraDeviceCallbacks::ONDEVICEERROR, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

::android::binder::Status BpCameraDeviceCallbacks::onDeviceIdle() {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraDeviceCallbacks::ONDEVICEIDLE, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

::android::binder::Status BpCameraDeviceCallbacks::onCaptureStarted(const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras, int64_t timestamp) {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeParcelable(resultExtras);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeInt64(timestamp);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraDeviceCallbacks::ONCAPTURESTARTED, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

::android::binder::Status BpCameraDeviceCallbacks::onResultReceived(const ::android::hardware::camera2::impl::CameraMetadataNative& result, const ::android::hardware::camera2::impl::CaptureResultExtras& resultExtras, const ::std::vector<::android::hardware::camera2::impl::PhysicalCaptureResultInfo>& physicalCaptureResultInfos) {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeParcelable(result);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeParcelable(resultExtras);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeParcelableVector(physicalCaptureResultInfos);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraDeviceCallbacks::ONRESULTRECEIVED, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

::android::binder::Status BpCameraDeviceCallbacks::onPrepared(int32_t streamId) {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeInt32(streamId);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraDeviceCallbacks::ONPREPARED, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

::android::binder::Status BpCameraDeviceCallbacks::onRepeatingRequestError(int64_t lastFrameNumber, int32_t repeatingRequestId) {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeInt64(lastFrameNumber);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = _aidl_data.writeInt32(repeatingRequestId);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraDeviceCallbacks::ONREPEATINGREQUESTERROR, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

::android::binder::Status BpCameraDeviceCallbacks::onRequestQueueEmpty() {
::android::Parcel _aidl_data;
::android::Parcel _aidl_reply;
::android::status_t _aidl_ret_status = ::android::OK;
::android::binder::Status _aidl_status;
_aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_ret_status = remote()->transact(ICameraDeviceCallbacks::ONREQUESTQUEUEEMPTY, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
if (((_aidl_ret_status) != (::android::OK))) {
goto _aidl_error;
}
_aidl_error:
_aidl_status.setFromStatusT(_aidl_ret_status);
return _aidl_status;
}

}  // namespace camera2

}  // namespace hardware

}  // namespace android
#include <android/hardware/camera2/BnCameraDeviceCallbacks.h>
#include <binder/Parcel.h>

namespace android {

namespace hardware {

namespace camera2 {

::android::status_t BnCameraDeviceCallbacks::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
::android::status_t _aidl_ret_status = ::android::OK;
switch (_aidl_code) {
case Call::ONDEVICEERROR:
{
int32_t in_errorCode;
::android::hardware::camera2::impl::CaptureResultExtras in_resultExtras;
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
_aidl_ret_status = _aidl_data.readInt32(&in_errorCode);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
_aidl_ret_status = _aidl_data.readParcelable(&in_resultExtras);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
::android::binder::Status _aidl_status(onDeviceError(in_errorCode, in_resultExtras));
}
break;
case Call::ONDEVICEIDLE:
{
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
::android::binder::Status _aidl_status(onDeviceIdle());
}
break;
case Call::ONCAPTURESTARTED:
{
::android::hardware::camera2::impl::CaptureResultExtras in_resultExtras;
int64_t in_timestamp;
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
_aidl_ret_status = _aidl_data.readParcelable(&in_resultExtras);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
_aidl_ret_status = _aidl_data.readInt64(&in_timestamp);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
::android::binder::Status _aidl_status(onCaptureStarted(in_resultExtras, in_timestamp));
}
break;
case Call::ONRESULTRECEIVED:
{
::android::hardware::camera2::impl::CameraMetadataNative in_result;
::android::hardware::camera2::impl::CaptureResultExtras in_resultExtras;
::std::vector<::android::hardware::camera2::impl::PhysicalCaptureResultInfo> in_physicalCaptureResultInfos;
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
_aidl_ret_status = _aidl_data.readParcelable(&in_result);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
_aidl_ret_status = _aidl_data.readParcelable(&in_resultExtras);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
_aidl_ret_status = _aidl_data.readParcelableVector(&in_physicalCaptureResultInfos);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
::android::binder::Status _aidl_status(onResultReceived(in_result, in_resultExtras, in_physicalCaptureResultInfos));
}
break;
case Call::ONPREPARED:
{
int32_t in_streamId;
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
_aidl_ret_status = _aidl_data.readInt32(&in_streamId);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
::android::binder::Status _aidl_status(onPrepared(in_streamId));
}
break;
case Call::ONREPEATINGREQUESTERROR:
{
int64_t in_lastFrameNumber;
int32_t in_repeatingRequestId;
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
_aidl_ret_status = _aidl_data.readInt64(&in_lastFrameNumber);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
_aidl_ret_status = _aidl_data.readInt32(&in_repeatingRequestId);
if (((_aidl_ret_status) != (::android::OK))) {
break;
}
::android::binder::Status _aidl_status(onRepeatingRequestError(in_lastFrameNumber, in_repeatingRequestId));
}
break;
case Call::ONREQUESTQUEUEEMPTY:
{
if (!(_aidl_data.checkInterface(this))) {
_aidl_ret_status = ::android::BAD_TYPE;
break;
}
::android::binder::Status _aidl_status(onRequestQueueEmpty());
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

}  // namespace camera2

}  // namespace hardware

}  // namespace android
