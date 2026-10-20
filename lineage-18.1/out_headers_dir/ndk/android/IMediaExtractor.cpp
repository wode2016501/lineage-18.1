#include <android/binder_parcel_utils.h>
#include <aidl/android/BpMediaExtractor.h>
#include <aidl/android/BnMediaExtractor.h>
#include <aidl/android/IMediaExtractor.h>

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

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IMediaExtractor::descriptor, _aidl_onTransact);

BpMediaExtractor::BpMediaExtractor(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpMediaExtractor::~BpMediaExtractor() {}

// Source for BnMediaExtractor
BnMediaExtractor::BnMediaExtractor() {}
BnMediaExtractor::~BnMediaExtractor() {}
::ndk::SpAIBinder BnMediaExtractor::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IMediaExtractor
const char* IMediaExtractor::descriptor = "android.IMediaExtractor";
IMediaExtractor::IMediaExtractor() {}
IMediaExtractor::~IMediaExtractor() {}


std::shared_ptr<IMediaExtractor> IMediaExtractor::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IMediaExtractor>(interface);
  }
  return ::ndk::SharedRefBase::make<BpMediaExtractor>(binder);
}

binder_status_t IMediaExtractor::writeToParcel(AParcel* parcel, const std::shared_ptr<IMediaExtractor>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IMediaExtractor::readFromParcel(const AParcel* parcel, std::shared_ptr<IMediaExtractor>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IMediaExtractor::fromBinder(binder);
  return STATUS_OK;
}
bool IMediaExtractor::setDefaultImpl(std::shared_ptr<IMediaExtractor> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IMediaExtractor::default_impl);
  if (impl) {
    IMediaExtractor::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IMediaExtractor>& IMediaExtractor::getDefaultImpl() {
  return IMediaExtractor::default_impl;
}
std::shared_ptr<IMediaExtractor> IMediaExtractor::default_impl = nullptr;
::ndk::SpAIBinder IMediaExtractorDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IMediaExtractorDefault::isRemote() {
  return false;
}
}  // namespace android
}  // namespace aidl
