#ifndef AIDL_GENERATED__BP_AIDL_STUFF_H_
#define AIDL_GENERATED__BP_AIDL_STUFF_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <IAidlStuff.h>

class BpAidlStuff : public ::android::BpInterface<IAidlStuff> {
public:
  explicit BpAidlStuff(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpAidlStuff() = default;
  ::android::binder::Status callLocal() override;
  ::android::binder::Status call(int32_t idx) override;
};  // class BpAidlStuff

#endif  // AIDL_GENERATED__BP_AIDL_STUFF_H_
