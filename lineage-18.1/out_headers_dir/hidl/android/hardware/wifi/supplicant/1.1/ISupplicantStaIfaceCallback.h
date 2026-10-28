#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_SUPPLICANT_V1_1_ISUPPLICANTSTAIFACECALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_SUPPLICANT_V1_1_ISUPPLICANTSTAIFACECALLBACK_H

#include <android/hardware/wifi/supplicant/1.0/ISupplicantStaIfaceCallback.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace wifi {
namespace supplicant {
namespace V1_1 {

/**
 * Callback Interface exposed by the supplicant service
 * for each station mode interface (ISupplicantStaIface).
 * 
 * Clients need to host an instance of this HIDL interface object and
 * pass a reference of the object to the supplicant via the
 * corresponding |ISupplicantStaIface.registerCallback_1_1| method.
 */
struct ISupplicantStaIfaceCallback : public ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.wifi.supplicant@1.1::ISupplicantStaIfaceCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class EapErrorCode : uint32_t;

    enum class EapErrorCode : uint32_t {
        SIM_GENERAL_FAILURE_AFTER_AUTH = 0u,
        SIM_TEMPORARILY_DENIED = 1026u,
        SIM_NOT_SUBSCRIBED = 1031u,
        SIM_GENERAL_FAILURE_BEFORE_AUTH = 16384u,
        SIM_VENDOR_SPECIFIC_EXPIRED_CERT = 16385u,
    };

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Used to indicate that a new network has been added.
     * 
     * @param id Network ID allocated to the corresponding network.
     */
    virtual ::android::hardware::Return<void> onNetworkAdded(uint32_t id) = 0;

    /**
     * Used to indicate that a network has been removed.
     * 
     * @param id Network ID allocated to the corresponding network.
     */
    virtual ::android::hardware::Return<void> onNetworkRemoved(uint32_t id) = 0;

    /**
     * Used to indicate a state change event on this particular iface. If this
     * event is triggered by a particular network, the |SupplicantNetworkId|,
     * |ssid|, |bssid| parameters must indicate the parameters of the network/AP
     * which cased this state transition.
     * 
     * @param newState New State of the interface. This must be one of the |State|
     *        values above.
     * @param bssid BSSID of the corresponding AP which caused this state
     *        change event. This must be zero'ed if this event is not
     *        specific to a particular network.
     * @param id ID of the corresponding network which caused this
     *        state change event. This must be invalid (UINT32_MAX) if this
     *        event is not specific to a particular network.
     * @param ssid SSID of the corresponding network which caused this state
     *        change event. This must be empty if this event is not specific
     *        to a particular network.
     */
    virtual ::android::hardware::Return<void> onStateChanged(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::State newState, const ::android::hardware::hidl_array<uint8_t, 6>& bssid, uint32_t id, const ::android::hardware::hidl_vec<uint8_t>& ssid) = 0;

    /**
     * Used to indicate the result of ANQP (either for IEEE 802.11u Interworking
     * or Hotspot 2.0) query.
     * 
     * @param bssid BSSID of the access point.
     * @param data ANQP data fetched from the access point.
     *        All the fields in this struct must be empty if the query failed.
     * @param hs20Data ANQP data fetched from the Hotspot 2.0 access point.
     *        All the fields in this struct must be empty if the query failed.
     */
    virtual ::android::hardware::Return<void> onAnqpQueryDone(const ::android::hardware::hidl_array<uint8_t, 6>& bssid, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::AnqpData& data, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::Hs20AnqpData& hs20Data) = 0;

    /**
     * Used to indicate the result of Hotspot 2.0 Icon query.
     * 
     * @param bssid BSSID of the access point.
     * @param fileName Name of the file that was requested.
     * @param data Icon data fetched from the access point.
     *        Must be empty if the query failed.
     */
    virtual ::android::hardware::Return<void> onHs20IconQueryDone(const ::android::hardware::hidl_array<uint8_t, 6>& bssid, const ::android::hardware::hidl_string& fileName, const ::android::hardware::hidl_vec<uint8_t>& data) = 0;

