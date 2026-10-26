#ifndef HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FACE_V1_0_IBIOMETRICSFACECLIENTCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FACE_V1_0_IBIOMETRICSFACECLIENTCALLBACK_H

#include <android/hardware/biometrics/face/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace biometrics {
namespace face {
namespace V1_0 {

/**
 * This callback interface is used by clients to recieve updates from the face
 * HAL.
 */
struct IBiometricsFaceClientCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.biometrics.face@1.0::IBiometricsFaceClientCallback"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * A callback invoked when one enrollment step has been completed.
     * 
     * @param deviceId A unique id associated with the HAL implementation
     *     service that processed this enrollment step.
     * @param faceId The id of the face template being enrolled.
     * @param userId The active user id for the template being enrolled.
     * @param remaining The number of remaining steps before enrolllment is
     *     complete or 0 if enrollment has completed successfully.
     */
    virtual ::android::hardware::Return<void> onEnrollResult(uint64_t deviceId, uint32_t faceId, int32_t userId, uint32_t remaining) = 0;

    /**
     * A callback invoked when a face has been successfully authenticated.
     * 
     * @param deviceId A unique id associated with the HAL implementation
     *     service that processed this authentication attempt.
     * @param faceId The id of the face template that passed the authentication
     *     challenge.
     * @param userId The active user id for the authenticated face.
     * @param token The hardware authentication token associated with this
     *     authenticate operation.
     */
    virtual ::android::hardware::Return<void> onAuthenticated(uint64_t deviceId, uint32_t faceId, int32_t userId, const ::android::hardware::hidl_vec<uint8_t>& token) = 0;

    /**
     * A callback invoked when a face is acquired.
     * 
     * If a non-critical, recoverable error occurs during an enrollment or
     * authentication attempt, the HAL implementation must invoke this callback
     * to allow clients to inform the user that some actionable change must be
     * made.
     * 
     * @param deviceId A unique id associated with the HAL implementation
     *     service that acquired a face.
     * @param userId The id of the active user associated with the attempted
     *     face acquisition.
     * @param acquiredInfo A message about the quality of the acquired image.
     * @param vendorCode An optional vendor-specific message. This is only valid
     *     when acquiredInfo == FaceAcquiredInfo.VENDOR. This message is opaque
     *     to the framework, and vendors must provide code to handle it. For
     *     example this can be used to guide enrollment in Settings or provide
     *     a message during authentication that is vendor-specific. The vendor
     *     is expected to provide help strings to cover all known values.
     */
    virtual ::android::hardware::Return<void> onAcquired(uint64_t deviceId, int32_t userId, ::android::hardware::biometrics::face::V1_0::FaceAcquiredInfo acquiredInfo, int32_t vendorCode) = 0;

    /**
     * A callback invoked when an error has occured.
     * 
     * @param deviceId A unique id associated with the HAL implementation
     *     service where this error occured.
     * @param userId The id of the active user when the error occured, or
     *     UserHandle::NONE if an active user had not been set yet.
     * @param error A message about the error that occurred.
     * @param vendorCode An optional, vendor-speicifc error message. Only valid
     *     when error == FaceError.VENDOR. This message is opaque to the
     *     framework, and vendors must provide code to handle it. For example,
     *     this scan be used to show the user an error message specific to the
     *     device. The vendor is expected to provide error strings to cover
     *     all known values.
     */
    virtual ::android::hardware::Return<void> onError(uint64_t deviceId, int32_t userId, ::android::hardware::biometrics::face::V1_0::FaceError error, int32_t vendorCode) = 0;

    /**
     * A callback invoked when a face template has been removed.
     * 
     * @param deviceId A unique id associated with the HAL implementation
     *     service that processed this removal.
     * @param removed A list of ids that were removed.
     * @param userId The active user id for the removed face template.
     */
    virtual ::android::hardware::Return<void> onRemoved(uint64_t deviceId, const ::android::hardware::hidl_vec<uint32_t>& removed, int32_t userId) = 0;

