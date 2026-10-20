#ifndef AIDL_GENERATED__BN_BINDER_NDK_UNIT_TEST_H_
#define AIDL_GENERATED__BN_BINDER_NDK_UNIT_TEST_H_

#include <binder/IInterface.h>
#include <IBinderNdkUnitTest.h>

class BnBinderNdkUnitTest : public ::android::BnInterface<IBinderNdkUnitTest> {
public:
  explicit BnBinderNdkUnitTest();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBinderNdkUnitTest

#endif  // AIDL_GENERATED__BN_BINDER_NDK_UNIT_TEST_H_
