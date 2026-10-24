#pragma once

#include <android/bluetooth/bluetooth_device.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace bluetooth {
class IBluetoothHearingAidDelegator;

class IBluetoothHearingAid : public ::android::IInterface {
public:
  typedef IBluetoothHearingAidDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothHearingAid)
  enum : int32_t { HI_SYNC_ID_INVALID = 0 };
  enum : int32_t { SIDE_LEFT = 0 };
  enum : int32_t { SIDE_RIGHT = 1 };
  enum : int32_t { MODE_MONAURAL = 0 };
  enum : int32_t { MODE_BINAURAL = 1 };
  virtual ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status setActiveDevice(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getActiveDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status adjustVolume(int32_t direction) = 0;
  virtual ::android::binder::Status setVolume(int32_t volume) = 0;
  virtual ::android::binder::Status getVolume(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getHiSyncId(const ::android::bluetooth::BluetoothDevice& device, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status getDeviceSide(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getDeviceMode(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
};  // class IBluetoothHearingAid

class IBluetoothHearingAidDefault : public IBluetoothHearingAid {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& /*states*/, ::std::vector<::android::bluetooth::BluetoothDevice>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setActiveDevice(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getActiveDevices(::std::vector<::android::bluetooth::BluetoothDevice>* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t /*priority*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status adjustVolume(int32_t /*direction*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setVolume(int32_t /*volume*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getVolume(int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getHiSyncId(const ::android::bluetooth::BluetoothDevice& /*device*/, int64_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDeviceSide(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getDeviceMode(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothHearingAidDefault
}  // namespace bluetooth
}  // namespace android
