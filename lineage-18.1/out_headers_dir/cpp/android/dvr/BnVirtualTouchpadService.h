#ifndef AIDL_GENERATED_ANDROID_DVR_BN_VIRTUAL_TOUCHPAD_SERVICE_H_
#define AIDL_GENERATED_ANDROID_DVR_BN_VIRTUAL_TOUCHPAD_SERVICE_H_

#include <binder/IInterface.h>
#include <android/dvr/IVirtualTouchpadService.h>

namespace android {

namespace dvr {

class BnVirtualTouchpadService : public ::android::BnInterface<IVirtualTouchpadService> {
public:
  explicit BnVirtualTouchpadService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVirtualTouchpadService

}  // namespace dvr

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_DVR_BN_VIRTUAL_TOUCHPAD_SERVICE_H_
