#include <android/bluetooth/IBluetoothLowEnergyCallback.h>
#include <android/bluetooth/BpBluetoothLowEnergyCallback.h>
namespace android {
namespace bluetooth {
DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(BluetoothLowEnergyCallback, "android.bluetooth.IBluetoothLowEnergyCallback")
}  // namespace bluetooth
}  // namespace android
#include <android/bluetooth/BpBluetoothLowEnergyCallback.h>
#include <android/bluetooth/BnBluetoothLowEnergyCallback.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {
namespace bluetooth {

BpBluetoothLowEnergyCallback::BpBluetoothLowEnergyCallback(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IBluetoothLowEnergyCallback>(_aidl_impl){
}

::android::binder::Status BpBluetoothLowEnergyCallback::OnClientRegistered(int32_t status, int32_t client_id) {
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
  _aidl_ret_status = _aidl_data.writeInt32(client_id);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnBluetoothLowEnergyCallback::TRANSACTION_OnClientRegistered, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBluetoothLowEnergyCallback::getDefaultImpl())) {
     return IBluetoothLowEnergyCallback::getDefaultImpl()->OnClientRegistered(status, client_id);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpBluetoothLowEnergyCallback::OnConnectionState(int32_t status, int32_t client_id, const ::android::String16& address, bool connected) {
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
  _aidl_ret_status = _aidl_data.writeInt32(client_id);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeString16(address);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeBool(connected);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnBluetoothLowEnergyCallback::TRANSACTION_OnConnectionState, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBluetoothLowEnergyCallback::getDefaultImpl())) {
     return IBluetoothLowEnergyCallback::getDefaultImpl()->OnConnectionState(status, client_id, address, connected);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

::android::binder::Status BpBluetoothLowEnergyCallback::OnMtuChanged(int32_t status, const ::android::String16& address, int32_t mtu) {
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
  _aidl_ret_status = _aidl_data.writeString16(address);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeInt32(mtu);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnBluetoothLowEnergyCallback::TRANSACTION_OnMtuChanged, _aidl_data, &_aidl_reply, ::android::IBinder::FLAG_ONEWAY);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBluetoothLowEnergyCallback::getDefaultImpl())) {
     return IBluetoothLowEnergyCallback::getDefaultImpl()->OnMtuChanged(status, address, mtu);
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
#include <android/bluetooth/BnBluetoothLowEnergyCallback.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {
namespace bluetooth {

BnBluetoothLowEnergyCallback::BnBluetoothLowEnergyCallback()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnBluetoothLowEnergyCallback::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnBluetoothLowEnergyCallback::TRANSACTION_OnClientRegistered:
  {
    int32_t in_status;
    int32_t in_client_id;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_client_id);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnClientRegistered(in_status, in_client_id));
  }
  break;
  case BnBluetoothLowEnergyCallback::TRANSACTION_OnConnectionState:
  {
    int32_t in_status;
    int32_t in_client_id;
    ::android::String16 in_address;
    bool in_connected;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_client_id);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readString16(&in_address);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readBool(&in_connected);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnConnectionState(in_status, in_client_id, in_address, in_connected));
  }
  break;
  case BnBluetoothLowEnergyCallback::TRANSACTION_OnMtuChanged:
  {
    int32_t in_status;
    ::android::String16 in_address;
    int32_t in_mtu;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_status);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readString16(&in_address);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    _aidl_ret_status = _aidl_data.readInt32(&in_mtu);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(OnMtuChanged(in_status, in_address, in_mtu));
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
