#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_A2DP_SINK_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_A2DP_SINK_CALLBACK_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothA2dpSinkCallback.h>

namespace android {

namespace bluetooth {

class BpBluetoothA2dpSinkCallback : public ::android::BpInterface<IBluetoothA2dpSinkCallback> {
public:
  explicit BpBluetoothA2dpSinkCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothA2dpSinkCallback() = default;
  ::android::binder::Status OnRegistered(int32_t status) override;
  ::android::binder::Status OnConnectionState(const ::android::String16& device_address, int32_t state) override;
  ::android::binder::Status OnAudioState(const ::android::String16& device_address, int32_t state) override;
  ::android::binder::Status OnAudioConfig(const ::android::String16& device_address, int32_t sample_rate, int32_t channel_count) override;
};  // class BpBluetoothA2dpSinkCallback

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_BP_BLUETOOTH_A2DP_SINK_CALLBACK_H_
