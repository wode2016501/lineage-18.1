#ifndef AIDL_GENERATED_ANDROID_DVR_BN_VR_COMPOSER_H_
#define AIDL_GENERATED_ANDROID_DVR_BN_VR_COMPOSER_H_

#include <binder/IInterface.h>
#include <android/dvr/IVrComposer.h>

namespace android {

namespace dvr {

class BnVrComposer : public ::android::BnInterface<IVrComposer> {
public:
  explicit BnVrComposer();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVrComposer

}  // namespace dvr

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_DVR_BN_VR_COMPOSER_H_
