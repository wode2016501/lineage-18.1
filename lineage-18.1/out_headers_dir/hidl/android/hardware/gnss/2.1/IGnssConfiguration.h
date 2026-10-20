#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSCONFIGURATION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSCONFIGURATION_H

#include <android/hardware/gnss/2.0/IGnssConfiguration.h>
#include <android/hardware/gnss/2.0/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V2_1 {

/**
 * Extended interface for GNSS Configuration support.
 */
struct IGnssConfiguration : public ::android::hardware::gnss::V2_0::IGnssConfiguration {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.gnss@2.1::IGnssConfiguration"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct BlacklistedSource;

    /**
     * Represents a blacklisted source, updating the GnssConstellationType to 2.0, which supports
     * IRNSS.
     */
    struct BlacklistedSource final {
        ::android::hardware::gnss::V2_0::GnssConstellationType constellation __attribute__ ((aligned(1)));
        int16_t svid __attribute__ ((aligned(2)));
    };

    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource, constellation) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource, svid) == 2, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource) == 2, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * IMPORTANT: GNSS HAL must expect the below methods to be called multiple
     * times. They can be called even when GnssLocationProvider is already
     * constructed and enabled. GNSS HAL must maintain the existing requests
     * for various callbacks regardless the change in configuration data.
     * 
     * 
     * This method enables or disables NI emergency SUPL restrictions.
     * 
     * @param enabled True if the device must only accept NI Emergency SUPL requests when the
     *                     device is truly in emergency mode (e.g. the user has dialed 911, 112,
     *                     etc...)
     *                False if the device must accept NI Emergency SUPL any time they are
     *                      received
     * 
     * @return success True if operation was successful.
     */
    virtual ::android::hardware::Return<bool> setSuplEs(bool enabled) = 0;

    /**
     * This method sets the SUPL version requested by Carrier. The GNSS HAL
     * must use this version of the SUPL protocol if supported.
     * 
     * @param version SUPL version requested by carrier. This is a bit mask
     * with bits 0:7 representing a service indicator field, bits 8:15
     * representing the minor version and bits 16:23 representing the
     * major version.
     * 
     * @return success True if operation was successful.
     */
    virtual ::android::hardware::Return<bool> setSuplVersion(uint32_t version) = 0;

    /**
     * This method sets the SUPL mode.
     * 
     * @param mode Bit mask that specifies the SUPL mode which is set with the SuplMode enum.
     * 
     * @return success True if operation was successful.
     */
    virtual ::android::hardware::Return<bool> setSuplMode(::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssConfiguration::SuplMode> mode) = 0;

    /**
     * This setting configures how GPS functionalities should be locked when
     * user turns off GPS On setting.
     * 
     * @param lock Bitmask that specifies the GPS functionalities to be be
     * locked as per the GpsLock enum.
     * 
     * @return success True if operation was successful.
     */
    virtual ::android::hardware::Return<bool> setGpsLock(::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssConfiguration::GpsLock> lock) = 0;

    /**
     * This method sets the LTE Positioning Profile configuration.
     * 
     * @param lppProfile Bitmask that specifies the LTE Positioning Profile
     * configuration to be set as per the LppProfile enum.
     * 
     * @return success True if operation was successful.
     */
    virtual ::android::hardware::Return<bool> setLppProfile(::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssConfiguration::LppProfile> lppProfile) = 0;

    /**
     * This method selects positioning protocol on A-Glonass system.
     * 
     * @param protocol Bitmask that specifies the positioning protocol to be
     * set as per GlonassPosProtocol enum.
     * 
     * @return success True if operation was successful.
     */
    virtual ::android::hardware::Return<bool> setGlonassPositioningProtocol(::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssConfiguration::GlonassPosProtocol> protocol) = 0;

    /**
     * This method configures which PDN to use.
     * 
     * @param enable Use emergency PDN if true and regular PDN if false.
     * @return success True if operation was successful.
     */
    virtual ::android::hardware::Return<bool> setEmergencySuplPdn(bool enable) = 0;

    /**
     * Injects a vector of BlacklistedSource(s) which the HAL must not use to calculate the
     * GNSS location output.
     * 
     * The superset of all satellite sources provided, including wildcards, in the latest call
     * to this method, is the set of satellites sources that must not be used in calculating
     * location.
     * 
     * All measurements from the specified satellites, across frequency bands, are blacklisted
     * together.
     * 
     * If this method is never called after the IGnssConfiguration.hal connection is made on boot,
     * or is called with an empty vector, then no satellites are to be blacklisted as a result of
     * this API.
     * 
     * This blacklist must be considered as an additional source of which satellites
     * should not be trusted for location on top of existing sources of similar information
     * such as satellite broadcast health being unhealthy and measurement outlier removal.
     * 
     * @param blacklist The BlacklistedSource(s) of satellites the HAL must not use.
     * 
     * @return success Whether the HAL accepts and abides by the provided blacklist.
     */
    virtual ::android::hardware::Return<bool> setBlacklist(const ::android::hardware::hidl_vec<::android::hardware::gnss::V1_1::IGnssConfiguration::BlacklistedSource>& blacklist) = 0;

    /**
     * This method sets the emergency session extension duration. The GNSS HAL
     * implementation must serve emergency SUPL and Control Plane network initiated
     * location requests for this extra duration after the user initiated emergency
     * session ends.
     * 
     * @param emergencyExtensionSeconds Number of seconds to extend the emergency
     * session duration post emergency call.
     * 
     * @return success True if the GNSS HAL implementation accepts and supports the
     * extended duration for emergency SUPL and Control Plane location requests.
     */
    virtual ::android::hardware::Return<bool> setEsExtensionSec(uint32_t emergencyExtensionSeconds) = 0;

    /**
     * Injects a vector of BlacklistedSource(s) which the HAL must not use to calculate the
     * GNSS location output.
     * 
     * The superset of all satellite sources provided, including wildcards, in the latest call
     * to this method, is the set of satellites sources that must not be used in calculating
     * location.
     * 
     * All measurements from the specified satellites, across frequency bands, are blacklisted
     * together.
     * 
     * If this method is never called after the IGnssConfiguration.hal connection is made on boot,
     * or is called with an empty vector, then no satellites are to be blacklisted as a result of
     * this API.
     * 
     * This blacklist must be considered as an additional source of which satellites
     * should not be trusted for location on top of existing sources of similar information
     * such as satellite broadcast health being unhealthy and measurement outlier removal.
     * 
     * @param blacklist The BlacklistedSource(s) of satellites the HAL must not use.
     * 
     * @return success Whether the HAL accepts and abides by the provided blacklist.
     */
    virtual ::android::hardware::Return<bool> setBlacklist_2_1(const ::android::hardware::hidl_vec<::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource>& blacklist) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssConfiguration>> castFrom(const ::android::sp<::android::hardware::gnss::V2_1::IGnssConfiguration>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssConfiguration>> castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IGnssConfiguration>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssConfiguration>> castFrom(const ::android::sp<::android::hardware::gnss::V1_1::IGnssConfiguration>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssConfiguration>> castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssConfiguration>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssConfiguration>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IGnssConfiguration> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssConfiguration> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssConfiguration> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssConfiguration> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IGnssConfiguration> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssConfiguration> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssConfiguration> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssConfiguration> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& o);
static inline bool operator==(const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& lhs, const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& lhs, const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_1::IGnssConfiguration>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".constellation = ";
    os += ::android::hardware::gnss::V2_0::toString(o.constellation);
    os += ", .svid = ";
    os += ::android::hardware::toString(o.svid);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& lhs, const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& rhs) {
    if (lhs.constellation != rhs.constellation) {
        return false;
    }
    if (lhs.svid != rhs.svid) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& lhs, const ::android::hardware::gnss::V2_1::IGnssConfiguration::BlacklistedSource& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_1::IGnssConfiguration>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::gnss::V2_1::IGnssConfiguration::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_1
}  // namespace gnss
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSCONFIGURATION_H
