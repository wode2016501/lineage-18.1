#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V1_0_IGNSSNAVIGATIONMESSAGECALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V1_0_IGNSSNAVIGATIONMESSAGECALLBACK_H

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
namespace V1_0 {

/**
 * Represents a GNSS navigation message (or a fragment of it).
 */
struct IGnssNavigationMessageCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.gnss@1.0::IGnssNavigationMessageCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class GnssNavigationMessageType : int16_t;
    enum class NavigationMessageStatus : uint16_t;
    struct GnssNavigationMessage;

    /**
     * Enumeration of available values to indicate the GNSS Navigation message
     * types.
     * 
     * For convenience, first byte is the GnssConstellationType on which that signal
     * is typically transmitted.
     */
    enum class GnssNavigationMessageType : int16_t {
        UNKNOWN = 0,
        /**
         * GPS L1 C/A message contained in the structure.
         */
        GPS_L1CA = 257 /* 0x0101 */,
        /**
         * GPS L2-CNAV message contained in the structure.
         */
        GPS_L2CNAV = 258 /* 0x0102 */,
        /**
         * GPS L5-CNAV message contained in the structure.
         */
        GPS_L5CNAV = 259 /* 0x0103 */,
        /**
         * GPS CNAV-2 message contained in the structure.
         */
        GPS_CNAV2 = 260 /* 0x0104 */,
        /**
         * Glonass L1 CA message contained in the structure.
         */
        GLO_L1CA = 769 /* 0x0301 */,
        /**
         * Beidou D1 message contained in the structure.
         */
        BDS_D1 = 1281 /* 0x0501 */,
        /**
         * Beidou D2 message contained in the structure.
         */
        BDS_D2 = 1282 /* 0x0502 */,
        /**
         * Galileo I/NAV message contained in the structure.
         */
        GAL_I = 1537 /* 0x0601 */,
        /**
         * Galileo F/NAV message contained in the structure.
         */
        GAL_F = 1538 /* 0x0602 */,
    };

    /**
     * Status of Navigation Message
     * When a message is received properly without any parity error in its
     * navigation words, the status must be set to PARITY_PASSED.
     * If a message is received with words that failed a parity check, but the GNSS
     * receiver has corrected those words, the status must be set to PARITY_REBUILT.
     * Do not send any navigation message that contains words with parity errors
     * that cannot be corrected.
     */
    enum class NavigationMessageStatus : uint16_t {
        PARITY_PASSED = 1 /* (1 << 0) */,
        PARITY_REBUILT = 2 /* (1 << 1) */,
        UNKNOWN = 0,
    };

    struct GnssNavigationMessage final {
        int16_t svid __attribute__ ((aligned(2)));
        ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType type __attribute__ ((aligned(2)));
        ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus> status __attribute__ ((aligned(2)));
        int16_t messageId __attribute__ ((aligned(2)));
        int16_t submessageId __attribute__ ((aligned(2)));
        ::android::hardware::hidl_vec<uint8_t> data __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage, svid) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage, type) == 2, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage, status) == 4, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage, messageId) == 6, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage, submessageId) == 8, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage, data) == 16, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage) == 32, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * The callback to report an available fragment of a GNSS navigation messages
     * from the HAL.
     * 
     * @param message - The GNSS navigation submessage/subframe representation.
     */
    virtual ::android::hardware::Return<void> gnssNavigationMessageCb(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& message) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback>> castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IGnssNavigationMessageCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssNavigationMessageCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssNavigationMessageCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssNavigationMessageCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IGnssNavigationMessageCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssNavigationMessageCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssNavigationMessageCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssNavigationMessageCallback> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(int16_t o);
static inline std::string toString(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType o);

constexpr int16_t operator|(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType rhs) {
    return static_cast<int16_t>(static_cast<int16_t>(lhs) | static_cast<int16_t>(rhs));
}
constexpr int16_t operator|(const int16_t lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType rhs) {
    return static_cast<int16_t>(lhs | static_cast<int16_t>(rhs));
}
constexpr int16_t operator|(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType lhs, const int16_t rhs) {
    return static_cast<int16_t>(static_cast<int16_t>(lhs) | rhs);
}
constexpr int16_t operator&(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType rhs) {
    return static_cast<int16_t>(static_cast<int16_t>(lhs) & static_cast<int16_t>(rhs));
}
constexpr int16_t operator&(const int16_t lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType rhs) {
    return static_cast<int16_t>(lhs & static_cast<int16_t>(rhs));
}
constexpr int16_t operator&(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType lhs, const int16_t rhs) {
    return static_cast<int16_t>(static_cast<int16_t>(lhs) & rhs);
}
constexpr int16_t &operator|=(int16_t& v, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType e) {
    v |= static_cast<int16_t>(e);
    return v;
}
constexpr int16_t &operator&=(int16_t& v, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType e) {
    v &= static_cast<int16_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint16_t o);
