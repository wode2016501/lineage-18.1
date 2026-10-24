#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothHeadset.h>

namespace android {
namespace bluetooth {
class BpBluetoothHeadset : public ::android::BpInterface<IBluetoothHeadset> {
public:
  explicit BpBluetoothHeadset(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothHeadset() = default;
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status startVoiceRecognition(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status stopVoiceRecognition(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status isAudioConnected(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status sendVendorSpecificResultCode(const ::android::bluetooth::BluetoothDevice& device, const ::android::String16& command, const ::android::String16& arg, bool* _aidl_return) override;
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) override;
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status getAudioState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status isAudioOn(bool* _aidl_return) override;
  ::android::binder::Status connectAudio(bool* _aidl_return) override;
  ::android::binder::Status disconnectAudio(bool* _aidl_return) override;
  ::android::binder::Status setAudioRouteAllowed(bool allowed) override;
  ::android::binder::Status getAudioRouteAllowed(bool* _aidl_return) override;
  ::android::binder::Status setForceScoAudio(bool forced) override;
  ::android::binder::Status startScoUsingVirtualVoiceCall(bool* _aidl_return) override;
  ::android::binder::Status stopScoUsingVirtualVoiceCall(bool* _aidl_return) override;
  ::android::binder::Status phoneStateChanged(int32_t numActive, int32_t numHeld, int32_t callState, const ::android::String16& number, int32_t type, const ::android::String16& name) override;
  ::android::binder::Status clccResponse(int32_t index, int32_t direction, int32_t status, int32_t mode, bool mpty, const ::android::String16& number, int32_t type) override;
  ::android::binder::Status setActiveDevice(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status getActiveDevice(::android::bluetooth::BluetoothDevice* _aidl_return) override;
  ::android::binder::Status isInbandRingingEnabled(bool* _aidl_return) override;
};  // class BpBluetoothHeadset
}  // namespace bluetooth
}  // namespace android
