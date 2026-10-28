#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace bluetooth {
class IBluetoothHeadsetPhone : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IBluetoothHeadsetPhone();
  virtual ~IBluetoothHeadsetPhone();



  static std::shared_ptr<IBluetoothHeadsetPhone> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IBluetoothHeadsetPhone>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IBluetoothHeadsetPhone>* instance);
  static bool setDefaultImpl(std::shared_ptr<IBluetoothHeadsetPhone> impl);
  static const std::shared_ptr<IBluetoothHeadsetPhone>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus answerCall(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus hangupCall(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus sendDtmf(int32_t in_dtmf, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus processChld(int32_t in_chld, bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getNetworkOperator(std::string* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getSubscriberNumber(std::string* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus listCurrentCalls(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus queryPhoneState(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus isHighDefCallInProgress(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus isCsCallInProgress(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus updateBtHandsfreeAfterRadioTechnologyChange() = 0;
  virtual ::ndk::ScopedAStatus cdmaSwapSecondCallState() = 0;
  virtual ::ndk::ScopedAStatus cdmaSetSecondCallState(bool in_state) = 0;
private:
  static std::shared_ptr<IBluetoothHeadsetPhone> default_impl;
};
class IBluetoothHeadsetPhoneDefault : public IBluetoothHeadsetPhone {
public:
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
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace bluetooth
}  // namespace android
}  // namespace aidl
