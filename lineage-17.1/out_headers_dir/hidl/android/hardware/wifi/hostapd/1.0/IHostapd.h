#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_0_IHOSTAPD_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_0_IHOSTAPD_H

#include <android/hardware/wifi/hostapd/1.0/types.h>
#include <android/hardware/wifi/supplicant/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

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
namespace V1_0 {

/**
 * Top-level object for managing SoftAPs.
 */
struct IHostapd : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.wifi.hostapd@1.0::IHostapd"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class ParamSizeLimits : uint32_t;
    enum class EncryptionType : uint32_t;
    enum class Band : uint32_t;
    struct HwModeParams;
    struct ChannelParams;
    struct IfaceParams;
    struct NetworkParams;

    /**
     * Size limits for some of the params used in this interface.
     */
    enum class ParamSizeLimits : uint32_t {
        /**
         * Max length of SSID param.
         */
        SSID_MAX_LEN_IN_BYTES = 32u,
        /**
         * Min length of PSK passphrase param.
         */
        WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES = 8u,
        /**
         * Max length of PSK passphrase param.
         */
        WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES = 63u,
    };

    /**
     * Possble Security types.
     */
    enum class EncryptionType : uint32_t {
        NONE = 0u,
        WPA = 1u /* (::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType.NONE implicitly + 1) */,
        WPA2 = 2u /* (::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType.WPA implicitly + 1) */,
    };

    /**
     * Band to use for the SoftAp operations.
     * When using ACS, special value |BAND_ANY| can be
     * used to indicate that any supported band can be used. This special
     * case is currently supported only with drivers with which
     * offloaded ACS is used.
     */
    enum class Band : uint32_t {
        BAND_2_4_GHZ = 0u,
        BAND_5_GHZ = 1u /* (::android::hardware::wifi::hostapd::V1_0::IHostapd::Band.BAND_2_4_GHZ implicitly + 1) */,
        BAND_ANY = 2u /* (::android::hardware::wifi::hostapd::V1_0::IHostapd::Band.BAND_5_GHZ implicitly + 1) */,
    };

    /**
     * Parameters to control the HW mode for the interface.
     */
    struct HwModeParams final {
        bool enable80211N __attribute__ ((aligned(1)));
        bool enable80211AC __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams, enable80211N) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams, enable80211AC) == 1, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams) == 2, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams) == 1, "wrong alignment");

    /**
     * Parameters to control the channel selection for the interface.
     */
    struct ChannelParams final {
        bool enableAcs __attribute__ ((aligned(1)));
        bool acsShouldExcludeDfs __attribute__ ((aligned(1)));
        uint32_t channel __attribute__ ((aligned(4)));
        ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band band __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams, enableAcs) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams, acsShouldExcludeDfs) == 1, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams, channel) == 4, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams, band) == 8, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams) == 12, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams) == 4, "wrong alignment");

    /**
     * Parameters to use for setting up the access point interface.
     */
    struct IfaceParams final {
        ::android::hardware::hidl_string ifaceName __attribute__ ((aligned(8)));
        ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams hwModeParams __attribute__ ((aligned(1)));
        ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams channelParams __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams, ifaceName) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams, hwModeParams) == 16, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams, channelParams) == 20, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams) == 32, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams) == 8, "wrong alignment");

    /**
     * Parameters to use for setting up the access point network.
     */
    struct NetworkParams final {
        ::android::hardware::hidl_vec<uint8_t> ssid __attribute__ ((aligned(8)));
        bool isHidden __attribute__ ((aligned(1)));
        ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType encryptionType __attribute__ ((aligned(4)));
        ::android::hardware::hidl_string pskPassphrase __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams, ssid) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams, isHidden) == 16, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams, encryptionType) == 20, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams, pskPassphrase) == 24, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams) == 40, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams) == 8, "wrong alignment");

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
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::hostapd::V1_0::IHostapd>> castFrom(const ::android::sp<::android::hardware::wifi::hostapd::V1_0::IHostapd>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::hostapd::V1_0::IHostapd>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits o);

constexpr uint32_t operator|(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType o);

constexpr uint32_t operator|(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::wifi::hostapd::V1_0::IHostapd::Band o);

