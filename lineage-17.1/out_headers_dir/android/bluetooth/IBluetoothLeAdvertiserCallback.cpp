#include <android/bluetooth/IBluetoothLeAdvertiserCallback.h>
#include <android/bluetooth/BpBluetoothLeAdvertiserCallback.h>
namespace android {
namespace bluetooth {
DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(BluetoothLeAdvertiserCallback, "android.bluetooth.IBluetoothLeAdvertiserCallback")
}  // namespace bluetooth
}  // namespace android
#include <android/bluetooth/BpBluetoothLeAdvertiserCallback.h>
#include <android/bluetooth/BnBluetoothLeAdvertiserCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {
namespace bluetooth {

BpBluetoothLeAdvertiserCallback::BpBluetoothLeAdvertiserCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IBluetoothLeAdvertiserCallback>(_aidl_impl){
}

::android::binder::Status BpBluetoothLeAdvertiserCallback::OnAdvertiserRegistered(int32_t status, int32_t advertiser_id) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
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
  _aidl_ret_status = _aidl_data.writeInt32(advertiser_id);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnBluetoothLeAdvertiserCallback::TRANSACTION_OnAdvertiserRegistered, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBluetoothLeAdvertiserCallback::getDefaultImpl())) {
     return IBluetoothLeAdvertiserCallback::getDefaultImpl()->OnAdvertiserRegistered(status, advertiser_id);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpBluetoothLeAdvertiserCallback::OnMultiAdvertiseCallback(int32_t status, bool is_start, const ::android::bluetooth::AdvertiseSettings& settings) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
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
  _aidl_ret_status = _aidl_data.writeBool(is_start);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeParcelable(settings);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnBluetoothLeAdvertiserCallback::TRANSACTION_OnMultiAdvertiseCallback, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBluetoothLeAdvertiserCallback::getDefaultImpl())) {
     return IBluetoothLeAdvertiserCallback::getDefaultImpl()->OnMultiAdvertiseCallback(status, is_start, settings);
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
#include <android/bluetooth/BnBluetoothLeAdvertiserCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {
namespace bluetooth {

BnBluetoothLeAdvertiserCallback::BnBluetoothLeAdvertiserCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnBluetoothLeAdvertiserCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnBluetoothLeAdvertiserCallback::TRANSACTION_OnAdvertiserRegistered:
  {
    int32_t in_status;
    int32_t in_advertiser_id;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_advertiser_id);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnAdvertiserRegistered(in_status, in_advertiser_id));
  }
  break;
  case BnBluetoothLeAdvertiserCallback::TRANSACTION_OnMultiAdvertiseCallback:
  {
    int32_t in_status;
    bool in_is_start;
    ::android::bluetooth::AdvertiseSettings in_settings;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_is_start);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readParcelable(&in_settings);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnMultiAdvertiseCallback(in_status, in_is_start, in_settings));
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

}  // namespace bluetooth
}  // namespace android
