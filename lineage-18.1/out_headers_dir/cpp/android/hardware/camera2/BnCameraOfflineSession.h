#ifndef AIDL_GENERATED_ANDROID_HARDWARE_CAMERA2_BN_CAMERA_OFFLINE_SESSION_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_CAMERA2_BN_CAMERA_OFFLINE_SESSION_H_

#include <binder/IInterface.h>
#include <android/hardware/camera2/ICameraOfflineSession.h>

namespace android {

namespace hardware {

namespace camera2 {

class BnCameraOfflineSession : public ::android::BnInterface<ICameraOfflineSession> {
public:
  explicit BnCameraOfflineSession();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraOfflineSession

}  // namespace camera2

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_CAMERA2_BN_CAMERA_OFFLINE_SESSION_H_
