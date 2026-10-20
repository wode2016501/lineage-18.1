#ifndef AIDL_GENERATED__BP_BINDER_STABILITY_TEST_H_
#define AIDL_GENERATED__BP_BINDER_STABILITY_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <IBinderStabilityTest.h>

class BpBinderStabilityTest : public ::android::BpInterface<IBinderStabilityTest> {
public:
  explicit BpBinderStabilityTest(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBinderStabilityTest() = default;
  ::android::binder::Status sendBinder(const ::android::sp<::android::IBinder>& binder) override;
  ::android::binder::Status sendAndCallBinder(const ::android::sp<::android::IBinder>& binder) override;
  ::android::binder::Status returnNoStabilityBinder(::android::sp<::android::IBinder>* _aidl_return) override;
  ::android::binder::Status returnLocalStabilityBinder(::android::sp<::android::IBinder>* _aidl_return) override;
  ::android::binder::Status returnVintfStabilityBinder(::android::sp<::android::IBinder>* _aidl_return) override;
  ::android::binder::Status returnVendorStabilityBinder(::android::sp<::android::IBinder>* _aidl_return) override;
};  // class BpBinderStabilityTest

#endif  // AIDL_GENERATED__BP_BINDER_STABILITY_TEST_H_
