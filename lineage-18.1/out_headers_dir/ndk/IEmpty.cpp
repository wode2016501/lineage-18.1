#include <android/binder_parcel_utils.h>
#include <aidl/BpEmpty.h>
#include <aidl/BnEmpty.h>
#include <aidl/IEmpty.h>

namespace aidl {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  (void)_aidl_binder;
  (void)_aidl_code;
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IEmpty::descriptor, _aidl_onTransact);

BpEmpty::BpEmpty(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpEmpty::~BpEmpty() {}

// Source for BnEmpty
BnEmpty::BnEmpty() {}
BnEmpty::~BnEmpty() {}
::ndk::SpAIBinder BnEmpty::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IEmpty
const char* IEmpty::descriptor = "IEmpty";
IEmpty::IEmpty() {}
IEmpty::~IEmpty() {}


std::shared_ptr<IEmpty> IEmpty::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IEmpty>(interface);
  }
  return ::ndk::SharedRefBase::make<BpEmpty>(binder);
}

binder_status_t IEmpty::writeToParcel(AParcel* parcel, const std::shared_ptr<IEmpty>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IEmpty::readFromParcel(const AParcel* parcel, std::shared_ptr<IEmpty>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IEmpty::fromBinder(binder);
  return STATUS_OK;
}
bool IEmpty::setDefaultImpl(std::shared_ptr<IEmpty> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IEmpty::default_impl);
  if (impl) {
    IEmpty::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IEmpty>& IEmpty::getDefaultImpl() {
  return IEmpty::default_impl;
}
std::shared_ptr<IEmpty> IEmpty::default_impl = nullptr;
::ndk::SpAIBinder IEmptyDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IEmptyDefault::isRemote() {
  return false;
}
}  // namespace aidl
