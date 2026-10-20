#include <IBinderVendorDoubleLoadTest.h>
#include <BpBinderVendorDoubleLoadTest.h>

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(BinderVendorDoubleLoadTest, "IBinderVendorDoubleLoadTest")
#include <BpBinderVendorDoubleLoadTest.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

BpBinderVendorDoubleLoadTest::BpBinderVendorDoubleLoadTest(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IBinderVendorDoubleLoadTest>(_aidl_impl){
}
::android::binder::Status BpBinderVendorDoubleLoadTest::RepeatString(const ::std::string& toRepeat, ::std::string* _aidl_return) {
  ::android::Parcel _aidl_data;
  ::android::Parcel _aidl_reply;
  ::android::status_t _aidl_ret_status = ::android::OK;
  ::android::binder::Status _aidl_status;
  _aidl_ret_status = _aidl_data.writeInterfaceToken(getInterfaceDescriptor());
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = _aidl_data.writeUtf8AsUtf16(toRepeat);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_ret_status = remote()->transact(::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* RepeatString */, _aidl_data, &_aidl_reply);
  if (UNLIKELY(_aidl_ret_status == ::android::UNKNOWN_TRANSACTION && IBinderVendorDoubleLoadTest::getDefaultImpl())) {
     return IBinderVendorDoubleLoadTest::getDefaultImpl()->RepeatString(toRepeat, _aidl_return);
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
  _aidl_ret_status = _aidl_reply.readUtf8FromUtf16(_aidl_return);
  if (((_aidl_ret_status) != (::android::OK))) {
    goto _aidl_error;
  }
  _aidl_error:
  _aidl_status.setFromStatusT(_aidl_ret_status);
  return _aidl_status;
}
#include <BnBinderVendorDoubleLoadTest.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

BnBinderVendorDoubleLoadTest::BnBinderVendorDoubleLoadTest()
{
  ::android::internal::Stability::markCompilationUnit(this);
}
::android::status_t BnBinderVendorDoubleLoadTest::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
  case ::android::IBinder::FIRST_CALL_TRANSACTION + 0 /* RepeatString */:
  {
    ::std::string in_toRepeat;
    ::std::string _aidl_return;
    if (!(_aidl_data.checkInterface(this))) {
      _aidl_ret_status = ::android::BAD_TYPE;
      break;
    }
    _aidl_ret_status = _aidl_data.readUtf8FromUtf16(&in_toRepeat);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    ::android::binder::Status _aidl_status(RepeatString(in_toRepeat, &_aidl_return));
    _aidl_ret_status = _aidl_status.writeToParcel(_aidl_reply);
    if (((_aidl_ret_status) != (::android::OK))) {
      break;
    }
    if (!_aidl_status.isOk()) {
      break;
    }
    _aidl_ret_status = _aidl_reply->writeUtf8AsUtf16(_aidl_return);
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
    _aidl_ret_status = ::android::binder::Status::fromExceptionCode(::android::binder::Status::EX_NULL_POINTER).writeToParcel(_aidl_reply);
  }
  return _aidl_ret_status;
}
