#include <android/binder_parcel_utils.h>
#include <aidl/android/media/BpCaptureStateListener.h>
#include <aidl/android/media/BnCaptureStateListener.h>
#include <aidl/android/media/ICaptureStateListener.h>

namespace aidl {
namespace android {
namespace media {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnCaptureStateListener> _aidl_impl = std::static_pointer_cast<BnCaptureStateListener>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*setCaptureState*/): {
      bool in_active;

      _aidl_ret_status = AParcel_readBool(_aidl_in, &in_active);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setCaptureState(in_active);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ICaptureStateListener::descriptor, _aidl_onTransact);

BpCaptureStateListener::BpCaptureStateListener(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpCaptureStateListener::~BpCaptureStateListener() {}

::ndk::ScopedAStatus BpCaptureStateListener::setCaptureState(bool in_active) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeBool(_aidl_in.get(), in_active);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*setCaptureState*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ICaptureStateListener::getDefaultImpl()) {
    return ICaptureStateListener::getDefaultImpl()->setCaptureState(in_active);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnCaptureStateListener
BnCaptureStateListener::BnCaptureStateListener() {}
BnCaptureStateListener::~BnCaptureStateListener() {}
::ndk::SpAIBinder BnCaptureStateListener::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ICaptureStateListener
const char* ICaptureStateListener::descriptor = "android.media.ICaptureStateListener";
ICaptureStateListener::ICaptureStateListener() {}
ICaptureStateListener::~ICaptureStateListener() {}


std::shared_ptr<ICaptureStateListener> ICaptureStateListener::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ICaptureStateListener>(interface);
  }
  return ::ndk::SharedRefBase::make<BpCaptureStateListener>(binder);
}

binder_status_t ICaptureStateListener::writeToParcel(AParcel* parcel, const std::shared_ptr<ICaptureStateListener>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ICaptureStateListener::readFromParcel(const AParcel* parcel, std::shared_ptr<ICaptureStateListener>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ICaptureStateListener::fromBinder(binder);
  return STATUS_OK;
}
bool ICaptureStateListener::setDefaultImpl(std::shared_ptr<ICaptureStateListener> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ICaptureStateListener::default_impl);
  if (impl) {
    ICaptureStateListener::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ICaptureStateListener>& ICaptureStateListener::getDefaultImpl() {
  return ICaptureStateListener::default_impl;
}
std::shared_ptr<ICaptureStateListener> ICaptureStateListener::default_impl = nullptr;
::ndk::ScopedAStatus ICaptureStateListenerDefault::setCaptureState(bool /*in_active*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ICaptureStateListenerDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ICaptureStateListenerDefault::isRemote() {
  return false;
}
}  // namespace media
}  // namespace android
}  // namespace aidl
