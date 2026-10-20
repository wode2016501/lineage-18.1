#include <android/hardware/vibrator/IVibratorCallback.h>
#include <android/hardware/vibrator/BpVibratorCallback.h>

namespace android {

namespace hardware {

namespace vibrator {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(VibratorCallback, "android.hardware.vibrator.IVibratorCallback")

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
#include <android/hardware/vibrator/BpVibratorCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace hardware {

namespace vibrator {

BpVibratorCallback::BpVibratorCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IVibratorCallback>(_aidl_impl){
}

::android::binder::Status BpVibratorCallback::onComplete() {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onComplete */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IVibratorCallback::getDefaultImpl())) {
     return IVibratorCallback::getDefaultImpl()->onComplete();
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
#include <android/hardware/vibrator/BnVibratorCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace hardware {

namespace vibrator {

BnVibratorCallback::BnVibratorCallback()
{
  ::android::internal::Stability::markVintf(this);
}

::android::status_t BnVibratorCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onComplete */:
  {
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    ::android::binder::Status _aidl_status(onComplete());
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

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
