#include <android/bluetooth/IBluetoothStateChangeCallback.h>
#include <android/bluetooth/BpBluetoothStateChangeCallback.h>

namespace android {

namespace bluetooth {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(BluetoothStateChangeCallback, "android.bluetooth.IBluetoothStateChangeCallback")

}  // namespace bluetooth

}  // namespace android
#include <android/bluetooth/BpBluetoothStateChangeCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace bluetooth {

BpBluetoothStateChangeCallback::BpBluetoothStateChangeCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IBluetoothStateChangeCallback>(_aidl_impl){
}

::android::binder::Status BpBluetoothStateChangeCallback::onBluetoothStateChange(bool on) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(on);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onBluetoothStateChange */, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBluetoothStateChangeCallback::getDefaultImpl())) {
     return IBluetoothStateChangeCallback::getDefaultImpl()->onBluetoothStateChange(on);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace bluetooth

}  // namespace android
#include <android/bluetooth/BnBluetoothStateChangeCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace bluetooth {

BnBluetoothStateChangeCallback::BnBluetoothStateChangeCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnBluetoothStateChangeCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onBluetoothStateChange */:
  {
    bool in_on;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_on);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onBluetoothStateChange(in_on));
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

}  // namespace bluetooth

}  // namespace android
