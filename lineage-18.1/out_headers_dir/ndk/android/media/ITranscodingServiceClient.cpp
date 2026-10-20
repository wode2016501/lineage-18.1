#include <android/binder_parcel_utils.h>
#include <aidl/android/media/BpTranscodingServiceClient.h>
#include <aidl/android/media/BnTranscodingServiceClient.h>
#include <aidl/android/media/ITranscodingServiceClient.h>

namespace aidl {
namespace android {
namespace media {
static binder_status_t _aidl_onTransact(AIBinder* _aidl_binder, transaction_code_t _aidl_code, const AParcel* _aidl_in, AParcel* _aidl_out) {
  (void)_aidl_in;
  (void)_aidl_out;
  binder_status_t _aidl_ret_status = STATUS_UNKNOWN_TRANSACTION;
  std::shared_ptr<BnTranscodingServiceClient> _aidl_impl = std::static_pointer_cast<BnTranscodingServiceClient>(::ndk::ICInterface::asInterface(_aidl_binder));
  switch (_aidl_code) {
    case (FIRST_CALL_TRANSACTION + 0 /*getName*/): {
      std::string _aidl_return;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->getName(&_aidl_return);
      _aidl_ret_status = AParcel_writeStatusHeader(_aidl_out, _aidl_status.get());
      if (_aidl_ret_status != STATUS_OK) break;

      if (!AStatus_isOk(_aidl_status.get())) break;

      _aidl_ret_status = ::ndk::AParcel_writeString(_aidl_out, _aidl_return);
      if (_aidl_ret_status != STATUS_OK) break;

      break;
    }
    case (FIRST_CALL_TRANSACTION + 1 /*onTranscodingFinished*/): {
      int32_t in_jobId;
      ::aidl::android::media::TranscodingResultParcel in_result;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_jobId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = ::ndk::AParcel_readParcelable(_aidl_in, &in_result);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onTranscodingFinished(in_jobId, in_result);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 2 /*onTranscodingFailed*/): {
      int32_t in_jobId;
      ::aidl::android::media::TranscodingErrorCode in_errorCode;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_jobId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, reinterpret_cast<int32_t*>(&in_errorCode));
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onTranscodingFailed(in_jobId, in_errorCode);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 3 /*onAwaitNumberOfJobsChanged*/): {
      int32_t in_jobId;
      int32_t in_oldAwaitNumber;
      int32_t in_newAwaitNumber;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_jobId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_oldAwaitNumber);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_newAwaitNumber);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onAwaitNumberOfJobsChanged(in_jobId, in_oldAwaitNumber, in_newAwaitNumber);
      _aidl_ret_status = STATUS_OK;
      break;
    }
    case (FIRST_CALL_TRANSACTION + 4 /*onProgressUpdate*/): {
      int32_t in_jobId;
      int32_t in_progress;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_jobId);
      if (_aidl_ret_status != STATUS_OK) break;

      _aidl_ret_status = AParcel_readInt32(_aidl_in, &in_progress);
      if (_aidl_ret_status != STATUS_OK) break;

      ::ndk::ScopedAStatus _aidl_status = _aidl_impl->onProgressUpdate(in_jobId, in_progress);
      _aidl_ret_status = STATUS_OK;
      break;
    }
  }
  return _aidl_ret_status;
}

static AIBinder_Class* _g_aidl_clazz = ::ndk::ICInterface::defineClass(ITranscodingServiceClient::descriptor, _aidl_onTransact);

BpTranscodingServiceClient::BpTranscodingServiceClient(const ::ndk::SpAIBinder& binder) : BpCInterface(binder) {}
BpTranscodingServiceClient::~BpTranscodingServiceClient() {}

