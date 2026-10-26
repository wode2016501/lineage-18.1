#ifndef AIDL_GENERATED_ANDROID_OS_BN_DUMPSTATE_H_
#define AIDL_GENERATED_ANDROID_OS_BN_DUMPSTATE_H_

#include <binder/IInterface.h>
#include <android/os/IDumpstate.h>

namespace android {

namespace os {

class BnDumpstate : public ::android::BnInterface<IDumpstate> {
public:
  explicit BnDumpstate();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDumpstate

}  // namespace os

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_OS_BN_DUMPSTATE_H_
