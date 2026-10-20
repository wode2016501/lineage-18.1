#include <android/binder_parcel_utils.h>
#include <aidl/android/hardware/BpSensorPrivacyListener.h>
#include <aidl/android/hardware/BnSensorPrivacyListener.h>
#include <aidl/android/hardware/ISensorPrivacyListener.h>
#include <aidl/android/hardware/BpSensorPrivacyManager.h>
#include <aidl/android/hardware/BnSensorPrivacyManager.h>
#include <aidl/android/hardware/ISensorPrivacyManager.h>

namespace aidl {
namespace android {
namespace hardware {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnSensorPrivacyManager> _aidl_impl = std::static_pointer_cast<BnSensorPrivacyManager>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*addSensorPrivacyListener*/): {
      std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener> in_listener;

      _aidl_ret_status = ::aidl::android::hardware::ISensorPrivacyListener::readFromParcel(_aidl_in, &in_listener);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->addSensorPrivacyListener(in_listener);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*removeSensorPrivacyListener*/): {
      std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener> in_listener;

      _aidl_ret_status = ::aidl::android::hardware::ISensorPrivacyListener::readFromParcel(_aidl_in, &in_listener);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->removeSensorPrivacyListener(in_listener);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*isSensorPrivacyEnabled*/): {
      bool _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->isSensorPrivacyEnabled(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeBool(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*setSensorPrivacy*/): {
      bool in_enable;

      _aidl_ret_status = AParcel_readBool(_aidl_in, &in_enable);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setSensorPrivacy(in_enable);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ISensorPrivacyManager::descriptor, _aidl_onTransact);

BpSensorPrivacyManager::BpSensorPrivacyManager(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpSensorPrivacyManager::~BpSensorPrivacyManager() {}

::ndk::ScopedAStatus BpSensorPrivacyManager::addSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& in_listener) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::hardware::ISensorPrivacyListener::writeToParcel(_aidl_in.get(), in_listener);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*addSensorPrivacyListener*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ISensorPrivacyManager::getDefaultImpl()) {
    return ISensorPrivacyManager::getDefaultImpl()->addSensorPrivacyListener(in_listener);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpSensorPrivacyManager::removeSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& in_listener) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::hardware::ISensorPrivacyListener::writeToParcel(_aidl_in.get(), in_listener);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*removeSensorPrivacyListener*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ISensorPrivacyManager::getDefaultImpl()) {
    return ISensorPrivacyManager::getDefaultImpl()->removeSensorPrivacyListener(in_listener);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpSensorPrivacyManager::isSensorPrivacyEnabled(bool* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*isSensorPrivacyEnabled*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ISensorPrivacyManager::getDefaultImpl()) {
    return ISensorPrivacyManager::getDefaultImpl()->isSensorPrivacyEnabled(_aidl_return);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_ret_status = AParcel_readBool(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpSensorPrivacyManager::setSensorPrivacy(bool in_enable) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeBool(_aidl_in.get(), in_enable);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*setSensorPrivacy*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ISensorPrivacyManager::getDefaultImpl()) {
    return ISensorPrivacyManager::getDefaultImpl()->setSensorPrivacy(in_enable);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnSensorPrivacyManager
BnSensorPrivacyManager::BnSensorPrivacyManager() {}
BnSensorPrivacyManager::~BnSensorPrivacyManager() {}
::ndk::SpAIBinder BnSensorPrivacyManager::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ISensorPrivacyManager
const char* ISensorPrivacyManager::descriptor = "android.hardware.ISensorPrivacyManager";
ISensorPrivacyManager::ISensorPrivacyManager() {}
ISensorPrivacyManager::~ISensorPrivacyManager() {}


std::shared_ptr<ISensorPrivacyManager> ISensorPrivacyManager::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ISensorPrivacyManager>(interface);
  }
  return ::ndk::SharedRefBase::make<BpSensorPrivacyManager>(binder);
}

binder_status_t ISensorPrivacyManager::writeToParcel(AParcel* parcel, const std::shared_ptr<ISensorPrivacyManager>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ISensorPrivacyManager::readFromParcel(const AParcel* parcel, std::shared_ptr<ISensorPrivacyManager>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ISensorPrivacyManager::fromBinder(binder);
  return STATUS_OK;
}
bool ISensorPrivacyManager::setDefaultImpl(std::shared_ptr<ISensorPrivacyManager> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ISensorPrivacyManager::default_impl);
  if (impl) {
    ISensorPrivacyManager::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ISensorPrivacyManager>& ISensorPrivacyManager::getDefaultImpl() {
  return ISensorPrivacyManager::default_impl;
}
std::shared_ptr<ISensorPrivacyManager> ISensorPrivacyManager::default_impl = nullptr;
::ndk::ScopedAStatus ISensorPrivacyManagerDefault::addSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& /*in_listener*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ISensorPrivacyManagerDefault::removeSensorPrivacyListener(const std::shared_ptr<::aidl::android::hardware::ISensorPrivacyListener>& /*in_listener*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ISensorPrivacyManagerDefault::isSensorPrivacyEnabled(bool* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ISensorPrivacyManagerDefault::setSensorPrivacy(bool /*in_enable*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ISensorPrivacyManagerDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ISensorPrivacyManagerDefault::isRemote() {
  return false;
}
}  // namespace hardware
}  // namespace android
}  // namespace aidl
