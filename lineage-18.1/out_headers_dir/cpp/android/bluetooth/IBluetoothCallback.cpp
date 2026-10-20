#include <android/bluetooth/IBluetoothCallback.h>
#include <android/bluetooth/BpBluetoothCallback.h>

namespace android {

namespace bluetooth {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(BluetoothCallback, "android.bluetooth.IBluetoothCallback")

}  // namespace bluetooth

}  // namespace android
#include <android/bluetooth/BpBluetoothCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

namespace bluetooth {

BpBluetoothCallback::BpBluetoothCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IBluetoothCallback>(_aidl_impl){
}

::android::binder::Status BpBluetoothCallback::onBluetoothStateChange(int32_t prevState, int32_t newState) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(prevState);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(newState);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onBluetoothStateChange */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBluetoothCallback::getDefaultImpl())) {
     return IBluetoothCallback::getDefaultImpl()->onBluetoothStateChange(prevState, newState);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace bluetooth

}  // namespace android
#include <android/bluetooth/BnBluetoothCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

namespace bluetooth {

BnBluetoothCallback::BnBluetoothCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnBluetoothCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* onBluetoothStateChange */:
  {
    int32_t in_prevState;
    int32_t in_newState;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_prevState);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_newState);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(onBluetoothStateChange(in_prevState, in_newState));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
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
