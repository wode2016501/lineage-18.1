#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_2_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_2_TYPES_H

#include <android/hardware/wifi/1.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_2 {

// Forward declaration for forward reference support:
struct NanConfigRequestSupplemental;
struct NanDataPathChannelInfo;
struct NanDataPathConfirmInd;
struct NanDataPathScheduleUpdateInd;

/**
 * NAN configuration request parameters added in the 1.2 HAL. These are supplemental to previous
 * versions.
 */
struct NanConfigRequestSupplemental final {
    uint32_t discoveryBeaconIntervalMs __attribute__ ((aligned(4)));
    uint32_t numberOfSpatialStreamsInDiscovery __attribute__ ((aligned(4)));
    bool enableDiscoveryWindowEarlyTermination __attribute__ ((aligned(1)));
    bool enableRanging __attribute__ ((aligned(1)));
};

static_assert(offsetof(::android::hardware::wifi::V1_2::NanConfigRequestSupplemental, discoveryBeaconIntervalMs) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_2::NanConfigRequestSupplemental, numberOfSpatialStreamsInDiscovery) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_2::NanConfigRequestSupplemental, enableDiscoveryWindowEarlyTermination) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_2::NanConfigRequestSupplemental, enableRanging) == 9, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_2::NanConfigRequestSupplemental) == 12, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_2::NanConfigRequestSupplemental) == 4, "wrong alignment");

/**
 * NAN data path channel information provided to the framework.
 */
struct NanDataPathChannelInfo final {
    uint32_t channelFreq __attribute__ ((aligned(4)));
    ::android::hardware::wifi::V1_0::WifiChannelWidthInMhz channelBandwidth __attribute__ ((aligned(4)));
    uint32_t numSpatialStreams __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::wifi::V1_2::NanDataPathChannelInfo, channelFreq) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_2::NanDataPathChannelInfo, channelBandwidth) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_2::NanDataPathChannelInfo, numSpatialStreams) == 8, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_2::NanDataPathChannelInfo) == 12, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_2::NanDataPathChannelInfo) == 4, "wrong alignment");

/**
 * NAN Data path confirmation Indication structure.
 * Event indication is received on both initiator and responder side when negotiation for a
 * data-path finish: on success or failure.
 */
struct NanDataPathConfirmInd final {
    ::android::hardware::wifi::V1_0::NanDataPathConfirmInd V1_0 __attribute__ ((aligned(8)));
    ::android::hardware::hidl_vec<::android::hardware::wifi::V1_2::NanDataPathChannelInfo> channelInfo __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::wifi::V1_2::NanDataPathConfirmInd, V1_0) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_2::NanDataPathConfirmInd, channelInfo) == 56, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_2::NanDataPathConfirmInd) == 72, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_2::NanDataPathConfirmInd) == 8, "wrong alignment");

/**
 * NAN data path channel information update indication structure.
 * Event indication is received by all NDP owners whenever the channels on which the NDP operates
 * are updated.
 * Note: multiple NDPs may share the same schedule, the indication specifies all NDPs to which it
 * applies.
 */
struct NanDataPathScheduleUpdateInd final {
    ::android::hardware::hidl_array<uint8_t, 6> peerDiscoveryAddress __attribute__ ((aligned(1)));
    ::android::hardware::hidl_vec<::android::hardware::wifi::V1_2::NanDataPathChannelInfo> channelInfo __attribute__ ((aligned(8)));
    ::android::hardware::hidl_vec<uint32_t> ndpInstanceIds __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd, peerDiscoveryAddress) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd, channelInfo) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd, ndpInstanceIds) == 24, "wrong offset");
static_assert(sizeof(::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd) == 40, "wrong size");
static_assert(__alignof(::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& o);
static inline bool operator==(const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& lhs, const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& lhs, const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& o);
static inline bool operator==(const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& lhs, const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& lhs, const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& o);
static inline bool operator==(const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& lhs, const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& lhs, const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& rhs);

static inline std::string toString(const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& o);
static inline bool operator==(const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& lhs, const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& rhs);
static inline bool operator!=(const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& lhs, const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& rhs);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".discoveryBeaconIntervalMs = ";
    os += ::android::hardware::toString(o.discoveryBeaconIntervalMs);
    os += ", .numberOfSpatialStreamsInDiscovery = ";
    os += ::android::hardware::toString(o.numberOfSpatialStreamsInDiscovery);
    os += ", .enableDiscoveryWindowEarlyTermination = ";
    os += ::android::hardware::toString(o.enableDiscoveryWindowEarlyTermination);
    os += ", .enableRanging = ";
    os += ::android::hardware::toString(o.enableRanging);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& lhs, const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& rhs) {
    if (lhs.discoveryBeaconIntervalMs != rhs.discoveryBeaconIntervalMs) {
        return false;
    }
    if (lhs.numberOfSpatialStreamsInDiscovery != rhs.numberOfSpatialStreamsInDiscovery) {
        return false;
    }
    if (lhs.enableDiscoveryWindowEarlyTermination != rhs.enableDiscoveryWindowEarlyTermination) {
        return false;
    }
    if (lhs.enableRanging != rhs.enableRanging) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& lhs, const ::android::hardware::wifi::V1_2::NanConfigRequestSupplemental& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".channelFreq = ";
    os += ::android::hardware::toString(o.channelFreq);
    os += ", .channelBandwidth = ";
    os += ::android::hardware::wifi::V1_0::toString(o.channelBandwidth);
    os += ", .numSpatialStreams = ";
    os += ::android::hardware::toString(o.numSpatialStreams);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& lhs, const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& rhs) {
    if (lhs.channelFreq != rhs.channelFreq) {
        return false;
    }
    if (lhs.channelBandwidth != rhs.channelBandwidth) {
        return false;
    }
    if (lhs.numSpatialStreams != rhs.numSpatialStreams) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& lhs, const ::android::hardware::wifi::V1_2::NanDataPathChannelInfo& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".V1_0 = ";
    os += ::android::hardware::wifi::V1_0::toString(o.V1_0);
    os += ", .channelInfo = ";
    os += ::android::hardware::toString(o.channelInfo);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& lhs, const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& rhs) {
    if (lhs.V1_0 != rhs.V1_0) {
        return false;
    }
    if (lhs.channelInfo != rhs.channelInfo) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& lhs, const ::android::hardware::wifi::V1_2::NanDataPathConfirmInd& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".peerDiscoveryAddress = ";
    os += ::android::hardware::toString(o.peerDiscoveryAddress);
    os += ", .channelInfo = ";
    os += ::android::hardware::toString(o.channelInfo);
    os += ", .ndpInstanceIds = ";
    os += ::android::hardware::toString(o.ndpInstanceIds);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& lhs, const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& rhs) {
    if (lhs.peerDiscoveryAddress != rhs.peerDiscoveryAddress) {
        return false;
    }
    if (lhs.channelInfo != rhs.channelInfo) {
        return false;
    }
    if (lhs.ndpInstanceIds != rhs.ndpInstanceIds) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& lhs, const ::android::hardware::wifi::V1_2::NanDataPathScheduleUpdateInd& rhs){
    return !(lhs == rhs);
}


}  // namespace V1_2
}  // namespace wifi
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_2_TYPES_H
