#ifndef AIDL_GENERATED__I_AIDL_STUFF_H_
#define AIDL_GENERATED__I_AIDL_STUFF_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

class IAidlStuff : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(AidlStuff)
  virtual ::android::binder::Status callLocal() = 0;
  virtual ::android::binder::Status call(int32_t idx) = 0;
};  // class IAidlStuff
class IAidlStuffDefault : public IAidlStuff {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status callLocal() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status call(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IAidlStuffDefault

#endif  // AIDL_GENERATED__I_AIDL_STUFF_H_
