#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V1_0_IGNSSMEASUREMENTCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V1_0_IGNSSMEASUREMENTCALLBACK_H

#include <android/hardware/gnss/1.0/types.h>
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
 * The callback interface to report measurements from the HAL.
 */
struct IGnssMeasurementCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.gnss@1.0::IGnssMeasurementCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class GnssClockFlags : uint16_t;
    enum class GnssMeasurementFlags : uint32_t;
    enum class GnssMultipathIndicator : uint8_t;
    enum class GnssMeasurementState : uint32_t;
    enum class GnssAccumulatedDeltaRangeState : uint16_t;
    struct GnssClock;
    struct GnssMeasurement;
    struct GnssData;

    /**
     * Flags to indicate what fields in GnssClock are valid.
     */
    enum class GnssClockFlags : uint16_t {
        /**
         * A valid 'leap second' is stored in the data structure.
         */
        HAS_LEAP_SECOND = 1 /* (1 << 0) */,
        /**
         * A valid 'time uncertainty' is stored in the data structure.
         */
        HAS_TIME_UNCERTAINTY = 2 /* (1 << 1) */,
        /**
         * A valid 'full bias' is stored in the data structure.
         */
        HAS_FULL_BIAS = 4 /* (1 << 2) */,
        /**
         * A valid 'bias' is stored in the data structure.
         */
        HAS_BIAS = 8 /* (1 << 3) */,
        /**
         * A valid 'bias uncertainty' is stored in the data structure.
         */
        HAS_BIAS_UNCERTAINTY = 16 /* (1 << 4) */,
        /**
         * A valid 'drift' is stored in the data structure.
         */
        HAS_DRIFT = 32 /* (1 << 5) */,
        /**
         * A valid 'drift uncertainty' is stored in the data structure.
         */
        HAS_DRIFT_UNCERTAINTY = 64 /* (1 << 6) */,
    };

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
    };

    /**
     * Enumeration of available values for the GNSS Measurement's multipath
     * indicator.
     */
    enum class GnssMultipathIndicator : uint8_t {
        /**
         * The indicator is not available or unknown.
         */
        INDICATOR_UNKNOWN = 0,
        /**
         * The measurement is indicated to be affected by multipath.
         */
        INDICATOR_PRESENT = 1,
        /**
         * The measurement is indicated to be not affected by multipath.
         */
        INDICATIOR_NOT_PRESENT = 2,
    };

    /**
     * Flags indicating the GNSS measurement state.
     * 
     * The expected behavior here is for GNSS HAL to set all the flags that applies.
     * For example, if the state for a satellite is only C/A code locked and bit
     * synchronized, and there is still millisecond ambiguity, the state must be
     * set as:
     * 
     * STATE_CODE_LOCK | STATE_BIT_SYNC |  STATE_MSEC_AMBIGUOUS
     * 
     * If GNSS is still searching for a satellite, the corresponding state must be
     * set to STATE_UNKNOWN(0).
     */
    enum class GnssMeasurementState : uint32_t {
        STATE_UNKNOWN = 0u,
        STATE_CODE_LOCK = 1u /* (1 << 0) */,
        STATE_BIT_SYNC = 2u /* (1 << 1) */,
        STATE_SUBFRAME_SYNC = 4u /* (1 << 2) */,
        STATE_TOW_DECODED = 8u /* (1 << 3) */,
        STATE_MSEC_AMBIGUOUS = 16u /* (1 << 4) */,
        STATE_SYMBOL_SYNC = 32u /* (1 << 5) */,
        STATE_GLO_STRING_SYNC = 64u /* (1 << 6) */,
        STATE_GLO_TOD_DECODED = 128u /* (1 << 7) */,
        STATE_BDS_D2_BIT_SYNC = 256u /* (1 << 8) */,
        STATE_BDS_D2_SUBFRAME_SYNC = 512u /* (1 << 9) */,
        STATE_GAL_E1BC_CODE_LOCK = 1024u /* (1 << 10) */,
        STATE_GAL_E1C_2ND_CODE_LOCK = 2048u /* (1 << 11) */,
        STATE_GAL_E1B_PAGE_SYNC = 4096u /* (1 << 12) */,
        STATE_SBAS_SYNC = 8192u /* (1 << 13) */,
        STATE_TOW_KNOWN = 16384u /* (1 << 14) */,
        STATE_GLO_TOD_KNOWN = 32768u /* (1 << 15) */,
    };

    /**
     * Flags indicating the Accumulated Delta Range's states.
     */
    enum class GnssAccumulatedDeltaRangeState : uint16_t {
        ADR_STATE_UNKNOWN = 0,
        ADR_STATE_VALID = 1 /* (1 << 0) */,
        ADR_STATE_RESET = 2 /* (1 << 1) */,
        ADR_STATE_CYCLE_SLIP = 4 /* (1 << 2) */,
    };

    /**
     * Represents an estimate of the GNSS clock time.
     */
    struct GnssClock final {
        ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags> gnssClockFlags __attribute__ ((aligned(2)));
        int16_t leapSecond __attribute__ ((aligned(2)));
        int64_t timeNs __attribute__ ((aligned(8)));
        double timeUncertaintyNs __attribute__ ((aligned(8)));
        int64_t fullBiasNs __attribute__ ((aligned(8)));
        double biasNs __attribute__ ((aligned(8)));
        double biasUncertaintyNs __attribute__ ((aligned(8)));
        double driftNsps __attribute__ ((aligned(8)));
        double driftUncertaintyNsps __attribute__ ((aligned(8)));
        uint32_t hwClockDiscontinuityCount __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, gnssClockFlags) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, leapSecond) == 2, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, timeNs) == 8, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, timeUncertaintyNs) == 16, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, fullBiasNs) == 24, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, biasNs) == 32, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, biasUncertaintyNs) == 40, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, driftNsps) == 48, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, driftUncertaintyNsps) == 56, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock, hwClockDiscontinuityCount) == 64, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock) == 72, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock) == 8, "wrong alignment");

    /**
     * Represents a GNSS Measurement, it contains raw and computed information.
     * 
     * All signal measurement information (e.g. svTime,
     * pseudorangeRate, multipathIndicator) reported in this struct must be
     * based on GNSS signal measurements only. You must not synthesize measurements
     * by calculating or reporting expected measurements based on known or estimated
     * position, velocity, or time.
     */
    struct GnssMeasurement final {
        ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags> flags __attribute__ ((aligned(4)));
        int16_t svid __attribute__ ((aligned(2)));
        ::android::hardware::gnss::V1_0::GnssConstellationType constellation __attribute__ ((aligned(1)));
        double timeOffsetNs __attribute__ ((aligned(8)));
        ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState> state __attribute__ ((aligned(4)));
        int64_t receivedSvTimeInNs __attribute__ ((aligned(8)));
        int64_t receivedSvTimeUncertaintyInNs __attribute__ ((aligned(8)));
        double cN0DbHz __attribute__ ((aligned(8)));
        double pseudorangeRateMps __attribute__ ((aligned(8)));
        double pseudorangeRateUncertaintyMps __attribute__ ((aligned(8)));
        ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState> accumulatedDeltaRangeState __attribute__ ((aligned(2)));
        double accumulatedDeltaRangeM __attribute__ ((aligned(8)));
        double accumulatedDeltaRangeUncertaintyM __attribute__ ((aligned(8)));
        float carrierFrequencyHz __attribute__ ((aligned(4)));
        int64_t carrierCycles __attribute__ ((aligned(8)));
        double carrierPhase __attribute__ ((aligned(8)));
        double carrierPhaseUncertainty __attribute__ ((aligned(8)));
        ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator multipathIndicator __attribute__ ((aligned(1)));
        double snrDb __attribute__ ((aligned(8)));
        double agcLevelDb __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, flags) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, svid) == 4, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, constellation) == 6, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, timeOffsetNs) == 8, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, state) == 16, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, receivedSvTimeInNs) == 24, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, receivedSvTimeUncertaintyInNs) == 32, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, cN0DbHz) == 40, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, pseudorangeRateMps) == 48, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, pseudorangeRateUncertaintyMps) == 56, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, accumulatedDeltaRangeState) == 64, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, accumulatedDeltaRangeM) == 72, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, accumulatedDeltaRangeUncertaintyM) == 80, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, carrierFrequencyHz) == 88, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, carrierCycles) == 96, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, carrierPhase) == 104, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, carrierPhaseUncertainty) == 112, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, multipathIndicator) == 120, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, snrDb) == 128, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, agcLevelDb) == 136, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement) == 144, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement) == 8, "wrong alignment");

    /**
     * Represents a reading of GNSS measurements. For devices where GnssSystemInfo's
     * yearOfHw is set to 2016+, it is mandatory that these be provided, on
     * request, when the GNSS receiver is searching/tracking signals.
     * 
     * - Reporting of GNSS constellation measurements is mandatory.
     * - Reporting of all tracked constellations are encouraged.
     */
    struct GnssData final {
        uint32_t measurementCount __attribute__ ((aligned(4)));
        ::android::hardware::hidl_array<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement, 64 /* GnssMax:SVS_COUNT */> measurements __attribute__ ((aligned(8)));
        ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock clock __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData, measurementCount) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData, measurements) == 8, "wrong offset");
    static_assert(offsetof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData, clock) == 9224, "wrong offset");
    static_assert(sizeof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData) == 9296, "wrong size");
    static_assert(__alignof(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData) == 8, "wrong alignment");

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
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurementCallback>> castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurementCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurementCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
static inline std::string toString(uint16_t o);
static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags o);

