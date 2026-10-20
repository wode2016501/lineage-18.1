#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_SV_V1_0_ISURROUNDVIEW2DSESSION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_SV_V1_0_ISURROUNDVIEW2DSESSION_H

#include <android/hardware/automotive/sv/1.0/ISurroundViewSession.h>
#include <android/hardware/automotive/sv/1.0/types.h>

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
 * Interface representing a surround view 2d session.
 * 
 * Surround view 2d provides a top/bird's eye view of the car and its surroundings.
 */
struct ISurroundView2dSession : public ::android::hardware::automotive::sv::V1_0::ISurroundViewSession {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.automotive.sv@1.0::ISurroundView2dSession"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Requests to start receiving surround view frames.
     * 
     * For surround view 3d, setViews() must be set before calling startStream().
     * 
     * @param stream     Stream to receiving callbacks for the session.
     * @return svResult  Returns OK if successful, returns VIEW_NOT_SET if setViews() is not
     *                   called for surround view 3d, appropriate error results otherwise.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::sv::V1_0::SvResult> startStream(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundViewStream>& stream) = 0;

    /**
     * Requests to stop stream.
     * 
     * Frames may continue to arrive after call returns. Each must be returned until
     * the closure of the stream is signaled by the ISurroundViewStream.
     */
    virtual ::android::hardware::Return<void> stopStream() = 0;

    /**
     * Signal from client that a frame, which was delivered by the stream, has been consumed.
     * 
     * @param  svFramesDesc Descriptor to signal done with frame.
     */
    virtual ::android::hardware::Return<void> doneWithFrames(const ::android::hardware::automotive::sv::V1_0::SvFramesDesc& svFramesDesc) = 0;

    /**
     * Return callback for get2dMappingInfo
     */
    using get2dMappingInfo_cb = std::function<void(const ::android::hardware::automotive::sv::V1_0::Sv2dMappingInfo& sv2dMappingInfo)>;
    /**
     * Gets mapping information for 2d surround view.
     * 
     * Mapping information maps the output frame of 2d surround view to actual dimensions
     * covered on the ground. Mapping information is fixed for a car and is based upon its camera
     * coverage. Mapping information can be used for doing overlays of objects in 3d space
     * onto the surround view 2d output frame.
     * 
     * @param sv2dConfig Configuration to set.
     * @return sv2dMappingInfo mapping information of the 2d surround view.
     */
    virtual ::android::hardware::Return<void> get2dMappingInfo(get2dMappingInfo_cb _hidl_cb) = 0;

    /**
     * Sets the configuration of 2d surround view.
     * 
     * Configuration is used for supported different target use-cases of the surround view eg.
     * fullscreen or preview. Default configuration is FULLSCREEN.
     * A set config call can be performed at any time (before or after startStream) of the session.
     * Once config change is complete, a CONFIG_CHANGED event is sent, after which
     * all frames received will be of the updated config.
     * 
     * @param sv2dConfig Configuration to set.
     * @return svResult  Returns OK if successful, appropriate error result otherwise.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::sv::V1_0::SvResult> set2dConfig(const ::android::hardware::automotive::sv::V1_0::Sv2dConfig& sv2dConfig) = 0;

    /**
     * Return callback for get2dConfig
     */
    using get2dConfig_cb = std::function<void(const ::android::hardware::automotive::sv::V1_0::Sv2dConfig& sv2dConfig)>;
    /**
     * Gets the current configuration of the 2d surround view.
     * 
     * Configuration is used for supported different target use-cases of the surround view eg.
     * fullscreen view or preview. Use setConfig call to set a configuration.
     * 
     * @return sv2dConfig the active current configuration of the 2d session.
     */
    virtual ::android::hardware::Return<void> get2dConfig(get2dConfig_cb _hidl_cb) = 0;

    /**
     * Return callback for projectCameraPoints
     */
    using projectCameraPoints_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::automotive::sv::V1_0::Point2dFloat>& points2d)>;
    /**
     * Projects points on camera image to surround view 2d image.
     * 
     * Useful for mapping points detected on individual camera frames onto the surround view 2d
     * output frame.
     * 
     * @param cameraPoints  List of camera pixel points to be projected in range including (0, 0)
     *                      and (width - 1, height -1) of camera frame. If point is outside camera
     * frame INVALID_ARG error is returned.
     * @param cameraId      Id of the EvsCamera to use for projecting points. Id must be one of the
     *                      cameras as returned by getCameraIds() else INVALID_ARG error is returned
     * @return points2d     Returns a list of 2d pixel points projecting into surround view 2d
     *                      frame in the same order as cameraPoints. Point projected maybe outside
     *                      surround view frame i.e. outside (0, 0) and
     *                      (sv_width - 1, sv_height - 1). Points that do not project to ground
     *                      plane are set with inValid true.
     */
    virtual ::android::hardware::Return<void> projectCameraPoints(const ::android::hardware::hidl_vec<::android::hardware::automotive::sv::V1_0::Point2dInt>& cameraPoints, const ::android::hardware::hidl_string& cameraId, projectCameraPoints_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView2dSession>> castFrom(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView2dSession>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView2dSession>> castFrom(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundViewSession>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView2dSession>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISurroundView2dSession> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISurroundView2dSession> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISurroundView2dSession> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISurroundView2dSession> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISurroundView2dSession> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISurroundView2dSession> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISurroundView2dSession> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISurroundView2dSession> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView2dSession>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::automotive::sv::V1_0::ISurroundView2dSession>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::automotive::sv::V1_0::ISurroundView2dSession::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_SV_V1_0_ISURROUNDVIEW2DSESSION_H
