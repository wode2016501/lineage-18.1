#include <android/binder_parcel_utils.h>
#include <aidl/android/hardware/BpCameraServiceProxy.h>
#include <aidl/android/hardware/BnCameraServiceProxy.h>
#include <aidl/android/hardware/ICameraServiceProxy.h>

namespace aidl {
namespace android {
namespace hardware {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnCameraServiceProxy> _aidl_impl = std::static_pointer_cast<BnCameraServiceProxy>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*pingForUserUpdate*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->pingForUserUpdate();
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*notifyCameraState*/): {
      std::string in_cameraId;
      int32_t in_facing;
      int32_t in_newCameraState;
      std::string in_clientName;
      int32_t in_apiLevel;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_cameraId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_facing);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_newCameraState);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_clientName);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_apiLevel);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->notifyCameraState(in_cameraId, in_facing, in_newCameraState, in_clientName, in_apiLevel);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ICameraServiceProxy::descriptor, _aidl_onTransact);

BpCameraServiceProxy::BpCameraServiceProxy(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpCameraServiceProxy::~BpCameraServiceProxy() {}

::ndk::ScopedAStatus BpCameraServiceProxy::pingForUserUpdate() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*pingForUserUpdate*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ICameraServiceProxy::getDefaultImpl()) {
    return ICameraServiceProxy::getDefaultImpl()->pingForUserUpdate();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpCameraServiceProxy::notifyCameraState(const std::string& in_cameraId, int32_t in_facing, int32_t in_newCameraState, const std::string& in_clientName, int32_t in_apiLevel) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_cameraId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_facing);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_newCameraState);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_clientName);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_apiLevel);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*notifyCameraState*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ICameraServiceProxy::getDefaultImpl()) {
    return ICameraServiceProxy::getDefaultImpl()->notifyCameraState(in_cameraId, in_facing, in_newCameraState, in_clientName, in_apiLevel);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnCameraServiceProxy
BnCameraServiceProxy::BnCameraServiceProxy() {}
BnCameraServiceProxy::~BnCameraServiceProxy() {}
::ndk::SpAIBinder BnCameraServiceProxy::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ICameraServiceProxy
const char* ICameraServiceProxy::descriptor = "android.hardware.ICameraServiceProxy";
ICameraServiceProxy::ICameraServiceProxy() {}
ICameraServiceProxy::~ICameraServiceProxy() {}


std::shared_ptr<ICameraServiceProxy> ICameraServiceProxy::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ICameraServiceProxy>(interface);
  }
  return ::ndk::SharedRefBase::make<BpCameraServiceProxy>(binder);
}

binder_status_t ICameraServiceProxy::writeToParcel(AParcel* parcel, const std::shared_ptr<ICameraServiceProxy>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ICameraServiceProxy::readFromParcel(const AParcel* parcel, std::shared_ptr<ICameraServiceProxy>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ICameraServiceProxy::fromBinder(binder);
  return STATUS_OK;
}
bool ICameraServiceProxy::setDefaultImpl(std::shared_ptr<ICameraServiceProxy> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ICameraServiceProxy::default_impl);
  if (impl) {
    ICameraServiceProxy::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ICameraServiceProxy>& ICameraServiceProxy::getDefaultImpl() {
  return ICameraServiceProxy::default_impl;
}
std::shared_ptr<ICameraServiceProxy> ICameraServiceProxy::default_impl = nullptr;
::ndk::ScopedAStatus ICameraServiceProxyDefault::pingForUserUpdate() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ICameraServiceProxyDefault::notifyCameraState(const std::string& /*in_cameraId*/, int32_t /*in_facing*/, int32_t /*in_newCameraState*/, const std::string& /*in_clientName*/, int32_t /*in_apiLevel*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ICameraServiceProxyDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ICameraServiceProxyDefault::isRemote() {
  return false;
}
}  // namespace hardware
}  // namespace android
}  // namespace aidl
