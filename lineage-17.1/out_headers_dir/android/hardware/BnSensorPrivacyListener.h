#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ISensorPrivacyListener.h>
#include <android/hardware/BnSensorPrivacyListener.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
class BnSensorPrivacyListener : public ::android::BnInterface<ISensorPrivacyListener> {
public:
  static constexpr uint32_t TRANSACTION_onSensorPrivacyChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnSensorPrivacyListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSensorPrivacyListener

class ISensorPrivacyListenerDelegator : public BnSensorPrivacyListener {
public:
  explicit ISensorPrivacyListenerDelegator(const ::android::sp<ISensorPrivacyListener> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ISensorPrivacyListener> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onSensorPrivacyChanged(bool enabled) override {
    return _aidl_delegate->onSensorPrivacyChanged(enabled);
  }
private:
  ::android::sp<ISensorPrivacyListener> _aidl_delegate;
};  // class ISensorPrivacyListenerDelegator
}  // namespace hardware
}  // namespace android
