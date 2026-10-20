#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BP_OCCUPANT_AWARENESS_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BP_OCCUPANT_AWARENESS_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/automotive/occupant_awareness/IOccupantAwareness.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class BpOccupantAwareness : public ::android::BpInterface<IOccupantAwareness> {
public:
  explicit BpOccupantAwareness(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpOccupantAwareness() = default;
  ::android::binder::Status startDetection(::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) override;
  ::android::binder::Status stopDetection(::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) override;
  ::android::binder::Status getCapabilityForRole(::android::hardware::automotive::occupant_awareness::Role occupantRole, int32_t* _aidl_return) override;
  ::android::binder::Status getState(::android::hardware::automotive::occupant_awareness::Role occupantRole, int32_t detectionCapability, ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus* _aidl_return) override;
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::automotive::occupant_awareness::IOccupantAwarenessClientCallback>& callback) override;
  ::android::binder::Status getLatestDetection(::android::hardware::automotive::occupant_awareness::OccupantDetections* detections) override;
};  // class BpOccupantAwareness

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BP_OCCUPANT_AWARENESS_H_
