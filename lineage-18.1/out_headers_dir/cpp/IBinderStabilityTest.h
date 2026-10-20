#ifndef AIDL_GENERATED__I_BINDER_STABILITY_TEST_H_
#define AIDL_GENERATED__I_BINDER_STABILITY_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

class IBinderStabilityTest : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BinderStabilityTest)
  virtual ::android::binder::Status sendBinder(const ::android::sp<::android::IBinder>& binder) = 0;
  virtual ::android::binder::Status sendAndCallBinder(const ::android::sp<::android::IBinder>& binder) = 0;
  virtual ::android::binder::Status returnNoStabilityBinder(::android::sp<::android::IBinder>* _aidl_return) = 0;
  virtual ::android::binder::Status returnLocalStabilityBinder(::android::sp<::android::IBinder>* _aidl_return) = 0;
  virtual ::android::binder::Status returnVintfStabilityBinder(::android::sp<::android::IBinder>* _aidl_return) = 0;
  virtual ::android::binder::Status returnVendorStabilityBinder(::android::sp<::android::IBinder>* _aidl_return) = 0;
};  // class IBinderStabilityTest
class IBinderStabilityTestDefault : public IBinderStabilityTest {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status sendBinder(const ::android::sp<::android::IBinder>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status sendAndCallBinder(const ::android::sp<::android::IBinder>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status returnNoStabilityBinder(::android::sp<::android::IBinder>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status returnLocalStabilityBinder(::android::sp<::android::IBinder>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status returnVintfStabilityBinder(::android::sp<::android::IBinder>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status returnVendorStabilityBinder(::android::sp<::android::IBinder>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBinderStabilityTestDefault

#endif  // AIDL_GENERATED__I_BINDER_STABILITY_TEST_H_
