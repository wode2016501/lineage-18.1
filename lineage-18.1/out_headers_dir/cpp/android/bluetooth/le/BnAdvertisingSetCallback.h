#ifndef AIDL_GENERATED_ANDROID_BLUETOOTH_LE_BN_ADVERTISING_SET_CALLBACK_H_
#define AIDL_GENERATED_ANDROID_BLUETOOTH_LE_BN_ADVERTISING_SET_CALLBACK_H_

#include <binder/IInterface.h>
#include <android/bluetooth/le/IAdvertisingSetCallback.h>

namespace android {

namespace bluetooth {

namespace le {

class BnAdvertisingSetCallback : public ::android::BnInterface<IAdvertisingSetCallback> {
public:
  explicit BnAdvertisingSetCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnAdvertisingSetCallback

}  // namespace le

}  // namespace bluetooth

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_BLUETOOTH_LE_BN_ADVERTISING_SET_CALLBACK_H_
