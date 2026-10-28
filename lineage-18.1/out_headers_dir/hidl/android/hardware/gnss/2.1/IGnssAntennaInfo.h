#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSANTENNAINFO_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSANTENNAINFO_H

#include <android/hardware/gnss/2.1/IGnssAntennaInfoCallback.h>
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
namespace V2_1 {

/**
 * Extended interface for GNSS antenna information support.
 */
struct IGnssAntennaInfo : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.gnss@2.1::IGnssAntennaInfo"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class GnssAntennaInfoStatus : int32_t;

    enum class GnssAntennaInfoStatus : int32_t {
        SUCCESS = 0,
        ERROR_ALREADY_INIT = -100 /* (-100) */,
        ERROR_GENERIC = -101 /* (-101) */,
    };

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Registers the callback routines with the HAL.
     * 
     * @param callback Handle to the GnssAntennaInfo callback interface.
     */
    virtual ::android::hardware::Return<::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus> setCallback(const ::android::sp<::android::hardware::gnss::V2_1::IGnssAntennaInfoCallback>& callback) = 0;

    /**
     * Stops updates from the HAL, and unregisters the callback routines.
     * After a call to close(), the previously registered callbacks must be
     * considered invalid by the HAL.
     * If close() is invoked without a previous setCallback, this function must perform
     * no work.
     */
    virtual ::android::hardware::Return<void> close() = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssAntennaInfo>> castFrom(const ::android::sp<::android::hardware::gnss::V2_1::IGnssAntennaInfo>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssAntennaInfo>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IGnssAntennaInfo> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssAntennaInfo> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssAntennaInfo> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssAntennaInfo> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IGnssAntennaInfo> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssAntennaInfo> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssAntennaInfo> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssAntennaInfo> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus o);

constexpr int32_t operator|(const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus lhs, const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus lhs, const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_1::IGnssAntennaInfo>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::SUCCESS) == static_cast<int32_t>(::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::SUCCESS)) {
        os += (first ? "" : " | ");
        os += "SUCCESS";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::SUCCESS;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_ALREADY_INIT) == static_cast<int32_t>(::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_ALREADY_INIT)) {
        os += (first ? "" : " | ");
        os += "ERROR_ALREADY_INIT";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_ALREADY_INIT;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_GENERIC) == static_cast<int32_t>(::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_GENERIC)) {
        os += (first ? "" : " | ");
        os += "ERROR_GENERIC";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_GENERIC;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::SUCCESS) {
        return "SUCCESS";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_ALREADY_INIT) {
        return "ERROR_ALREADY_INIT";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_GENERIC) {
        return "ERROR_GENERIC";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_1::IGnssAntennaInfo>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::gnss::V2_1::IGnssAntennaInfo::descriptor;
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

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus, 3> hidl_enum_values<::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus> = {
    ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::SUCCESS,
    ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_ALREADY_INIT,
    ::android::hardware::gnss::V2_1::IGnssAntennaInfo::GnssAntennaInfoStatus::ERROR_GENERIC,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSANTENNAINFO_H
