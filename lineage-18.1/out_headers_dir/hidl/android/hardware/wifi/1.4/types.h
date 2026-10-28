#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_4_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_4_TYPES_H

#include <android/hardware/wifi/1.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_4 {

// Forward declaration for forward reference support:
enum class WifiBand : uint32_t;
enum class NanBandIndex : uint32_t;
enum class WifiRatePreamble : uint32_t;
enum class RttPreamble : uint32_t;
struct NanDebugConfig;
struct NanConfigRequest;
struct NanEnableRequest;
struct RttConfig;
struct RttCapabilities;
struct RttResponder;
struct WifiRateInfo;
struct RttResult;

/**
 * Wifi bands defined in 80211 spec.
 */
enum class WifiBand : uint32_t {
    BAND_UNSPECIFIED = 0u,
    /**
     * 2.4 GHz.
     */
    BAND_24GHZ = 1u,
    /**
     * 5 GHz without DFS.
     */
    BAND_5GHZ = 2u,
    /**
     * 5 GHz DFS only.
     */
    BAND_5GHZ_DFS = 4u,
    /**
     * 5 GHz with DFS.
     */
    BAND_5GHZ_WITH_DFS = 6u,
    /**
     * 2.4 GHz + 5 GHz; no DFS.
     */
    BAND_24GHZ_5GHZ = 3u,
    /**
     * 2.4 GHz + 5 GHz with DFS
     */
    BAND_24GHZ_5GHZ_WITH_DFS = 7u,
    /**
     * 6 GHz.
     */
    BAND_6GHZ = 8u,
    /**
     * 5 GHz no DFS + 6 GHz.
     */
    BAND_5GHZ_6GHZ = 10u,
    /**
     * 2.4 GHz + 5 GHz no DFS + 6 GHz.
     */
    BAND_24GHZ_5GHZ_6GHZ = 11u,
    /**
     * 2.4 GHz + 5 GHz with DFS + 6 GHz.
     */
    BAND_24GHZ_5GHZ_WITH_DFS_6GHZ = 15u,
};

/**
 * The discovery bands supported by NAN.
 */
enum class NanBandIndex : uint32_t {
    NAN_BAND_24GHZ = 0u,
    NAN_BAND_5GHZ = 1u /* (::android::hardware::wifi::V1_0::NanBandIndex.NAN_BAND_24GHZ implicitly + 1) */,
    /**
     * Index for 6 GHz band.
     */
    NAN_BAND_6GHZ = 2u,
};

/**
 * Wifi Rate Preamble
 */
enum class WifiRatePreamble : uint32_t {
    OFDM = 0u,
    CCK = 1u,
    HT = 2u,
    VHT = 3u,
    RESERVED = 4u,
    /**
     * Preamble type for 11ax
     */
    HE = 5u,
};

/**
 * RTT Measurement Preamble.
 */
enum class RttPreamble : uint32_t {
    LEGACY = 1u /* 0x1 */,
    HT = 2u /* 0x2 */,
    VHT = 4u /* 0x4 */,
    /**
     * Preamble type for 11ax
     */
    HE = 8u /* 0x8 */,
};

/**
 * Debug configuration parameters. Many of these allow non-standard-compliant operation and are
 * not intended for normal operational mode.
 */
struct NanDebugConfig final {
    bool validClusterIdVals __attribute__ ((aligned(1)));
    uint16_t clusterIdBottomRangeVal __attribute__ ((aligned(2)));
    uint16_t clusterIdTopRangeVal __attribute__ ((aligned(2)));
    bool validIntfAddrVal __attribute__ ((aligned(1)));
    ::android::hardware::hidl_array<uint8_t, 6> intfAddrVal __attribute__ ((aligned(1)));
    bool validOuiVal __attribute__ ((aligned(1)));
    uint32_t ouiVal __attribute__ ((aligned(4)));
    bool validRandomFactorForceVal __attribute__ ((aligned(1)));
    uint8_t randomFactorForceVal __attribute__ ((aligned(1)));
    bool validHopCountForceVal __attribute__ ((aligned(1)));
    uint8_t hopCountForceVal __attribute__ ((aligned(1)));
    bool validDiscoveryChannelVal __attribute__ ((aligned(1)));
    ::android::hardware::hidl_array<uint32_t, 3> discoveryChannelMhzVal __attribute__ ((aligned(4)));
    bool validUseBeaconsInBandVal __attribute__ ((aligned(1)));
    ::android::hardware::hidl_array<bool, 3> useBeaconsInBandVal __attribute__ ((aligned(1)));
    bool validUseSdfInBandVal __attribute__ ((aligned(1)));
    ::android::hardware::hidl_array<bool, 3> useSdfInBandVal __attribute__ ((aligned(1)));
};

static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, validClusterIdVals) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, clusterIdBottomRangeVal) == 2, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, clusterIdTopRangeVal) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, validIntfAddrVal) == 6, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, intfAddrVal) == 7, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, validOuiVal) == 13, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, ouiVal) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, validRandomFactorForceVal) == 20, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, randomFactorForceVal) == 21, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, validHopCountForceVal) == 22, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, hopCountForceVal) == 23, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, validDiscoveryChannelVal) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, discoveryChannelMhzVal) == 28, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, validUseBeaconsInBandVal) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, useBeaconsInBandVal) == 41, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, validUseSdfInBandVal) == 44, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanDebugConfig, useSdfInBandVal) == 45, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_4::NanDebugConfig) == 48, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_4::NanDebugConfig) == 4, "wrong alignment");

/**
 * Configuration parameters of NAN: used when enabling and re-configuring a NAN cluster.
 */
