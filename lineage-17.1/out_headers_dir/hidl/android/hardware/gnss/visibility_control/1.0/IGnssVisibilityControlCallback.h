#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_VISIBILITY_CONTROL_V1_0_IGNSSVISIBILITYCONTROLCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_VISIBILITY_CONTROL_V1_0_IGNSSVISIBILITYCONTROLCALLBACK_H

#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace gnss {
namespace visibility_control {
namespace V1_0 {

/**
 * GNSS location reporting permissions and notification callback interface.
 */
struct IGnssVisibilityControlCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.gnss.visibility_control@1.0::IGnssVisibilityControlCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class NfwProtocolStack : uint8_t;
    enum class NfwRequestor : uint8_t;
    enum class NfwResponseType : uint8_t;
    struct NfwNotification;

    /**
     * Protocol stack that is requesting the non-framework location information.
     */
    enum class NfwProtocolStack : uint8_t {
        /**
         * Cellular control plane requests
         */
        CTRL_PLANE = 0,
        /**
         * All types of SUPL requests
         */
        SUPL = 1,
        /**
         * All types of requests from IMS
         */
        IMS = 10,
        /**
         * All types of requests from SIM
         */
        SIM = 11,
        /**
         * Requests from other protocol stacks
         */
        OTHER_PROTOCOL_STACK = 100,
    };

    enum class NfwRequestor : uint8_t {
        /**
         * Wireless service provider
         */
        CARRIER = 0,
        /**
         * Device manufacturer
         */
        OEM = 10,
        /**
         * Modem chipset vendor
         */
        MODEM_CHIPSET_VENDOR = 11,
        /**
         * GNSS chipset vendor
         */
        GNSS_CHIPSET_VENDOR = 12,
        /**
         * Other chipset vendor
         */
        OTHER_CHIPSET_VENDOR = 13,
        /**
         * Automobile client
         */
        AUTOMOBILE_CLIENT = 20,
        /**
         * Other sources
         */
        OTHER_REQUESTOR = 100,
    };

    /**
     * GNSS response type for non-framework location requests.
     */
    enum class NfwResponseType : uint8_t {
        /**
         * Request rejected because framework has not given permission for this use case
         */
        REJECTED = 0,
        /**
         * Request accepted but could not provide location because of a failure
         */
        ACCEPTED_NO_LOCATION_PROVIDED = 1,
        /**
         * Request accepted and location provided
         */
        ACCEPTED_LOCATION_PROVIDED = 2,
    };

    /**
     * Represents a non-framework location information request/response notification.
     */
    struct NfwNotification final {
        ::android::hardware::hidl_string proxyAppPackageName __attribute__ ((aligned(8)));
        ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack protocolStack __attribute__ ((aligned(1)));
        ::android::hardware::hidl_string otherProtocolStackName __attribute__ ((aligned(8)));
        ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor requestor __attribute__ ((aligned(1)));
        ::android::hardware::hidl_string requestorId __attribute__ ((aligned(8)));
        ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType responseType __attribute__ ((aligned(1)));
        bool inEmergencyMode __attribute__ ((aligned(1)));
        bool isCachedLocation __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification, proxyAppPackageName) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification, protocolStack) == 16, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification, otherProtocolStackName) == 24, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification, requestor) == 40, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification, requestorId) == 48, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification, responseType) == 64, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification, inEmergencyMode) == 65, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification, isCachedLocation) == 66, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification) == 72, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Callback to report a non-framework delivered location.
     * 
     * The GNSS HAL implementation must call this method to notify the framework whenever
     * a non-framework location request is made to the GNSS HAL.
     * 
     * Non-framework entities like low power sensor hubs that request location from GNSS and
     * only pass location information through Android framework controls are exempt from this
     * power-spending reporting. However, low power sensor hubs or other chipsets which may send
     * the location information to anywhere other than Android framework (which provides user
     * visibility and control), must report location information use through this API whenever
     * location information (or events driven by that location such as "home" location detection)
     * leaves the domain of that low power chipset.
     * 
     * To avoid overly spamming the framework, high speed location reporting of the exact same
     * type may be throttled to report location at a lower rate than the actual report rate, as
     * long as the location is reported with a latency of no more than the larger of 5 seconds,
     * or the next the Android processor awake time. For example, if an Automotive client is
     * getting location information from the GNSS location system at 20Hz, this method may be
     * called at 1Hz. As another example, if a low power processor is getting location from the
     * GNSS chipset, and the Android processor is asleep, the notification to the Android HAL may
     * be delayed until the next wake of the Android processor.
     * 
     * @param notification Non-framework delivered location request/response description.
     */
    virtual ::android::hardware::Return<void> nfwNotifyCb(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& notification) = 0;

    /**
     * Tells if the device is currently in an emergency session.
     * 
     * Emergency session is defined as the device being actively in a user initiated emergency
     * call or in post emergency call extension time period.
     * 
     * If the GNSS HAL implementation cannot determine if the device is in emergency session
     * mode, it must call this method to confirm that the device is in emergency session before
     * serving network initiated emergency SUPL and Control Plane location requests.
     * 
     * @return success True if the framework determines that the device is in emergency session.
     */
    virtual ::android::hardware::Return<bool> isInEmergencySession() = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback>> castFrom(const ::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IGnssVisibilityControlCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssVisibilityControlCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssVisibilityControlCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssVisibilityControlCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IGnssVisibilityControlCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssVisibilityControlCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssVisibilityControlCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssVisibilityControlCallback> getService(bool getStub) { return getService("default", getStub); }
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

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack o);

