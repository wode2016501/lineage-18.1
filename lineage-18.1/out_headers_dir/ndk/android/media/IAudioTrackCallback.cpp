#include <android/binder_parcel_utils.h>
#include <aidl/android/media/BpAudioTrackCallback.h>
#include <aidl/android/media/BnAudioTrackCallback.h>
#include <aidl/android/media/IAudioTrackCallback.h>

namespace aidl {
namespace android {
namespace media {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnAudioTrackCallback> _aidl_impl = std::static_pointer_cast<BnAudioTrackCallback>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*onCodecFormatChanged*/): {
      std::vector<int8_t> in_audioMetadata;

      _aidl_ret_status = ::ndk::AParcel_readVector(_aidl_in, &in_audioMetadata);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onCodecFormatChanged(in_audioMetadata);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(IAudioTrackCallback::descriptor, _aidl_onTransact);

BpAudioTrackCallback::BpAudioTrackCallback(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpAudioTrackCallback::~BpAudioTrackCallback() {}

::ndk::ScopedAStatus BpAudioTrackCallback::onCodecFormatChanged(const std::vector<int8_t>& in_audioMetadata) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeVector(_aidl_in.get(), in_audioMetadata);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*onCodecFormatChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && IAudioTrackCallback::getDefaultImpl()) {
    return IAudioTrackCallback::getDefaultImpl()->onCodecFormatChanged(in_audioMetadata);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnAudioTrackCallback
BnAudioTrackCallback::BnAudioTrackCallback() {}
BnAudioTrackCallback::~BnAudioTrackCallback() {}
::ndk::SpAIBinder BnAudioTrackCallback::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for IAudioTrackCallback
const char* IAudioTrackCallback::descriptor = "android.media.IAudioTrackCallback";
IAudioTrackCallback::IAudioTrackCallback() {}
IAudioTrackCallback::~IAudioTrackCallback() {}


std::shared_ptr<IAudioTrackCallback> IAudioTrackCallback::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<IAudioTrackCallback>(interface);
  }
  return ::ndk::SharedRefBase::make<BpAudioTrackCallback>(binder);
}

binder_status_t IAudioTrackCallback::writeToParcel(AParcel* parcel, const std::shared_ptr<IAudioTrackCallback>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t IAudioTrackCallback::readFromParcel(const AParcel* parcel, std::shared_ptr<IAudioTrackCallback>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = IAudioTrackCallback::fromBinder(binder);
  return STATUS_OK;
}
bool IAudioTrackCallback::setDefaultImpl(std::shared_ptr<IAudioTrackCallback> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!IAudioTrackCallback::default_impl);
  if (impl) {
    IAudioTrackCallback::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<IAudioTrackCallback>& IAudioTrackCallback::getDefaultImpl() {
  return IAudioTrackCallback::default_impl;
}
std::shared_ptr<IAudioTrackCallback> IAudioTrackCallback::default_impl = nullptr;
::ndk::ScopedAStatus IAudioTrackCallbackDefault::onCodecFormatChanged(const std::vector<int8_t>& /*in_audioMetadata*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder IAudioTrackCallbackDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool IAudioTrackCallbackDefault::isRemote() {
  return false;
}
}  // namespace media
}  // namespace android
}  // namespace aidl
