#include <android/binder_parcel_utils.h>
#include <aidl/android/hardware/BpCameraClient.h>
#include <aidl/android/hardware/BnCameraClient.h>
#include <aidl/android/hardware/ICameraClient.h>

namespace aidl {
namespace android {
namespace hardware {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  (void)_aidl_binder;
  (void)_aidl_code;
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ICameraClient::descriptor, _aidl_onTransact);

BpCameraClient::BpCameraClient(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpCameraClient::~BpCameraClient() {}

// Source for BnCameraClient
BnCameraClient::BnCameraClient() {}
BnCameraClient::~BnCameraClient() {}
::ndk::SpAIBinder BnCameraClient::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ICameraClient
const char* ICameraClient::descriptor = "android.hardware.ICameraClient";
ICameraClient::ICameraClient() {}
ICameraClient::~ICameraClient() {}


std::shared_ptr<ICameraClient> ICameraClient::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ICameraClient>(interface);
  }
  return ::ndk::SharedRefBase::make<BpCameraClient>(binder);
}

binder_status_t ICameraClient::writeToParcel(AParcel* parcel, const std::shared_ptr<ICameraClient>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ICameraClient::readFromParcel(const AParcel* parcel, std::shared_ptr<ICameraClient>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ICameraClient::fromBinder(binder);
  return STATUS_OK;
}
bool ICameraClient::setDefaultImpl(std::shared_ptr<ICameraClient> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ICameraClient::default_impl);
  if (impl) {
    ICameraClient::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ICameraClient>& ICameraClient::getDefaultImpl() {
  return ICameraClient::default_impl;
}
std::shared_ptr<ICameraClient> ICameraClient::default_impl = nullptr;
::ndk::SpAIBinder ICameraClientDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ICameraClientDefault::isRemote() {
  return false;
}
}  // namespace hardware
}  // namespace android
}  // namespace aidl
