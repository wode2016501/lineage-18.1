#pragma once

#include <android/bluetooth/bluetooth_device.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {
namespace bluetooth {
class IBluetoothHeadsetDelegator;

class IBluetoothHeadset : public ::android::IInterface {
public:
  typedef IBluetoothHeadsetDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothHeadset)
  virtual ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) = 0;
  virtual ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status startVoiceRecognition(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status stopVoiceRecognition(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isAudioConnected(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status sendVendorSpecificResultCode(const ::android::bluetooth::BluetoothDevice& device, const ::android::String16& command, const ::android::String16& arg, bool* _aidl_return) = 0;
  virtual ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status getAudioState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status isAudioOn(bool* _aidl_return) = 0;
  virtual ::android::binder::Status connectAudio(bool* _aidl_return) = 0;
  virtual ::android::binder::Status disconnectAudio(bool* _aidl_return) = 0;
  virtual ::android::binder::Status setAudioRouteAllowed(bool allowed) = 0;
  virtual ::android::binder::Status getAudioRouteAllowed(bool* _aidl_return) = 0;
  virtual ::android::binder::Status setForceScoAudio(bool forced) = 0;
  virtual ::android::binder::Status startScoUsingVirtualVoiceCall(bool* _aidl_return) = 0;
  virtual ::android::binder::Status stopScoUsingVirtualVoiceCall(bool* _aidl_return) = 0;
  virtual ::android::binder::Status phoneStateChanged(int32_t numActive, int32_t numHeld, int32_t callState, const ::android::String16& number, int32_t type, const ::android::String16& name) = 0;
  virtual ::android::binder::Status clccResponse(int32_t index, int32_t direction, int32_t status, int32_t mode, bool mpty, const ::android::String16& number, int32_t type) = 0;
  virtual ::android::binder::Status setActiveDevice(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getActiveDevice(::android::bluetooth::BluetoothDevice* _aidl_return) = 0;
  virtual ::android::binder::Status isInbandRingingEnabled(bool* _aidl_return) = 0;
};  // class IBluetoothHeadset

class IBluetoothHeadsetDefault : public IBluetoothHeadset {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
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
  ::android::binder::Status startVoiceRecognition(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopVoiceRecognition(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isAudioConnected(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status sendVendorSpecificResultCode(const ::android::bluetooth::BluetoothDevice& /*device*/, const ::android::String16& /*command*/, const ::android::String16& /*arg*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t /*priority*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAudioState(const ::android::bluetooth::BluetoothDevice& /*device*/, int32_t* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isAudioOn(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status connectAudio(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status disconnectAudio(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setAudioRouteAllowed(bool /*allowed*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getAudioRouteAllowed(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setForceScoAudio(bool /*forced*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startScoUsingVirtualVoiceCall(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopScoUsingVirtualVoiceCall(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status phoneStateChanged(int32_t /*numActive*/, int32_t /*numHeld*/, int32_t /*callState*/, const ::android::String16& /*number*/, int32_t /*type*/, const ::android::String16& /*name*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clccResponse(int32_t /*index*/, int32_t /*direction*/, int32_t /*status*/, int32_t /*mode*/, bool /*mpty*/, const ::android::String16& /*number*/, int32_t /*type*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setActiveDevice(const ::android::bluetooth::BluetoothDevice& /*device*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getActiveDevice(::android::bluetooth::BluetoothDevice* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isInbandRingingEnabled(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothHeadsetDefault
}  // namespace bluetooth
}  // namespace android
