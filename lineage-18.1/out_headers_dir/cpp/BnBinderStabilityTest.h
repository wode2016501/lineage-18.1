#ifndef AIDL_GENERATED__BN_BINDER_STABILITY_TEST_H_
#define AIDL_GENERATED__BN_BINDER_STABILITY_TEST_H_

#include <binder/IInterface.h>
#include <IBinderStabilityTest.h>

class BnBinderStabilityTest : public ::android::BnInterface<IBinderStabilityTest> {
public:
  explicit BnBinderStabilityTest();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBinderStabilityTest

#endif  // AIDL_GENERATED__BN_BINDER_STABILITY_TEST_H_
