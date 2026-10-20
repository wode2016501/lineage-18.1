#include <android/IMediaExtractor.h>
#include <android/BpMediaExtractor.h>

namespace android {

DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(MediaExtractor, "android.IMediaExtractor")

}  // namespace android
#include <android/BpMediaExtractor.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

BpMediaExtractor::BpMediaExtractor(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IMediaExtractor>(_aidl_impl){
}

}  // namespace android
#include <android/BnMediaExtractor.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

BnMediaExtractor::BnMediaExtractor()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnMediaExtractor::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
  ::android::status_t _aidl_ret_status = ::android::OK;
  switch (_aidl_code) {
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

}  // namespace android
