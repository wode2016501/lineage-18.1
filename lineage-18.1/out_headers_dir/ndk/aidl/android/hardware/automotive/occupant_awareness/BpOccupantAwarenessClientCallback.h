#pragma once

#include "aidl/android/hardware/automotive/occupant_awareness/IOccupantAwarenessClientCallback.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace hardware {
namespace automotive {
namespace occupant_awareness {
class BpOccupantAwarenessClientCallback : public ::ndk::BpCInterface<IOccupantAwarenessClientCallback> {
public:
  BpOccupantAwarenessClientCallback(const ::ndk::SpAIBinder& binder);
  virtual ~BpOccupantAwarenessClientCallback();

  ::ndk::ScopedAStatus onSystemStatusChanged(int32_t in_detectionFlags, ::aidl::android::hardware::automotive::occupant_awareness::OccupantAwarenessStatus in_status) override;
  ::ndk::ScopedAStatus onDetectionEvent(const ::aidl::android::hardware::automotive::occupant_awareness::OccupantDetections& in_detections) override;
};
}  // namespace occupant_awareness
}  // namespace automotive
}  // namespace hardware
}  // namespace android
}  // namespace aidl
