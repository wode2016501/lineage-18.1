#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_EVS_V1_0_IEVSDISPLAY_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_EVS_V1_0_IEVSDISPLAY_H

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
struct IEvsDisplay : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.automotive.evs@1.0::IEvsDisplay"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getDisplayInfo
     */
    using getDisplayInfo_cb = std::function<void(const ::android::hardware::automotive::evs::V1_0::DisplayDesc& info)>;
    /**
     * Returns basic information about the EVS display provided by the system.
     * 
     * See the description of the DisplayDesc structure for details.
     */
    virtual ::android::hardware::Return<void> getDisplayInfo(getDisplayInfo_cb _hidl_cb) = 0;

    /**
     * Clients may set the display state to express their desired state.
     * 
     * The HAL implementation must gracefully accept a request for any state while in
     * any other state, although the response may be to defer or ignore the request. The display
     * is defined to start in the NOT_VISIBLE state upon initialization. The client is
     * then expected to request the VISIBLE_ON_NEXT_FRAME state, and then begin providing
     * video. When the display is no longer required, the client is expected to request
     * the NOT_VISIBLE state after passing the last video frame.
     * Returns INVALID_ARG if the requested state is not a recognized value.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::evs::V1_0::EvsResult> setDisplayState(::android::hardware::automotive::evs::V1_0::DisplayState state) = 0;

    /**
     * This call requests the current state of the display
     * 
     * The HAL implementation should report the actual current state, which might
     * transiently differ from the most recently requested state. Note, however, that
     * the logic responsible for changing display states should generally live above
     * the device layer, making it undesirable for the HAL implementation to spontaneously
     * change display states.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::evs::V1_0::DisplayState> getDisplayState() = 0;

    /**
     * Return callback for getTargetBuffer
     */
    using getTargetBuffer_cb = std::function<void(const ::android::hardware::automotive::evs::V1_0::BufferDesc& buffer)>;
    /**
     * This call returns a handle to a frame buffer associated with the display.
     * 
     * The returned buffer may be locked and written to by software and/or GL. This buffer
     * must be returned via a call to returnTargetBufferForDisplay() even if the
     * display is no longer visible.
     */
    virtual ::android::hardware::Return<void> getTargetBuffer(getTargetBuffer_cb _hidl_cb) = 0;

    /**
     * This call tells the display that the buffer is ready for display.
     * 
     * The buffer is no longer valid for use by the client after this call.
     * There is no maximum time the caller may hold onto the buffer before making this
     * call. The buffer may be returned at any time and in any DisplayState, but all
     * buffers are expected to be returned before the IEvsDisplay interface is destroyed.
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::evs::V1_0::EvsResult> returnTargetBufferForDisplay(const ::android::hardware::automotive::evs::V1_0::BufferDesc& buffer) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::evs::V1_0::IEvsDisplay>> castFrom(const ::android::sp<::android::hardware::automotive::evs::V1_0::IEvsDisplay>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::evs::V1_0::IEvsDisplay>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IEvsDisplay> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IEvsDisplay> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IEvsDisplay> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IEvsDisplay> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IEvsDisplay> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IEvsDisplay> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IEvsDisplay> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IEvsDisplay> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::automotive::evs::V1_0::IEvsDisplay>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::automotive::evs::V1_0::IEvsDisplay>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::automotive::evs::V1_0::IEvsDisplay::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_EVS_V1_0_IEVSDISPLAY_H