    /**
     * Used to indicate a Hotspot 2.0 subscription remediation event.
     * 
     * @param bssid BSSID of the access point.
     * @param osuMethod OSU method.
     * @param url URL of the server.
     */
    virtual ::android::hardware::Return<void> onHs20SubscriptionRemediation(const ::android::hardware::hidl_array<uint8_t, 6>& bssid, ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::OsuMethod osuMethod, const ::android::hardware::hidl_string& url) = 0;

    /**
     * Used to indicate a Hotspot 2.0 imminent deauth notice.
     * 
     * @param bssid BSSID of the access point.
     * @param reasonCode Code to indicate the deauth reason.
     *        Refer to section 3.2.1.2 of the Hotspot 2.0 spec.
     * @param reAuthDelayInSec Delay before reauthenticating.
     * @param url URL of the server.
     */
    virtual ::android::hardware::Return<void> onHs20DeauthImminentNotice(const ::android::hardware::hidl_array<uint8_t, 6>& bssid, uint32_t reasonCode, uint32_t reAuthDelayInSec, const ::android::hardware::hidl_string& url) = 0;

    /**
     * Used to indicate the disconnection from the currently connected
     * network on this iface.
     * 
     * @param bssid BSSID of the AP from which we disconnected.
     * @param locallyGenerated If the disconnect was triggered by
     *        wpa_supplicant.
     * @param reasonCode 802.11 code to indicate the disconnect reason
     *        from access point. Refer to section 8.4.1.7 of IEEE802.11 spec.
     */
    virtual ::android::hardware::Return<void> onDisconnected(const ::android::hardware::hidl_array<uint8_t, 6>& bssid, bool locallyGenerated, ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::ReasonCode reasonCode) = 0;

    /**
     * Used to indicate an association rejection recieved from the AP
     * to which the connection is being attempted.
     * 
     * @param bssid BSSID of the corresponding AP which sent this
     *        reject.
     * @param statusCode 802.11 code to indicate the reject reason.
     *        Refer to section 8.4.1.9 of IEEE 802.11 spec.
     * @param timedOut Whether failure is due to timeout rather
     *        than explicit rejection response from the AP.
     */
    virtual ::android::hardware::Return<void> onAssociationRejected(const ::android::hardware::hidl_array<uint8_t, 6>& bssid, ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::StatusCode statusCode, bool timedOut) = 0;

    /**
     * Used to indicate the timeout of authentication to an AP.
     * 
     * @param bssid BSSID of the corresponding AP.
     */
    virtual ::android::hardware::Return<void> onAuthenticationTimeout(const ::android::hardware::hidl_array<uint8_t, 6>& bssid) = 0;

    /**
     * Used to indicate an EAP authentication failure.
     */
    virtual ::android::hardware::Return<void> onEapFailure() = 0;

    /**
     * Used to indicate the change of active bssid.
     * This is useful to figure out when the driver/firmware roams to a bssid
     * on its own.
     * 
     * @param reason Reason why the bssid changed.
     * @param bssid BSSID of the corresponding AP.
     */
    virtual ::android::hardware::Return<void> onBssidChanged(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::BssidChangeReason reason, const ::android::hardware::hidl_array<uint8_t, 6>& bssid) = 0;

    /**
     * Used to indicate the success of a WPS connection attempt.
     */
    virtual ::android::hardware::Return<void> onWpsEventSuccess() = 0;

    /**
     * Used to indicate the failure of a WPS connection attempt.
     * 
     * @param bssid BSSID of the AP to which we initiated WPS
     *        connection.
     * @param configError Configuration error code.
     * @param errorInd Error indication code.
     */
    virtual ::android::hardware::Return<void> onWpsEventFail(const ::android::hardware::hidl_array<uint8_t, 6>& bssid, ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::WpsConfigError configError, ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback::WpsErrorIndication errorInd) = 0;

    /**
     * Used to indicate the overlap of a WPS PBC connection attempt.
     */
    virtual ::android::hardware::Return<void> onWpsEventPbcOverlap() = 0;

