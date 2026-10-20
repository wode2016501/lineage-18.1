#include <android/binder_parcel_utils.h>
#include <aidl/android/dvr/BpVrComposer.h>
#include <aidl/android/dvr/BnVrComposer.h>
#include <aidl/android/dvr/IVrComposer.h>
#include <aidl/android/dvr/BpVrComposerCallback.h>
#include <aidl/android/dvr/BnVrComposerCallback.h>
#include <aidl/android/dvr/IVrComposerCallback.h>

namespace aidl {
namespace android {
namespace dvr {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnVrComposer> _aidl_impl = std::static_pointer_cast<BnVrComposer>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*registerObserver*/): {
      std::shared_ptr<::aidl::android::dvr::IVrComposerCallback> in_callback;

      _aidl_ret_status = ::aidl::android::dvr::IVrComposerCallback::readFromParcel(_aidl_in, &in_callback);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->registerObserver(in_callback);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*clearObserver*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->clearObserver();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IVrComposer::descriptor, _aidl_onTransact);

BpVrComposer::BpVrComposer(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpVrComposer::~BpVrComposer() {}

::ndk::ScopedAStatus BpVrComposer::registerObserver(const std::shared_ptr<::aidl::android::dvr::IVrComposerCallback>& in_callback) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::dvr::IVrComposerCallback::writeToParcel(_aidl_in.get(), in_callback);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*registerObserver*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IVrComposer::getDefaultImpl()) {
    return IVrComposer::getDefaultImpl()->registerObserver(in_callback);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpVrComposer::clearObserver() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*clearObserver*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IVrComposer::getDefaultImpl()) {
    return IVrComposer::getDefaultImpl()->clearObserver();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnVrComposer
BnVrComposer::BnVrComposer() {}
BnVrComposer::~BnVrComposer() {}
::ndk::SpAIBinder BnVrComposer::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IVrComposer
const char* IVrComposer::descriptor = "android.dvr.IVrComposer";
IVrComposer::IVrComposer() {}
IVrComposer::~IVrComposer() {}

const char* IVrComposer::SERVICE_NAME = "vr_hwc";

std::shared_ptr<IVrComposer> IVrComposer::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IVrComposer>(interface);
  }
  return ::ndk::SharedRefBase::make<BpVrComposer>(binder);
}

binder_status_t IVrComposer::writeToParcel(AParcel* parcel, const std::shared_ptr<IVrComposer>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IVrComposer::readFromParcel(const AParcel* parcel, std::shared_ptr<IVrComposer>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IVrComposer::fromBinder(binder);
  return STATUS_OK;
}
bool IVrComposer::setDefaultImpl(std::shared_ptr<IVrComposer> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IVrComposer::default_impl);
  if (impl) {
    IVrComposer::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IVrComposer>& IVrComposer::getDefaultImpl() {
  return IVrComposer::default_impl;
}
std::shared_ptr<IVrComposer> IVrComposer::default_impl = nullptr;
::ndk::ScopedAStatus IVrComposerDefault::registerObserver(const std::shared_ptr<::aidl::android::dvr::IVrComposerCallback>& /*in_callback*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IVrComposerDefault::clearObserver() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IVrComposerDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IVrComposerDefault::isRemote() {
  return false;
}
}  // namespace dvr
}  // namespace android
}  // namespace aidl
