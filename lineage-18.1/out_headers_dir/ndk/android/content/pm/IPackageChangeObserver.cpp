#include <android/binder_parcel_utils.h>
#include <aidl/android/content/pm/BpPackageChangeObserver.h>
#include <aidl/android/content/pm/BnPackageChangeObserver.h>
#include <aidl/android/content/pm/IPackageChangeObserver.h>

namespace aidl {
namespace android {
namespace content {
namespace pm {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnPackageChangeObserver> _aidl_impl = std::static_pointer_cast<BnPackageChangeObserver>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onPackageChanged*/): {
      ::aidl::android::content::pm::PackageChangeEvent in_event;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_event);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onPackageChanged(in_event);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IPackageChangeObserver::descriptor, _aidl_onTransact);

BpPackageChangeObserver::BpPackageChangeObserver(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpPackageChangeObserver::~BpPackageChangeObserver() {}

::ndk::ScopedAStatus BpPackageChangeObserver::onPackageChanged(const ::aidl::android::content::pm::PackageChangeEvent& in_event) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_event);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onPackageChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IPackageChangeObserver::getDefaultImpl()) {
    return IPackageChangeObserver::getDefaultImpl()->onPackageChanged(in_event);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnPackageChangeObserver
BnPackageChangeObserver::BnPackageChangeObserver() {}
BnPackageChangeObserver::~BnPackageChangeObserver() {}
::ndk::SpAIBinder BnPackageChangeObserver::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IPackageChangeObserver
const char* IPackageChangeObserver::descriptor = "android.content.pm.IPackageChangeObserver";
IPackageChangeObserver::IPackageChangeObserver() {}
IPackageChangeObserver::~IPackageChangeObserver() {}


std::shared_ptr<IPackageChangeObserver> IPackageChangeObserver::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IPackageChangeObserver>(interface);
  }
  return ::ndk::SharedRefBase::make<BpPackageChangeObserver>(binder);
}

binder_status_t IPackageChangeObserver::writeToParcel(AParcel* parcel, const std::shared_ptr<IPackageChangeObserver>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IPackageChangeObserver::readFromParcel(const AParcel* parcel, std::shared_ptr<IPackageChangeObserver>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IPackageChangeObserver::fromBinder(binder);
  return STATUS_OK;
}
bool IPackageChangeObserver::setDefaultImpl(std::shared_ptr<IPackageChangeObserver> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IPackageChangeObserver::default_impl);
  if (impl) {
    IPackageChangeObserver::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IPackageChangeObserver>& IPackageChangeObserver::getDefaultImpl() {
  return IPackageChangeObserver::default_impl;
}
std::shared_ptr<IPackageChangeObserver> IPackageChangeObserver::default_impl = nullptr;
::ndk::ScopedAStatus IPackageChangeObserverDefault::onPackageChanged(const ::aidl::android::content::pm::PackageChangeEvent& /*in_event*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IPackageChangeObserverDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IPackageChangeObserverDefault::isRemote() {
  return false;
}
}  // namespace pm
}  // namespace content
}  // namespace android
}  // namespace aidl
