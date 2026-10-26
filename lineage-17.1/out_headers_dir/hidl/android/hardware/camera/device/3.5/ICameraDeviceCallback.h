#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_5_ICAMERADEVICECALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_5_ICAMERADEVICECALLBACK_H

#include <android/hardware/camera/device/3.2/types.h>
#include <android/hardware/camera/device/3.4/ICameraDeviceCallback.h>
#include <android/hardware/camera/device/3.5/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_5 {

/**
 * Callback methods for the HAL to call into the framework.
 */
struct ICameraDeviceCallback : public ::android::hardware::camera::device::V3_4::ICameraDeviceCallback {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.camera.device@3.5::ICameraDeviceCallback"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * processCaptureResult:
     * 
     * Send results from one or more completed or partially completed captures
     * to the framework.
     * processCaptureResult() may be invoked multiple times by the HAL in
     * response to a single capture request. This allows, for example, the
     * metadata and low-resolution buffers to be returned in one call, and
     * post-processed JPEG buffers in a later call, once it is available. Each
     * call must include the frame number of the request it is returning
     * metadata or buffers for. Only one call to processCaptureResult
     * may be made at a time by the HAL although the calls may come from
     * different threads in the HAL.
     * 
     * A component (buffer or metadata) of the complete result may only be
     * included in one process_capture_result call. A buffer for each stream,
     * and the result metadata, must be returned by the HAL for each request in
     * one of the processCaptureResult calls, even in case of errors producing
     * some of the output. A call to processCaptureResult() with neither
     * output buffers or result metadata is not allowed.
     * 
     * The order of returning metadata and buffers for a single result does not
     * matter, but buffers for a given stream must be returned in FIFO order. So
     * the buffer for request 5 for stream A must always be returned before the
     * buffer for request 6 for stream A. This also applies to the result
     * metadata; the metadata for request 5 must be returned before the metadata
     * for request 6.
     * 
     * However, different streams are independent of each other, so it is
     * acceptable and expected that the buffer for request 5 for stream A may be
     * returned after the buffer for request 6 for stream B is. And it is
     * acceptable that the result metadata for request 6 for stream B is
     * returned before the buffer for request 5 for stream A is. If multiple
     * capture results are included in a single call, camera framework must
     * process results sequentially from lower index to higher index, as if
     * these results were sent to camera framework one by one, from lower index
     * to higher index.
     * 
     * The HAL retains ownership of result structure, which only needs to be
     * valid to access during this call.
     * 
     * The output buffers do not need to be filled yet; the framework must wait
     * on the stream buffer release sync fence before reading the buffer
     * data. Therefore, this method should be called by the HAL as soon as
     * possible, even if some or all of the output buffers are still in
     * being filled. The HAL must include valid release sync fences into each
     * output_buffers stream buffer entry, or -1 if that stream buffer is
     * already filled.
     * 
     * If the result buffer cannot be constructed for a request, the HAL must
     * return an empty metadata buffer, but still provide the output buffers and
     * their sync fences. In addition, notify() must be called with an
     * ERROR_RESULT message.
     * 
     * If an output buffer cannot be filled, its status field must be set to
     * STATUS_ERROR. In addition, notify() must be called with a ERROR_BUFFER
     * message.
     * 
     * If the entire capture has failed, then this method still needs to be
     * called to return the output buffers to the framework. All the buffer
     * statuses must be STATUS_ERROR, and the result metadata must be an
     * empty buffer. In addition, notify() must be called with a ERROR_REQUEST
     * message. In this case, individual ERROR_RESULT/ERROR_BUFFER messages
     * must not be sent.
     * 
     * Performance requirements:
     * 
     * This is a non-blocking call. The framework must handle each CaptureResult
     * within 5ms.
     * 
     * The pipeline latency (see S7 for definition) should be less than or equal to
     * 4 frame intervals, and must be less than or equal to 8 frame intervals.
     * 
     */
    virtual ::android::hardware::Return<void> processCaptureResult(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::CaptureResult>& results) = 0;