    /**
     * A callback invoked to enumerate all current face templates.
     * 
     * @param deviceId A unique id associated with the HAL implementation
     *     service that processed this enumeration.
     * @param faceIds A list of ids of all currently enrolled face templates.
     * @param userId The active user id for the enumerated face template.
     */
    virtual ::android::hardware::Return<void> onEnumerate(uint64_t deviceId, const ::android::hardware::hidl_vec<uint32_t>& faceIds, int32_t userId) = 0;

    /**
     * A callback invoked when the lockout state changes.
     * 
     * This method must only be invoked when setActiveUser() is called,
     * when lockout starts, and when lockout ends. When lockout starts,
     * duration must be greater than 0, and when lockout ends, duration must
     * be 0. This must be called before calling onError() with parameters
     * LOCKOUT or LOCKOUT_PERMANENT. If the user is permanently locked out,
     * the duration must be MAX_UINT64.
     * 
     * @param duration the remaining lockout duration in milliseconds, or 0
     *     if the user is not locked out.
     */
    virtual ::android::hardware::Return<void> onLockoutChanged(uint64_t duration) = 0;

    /**
     * Return callback for interfaceChain
     */
    using interfaceChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& descriptors)>;
    virtual ::android::hardware::Return<void> interfaceChain(interfaceChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options) override;

    /**
     * Return callback for interfaceDescriptor
     */
    using interfaceDescriptor_cb = std::function<void(const ::android::hardware::hidl_string& descriptor)>;
    virtual ::android::hardware::Return<void> interfaceDescriptor(interfaceDescriptor_cb _hidl_cb) override;

    /**
     * Return callback for getHashChain
     */
    using getHashChain_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>>& hashchain)>;
    virtual ::android::hardware::Return<void> getHashChain(getHashChain_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> setHALInstrumentation() override;

    virtual ::android::hardware::Return<bool> linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie) override;

    virtual ::android::hardware::Return<void> ping() override;

    /**
     * Return callback for getDebugInfo
     */
    using getDebugInfo_cb = std::function<void(const ::android::hidl::base::V1_0::DebugInfo& info)>;
    virtual ::android::hardware::Return<void> getDebugInfo(getDebugInfo_cb _hidl_cb) override;

    virtual ::android::hardware::Return<void> notifySyspropsChanged() override;

    virtual ::android::hardware::Return<bool> unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient) override;

    // cast static functions
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::biometrics::face::V1_0::IBiometricsFaceClientCallback>> castFrom(const ::android::sp<::android::hardware::biometrics::face::V1_0::IBiometricsFaceClientCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::biometrics::face::V1_0::IBiometricsFaceClientCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

    // helper methods for interactions with the hwservicemanager
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is currently not available or not in the VINTF manifest on a Trebilized
     * device, this will return nullptr. This is useful when you don't want to block
     * during device boot. If getStub is true, this will try to return an unwrapped
     * passthrough implementation in the same process. This is useful when getting an
     * implementation from the same partition/compilation group.
     * 
     * In general, prefer getService(std::string,bool)
     */
    static ::android::sp<IBiometricsFaceClientCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBiometricsFaceClientCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBiometricsFaceClientCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBiometricsFaceClientCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBiometricsFaceClientCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBiometricsFaceClientCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBiometricsFaceClientCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBiometricsFaceClientCallback> getService(bool getStub) { return getService("default", getStub); }
    /**
     * Registers a service with the service manager. For Trebilized devices, the service
     * must also be in the VINTF manifest.
     */
    __attribute__ ((warn_unused_result))::android::status_t registerAsService(const std::string &serviceName="default");
    /**
     * Registers for notifications for when a service is registered.
     */
    static bool registerForNotifications(
            const std::string &serviceName,
            const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification);
};

//
// type declarations for package
//

static inline std::string toString(const ::android::sp<::android::hardware::biometrics::face::V1_0::IBiometricsFaceClientCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::biometrics::face::V1_0::IBiometricsFaceClientCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::biometrics::face::V1_0::IBiometricsFaceClientCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace face
}  // namespace biometrics
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_BIOMETRICS_FACE_V1_0_IBIOMETRICSFACECLIENTCALLBACK_H
