#pragma once

#include <binder/IInterface.h>
#include <android/bluetooth/IBluetoothStateChangeCallback.h>
#include <android/bluetooth/BnBluetoothStateChangeCallback.h>
#include <binder/Delegate.h>


namespace android {
namespace bluetooth {
class BnBluetoothStateChangeCallback : public ::android::BnInterface<IBluetoothStateChangeCallback> {
public:
  static constexpr uint32_t TRANSACTION_onBluetoothStateChange = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnBluetoothStateChangeCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnBluetoothStateChangeCallback

class IBluetoothStateChangeCallbackDelegator : public BnBluetoothStateChangeCallback {
public:
  explicit IBluetoothStateChangeCallbackDelegator(const ::android::sp<IBluetoothStateChangeCallback> &impl) : _aidl_delegate(impl) {}

  ::android::sp<IBluetoothStateChangeCallback> getImpl() { return _aidl_delegate; }
  ::android::binder::Status onBluetoothStateChange(bool on) override {
    return _aidl_delegate->onBluetoothStateChange(on);
  }
private:
  ::android::sp<IBluetoothStateChangeCallback> _aidl_delegate;
};  // class IBluetoothStateChangeCallbackDelegator
}  // namespace bluetooth
}  // namespace android
