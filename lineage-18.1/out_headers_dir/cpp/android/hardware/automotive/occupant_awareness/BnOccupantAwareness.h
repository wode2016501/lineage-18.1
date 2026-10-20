#ifndef AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BN_OCCUPANT_AWARENESS_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BN_OCCUPANT_AWARENESS_H_

#include <binder/IInterface.h>
#include <android/hardware/automotive/occupant_awareness/IOccupantAwareness.h>

namespace android {

namespace hardware {

namespace automotive {

namespace occupant_awareness {

class BnOccupantAwareness : public ::android::BnInterface<IOccupantAwareness> {
public:
  explicit BnOccupantAwareness();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnOccupantAwareness

}  // namespace occupant_awareness

}  // namespace automotive

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_OCCUPANT_AWARENESS_BN_OCCUPANT_AWARENESS_H_
