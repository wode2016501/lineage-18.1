#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSMEASUREMENTCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSMEASUREMENTCALLBACK_H

#include <android/hardware/gnss/1.0/IGnssMeasurementCallback.h>
#include <android/hardware/gnss/2.0/IGnssMeasurementCallback.h>
#include <android/hardware/gnss/2.0/types.h>
#include <android/hardware/gnss/2.1/types.h>

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
 * The callback interface to report measurements from the HAL.
 */
struct IGnssMeasurementCallback : public ::android::hardware::gnss::V2_0::IGnssMeasurementCallback {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.gnss@2.1::IGnssMeasurementCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class GnssMeasurementFlags : uint32_t;
    struct GnssMeasurement;
    struct GnssClock;
    struct GnssData;

    /**
     * Flags to indicate what fields in GnssMeasurement are valid.
     */
    enum class GnssMeasurementFlags : uint32_t {
        /**
         * A valid 'snr' is stored in the data structure.
         */
        HAS_SNR = 1u /* (1 << 0) */,
        /**
         * A valid 'carrier frequency' is stored in the data structure.
         */
        HAS_CARRIER_FREQUENCY = 512u /* (1 << 9) */,
        /**
         * A valid 'carrier cycles' is stored in the data structure.
         */
        HAS_CARRIER_CYCLES = 1024u /* (1 << 10) */,
        /**
         * A valid 'carrier phase' is stored in the data structure.
         */
        HAS_CARRIER_PHASE = 2048u /* (1 << 11) */,
        /**
         * A valid 'carrier phase uncertainty' is stored in the data structure.
         */
        HAS_CARRIER_PHASE_UNCERTAINTY = 4096u /* (1 << 12) */,
        /**
         * A valid automatic gain control is stored in the data structure.
         */
        HAS_AUTOMATIC_GAIN_CONTROL = 8192u /* (1 << 13) */,
        /**
         * A valid full inter-signal bias is stored in the data structure.
         */
        HAS_FULL_ISB = 65536u /* (1 << 16) */,
        /**
         * A valid full inter-signal bias uncertainty is stored in the data structure.
         */
        HAS_FULL_ISB_UNCERTAINTY = 131072u /* (1 << 17) */,
        /**
         * A valid satellite inter-signal bias is stored in the data structure.
         */
        HAS_SATELLITE_ISB = 262144u /* (1 << 18) */,
        /**
         * A valid satellite inter-signal bias uncertainty is stored in the data structure.
         */
        HAS_SATELLITE_ISB_UNCERTAINTY = 524288u /* (1 << 19) */,
    };

