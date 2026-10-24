#pragma once

#include <android/hardware/ISensorPrivacyListener.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android::hardware {
class ISensorPrivacyListener;
}  // namespace android::hardware
namespace android {
namespace hardware {
class ISensorPrivacyManagerDelegator;

class ISensorPrivacyManager : public ::android::IInterface {
public:
  typedef ISensorPrivacyManagerDelegator DefaultDelegator;
  DECLARE_META_INTERFACE(SensorPrivacyManager)
  virtual ::android::binder::Status addSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) = 0;
  virtual ::android::binder::Status removeSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& listener) = 0;
  virtual ::android::binder::Status isSensorPrivacyEnabled(bool* _aidl_return) = 0;
  virtual ::android::binder::Status setSensorPrivacy(bool enable) = 0;
};  // class ISensorPrivacyManager

class ISensorPrivacyManagerDefault : public ISensorPrivacyManager {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status addSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& /*listener*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status removeSensorPrivacyListener(const ::android::sp<::android::hardware::ISensorPrivacyListener>& /*listener*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isSensorPrivacyEnabled(bool* /*_aidl_return*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setSensorPrivacy(bool /*enable*/) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISensorPrivacyManagerDefault
}  // namespace hardware
}  // namespace android
