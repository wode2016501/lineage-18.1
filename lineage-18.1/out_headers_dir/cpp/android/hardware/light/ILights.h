#ifndef AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_I_LIGHTS_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_I_LIGHTS_H_

#include <android/hardware/light/HwLight.h>
#include <android/hardware/light/HwLightState.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace light {

class ILights : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Lights)
  virtual ::android::binder::Status setLightState(int32_t id, const ::android::hardware::light::HwLightState& state) = 0;
  virtual ::android::binder::Status getLights(::std::vector<::android::hardware::light::HwLight>* _aidl_return) = 0;
};  // class ILights

class ILightsDefault : public ILights {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setLightState(int32_t, const ::android::hardware::light::HwLightState&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLights(::std::vector<::android::hardware::light::HwLight>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ILightsDefault

}  // namespace light

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_LIGHT_I_LIGHTS_H_
