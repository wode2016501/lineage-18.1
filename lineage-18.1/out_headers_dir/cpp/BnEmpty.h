#ifndef AIDL_GENERATED__BN_EMPTY_H_
#define AIDL_GENERATED__BN_EMPTY_H_

#include <binder/IInterface.h>
#include <IEmpty.h>

class BnEmpty : public ::android::BnInterface<IEmpty> {
public:
  explicit BnEmpty();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnEmpty

#endif  // AIDL_GENERATED__BN_EMPTY_H_