constexpr uint16_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) | static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator|(const uint16_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags rhs) {
    return static_cast<uint16_t>(lhs | static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags lhs, const uint16_t rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) | rhs);
}
constexpr uint16_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) & static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator&(const uint16_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags rhs) {
    return static_cast<uint16_t>(lhs & static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags lhs, const uint16_t rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) & rhs);
}
constexpr uint16_t &operator|=(uint16_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags e) {
    v |= static_cast<uint16_t>(e);
    return v;
}
constexpr uint16_t &operator&=(uint16_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags e) {
    v &= static_cast<uint16_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags o);

constexpr uint32_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator o);

constexpr uint8_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState o);

constexpr uint32_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint16_t o);
static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState o);

constexpr uint16_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) | static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator|(const uint16_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState rhs) {
    return static_cast<uint16_t>(lhs | static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator|(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState lhs, const uint16_t rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) | rhs);
}
constexpr uint16_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) & static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator&(const uint16_t lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState rhs) {
    return static_cast<uint16_t>(lhs & static_cast<uint16_t>(rhs));
}
constexpr uint16_t operator&(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState lhs, const uint16_t rhs) {
    return static_cast<uint16_t>(static_cast<uint16_t>(lhs) & rhs);
}
constexpr uint16_t &operator|=(uint16_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState e) {
    v |= static_cast<uint16_t>(e);
    return v;
}
constexpr uint16_t &operator&=(uint16_t& v, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState e) {
    v &= static_cast<uint16_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& o);
