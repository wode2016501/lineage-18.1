#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_SUPPLICANT_V1_0_ISUPPLICANTSTANETWORKCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_SUPPLICANT_V1_0_ISUPPLICANTSTANETWORKCALLBACK_H

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
namespace supplicant {
namespace V1_0 {

/**
 * Callback Interface exposed by the supplicant service
 * for each network (ISupplicantStaNetwork).
 * 
 * Clients need to host an instance of this HIDL interface object and
 * pass a reference of the object to the supplicant via the
 * corresponding |ISupplicantStaNetwork.registerCallback| method.
 */
struct ISupplicantStaNetworkCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.wifi.supplicant@1.0::ISupplicantStaNetworkCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct NetworkRequestEapSimGsmAuthParams;
    struct NetworkRequestEapSimUmtsAuthParams;

    /**
     * Params of |onNetworkEapSimGsmAuthRequest| request. (Refer RFC 4186)
     */
    typedef ::android::hardware::hidl_array<uint8_t, 16> GsmRand;

    struct NetworkRequestEapSimGsmAuthParams final {
        ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 16>> rands __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams, rands) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams) == 16, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams) == 8, "wrong alignment");

    /**
     * Params of |onNetworkEapSimUmtsAuthRequest| request. (Refer RFC 4187)
     */
    struct NetworkRequestEapSimUmtsAuthParams final {
        ::android::hardware::hidl_array<uint8_t, 16> rand __attribute__ ((aligned(1)));
        ::android::hardware::hidl_array<uint8_t, 16> autn __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams, rand) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams, autn) == 16, "wrong offset");
    static_assert(sizeof(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams) == 32, "wrong size");
    static_assert(__alignof(::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams) == 1, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Used to request EAP GSM SIM authentication for this particular network.
     * 
     * The response for the request must be sent using the corresponding
     * |ISupplicantNetwork.sendNetworkEapSimGsmAuthResponse| call.
     * 
     * @param params Params associated with the request.
     */
    virtual ::android::hardware::Return<void> onNetworkEapSimGsmAuthRequest(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& params) = 0;

    /**
     * Used to request EAP UMTS SIM authentication for this particular network.
     * 
     * The response for the request must be sent using the corresponding
     * |ISupplicantNetwork.sendNetworkEapSimUmtsAuthResponse| call.
     * 
     * @param params Params associated with the request.
     */
    virtual ::android::hardware::Return<void> onNetworkEapSimUmtsAuthRequest(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& params) = 0;

    /**
     * Used to request EAP Identity for this particular network.
     * 
     * The response for the request must be sent using the corresponding
     * |ISupplicantNetwork.sendNetworkEapIdentityResponse| call.
     */
    virtual ::android::hardware::Return<void> onNetworkEapIdentityRequest() = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback>> castFrom(const ::android::sp<::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISupplicantStaNetworkCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISupplicantStaNetworkCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISupplicantStaNetworkCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISupplicantStaNetworkCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISupplicantStaNetworkCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISupplicantStaNetworkCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISupplicantStaNetworkCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISupplicantStaNetworkCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& o);
static inline bool operator==(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& lhs, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& rhs);
static inline bool operator!=(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& lhs, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& rhs);

static inline std::string toString(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& o);
static inline bool operator==(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& lhs, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& rhs);
static inline bool operator!=(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& lhs, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".rands = ";
    os += ::android::hardware::toString(o.rands);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& lhs, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& rhs) {
    if (lhs.rands != rhs.rands) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& lhs, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimGsmAuthParams& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".rand = ";
    os += ::android::hardware::toString(o.rand);
    os += ", .autn = ";
    os += ::android::hardware::toString(o.autn);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& lhs, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& rhs) {
    if (lhs.rand != rhs.rand) {
        return false;
    }
    if (lhs.autn != rhs.autn) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& lhs, const ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::NetworkRequestEapSimUmtsAuthParams& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::wifi::supplicant::V1_0::ISupplicantStaNetworkCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace supplicant
}  // namespace wifi
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_SUPPLICANT_V1_0_ISUPPLICANTSTANETWORKCALLBACK_H
