#include <android/binder_parcel_utils.h>
#include <aidl/android/hardware/tests/extension/vibrator/BpCustomVibrator.h>
#include <aidl/android/hardware/tests/extension/vibrator/BnCustomVibrator.h>
#include <aidl/android/hardware/tests/extension/vibrator/ICustomVibrator.h>
#include <aidl/android/hardware/vibrator/BpVibratorCallback.h>
#include <aidl/android/hardware/vibrator/BnVibratorCallback.h>
#include <aidl/android/hardware/vibrator/IVibratorCallback.h>

namespace aidl {
namespace android {
namespace hardware {
namespace tests {
namespace extension {
namespace vibrator {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnCustomVibrator> _aidl_impl = std::static_pointer_cast<BnCustomVibrator>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*getVendorCapabilities*/): {
      int32_t _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getVendorCapabilities(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeInt32(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*setDirectionality*/): {
      ::aidl::android::hardware::tests::extension::vibrator::Directionality in_directionality;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_directionality));
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->setDirectionality(in_directionality);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*perform*/): {
      ::aidl::android::hardware::tests::extension::vibrator::VendorEffect in_effect;
      std::shared_ptr<::aidl::android::hardware::vibrator::IVibratorCallback> in_callback;
      int32_t _aidl_return;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_effect));
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::aidl::android::hardware::vibrator::IVibratorCallback::readFromParcel(_aidl_in, &in_callback);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->perform(in_effect, in_callback, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = AParcel_writeInt32(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ICustomVibrator::descriptor, _aidl_onTransact);

BpCustomVibrator::BpCustomVibrator(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpCustomVibrator::~BpCustomVibrator() {}

::ndk::ScopedAStatus BpCustomVibrator::getVendorCapabilities(int32_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*getVendorCapabilities*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ICustomVibrator::getDefaultImpl()) {
    return ICustomVibrator::getDefaultImpl()->getVendorCapabilities(_aidl_return);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_ret_status = AParcel_readInt32(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpCustomVibrator::setDirectionality(::aidl::android::hardware::tests::extension::vibrator::Directionality in_directionality) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_directionality));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*setDirectionality*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ICustomVibrator::getDefaultImpl()) {
    return ICustomVibrator::getDefaultImpl()->setDirectionality(in_directionality);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpCustomVibrator::perform(::aidl::android::hardware::tests::extension::vibrator::VendorEffect in_effect, const std::shared_ptr<::aidl::android::hardware::vibrator::IVibratorCallback>& in_callback, int32_t* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_effect));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::hardware::vibrator::IVibratorCallback::writeToParcel(_aidl_in.get(), in_callback);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*perform*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ICustomVibrator::getDefaultImpl()) {
    return ICustomVibrator::getDefaultImpl()->perform(in_effect, in_callback, _aidl_return);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_ret_status = AParcel_readInt32(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnCustomVibrator
BnCustomVibrator::BnCustomVibrator() {}
BnCustomVibrator::~BnCustomVibrator() {}
::ndk::SpAIBinder BnCustomVibrator::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markVintfStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ICustomVibrator
const char* ICustomVibrator::descriptor = "android.hardware.tests.extension.vibrator.ICustomVibrator";
ICustomVibrator::ICustomVibrator() {}
ICustomVibrator::~ICustomVibrator() {}


std::shared_ptr<ICustomVibrator> ICustomVibrator::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ICustomVibrator>(interface);
  }
  return ::ndk::SharedRefBase::make<BpCustomVibrator>(binder);
}

binder_status_t ICustomVibrator::writeToParcel(AParcel* parcel, const std::shared_ptr<ICustomVibrator>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ICustomVibrator::readFromParcel(const AParcel* parcel, std::shared_ptr<ICustomVibrator>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ICustomVibrator::fromBinder(binder);
  return STATUS_OK;
}
bool ICustomVibrator::setDefaultImpl(std::shared_ptr<ICustomVibrator> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ICustomVibrator::default_impl);
  if (impl) {
    ICustomVibrator::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ICustomVibrator>& ICustomVibrator::getDefaultImpl() {
  return ICustomVibrator::default_impl;
}
std::shared_ptr<ICustomVibrator> ICustomVibrator::default_impl = nullptr;
::ndk::ScopedAStatus ICustomVibratorDefault::getVendorCapabilities(int32_t* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ICustomVibratorDefault::setDirectionality(::aidl::android::hardware::tests::extension::vibrator::Directionality /*in_directionality*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ICustomVibratorDefault::perform(::aidl::android::hardware::tests::extension::vibrator::VendorEffect /*in_effect*/, const std::shared_ptr<::aidl::android::hardware::vibrator::IVibratorCallback>& /*in_callback*/, int32_t* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ICustomVibratorDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ICustomVibratorDefault::isRemote() {
  return false;
}
}  // namespace vibrator
}  // namespace extension
}  // namespace tests
}  // namespace hardware
}  // namespace android
}  // namespace aidl
