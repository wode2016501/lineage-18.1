#ifndef HIDL_GENERATED_ANDROID_HARDWARE_GNSS_MEASUREMENT_CORRECTIONS_V1_1_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_GNSS_MEASUREMENT_CORRECTIONS_V1_1_TYPES_H

#include <android/hardware/gnss/measurement_corrections/1.0/types.h>
#include <android/hardware/gnss/2.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace gnss {
namespace measurement_corrections {
namespace V1_1 {

// Forward declaration for forward reference support:
struct MeasurementCorrections;
struct SingleSatCorrection;

/**
 * A struct containing a set of measurement corrections for all used GNSS satellites at the location
 * specified by latitudeDegrees, longitudeDegrees, altitudeMeters and at the time of week specified
 * toaGpsNanosecondsOfWeek. The v1_0.satCorrections field is deprecated and is no longer used by
 * framework.
 */
struct MeasurementCorrections final {
    ::android::hardware::gnss::measurement_corrections::V1_0::MeasurementCorrections v1_0 __attribute__ ((aligned(8)));
    bool hasEnvironmentBearing __attribute__ ((aligned(1)));
    float environmentBearingDegrees __attribute__ ((aligned(4)));
    float environmentBearingUncertaintyDegrees __attribute__ ((aligned(4)));
    ::android::hardware::hidl_vec<::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection> satCorrections __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections, v1_0) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections, hasEnvironmentBearing) == 64, "wrong offset");
static_assert(offsetof(::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections, environmentBearingDegrees) == 68, "wrong offset");
static_assert(offsetof(::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections, environmentBearingUncertaintyDegrees) == 72, "wrong offset");
static_assert(offsetof(::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections, satCorrections) == 80, "wrong offset");
static_assert(sizeof(::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections) == 96, "wrong size");
static_assert(__alignof(::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections) == 8, "wrong alignment");

/**
 * A struct with measurement corrections for a single visible satellites, updating the
 * GnssConstellationType to 2.0, which supports IRNSS. The v1_0.constellation is deprecated and is
 * no longer used by framework.
 * 
 * The bit mask singleSatCorrectionFlags indicates which correction values are valid in the struct
 */
struct SingleSatCorrection final {
    ::android::hardware::gnss::measurement_corrections::V1_0::SingleSatCorrection v1_0 __attribute__ ((aligned(8)));
    ::android::hardware::gnss::V2_0::GnssConstellationType constellation __attribute__ ((aligned(1)));
};

static_assert(offsetof(::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection, v1_0) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection, constellation) == 56, "wrong offset");
static_assert(sizeof(::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection) == 64, "wrong size");
static_assert(__alignof(::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& o);
static inline bool operator==(const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& lhs, const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& rhs);
static inline bool operator!=(const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& lhs, const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& rhs);

static inline std::string toString(const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& o);
static inline bool operator==(const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& lhs, const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& rhs);
static inline bool operator!=(const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& lhs, const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& rhs);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v1_0 = ";
    os += ::android::hardware::gnss::measurement_corrections::V1_0::toString(o.v1_0);
    os += ", .hasEnvironmentBearing = ";
    os += ::android::hardware::toString(o.hasEnvironmentBearing);
    os += ", .environmentBearingDegrees = ";
    os += ::android::hardware::toString(o.environmentBearingDegrees);
    os += ", .environmentBearingUncertaintyDegrees = ";
    os += ::android::hardware::toString(o.environmentBearingUncertaintyDegrees);
    os += ", .satCorrections = ";
    os += ::android::hardware::toString(o.satCorrections);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& lhs, const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& rhs) {
    if (lhs.v1_0 != rhs.v1_0) {
        return false;
    }
    if (lhs.hasEnvironmentBearing != rhs.hasEnvironmentBearing) {
        return false;
    }
    if (lhs.environmentBearingDegrees != rhs.environmentBearingDegrees) {
        return false;
    }
    if (lhs.environmentBearingUncertaintyDegrees != rhs.environmentBearingUncertaintyDegrees) {
        return false;
    }
    if (lhs.satCorrections != rhs.satCorrections) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& lhs, const ::android::hardware::gnss::measurement_corrections::V1_1::MeasurementCorrections& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".v1_0 = ";
    os += ::android::hardware::gnss::measurement_corrections::V1_0::toString(o.v1_0);
    os += ", .constellation = ";
    os += ::android::hardware::gnss::V2_0::toString(o.constellation);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& lhs, const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& rhs) {
    if (lhs.v1_0 != rhs.v1_0) {
        return false;
    }
    if (lhs.constellation != rhs.constellation) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& lhs, const ::android::hardware::gnss::measurement_corrections::V1_1::SingleSatCorrection& rhs){
    return !(lhs == rhs);
}


}  // namespace V1_1
}  // namespace measurement_corrections
}  // namespace gnss
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_GNSS_MEASUREMENT_CORRECTIONS_V1_1_TYPES_H
