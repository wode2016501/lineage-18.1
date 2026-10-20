#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_I_OCCUPANT_AWARENESS_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_I_OCCUPANT_AWARENESS_H_

#include <android/hardware/automotive/occupant_awareness/IOccupantAwarenessClientCallback.h>
#include <android/hardware/automotive/occupant_awareness/OccupantAwarenessStatus.h>
#include <android/hardware/automotive/occupant_awareness/OccupantDetections.h>
#include <android/hardware/automotive/occupant_awareness/Role.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class IOccupantAwareness : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(OccupantAwareness)
  enum  : int32_t {
    CAP_NONE = 0,
    CAP_PRESENCE_DETECTION = 1,
    CAP_GAZE_DETECTION = 2,
    CAP_DRIVER_MONITORING_DETECTION = 4,
  };
  virtual ::android::binder::Status startDetection(::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) = 0;
  virtual ::android::binder::Status stopDetection(::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) = 0;
  virtual ::android::binder::Status getCapabilityForRole(::android::hardware::automotive::occupant_awareness::Role occupantRole, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getState(::android::hardware::automotive::occupant_awareness::Role occupantRole, int32_t detectionCapability, ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) = 0;
  virtual ::android::binder::Status setCallback(const ::android::sp<::android::hardware::automotive::occupant_awareness::IOccupantAwarenessClientCallback>& callback) = 0;
  virtual ::android::binder::Status getLatestDetection(::android::hardware::automotive::occupant_awareness::OccupantDetections* detections) = 0;
};  // class IOccupantAwareness

class IOccupantAwarenessDefault : public IOccupantAwareness {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status startDetection(::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopDetection(::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getCapabilityForRole(::android::hardware::automotive::occupant_awareness::Role, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getState(::android::hardware::automotive::occupant_awareness::Role, int32_t, ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::automotive::occupant_awareness::IOccupantAwarenessClientCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getLatestDetection(::android::hardware::automotive::occupant_awareness::OccupantDetections*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IOccupantAwarenessDefault

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_I_OCCUPANT_AWARENESS_H_
