#pragma once

#include <binder/IInterface.h>
#include <android/dvr/IVirtualTouchpadService.h>
#include <android/dvr/BnVirtualTouchpadService.h>
#include <binder/Delegate.h>


namespace android {
namespace dvr {
class BnVirtualTouchpadService : public ::android::BnInterface<IVirtualTouchpadService> {
public:
  static constexpr uint32_t TRANSACTION_attach = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_detach = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_touch = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_buttonState = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_scroll = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnVirtualTouchpadService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVirtualTouchpadService

class IVirtualTouchpadServiceDelegator : public BnVirtualTouchpadService {
public:
  explicit IVirtualTouchpadServiceDelegator(const ::android::sp<IVirtualTouchpadService> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IVirtualTouchpadService> getImpl() { return _aidl_delegate; }
  ::android::binder::Status attach() override {
    return _aidl_delegate->attach();
  }
  ::android::binder::Status detach() override {
    return _aidl_delegate->detach();
  }
  ::android::binder::Status touch(int32_t touchpad, float x, float y, float pressure) override {
    return _aidl_delegate->touch(touchpad, x, y, pressure);
  }
  ::android::binder::Status buttonState(int32_t touchpad, int32_t buttons) override {
    return _aidl_delegate->buttonState(touchpad, buttons);
  }
  ::android::binder::Status scroll(int32_t touchpad, float x, float y) override {
    return _aidl_delegate->scroll(touchpad, x, y);
  }
private:
  ::android::sp<IVirtualTouchpadService> _aidl_delegate;
};  // class IVirtualTouchpadServiceDelegator
}  // namespace dvr
}  // namespace android
