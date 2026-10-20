#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_0_IGNSSDEBUG_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_0_IGNSSDEBUG_H

#include <android/hardware/gnss/1.0/IGnssDebug.h>
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
namespace V2_0 {

/**
 * Extended interface for DEBUG support.
 */
struct IGnssDebug : public ::android::hardware::gnss::V1_0::IGnssDebug {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.gnss@2.0::IGnssDebug"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct SatelliteData;
    struct DebugData;

    /**
     * Extending SatelliteData, replacing the GnssConstellationType.
     */
    struct SatelliteData final {
        ::android::hardware::gnss::V1_0::IGnssDebug::SatelliteData v1_0 __attribute__ ((aligned(4)));
        ::android::hardware::gnss::V2_0::GnssConstellationType constellation __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData, v1_0) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData, constellation) == 20, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData) == 4, "wrong alignment");

    /**
     * Provides a set of debug information that is filled by the GNSS chipset when the method
     * getDebugData() is invoked.
     */
    struct DebugData final {
        ::android::hardware::gnss::V1_0::IGnssDebug::PositionDebug position __attribute__ ((aligned(8)));
        ::android::hardware::gnss::V1_0::IGnssDebug::TimeDebug time __attribute__ ((aligned(8)));
        ::android::hardware::hidl_vec<::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData> satelliteDataArray __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::gnss::V2_0::IGnssDebug::DebugData, position) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_0::IGnssDebug::DebugData, time) == 80, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_0::IGnssDebug::DebugData, satelliteDataArray) == 96, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V2_0::IGnssDebug::DebugData) == 112, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V2_0::IGnssDebug::DebugData) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getDebugData
     */
    using getDebugData_cb = std::function<void(const ::android::hardware::gnss::V1_0::IGnssDebug::DebugData& debugData)>;
    /**
     * This methods requests position, time and satellite ephemeris debug information
     * from the HAL.
     * 
     * @return ret debugData information from GNSS Hal that contains the current best
     * known position, best known time estimate and a complete list of
     * constellations that the device can track.
     */
    virtual ::android::hardware::Return<void> getDebugData(getDebugData_cb _hidl_cb) = 0;

    /**
     * Return callback for getDebugData_2_0
     */
    using getDebugData_2_0_cb = std::function<void(const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& debugData)>;
    /**
     * This methods requests position, time and satellite ephemeris debug information from the HAL.
     * 
     * @return ret debugData information from GNSS Hal that contains the current best known
     * position, best known time estimate and a complete list of constellations that the device can
     * track.
     */
    virtual ::android::hardware::Return<void> getDebugData_2_0(getDebugData_2_0_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssDebug>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IGnssDebug> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssDebug> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssDebug> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssDebug> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IGnssDebug> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssDebug> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssDebug> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssDebug> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& o);
static inline bool operator==(const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& lhs, const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& lhs, const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& rhs);

static inline std::string toString(const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& o);
static inline bool operator==(const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& lhs, const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& lhs, const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v1_0 = ";
    os += ::android::hardware::gnss::V1_0::toString(o.v1_0);
    os += ", .constellation = ";
    os += ::android::hardware::gnss::V2_0::toString(o.constellation);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& lhs, const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& rhs) {
    if (lhs.v1_0 != rhs.v1_0) {
        return false;
    }
    if (lhs.constellation != rhs.constellation) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& lhs, const ::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".position = ";
    os += ::android::hardware::gnss::V1_0::toString(o.position);
    os += ", .time = ";
    os += ::android::hardware::gnss::V1_0::toString(o.time);
    os += ", .satelliteDataArray = ";
    os += ::android::hardware::toString(o.satelliteDataArray);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& lhs, const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& rhs) {
    if (lhs.position != rhs.position) {
        return false;
    }
    if (lhs.time != rhs.time) {
        return false;
    }
    if (lhs.satelliteDataArray != rhs.satelliteDataArray) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& lhs, const ::android::hardware::gnss::V2_0::IGnssDebug::DebugData& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::gnss::V2_0::IGnssDebug::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_0_IGNSSDEBUG_H
