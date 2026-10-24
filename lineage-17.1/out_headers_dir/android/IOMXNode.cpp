#include <android/IOMXNode.h>
#include <android/BpOMXNode.h>
namespace android {
DO_NOT_DIRECTLY_USE_ME_IMPLEMENT_META_INTERFACE(OMXNode, "android.IOMXNode")
}  // namespace android
#include <android/BpOMXNode.h>
#include <android/BnOMXNode.h>
#include <binder/Parcel.h>
#include <android-base/macros.h>

namespace android {

BpOMXNode::BpOMXNode(const ::android::sp<::android::IBinder>& _aidl_impl)
    : BpInterface<IOMXNode>(_aidl_impl){
}

}  // namespace android
#include <android/BnOMXNode.h>
#include <binder/Parcel.h>
#include <binder/Stability.h>

namespace android {

BnOMXNode::BnOMXNode()
{
  ::android::internal::Stability::markCompilationUnit(this);
}

::android::status_t BnOMXNode::onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) {
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

}  // namespace android
