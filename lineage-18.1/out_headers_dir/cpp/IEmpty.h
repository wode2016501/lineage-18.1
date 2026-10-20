#ifndef AIDL_GENERATED__I_EMPTY_H_
#define AIDL_GENERATED__I_EMPTY_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

class IEmpty : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Empty)
};  // class IEmpty
class IEmptyDefault : public IEmpty {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
};  // class IEmptyDefault

#endif  // AIDL_GENERATED__I_EMPTY_H_
