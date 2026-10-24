#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothHeadsetPhone.h>
#include <android/bluetooth/BnBluetoothHeadsetPhone.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothHeadsetPhone : public ::android::BnInterface<IBluetoothHeadsetPhone> {
public:
  static constexpr uint32_t TRANSACTION_answerCall = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_hangupCall = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_sendDtmf = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_processChld = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getNetworkOperator = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_getSubscriberNumber = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_listCurrentCalls = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_queryPhoneState = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_isHighDefCallInProgress = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_updateBtHandsfreeAfterRadioTechnologyChange = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_cdmaSwapSecondCallState = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_cdmaSetSecondCallState = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  explicit BnBluetoothHeadsetPhone();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothHeadsetPhone

class IBluetoothHeadsetPhoneDelegator : public BnBluetoothHeadsetPhone {
public:
  explicit IBluetoothHeadsetPhoneDelegator(const ::android::sp<IBluetoothHeadsetPhone> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothHeadsetPhone> getImpl() { return _aidl_delegate; }
  ::android::binder::Status answerCall(bool* _aidl_return) override {
    return _aidl_delegate->answerCall(_aidl_return);
  }
  ::android::binder::Status hangupCall(bool* _aidl_return) override {
    return _aidl_delegate->hangupCall(_aidl_return);
  }
  ::android::binder::Status sendDtmf(int32_t dtmf, bool* _aidl_return) override {
    return _aidl_delegate->sendDtmf(dtmf, _aidl_return);
  }
  ::android::binder::Status processChld(int32_t chld, bool* _aidl_return) override {
    return _aidl_delegate->processChld(chld, _aidl_return);
  }
  ::android::binder::Status getNetworkOperator(::android::String16* _aidl_return) override {
    return _aidl_delegate->getNetworkOperator(_aidl_return);
  }
  ::android::binder::Status getSubscriberNumber(::android::String16* _aidl_return) override {
    return _aidl_delegate->getSubscriberNumber(_aidl_return);
  }
  ::android::binder::Status listCurrentCalls(bool* _aidl_return) override {
    return _aidl_delegate->listCurrentCalls(_aidl_return);
  }
  ::android::binder::Status queryPhoneState(bool* _aidl_return) override {
    return _aidl_delegate->queryPhoneState(_aidl_return);
  }
  ::android::binder::Status isHighDefCallInProgress(bool* _aidl_return) override {
    return _aidl_delegate->isHighDefCallInProgress(_aidl_return);
  }
  ::android::binder::Status updateBtHandsfreeAfterRadioTechnologyChange() override {
    return _aidl_delegate->updateBtHandsfreeAfterRadioTechnologyChange();
  }
  ::android::binder::Status cdmaSwapSecondCallState() override {
    return _aidl_delegate->cdmaSwapSecondCallState();
  }
  ::android::binder::Status cdmaSetSecondCallState(bool state) override {
    return _aidl_delegate->cdmaSetSecondCallState(state);
  }
private:
  ::android::sp<IBluetoothHeadsetPhone> _aidl_delegate;
};  // class IBluetoothHeadsetPhoneDelegator
}  // namespace bluetooth
}  // namespace android