static inline bool operator==(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& rhs);

static inline std::string toString(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& o);
static inline bool operator==(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& rhs);

static inline std::string toString(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& o);
static inline bool operator==(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& rhs);
static inline bool operator!=(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurementCallback>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags>(uint16_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_LEAP_SECOND) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_LEAP_SECOND)) {
        os += (first ? "" : " | ");
        os += "HAS_LEAP_SECOND";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_LEAP_SECOND;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_TIME_UNCERTAINTY) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_TIME_UNCERTAINTY)) {
        os += (first ? "" : " | ");
        os += "HAS_TIME_UNCERTAINTY";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_TIME_UNCERTAINTY;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_FULL_BIAS) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_FULL_BIAS)) {
        os += (first ? "" : " | ");
        os += "HAS_FULL_BIAS";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_FULL_BIAS;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS)) {
        os += (first ? "" : " | ");
        os += "HAS_BIAS";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS_UNCERTAINTY) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS_UNCERTAINTY)) {
        os += (first ? "" : " | ");
        os += "HAS_BIAS_UNCERTAINTY";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS_UNCERTAINTY;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT)) {
        os += (first ? "" : " | ");
        os += "HAS_DRIFT";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT_UNCERTAINTY) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT_UNCERTAINTY)) {
        os += (first ? "" : " | ");
        os += "HAS_DRIFT_UNCERTAINTY";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT_UNCERTAINTY;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_LEAP_SECOND) {
        return "HAS_LEAP_SECOND";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_TIME_UNCERTAINTY) {
        return "HAS_TIME_UNCERTAINTY";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_FULL_BIAS) {
        return "HAS_FULL_BIAS";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS) {
        return "HAS_BIAS";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS_UNCERTAINTY) {
        return "HAS_BIAS_UNCERTAINTY";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT) {
        return "HAS_DRIFT";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT_UNCERTAINTY) {
        return "HAS_DRIFT_UNCERTAINTY";
    }
    std::string os;
    os += toHexString(static_cast<uint16_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR)) {
        os += (first ? "" : " | ");
        os += "HAS_SNR";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY)) {
        os += (first ? "" : " | ");
        os += "HAS_CARRIER_FREQUENCY";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES)) {
        os += (first ? "" : " | ");
        os += "HAS_CARRIER_CYCLES";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE)) {
        os += (first ? "" : " | ");
        os += "HAS_CARRIER_PHASE";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY)) {
        os += (first ? "" : " | ");
        os += "HAS_CARRIER_PHASE_UNCERTAINTY";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL)) {
        os += (first ? "" : " | ");
        os += "HAS_AUTOMATIC_GAIN_CONTROL";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR) {
        return "HAS_SNR";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY) {
        return "HAS_CARRIER_FREQUENCY";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES) {
        return "HAS_CARRIER_CYCLES";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE) {
        return "HAS_CARRIER_PHASE";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY) {
        return "HAS_CARRIER_PHASE_UNCERTAINTY";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL) {
        return "HAS_AUTOMATIC_GAIN_CONTROL";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_UNKNOWN) == static_cast<uint8_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "INDICATOR_UNKNOWN";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_UNKNOWN;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_PRESENT) == static_cast<uint8_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_PRESENT)) {
        os += (first ? "" : " | ");
        os += "INDICATOR_PRESENT";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_PRESENT;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATIOR_NOT_PRESENT) == static_cast<uint8_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATIOR_NOT_PRESENT)) {
        os += (first ? "" : " | ");
        os += "INDICATIOR_NOT_PRESENT";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATIOR_NOT_PRESENT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_UNKNOWN) {
        return "INDICATOR_UNKNOWN";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_PRESENT) {
        return "INDICATOR_PRESENT";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATIOR_NOT_PRESENT) {
        return "INDICATIOR_NOT_PRESENT";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_UNKNOWN) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "STATE_UNKNOWN";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_UNKNOWN;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_CODE_LOCK) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_CODE_LOCK)) {
        os += (first ? "" : " | ");
        os += "STATE_CODE_LOCK";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_CODE_LOCK;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BIT_SYNC) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BIT_SYNC)) {
        os += (first ? "" : " | ");
        os += "STATE_BIT_SYNC";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BIT_SYNC;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SUBFRAME_SYNC) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SUBFRAME_SYNC)) {
        os += (first ? "" : " | ");
        os += "STATE_SUBFRAME_SYNC";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SUBFRAME_SYNC;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_DECODED) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_DECODED)) {
        os += (first ? "" : " | ");
        os += "STATE_TOW_DECODED";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_DECODED;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_MSEC_AMBIGUOUS) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_MSEC_AMBIGUOUS)) {
        os += (first ? "" : " | ");
        os += "STATE_MSEC_AMBIGUOUS";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_MSEC_AMBIGUOUS;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SYMBOL_SYNC) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SYMBOL_SYNC)) {
        os += (first ? "" : " | ");
        os += "STATE_SYMBOL_SYNC";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SYMBOL_SYNC;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_STRING_SYNC) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_STRING_SYNC)) {
        os += (first ? "" : " | ");
        os += "STATE_GLO_STRING_SYNC";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_STRING_SYNC;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_DECODED) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_DECODED)) {
        os += (first ? "" : " | ");
        os += "STATE_GLO_TOD_DECODED";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_DECODED;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_BIT_SYNC) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_BIT_SYNC)) {
        os += (first ? "" : " | ");
        os += "STATE_BDS_D2_BIT_SYNC";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_BIT_SYNC;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_SUBFRAME_SYNC) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_SUBFRAME_SYNC)) {
        os += (first ? "" : " | ");
        os += "STATE_BDS_D2_SUBFRAME_SYNC";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_SUBFRAME_SYNC;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1BC_CODE_LOCK) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1BC_CODE_LOCK)) {
        os += (first ? "" : " | ");
        os += "STATE_GAL_E1BC_CODE_LOCK";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1BC_CODE_LOCK;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1C_2ND_CODE_LOCK) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1C_2ND_CODE_LOCK)) {
        os += (first ? "" : " | ");
        os += "STATE_GAL_E1C_2ND_CODE_LOCK";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1C_2ND_CODE_LOCK;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1B_PAGE_SYNC) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1B_PAGE_SYNC)) {
        os += (first ? "" : " | ");
        os += "STATE_GAL_E1B_PAGE_SYNC";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1B_PAGE_SYNC;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SBAS_SYNC) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SBAS_SYNC)) {
        os += (first ? "" : " | ");
        os += "STATE_SBAS_SYNC";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SBAS_SYNC;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_KNOWN) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_KNOWN)) {
        os += (first ? "" : " | ");
        os += "STATE_TOW_KNOWN";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_KNOWN;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_KNOWN) == static_cast<uint32_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_KNOWN)) {
        os += (first ? "" : " | ");
        os += "STATE_GLO_TOD_KNOWN";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_KNOWN;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_UNKNOWN) {
        return "STATE_UNKNOWN";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_CODE_LOCK) {
        return "STATE_CODE_LOCK";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BIT_SYNC) {
        return "STATE_BIT_SYNC";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SUBFRAME_SYNC) {
        return "STATE_SUBFRAME_SYNC";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_DECODED) {
        return "STATE_TOW_DECODED";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_MSEC_AMBIGUOUS) {
        return "STATE_MSEC_AMBIGUOUS";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SYMBOL_SYNC) {
        return "STATE_SYMBOL_SYNC";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_STRING_SYNC) {
        return "STATE_GLO_STRING_SYNC";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_DECODED) {
        return "STATE_GLO_TOD_DECODED";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_BIT_SYNC) {
        return "STATE_BDS_D2_BIT_SYNC";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_SUBFRAME_SYNC) {
        return "STATE_BDS_D2_SUBFRAME_SYNC";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1BC_CODE_LOCK) {
        return "STATE_GAL_E1BC_CODE_LOCK";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1C_2ND_CODE_LOCK) {
        return "STATE_GAL_E1C_2ND_CODE_LOCK";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1B_PAGE_SYNC) {
        return "STATE_GAL_E1B_PAGE_SYNC";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SBAS_SYNC) {
        return "STATE_SBAS_SYNC";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_KNOWN) {
        return "STATE_TOW_KNOWN";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_KNOWN) {
        return "STATE_GLO_TOD_KNOWN";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState>(uint16_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_UNKNOWN) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "ADR_STATE_UNKNOWN";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_UNKNOWN;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_VALID) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_VALID)) {
        os += (first ? "" : " | ");
        os += "ADR_STATE_VALID";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_VALID;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_RESET) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_RESET)) {
        os += (first ? "" : " | ");
        os += "ADR_STATE_RESET";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_RESET;
    }
    if ((o & ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_CYCLE_SLIP) == static_cast<uint16_t>(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_CYCLE_SLIP)) {
        os += (first ? "" : " | ");
        os += "ADR_STATE_CYCLE_SLIP";
        first = false;
        flipped |= ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_CYCLE_SLIP;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_UNKNOWN) {
        return "ADR_STATE_UNKNOWN";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_VALID) {
        return "ADR_STATE_VALID";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_RESET) {
        return "ADR_STATE_RESET";
    }
    if (o == ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_CYCLE_SLIP) {
        return "ADR_STATE_CYCLE_SLIP";
    }
    std::string os;
    os += toHexString(static_cast<uint16_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".gnssClockFlags = ";
    os += ::android::hardware::gnss::V1_0::toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags>(o.gnssClockFlags);
    os += ", .leapSecond = ";
    os += ::android::hardware::toString(o.leapSecond);
    os += ", .timeNs = ";
    os += ::android::hardware::toString(o.timeNs);
    os += ", .timeUncertaintyNs = ";
    os += ::android::hardware::toString(o.timeUncertaintyNs);
    os += ", .fullBiasNs = ";
    os += ::android::hardware::toString(o.fullBiasNs);
    os += ", .biasNs = ";
    os += ::android::hardware::toString(o.biasNs);
    os += ", .biasUncertaintyNs = ";
    os += ::android::hardware::toString(o.biasUncertaintyNs);
    os += ", .driftNsps = ";
    os += ::android::hardware::toString(o.driftNsps);
    os += ", .driftUncertaintyNsps = ";
    os += ::android::hardware::toString(o.driftUncertaintyNsps);
    os += ", .hwClockDiscontinuityCount = ";
    os += ::android::hardware::toString(o.hwClockDiscontinuityCount);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& rhs) {
    if (lhs.gnssClockFlags != rhs.gnssClockFlags) {
        return false;
    }
    if (lhs.leapSecond != rhs.leapSecond) {
        return false;
    }
    if (lhs.timeNs != rhs.timeNs) {
        return false;
    }
    if (lhs.timeUncertaintyNs != rhs.timeUncertaintyNs) {
        return false;
    }
    if (lhs.fullBiasNs != rhs.fullBiasNs) {
        return false;
    }
    if (lhs.biasNs != rhs.biasNs) {
        return false;
    }
    if (lhs.biasUncertaintyNs != rhs.biasUncertaintyNs) {
        return false;
    }
    if (lhs.driftNsps != rhs.driftNsps) {
        return false;
    }
    if (lhs.driftUncertaintyNsps != rhs.driftUncertaintyNsps) {
        return false;
    }
    if (lhs.hwClockDiscontinuityCount != rhs.hwClockDiscontinuityCount) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClock& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".flags = ";
    os += ::android::hardware::gnss::V1_0::toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags>(o.flags);
    os += ", .svid = ";
    os += ::android::hardware::toString(o.svid);
    os += ", .constellation = ";
    os += ::android::hardware::gnss::V1_0::toString(o.constellation);
    os += ", .timeOffsetNs = ";
    os += ::android::hardware::toString(o.timeOffsetNs);
    os += ", .state = ";
    os += ::android::hardware::gnss::V1_0::toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState>(o.state);
    os += ", .receivedSvTimeInNs = ";
    os += ::android::hardware::toString(o.receivedSvTimeInNs);
    os += ", .receivedSvTimeUncertaintyInNs = ";
    os += ::android::hardware::toString(o.receivedSvTimeUncertaintyInNs);
    os += ", .cN0DbHz = ";
    os += ::android::hardware::toString(o.cN0DbHz);
    os += ", .pseudorangeRateMps = ";
    os += ::android::hardware::toString(o.pseudorangeRateMps);
    os += ", .pseudorangeRateUncertaintyMps = ";
    os += ::android::hardware::toString(o.pseudorangeRateUncertaintyMps);
    os += ", .accumulatedDeltaRangeState = ";
    os += ::android::hardware::gnss::V1_0::toString<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState>(o.accumulatedDeltaRangeState);
    os += ", .accumulatedDeltaRangeM = ";
    os += ::android::hardware::toString(o.accumulatedDeltaRangeM);
    os += ", .accumulatedDeltaRangeUncertaintyM = ";
    os += ::android::hardware::toString(o.accumulatedDeltaRangeUncertaintyM);
    os += ", .carrierFrequencyHz = ";
    os += ::android::hardware::toString(o.carrierFrequencyHz);
    os += ", .carrierCycles = ";
    os += ::android::hardware::toString(o.carrierCycles);
    os += ", .carrierPhase = ";
    os += ::android::hardware::toString(o.carrierPhase);
    os += ", .carrierPhaseUncertainty = ";
    os += ::android::hardware::toString(o.carrierPhaseUncertainty);
    os += ", .multipathIndicator = ";
    os += ::android::hardware::gnss::V1_0::toString(o.multipathIndicator);
    os += ", .snrDb = ";
    os += ::android::hardware::toString(o.snrDb);
    os += ", .agcLevelDb = ";
    os += ::android::hardware::toString(o.agcLevelDb);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& rhs) {
    if (lhs.flags != rhs.flags) {
        return false;
    }
    if (lhs.svid != rhs.svid) {
        return false;
    }
    if (lhs.constellation != rhs.constellation) {
        return false;
    }
    if (lhs.timeOffsetNs != rhs.timeOffsetNs) {
        return false;
    }
    if (lhs.state != rhs.state) {
        return false;
    }
    if (lhs.receivedSvTimeInNs != rhs.receivedSvTimeInNs) {
        return false;
    }
    if (lhs.receivedSvTimeUncertaintyInNs != rhs.receivedSvTimeUncertaintyInNs) {
        return false;
    }
    if (lhs.cN0DbHz != rhs.cN0DbHz) {
        return false;
    }
    if (lhs.pseudorangeRateMps != rhs.pseudorangeRateMps) {
        return false;
    }
    if (lhs.pseudorangeRateUncertaintyMps != rhs.pseudorangeRateUncertaintyMps) {
        return false;
    }
    if (lhs.accumulatedDeltaRangeState != rhs.accumulatedDeltaRangeState) {
        return false;
    }
    if (lhs.accumulatedDeltaRangeM != rhs.accumulatedDeltaRangeM) {
        return false;
    }
    if (lhs.accumulatedDeltaRangeUncertaintyM != rhs.accumulatedDeltaRangeUncertaintyM) {
        return false;
    }
    if (lhs.carrierFrequencyHz != rhs.carrierFrequencyHz) {
        return false;
    }
    if (lhs.carrierCycles != rhs.carrierCycles) {
        return false;
    }
    if (lhs.carrierPhase != rhs.carrierPhase) {
        return false;
    }
    if (lhs.carrierPhaseUncertainty != rhs.carrierPhaseUncertainty) {
        return false;
    }
    if (lhs.multipathIndicator != rhs.multipathIndicator) {
        return false;
    }
    if (lhs.snrDb != rhs.snrDb) {
        return false;
    }
    if (lhs.agcLevelDb != rhs.agcLevelDb) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurement& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".measurementCount = ";
    os += ::android::hardware::toString(o.measurementCount);
    os += ", .measurements = ";
    os += ::android::hardware::toString(o.measurements);
    os += ", .clock = ";
    os += ::android::hardware::gnss::V1_0::toString(o.clock);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& rhs) {
    if (lhs.measurementCount != rhs.measurementCount) {
        return false;
    }
    if (lhs.measurements != rhs.measurements) {
        return false;
    }
    if (lhs.clock != rhs.clock) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& lhs, const ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssData& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurementCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::descriptor;
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
template<> constexpr std::array<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags, 7> hidl_enum_values<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags> = {
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_LEAP_SECOND,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_TIME_UNCERTAINTY,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_FULL_BIAS,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_BIAS_UNCERTAINTY,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssClockFlags::HAS_DRIFT_UNCERTAINTY,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags, 6> hidl_enum_values<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags> = {
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_SNR,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_FREQUENCY,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_CYCLES,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_CARRIER_PHASE_UNCERTAINTY,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementFlags::HAS_AUTOMATIC_GAIN_CONTROL,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator, 3> hidl_enum_values<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator> = {
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_UNKNOWN,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATOR_PRESENT,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMultipathIndicator::INDICATIOR_NOT_PRESENT,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState, 17> hidl_enum_values<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState> = {
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_UNKNOWN,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_CODE_LOCK,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BIT_SYNC,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SUBFRAME_SYNC,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_DECODED,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_MSEC_AMBIGUOUS,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SYMBOL_SYNC,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_STRING_SYNC,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_DECODED,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_BIT_SYNC,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_BDS_D2_SUBFRAME_SYNC,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1BC_CODE_LOCK,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1C_2ND_CODE_LOCK,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GAL_E1B_PAGE_SYNC,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_SBAS_SYNC,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_TOW_KNOWN,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssMeasurementState::STATE_GLO_TOD_KNOWN,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState, 4> hidl_enum_values<::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState> = {
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_UNKNOWN,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_VALID,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_RESET,
    ::android::hardware::gnss::V1_0::IGnssMeasurementCallback::GnssAccumulatedDeltaRangeState::ADR_STATE_CYCLE_SLIP,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_V1_0_IGNSSMEASUREMENTCALLBACK_H
