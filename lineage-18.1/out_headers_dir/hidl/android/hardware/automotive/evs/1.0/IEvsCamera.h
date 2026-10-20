#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_EVS_V1_0_IEVSCAMERA_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_EVS_V1_0_IEVSCAMERA_H

#include <android/hardware/automotive/evs/1.0/IEvsCameraStream.h>
#include <android/hardware/automotive/evs/1.0/types.h>
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
namespace evs {
namespace V1_0 {

/**
 * Represents a single camera and is the primary interface for capturing images.
 */
struct IEvsCamera : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.automotive.evs@1.0::IEvsCamera"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getCameraInfo
     */
    using getCameraInfo_cb = std::function<void(const ::android::hardware::automotive::evs::V1_0::CameraDesc& info)>;
    /**
     * Returns the ID of this camera.
     * 
     * @return info The description of this camera.  This must be the same value as
     *              reported by EvsEnumerator::getCameraList().
     */
    virtual ::android::hardware::Return<void> getCameraInfo(getCameraInfo_cb _hidl_cb) = 0;

    /**
     * Specifies the depth of the buffer chain the camera is asked to support.
     * 
     * Up to this many frames may be held concurrently by the client of IEvsCamera.
     * If this many frames have been delivered to the receiver without being returned
     * by doneWithFrame, the stream must skip frames until a buffer is returned for reuse.
     * It is legal for this call to come at any time, even while streams are already running,
     * in which case buffers should be added or removed from the chain as appropriate.
     * If no call is made to this entry point, the IEvsCamera must support at least one
     * frame by default. More is acceptable.
     * 
     * @param  bufferCount Number of buffers the client of IEvsCamera may hold concurrently.
     * @return result EvsResult::OK is returned if this call is successful.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::evs::V1_0::EvsResult> setMaxFramesInFlight(uint32_t bufferCount) = 0;

    /**
     * Request to start EVS camera stream from this camera.
     * 
     * The IEvsCameraStream must begin receiving calls with various events
     * including new image frame ready until stopVideoStream() is called.
     * 
     * @param  receiver IEvsCameraStream implementation.
     * @return result EvsResult::OK is returned if this call is successful.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::evs::V1_0::EvsResult> startVideoStream(const ::android::sp<::android::hardware::automotive::evs::V1_0::IEvsCameraStream>& receiver) = 0;

    /**
     * Return a frame that was delivered by to the IEvsCameraStream.
     * 
     * When done consuming a frame delivered to the IEvsCameraStream
     * interface, it must be returned to the IEvsCamera for reuse.
     * A small, finite number of buffers are available (possibly as small
     * as one), and if the supply is exhausted, no further frames may be
     * delivered until a buffer is returned.
     * 
     * @param  buffer A buffer to be returned.
     */
    virtual ::android::hardware::Return<void> doneWithFrame(const ::android::hardware::automotive::evs::V1_0::BufferDesc& buffer) = 0;

    /**
     * Stop the delivery of EVS camera frames.
     * 
     * Because delivery is asynchronous, frames may continue to arrive for
     * some time after this call returns. Each must be returned until the
     * closure of the stream is signaled to the IEvsCameraStream.
     * This function cannot fail and is simply ignored if the stream isn't running.
     */
    virtual ::android::hardware::Return<void> stopVideoStream() = 0;

    /**
     * Request driver specific information from the HAL implementation.
     * 
     * The values allowed for opaqueIdentifier are driver specific,
     * but no value passed in may crash the driver. The driver should
     * return 0 for any unrecognized opaqueIdentifier.
     * 
     * @param  opaqueIdentifier An unique identifier of the information to
     *                          request.
     * @return value            Requested information.  Zero is returned if the
     *                          driver does not recognize a given identifier.
     */
    virtual ::android::hardware::Return<int32_t> getExtendedInfo(uint32_t opaqueIdentifier) = 0;

    /**
     * Send a driver specific value to the HAL implementation.
     * 
     * This extension is provided to facilitate car specific
     * extensions, but no HAL implementation may require this call
     * in order to function in a default state.
     * INVALID_ARG is returned if the opaqueValue is not meaningful to
     * the driver implementation.
     * 
     * @param  opaqueIdentifier An unique identifier of the information to
     *                          program.
     *         opaqueValue      A value to program.
     * @return result           EvsResult::OK is returned if this call is successful.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::evs::V1_0::EvsResult> setExtendedInfo(uint32_t opaqueIdentifier, int32_t opaqueValue) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::evs::V1_0::IEvsCamera>> castFrom(const ::android::sp<::android::hardware::automotive::evs::V1_0::IEvsCamera>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::evs::V1_0::IEvsCamera>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IEvsCamera> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IEvsCamera> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IEvsCamera> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IEvsCamera> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IEvsCamera> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IEvsCamera> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IEvsCamera> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IEvsCamera> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::automotive::evs::V1_0::IEvsCamera>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::automotive::evs::V1_0::IEvsCamera>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::automotive::evs::V1_0::IEvsCamera::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace evs
}  // namespace automotive
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_EVS_V1_0_IEVSCAMERA_H
