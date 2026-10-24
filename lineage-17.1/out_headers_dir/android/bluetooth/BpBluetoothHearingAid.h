#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothHearingAid.h>

namespace android {
namespace bluetooth {
class BpBluetoothHearingAid : public ::android::BpInterface<IBluetoothHearingAid> {
public:
  explicit BpBluetoothHearingAid(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothHearingAid() = default;
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status setActiveDevice(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override;
  ::android::binder::Status getActiveDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override;
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) override;
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status adjustVolume(int32_t direction) override;
  ::android::binder::Status setVolume(int32_t volume) override;
  ::android::binder::Status getVolume(int32_t* _aidl_return) override;
  ::android::binder::Status getHiSyncId(const ::android::bluetooth::BluetoothDevice& device, int64_t* _aidl_return) override;
  ::android::binder::Status getDeviceSide(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
  ::android::binder::Status getDeviceMode(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override;
};  // class BpBluetoothHearingAid
}  // namespace bluetooth
}  // namespace android
