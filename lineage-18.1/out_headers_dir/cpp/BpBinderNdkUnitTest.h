#ifndef AIDL_GENERATED__BP_BINDER_NDK_UNIT_TEST_H_
#define AIDL_GENERATED__BP_BINDER_NDK_UNIT_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <IBinderNdkUnitTest.h>

class BpBinderNdkUnitTest : public ::android::BpInterface<IBinderNdkUnitTest> {
public:
  explicit BpBinderNdkUnitTest(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBinderNdkUnitTest() = default;
  ::android::binder::Status takeInterface(const ::android::sp<::android::os::IEmpty>& test) override;
  ::android::binder::Status forceFlushCommands() override;
};  // class BpBinderNdkUnitTest

#endif  // AIDL_GENERATED__BP_BINDER_NDK_UNIT_TEST_H_