static inline std::string toString(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus o);

constexpr uint16_t operator|(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) | static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator|(const uint16_t lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus rhs) {
    return static_cast<uint16_t>(lhs | static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator|(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus lhs, const uint16_t rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) | rhs);
}
constexpr uint16_t operator&(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) & static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator&(const uint16_t lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus rhs) {
    return static_cast<uint16_t>(lhs & static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator&(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus lhs, const uint16_t rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) & rhs);
}
constexpr uint16_t &operator|=(uint16_t& v, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus e) {
    v |= static_cast<uint16_t>(e);
    return v;
}
constexpr uint16_t &operator&=(uint16_t& v, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus e) {
    v &= static_cast<uint16_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& o);
static inline bool operator==(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType>(int16_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::UNKNOWN) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::UNKNOWN;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L1CA) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L1CA)) {
        os += (first ? "" : " | ");
        os += "GPS_L1CA";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L1CA;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L2CNAV) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L2CNAV)) {
        os += (first ? "" : " | ");
        os += "GPS_L2CNAV";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L2CNAV;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L5CNAV) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L5CNAV)) {
        os += (first ? "" : " | ");
        os += "GPS_L5CNAV";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L5CNAV;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_CNAV2) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_CNAV2)) {
        os += (first ? "" : " | ");
        os += "GPS_CNAV2";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_CNAV2;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GLO_L1CA) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GLO_L1CA)) {
        os += (first ? "" : " | ");
        os += "GLO_L1CA";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GLO_L1CA;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D1) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D1)) {
        os += (first ? "" : " | ");
        os += "BDS_D1";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D1;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D2) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D2)) {
        os += (first ? "" : " | ");
        os += "BDS_D2";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D2;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_I) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_I)) {
        os += (first ? "" : " | ");
        os += "GAL_I";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_I;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_F) == static_cast<int16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_F)) {
        os += (first ? "" : " | ");
        os += "GAL_F";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_F;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::UNKNOWN) {
        return "UNKNOWN";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L1CA) {
        return "GPS_L1CA";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L2CNAV) {
        return "GPS_L2CNAV";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L5CNAV) {
        return "GPS_L5CNAV";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_CNAV2) {
        return "GPS_CNAV2";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GLO_L1CA) {
        return "GLO_L1CA";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D1) {
        return "BDS_D1";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D2) {
        return "BDS_D2";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_I) {
        return "GAL_I";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_F) {
        return "GAL_F";
    }
    std::string os;
    os += toHexString(static_cast<int16_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus>(uint16_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_PASSED) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_PASSED)) {
        os += (first ? "" : " | ");
        os += "PARITY_PASSED";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_PASSED;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_REBUILT) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_REBUILT)) {
        os += (first ? "" : " | ");
        os += "PARITY_REBUILT";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_REBUILT;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::UNKNOWN) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::UNKNOWN;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_PASSED) {
        return "PARITY_PASSED";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_REBUILT) {
        return "PARITY_REBUILT";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::UNKNOWN) {
        return "UNKNOWN";
    }
    std::string os;
    os += toHexString(static_cast<uint16_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".svid = ";
    os += ::android::hardware::toString(o.svid);
    os += ", .type = ";
    os += ::android::hardware::gnss::V1_0::toString(o.type);
    os += ", .status = ";
    os += ::android::hardware::gnss::V1_0::toString<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus>(o.status);
    os += ", .messageId = ";
    os += ::android::hardware::toString(o.messageId);
    os += ", .submessageId = ";
    os += ::android::hardware::toString(o.submessageId);
    os += ", .data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& rhs) {
    if (lhs.svid != rhs.svid) {
        return false;
    }
    if (lhs.type != rhs.type) {
        return false;
    }
    if (lhs.status != rhs.status) {
        return false;
    }
    if (lhs.messageId != rhs.messageId) {
        return false;
    }
    if (lhs.submessageId != rhs.submessageId) {
        return false;
    }
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& lhs, const ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessage& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace gnss
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType, 10> hidl_enum_values<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType> = {
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::UNKNOWN,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L1CA,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L2CNAV,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_L5CNAV,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GPS_CNAV2,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GLO_L1CA,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D1,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::BDS_D2,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_I,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::GnssNavigationMessageType::GAL_F,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus, 3> hidl_enum_values<::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus> = {
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_PASSED,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::PARITY_REBUILT,
    ::android::hardware::gnss::V1_0::IGnssNavigationMessageCallback::NavigationMessageStatus::UNKNOWN,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V1_0_IGNSSNAVIGATIONMESSAGECALLBACK_H
