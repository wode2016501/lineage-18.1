#ifndef AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_CLIENT_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_CLIENT_H_

#include <binder/IInterface.h>
#include <android/hardware/ICameraClient.h>

namespace android {

namespace hardware {

class BnCameraClient : public ::android::BnInterface<ICameraClient> {
public:
  explicit BnCameraClient();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraClient

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_CLIENT_H_
