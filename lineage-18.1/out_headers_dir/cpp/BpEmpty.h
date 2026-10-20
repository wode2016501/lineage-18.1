#ifndef AIDL_GENERATED__BP_EMPTY_H_
#define AIDL_GENERATED__BP_EMPTY_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <IEmpty.h>

class BpEmpty : public ::android::BpInterface<IEmpty> {
public:
  explicit BpEmpty(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpEmpty() = default;
};  // class BpEmpty

#endif  // AIDL_GENERATED__BP_EMPTY_H_