struct NanConfigRequest final {
    uint8_t masterPref __attribute__ ((aligned(1)));
    bool disableDiscoveryAddressChangeIndication __attribute__ ((aligned(1)));
    bool disableStartedClusterIndication __attribute__ ((aligned(1)));
    bool disableJoinedClusterIndication __attribute__ ((aligned(1)));
    bool includePublishServiceIdsInBeacon __attribute__ ((aligned(1)));
    uint8_t numberOfPublishServiceIdsInBeacon __attribute__ ((aligned(1)));
    bool includeSubscribeServiceIdsInBeacon __attribute__ ((aligned(1)));
    uint8_t numberOfSubscribeServiceIdsInBeacon __attribute__ ((aligned(1)));
    uint16_t rssiWindowSize __attribute__ ((aligned(2)));
    uint32_t macAddressRandomizationIntervalSec __attribute__ ((aligned(4)));
    ::android::hardware::hidl_array<::android::hardware::wifi::V1_0::NanBandSpecificConfig, 3> bandSpecificConfig __attribute__ ((aligned(2)));
};

static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, masterPref) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, disableDiscoveryAddressChangeIndication) == 1, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, disableStartedClusterIndication) == 2, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, disableJoinedClusterIndication) == 3, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, includePublishServiceIdsInBeacon) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, numberOfPublishServiceIdsInBeacon) == 5, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, includeSubscribeServiceIdsInBeacon) == 6, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, numberOfSubscribeServiceIdsInBeacon) == 7, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, rssiWindowSize) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, macAddressRandomizationIntervalSec) == 12, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanConfigRequest, bandSpecificConfig) == 16, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_4::NanConfigRequest) == 40, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_4::NanConfigRequest) == 4, "wrong alignment");

/**
 * Enable requests for NAN: start-up configuration |IWifiNanIface.enableRequest|.
 */
struct NanEnableRequest final {
    ::android::hardware::hidl_array<bool, 3> operateInBand __attribute__ ((aligned(1)));
    uint8_t hopCountMax __attribute__ ((aligned(1)));
    ::android::hardware::wifi::V1_4::NanConfigRequest configParams __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_4::NanDebugConfig debugConfigs __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::wifi::V1_4::NanEnableRequest, operateInBand) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanEnableRequest, hopCountMax) == 3, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanEnableRequest, configParams) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::NanEnableRequest, debugConfigs) == 44, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_4::NanEnableRequest) == 92, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_4::NanEnableRequest) == 4, "wrong alignment");

/**
 * RTT configuration.
 */
struct RttConfig final {
    ::android::hardware::hidl_array<uint8_t, 6> addr __attribute__ ((aligned(1)));
    ::android::hardware::wifi::V1_0::RttType type __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_0::RttPeerType peer __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_0::WifiChannelInfo channel __attribute__ ((aligned(4)));
    uint32_t burstPeriod __attribute__ ((aligned(4)));
    uint32_t numBurst __attribute__ ((aligned(4)));
    uint32_t numFramesPerBurst __attribute__ ((aligned(4)));
    uint32_t numRetriesPerRttFrame __attribute__ ((aligned(4)));
    uint32_t numRetriesPerFtmr __attribute__ ((aligned(4)));
    bool mustRequestLci __attribute__ ((aligned(1)));
    bool mustRequestLcr __attribute__ ((aligned(1)));
    uint32_t burstDuration __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_4::RttPreamble preamble __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_0::RttBw bw __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, addr) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, type) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, peer) == 12, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, channel) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, burstPeriod) == 32, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, numBurst) == 36, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, numFramesPerBurst) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, numRetriesPerRttFrame) == 44, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, numRetriesPerFtmr) == 48, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, mustRequestLci) == 52, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, mustRequestLcr) == 53, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, burstDuration) == 56, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, preamble) == 60, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttConfig, bw) == 64, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_4::RttConfig) == 68, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_4::RttConfig) == 4, "wrong alignment");

/**
 * RTT Capabilities.
 */
struct RttCapabilities final {
    bool rttOneSidedSupported __attribute__ ((aligned(1)));
    bool rttFtmSupported __attribute__ ((aligned(1)));
    bool lciSupported __attribute__ ((aligned(1)));
    bool lcrSupported __attribute__ ((aligned(1)));
    bool responderSupported __attribute__ ((aligned(1)));
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::V1_4::RttPreamble> preambleSupport __attribute__ ((aligned(4)));
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::V1_0::RttBw> bwSupport __attribute__ ((aligned(4)));
    uint8_t mcVersion __attribute__ ((aligned(1)));
};

static_assert(offsetof(::android::hardware::wifi::V1_4::RttCapabilities, rttOneSidedSupported) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttCapabilities, rttFtmSupported) == 1, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttCapabilities, lciSupported) == 2, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttCapabilities, lcrSupported) == 3, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttCapabilities, responderSupported) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttCapabilities, preambleSupport) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttCapabilities, bwSupport) == 12, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttCapabilities, mcVersion) == 16, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_4::RttCapabilities) == 20, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_4::RttCapabilities) == 4, "wrong alignment");

/**
 * RTT Responder information
 */
struct RttResponder final {
    ::android::hardware::wifi::V1_0::WifiChannelInfo channel __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_4::RttPreamble preamble __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::wifi::V1_4::RttResponder, channel) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResponder, preamble) == 16, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_4::RttResponder) == 20, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_4::RttResponder) == 4, "wrong alignment");

/**
 * Wifi rate info.
 */
struct WifiRateInfo final {
    ::android::hardware::wifi::V1_4::WifiRatePreamble preamble __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_0::WifiRateNss nss __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_0::WifiChannelWidthInMhz bw __attribute__ ((aligned(4)));
    uint8_t rateMcsIdx __attribute__ ((aligned(1)));
    uint32_t bitRateInKbps __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::wifi::V1_4::WifiRateInfo, preamble) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::WifiRateInfo, nss) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::WifiRateInfo, bw) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::WifiRateInfo, rateMcsIdx) == 12, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::WifiRateInfo, bitRateInKbps) == 16, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_4::WifiRateInfo) == 20, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_4::WifiRateInfo) == 4, "wrong alignment");

