#include <android/binder_parcel_utils.h>
#include <aidl/android/BpDataSource.h>
#include <aidl/android/BnDataSource.h>
#include <aidl/android/IDataSource.h>

namespace aidl {
namespace android {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  (void)_aidl_binder;
  (void)_aidl_code;
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IDataSource::descriptor, _aidl_onTransact);

BpDataSource::BpDataSource(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpDataSource::~BpDataSource() {}

// Source for BnDataSource
BnDataSource::BnDataSource() {}
BnDataSource::~BnDataSource() {}
::ndk::SpAIBinder BnDataSource::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IDataSource
const char* IDataSource::descriptor = "android.IDataSource";
IDataSource::IDataSource() {}
IDataSource::~IDataSource() {}


std::shared_ptr<IDataSource> IDataSource::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IDataSource>(interface);
  }
  return ::ndk::SharedRefBase::make<BpDataSource>(binder);
}

binder_status_t IDataSource::writeToParcel(AParcel* parcel, const std::shared_ptr<IDataSource>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IDataSource::readFromParcel(const AParcel* parcel, std::shared_ptr<IDataSource>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IDataSource::fromBinder(binder);
  return STATUS_OK;
}
bool IDataSource::setDefaultImpl(std::shared_ptr<IDataSource> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IDataSource::default_impl);
  if (impl) {
    IDataSource::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IDataSource>& IDataSource::getDefaultImpl() {
  return IDataSource::default_impl;
}
std::shared_ptr<IDataSource> IDataSource::default_impl = nullptr;
::ndk::SpAIBinder IDataSourceDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IDataSourceDefault::isRemote() {
  return false;
}
}  // namespace android
}  // namespace aidl