    /**
     * notify:
     * 
     * Asynchronous notification callback from the HAL, fired for various
     * reasons. Only for information independent of frame capture, or that
     * require specific timing. Multiple messages may be sent in one call; a
     * message with a higher index must be considered to have occurred after a
     * message with a lower index.
     * 
     * Multiple threads may call notify() simultaneously.
     * 
     * Buffers delivered to the framework must not be dispatched to the
     * application layer until a start of exposure timestamp (or input image's
     * start of exposure timestamp for a reprocess request) has been received
     * via a SHUTTER notify() call. It is highly recommended to dispatch this
     * call as early as possible.
     * 
     * The SHUTTER notify calls for requests with android.control.enableZsl
     * set to TRUE and ANDROID_CONTROL_CAPTURE_INTENT == STILL_CAPTURE may be
     * out-of-order compared to SHUTTER notify for other kinds of requests
     * (including regular, reprocess, or zero-shutter-lag requests with
     * different capture intents).
     * 
     * As a result, the capture results of zero-shutter-lag requests with
     * ANDROID_CONTROL_CAPTURE_INTENT == STILL_CAPTURE may be out-of-order
     * compared to capture results for other kinds of requests.
     * 
     * Different SHUTTER notify calls for zero-shutter-lag requests with
     * ANDROID_CONTROL_CAPTURE_INTENT == STILL_CAPTURE must be in order between
     * them, as is for other kinds of requests. SHUTTER notify calls for
     * zero-shutter-lag requests with non STILL_CAPTURE intent must be in order
     * with SHUTTER notify calls for regular requests.
     * ------------------------------------------------------------------------
     * Performance requirements:
     * 
     * This is a non-blocking call. The framework must handle each message in 5ms.
     */
    virtual ::android::hardware::Return<void> notify(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::NotifyMsg>& msgs) = 0;

    /**
     * processCaptureResult_3_4:
     * 
     * Identical to @3.2::ICameraDeviceCallback.processCaptureResult, except
     * that it takes a list of @3.4::CaptureResult, which could contain
     * physical camera metadata for logical multi-camera.
     * 
     */
    virtual ::android::hardware::Return<void> processCaptureResult_3_4(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::CaptureResult>& results) = 0;

    /**
     * Return callback for requestStreamBuffers
     */
    using requestStreamBuffers_cb = std::function<void(::android::hardware::camera::device::V3_5::BufferRequestStatus st, const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::StreamBufferRet>& buffers)>;
    /**
     * requestStreamBuffers:
     * 
     * Synchronous callback for HAL to ask for output buffers from camera service.
     * 
     * This call may be serialized in camera service so it is strongly
     * recommended to only call this method from one thread.
     * 
     * When camera device advertises
     * (CameraMetadataEnumAndroidInfoSupportedBufferManagementVersion ==
     * ANDROID_INFO_SUPPORTED_BUFFER_MANAGEMENT_VERSION_HIDL_DEVICE_3_5), HAL
     * can use this method to request buffers from camera service.
     * 
     * @return status Status code for the operation, one of:
     *     OK: all requested buffers are returned
     *     FAILED_PARTIAL: some streams failed while some succeeds. Check
     *             individual StreamBufferRet for details.
     *     FAILED_CONFIGURING: the request failed because camera servicve is
     *             performing configureStreams and no buffers are returned.
     *     FAILED_UNKNOWN: the request failed for unknown reason and no buffers
     *             are returned.
     * 
     * Performance requirements:
     * This is a blocking call that takes more time with more buffers requested.
     * HAL must not request large amount of buffers on a latency critical code
     * path. It is highly recommended to use a dedicated thread to perform
     * all requestStreamBuffers calls, and adjust the thread priority and/or
     * timing of making the call in order for buffers to arrive before HAL is
     * ready to fill the buffer.
     */
    virtual ::android::hardware::Return<void> requestStreamBuffers(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_5::BufferRequest>& bufReqs, requestStreamBuffers_cb _hidl_cb) = 0;

    /**
     * returnStreamBuffers:
     * 
     * Synchronous callback for HAL to return output buffers to camera service.
     * 
     * If this method is called during a configureStreams call, it must be blocked
     * until camera service finishes the ongoing configureStreams call.
     */
    virtual ::android::hardware::Return<void> returnStreamBuffers(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>& buffers) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>> castFrom(const ::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>> castFrom(const ::android::sp<::android::hardware::camera::device::V3_4::ICameraDeviceCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>> castFrom(const ::android::sp<::android::hardware::camera::device::V3_2::ICameraDeviceCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ICameraDeviceCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ICameraDeviceCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ICameraDeviceCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ICameraDeviceCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ICameraDeviceCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ICameraDeviceCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ICameraDeviceCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ICameraDeviceCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::camera::device::V3_5::ICameraDeviceCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::camera::device::V3_5::ICameraDeviceCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V3_5
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CAMERA_DEVICE_V3_5_ICAMERADEVICECALLBACK_H