::ndk::ScopedAStatus BpTranscodingServiceClient::getName(std::string* _aidl_return) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 0 /*getName*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    0
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingServiceClient::getDefaultImpl()) {
    return ITranscodingServiceClient::getDefaultImpl()->getName(_aidl_return);
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
::ndk::ScopedAStatus BpTranscodingServiceClient::onTranscodingFinished(int32_t in_jobId, const ::aidl::android::media::TranscodingResultParcel& in_result) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_jobId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = ::ndk::AParcel_writeParcelable(_aidl_in.get(), in_result);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 1 /*onTranscodingFinished*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingServiceClient::getDefaultImpl()) {
    return ITranscodingServiceClient::getDefaultImpl()->onTranscodingFinished(in_jobId, in_result);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingServiceClient::onTranscodingFailed(int32_t in_jobId, ::aidl::android::media::TranscodingErrorCode in_errorCode) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_jobId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), static_cast<int32_t>(in_errorCode));
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 2 /*onTranscodingFailed*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingServiceClient::getDefaultImpl()) {
    return ITranscodingServiceClient::getDefaultImpl()->onTranscodingFailed(in_jobId, in_errorCode);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingServiceClient::onAwaitNumberOfJobsChanged(int32_t in_jobId, int32_t in_oldAwaitNumber, int32_t in_newAwaitNumber) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_jobId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_oldAwaitNumber);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_newAwaitNumber);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 3 /*onAwaitNumberOfJobsChanged*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingServiceClient::getDefaultImpl()) {
    return ITranscodingServiceClient::getDefaultImpl()->onAwaitNumberOfJobsChanged(in_jobId, in_oldAwaitNumber, in_newAwaitNumber);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
::ndk::ScopedAStatus BpTranscodingServiceClient::onProgressUpdate(int32_t in_jobId, int32_t in_progress) {
  binder_status_t _aidl_ret_status = STATUS_OK;
  ::ndk::ScopedAStatus _aidl_status;
  ::ndk::ScopedAParcel _aidl_in;
  ::ndk::ScopedAParcel _aidl_out;

  _aidl_ret_status = AIBinder_prepareTransaction(asBinder().get(), _aidl_in.getR());
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_jobId);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AParcel_writeInt32(_aidl_in.get(), in_progress);
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_ret_status = AIBinder_transact(
    asBinder().get(),
    (FIRST_CALL_TRANSACTION + 4 /*onProgressUpdate*/),
    _aidl_in.getR(),
    _aidl_out.getR(),
    FLAG_ONEWAY
    #ifdef BINDER_STABILITY_SUPPORT
    | FLAG_PRIVATE_LOCAL
    #endif  // BINDER_STABILITY_SUPPORT
    );
  if (_aidl_ret_status == STATUS_UNKNOWN_TRANSACTION && ITranscodingServiceClient::getDefaultImpl()) {
    return ITranscodingServiceClient::getDefaultImpl()->onProgressUpdate(in_jobId, in_progress);
  }
  if (_aidl_ret_status != STATUS_OK) goto _aidl_error;

  _aidl_error:
  _aidl_status.set(AStatus_fromStatus(_aidl_ret_status));
  return _aidl_status;
}
// Source for BnTranscodingServiceClient
BnTranscodingServiceClient::BnTranscodingServiceClient() {}
BnTranscodingServiceClient::~BnTranscodingServiceClient() {}
::ndk::SpAIBinder BnTranscodingServiceClient::createBinder() {
  AIBinder* binder = AIBinder_new(_g_aidl_clazz, static_cast<void*>(this));
  #ifdef BINDER_STABILITY_SUPPORT
  AIBinder_markCompilationUnitStability(binder);
  #endif  // BINDER_STABILITY_SUPPORT
  return ::ndk::SpAIBinder(binder);
}
// Source for ITranscodingServiceClient
const char* ITranscodingServiceClient::descriptor = "android.media.ITranscodingServiceClient";
ITranscodingServiceClient::ITranscodingServiceClient() {}
ITranscodingServiceClient::~ITranscodingServiceClient() {}


std::shared_ptr<ITranscodingServiceClient> ITranscodingServiceClient::fromBinder(const ::ndk::SpAIBinder& binder) {
  if (!AIBinder_associateClass(binder.get(), _g_aidl_clazz)) { return nullptr; }
  std::shared_ptr<::ndk::ICInterface> interface = ::ndk::ICInterface::asInterface(binder.get());
  if (interface) {
    return std::static_pointer_cast<ITranscodingServiceClient>(interface);
  }
  return ::ndk::SharedRefBase::make<BpTranscodingServiceClient>(binder);
}

binder_status_t ITranscodingServiceClient::writeToParcel(AParcel* parcel, const std::shared_ptr<ITranscodingServiceClient>& instance) {
  return AParcel_writeStrongBinder(parcel, instance ? instance->asBinder().get() : nullptr);
}
binder_status_t ITranscodingServiceClient::readFromParcel(const AParcel* parcel, std::shared_ptr<ITranscodingServiceClient>* instance) {
  ::ndk::SpAIBinder binder;
  binder_status_t status = AParcel_readStrongBinder(parcel, binder.getR());
  if (status != STATUS_OK) return status;
  *instance = ITranscodingServiceClient::fromBinder(binder);
  return STATUS_OK;
}
bool ITranscodingServiceClient::setDefaultImpl(std::shared_ptr<ITranscodingServiceClient> impl) {
  // Only one user of this interface can use this function
  // at a time. This is a heuristic to detect if two different
  // users in the same process use this function.
  assert(!ITranscodingServiceClient::default_impl);
  if (impl) {
    ITranscodingServiceClient::default_impl = impl;
    return true;
  }
  return false;
}
const std::shared_ptr<ITranscodingServiceClient>& ITranscodingServiceClient::getDefaultImpl() {
  return ITranscodingServiceClient::default_impl;
}
std::shared_ptr<ITranscodingServiceClient> ITranscodingServiceClient::default_impl = nullptr;
::ndk::ScopedAStatus ITranscodingServiceClientDefault::getName(std::string* /*_aidl_return*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingServiceClientDefault::onTranscodingFinished(int32_t /*in_jobId*/, const ::aidl::android::media::TranscodingResultParcel& /*in_result*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingServiceClientDefault::onTranscodingFailed(int32_t /*in_jobId*/, ::aidl::android::media::TranscodingErrorCode /*in_errorCode*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingServiceClientDefault::onAwaitNumberOfJobsChanged(int32_t /*in_jobId*/, int32_t /*in_oldAwaitNumber*/, int32_t /*in_newAwaitNumber*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::ScopedAStatus ITranscodingServiceClientDefault::onProgressUpdate(int32_t /*in_jobId*/, int32_t /*in_progress*/) {
  ::ndk::ScopedAStatus _aidl_status;
  _aidl_status.set(AStatus_fromStatus(STATUS_UNKNOWN_TRANSACTION));
  return _aidl_status;
}
::ndk::SpAIBinder ITranscodingServiceClientDefault::asBinder() {
  return ::ndk::SpAIBinder();
}
bool ITranscodingServiceClientDefault::isRemote() {
  return false;
}
}  // namespace media
}  // namespace android
}  // namespace aidl
