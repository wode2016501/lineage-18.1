#ifndef AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_H_

#include <binder/IInterface.h>
#include <android/hardware/ICamera.h>

namespace android {

namespace hardware {

class BnCamera : public ::android::BnInterface<ICamera> {
public:
  explicit BnCamera();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCamera

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_BN_CAMERA_H_