constexpr uint8_t operator|(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor o);

constexpr uint8_t operator|(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType o);

constexpr uint8_t operator|(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& o);
static inline bool operator==(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& rhs);
static inline bool operator!=(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::CTRL_PLANE) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::CTRL_PLANE)) {
        os += (first ? "" : " | ");
        os += "CTRL_PLANE";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::CTRL_PLANE;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SUPL) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SUPL)) {
        os += (first ? "" : " | ");
        os += "SUPL";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SUPL;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::IMS) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::IMS)) {
        os += (first ? "" : " | ");
        os += "IMS";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::IMS;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SIM) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SIM)) {
        os += (first ? "" : " | ");
        os += "SIM";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SIM;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::OTHER_PROTOCOL_STACK) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::OTHER_PROTOCOL_STACK)) {
        os += (first ? "" : " | ");
        os += "OTHER_PROTOCOL_STACK";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::OTHER_PROTOCOL_STACK;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::CTRL_PLANE) {
        return "CTRL_PLANE";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SUPL) {
        return "SUPL";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::IMS) {
        return "IMS";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SIM) {
        return "SIM";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::OTHER_PROTOCOL_STACK) {
        return "OTHER_PROTOCOL_STACK";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::CARRIER) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::CARRIER)) {
        os += (first ? "" : " | ");
        os += "CARRIER";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::CARRIER;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OEM) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OEM)) {
        os += (first ? "" : " | ");
        os += "OEM";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OEM;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::MODEM_CHIPSET_VENDOR) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::MODEM_CHIPSET_VENDOR)) {
        os += (first ? "" : " | ");
        os += "MODEM_CHIPSET_VENDOR";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::MODEM_CHIPSET_VENDOR;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::GNSS_CHIPSET_VENDOR) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::GNSS_CHIPSET_VENDOR)) {
        os += (first ? "" : " | ");
        os += "GNSS_CHIPSET_VENDOR";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::GNSS_CHIPSET_VENDOR;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_CHIPSET_VENDOR) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_CHIPSET_VENDOR)) {
        os += (first ? "" : " | ");
        os += "OTHER_CHIPSET_VENDOR";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_CHIPSET_VENDOR;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::AUTOMOBILE_CLIENT) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::AUTOMOBILE_CLIENT)) {
        os += (first ? "" : " | ");
        os += "AUTOMOBILE_CLIENT";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::AUTOMOBILE_CLIENT;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_REQUESTOR) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_REQUESTOR)) {
        os += (first ? "" : " | ");
        os += "OTHER_REQUESTOR";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_REQUESTOR;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::CARRIER) {
        return "CARRIER";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OEM) {
        return "OEM";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::MODEM_CHIPSET_VENDOR) {
        return "MODEM_CHIPSET_VENDOR";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::GNSS_CHIPSET_VENDOR) {
        return "GNSS_CHIPSET_VENDOR";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_CHIPSET_VENDOR) {
        return "OTHER_CHIPSET_VENDOR";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::AUTOMOBILE_CLIENT) {
        return "AUTOMOBILE_CLIENT";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_REQUESTOR) {
        return "OTHER_REQUESTOR";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::REJECTED) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::REJECTED)) {
        os += (first ? "" : " | ");
        os += "REJECTED";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::REJECTED;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_NO_LOCATION_PROVIDED) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_NO_LOCATION_PROVIDED)) {
        os += (first ? "" : " | ");
        os += "ACCEPTED_NO_LOCATION_PROVIDED";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_NO_LOCATION_PROVIDED;
    }
    if ((o & ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_LOCATION_PROVIDED) == static_cast<uint8_t>(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_LOCATION_PROVIDED)) {
        os += (first ? "" : " | ");
        os += "ACCEPTED_LOCATION_PROVIDED";
        first = false;
        flipped |= ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_LOCATION_PROVIDED;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::REJECTED) {
        return "REJECTED";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_NO_LOCATION_PROVIDED) {
        return "ACCEPTED_NO_LOCATION_PROVIDED";
    }
    if (o == ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_LOCATION_PROVIDED) {
        return "ACCEPTED_LOCATION_PROVIDED";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".proxyAppPackageName = ";
    os += ::android::hardware::toString(o.proxyAppPackageName);
    os += ", .protocolStack = ";
    os += ::android::hardware::gnss::visibility_control::V1_0::toString(o.protocolStack);
    os += ", .otherProtocolStackName = ";
    os += ::android::hardware::toString(o.otherProtocolStackName);
    os += ", .requestor = ";
    os += ::android::hardware::gnss::visibility_control::V1_0::toString(o.requestor);
    os += ", .requestorId = ";
    os += ::android::hardware::toString(o.requestorId);
    os += ", .responseType = ";
    os += ::android::hardware::gnss::visibility_control::V1_0::toString(o.responseType);
    os += ", .inEmergencyMode = ";
    os += ::android::hardware::toString(o.inEmergencyMode);
    os += ", .isCachedLocation = ";
    os += ::android::hardware::toString(o.isCachedLocation);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& rhs) {
    if (lhs.proxyAppPackageName != rhs.proxyAppPackageName) {
        return false;
    }
    if (lhs.protocolStack != rhs.protocolStack) {
        return false;
    }
    if (lhs.otherProtocolStackName != rhs.otherProtocolStackName) {
        return false;
    }
    if (lhs.requestor != rhs.requestor) {
        return false;
    }
    if (lhs.requestorId != rhs.requestorId) {
        return false;
    }
    if (lhs.responseType != rhs.responseType) {
        return false;
    }
    if (lhs.inEmergencyMode != rhs.inEmergencyMode) {
        return false;
    }
    if (lhs.isCachedLocation != rhs.isCachedLocation) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& lhs, const ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwNotification& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace visibility_control
}  // namespace gnss
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack, 5> hidl_enum_values<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack> = {
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::CTRL_PLANE,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SUPL,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::IMS,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::SIM,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwProtocolStack::OTHER_PROTOCOL_STACK,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor, 7> hidl_enum_values<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor> = {
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::CARRIER,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OEM,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::MODEM_CHIPSET_VENDOR,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::GNSS_CHIPSET_VENDOR,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_CHIPSET_VENDOR,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::AUTOMOBILE_CLIENT,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwRequestor::OTHER_REQUESTOR,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType, 3> hidl_enum_values<::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType> = {
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::REJECTED,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_NO_LOCATION_PROVIDED,
    ::android::hardware::gnss::visibility_control::V1_0::IGnssVisibilityControlCallback::NfwResponseType::ACCEPTED_LOCATION_PROVIDED,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_VISIBILITY_CONTROL_V1_0_IGNSSVISIBILITYCONTROLCALLBACK_H
