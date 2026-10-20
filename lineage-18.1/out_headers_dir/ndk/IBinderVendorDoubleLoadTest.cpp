#include <android/binder_parcel_utils.h>
#include <aidl/BpBinderVendorDoubleLoadTest.h>
#include <aidl/BnBinderVendorDoubleLoadTest.h>
#include <aidl/IBinderVendorDoubleLoadTest.h>

namespace aidl {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnBinderVendorDoubleLoadTest> _aidl_impl = std::static_pointer_cast<BnBinderVendorDoubleLoadTest>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*RepeatString*/): {
      std::string in_toRepeat;
      std::string _aidl_return;

      _aidl_ret_status = ::ndk::AParcel_readString(_aidl_in, &in_toRepeat);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->RepeatString(in_toRepeat, &_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IBinderVendorDoubleLoadTest::descriptor, _aidl_onTransact);

BpBinderVendorDoubleLoadTest::BpBinderVendorDoubleLoadTest(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpBinderVendorDoubleLoadTest::~BpBinderVendorDoubleLoadTest() {}

::ndk::ScopedAStatus BpBinderVendorDoubleLoadTest::RepeatString(const std::string& in_toRepeat, std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_in.get(), in_toRepeat);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*RepeatString*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBinderVendorDoubleLoadTest::getDefaultImpl()) {
    return IBinderVendorDoubleLoadTest::getDefaultImpl()->RepeatString(in_toRepeat, _aidl_return);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_ret_status = ::ndk::AParcel_readString(_aidl_out.get(), _aidl_return);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnBinderVendorDoubleLoadTest
BnBinderVendorDoubleLoadTest::BnBinderVendorDoubleLoadTest() {}
BnBinderVendorDoubleLoadTest::~BnBinderVendorDoubleLoadTest() {}
::ndk::SpAIBinder BnBinderVendorDoubleLoadTest::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IBinderVendorDoubleLoadTest
const char* IBinderVendorDoubleLoadTest::descriptor = "IBinderVendorDoubleLoadTest";
IBinderVendorDoubleLoadTest::IBinderVendorDoubleLoadTest() {}
IBinderVendorDoubleLoadTest::~IBinderVendorDoubleLoadTest() {}


std::shared_ptr<IBinderVendorDoubleLoadTest> IBinderVendorDoubleLoadTest::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IBinderVendorDoubleLoadTest>(interface);
  }
  return ::ndk::SharedRefBase::make<BpBinderVendorDoubleLoadTest>(binder);
}

binder_status_t IBinderVendorDoubleLoadTest::writeToParcel(AParcel* parcel, const std::shared_ptr<IBinderVendorDoubleLoadTest>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IBinderVendorDoubleLoadTest::readFromParcel(const AParcel* parcel, std::shared_ptr<IBinderVendorDoubleLoadTest>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IBinderVendorDoubleLoadTest::fromBinder(binder);
  return STATUS_OK;
}
bool IBinderVendorDoubleLoadTest::setDefaultImpl(std::shared_ptr<IBinderVendorDoubleLoadTest> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IBinderVendorDoubleLoadTest::default_impl);
  if (impl) {
    IBinderVendorDoubleLoadTest::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IBinderVendorDoubleLoadTest>& IBinderVendorDoubleLoadTest::getDefaultImpl() {
  return IBinderVendorDoubleLoadTest::default_impl;
}
std::shared_ptr<IBinderVendorDoubleLoadTest> IBinderVendorDoubleLoadTest::default_impl = nullptr;
::ndk::ScopedAStatus IBinderVendorDoubleLoadTestDefault::RepeatString(const std::string& /*in_toRepeat*/, std::string* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IBinderVendorDoubleLoadTestDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IBinderVendorDoubleLoadTestDefault::isRemote() {
  return false;
}
}  // namespace aidl