/**
 * RTT results.
 */
struct RttResult final {
    ::android::hardware::hidl_array<uint8_t, 6> addr __attribute__ ((aligned(1)));
    uint32_t burstNum __attribute__ ((aligned(4)));
    uint32_t measurementNumber __attribute__ ((aligned(4)));
    uint32_t successNumber __attribute__ ((aligned(4)));
    uint8_t numberPerBurstPeer __attribute__ ((aligned(1)));
    ::android::hardware::wifi::V1_0::RttStatus status __attribute__ ((aligned(4)));
    uint8_t retryAfterDuration __attribute__ ((aligned(1)));
    ::android::hardware::wifi::V1_0::RttType type __attribute__ ((aligned(4)));
    int32_t rssi __attribute__ ((aligned(4)));
    int32_t rssiSpread __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_4::WifiRateInfo txRate __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_4::WifiRateInfo rxRate __attribute__ ((aligned(4)));
    uint64_t rtt __attribute__ ((aligned(8)));
    uint64_t rttSd __attribute__ ((aligned(8)));
    uint64_t rttSpread __attribute__ ((aligned(8)));
    int32_t distanceInMm __attribute__ ((aligned(4)));
    int32_t distanceSdInMm __attribute__ ((aligned(4)));
    int32_t distanceSpreadInMm __attribute__ ((aligned(4)));
    uint64_t timeStampInUs __attribute__ ((aligned(8)));
    uint32_t burstDurationInMs __attribute__ ((aligned(4)));
    uint32_t negotiatedBurstNum __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_0::WifiInformationElement lci __attribute__ ((aligned(8)));
    ::android::hardware::wifi::V1_0::WifiInformationElement lcr __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, addr) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, burstNum) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, measurementNumber) == 12, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, successNumber) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, numberPerBurstPeer) == 20, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, status) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, retryAfterDuration) == 28, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, type) == 32, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, rssi) == 36, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, rssiSpread) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, txRate) == 44, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, rxRate) == 64, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, rtt) == 88, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, rttSd) == 96, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, rttSpread) == 104, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, distanceInMm) == 112, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, distanceSdInMm) == 116, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, distanceSpreadInMm) == 120, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, timeStampInUs) == 128, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, burstDurationInMs) == 136, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, negotiatedBurstNum) == 140, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, lci) == 144, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_4::RttResult, lcr) == 168, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_4::RttResult) == 192, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_4::RttResult) == 8, "wrong alignment");

//
// type declarations for package
//

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::wifi::V1_4::WifiBand o);

constexpr uint32_t operator|(const ::android::hardware::wifi::V1_4::WifiBand lhs, const ::android::hardware::wifi::V1_4::WifiBand rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::wifi::V1_4::WifiBand rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::wifi::V1_4::WifiBand lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::wifi::V1_4::WifiBand lhs, const ::android::hardware::wifi::V1_4::WifiBand rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::wifi::V1_4::WifiBand rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::wifi::V1_4::WifiBand lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::wifi::V1_4::WifiBand e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::wifi::V1_4::WifiBand e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::wifi::V1_4::NanBandIndex o);

constexpr uint32_t operator|(const ::android::hardware::wifi::V1_4::NanBandIndex lhs, const ::android::hardware::wifi::V1_4::NanBandIndex rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::wifi::V1_4::NanBandIndex rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::wifi::V1_4::NanBandIndex lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::wifi::V1_4::NanBandIndex lhs, const ::android::hardware::wifi::V1_4::NanBandIndex rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::wifi::V1_4::NanBandIndex rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::wifi::V1_4::NanBandIndex lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::wifi::V1_4::NanBandIndex e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::wifi::V1_4::NanBandIndex e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::wifi::V1_4::WifiRatePreamble o);

constexpr uint32_t operator|(const ::android::hardware::wifi::V1_4::WifiRatePreamble lhs, const ::android::hardware::wifi::V1_4::WifiRatePreamble rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::wifi::V1_4::WifiRatePreamble rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::wifi::V1_4::WifiRatePreamble lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::wifi::V1_4::WifiRatePreamble lhs, const ::android::hardware::wifi::V1_4::WifiRatePreamble rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::wifi::V1_4::WifiRatePreamble rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::wifi::V1_4::WifiRatePreamble lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::wifi::V1_4::WifiRatePreamble e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::wifi::V1_4::WifiRatePreamble e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::wifi::V1_4::RttPreamble o);

