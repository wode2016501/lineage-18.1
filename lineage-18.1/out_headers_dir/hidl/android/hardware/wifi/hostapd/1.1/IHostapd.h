#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_1_IHOSTAPD_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_1_IHOSTAPD_H

#include <android/hardware/wifi/hostapd/1.0/IHostapd.h>
#include <android/hardware/wifi/hostapd/1.0/types.h>
#include <android/hardware/wifi/hostapd/1.1/IHostapdCallback.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace wifi {
namespace hostapd {
namespace V1_1 {

/**
 * Top-level object for managing SoftAPs.
 */
struct IHostapd : public ::android::hardware::wifi::hostapd::V1_0::IHostapd {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.wifi.hostapd@1.1::IHostapd"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct AcsChannelRange;
    struct ChannelParams;
    struct IfaceParams;

    /**
     * Parameters to specify the channel range for ACS.
     */
    struct AcsChannelRange final {
        uint32_t start __attribute__ ((aligned(4)));
        uint32_t end __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange, start) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange, end) == 4, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange) == 8, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange) == 4, "wrong alignment");

    /**
     * Parameters to control the channel selection for the interface.
     */
    struct ChannelParams final {
        ::android::hardware::hidl_vec<::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange> acsChannelRanges __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams, acsChannelRanges) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams) == 16, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams) == 8, "wrong alignment");

    /**
     * Parameters to use for setting up the access point interface.
     */
    struct IfaceParams final {
        ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams V1_0 __attribute__ ((aligned(8)));
        ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams channelParams __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams, V1_0) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams, channelParams) == 32, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams) == 48, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for addAccessPoint
     */
    using addAccessPoint_cb = std::function<void(const ::android::hardware::wifi::hostapd::V1_0::HostapdStatus& status)>;
    /**
     * Adds a new access point for hostapd to control.
     * 
     * This should trigger the setup of an access point with the specified
     * interface and network params.
     * 
     * @param ifaceParams AccessPoint Params for the access point.
     * @param nwParams Network Params for the access point.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |HostapdStatusCode.SUCCESS|,
     *         |HostapdStatusCode.FAILURE_ARGS_INVALID|,
     *         |HostapdStatusCode.FAILURE_UNKNOWN|,
     *         |HostapdStatusCode.FAILURE_IFACE_EXISTS|
     */
    virtual ::android::hardware::Return<void> addAccessPoint(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& ifaceParams, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& nwParams, addAccessPoint_cb _hidl_cb) = 0;

    /**
     * Return callback for removeAccessPoint
     */
    using removeAccessPoint_cb = std::function<void(const ::android::hardware::wifi::hostapd::V1_0::HostapdStatus& status)>;
    /**
     * Removes an existing access point from hostapd.
     * 
     * This should bring down the access point previously setup on the
     * interface.
     * 
     * @param ifaceName Name of the interface.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |HostapdStatusCode.SUCCESS|,
     *         |HostapdStatusCode.FAILURE_UNKNOWN|,
     *         |HostapdStatusCode.FAILURE_IFACE_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> removeAccessPoint(const ::android::hardware::hidl_string& ifaceName, removeAccessPoint_cb _hidl_cb) = 0;

    /**
     * Terminate the service.
     * This must de-register the service and clear all state. If this HAL
     * supports the lazy HAL protocol, then this may trigger daemon to exit and
     * wait to be restarted.
     */
    virtual ::android::hardware::Return<void> terminate() = 0;

    /**
     * Return callback for addAccessPoint_1_1
     */
    using addAccessPoint_1_1_cb = std::function<void(const ::android::hardware::wifi::hostapd::V1_0::HostapdStatus& status)>;
    /**
     * Adds a new access point for hostapd to control.
     * 
     * This should trigger the setup of an access point with the specified
     * interface and network params.
     * 
     * @param ifaceParams AccessPoint Params for the access point.
     * @param nwParams Network Params for the access point.
     * @return status Status of the operation.
     *         Possible status codes:
     *         |HostapdStatusCode.SUCCESS|,
     *         |HostapdStatusCode.FAILURE_ARGS_INVALID|,
     *         |HostapdStatusCode.FAILURE_UNKNOWN|,
     *         |HostapdStatusCode.FAILURE_IFACE_EXISTS|
     */
    virtual ::android::hardware::Return<void> addAccessPoint_1_1(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& ifaceParams, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& nwParams, addAccessPoint_1_1_cb _hidl_cb) = 0;

    /**
     * Return callback for registerCallback
     */
    using registerCallback_cb = std::function<void(const ::android::hardware::wifi::hostapd::V1_0::HostapdStatus& status)>;
    /**
     * Register for callbacks from the hostapd service.
     * 
     * These callbacks are invoked for global events that are not specific
     * to any interface or network. Registration of multiple callback
     * objects is supported. These objects must be deleted when the corresponding
     * client process is dead.
     * 
     * @param callback An instance of the |IHostapdCallback| HIDL interface
     *     object.
     * @return status Status of the operation.
     *     Possible status codes:
     *     |HostapdStatusCode.SUCCESS|,
     *     |HostapdStatusCode.FAILURE_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> registerCallback(const ::android::sp<::android::hardware::wifi::hostapd::V1_1::IHostapdCallback>& callback, registerCallback_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::hostapd::V1_1::IHostapd>> castFrom(const ::android::sp<::android::hardware::wifi::hostapd::V1_1::IHostapd>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::hostapd::V1_1::IHostapd>> castFrom(const ::android::sp<::android::hardware::wifi::hostapd::V1_0::IHostapd>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::hostapd::V1_1::IHostapd>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IHostapd> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IHostapd> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IHostapd> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IHostapd> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IHostapd> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IHostapd> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IHostapd> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IHostapd> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& o);
static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& rhs);
static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& rhs);

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& o);
static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& rhs);
static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& rhs);

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& o);
static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& rhs);
static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::wifi::hostapd::V1_1::IHostapd>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".start = ";
    os += ::android::hardware::toString(o.start);
    os += ", .end = ";
    os += ::android::hardware::toString(o.end);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& rhs) {
    if (lhs.start != rhs.start) {
        return false;
    }
    if (lhs.end != rhs.end) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::AcsChannelRange& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".acsChannelRanges = ";
    os += ::android::hardware::toString(o.acsChannelRanges);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& rhs) {
    if (lhs.acsChannelRanges != rhs.acsChannelRanges) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::ChannelParams& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".V1_0 = ";
    os += ::android::hardware::wifi::hostapd::V1_0::toString(o.V1_0);
    os += ", .channelParams = ";
    os += ::android::hardware::wifi::hostapd::V1_1::toString(o.channelParams);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& rhs) {
    if (lhs.V1_0 != rhs.V1_0) {
        return false;
    }
    if (lhs.channelParams != rhs.channelParams) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& lhs, const ::android::hardware::wifi::hostapd::V1_1::IHostapd::IfaceParams& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::wifi::hostapd::V1_1::IHostapd>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::wifi::hostapd::V1_1::IHostapd::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_1
}  // namespace hostapd
}  // namespace wifi
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_1_IHOSTAPD_H
