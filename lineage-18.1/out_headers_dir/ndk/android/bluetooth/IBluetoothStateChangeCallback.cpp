#include <android/binder_parcel_utils.h>
#include <aidl/android/bluetooth/BpBluetoothStateChangeCallback.h>
#include <aidl/android/bluetooth/BnBluetoothStateChangeCallback.h>
#include <aidl/android/bluetooth/IBluetoothStateChangeCallback.h>

namespace aidl {
namespace android {
namespace bluetooth {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnBluetoothStateChangeCallback> _aidl_impl = std::static_pointer_cast<BnBluetoothStateChangeCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onBluetoothStateChange*/): {
      bool in_on;

      _aidl_ret_status = AParcel_readBool(_aidl_in, &in_on);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onBluetoothStateChange(in_on);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IBluetoothStateChangeCallback::descriptor, _aidl_onTransact);

BpBluetoothStateChangeCallback::BpBluetoothStateChangeCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpBluetoothStateChangeCallback::~BpBluetoothStateChangeCallback() {}

::ndk::ScopedAStatus BpBluetoothStateChangeCallback::onBluetoothStateChange(bool in_on) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeBool(_aidl_in.get(), in_on);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onBluetoothStateChange*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBluetoothStateChangeCallback::getDefaultImpl()) {
    return IBluetoothStateChangeCallback::getDefaultImpl()->onBluetoothStateChange(in_on);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnBluetoothStateChangeCallback
BnBluetoothStateChangeCallback::BnBluetoothStateChangeCallback() {}
BnBluetoothStateChangeCallback::~BnBluetoothStateChangeCallback() {}
::ndk::SpAIBinder BnBluetoothStateChangeCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IBluetoothStateChangeCallback
const char* IBluetoothStateChangeCallback::descriptor = "android.bluetooth.IBluetoothStateChangeCallback";
IBluetoothStateChangeCallback::IBluetoothStateChangeCallback() {}
IBluetoothStateChangeCallback::~IBluetoothStateChangeCallback() {}


std::shared_ptr<IBluetoothStateChangeCallback> IBluetoothStateChangeCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IBluetoothStateChangeCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpBluetoothStateChangeCallback>(binder);
}

binder_status_t IBluetoothStateChangeCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothStateChangeCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IBluetoothStateChangeCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothStateChangeCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IBluetoothStateChangeCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IBluetoothStateChangeCallback::setDefaultImpl(std::shared_ptr<IBluetoothStateChangeCallback> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IBluetoothStateChangeCallback::default_impl);
  if (impl) {
    IBluetoothStateChangeCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IBluetoothStateChangeCallback>& IBluetoothStateChangeCallback::getDefaultImpl() {
  return IBluetoothStateChangeCallback::default_impl;
}
std::shared_ptr<IBluetoothStateChangeCallback> IBluetoothStateChangeCallback::default_impl = nullptr;
::ndk::ScopedAStatus IBluetoothStateChangeCallbackDefault::onBluetoothStateChange(bool /*in_on*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IBluetoothStateChangeCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IBluetoothStateChangeCallbackDefault::isRemote() {
  return false;
}
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
