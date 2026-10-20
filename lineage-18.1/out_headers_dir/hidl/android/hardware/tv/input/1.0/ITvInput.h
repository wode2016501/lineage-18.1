#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TV_INPUT_V1_0_ITVINPUT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TV_INPUT_V1_0_ITVINPUT_H

#include <android/hardware/tv/input/1.0/ITvInputCallback.h>
#include <android/hardware/tv/input/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tv {
namespace input {
namespace V1_0 {

struct ITvInput : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tv.input@1.0::ITvInput"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    // @entry @exit @callflow(next="getStreamConfigurations")
    /**
     * Sets a callback for events.
     * 
     * Note that initially no device is available in the client side, so the
     * implementation must notify all the currently available devices including
     * static devices via callback once callback is set.
     * 
     * @param callback Callback object to pass events.
     */
    virtual ::android::hardware::Return<void> setCallback(const ::android::sp<::android::hardware::tv::input::V1_0::ITvInputCallback>& callback) = 0;

    /**
     * Return callback for getStreamConfigurations
     */
    using getStreamConfigurations_cb = std::function<void(::android::hardware::tv::input::V1_0::Result result, const ::android::hardware::hidl_vec<::android::hardware::tv::input::V1_0::TvStreamConfig>& configurations)>;
    // @callflow(next={"openStream", "getStreamConfigurations", "closeStream"})
    /**
     * Gets stream configurations for a specific device.
     * 
     * The configs object is valid only until the next
     * STREAM_CONFIGURATIONS_CHANGED event.
     * 
     * @param deviceId Device ID for the configurations.
     * @return result OK upon success. Otherwise,
     *         INVALID_ARGUMENTS if the given device ID is not valid.
     * @return configurations An array of available configurations.
     */
    virtual ::android::hardware::Return<void> getStreamConfigurations(int32_t deviceId, getStreamConfigurations_cb _hidl_cb) = 0;

    /**
     * Return callback for openStream
     */
    using openStream_cb = std::function<void(::android::hardware::tv::input::V1_0::Result result, const ::android::hardware::hidl_handle& sidebandStream)>;
    // @callflow(next={"closeStream", "getStreamConfigurations", "openStream"})
    /**
     * Opens a specific stream in a device.
     * 
     * @param deviceId Device ID for the steam to open.
     * @param streamId Steam ID for the steam to open. Must be one of the
     *         stream IDs returned from getStreamConfigurations().
     * @return result OK upon success. Otherwise,
     *         INVALID_ARGUMENTS if any of given IDs are not valid;
     *         INVALID_STATE if the stream with the given ID is already open;
     *         NO_RESOURCE if the client must close other streams to open the
     *                 stream.
     * @return sidebandStream handle for sideband stream.
     */
    virtual ::android::hardware::Return<void> openStream(int32_t deviceId, int32_t streamId, openStream_cb _hidl_cb) = 0;

    // @callflow(next={"getStreamConfigurations", "openStream", "closeStream"})
    /**
     * Closes a specific stream in a device.
     * 
     * @param deviceId Device ID for the steam to open.
     * @param streamId Steam ID for the steam to open.
     * @return result OK upon success. Otherwise,
     *         INVALID_ARGUMENTS if any of given IDs are not valid;
     *         INVALID_STATE if the stream with the given ID is not open.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::input::V1_0::Result> closeStream(int32_t deviceId, int32_t streamId) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tv::input::V1_0::ITvInput>> castFrom(const ::android::sp<::android::hardware::tv::input::V1_0::ITvInput>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tv::input::V1_0::ITvInput>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ITvInput> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ITvInput> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ITvInput> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ITvInput> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ITvInput> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ITvInput> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ITvInput> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ITvInput> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::tv::input::V1_0::ITvInput>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::tv::input::V1_0::ITvInput>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tv::input::V1_0::ITvInput::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace input
}  // namespace tv
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TV_INPUT_V1_0_ITVINPUT_H
