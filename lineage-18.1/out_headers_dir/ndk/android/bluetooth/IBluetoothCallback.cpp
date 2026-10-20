#include <android/binder_parcel_utils.h>
#include <aidl/android/bluetooth/BpBluetoothCallback.h>
#include <aidl/android/bluetooth/BnBluetoothCallback.h>
#include <aidl/android/bluetooth/IBluetoothCallback.h>

namespace aidl {
namespace android {
namespace bluetooth {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnBluetoothCallback> _aidl_impl = std::static_pointer_cast<BnBluetoothCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onBluetoothStateChange*/): {
      int32_t in_prevState;
      int32_t in_newState;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_prevState);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_newState);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onBluetoothStateChange(in_prevState, in_newState);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IBluetoothCallback::descriptor, _aidl_onTransact);

BpBluetoothCallback::BpBluetoothCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpBluetoothCallback::~BpBluetoothCallback() {}

::ndk::ScopedAStatus BpBluetoothCallback::onBluetoothStateChange(int32_t in_prevState, int32_t in_newState) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_prevState);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_newState);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onBluetoothStateChange*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBluetoothCallback::getDefaultImpl()) {
    return IBluetoothCallback::getDefaultImpl()->onBluetoothStateChange(in_prevState, in_newState);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnBluetoothCallback
BnBluetoothCallback::BnBluetoothCallback() {}
BnBluetoothCallback::~BnBluetoothCallback() {}
::ndk::SpAIBinder BnBluetoothCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IBluetoothCallback
const char* IBluetoothCallback::descriptor = "android.bluetooth.IBluetoothCallback";
IBluetoothCallback::IBluetoothCallback() {}
IBluetoothCallback::~IBluetoothCallback() {}


std::shared_ptr<IBluetoothCallback> IBluetoothCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IBluetoothCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpBluetoothCallback>(binder);
}

binder_status_t IBluetoothCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IBluetoothCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IBluetoothCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IBluetoothCallback::setDefaultImpl(std::shared_ptr<IBluetoothCallback> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IBluetoothCallback::default_impl);
  if (impl) {
    IBluetoothCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IBluetoothCallback>& IBluetoothCallback::getDefaultImpl() {
  return IBluetoothCallback::default_impl;
}
std::shared_ptr<IBluetoothCallback> IBluetoothCallback::default_impl = nullptr;
::ndk::ScopedAStatus IBluetoothCallbackDefault::onBluetoothStateChange(int32_t /*in_prevState*/, int32_t /*in_newState*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IBluetoothCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IBluetoothCallbackDefault::isRemote() {
  return false;
}
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
