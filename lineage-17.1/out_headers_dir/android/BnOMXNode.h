#pragma once

#include <binder/IInterface.h>
#include <android/IOMXNode.h>
#include <android/BnOMXNode.h>
#include <binder/Delegate.h>


namespace android {
class BnOMXNode : public ::android::BnInterface<IOMXNode> {
public:
  explicit BnOMXNode();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnOMXNode

class IOMXNodeDelegator : public BnOMXNode {
public:
  explicit IOMXNodeDelegator(const ::android::sp<IOMXNode> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IOMXNode> getImpl() { return _aidl_delegate; }
private:
  ::android::sp<IOMXNode> _aidl_delegate;
};  // class IOMXNodeDelegator
}  // namespace android
