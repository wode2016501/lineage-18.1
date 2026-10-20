#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_A2DP_SINK_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_A2DP_SINK_CALLBACK_H_

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothA2dpSinkCallback.h>

namespace android {

namespace bluetooth {

class BnBluetoothA2dpSinkCallback : public ::android::BnInterface<IBluetoothA2dpSinkCallback> {
public:
  explicit BnBluetoothA2dpSinkCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothA2dpSinkCallback

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_A2DP_SINK_CALLBACK_H_