constexpr uint32_t operator|(const ::android::hardware::wifi::V1_4::RttPreamble lhs, const ::android::hardware::wifi::V1_4::RttPreamble rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::wifi::V1_4::RttPreamble rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::wifi::V1_4::RttPreamble lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::wifi::V1_4::RttPreamble lhs, const ::android::hardware::wifi::V1_4::RttPreamble rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::wifi::V1_4::RttPreamble rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::wifi::V1_4::RttPreamble lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::wifi::V1_4::RttPreamble e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::wifi::V1_4::RttPreamble e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::NanDebugConfig& o);
static inline bool operator==(const ::android::hardware::wifi::V1_4::NanDebugConfig& lhs, const ::android::hardware::wifi::V1_4::NanDebugConfig& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_4::NanDebugConfig& lhs, const ::android::hardware::wifi::V1_4::NanDebugConfig& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_4::NanConfigRequest& o);
static inline bool operator==(const ::android::hardware::wifi::V1_4::NanConfigRequest& lhs, const ::android::hardware::wifi::V1_4::NanConfigRequest& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_4::NanConfigRequest& lhs, const ::android::hardware::wifi::V1_4::NanConfigRequest& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_4::NanEnableRequest& o);
static inline bool operator==(const ::android::hardware::wifi::V1_4::NanEnableRequest& lhs, const ::android::hardware::wifi::V1_4::NanEnableRequest& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_4::NanEnableRequest& lhs, const ::android::hardware::wifi::V1_4::NanEnableRequest& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_4::RttConfig& o);
static inline bool operator==(const ::android::hardware::wifi::V1_4::RttConfig& lhs, const ::android::hardware::wifi::V1_4::RttConfig& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_4::RttConfig& lhs, const ::android::hardware::wifi::V1_4::RttConfig& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_4::RttCapabilities& o);
static inline bool operator==(const ::android::hardware::wifi::V1_4::RttCapabilities& lhs, const ::android::hardware::wifi::V1_4::RttCapabilities& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_4::RttCapabilities& lhs, const ::android::hardware::wifi::V1_4::RttCapabilities& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_4::RttResponder& o);
static inline bool operator==(const ::android::hardware::wifi::V1_4::RttResponder& lhs, const ::android::hardware::wifi::V1_4::RttResponder& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_4::RttResponder& lhs, const ::android::hardware::wifi::V1_4::RttResponder& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_4::WifiRateInfo& o);
static inline bool operator==(const ::android::hardware::wifi::V1_4::WifiRateInfo& lhs, const ::android::hardware::wifi::V1_4::WifiRateInfo& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_4::WifiRateInfo& lhs, const ::android::hardware::wifi::V1_4::WifiRateInfo& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_4::RttResult& o);
static inline bool operator==(const ::android::hardware::wifi::V1_4::RttResult& lhs, const ::android::hardware::wifi::V1_4::RttResult& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_4::RttResult& lhs, const ::android::hardware::wifi::V1_4::RttResult& rhs);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::wifi::V1_4::WifiBand>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::V1_4::WifiBand> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_UNSPECIFIED) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_UNSPECIFIED)) {
        os += (first ? "" : " | ");
        os += "BAND_UNSPECIFIED";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_UNSPECIFIED;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_24GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_5GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_DFS) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_DFS)) {
        os += (first ? "" : " | ");
        os += "BAND_5GHZ_DFS";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_DFS;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_WITH_DFS) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_WITH_DFS)) {
        os += (first ? "" : " | ");
        os += "BAND_5GHZ_WITH_DFS";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_WITH_DFS;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_24GHZ_5GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS)) {
        os += (first ? "" : " | ");
        os += "BAND_24GHZ_5GHZ_WITH_DFS";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_6GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_6GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_6GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_6GHZ;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_6GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_6GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_5GHZ_6GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_6GHZ;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_6GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_6GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_24GHZ_5GHZ_6GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_6GHZ;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS_6GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS_6GHZ)) {
        os += (first ? "" : " | ");
        os += "BAND_24GHZ_5GHZ_WITH_DFS_6GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS_6GHZ;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::wifi::V1_4::WifiBand o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_UNSPECIFIED) {
        return "BAND_UNSPECIFIED";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ) {
        return "BAND_24GHZ";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ) {
        return "BAND_5GHZ";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_DFS) {
        return "BAND_5GHZ_DFS";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_WITH_DFS) {
        return "BAND_5GHZ_WITH_DFS";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ) {
        return "BAND_24GHZ_5GHZ";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS) {
        return "BAND_24GHZ_5GHZ_WITH_DFS";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_6GHZ) {
        return "BAND_6GHZ";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_6GHZ) {
        return "BAND_5GHZ_6GHZ";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_6GHZ) {
        return "BAND_24GHZ_5GHZ_6GHZ";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS_6GHZ) {
        return "BAND_24GHZ_5GHZ_WITH_DFS_6GHZ";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::wifi::V1_4::NanBandIndex>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::V1_4::NanBandIndex> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_24GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_24GHZ)) {
        os += (first ? "" : " | ");
        os += "NAN_BAND_24GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_24GHZ;
    }
    if ((o & ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_5GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_5GHZ)) {
        os += (first ? "" : " | ");
        os += "NAN_BAND_5GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_5GHZ;
    }
    if ((o & ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_6GHZ) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_6GHZ)) {
        os += (first ? "" : " | ");
        os += "NAN_BAND_6GHZ";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_6GHZ;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::wifi::V1_4::NanBandIndex o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_24GHZ) {
        return "NAN_BAND_24GHZ";
    }
    if (o == ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_5GHZ) {
        return "NAN_BAND_5GHZ";
    }
    if (o == ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_6GHZ) {
        return "NAN_BAND_6GHZ";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::wifi::V1_4::WifiRatePreamble>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::V1_4::WifiRatePreamble> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::wifi::V1_4::WifiRatePreamble::OFDM) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiRatePreamble::OFDM)) {
        os += (first ? "" : " | ");
        os += "OFDM";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiRatePreamble::OFDM;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiRatePreamble::CCK) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiRatePreamble::CCK)) {
        os += (first ? "" : " | ");
        os += "CCK";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiRatePreamble::CCK;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiRatePreamble::HT) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiRatePreamble::HT)) {
        os += (first ? "" : " | ");
        os += "HT";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiRatePreamble::HT;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiRatePreamble::VHT) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiRatePreamble::VHT)) {
        os += (first ? "" : " | ");
        os += "VHT";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiRatePreamble::VHT;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiRatePreamble::RESERVED) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiRatePreamble::RESERVED)) {
        os += (first ? "" : " | ");
        os += "RESERVED";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiRatePreamble::RESERVED;
    }
    if ((o & ::android::hardware::wifi::V1_4::WifiRatePreamble::HE) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::WifiRatePreamble::HE)) {
        os += (first ? "" : " | ");
        os += "HE";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::WifiRatePreamble::HE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::wifi::V1_4::WifiRatePreamble o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::wifi::V1_4::WifiRatePreamble::OFDM) {
        return "OFDM";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiRatePreamble::CCK) {
        return "CCK";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiRatePreamble::HT) {
        return "HT";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiRatePreamble::VHT) {
        return "VHT";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiRatePreamble::RESERVED) {
        return "RESERVED";
    }
    if (o == ::android::hardware::wifi::V1_4::WifiRatePreamble::HE) {
        return "HE";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::wifi::V1_4::RttPreamble>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::wifi::V1_4::RttPreamble> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::wifi::V1_4::RttPreamble::LEGACY) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::RttPreamble::LEGACY)) {
        os += (first ? "" : " | ");
        os += "LEGACY";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::RttPreamble::LEGACY;
    }
    if ((o & ::android::hardware::wifi::V1_4::RttPreamble::HT) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::RttPreamble::HT)) {
        os += (first ? "" : " | ");
        os += "HT";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::RttPreamble::HT;
    }
    if ((o & ::android::hardware::wifi::V1_4::RttPreamble::VHT) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::RttPreamble::VHT)) {
        os += (first ? "" : " | ");
        os += "VHT";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::RttPreamble::VHT;
    }
    if ((o & ::android::hardware::wifi::V1_4::RttPreamble::HE) == static_cast<uint32_t>(::android::hardware::wifi::V1_4::RttPreamble::HE)) {
        os += (first ? "" : " | ");
        os += "HE";
        first = false;
        flipped |= ::android::hardware::wifi::V1_4::RttPreamble::HE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::wifi::V1_4::RttPreamble o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::wifi::V1_4::RttPreamble::LEGACY) {
        return "LEGACY";
    }
    if (o == ::android::hardware::wifi::V1_4::RttPreamble::HT) {
        return "HT";
    }
    if (o == ::android::hardware::wifi::V1_4::RttPreamble::VHT) {
        return "VHT";
    }
    if (o == ::android::hardware::wifi::V1_4::RttPreamble::HE) {
        return "HE";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::NanDebugConfig& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".validClusterIdVals = ";
    os += ::android::hardware::toString(o.validClusterIdVals);
    os += ", .clusterIdBottomRangeVal = ";
    os += ::android::hardware::toString(o.clusterIdBottomRangeVal);
    os += ", .clusterIdTopRangeVal = ";
    os += ::android::hardware::toString(o.clusterIdTopRangeVal);
    os += ", .validIntfAddrVal = ";
    os += ::android::hardware::toString(o.validIntfAddrVal);
    os += ", .intfAddrVal = ";
    os += ::android::hardware::toString(o.intfAddrVal);
    os += ", .validOuiVal = ";
    os += ::android::hardware::toString(o.validOuiVal);
    os += ", .ouiVal = ";
    os += ::android::hardware::toString(o.ouiVal);
    os += ", .validRandomFactorForceVal = ";
    os += ::android::hardware::toString(o.validRandomFactorForceVal);
    os += ", .randomFactorForceVal = ";
    os += ::android::hardware::toString(o.randomFactorForceVal);
    os += ", .validHopCountForceVal = ";
    os += ::android::hardware::toString(o.validHopCountForceVal);
    os += ", .hopCountForceVal = ";
    os += ::android::hardware::toString(o.hopCountForceVal);
    os += ", .validDiscoveryChannelVal = ";
    os += ::android::hardware::toString(o.validDiscoveryChannelVal);
    os += ", .discoveryChannelMhzVal = ";
    os += ::android::hardware::toString(o.discoveryChannelMhzVal);
    os += ", .validUseBeaconsInBandVal = ";
    os += ::android::hardware::toString(o.validUseBeaconsInBandVal);
    os += ", .useBeaconsInBandVal = ";
    os += ::android::hardware::toString(o.useBeaconsInBandVal);
    os += ", .validUseSdfInBandVal = ";
    os += ::android::hardware::toString(o.validUseSdfInBandVal);
    os += ", .useSdfInBandVal = ";
    os += ::android::hardware::toString(o.useSdfInBandVal);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_4::NanDebugConfig& lhs, const ::android::hardware::wifi::V1_4::NanDebugConfig& rhs) {
    if (lhs.validClusterIdVals != rhs.validClusterIdVals) {
        return false;
    }
    if (lhs.clusterIdBottomRangeVal != rhs.clusterIdBottomRangeVal) {
        return false;
    }
    if (lhs.clusterIdTopRangeVal != rhs.clusterIdTopRangeVal) {
        return false;
    }
    if (lhs.validIntfAddrVal != rhs.validIntfAddrVal) {
        return false;
    }
    if (lhs.intfAddrVal != rhs.intfAddrVal) {
        return false;
    }
    if (lhs.validOuiVal != rhs.validOuiVal) {
        return false;
    }
    if (lhs.ouiVal != rhs.ouiVal) {
        return false;
    }
    if (lhs.validRandomFactorForceVal != rhs.validRandomFactorForceVal) {
        return false;
    }
    if (lhs.randomFactorForceVal != rhs.randomFactorForceVal) {
        return false;
    }
    if (lhs.validHopCountForceVal != rhs.validHopCountForceVal) {
        return false;
    }
    if (lhs.hopCountForceVal != rhs.hopCountForceVal) {
        return false;
    }
    if (lhs.validDiscoveryChannelVal != rhs.validDiscoveryChannelVal) {
        return false;
    }
    if (lhs.discoveryChannelMhzVal != rhs.discoveryChannelMhzVal) {
        return false;
    }
    if (lhs.validUseBeaconsInBandVal != rhs.validUseBeaconsInBandVal) {
        return false;
    }
    if (lhs.useBeaconsInBandVal != rhs.useBeaconsInBandVal) {
        return false;
    }
    if (lhs.validUseSdfInBandVal != rhs.validUseSdfInBandVal) {
        return false;
    }
    if (lhs.useSdfInBandVal != rhs.useSdfInBandVal) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_4::NanDebugConfig& lhs, const ::android::hardware::wifi::V1_4::NanDebugConfig& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::NanConfigRequest& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".masterPref = ";
    os += ::android::hardware::toString(o.masterPref);
    os += ", .disableDiscoveryAddressChangeIndication = ";
    os += ::android::hardware::toString(o.disableDiscoveryAddressChangeIndication);
    os += ", .disableStartedClusterIndication = ";
    os += ::android::hardware::toString(o.disableStartedClusterIndication);
    os += ", .disableJoinedClusterIndication = ";
    os += ::android::hardware::toString(o.disableJoinedClusterIndication);
    os += ", .includePublishServiceIdsInBeacon = ";
    os += ::android::hardware::toString(o.includePublishServiceIdsInBeacon);
    os += ", .numberOfPublishServiceIdsInBeacon = ";
    os += ::android::hardware::toString(o.numberOfPublishServiceIdsInBeacon);
    os += ", .includeSubscribeServiceIdsInBeacon = ";
    os += ::android::hardware::toString(o.includeSubscribeServiceIdsInBeacon);
    os += ", .numberOfSubscribeServiceIdsInBeacon = ";
    os += ::android::hardware::toString(o.numberOfSubscribeServiceIdsInBeacon);
    os += ", .rssiWindowSize = ";
    os += ::android::hardware::toString(o.rssiWindowSize);
    os += ", .macAddressRandomizationIntervalSec = ";
    os += ::android::hardware::toString(o.macAddressRandomizationIntervalSec);
    os += ", .bandSpecificConfig = ";
    os += ::android::hardware::toString(o.bandSpecificConfig);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_4::NanConfigRequest& lhs, const ::android::hardware::wifi::V1_4::NanConfigRequest& rhs) {
    if (lhs.masterPref != rhs.masterPref) {
        return false;
    }
    if (lhs.disableDiscoveryAddressChangeIndication != rhs.disableDiscoveryAddressChangeIndication) {
        return false;
    }
    if (lhs.disableStartedClusterIndication != rhs.disableStartedClusterIndication) {
        return false;
    }
    if (lhs.disableJoinedClusterIndication != rhs.disableJoinedClusterIndication) {
        return false;
    }
    if (lhs.includePublishServiceIdsInBeacon != rhs.includePublishServiceIdsInBeacon) {
        return false;
    }
    if (lhs.numberOfPublishServiceIdsInBeacon != rhs.numberOfPublishServiceIdsInBeacon) {
        return false;
    }
    if (lhs.includeSubscribeServiceIdsInBeacon != rhs.includeSubscribeServiceIdsInBeacon) {
        return false;
    }
    if (lhs.numberOfSubscribeServiceIdsInBeacon != rhs.numberOfSubscribeServiceIdsInBeacon) {
        return false;
    }
    if (lhs.rssiWindowSize != rhs.rssiWindowSize) {
        return false;
    }
    if (lhs.macAddressRandomizationIntervalSec != rhs.macAddressRandomizationIntervalSec) {
        return false;
    }
    if (lhs.bandSpecificConfig != rhs.bandSpecificConfig) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_4::NanConfigRequest& lhs, const ::android::hardware::wifi::V1_4::NanConfigRequest& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::NanEnableRequest& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".operateInBand = ";
    os += ::android::hardware::toString(o.operateInBand);
    os += ", .hopCountMax = ";
    os += ::android::hardware::toString(o.hopCountMax);
    os += ", .configParams = ";
    os += ::android::hardware::wifi::V1_4::toString(o.configParams);
    os += ", .debugConfigs = ";
    os += ::android::hardware::wifi::V1_4::toString(o.debugConfigs);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_4::NanEnableRequest& lhs, const ::android::hardware::wifi::V1_4::NanEnableRequest& rhs) {
    if (lhs.operateInBand != rhs.operateInBand) {
        return false;
    }
    if (lhs.hopCountMax != rhs.hopCountMax) {
        return false;
    }
    if (lhs.configParams != rhs.configParams) {
        return false;
    }
    if (lhs.debugConfigs != rhs.debugConfigs) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_4::NanEnableRequest& lhs, const ::android::hardware::wifi::V1_4::NanEnableRequest& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::RttConfig& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".addr = ";
    os += ::android::hardware::toString(o.addr);
    os += ", .type = ";
    os += ::android::hardware::wifi::V1_0::toString(o.type);
    os += ", .peer = ";
    os += ::android::hardware::wifi::V1_0::toString(o.peer);
    os += ", .channel = ";
    os += ::android::hardware::wifi::V1_0::toString(o.channel);
    os += ", .burstPeriod = ";
    os += ::android::hardware::toString(o.burstPeriod);
    os += ", .numBurst = ";
    os += ::android::hardware::toString(o.numBurst);
    os += ", .numFramesPerBurst = ";
    os += ::android::hardware::toString(o.numFramesPerBurst);
    os += ", .numRetriesPerRttFrame = ";
    os += ::android::hardware::toString(o.numRetriesPerRttFrame);
    os += ", .numRetriesPerFtmr = ";
    os += ::android::hardware::toString(o.numRetriesPerFtmr);
    os += ", .mustRequestLci = ";
    os += ::android::hardware::toString(o.mustRequestLci);
    os += ", .mustRequestLcr = ";
    os += ::android::hardware::toString(o.mustRequestLcr);
    os += ", .burstDuration = ";
    os += ::android::hardware::toString(o.burstDuration);
    os += ", .preamble = ";
    os += ::android::hardware::wifi::V1_4::toString(o.preamble);
    os += ", .bw = ";
    os += ::android::hardware::wifi::V1_0::toString(o.bw);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_4::RttConfig& lhs, const ::android::hardware::wifi::V1_4::RttConfig& rhs) {
    if (lhs.addr != rhs.addr) {
        return false;
    }
    if (lhs.type != rhs.type) {
        return false;
    }
    if (lhs.peer != rhs.peer) {
        return false;
    }
    if (lhs.channel != rhs.channel) {
        return false;
    }
    if (lhs.burstPeriod != rhs.burstPeriod) {
        return false;
    }
    if (lhs.numBurst != rhs.numBurst) {
        return false;
    }
    if (lhs.numFramesPerBurst != rhs.numFramesPerBurst) {
        return false;
    }
    if (lhs.numRetriesPerRttFrame != rhs.numRetriesPerRttFrame) {
        return false;
    }
    if (lhs.numRetriesPerFtmr != rhs.numRetriesPerFtmr) {
        return false;
    }
    if (lhs.mustRequestLci != rhs.mustRequestLci) {
        return false;
    }
    if (lhs.mustRequestLcr != rhs.mustRequestLcr) {
        return false;
    }
    if (lhs.burstDuration != rhs.burstDuration) {
        return false;
    }
    if (lhs.preamble != rhs.preamble) {
        return false;
    }
    if (lhs.bw != rhs.bw) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_4::RttConfig& lhs, const ::android::hardware::wifi::V1_4::RttConfig& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::RttCapabilities& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".rttOneSidedSupported = ";
    os += ::android::hardware::toString(o.rttOneSidedSupported);
    os += ", .rttFtmSupported = ";
    os += ::android::hardware::toString(o.rttFtmSupported);
    os += ", .lciSupported = ";
    os += ::android::hardware::toString(o.lciSupported);
    os += ", .lcrSupported = ";
    os += ::android::hardware::toString(o.lcrSupported);
    os += ", .responderSupported = ";
    os += ::android::hardware::toString(o.responderSupported);
    os += ", .preambleSupport = ";
    os += ::android::hardware::wifi::V1_4::toString<::android::hardware::wifi::V1_4::RttPreamble>(o.preambleSupport);
    os += ", .bwSupport = ";
    os += ::android::hardware::wifi::V1_0::toString<::android::hardware::wifi::V1_0::RttBw>(o.bwSupport);
    os += ", .mcVersion = ";
    os += ::android::hardware::toString(o.mcVersion);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_4::RttCapabilities& lhs, const ::android::hardware::wifi::V1_4::RttCapabilities& rhs) {
    if (lhs.rttOneSidedSupported != rhs.rttOneSidedSupported) {
        return false;
    }
    if (lhs.rttFtmSupported != rhs.rttFtmSupported) {
        return false;
    }
    if (lhs.lciSupported != rhs.lciSupported) {
        return false;
    }
    if (lhs.lcrSupported != rhs.lcrSupported) {
        return false;
    }
    if (lhs.responderSupported != rhs.responderSupported) {
        return false;
    }
    if (lhs.preambleSupport != rhs.preambleSupport) {
        return false;
    }
    if (lhs.bwSupport != rhs.bwSupport) {
        return false;
    }
    if (lhs.mcVersion != rhs.mcVersion) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_4::RttCapabilities& lhs, const ::android::hardware::wifi::V1_4::RttCapabilities& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::RttResponder& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".channel = ";
    os += ::android::hardware::wifi::V1_0::toString(o.channel);
    os += ", .preamble = ";
    os += ::android::hardware::wifi::V1_4::toString(o.preamble);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_4::RttResponder& lhs, const ::android::hardware::wifi::V1_4::RttResponder& rhs) {
    if (lhs.channel != rhs.channel) {
        return false;
    }
    if (lhs.preamble != rhs.preamble) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_4::RttResponder& lhs, const ::android::hardware::wifi::V1_4::RttResponder& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::WifiRateInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".preamble = ";
    os += ::android::hardware::wifi::V1_4::toString(o.preamble);
    os += ", .nss = ";
    os += ::android::hardware::wifi::V1_0::toString(o.nss);
    os += ", .bw = ";
    os += ::android::hardware::wifi::V1_0::toString(o.bw);
    os += ", .rateMcsIdx = ";
    os += ::android::hardware::toString(o.rateMcsIdx);
    os += ", .bitRateInKbps = ";
    os += ::android::hardware::toString(o.bitRateInKbps);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_4::WifiRateInfo& lhs, const ::android::hardware::wifi::V1_4::WifiRateInfo& rhs) {
    if (lhs.preamble != rhs.preamble) {
        return false;
    }
    if (lhs.nss != rhs.nss) {
        return false;
    }
    if (lhs.bw != rhs.bw) {
        return false;
    }
    if (lhs.rateMcsIdx != rhs.rateMcsIdx) {
        return false;
    }
    if (lhs.bitRateInKbps != rhs.bitRateInKbps) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_4::WifiRateInfo& lhs, const ::android::hardware::wifi::V1_4::WifiRateInfo& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_4::RttResult& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".addr = ";
    os += ::android::hardware::toString(o.addr);
    os += ", .burstNum = ";
    os += ::android::hardware::toString(o.burstNum);
    os += ", .measurementNumber = ";
    os += ::android::hardware::toString(o.measurementNumber);
    os += ", .successNumber = ";
    os += ::android::hardware::toString(o.successNumber);
    os += ", .numberPerBurstPeer = ";
    os += ::android::hardware::toString(o.numberPerBurstPeer);
    os += ", .status = ";
    os += ::android::hardware::wifi::V1_0::toString(o.status);
    os += ", .retryAfterDuration = ";
    os += ::android::hardware::toString(o.retryAfterDuration);
    os += ", .type = ";
    os += ::android::hardware::wifi::V1_0::toString(o.type);
    os += ", .rssi = ";
    os += ::android::hardware::toString(o.rssi);
    os += ", .rssiSpread = ";
    os += ::android::hardware::toString(o.rssiSpread);
    os += ", .txRate = ";
    os += ::android::hardware::wifi::V1_4::toString(o.txRate);
    os += ", .rxRate = ";
    os += ::android::hardware::wifi::V1_4::toString(o.rxRate);
    os += ", .rtt = ";
    os += ::android::hardware::toString(o.rtt);
    os += ", .rttSd = ";
    os += ::android::hardware::toString(o.rttSd);
    os += ", .rttSpread = ";
    os += ::android::hardware::toString(o.rttSpread);
    os += ", .distanceInMm = ";
    os += ::android::hardware::toString(o.distanceInMm);
    os += ", .distanceSdInMm = ";
    os += ::android::hardware::toString(o.distanceSdInMm);
    os += ", .distanceSpreadInMm = ";
    os += ::android::hardware::toString(o.distanceSpreadInMm);
    os += ", .timeStampInUs = ";
    os += ::android::hardware::toString(o.timeStampInUs);
    os += ", .burstDurationInMs = ";
    os += ::android::hardware::toString(o.burstDurationInMs);
    os += ", .negotiatedBurstNum = ";
    os += ::android::hardware::toString(o.negotiatedBurstNum);
    os += ", .lci = ";
    os += ::android::hardware::wifi::V1_0::toString(o.lci);
    os += ", .lcr = ";
    os += ::android::hardware::wifi::V1_0::toString(o.lcr);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_4::RttResult& lhs, const ::android::hardware::wifi::V1_4::RttResult& rhs) {
    if (lhs.addr != rhs.addr) {
        return false;
    }
    if (lhs.burstNum != rhs.burstNum) {
        return false;
    }
    if (lhs.measurementNumber != rhs.measurementNumber) {
        return false;
    }
    if (lhs.successNumber != rhs.successNumber) {
        return false;
    }
    if (lhs.numberPerBurstPeer != rhs.numberPerBurstPeer) {
        return false;
    }
    if (lhs.status != rhs.status) {
        return false;
    }
    if (lhs.retryAfterDuration != rhs.retryAfterDuration) {
        return false;
    }
    if (lhs.type != rhs.type) {
        return false;
    }
    if (lhs.rssi != rhs.rssi) {
        return false;
    }
    if (lhs.rssiSpread != rhs.rssiSpread) {
        return false;
    }
    if (lhs.txRate != rhs.txRate) {
        return false;
    }
    if (lhs.rxRate != rhs.rxRate) {
        return false;
    }
    if (lhs.rtt != rhs.rtt) {
        return false;
    }
    if (lhs.rttSd != rhs.rttSd) {
        return false;
    }
    if (lhs.rttSpread != rhs.rttSpread) {
        return false;
    }
    if (lhs.distanceInMm != rhs.distanceInMm) {
        return false;
    }
    if (lhs.distanceSdInMm != rhs.distanceSdInMm) {
        return false;
    }
    if (lhs.distanceSpreadInMm != rhs.distanceSpreadInMm) {
        return false;
    }
    if (lhs.timeStampInUs != rhs.timeStampInUs) {
        return false;
    }
    if (lhs.burstDurationInMs != rhs.burstDurationInMs) {
        return false;
    }
    if (lhs.negotiatedBurstNum != rhs.negotiatedBurstNum) {
        return false;
    }
    if (lhs.lci != rhs.lci) {
        return false;
    }
    if (lhs.lcr != rhs.lcr) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_4::RttResult& lhs, const ::android::hardware::wifi::V1_4::RttResult& rhs){
    return !(lhs == rhs);
}


}  // namespace V1_4
}  // namespace wifi
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::wifi::V1_4::WifiBand, 11> hidl_enum_values<::android::hardware::wifi::V1_4::WifiBand> = {
    ::android::hardware::wifi::V1_4::WifiBand::BAND_UNSPECIFIED,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_DFS,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_WITH_DFS,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_6GHZ,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_5GHZ_6GHZ,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_6GHZ,
    ::android::hardware::wifi::V1_4::WifiBand::BAND_24GHZ_5GHZ_WITH_DFS_6GHZ,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::wifi::V1_4::NanBandIndex, 3> hidl_enum_values<::android::hardware::wifi::V1_4::NanBandIndex> = {
    ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_24GHZ,
    ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_5GHZ,
    ::android::hardware::wifi::V1_4::NanBandIndex::NAN_BAND_6GHZ,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::wifi::V1_4::WifiRatePreamble, 6> hidl_enum_values<::android::hardware::wifi::V1_4::WifiRatePreamble> = {
    ::android::hardware::wifi::V1_4::WifiRatePreamble::OFDM,
    ::android::hardware::wifi::V1_4::WifiRatePreamble::CCK,
    ::android::hardware::wifi::V1_4::WifiRatePreamble::HT,
    ::android::hardware::wifi::V1_4::WifiRatePreamble::VHT,
    ::android::hardware::wifi::V1_4::WifiRatePreamble::RESERVED,
    ::android::hardware::wifi::V1_4::WifiRatePreamble::HE,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::wifi::V1_4::RttPreamble, 4> hidl_enum_values<::android::hardware::wifi::V1_4::RttPreamble> = {
    ::android::hardware::wifi::V1_4::RttPreamble::LEGACY,
    ::android::hardware::wifi::V1_4::RttPreamble::HT,
    ::android::hardware::wifi::V1_4::RttPreamble::VHT,
    ::android::hardware::wifi::V1_4::RttPreamble::HE,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_4_TYPES_H
