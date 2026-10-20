#include <android/binder_parcel_utils.h>
#include <aidl/android/dvr/BpVirtualTouchpadService.h>
#include <aidl/android/dvr/BnVirtualTouchpadService.h>
#include <aidl/android/dvr/IVirtualTouchpadService.h>

namespace aidl {
namespace android {
namespace dvr {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnVirtualTouchpadService> _aidl_impl = std::static_pointer_cast<BnVirtualTouchpadService>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*attach*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->attach();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*detach*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->detach();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*touch*/): {
      int32_t in_touchpad;
      float in_x;
      float in_y;
      float in_pressure;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_touchpad);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readFloat(_aidl_in, &in_x);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readFloat(_aidl_in, &in_y);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readFloat(_aidl_in, &in_pressure);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->touch(in_touchpad, in_x, in_y, in_pressure);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*buttonState*/): {
      int32_t in_touchpad;
      int32_t in_buttons;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_touchpad);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_buttons);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->buttonState(in_touchpad, in_buttons);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 4 /*scroll*/): {
      int32_t in_touchpad;
      float in_x;
      float in_y;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_touchpad);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readFloat(_aidl_in, &in_x);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readFloat(_aidl_in, &in_y);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->scroll(in_touchpad, in_x, in_y);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IVirtualTouchpadService::descriptor, _aidl_onTransact);

BpVirtualTouchpadService::BpVirtualTouchpadService(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpVirtualTouchpadService::~BpVirtualTouchpadService() {}

::ndk::ScopedAStatus BpVirtualTouchpadService::attach() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*attach*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IVirtualTouchpadService::getDefaultImpl()) {
    return IVirtualTouchpadService::getDefaultImpl()->attach();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpVirtualTouchpadService::detach() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*detach*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IVirtualTouchpadService::getDefaultImpl()) {
    return IVirtualTouchpadService::getDefaultImpl()->detach();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpVirtualTouchpadService::touch(int32_t in_touchpad, float in_x, float in_y, float in_pressure) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_touchpad);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeFloat(_aidl_in.get(), in_x);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeFloat(_aidl_in.get(), in_y);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeFloat(_aidl_in.get(), in_pressure);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*touch*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IVirtualTouchpadService::getDefaultImpl()) {
    return IVirtualTouchpadService::getDefaultImpl()->touch(in_touchpad, in_x, in_y, in_pressure);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpVirtualTouchpadService::buttonState(int32_t in_touchpad, int32_t in_buttons) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_touchpad);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_buttons);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*buttonState*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IVirtualTouchpadService::getDefaultImpl()) {
    return IVirtualTouchpadService::getDefaultImpl()->buttonState(in_touchpad, in_buttons);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpVirtualTouchpadService::scroll(int32_t in_touchpad, float in_x, float in_y) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_touchpad);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeFloat(_aidl_in.get(), in_x);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeFloat(_aidl_in.get(), in_y);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 4 /*scroll*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IVirtualTouchpadService::getDefaultImpl()) {
    return IVirtualTouchpadService::getDefaultImpl()->scroll(in_touchpad, in_x, in_y);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnVirtualTouchpadService
BnVirtualTouchpadService::BnVirtualTouchpadService() {}
BnVirtualTouchpadService::~BnVirtualTouchpadService() {}
::ndk::SpAIBinder BnVirtualTouchpadService::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IVirtualTouchpadService
const char* IVirtualTouchpadService::descriptor = "android.dvr.IVirtualTouchpadService";
IVirtualTouchpadService::IVirtualTouchpadService() {}
IVirtualTouchpadService::~IVirtualTouchpadService() {}

const char* IVirtualTouchpadService::SERVICE_NAME = "virtual_touchpad";

std::shared_ptr<IVirtualTouchpadService> IVirtualTouchpadService::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IVirtualTouchpadService>(interface);
  }
  return ::ndk::SharedRefBase::make<BpVirtualTouchpadService>(binder);
}

binder_status_t IVirtualTouchpadService::writeToParcel(AParcel* parcel, const std::shared_ptr<IVirtualTouchpadService>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IVirtualTouchpadService::readFromParcel(const AParcel* parcel, std::shared_ptr<IVirtualTouchpadService>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IVirtualTouchpadService::fromBinder(binder);
  return STATUS_OK;
}
bool IVirtualTouchpadService::setDefaultImpl(std::shared_ptr<IVirtualTouchpadService> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IVirtualTouchpadService::default_impl);
  if (impl) {
    IVirtualTouchpadService::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IVirtualTouchpadService>& IVirtualTouchpadService::getDefaultImpl() {
  return IVirtualTouchpadService::default_impl;
}
std::shared_ptr<IVirtualTouchpadService> IVirtualTouchpadService::default_impl = nullptr;
::ndk::ScopedAStatus IVirtualTouchpadServiceDefault::attach() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IVirtualTouchpadServiceDefault::detach() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IVirtualTouchpadServiceDefault::touch(int32_t /*in_touchpad*/, float /*in_x*/, float /*in_y*/, float /*in_pressure*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IVirtualTouchpadServiceDefault::buttonState(int32_t /*in_touchpad*/, int32_t /*in_buttons*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IVirtualTouchpadServiceDefault::scroll(int32_t /*in_touchpad*/, float /*in_x*/, float /*in_y*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IVirtualTouchpadServiceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IVirtualTouchpadServiceDefault::isRemote() {
  return false;
}
}  // namespace dvr
}  // namespace android
}  // namespace aidl
