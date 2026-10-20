#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_AVRCP_TARGET_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_AVRCP_TARGET_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace bluetooth {

class IBluetoothAvrcpTarget : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(BluetoothAvrcpTarget)
  virtual ::android::binder::Status sendVolumeChanged(int32_t volume) = 0;
};  // class IBluetoothAvrcpTarget

class IBluetoothAvrcpTargetDefault : public IBluetoothAvrcpTarget {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status sendVolumeChanged(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothAvrcpTargetDefault

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_I_BLUETOOTH_AVRCP_TARGET_H_
