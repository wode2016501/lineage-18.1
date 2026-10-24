#include <android/tests/binder/IBenchmark.h>
#include <android/tests/binder/BpBenchmark.h>
namespace android {
namespace tests {
namespace binder {
DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(Benchmark, "android.tests.binder.IBenchmark")
}  // namespace binder
}  // namespace tests
}  // namespace android
#include <android/tests/binder/BpBenchmark.h>
#include <android/tests/binder/BnBenchmark.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {
namespace tests {
namespace binder {

BpBenchmark::BpBenchmark(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IBenchmark>(_aidl_impl){
}

::android::binder::Status BpBenchmark::sendVec(const ::std::vector<uint8_t>& data, ::std::vector<uint8_t>* _aidl_return) {
  ::android::Parcel _aidl_data;
  _aidl_data.markForBinder(remoteStrong());
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeByteVector(data);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(BnBenchmark::TRANSACTION_sendVec, _aidl_data, &_aidl_reply, 0);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBenchmark::getDefaultImpl())) {
     return IBenchmark::getDefaultImpl()->sendVec(data, _aidl_return);
  }
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_status.readFromParcel(_aidl_reply);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  if (!_aidl_status.isOk()) {
    return _aidl_status;
  }
  _aidl_ret_status = _aidl_reply.readByteVector(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}

}  // namespace binder
}  // namespace tests
}  // namespace android
#include <android/tests/binder/BnBenchmark.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {
namespace tests {
namespace binder {

BnBenchmark::BnBenchmark()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnBenchmark::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case BnBenchmark::TRANSACTION_sendVec:
  {
    ::std::vector<uint8_t> in_data;
    ::std::vector<uint8_t> _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readByteVector(&in_data);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(sendVec(in_data, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeByteVector(_aidl_return);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
  }
  break;
  default:
  {
    _aidl_ret_status = ::android::BBinder::onTransact(_aidl_code, _aidl_data, _aidl_reply, _aidl_flags);
  }
  break;
  }
  if (_aidl_ret_status == ::android::UNEXPECTED_NULL) {
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeOverParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}

}  // namespace binder
}  // namespace tests
}  // namespace android
