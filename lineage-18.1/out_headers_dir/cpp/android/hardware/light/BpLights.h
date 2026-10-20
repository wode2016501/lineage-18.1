#ifndef AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_BP_LIGHTS_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_BP_LIGHTS_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/light/ILights.h>

namespace android {

namespace hardware {

namespace light {

class BpLights : public ::android::BpInterface<ILights> {
public:
  explicit BpLights(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpLights() = default;
  ::android::binder::Status setLightState(int32_t id, const ::android::hardware::light::HwLightState& state) override;
  ::android::binder::Status getLights(::std::vector<::android::hardware::light::HwLight>* _aidl_return) override;
};  // class BpLights

}  // namespace light

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_BP_LIGHTS_H_
