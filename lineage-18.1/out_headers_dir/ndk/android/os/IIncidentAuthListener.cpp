#include <android/binder_parcel_utils.h>
#include <aidl/android/os/BpIncidentAuthListener.h>
#include <aidl/android/os/BnIncidentAuthListener.h>
#include <aidl/android/os/IIncidentAuthListener.h>

namespace aidl {
namespace android {
namespace os {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnIncidentAuthListener> _aidl_impl = std::static_pointer_cast<BnIncidentAuthListener>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onReportApproved*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onReportApproved();
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*onReportDenied*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onReportDenied();
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IIncidentAuthListener::descriptor, _aidl_onTransact);

BpIncidentAuthListener::BpIncidentAuthListener(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpIncidentAuthListener::~BpIncidentAuthListener() {}

::ndk::ScopedAStatus BpIncidentAuthListener::onReportApproved() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onReportApproved*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IIncidentAuthListener::getDefaultImpl()) {
    return IIncidentAuthListener::getDefaultImpl()->onReportApproved();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpIncidentAuthListener::onReportDenied() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*onReportDenied*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IIncidentAuthListener::getDefaultImpl()) {
    return IIncidentAuthListener::getDefaultImpl()->onReportDenied();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnIncidentAuthListener
BnIncidentAuthListener::BnIncidentAuthListener() {}
BnIncidentAuthListener::~BnIncidentAuthListener() {}
::ndk::SpAIBinder BnIncidentAuthListener::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IIncidentAuthListener
const char* IIncidentAuthListener::descriptor = "android.os.IIncidentAuthListener";
IIncidentAuthListener::IIncidentAuthListener() {}
IIncidentAuthListener::~IIncidentAuthListener() {}


std::shared_ptr<IIncidentAuthListener> IIncidentAuthListener::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IIncidentAuthListener>(interface);
  }
  return ::ndk::SharedRefBase::make<BpIncidentAuthListener>(binder);
}

binder_status_t IIncidentAuthListener::writeToParcel(AParcel* parcel, const std::shared_ptr<IIncidentAuthListener>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IIncidentAuthListener::readFromParcel(const AParcel* parcel, std::shared_ptr<IIncidentAuthListener>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IIncidentAuthListener::fromBinder(binder);
  return STATUS_OK;
}
bool IIncidentAuthListener::setDefaultImpl(std::shared_ptr<IIncidentAuthListener> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IIncidentAuthListener::default_impl);
  if (impl) {
    IIncidentAuthListener::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IIncidentAuthListener>& IIncidentAuthListener::getDefaultImpl() {
  return IIncidentAuthListener::default_impl;
}
std::shared_ptr<IIncidentAuthListener> IIncidentAuthListener::default_impl = nullptr;
::ndk::ScopedAStatus IIncidentAuthListenerDefault::onReportApproved() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IIncidentAuthListenerDefault::onReportDenied() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IIncidentAuthListenerDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IIncidentAuthListenerDefault::isRemote() {
  return false;
}
}  // namespace os
}  // namespace android
}  // namespace aidl
