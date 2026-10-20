#include <android/binder_parcel_utils.h>
#include <aidl/android/tests/binder/BpBenchmark.h>
#include <aidl/android/tests/binder/BnBenchmark.h>
#include <aidl/android/tests/binder/IBenchmark.h>

namespace aidl {
namespace android {
namespace tests {
namespace binder {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnBenchmark> _aidl_impl = std::static_pointer_cast<BnBenchmark>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*sendVec*/): {
      std::vector<int8_t> in_data;
      std::vector<int8_t> _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_data);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->sendVec(in_data, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IBenchmark::descriptor, _aidl_onTransact);

BpBenchmark::BpBenchmark(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpBenchmark::~BpBenchmark() {}

::ndk::ScopedAStatus BpBenchmark::sendVec(const std::vector<int8_t>& in_data, std::vector<int8_t>* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_data);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*sendVec*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBenchmark::getDefaultImpl()) {
    return IBenchmark::getDefaultImpl()->sendVec(in_data, _aidl_return);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnBenchmark
BnBenchmark::BnBenchmark() {}
BnBenchmark::~BnBenchmark() {}
::ndk::SpAIBinder BnBenchmark::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IBenchmark
const char* IBenchmark::descriptor = "android.tests.binder.IBenchmark";
IBenchmark::IBenchmark() {}
IBenchmark::~IBenchmark() {}


std::shared_ptr<IBenchmark> IBenchmark::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IBenchmark>(interface);
  }
  return ::ndk::SharedRefBase::make<BpBenchmark>(binder);
}

binder_status_t IBenchmark::writeToParcel(AParcel* parcel, const std::shared_ptr<IBenchmark>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IBenchmark::readFromParcel(const AParcel* parcel, std::shared_ptr<IBenchmark>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IBenchmark::fromBinder(binder);
  return STATUS_OK;
}
bool IBenchmark::setDefaultImpl(std::shared_ptr<IBenchmark> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IBenchmark::default_impl);
  if (impl) {
    IBenchmark::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IBenchmark>& IBenchmark::getDefaultImpl() {
  return IBenchmark::default_impl;
}
std::shared_ptr<IBenchmark> IBenchmark::default_impl = nullptr;
::ndk::ScopedAStatus IBenchmarkDefault::sendVec(const std::vector<int8_t>& /*in_data*/, std::vector<int8_t>* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IBenchmarkDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IBenchmarkDefault::isRemote() {
  return false;
}
}  // namespace binder
}  // namespace tests
}  // namespace android
}  // namespace aidl
