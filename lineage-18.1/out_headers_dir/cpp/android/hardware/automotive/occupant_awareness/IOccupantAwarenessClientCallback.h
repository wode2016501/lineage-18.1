#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_I_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_I_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_

#include <android/hardware/automotive/occupant_awareness/OccupantAwarenessStatus.h>
#include <android/hardware/automotive/occupant_awareness/OccupantDetections.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class IOccupantAwarenessClientCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(OccupantAwarenessClientCallback)
  virtual ::android::binder::Status onSystemStatusChanged(int32_t detectionFlags, ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus status) = 0;
  virtual ::android::binder::Status onDetectionEvent(const ::android::hardware::automotive::occupant_awareness::OccupantDetections& detections) = 0;
};  // class IOccupantAwarenessClientCallback

class IOccupantAwarenessClientCallbackDefault : public IOccupantAwarenessClientCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onSystemStatusChanged(int32_t, ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onDetectionEvent(const ::android::hardware::automotive::occupant_awareness::OccupantDetections&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IOccupantAwarenessClientCallbackDefault

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_I_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_
