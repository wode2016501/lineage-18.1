#ifndef AIDL_GENERATED_ANDROID_HARDWARE_BP_CAMERA_SERVICE_PROXY_H_
#define AIDL_GENERATED_ANDROID_HARDWARE_BP_CAMERA_SERVICE_PROXY_H_

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/ICameraServiceProxy.h>

namespace android {

namespace hardware {

class BpCameraServiceProxy : public ::android::BpInterface<ICameraServiceProxy> {
public:
explicit BpCameraServiceProxy(const ::android::sp<::android::IBinder>& _aidl_impl);
virtual ~BpCameraServiceProxy() = default;
::android::binder::Status pingForUserUpdate() override;
::android::binder::Status notifyCameraState(const ::android::String16& cameraId, int32_t facing, int32_t newCameraState, const ::android::String16& clientName, int32_t apiLevel) override;
};  // class BpCameraServiceProxy

}  // namespace hardware

}  // namespace android

#endif  // AIDL_GENERATED_ANDROID_HARDWARE_BP_CAMERA_SERVICE_PROXY_H_
