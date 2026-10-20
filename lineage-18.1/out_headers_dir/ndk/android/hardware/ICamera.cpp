#include <android/binder_parcel_utils.h>
#include <aidl/android/hardware/BpCamera.h>
#include <aidl/android/hardware/BnCamera.h>
#include <aidl/android/hardware/ICamera.h>

namespace aidl {
namespace android {
namespace hardware {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnCamera> _aidl_impl = std::static_pointer_cast<BnCamera>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*disconnect*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->disconnect();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ICamera::descriptor, _aidl_onTransact);

BpCamera::BpCamera(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpCamera::~BpCamera() {}

::ndk::ScopedAStatus BpCamera::disconnect() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*disconnect*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ICamera::getDefaultImpl()) {
    return ICamera::getDefaultImpl()->disconnect();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnCamera
BnCamera::BnCamera() {}
BnCamera::~BnCamera() {}
::ndk::SpAIBinder BnCamera::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ICamera
const char* ICamera::descriptor = "android.hardware.ICamera";
ICamera::ICamera() {}
ICamera::~ICamera() {}


std::shared_ptr<ICamera> ICamera::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ICamera>(interface);
  }
  return ::ndk::SharedRefBase::make<BpCamera>(binder);
}

binder_status_t ICamera::writeToParcel(AParcel* parcel, const std::shared_ptr<ICamera>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ICamera::readFromParcel(const AParcel* parcel, std::shared_ptr<ICamera>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ICamera::fromBinder(binder);
  return STATUS_OK;
}
bool ICamera::setDefaultImpl(std::shared_ptr<ICamera> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ICamera::default_impl);
  if (impl) {
    ICamera::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ICamera>& ICamera::getDefaultImpl() {
  return ICamera::default_impl;
}
std::shared_ptr<ICamera> ICamera::default_impl = nullptr;
::ndk::ScopedAStatus ICameraDefault::disconnect() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ICameraDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ICameraDefault::isRemote() {
  return false;
}
}  // namespace hardware
}  // namespace android
}  // namespace aidl
