#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {
namespace bluetooth {
class IBluetoothHeadsetPhoneDelegator;

class IBluetoothHeadsetPhone : public ::android::IInterface {
public:
  typedef IBluetoothHeadsetPhoneDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(BluetoothHeadsetPhone)
  virtual ::android::binder::Status answerCall(bool* _aidl_return) = 0;
  virtual ::android::binder::Status hangupCall(bool* _aidl_return) = 0;
  virtual ::android::binder::Status sendDtmf(int32_t dtmf, bool* _aidl_return) = 0;
  virtual ::android::binder::Status processChld(int32_t chld, bool* _aidl_return) = 0;
  virtual ::android::binder::Status getNetworkOperator(::android::String16* _aidl_return) = 0;
  virtual ::android::binder::Status getSubscriberNumber(::android::String16* _aidl_return) = 0;
  virtual ::android::binder::Status listCurrentCalls(bool* _aidl_return) = 0;
  virtual ::android::binder::Status queryPhoneState(bool* _aidl_return) = 0;
  virtual ::android::binder::Status isHighDefCallInProgress(bool* _aidl_return) = 0;
  virtual ::android::binder::Status updateBtHandsfreeAfterRadioTechnologyChange() = 0;
  virtual ::android::binder::Status cdmaSwapSecondCallState() = 0;
  virtual ::android::binder::Status cdmaSetSecondCallState(bool state) = 0;
};  // class IBluetoothHeadsetPhone

class IBluetoothHeadsetPhoneDefault : public IBluetoothHeadsetPhone {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status answerCall(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status hangupCall(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status sendDtmf(int32_t /*dtmf*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status processChld(int32_t /*chld*/, bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getNetworkOperator(::android::String16* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSubscriberNumber(::android::String16* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status listCurrentCalls(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status queryPhoneState(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isHighDefCallInProgress(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status updateBtHandsfreeAfterRadioTechnologyChange() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cdmaSwapSecondCallState() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cdmaSetSecondCallState(bool /*state*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IBluetoothHeadsetPhoneDefault
}  // namespace bluetooth
}  // namespace android