    /**
     * Extends a GNSS Measurement, adding basebandCN0DbHz, GnssMeasurementFlags,
     * receiverInterSignalBiasNs, receiverInterSignalBiasUncertaintyNs, satelliteInterSignalBiasNs
     * and satelliteInterSignalBiasUncertaintyNs.
     */
    struct GnssMeasurement final {
        ::android::hardware::gnss::V2_0::IGnssMeasurementCallback::GnssMeasurement v2_0 __attribute__ ((aligned(8)));
        ::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags> flags __attribute__ ((aligned(4)));
        double fullInterSignalBiasNs __attribute__ ((aligned(8)));
        double fullInterSignalBiasUncertaintyNs __attribute__ ((aligned(8)));
        double satelliteInterSignalBiasNs __attribute__ ((aligned(8)));
        double satelliteInterSignalBiasUncertaintyNs __attribute__ ((aligned(8)));
        double basebandCN0DbHz __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement, v2_0) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement, flags) == 176, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement, fullInterSignalBiasNs) == 184, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement, fullInterSignalBiasUncertaintyNs) == 192, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement, satelliteInterSignalBiasNs) == 200, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement, satelliteInterSignalBiasUncertaintyNs) == 208, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement, basebandCN0DbHz) == 216, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement) == 224, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement) == 8, "wrong alignment");

    /**
     * Extends a GNSS clock time, adding a referenceSignalTypeForIsb.
     */
    struct GnssClock final {
        ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock v1_0 __attribute__ ((aligned(8)));
        ::android::hardware::gnss::V2_1::GnssSignalType referenceSignalTypeForIsb __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock, v1_0) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock, referenceSignalTypeForIsb) == 72, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock) == 104, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock) == 8, "wrong alignment");

    /**
     * Complete set of GNSS Measurement data, same as 2.0 with additional fields in measurements.
     */
    struct GnssData final {
        ::android::hardware::hidl_vec<::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement> measurements __attribute__ ((aligned(8)));
        ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock clock __attribute__ ((aligned(8)));
        ::android::hardware::gnss::V2_0::ElapsedRealtime elapsedRealtime __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData, measurements) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData, clock) == 16, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData, elapsedRealtime) == 120, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData) == 144, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Callback for the hal to pass a GnssData structure back to the client.
     * 
     * @param data Contains a reading of GNSS measurements.
     */
    virtual ::android::hardware::Return<void> GnssMeasurementCb(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& data) = 0;

    /**
     * Callback for the hal to pass a GnssData structure back to the client.
     * 
     * @param data Contains a reading of GNSS measurements.
     */
    virtual ::android::hardware::Return<void> gnssMeasurementCb(const ::android::hardware::gnss::V1_1::IGnssMeasurementCallback::GnssData& data) = 0;

    /**
     * Callback for the hal to pass a GnssData structure back to the client.
     * 
     * @param data Contains a reading of GNSS measurements.
     */
    virtual ::android::hardware::Return<void> gnssMeasurementCb_2_0(const ::android::hardware::gnss::V2_0::IGnssMeasurementCallback::GnssData& data) = 0;

    /**
     * Callback for the hal to pass a GnssData structure back to the client.
     * 
     * @param data Contains a reading of GNSS measurements.
     */
    virtual ::android::hardware::Return<void> gnssMeasurementCb_2_1(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& data) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssMeasurementCallback>> castFrom(const ::android::sp<::android::hardware::gnss::V2_1::IGnssMeasurementCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssMeasurementCallback>> castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurementCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssMeasurementCallback>> castFrom(const ::android::sp<::android::hardware::gnss::V1_1::IGnssMeasurementCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssMeasurementCallback>> castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurementCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_1::IGnssMeasurementCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IGnssMeasurementCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssMeasurementCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGnssMeasurementCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssMeasurementCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IGnssMeasurementCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssMeasurementCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGnssMeasurementCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGnssMeasurementCallback> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags o);

constexpr uint32_t operator|(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& o);
static inline bool operator==(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& rhs);

static inline std::string toString(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& o);
static inline bool operator==(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& rhs);

static inline std::string toString(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& o);
static inline bool operator==(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_1::IGnssMeasurementCallback>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR)) {
        os += (first ? "" : " | ");
        os += "HAS_SNR";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY)) {
        os += (first ? "" : " | ");
        os += "HAS_CARRIER_FREQUENCY";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES)) {
        os += (first ? "" : " | ");
        os += "HAS_CARRIER_CYCLES";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE)) {
        os += (first ? "" : " | ");
        os += "HAS_CARRIER_PHASE";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY)) {
        os += (first ? "" : " | ");
        os += "HAS_CARRIER_PHASE_UNCERTAINTY";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL)) {
        os += (first ? "" : " | ");
        os += "HAS_AUTOMATIC_GAIN_CONTROL";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB)) {
        os += (first ? "" : " | ");
        os += "HAS_FULL_ISB";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB_UNCERTAINTY) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB_UNCERTAINTY)) {
        os += (first ? "" : " | ");
        os += "HAS_FULL_ISB_UNCERTAINTY";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB_UNCERTAINTY;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB)) {
        os += (first ? "" : " | ");
        os += "HAS_SATELLITE_ISB";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB;
    }
    if ((o & ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB_UNCERTAINTY) == static_cast<uint32_t>(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB_UNCERTAINTY)) {
        os += (first ? "" : " | ");
        os += "HAS_SATELLITE_ISB_UNCERTAINTY";
        first = false;
        flipped |= ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB_UNCERTAINTY;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR) {
        return "HAS_SNR";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY) {
        return "HAS_CARRIER_FREQUENCY";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES) {
        return "HAS_CARRIER_CYCLES";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE) {
        return "HAS_CARRIER_PHASE";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY) {
        return "HAS_CARRIER_PHASE_UNCERTAINTY";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL) {
        return "HAS_AUTOMATIC_GAIN_CONTROL";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB) {
        return "HAS_FULL_ISB";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB_UNCERTAINTY) {
        return "HAS_FULL_ISB_UNCERTAINTY";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB) {
        return "HAS_SATELLITE_ISB";
    }
    if (o == ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB_UNCERTAINTY) {
        return "HAS_SATELLITE_ISB_UNCERTAINTY";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v2_0 = ";
    os += ::android::hardware::gnss::V2_0::toString(o.v2_0);
    os += ", .flags = ";
    os += ::android::hardware::gnss::V2_1::toString<::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags>(o.flags);
    os += ", .fullInterSignalBiasNs = ";
    os += ::android::hardware::toString(o.fullInterSignalBiasNs);
    os += ", .fullInterSignalBiasUncertaintyNs = ";
    os += ::android::hardware::toString(o.fullInterSignalBiasUncertaintyNs);
    os += ", .satelliteInterSignalBiasNs = ";
    os += ::android::hardware::toString(o.satelliteInterSignalBiasNs);
    os += ", .satelliteInterSignalBiasUncertaintyNs = ";
    os += ::android::hardware::toString(o.satelliteInterSignalBiasUncertaintyNs);
    os += ", .basebandCN0DbHz = ";
    os += ::android::hardware::toString(o.basebandCN0DbHz);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& rhs) {
    if (lhs.v2_0 != rhs.v2_0) {
        return false;
    }
    if (lhs.flags != rhs.flags) {
        return false;
    }
    if (lhs.fullInterSignalBiasNs != rhs.fullInterSignalBiasNs) {
        return false;
    }
    if (lhs.fullInterSignalBiasUncertaintyNs != rhs.fullInterSignalBiasUncertaintyNs) {
        return false;
    }
    if (lhs.satelliteInterSignalBiasNs != rhs.satelliteInterSignalBiasNs) {
        return false;
    }
    if (lhs.satelliteInterSignalBiasUncertaintyNs != rhs.satelliteInterSignalBiasUncertaintyNs) {
        return false;
    }
    if (lhs.basebandCN0DbHz != rhs.basebandCN0DbHz) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurement& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v1_0 = ";
    os += ::android::hardware::gnss::V1_0::toString(o.v1_0);
    os += ", .referenceSignalTypeForIsb = ";
    os += ::android::hardware::gnss::V2_1::toString(o.referenceSignalTypeForIsb);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& rhs) {
    if (lhs.v1_0 != rhs.v1_0) {
        return false;
    }
    if (lhs.referenceSignalTypeForIsb != rhs.referenceSignalTypeForIsb) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssClock& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".measurements = ";
    os += ::android::hardware::toString(o.measurements);
    os += ", .clock = ";
    os += ::android::hardware::gnss::V2_1::toString(o.clock);
    os += ", .elapsedRealtime = ";
    os += ::android::hardware::gnss::V2_0::toString(o.elapsedRealtime);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& rhs) {
    if (lhs.measurements != rhs.measurements) {
        return false;
    }
    if (lhs.clock != rhs.clock) {
        return false;
    }
    if (lhs.elapsedRealtime != rhs.elapsedRealtime) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& lhs, const ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssData& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V2_1::IGnssMeasurementCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::descriptor;
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
template<> constexpr std::array<::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags, 10> hidl_enum_values<::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags> = {
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_FULL_ISB_UNCERTAINTY,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB,
    ::android::hardware::gnss::V2_1::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SATELLITE_ISB_UNCERTAINTY,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V2_1_IGNSSMEASUREMENTCALLBACK_H
