#include <android/os/IDumpstateToken.h>
#include <android/os/BpDumpstateToken.h>
namespace android {
namespace os {
DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(DumpstateToken, "android.os.IDumpstateToken")
}  // namespace os
}  // namespace android
#include <android/os/BpDumpstateToken.h>
#include <android/os/BnDumpstateToken.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {
namespace os {

BpDumpstateToken::BpDumpstateToken(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IDumpstateToken>(_aidl_impl){
}

}  // namespace os
}  // namespace android
#include <android/os/BnDumpstateToken.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {
namespace os {

BnDumpstateToken::BnDumpstateToken()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnDumpstateToken::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
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

}  // namespace os
}  // namespace android
