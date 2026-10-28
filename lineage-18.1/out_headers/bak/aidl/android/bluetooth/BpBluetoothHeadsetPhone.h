#pragma once

#include "aidl/android/bluetooth/IBluetoothHeadsetPhone.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace bluetooth {
class BpBluetoothHeadsetPhone : public ::ndk::BpCInterface<IBluetoothHeadsetPhone> {
public:
  BpBluetoothHeadsetPhone(const ::ndk::SpAIBinder& binder);
  virtual ~BpBluetoothHeadsetPhone();

  ::ndk::ScopedAStatus answerCall(bool* _aidl_return) override;
  ::ndk::ScopedAStatus hangupCall(bool* _aidl_return) override;
  ::ndk::ScopedAStatus sendDtmf(int32_t in_dtmf, bool* _aidl_return) override;
  ::ndk::ScopedAStatus processChld(int32_t in_chld, bool* _aidl_return) override;
  ::ndk::ScopedAStatus getNetworkOperator(std::string* _aidl_return) override;
  ::ndk::ScopedAStatus getSubscriberNumber(std::string* _aidl_return) override;
  ::ndk::ScopedAStatus listCurrentCalls(bool* _aidl_return) override;
  ::ndk::ScopedAStatus queryPhoneState(bool* _aidl_return) override;
  ::ndk::ScopedAStatus isHighDefCallInProgress(bool* _aidl_return) override;
  ::ndk::ScopedAStatus isCsCallInProgress(bool* _aidl_return) override;
  ::ndk::ScopedAStatus updateBtHandsfreeAfterRadioTechnologyChange() override;
  ::ndk::ScopedAStatus cdmaSwapSecondCallState() override;
  ::ndk::ScopedAStatus cdmaSetSecondCallState(bool in_state) override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
