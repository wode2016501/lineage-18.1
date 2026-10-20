#ifndef AIDL_GENERATED_ANDROID_OS_BN_INCIDENT_AUTH_LISTENER_H_
#define AIDL_GENERATED_ANDROID_OS_BN_INCIDENT_AUTH_LISTENER_H_

#include <binder/IInterface.h>
#include <android/os/IIncidentAuthListener.h>

namespace android {

namespace os {

class BnIncidentAuthListener : public ::android::BnInterface<IIncidentAuthListener> {
public:
  explicit BnIncidentAuthListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIncidentAuthListener

}  // namespace os

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_OS_BN_INCIDENT_AUTH_LISTENER_H_
