#ifndef AIDL_GENERATED__I_BINDER_NDK_UNIT_TEST_H_
#define AIDL_GENERATED__I_BINDER_NDK_UNIT_TEST_H_

#include <android/os/IEmpty.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

class IBinderNdkUnitTest : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BinderNdkUnitTest)
  virtual ::android::binder::Status takeInterface(const ::android::sp<::android::os::IEmpty>& test) = 0;
  virtual ::android::binder::Status forceFlushCommands() = 0;
};  // class IBinderNdkUnitTest
class IBinderNdkUnitTestDefault : public IBinderNdkUnitTest {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status takeInterface(const ::android::sp<::android::os::IEmpty>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status forceFlushCommands() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBinderNdkUnitTestDefault

#endif  // AIDL_GENERATED__I_BINDER_NDK_UNIT_TEST_H_
