#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/bluetooth/IBluetoothHeadsetPhone.h>

namespace android {
namespace bluetooth {
class BpBluetoothHeadsetPhone : public ::android::BpInterface<IBluetoothHeadsetPhone> {
public:
  explicit BpBluetoothHeadsetPhone(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpBluetoothHeadsetPhone() = default;
  ::android::binder::Status answerCall(bool* _aidl_return) override;
  ::android::binder::Status hangupCall(bool* _aidl_return) override;
  ::android::binder::Status sendDtmf(int32_t dtmf, bool* _aidl_return) override;
  ::android::binder::Status processChld(int32_t chld, bool* _aidl_return) override;
  ::android::binder::Status getNetworkOperator(::android::String16* _aidl_return) override;
  ::android::binder::Status getSubscriberNumber(::android::String16* _aidl_return) override;
  ::android::binder::Status listCurrentCalls(bool* _aidl_return) override;
  ::android::binder::Status queryPhoneState(bool* _aidl_return) override;
  ::android::binder::Status isHighDefCallInProgress(bool* _aidl_return) override;
  ::android::binder::Status updateBtHandsfreeAfterRadioTechnologyChange() override;
  ::android::binder::Status cdmaSwapSecondCallState() override;
  ::android::binder::Status cdmaSetSecondCallState(bool state) override;
};  // class BpBluetoothHeadsetPhone
}  // namespace bluetooth
}  // namespace android
