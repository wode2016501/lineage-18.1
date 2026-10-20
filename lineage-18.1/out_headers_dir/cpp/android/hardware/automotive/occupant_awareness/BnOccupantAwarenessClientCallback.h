#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BN_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BN_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_

#include <binder/IInterface.h>
#include <android/hardware/automotive/occupant_awareness/IOccupantAwarenessClientCallback.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class BnOccupantAwarenessClientCallback : public ::android::BnInterface<IOccupantAwarenessClientCallback> {
public:
  explicit BnOccupantAwarenessClientCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnOccupantAwarenessClientCallback

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BN_OCCUPANT_AWARENESS_CLIENT_CALLBACK_H_
