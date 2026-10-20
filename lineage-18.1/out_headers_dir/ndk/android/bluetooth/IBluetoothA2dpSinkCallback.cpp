#include <android/binder_parcel_utils.h>
#include <aidl/android/bluetooth/BpBluetoothA2dpSinkCallback.h>
#include <aidl/android/bluetooth/BnBluetoothA2dpSinkCallback.h>
#include <aidl/android/bluetooth/IBluetoothA2dpSinkCallback.h>

namespace aidl {
namespace android {
namespace bluetooth {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnBluetoothA2dpSinkCallback> _aidl_impl = std::static_pointer_cast<BnBluetoothA2dpSinkCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*OnRegistered*/): {
      int32_t in_status;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_status);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->OnRegistered(in_status);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*OnConnectionState*/): {
      std::string in_device_address;
      int32_t in_state;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_device_address);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_state);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->OnConnectionState(in_device_address, in_state);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*OnAudioState*/): {
      std::string in_device_address;
      int32_t in_state;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_device_address);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_state);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->OnAudioState(in_device_address, in_state);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*OnAudioConfig*/): {
      std::string in_device_address;
      int32_t in_sample_rate;
      int32_t in_channel_count;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_device_address);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_sample_rate);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_channel_count);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->OnAudioConfig(in_device_address, in_sample_rate, in_channel_count);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IBluetoothA2dpSinkCallback::descriptor, _aidl_onTransact);

BpBluetoothA2dpSinkCallback::BpBluetoothA2dpSinkCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpBluetoothA2dpSinkCallback::~BpBluetoothA2dpSinkCallback() {}

::ndk::ScopedAStatus BpBluetoothA2dpSinkCallback::OnRegistered(int32_t in_status) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_status);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*OnRegistered*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBluetoothA2dpSinkCallback::getDefaultImpl()) {
    return IBluetoothA2dpSinkCallback::getDefaultImpl()->OnRegistered(in_status);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpBluetoothA2dpSinkCallback::OnConnectionState(const std::string& in_device_address, int32_t in_state) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_device_address);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_state);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*OnConnectionState*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBluetoothA2dpSinkCallback::getDefaultImpl()) {
    return IBluetoothA2dpSinkCallback::getDefaultImpl()->OnConnectionState(in_device_address, in_state);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpBluetoothA2dpSinkCallback::OnAudioState(const std::string& in_device_address, int32_t in_state) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_device_address);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_state);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*OnAudioState*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBluetoothA2dpSinkCallback::getDefaultImpl()) {
    return IBluetoothA2dpSinkCallback::getDefaultImpl()->OnAudioState(in_device_address, in_state);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpBluetoothA2dpSinkCallback::OnAudioConfig(const std::string& in_device_address, int32_t in_sample_rate, int32_t in_channel_count) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_device_address);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_sample_rate);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_channel_count);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*OnAudioConfig*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBluetoothA2dpSinkCallback::getDefaultImpl()) {
    return IBluetoothA2dpSinkCallback::getDefaultImpl()->OnAudioConfig(in_device_address, in_sample_rate, in_channel_count);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnBluetoothA2dpSinkCallback
BnBluetoothA2dpSinkCallback::BnBluetoothA2dpSinkCallback() {}
BnBluetoothA2dpSinkCallback::~BnBluetoothA2dpSinkCallback() {}
::ndk::SpAIBinder BnBluetoothA2dpSinkCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IBluetoothA2dpSinkCallback
const char* IBluetoothA2dpSinkCallback::descriptor = "android.bluetooth.IBluetoothA2dpSinkCallback";
IBluetoothA2dpSinkCallback::IBluetoothA2dpSinkCallback() {}
IBluetoothA2dpSinkCallback::~IBluetoothA2dpSinkCallback() {}


std::shared_ptr<IBluetoothA2dpSinkCallback> IBluetoothA2dpSinkCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IBluetoothA2dpSinkCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpBluetoothA2dpSinkCallback>(binder);
}

binder_status_t IBluetoothA2dpSinkCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothA2dpSinkCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IBluetoothA2dpSinkCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothA2dpSinkCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IBluetoothA2dpSinkCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IBluetoothA2dpSinkCallback::setDefaultImpl(std::shared_ptr<IBluetoothA2dpSinkCallback> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IBluetoothA2dpSinkCallback::default_impl);
  if (impl) {
    IBluetoothA2dpSinkCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IBluetoothA2dpSinkCallback>& IBluetoothA2dpSinkCallback::getDefaultImpl() {
  return IBluetoothA2dpSinkCallback::default_impl;
}
std::shared_ptr<IBluetoothA2dpSinkCallback> IBluetoothA2dpSinkCallback::default_impl = nullptr;
::ndk::ScopedAStatus IBluetoothA2dpSinkCallbackDefault::OnRegistered(int32_t /*in_status*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IBluetoothA2dpSinkCallbackDefault::OnConnectionState(const std::string& /*in_device_address*/, int32_t /*in_state*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IBluetoothA2dpSinkCallbackDefault::OnAudioState(const std::string& /*in_device_address*/, int32_t /*in_state*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IBluetoothA2dpSinkCallbackDefault::OnAudioConfig(const std::string& /*in_device_address*/, int32_t /*in_sample_rate*/, int32_t /*in_channel_count*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IBluetoothA2dpSinkCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IBluetoothA2dpSinkCallbackDefault::isRemote() {
  return false;
}
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
