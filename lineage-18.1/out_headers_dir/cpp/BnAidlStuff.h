#ifndef AIDL_GENERATED__BN_AIDL_STUFF_H_
#define AIDL_GENERATED__BN_AIDL_STUFF_H_

#include <binder/IInterface.h>
#include <IAidlStuff.h>

class BnAidlStuff : public ::android::BnInterface<IAidlStuff> {
public:
  explicit BnAidlStuff();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAidlStuff

#endif  // AIDL_GENERATED__BN_AIDL_STUFF_H_
