#ifndef AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_SERVICE_PROXY_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_SERVICE_PROXY_H_

#include <binder/IInterface.h>
#include <android/hardware/ICameraServiceProxy.h>

namespace android {

namespace hardware {

class BnCameraServiceProxy : public ::android::BnInterface<ICameraServiceProxy> {
public:
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraServiceProxy

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_SERVICE_PROXY_H_
