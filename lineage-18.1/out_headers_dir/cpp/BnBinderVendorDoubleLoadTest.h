#ifndef AIDL_GENERATED__BN_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_
#define AIDL_GENERATED__BN_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_

#include <binder/IInterface.h>
#include <IBinderVendorDoubleLoadTest.h>

class BnBinderVendorDoubleLoadTest : public ::android::BnInterface<IBinderVendorDoubleLoadTest> {
public:
  explicit BnBinderVendorDoubleLoadTest();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBinderVendorDoubleLoadTest

#endif  // AIDL_GENERATED__BN_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_
