#include <android/binder_parcel_utils.h>
#include <aidl/BpBinderNdkUnitTest.h>
#include <aidl/BnBinderNdkUnitTest.h>
#include <aidl/IBinderNdkUnitTest.h>
#include <aidl/android/os/BpEmpty.h>
#include <aidl/android/os/BnEmpty.h>
#include <aidl/android/os/IEmpty.h>

namespace aidl {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnBinderNdkUnitTest> _aidl_impl = std::static_pointer_cast<BnBinderNdkUnitTest>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*takeInterface*/): {
      std::shared_ptr<::aidl::android::os::IEmpty> in_test;

      _aidl_ret_status = ::aidl::android::os::IEmpty::readFromParcel(_aidl_in, &in_test);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->takeInterface(in_test);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*forceFlushCommands*/): {

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->forceFlushCommands();
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IBinderNdkUnitTest::descriptor, _aidl_onTransact);

BpBinderNdkUnitTest::BpBinderNdkUnitTest(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpBinderNdkUnitTest::~BpBinderNdkUnitTest() {}

::ndk::ScopedAStatus BpBinderNdkUnitTest::takeInterface(const std::shared_ptr<::aidl::android::os::IEmpty>& in_test) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::aidl::android::os::IEmpty::writeToParcel(_aidl_in.get(), in_test);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*takeInterface*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBinderNdkUnitTest::getDefaultImpl()) {
    return IBinderNdkUnitTest::getDefaultImpl()->takeInterface(in_test);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpBinderNdkUnitTest::forceFlushCommands() {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*forceFlushCommands*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IBinderNdkUnitTest::getDefaultImpl()) {
    return IBinderNdkUnitTest::getDefaultImpl()->forceFlushCommands();
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_readStatusHeader(_aidl_out.get(), _aidl_status.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  if (!AStatus_isOk(_aidl_status.get())) return _aidl_status;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnBinderNdkUnitTest
BnBinderNdkUnitTest::BnBinderNdkUnitTest() {}
BnBinderNdkUnitTest::~BnBinderNdkUnitTest() {}
::ndk::SpAIBinder BnBinderNdkUnitTest::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IBinderNdkUnitTest
const char* IBinderNdkUnitTest::descriptor = "IBinderNdkUnitTest";
IBinderNdkUnitTest::IBinderNdkUnitTest() {}
IBinderNdkUnitTest::~IBinderNdkUnitTest() {}


std::shared_ptr<IBinderNdkUnitTest> IBinderNdkUnitTest::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IBinderNdkUnitTest>(interface);
  }
  return ::ndk::SharedRefBase::make<BpBinderNdkUnitTest>(binder);
}

binder_status_t IBinderNdkUnitTest::writeToParcel(AParcel* parcel, const std::shared_ptr<IBinderNdkUnitTest>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IBinderNdkUnitTest::readFromParcel(const AParcel* parcel, std::shared_ptr<IBinderNdkUnitTest>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IBinderNdkUnitTest::fromBinder(binder);
  return STATUS_OK;
}
bool IBinderNdkUnitTest::setDefaultImpl(std::shared_ptr<IBinderNdkUnitTest> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IBinderNdkUnitTest::default_impl);
  if (impl) {
    IBinderNdkUnitTest::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IBinderNdkUnitTest>& IBinderNdkUnitTest::getDefaultImpl() {
  return IBinderNdkUnitTest::default_impl;
}
std::shared_ptr<IBinderNdkUnitTest> IBinderNdkUnitTest::default_impl = nullptr;
::ndk::ScopedAStatus IBinderNdkUnitTestDefault::takeInterface(const std::shared_ptr<::aidl::android::os::IEmpty>& /*in_test*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus IBinderNdkUnitTestDefault::forceFlushCommands() {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IBinderNdkUnitTestDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IBinderNdkUnitTestDefault::isRemote() {
  return false;
}
}  // namespace aidl
