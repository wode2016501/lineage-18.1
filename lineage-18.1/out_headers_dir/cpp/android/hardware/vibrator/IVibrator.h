#ifndef AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_I_VIBRATOR_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_I_VIBRATOR_H_

#include <android/hardware/vibrator/CompositeEffect.h>
#include <android/hardware/vibrator/CompositePrimitive.h>
#include <android/hardware/vibrator/Effect.h>
#include <android/hardware/vibrator/EffectStrength.h>
#include <android/hardware/vibrator/IVibratorCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace vibrator {

class IVibrator : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Vibrator)
  enum  : int32_t {
    CAP_ON_CALLBACK = 1,
    CAP_PERFORM_CALLBACK = 2,
    CAP_AMPLITUDE_CONTROL = 4,
    CAP_EXTERNAL_CONTROL = 8,
    CAP_EXTERNAL_AMPLITUDE_CONTROL = 16,
    CAP_COMPOSE_EFFECTS = 32,
    CAP_ALWAYS_ON_CONTROL = 64,
  };
  virtual ::android::binder::Status getCapabilities(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status off() = 0;
  virtual ::android::binder::Status on(int32_t timeoutMs, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) = 0;
  virtual ::android::binder::Status perform(::android::hardware::vibrator::Effect effect, ::android::hardware::vibrator::EffectStrength strength, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getSupportedEffects(::std::vector<::android::hardware::vibrator::Effect>* _aidl_return) = 0;
  virtual ::android::binder::Status setAmplitude(float amplitude) = 0;
  virtual ::android::binder::Status setExternalControl(bool enabled) = 0;
  virtual ::android::binder::Status getCompositionDelayMax(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getCompositionSizeMax(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getSupportedPrimitives(::std::vector<::android::hardware::vibrator::CompositePrimitive>* _aidl_return) = 0;
  virtual ::android::binder::Status getPrimitiveDuration(::android::hardware::vibrator::CompositePrimitive primitive, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status compose(const ::std::vector<::android::hardware::vibrator::CompositeEffect>& composite, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>& callback) = 0;
  virtual ::android::binder::Status getSupportedAlwaysOnEffects(::std::vector<::android::hardware::vibrator::Effect>* _aidl_return) = 0;
  virtual ::android::binder::Status alwaysOnEnable(int32_t id, ::android::hardware::vibrator::Effect effect, ::android::hardware::vibrator::EffectStrength strength) = 0;
  virtual ::android::binder::Status alwaysOnDisable(int32_t id) = 0;
};  // class IVibrator

class IVibratorDefault : public IVibrator {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status getCapabilities(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status off() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status on(int32_t, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status perform(::android::hardware::vibrator::Effect, ::android::hardware::vibrator::EffectStrength, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedEffects(::std::vector<::android::hardware::vibrator::Effect>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAmplitude(float) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setExternalControl(bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCompositionDelayMax(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCompositionSizeMax(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedPrimitives(::std::vector<::android::hardware::vibrator::CompositePrimitive>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPrimitiveDuration(::android::hardware::vibrator::CompositePrimitive, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status compose(const ::std::vector<::android::hardware::vibrator::CompositeEffect>&, const ::android::sp<::android::hardware::vibrator::IVibratorCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSupportedAlwaysOnEffects(::std::vector<::android::hardware::vibrator::Effect>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status alwaysOnEnable(int32_t, ::android::hardware::vibrator::Effect, ::android::hardware::vibrator::EffectStrength) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status alwaysOnDisable(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVibratorDefault

}  // namespace vibrator

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_VIBRATOR_I_VIBRATOR_H_
