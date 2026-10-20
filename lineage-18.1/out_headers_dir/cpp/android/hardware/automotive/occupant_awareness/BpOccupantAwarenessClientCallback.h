#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BP_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BP_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/automotive/occupant_awareness/IOccupantAwarenessClientCallback.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class BpOccupantAwarenessClientCallback : public ::android::BpInterface<IOccupantAwarenessClientCallback> {
public:
  explicit BpOccupantAwarenessClientCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpOccupantAwarenessClientCallback() = default;
  ::android::binder::Status onSystemStatusChanged(int32_t detectionFlags, ::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus status) override;
  ::android::binder::Status onDetectionEvent(const ::android::hardware::automotive::occupant_awareness::OccupantDetections& detections) override;
};  // class BpOccupantAwarenessClientCallback

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BP_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_
