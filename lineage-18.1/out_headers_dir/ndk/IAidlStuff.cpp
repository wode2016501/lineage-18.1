#include <android/binder_parcel_utils.h>
#include <aidl/BpAidlStuff.h>
#include <aidl/BnAidlStuff.h>
#include <aidl/IAidlStuff.h>

namespace aidl {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnAidlStuff> _aidl_impl = std::static_pointer_cast<BnAidlStuff>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*callLocal*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->callLocal();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*call*/): {
      int32_t in_idx;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_idx);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->call(in_idx);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IAidlStuff::descriptor, _aidl_onTransact);

BpAidlStuff::BpAidlStuff(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpAidlStuff::~BpAidlStuff() {}

::ndk::ScopedAStatus BpAidlStuff::callLocal() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*callLocal*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IAidlStuff::getDefaultImpl()) {
    return IAidlStuff::getDefaultImpl()->callLocal();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpAidlStuff::call(int32_t in_idx) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_idx);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*call*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IAidlStuff::getDefaultImpl()) {
    return IAidlStuff::getDefaultImpl()->call(in_idx);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnAidlStuff
BnAidlStuff::BnAidlStuff() {}
BnAidlStuff::~BnAidlStuff() {}
::ndk::SpAIBinder BnAidlStuff::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IAidlStuff
const char* IAidlStuff::descriptor = "IAidlStuff";
IAidlStuff::IAidlStuff() {}
IAidlStuff::~IAidlStuff() {}


std::shared_ptr<IAidlStuff> IAidlStuff::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IAidlStuff>(interface);
  }
  return ::ndk::SharedRefBase::make<BpAidlStuff>(binder);
}

binder_status_t IAidlStuff::writeToParcel(AParcel* parcel, const std::shared_ptr<IAidlStuff>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IAidlStuff::readFromParcel(const AParcel* parcel, std::shared_ptr<IAidlStuff>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IAidlStuff::fromBinder(binder);
  return STATUS_OK;
}
bool IAidlStuff::setDefaultImpl(std::shared_ptr<IAidlStuff> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IAidlStuff::default_impl);
  if (impl) {
    IAidlStuff::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IAidlStuff>& IAidlStuff::getDefaultImpl() {
  return IAidlStuff::default_impl;
}
std::shared_ptr<IAidlStuff> IAidlStuff::default_impl = nullptr;
::ndk::ScopedAStatus IAidlStuffDefault::callLocal() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IAidlStuffDefault::call(int32_t /*in_idx*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IAidlStuffDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IAidlStuffDefault::isRemote() {
  return false;
}
}  // namespace aidl
