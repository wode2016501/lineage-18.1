#ifndef AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_BN_LIGHTS_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_BN_LIGHTS_H_

#include <binder/IInterface.h>
#include <android/hardware/light/ILights.h>

namespace android {

namespace hardware {

namespace light {

class BnLights : public ::android::BnInterface<ILights> {
public:
  explicit BnLights();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnLights

}  // namespace light

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_BN_LIGHTS_H_
