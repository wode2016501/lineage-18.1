#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_A2DP_SINK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_A2DP_SINK_H_

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothA2dpSink.h>

namespace android {

namespace bluetooth {

class BnBluetoothA2dpSink : public ::android::BnInterface<IBluetoothA2dpSink> {
public:
  explicit BnBluetoothA2dpSink();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothA2dpSink

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BN_BLUETOOTH_A2DP_SINK_H_
