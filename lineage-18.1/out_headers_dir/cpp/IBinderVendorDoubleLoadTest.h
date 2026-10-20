#ifndef AIDL_GENERATED__I_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_
#define AIDL_GENERATED__I_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <string>
#include <utils/StrongPointer.h>

class IBinderVendorDoubleLoadTest : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BinderVendorDoubleLoadTest)
  virtual ::android::binder::Status RepeatString(const ::std::string& toRepeat, ::std::string* _aidl_return) = 0;
};  // class IBinderVendorDoubleLoadTest
class IBinderVendorDoubleLoadTestDefault : public IBinderVendorDoubleLoadTest {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status RepeatString(const ::std::string&, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBinderVendorDoubleLoadTestDefault

#endif  // AIDL_GENERATED__I_BINDER_VENDOR_DOUBLE_LOAD_TEST_H_
