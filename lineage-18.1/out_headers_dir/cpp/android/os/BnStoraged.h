#ifndef AIDL_GENERATED_ANDROID_OS_BN_STORAGED_H_
#define AIDL_GENERATED_ANDROID_OS_BN_STORAGED_H_

#include <binder/IInterface.h>
#include <android/os/IStoraged.h>

namespace android {

namespace os {

class BnStoraged : public ::android::BnInterface<IStoraged> {
public:
  explicit BnStoraged();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnStoraged

}  // namespace os

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_OS_BN_STORAGED_H_