    /**
     * Used to indicate that the external radio work can start now.
     * 
     * @return id Identifier generated for the radio work request.
     */
    virtual ::android::hardware::Return<void> onExtRadioWorkStart(uint32_t id) = 0;

    /**
     * Used to indicate that the external radio work request has timed out.
     * 
     * @return id Identifier generated for the radio work request.
     */
    virtual ::android::hardware::Return<void> onExtRadioWorkTimeout(uint32_t id) = 0;

    /**
     * Used to indicate an EAP authentication failure.
     */
    virtual ::android::hardware::Return<void> onEapFailure_1_1(::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode errorCode) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback>> castFrom(const ::android::sp<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback>> castFrom(const ::android::sp<::android::hardware::wifi::supplicant::V1_0::ISupplicantStaIfaceCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISupplicantStaIfaceCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISupplicantStaIfaceCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISupplicantStaIfaceCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISupplicantStaIfaceCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISupplicantStaIfaceCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISupplicantStaIfaceCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISupplicantStaIfaceCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISupplicantStaIfaceCallback> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode o);

constexpr uint32_t operator|(const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode lhs, const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode lhs, const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::sp<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_AFTER_AUTH) == static_cast<uint32_t>(::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_AFTER_AUTH)) {
        os += (first ? "" : " | ");
        os += "SIM_GENERAL_FAILURE_AFTER_AUTH";
        first = false;
        flipped |= ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_AFTER_AUTH;
    }
    if ((o & ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_TEMPORARILY_DENIED) == static_cast<uint32_t>(::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_TEMPORARILY_DENIED)) {
        os += (first ? "" : " | ");
        os += "SIM_TEMPORARILY_DENIED";
        first = false;
        flipped |= ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_TEMPORARILY_DENIED;
    }
    if ((o & ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_NOT_SUBSCRIBED) == static_cast<uint32_t>(::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_NOT_SUBSCRIBED)) {
        os += (first ? "" : " | ");
        os += "SIM_NOT_SUBSCRIBED";
        first = false;
        flipped |= ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_NOT_SUBSCRIBED;
    }
    if ((o & ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_BEFORE_AUTH) == static_cast<uint32_t>(::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_BEFORE_AUTH)) {
        os += (first ? "" : " | ");
        os += "SIM_GENERAL_FAILURE_BEFORE_AUTH";
        first = false;
        flipped |= ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_BEFORE_AUTH;
    }
    if ((o & ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_VENDOR_SPECIFIC_EXPIRED_CERT) == static_cast<uint32_t>(::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_VENDOR_SPECIFIC_EXPIRED_CERT)) {
        os += (first ? "" : " | ");
        os += "SIM_VENDOR_SPECIFIC_EXPIRED_CERT";
        first = false;
        flipped |= ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_VENDOR_SPECIFIC_EXPIRED_CERT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_AFTER_AUTH) {
        return "SIM_GENERAL_FAILURE_AFTER_AUTH";
    }
    if (o == ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_TEMPORARILY_DENIED) {
        return "SIM_TEMPORARILY_DENIED";
    }
    if (o == ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_NOT_SUBSCRIBED) {
        return "SIM_NOT_SUBSCRIBED";
    }
    if (o == ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_BEFORE_AUTH) {
        return "SIM_GENERAL_FAILURE_BEFORE_AUTH";
    }
    if (o == ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_VENDOR_SPECIFIC_EXPIRED_CERT) {
        return "SIM_VENDOR_SPECIFIC_EXPIRED_CERT";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline std::string toString(const ::android::sp<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_1
}  // namespace supplicant
}  // namespace wifi
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode, 5> hidl_enum_values<::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode> = {
    ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_AFTER_AUTH,
    ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_TEMPORARILY_DENIED,
    ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_NOT_SUBSCRIBED,
    ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_GENERAL_FAILURE_BEFORE_AUTH,
    ::android::hardware::wifi::supplicant::V1_1::ISupplicantStaIfaceCallback::EapErrorCode::SIM_VENDOR_SPECIFIC_EXPIRED_CERT,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_SUPPLICANT_V1_1_ISUPPLICANTSTAIFACECALLBACK_H
