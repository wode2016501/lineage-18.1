#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_0_IAGNSSCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_0_IAGNSSCALLBACK_H

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
namespace V2_0 {

/**
 * Callback structure for the AGNSS interface.
 */
struct IAGnssCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.gnss@2.0::IAGnssCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class AGnssType : uint8_t;
    enum class AGnssStatusValue : uint8_t;

    /**
     * AGNSS service type *
     */
    enum class AGnssType : uint8_t {
        SUPL = 1,
        C2K = 2,
        SUPL_EIMS = 3,
        SUPL_IMS = 4,
    };

    enum class AGnssStatusValue : uint8_t {
        /**
         * GNSS requests data connection for AGNSS.
         */
        REQUEST_AGNSS_DATA_CONN = 1,
        /**
         * GNSS releases the AGNSS data connection.
         */
        RELEASE_AGNSS_DATA_CONN = 2,
        /**
         * AGNSS data connection initiated
         */
        AGNSS_DATA_CONNECTED = 3,
        /**
         * AGNSS data connection completed
         */
        AGNSS_DATA_CONN_DONE = 4,
        /**
         * AGNSS data connection failed
         */
        AGNSS_DATA_CONN_FAILED = 5,
    };

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Callback with AGNSS status information.
     * 
     * The GNSS HAL implementation must use this method to request the framework to setup
     * network connection for the specified AGNSS service and to update the connection
     * status so that the framework can release the resources.
     * 
     * @param type Type of AGNSS service.
     * @parama status Status of the data connection.
     */
    virtual ::android::hardware::Return<void> agnssStatusCb(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType type, ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue status) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssCallback>> castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IAGnssCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IAGnssCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IAGnssCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IAGnssCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IAGnssCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IAGnssCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IAGnssCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IAGnssCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IAGnssCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IAGnssCallback> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType o);

constexpr uint8_t operator|(const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType lhs, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType lhs, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue o);

constexpr uint8_t operator|(const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue lhs, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue lhs, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_0::IAGnssCallback>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL)) {
        os += (first ? "" : " | ");
        os += "SUPL";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL;
    }
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::C2K) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::C2K)) {
        os += (first ? "" : " | ");
        os += "C2K";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::C2K;
    }
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_EIMS) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_EIMS)) {
        os += (first ? "" : " | ");
        os += "SUPL_EIMS";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_EIMS;
    }
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_IMS) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_IMS)) {
        os += (first ? "" : " | ");
        os += "SUPL_IMS";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_IMS;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL) {
        return "SUPL";
    }
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::C2K) {
        return "C2K";
    }
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_EIMS) {
        return "SUPL_EIMS";
    }
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_IMS) {
        return "SUPL_IMS";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::REQUEST_AGNSS_DATA_CONN) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::REQUEST_AGNSS_DATA_CONN)) {
        os += (first ? "" : " | ");
        os += "REQUEST_AGNSS_DATA_CONN";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::REQUEST_AGNSS_DATA_CONN;
    }
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::RELEASE_AGNSS_DATA_CONN) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::RELEASE_AGNSS_DATA_CONN)) {
        os += (first ? "" : " | ");
        os += "RELEASE_AGNSS_DATA_CONN";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::RELEASE_AGNSS_DATA_CONN;
    }
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONNECTED) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONNECTED)) {
        os += (first ? "" : " | ");
        os += "AGNSS_DATA_CONNECTED";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONNECTED;
    }
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_DONE) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_DONE)) {
        os += (first ? "" : " | ");
        os += "AGNSS_DATA_CONN_DONE";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_DONE;
    }
    if ((o & ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_FAILED) == static_cast<uint8_t>(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_FAILED)) {
        os += (first ? "" : " | ");
        os += "AGNSS_DATA_CONN_FAILED";
        first = false;
        flipped |= ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_FAILED;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::REQUEST_AGNSS_DATA_CONN) {
        return "REQUEST_AGNSS_DATA_CONN";
    }
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::RELEASE_AGNSS_DATA_CONN) {
        return "RELEASE_AGNSS_DATA_CONN";
    }
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONNECTED) {
        return "AGNSS_DATA_CONNECTED";
    }
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_DONE) {
        return "AGNSS_DATA_CONN_DONE";
    }
    if (o == ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_FAILED) {
        return "AGNSS_DATA_CONN_FAILED";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_0::IAGnssCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::gnss::V2_0::IAGnssCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_0
}  // namespace gnss
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType, 4> hidl_enum_values<::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType> = {
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL,
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::C2K,
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_EIMS,
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssType::SUPL_IMS,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue, 5> hidl_enum_values<::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue> = {
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::REQUEST_AGNSS_DATA_CONN,
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::RELEASE_AGNSS_DATA_CONN,
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONNECTED,
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_DONE,
    ::android::hardware::gnss::V2_0::IAGnssCallback::AGnssStatusValue::AGNSS_DATA_CONN_FAILED,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_0_IAGNSSCALLBACK_H