constexpr uint32_t operator|(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& o);
static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& rhs);
static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& rhs);

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& o);
static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& rhs);
static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& rhs);

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& o);
static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& rhs);
static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& rhs);

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& o);
static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& rhs);
static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::wifi::hostapd::V1_0::IHostapd>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::SSID_MAX_LEN_IN_BYTES) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::SSID_MAX_LEN_IN_BYTES)) {
        os += (first ? "" : " | ");
        os += "SSID_MAX_LEN_IN_BYTES";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::SSID_MAX_LEN_IN_BYTES;
    }
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES)) {
        os += (first ? "" : " | ");
        os += "WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES;
    }
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES)) {
        os += (first ? "" : " | ");
        os += "WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::SSID_MAX_LEN_IN_BYTES) {
        return "SSID_MAX_LEN_IN_BYTES";
    }
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES) {
        return "WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES";
    }
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES) {
        return "WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::NONE) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::NONE)) {
        os += (first ? "" : " | ");
        os += "NONE";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::NONE;
    }
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA)) {
        os += (first ? "" : " | ");
        os += "WPA";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA;
    }
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA2) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA2)) {
        os += (first ? "" : " | ");
        os += "WPA2";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA2;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::NONE) {
        return "NONE";
    }
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA) {
        return "WPA";
    }
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA2) {
        return "WPA2";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::wifi::hostapd::V1_0::IHostapd::Band>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::hostapd::V1_0::IHostapd::Band> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_2_4_GHZ) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_2_4_GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_2_4_GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_2_4_GHZ;
    }
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_5_GHZ) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_5_GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_5_GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_5_GHZ;
    }
    if ((o & ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_ANY) == static_cast<uint32_t>(::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_ANY)) {
        os += (first ? "" : " | ");
        os += "BAND_ANY";
        first = false;
        flipped |= ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_ANY;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::wifi::hostapd::V1_0::IHostapd::Band o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_2_4_GHZ) {
        return "BAND_2_4_GHZ";
    }
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_5_GHZ) {
        return "BAND_5_GHZ";
    }
    if (o == ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_ANY) {
        return "BAND_ANY";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".enable80211N = ";
    os += ::android::hardware::toString(o.enable80211N);
    os += ", .enable80211AC = ";
    os += ::android::hardware::toString(o.enable80211AC);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& rhs) {
    if (lhs.enable80211N != rhs.enable80211N) {
        return false;
    }
    if (lhs.enable80211AC != rhs.enable80211AC) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::HwModeParams& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".enableAcs = ";
    os += ::android::hardware::toString(o.enableAcs);
    os += ", .acsShouldExcludeDfs = ";
    os += ::android::hardware::toString(o.acsShouldExcludeDfs);
    os += ", .channel = ";
    os += ::android::hardware::toString(o.channel);
    os += ", .band = ";
    os += ::android::hardware::wifi::hostapd::V1_0::toString(o.band);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& rhs) {
    if (lhs.enableAcs != rhs.enableAcs) {
        return false;
    }
    if (lhs.acsShouldExcludeDfs != rhs.acsShouldExcludeDfs) {
        return false;
    }
    if (lhs.channel != rhs.channel) {
        return false;
    }
    if (lhs.band != rhs.band) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::ChannelParams& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".ifaceName = ";
    os += ::android::hardware::toString(o.ifaceName);
    os += ", .hwModeParams = ";
    os += ::android::hardware::wifi::hostapd::V1_0::toString(o.hwModeParams);
    os += ", .channelParams = ";
    os += ::android::hardware::wifi::hostapd::V1_0::toString(o.channelParams);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& rhs) {
    if (lhs.ifaceName != rhs.ifaceName) {
        return false;
    }
    if (lhs.hwModeParams != rhs.hwModeParams) {
        return false;
    }
    if (lhs.channelParams != rhs.channelParams) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::IfaceParams& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".ssid = ";
    os += ::android::hardware::toString(o.ssid);
    os += ", .isHidden = ";
    os += ::android::hardware::toString(o.isHidden);
    os += ", .encryptionType = ";
    os += ::android::hardware::wifi::hostapd::V1_0::toString(o.encryptionType);
    os += ", .pskPassphrase = ";
    os += ::android::hardware::toString(o.pskPassphrase);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& rhs) {
    if (lhs.ssid != rhs.ssid) {
        return false;
    }
    if (lhs.isHidden != rhs.isHidden) {
        return false;
    }
    if (lhs.encryptionType != rhs.encryptionType) {
        return false;
    }
    if (lhs.pskPassphrase != rhs.pskPassphrase) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& lhs, const ::android::hardware::wifi::hostapd::V1_0::IHostapd::NetworkParams& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::wifi::hostapd::V1_0::IHostapd>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::wifi::hostapd::V1_0::IHostapd::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace hostapd
}  // namespace wifi
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits, 3> hidl_enum_values<::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits> = {
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::SSID_MAX_LEN_IN_BYTES,
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MIN_LEN_IN_BYTES,
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::ParamSizeLimits::WPA2_PSK_PASSPHRASE_MAX_LEN_IN_BYTES,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType, 3> hidl_enum_values<::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType> = {
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::NONE,
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA,
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::EncryptionType::WPA2,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::wifi::hostapd::V1_0::IHostapd::Band, 3> hidl_enum_values<::android::hardware::wifi::hostapd::V1_0::IHostapd::Band> = {
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_2_4_GHZ,
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_5_GHZ,
    ::android::hardware::wifi::hostapd::V1_0::IHostapd::Band::BAND_ANY,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_HOSTAPD_V1_0_IHOSTAPD_H
