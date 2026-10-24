#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ISensorPrivacyManager.h>
#include <android/hardware/BnSensorPrivacyListener.h>
#include <android/hardware/BnSensorPrivacyManager.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
class BnSensorPrivacyManager : public ::android::BnInterface<ISensorPrivacyManager> {
public:
  static constexpr uint32_t TRANSACTION_addSensorPrivacyListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_removeSensorPrivacyListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_isSensorPrivacyEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_setSensorPrivacy = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnSensorPrivacyManager();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSensorPrivacyManager

class ISensorPrivacyManagerDelegator : public BnSensorPrivacyManager {
public:
  explicit ISensorPrivacyManagerDelegator(const ::android::sp<ISensorPrivacyManager> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ISensorPrivacyManager> getImpl() { return _aidl_delegate; }
  ::android::binder::Status addSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) override {
    ::android::sp<::android::hardware::ISensorPrivacyListenerDelegator> _listener;
    if (listener) {
      _listener = ::android::sp<::android::hardware::ISensorPrivacyListenerDelegator>::cast(delegate(listener));
    }
    return _aidl_delegate->addSensorPrivacyListener(_listener);
  }
  ::android::binder::Status removeSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) override {
    ::android::sp<::android::hardware::ISensorPrivacyListenerDelegator> _listener;
    if (listener) {
      _listener = ::android::sp<::android::hardware::ISensorPrivacyListenerDelegator>::cast(delegate(listener));
    }
    return _aidl_delegate->removeSensorPrivacyListener(_listener);
  }
  ::android::binder::Status isSensorPrivacyEnabled(bool* _aidl_return) override {
    return _aidl_delegate->isSensorPrivacyEnabled(_aidl_return);
  }
  ::android::binder::Status setSensorPrivacy(bool enable) override {
    return _aidl_delegate->setSensorPrivacy(enable);
  }
private:
  ::android::sp<ISensorPrivacyManager> _aidl_delegate;
};  // class ISensorPrivacyManagerDelegator
}  // namespace hardware
}  // namespace android
