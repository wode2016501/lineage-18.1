#include <android/binder_parcel_utils.h>
#include <aidl/android/hardware/BpSensorPrivacyListener.h>
#include <aidl/android/hardware/BnSensorPrivacyListener.h>
#include <aidl/android/hardware/ISensorPrivacyListener.h>

namespace aidl {
namespace android {
namespace hardware {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnSensorPrivacyListener> _aidl_impl = std::static_pointer_cast<BnSensorPrivacyListener>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onSensorPrivacyChanged*/): {
      bool in_enabled;

      _aidl_ret_status = AParcel_readBool(_aidl_in, &in_enabled);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onSensorPrivacyChanged(in_enabled);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ISensorPrivacyListener::descriptor, _aidl_onTransact);

BpSensorPrivacyListener::BpSensorPrivacyListener(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpSensorPrivacyListener::~BpSensorPrivacyListener() {}

::ndk::ScopedAStatus BpSensorPrivacyListener::onSensorPrivacyChanged(bool in_enabled) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeBool(_aidl_in.get(), in_enabled);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onSensorPrivacyChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ISensorPrivacyListener::getDefaultImpl()) {
    return ISensorPrivacyListener::getDefaultImpl()->onSensorPrivacyChanged(in_enabled);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnSensorPrivacyListener
BnSensorPrivacyListener::BnSensorPrivacyListener() {}
BnSensorPrivacyListener::~BnSensorPrivacyListener() {}
::ndk::SpAIBinder BnSensorPrivacyListener::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ISensorPrivacyListener
const char* ISensorPrivacyListener::descriptor = "android.hardware.ISensorPrivacyListener";
ISensorPrivacyListener::ISensorPrivacyListener() {}
ISensorPrivacyListener::~ISensorPrivacyListener() {}


std::shared_ptr<ISensorPrivacyListener> ISensorPrivacyListener::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ISensorPrivacyListener>(interface);
  }
  return ::ndk::SharedRefBase::make<BpSensorPrivacyListener>(binder);
}

binder_status_t ISensorPrivacyListener::writeToParcel(AParcel* parcel, const std::shared_ptr<ISensorPrivacyListener>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ISensorPrivacyListener::readFromParcel(const AParcel* parcel, std::shared_ptr<ISensorPrivacyListener>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ISensorPrivacyListener::fromBinder(binder);
  return STATUS_OK;
}
bool ISensorPrivacyListener::setDefaultImpl(std::shared_ptr<ISensorPrivacyListener> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ISensorPrivacyListener::default_impl);
  if (impl) {
    ISensorPrivacyListener::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ISensorPrivacyListener>& ISensorPrivacyListener::getDefaultImpl() {
  return ISensorPrivacyListener::default_impl;
}
std::shared_ptr<ISensorPrivacyListener> ISensorPrivacyListener::default_impl = nullptr;
::ndk::ScopedAStatus ISensorPrivacyListenerDefault::onSensorPrivacyChanged(bool /*in_enabled*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ISensorPrivacyListenerDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ISensorPrivacyListenerDefault::isRemote() {
  return false;
}
}  // namespace hardware
}  // namespace android
}  // namespace aidl
