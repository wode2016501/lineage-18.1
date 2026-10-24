#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothHeadset.h>
#include <android/bluetooth/BnBluetoothHeadset.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothHeadset : public ::android::BnInterface<IBluetoothHeadset> {
public:
  static constexpr uint32_t TRANSACTION_getConnectedDevices = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getDevicesMatchingConnectionStates = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getConnectionState = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_startVoiceRecognition = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_stopVoiceRecognition = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_isAudioConnected = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_sendVendorSpecificResultCode = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_connect = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_setPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_getPriority = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getAudioState = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_isAudioOn = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_connectAudio = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_disconnectAudio = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_setAudioRouteAllowed = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_getAudioRouteAllowed = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_setForceScoAudio = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_startScoUsingVirtualVoiceCall = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_stopScoUsingVirtualVoiceCall = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_phoneStateChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_clccResponse = ::android::IBinder::FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_setActiveDevice = ::android::IBinder::FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_getActiveDevice = ::android::IBinder::FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_isInbandRingingEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 24;
  explicit BnBluetoothHeadset();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothHeadset

class IBluetoothHeadsetDelegator : public BnBluetoothHeadset {
public:
  explicit IBluetoothHeadsetDelegator(const ::android::sp<IBluetoothHeadset> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothHeadset> getImpl() { return _aidl_delegate; }
  ::android::binder::Status getConnectedDevices(::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override {
    return _aidl_delegate->getConnectedDevices(_aidl_return);
  }
  ::android::binder::Status getDevicesMatchingConnectionStates(const ::std::vector<int32_t>& states, ::std::vector<::android::bluetooth::BluetoothDevice>* _aidl_return) override {
    return _aidl_delegate->getDevicesMatchingConnectionStates(states, _aidl_return);
  }
  ::android::binder::Status getConnectionState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getConnectionState(device, _aidl_return);
  }
  ::android::binder::Status startVoiceRecognition(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->startVoiceRecognition(device, _aidl_return);
  }
  ::android::binder::Status stopVoiceRecognition(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->stopVoiceRecognition(device, _aidl_return);
  }
  ::android::binder::Status isAudioConnected(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->isAudioConnected(device, _aidl_return);
  }
  ::android::binder::Status sendVendorSpecificResultCode(const ::android::bluetooth::BluetoothDevice& device, const ::android::String16& command, const ::android::String16& arg, bool* _aidl_return) override {
    return _aidl_delegate->sendVendorSpecificResultCode(device, command, arg, _aidl_return);
  }
  ::android::binder::Status connect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->connect(device, _aidl_return);
  }
  ::android::binder::Status disconnect(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->disconnect(device, _aidl_return);
  }
  ::android::binder::Status setPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t priority, bool* _aidl_return) override {
    return _aidl_delegate->setPriority(device, priority, _aidl_return);
  }
  ::android::binder::Status getPriority(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getPriority(device, _aidl_return);
  }
  ::android::binder::Status getAudioState(const ::android::bluetooth::BluetoothDevice& device, int32_t* _aidl_return) override {
    return _aidl_delegate->getAudioState(device, _aidl_return);
  }
  ::android::binder::Status isAudioOn(bool* _aidl_return) override {
    return _aidl_delegate->isAudioOn(_aidl_return);
  }
  ::android::binder::Status connectAudio(bool* _aidl_return) override {
    return _aidl_delegate->connectAudio(_aidl_return);
  }
  ::android::binder::Status disconnectAudio(bool* _aidl_return) override {
    return _aidl_delegate->disconnectAudio(_aidl_return);
  }
  ::android::binder::Status setAudioRouteAllowed(bool allowed) override {
    return _aidl_delegate->setAudioRouteAllowed(allowed);
  }
  ::android::binder::Status getAudioRouteAllowed(bool* _aidl_return) override {
    return _aidl_delegate->getAudioRouteAllowed(_aidl_return);
  }
  ::android::binder::Status setForceScoAudio(bool forced) override {
    return _aidl_delegate->setForceScoAudio(forced);
  }
  ::android::binder::Status startScoUsingVirtualVoiceCall(bool* _aidl_return) override {
    return _aidl_delegate->startScoUsingVirtualVoiceCall(_aidl_return);
  }
  ::android::binder::Status stopScoUsingVirtualVoiceCall(bool* _aidl_return) override {
    return _aidl_delegate->stopScoUsingVirtualVoiceCall(_aidl_return);
  }
  ::android::binder::Status phoneStateChanged(int32_t numActive, int32_t numHeld, int32_t callState, const ::android::String16& number, int32_t type, const ::android::String16& name) override {
    return _aidl_delegate->phoneStateChanged(numActive, numHeld, callState, number, type, name);
  }
  ::android::binder::Status clccResponse(int32_t index, int32_t direction, int32_t status, int32_t mode, bool mpty, const ::android::String16& number, int32_t type) override {
    return _aidl_delegate->clccResponse(index, direction, status, mode, mpty, number, type);
  }
  ::android::binder::Status setActiveDevice(const ::android::bluetooth::BluetoothDevice& device, bool* _aidl_return) override {
    return _aidl_delegate->setActiveDevice(device, _aidl_return);
  }
  ::android::binder::Status getActiveDevice(::android::bluetooth::BluetoothDevice* _aidl_return) override {
    return _aidl_delegate->getActiveDevice(_aidl_return);
  }
  ::android::binder::Status isInbandRingingEnabled(bool* _aidl_return) override {
    return _aidl_delegate->isInbandRingingEnabled(_aidl_return);
  }
private:
  ::android::sp<IBluetoothHeadset> _aidl_delegate;
};  // class IBluetoothHeadsetDelegator
}  // namespace bluetooth
}  // namespace android
