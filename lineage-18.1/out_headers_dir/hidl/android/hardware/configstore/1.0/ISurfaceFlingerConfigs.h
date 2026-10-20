#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CONFIGSTORE_V1_0_ISURFACEFLINGERCONFIGS_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CONFIGSTORE_V1_0_ISURFACEFLINGERCONFIGS_H

#include <android/hardware/configstore/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace configstore {
namespace V1_0 {

struct ISurfaceFlingerConfigs : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.configstore@1.0::ISurfaceFlingerConfigs"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for vsyncEventPhaseOffsetNs
     */
    using vsyncEventPhaseOffsetNs_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalInt64& value)>;
    /**
     * The following two methods define (respectively):
     * 
     * - The phase offset between hardware vsync and when apps are woken up by the
     *   Choreographer callback
     * - The phase offset between hardware vsync and when SurfaceFlinger wakes up
     *   to consume input
     * 
     * Their values may be tuned to trade off between display pipeline latency (both
     * overall latency and the lengths of the app --> SF and SF --> display phases)
     * and frame delivery jitter (which typically manifests as "jank" or "jerkiness"
     * while interacting with the device). The default values must produce a
     * relatively low amount of jitter at the expense of roughly two frames of
     * app --> display latency, and unless significant testing is performed to avoid
     * increased display jitter (both manual investigation using systrace [1] and
     * automated testing using dumpsys gfxinfo [2] are recommended), they should not
     * be modified.
     * 
     * [1] https://developer.android.com/studio/profile/systrace.html
     * [2] https://developer.android.com/training/testing/performance.html
     */
    virtual ::android::hardware::Return<void> vsyncEventPhaseOffsetNs(vsyncEventPhaseOffsetNs_cb _hidl_cb) = 0;

    /**
     * Return callback for vsyncSfEventPhaseOffsetNs
     */
    using vsyncSfEventPhaseOffsetNs_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalInt64& value)>;
    virtual ::android::hardware::Return<void> vsyncSfEventPhaseOffsetNs(vsyncSfEventPhaseOffsetNs_cb _hidl_cb) = 0;

    /**
     * Return callback for useContextPriority
     */
    using useContextPriority_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalBool& value)>;
    /**
     * Instruct the Render Engine to use EGL_IMG_context_priority hint if
     * availabe.
     */
    virtual ::android::hardware::Return<void> useContextPriority(useContextPriority_cb _hidl_cb) = 0;

    /**
     * Return callback for hasWideColorDisplay
     */
    using hasWideColorDisplay_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalBool& value)>;
    /**
     * hasWideColorDisplay indicates that the device has
     * or can support a wide-color display, e.g. color space
     * greater than sRGB. Typical display may have same
     * color primaries as DCI-P3.
     * Indicate support for this feature by setting
     * TARGET_HAS_WIDE_COLOR_DISPLAY to true in BoardConfig.mk
     * This also means that the device is color managed.
     * A color managed device will use the appropriate
     * display mode depending on the content on the screen.
     * Default is sRGB.
     */
    virtual ::android::hardware::Return<void> hasWideColorDisplay(hasWideColorDisplay_cb _hidl_cb) = 0;

    /**
     * Return callback for hasHDRDisplay
     */
    using hasHDRDisplay_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalBool& value)>;
    /**
     * hwHDRDisplay indicates that the device has an High Dynamic Range display.
     * A display is considered High Dynamic Range if it
     * 
     *     1. is a wide color gamut display, typically DCI-P3 or lager
     *     2. has high luminance capability, typically 540 nits or higher at 10% OPR
     * 
     * Indicate support for this feature by setting
     * TARGET_HAS_HDR_DISPLAY to true in BoardConfig.mk
     * TARGET_HAS_WIDE_COLOR_DISPLAY must be set to true when
     * TARGET_HAS_HDR_DISPLAY is true.
     */
    virtual ::android::hardware::Return<void> hasHDRDisplay(hasHDRDisplay_cb _hidl_cb) = 0;

    /**
     * Return callback for presentTimeOffsetFromVSyncNs
     */
    using presentTimeOffsetFromVSyncNs_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalInt64& value)>;
    /**
     * Specify the offset in nanoseconds to add to vsync time when timestamping
     * present fences.
     */
    virtual ::android::hardware::Return<void> presentTimeOffsetFromVSyncNs(presentTimeOffsetFromVSyncNs_cb _hidl_cb) = 0;

    /**
     * Return callback for useHwcForRGBtoYUV
     */
    using useHwcForRGBtoYUV_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalBool& value)>;
    /**
     * Some hardware can do RGB->YUV conversion more efficiently in hardware
     * controlled by HWC than in hardware controlled by the video encoder.
     * This instruct VirtualDisplaySurface to use HWC for such conversion on
     * GL composition.
     */
    virtual ::android::hardware::Return<void> useHwcForRGBtoYUV(useHwcForRGBtoYUV_cb _hidl_cb) = 0;

    /**
     * Return callback for maxVirtualDisplaySize
     */
    using maxVirtualDisplaySize_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalUInt64& value)>;
    /**
     *  Maximum dimension supported by HWC for virtual display.
     *  Must be equals to min(max_width, max_height).
     */
    virtual ::android::hardware::Return<void> maxVirtualDisplaySize(maxVirtualDisplaySize_cb _hidl_cb) = 0;

    /**
     * Return callback for hasSyncFramework
     */
    using hasSyncFramework_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalBool& value)>;
    /**
     * Indicates if Sync framework is available. Sync framework provides fence
     * mechanism which significantly reduces buffer processing latency.
     */
    virtual ::android::hardware::Return<void> hasSyncFramework(hasSyncFramework_cb _hidl_cb) = 0;

    /**
     * Return callback for useVrFlinger
     */
    using useVrFlinger_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalBool& value)>;
    /**
     * Return true if surface flinger should use vr flinger for compatible vr
     * apps, false otherwise. Devices that will never be running vr apps should
     * return false to avoid extra resource usage. Daydream ready devices must
     * return true for full vr support.
     */
    virtual ::android::hardware::Return<void> useVrFlinger(useVrFlinger_cb _hidl_cb) = 0;

    /**
     * Return callback for maxFrameBufferAcquiredBuffers
     */
    using maxFrameBufferAcquiredBuffers_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalInt64& value)>;
    /**
     * Controls the number of buffers SurfaceFlinger will allocate for use in
     * FramebufferSurface.
     */
    virtual ::android::hardware::Return<void> maxFrameBufferAcquiredBuffers(maxFrameBufferAcquiredBuffers_cb _hidl_cb) = 0;

    /**
     * Return callback for startGraphicsAllocatorService
     */
    using startGraphicsAllocatorService_cb = std::function<void(const ::android::hardware::configstore::V1_0::OptionalBool& value)>;
    /**
     * Returns true if surface flinger should start
     * hardware.graphics.allocator@2.0::IAllocator service.
     */
    virtual ::android::hardware::Return<void> startGraphicsAllocatorService(startGraphicsAllocatorService_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs>> castFrom(const ::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISurfaceFlingerConfigs> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISurfaceFlingerConfigs> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISurfaceFlingerConfigs> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISurfaceFlingerConfigs> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISurfaceFlingerConfigs> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISurfaceFlingerConfigs> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISurfaceFlingerConfigs> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISurfaceFlingerConfigs> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace configstore
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CONFIGSTORE_V1_0_ISURFACEFLINGERCONFIGS_H
