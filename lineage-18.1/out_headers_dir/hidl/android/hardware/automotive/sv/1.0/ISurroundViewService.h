#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_SV_V1_0_ISURROUNDVIEWSERVICE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_SV_V1_0_ISURROUNDVIEWSERVICE_H

#include <android/hardware/automotive/sv/1.0/ISurroundView2dSession.h>
#include <android/hardware/automotive/sv/1.0/ISurroundView3dSession.h>
#include <android/hardware/automotive/sv/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace automotive {
namespace sv {
namespace V1_0 {

/**
 * Interface representing entry point for surround view.
 * 
 * Surround view service has two types of sessions 2d and 3d. Refer to their respective interface
 * for more details.
 */
struct ISurroundViewService : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.automotive.sv@1.0::ISurroundViewService"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getCameraIds
     */
    using getCameraIds_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& cameraIds)>;
    /**
     * Gets a list of camera ids that are used for generating surround view.
     * For 4 camera configuration, the cameras ids are ordered in clockwise direction
     * when viewed from top of the car starting with the front camera. i.e. FRONT, RIGHT, REAR and
     * LEFT. All other configurations must follow clockwise order.
     * 
     * @result cameraIds List of camera ids that matching the Id of EVS Cameras used by service.
     */
    virtual ::android::hardware::Return<void> getCameraIds(getCameraIds_cb _hidl_cb) = 0;

    /**
     * Return callback for start2dSession
     */
    using start2dSession_cb = std::function<void(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView2dSession>& sv2dSession, ::android::hardware::automotive::sv::V1_0::SvResult result)>;
    /**
     * Starts a surround view 2d session.
     * 
     * @result sv2dSession Returns a new 2d session that was created.
     *         result      Returns OK if successful, appropriate error result otherwise.
     */
    virtual ::android::hardware::Return<void> start2dSession(start2dSession_cb _hidl_cb) = 0;

    /**
     * Stops a surround view 2d session.
     * 
     * @param sv2dSession Valid 2d session to be stopped.
     * @return svResult   Returns OK if successful, appropriate error result otherwise.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::sv::V1_0::SvResult> stop2dSession(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView2dSession>& sv2dSession) = 0;

    /**
     * Return callback for start3dSession
     */
    using start3dSession_cb = std::function<void(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView3dSession>& sv3dSession, ::android::hardware::automotive::sv::V1_0::SvResult result)>;
    /**
     * Starts a surround view 3d session.
     * 
     * @result sv3dSession Returns a new 3d session that was created.
     *         result      Returns OK if successful, appropriate error result otherwise.
     */
    virtual ::android::hardware::Return<void> start3dSession(start3dSession_cb _hidl_cb) = 0;

    /**
     * Stops a surround view 2d session.
     * 
     * @param sv2dSession Valid 2d session to be stopped.
     * @return svResult  Returns OK if successful, appropriate error result otherwise.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::sv::V1_0::SvResult> stop3dSession(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView3dSession>& sv3dSession) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundViewService>> castFrom(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundViewService>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundViewService>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISurroundViewService> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISurroundViewService> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISurroundViewService> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISurroundViewService> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISurroundViewService> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISurroundViewService> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISurroundViewService> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISurroundViewService> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundViewService>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundViewService>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::automotive::sv::V1_0::ISurroundViewService::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace sv
}  // namespace automotive
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_SV_V1_0_ISURROUNDVIEWSERVICE_H
