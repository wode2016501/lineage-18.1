#include <android/binder_parcel_utils.h>
#include <aidl/android/bluetooth/BpBluetoothGattClientCallback.h>
#include <aidl/android/bluetooth/BnBluetoothGattClientCallback.h>
#include <aidl/android/bluetooth/IBluetoothGattClientCallback.h>

namespace aidl {
namespace android {
namespace bluetooth {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnBluetoothGattClientCallback> _aidl_impl = std::static_pointer_cast<BnBluetoothGattClientCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*OnClientRegistered*/): {
      int32_t in_status;
      int32_t in_client_id;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_status);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_client_id);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->OnClientRegistered(in_status, in_client_id);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IBluetoothGattClientCallback::descriptor, _aidl_onTransact);

BpBluetoothGattClientCallback::BpBluetoothGattClientCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpBluetoothGattClientCallback::~BpBluetoothGattClientCallback() {}

::ndk::ScopedAStatus BpBluetoothGattClientCallback::OnClientRegistered(int32_t in_status, int32_t in_client_id) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_status);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_client_id);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*OnClientRegistered*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBluetoothGattClientCallback::getDefaultImpl()) {
    return IBluetoothGattClientCallback::getDefaultImpl()->OnClientRegistered(in_status, in_client_id);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnBluetoothGattClientCallback
BnBluetoothGattClientCallback::BnBluetoothGattClientCallback() {}
BnBluetoothGattClientCallback::~BnBluetoothGattClientCallback() {}
::ndk::SpAIBinder BnBluetoothGattClientCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IBluetoothGattClientCallback
const char* IBluetoothGattClientCallback::descriptor = "android.bluetooth.IBluetoothGattClientCallback";
IBluetoothGattClientCallback::IBluetoothGattClientCallback() {}
IBluetoothGattClientCallback::~IBluetoothGattClientCallback() {}


std::shared_ptr<IBluetoothGattClientCallback> IBluetoothGattClientCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IBluetoothGattClientCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpBluetoothGattClientCallback>(binder);
}

binder_status_t IBluetoothGattClientCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothGattClientCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IBluetoothGattClientCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothGattClientCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IBluetoothGattClientCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IBluetoothGattClientCallback::setDefaultImpl(std::shared_ptr<IBluetoothGattClientCallback> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IBluetoothGattClientCallback::default_impl);
  if (impl) {
    IBluetoothGattClientCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IBluetoothGattClientCallback>& IBluetoothGattClientCallback::getDefaultImpl() {
  return IBluetoothGattClientCallback::default_impl;
}
std::shared_ptr<IBluetoothGattClientCallback> IBluetoothGattClientCallback::default_impl = nullptr;
::ndk::ScopedAStatus IBluetoothGattClientCallbackDefault::OnClientRegistered(int32_t /*in_status*/, int32_t /*in_client_id*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IBluetoothGattClientCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IBluetoothGattClientCallbackDefault::isRemote() {
  return false;
}
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
