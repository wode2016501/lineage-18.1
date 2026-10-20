#include <android/hardware/automotive/occupant_awareness/IOccupantAwarenessClientCallback.h>
#include <android/hardware/automotive/occupant_awareness/BpOccupantAwarenessClientCallback.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(OccupantAwarenessClientCallback, "android.hardware.automotive.occupant_awareness.IOccupantAwarenessClientCallback")

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android
#include <android/hardware/automotive/occupant_awareness/BpOccupantAwarenessClientCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

BpOccupantAwarenessClientCallback::BpOccupantAwarenessClientCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IOccupantAwarenessClientCallback>(_aidl_impl){
}

::android::binder::Status BpOccupantAwarenessClientCallback::onSystemStatusChanged(int32_t detectionFlags, ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus status) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(detectionFlags);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByte(static_cast<int8_t>(status));
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onSystemStatusChanged */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IOccupantAwarenessClientCallback::getDefaultImpl())) {
     return IOccupantAwarenessClientCallback::getDefaultImpl()->onSystemStatusChanged(detectionFlags, status);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpOccupantAwarenessClientCallback::onDetectionEvent(const ::android::hardware::automotive::occupant_awareness::OccupantDetections& detections) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(detections);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 1 /* onDetectionEvent */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IOccupantAwarenessClientCallback::getDefaultImpl())) {
     return IOccupantAwarenessClientCallback::getDefaultImpl()->onDetectionEvent(detections);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android
#include <android/hardware/automotive/occupant_awareness/BnOccupantAwarenessClientCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

BnOccupantAwarenessClientCallback::BnOccupantAwarenessClientCallback()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnOccupantAwarenessClientCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onSystemStatusChanged */:
  {
    int32_t in_detectionFlags;
    ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus in_status;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_detectionFlags);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readByte(reinterpret_cast<int8_t *>(&in_status));
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onSystemStatusChanged(in_detectionFlags, in_status));
  }
  break;
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 1 /* onDetectionEvent */:
  {
    ::android::hardware::automotive::occupant_awareness::OccupantDetections in_detections;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_detections);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onDetectionEvent(in_detections));
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

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android
