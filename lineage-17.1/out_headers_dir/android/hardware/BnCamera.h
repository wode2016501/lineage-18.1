#pragma once

#include <binder/IInterface.h>
#include <android/hardware/ICamera.h>
#include <android/hardware/BnCamera.h>
#include <binder/Delegate.h>


namespace android {
namespace hardware {
class BnCamera : public ::android::BnInterface<ICamera> {
public:
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnCamera();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCamera

class ICameraDelegator : public BnCamera {
public:
  explicit ICameraDelegator(const ::android::sp<ICamera> &impl) : _aidl_delegate(impl) {}

  ::android::sp<ICamera> getImpl() { return _aidl_delegate; }
  ::android::binder::Status disconnect() override {
    return _aidl_delegate->disconnect();
  }
private:
  ::android::sp<ICamera> _aidl_delegate;
};  // class ICameraDelegator
}  // namespace hardware
}  // namespace android
