#ifndef AIDL_GENERATED__BP_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_
#define AIDL_GENERATED__BP_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <IBinderVendorDoubleLoadTest.h>

class BpBinderVendorDoubleLoadTest : public ::android::BpInterface<IBinderVendorDoubleLoadTest> {
public:
  explicit BpBinderVendorDoubleLoadTest(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBinderVendorDoubleLoadTest() = default;
  ::android::binder::Status RepeatString(const ::std::string& toRepeat, ::std::string* _aidl_return) override;
};  // class BpBinderVendorDoubleLoadTest

#endif  // AIDL_GENERATED__BP_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_
