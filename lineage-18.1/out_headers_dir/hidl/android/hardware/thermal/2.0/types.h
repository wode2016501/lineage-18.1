#ifndef HIDL_GENERATED_ANDROID_HARDWARE_THERMAL_V2_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_THERMAL_V2_0_TYPES_H

#include <android/hardware/thermal/1.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace thermal {
namespace V2_0 {

// Forward declaration for forward reference support:
enum class TemperatureType : int32_t;
enum class CoolingType : uint32_t;
enum class ThrottlingSeverity : uint32_t;
struct TemperatureThreshold;
struct Temperature;
struct CoolingDevice;

/**
 * Device temperature types
 */
enum class TemperatureType : int32_t {
    UNKNOWN = -1 /* (-1) */,
    CPU = 0,
    GPU = 1,
    BATTERY = 2,
    SKIN = 3,
    USB_PORT = 4,
    POWER_AMPLIFIER = 5,
    /**
     * Battery Charge Limit - virtual thermal sensors
     */
    BCL_VOLTAGE = 6,
    BCL_CURRENT = 7,
    BCL_PERCENTAGE = 8,
    /**
     * Neural Processing Unit
     */
    NPU = 9,
};

/**
 * Device cooling device types
 */
enum class CoolingType : uint32_t {
    FAN = 0u,
    BATTERY = 1u /* (::android::hardware::thermal::V2_0::CoolingType.FAN implicitly + 1) */,
    CPU = 2u /* (::android::hardware::thermal::V2_0::CoolingType.BATTERY implicitly + 1) */,
    GPU = 3u /* (::android::hardware::thermal::V2_0::CoolingType.CPU implicitly + 1) */,
    MODEM = 4u /* (::android::hardware::thermal::V2_0::CoolingType.GPU implicitly + 1) */,
    NPU = 5u /* (::android::hardware::thermal::V2_0::CoolingType.MODEM implicitly + 1) */,
    COMPONENT = 6u /* (::android::hardware::thermal::V2_0::CoolingType.NPU implicitly + 1) */,
};

/**
 * Device throttling severity
 */
enum class ThrottlingSeverity : uint32_t {
    /**
     * Not under throttling.
     */
    NONE = 0u,
    /**
     * Light throttling where UX is not impacted.
     */
    LIGHT = 1u /* (::android::hardware::thermal::V2_0::ThrottlingSeverity.NONE implicitly + 1) */,
    /**
     * Moderate throttling where UX is not largely impacted.
     */
    MODERATE = 2u /* (::android::hardware::thermal::V2_0::ThrottlingSeverity.LIGHT implicitly + 1) */,
    /**
     * Severe throttling where UX is largely impacted.
     * Similar to 1.0 throttlingThreshold.
     */
    SEVERE = 3u /* (::android::hardware::thermal::V2_0::ThrottlingSeverity.MODERATE implicitly + 1) */,
    /**
     * Platform has done everything to reduce power.
     */
    CRITICAL = 4u /* (::android::hardware::thermal::V2_0::ThrottlingSeverity.SEVERE implicitly + 1) */,
    /**
     * Key components in platform are shutting down due to thermal condition.
     * Device functionalities will be limited.
     */
    EMERGENCY = 5u /* (::android::hardware::thermal::V2_0::ThrottlingSeverity.CRITICAL implicitly + 1) */,
    /**
     * Need shutdown immediately.
     */
    SHUTDOWN = 6u /* (::android::hardware::thermal::V2_0::ThrottlingSeverity.EMERGENCY implicitly + 1) */,
};

struct TemperatureThreshold final {
    ::android::hardware::thermal::V2_0::TemperatureType type __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string name __attribute__ ((aligned(8)));
    ::android::hardware::hidl_array<float, 7 /* ThrottlingSeverity#len */> hotThrottlingThresholds __attribute__ ((aligned(4)));
    ::android::hardware::hidl_array<float, 7 /* ThrottlingSeverity#len */> coldThrottlingThresholds __attribute__ ((aligned(4)));
    float vrThrottlingThreshold __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::thermal::V2_0::TemperatureThreshold, type) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::TemperatureThreshold, name) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::TemperatureThreshold, hotThrottlingThresholds) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::TemperatureThreshold, coldThrottlingThresholds) == 52, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::TemperatureThreshold, vrThrottlingThreshold) == 80, "wrong offset");
static_assert(sizeof(::android::hardware::thermal::V2_0::TemperatureThreshold) == 88, "wrong size");
static_assert(__alignof(::android::hardware::thermal::V2_0::TemperatureThreshold) == 8, "wrong alignment");

struct Temperature final {
    ::android::hardware::thermal::V2_0::TemperatureType type __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string name __attribute__ ((aligned(8)));
    float value __attribute__ ((aligned(4)));
    ::android::hardware::thermal::V2_0::ThrottlingSeverity throttlingStatus __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::thermal::V2_0::Temperature, type) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::Temperature, name) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::Temperature, value) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::Temperature, throttlingStatus) == 28, "wrong offset");
static_assert(sizeof(::android::hardware::thermal::V2_0::Temperature) == 32, "wrong size");
static_assert(__alignof(::android::hardware::thermal::V2_0::Temperature) == 8, "wrong alignment");

struct CoolingDevice final {
    ::android::hardware::thermal::V2_0::CoolingType type __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string name __attribute__ ((aligned(8)));
    uint64_t value __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::thermal::V2_0::CoolingDevice, type) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::CoolingDevice, name) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::thermal::V2_0::CoolingDevice, value) == 24, "wrong offset");
static_assert(sizeof(::android::hardware::thermal::V2_0::CoolingDevice) == 32, "wrong size");
static_assert(__alignof(::android::hardware::thermal::V2_0::CoolingDevice) == 8, "wrong alignment");

//
// type declarations for package
//

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::thermal::V2_0::TemperatureType o);

constexpr int32_t operator|(const ::android::hardware::thermal::V2_0::TemperatureType lhs, const ::android::hardware::thermal::V2_0::TemperatureType rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::thermal::V2_0::TemperatureType rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::thermal::V2_0::TemperatureType lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::thermal::V2_0::TemperatureType lhs, const ::android::hardware::thermal::V2_0::TemperatureType rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::thermal::V2_0::TemperatureType rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::thermal::V2_0::TemperatureType lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::thermal::V2_0::TemperatureType e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::thermal::V2_0::TemperatureType e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::thermal::V2_0::CoolingType o);

constexpr uint32_t operator|(const ::android::hardware::thermal::V2_0::CoolingType lhs, const ::android::hardware::thermal::V2_0::CoolingType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::thermal::V2_0::CoolingType rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::thermal::V2_0::CoolingType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::thermal::V2_0::CoolingType lhs, const ::android::hardware::thermal::V2_0::CoolingType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::thermal::V2_0::CoolingType rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::thermal::V2_0::CoolingType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::thermal::V2_0::CoolingType e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::thermal::V2_0::CoolingType e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::thermal::V2_0::ThrottlingSeverity o);

constexpr uint32_t operator|(const ::android::hardware::thermal::V2_0::ThrottlingSeverity lhs, const ::android::hardware::thermal::V2_0::ThrottlingSeverity rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::thermal::V2_0::ThrottlingSeverity rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::thermal::V2_0::ThrottlingSeverity lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::thermal::V2_0::ThrottlingSeverity lhs, const ::android::hardware::thermal::V2_0::ThrottlingSeverity rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::thermal::V2_0::ThrottlingSeverity rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::thermal::V2_0::ThrottlingSeverity lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::thermal::V2_0::ThrottlingSeverity e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::thermal::V2_0::ThrottlingSeverity e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::thermal::V2_0::TemperatureThreshold& o);
static inline bool operator==(const ::android::hardware::thermal::V2_0::TemperatureThreshold& lhs, const ::android::hardware::thermal::V2_0::TemperatureThreshold& rhs);
static inline bool operator!=(const ::android::hardware::thermal::V2_0::TemperatureThreshold& lhs, const ::android::hardware::thermal::V2_0::TemperatureThreshold& rhs);

static inline std::string toString(const ::android::hardware::thermal::V2_0::Temperature& o);
static inline bool operator==(const ::android::hardware::thermal::V2_0::Temperature& lhs, const ::android::hardware::thermal::V2_0::Temperature& rhs);
static inline bool operator!=(const ::android::hardware::thermal::V2_0::Temperature& lhs, const ::android::hardware::thermal::V2_0::Temperature& rhs);

static inline std::string toString(const ::android::hardware::thermal::V2_0::CoolingDevice& o);
static inline bool operator==(const ::android::hardware::thermal::V2_0::CoolingDevice& lhs, const ::android::hardware::thermal::V2_0::CoolingDevice& rhs);
static inline bool operator!=(const ::android::hardware::thermal::V2_0::CoolingDevice& lhs, const ::android::hardware::thermal::V2_0::CoolingDevice& rhs);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::thermal::V2_0::TemperatureType>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::thermal::V2_0::TemperatureType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::UNKNOWN) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::UNKNOWN;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::CPU) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::CPU)) {
        os += (first ? "" : " | ");
        os += "CPU";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::CPU;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::GPU) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::GPU)) {
        os += (first ? "" : " | ");
        os += "GPU";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::GPU;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::BATTERY) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::BATTERY)) {
        os += (first ? "" : " | ");
        os += "BATTERY";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::BATTERY;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::SKIN) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::SKIN)) {
        os += (first ? "" : " | ");
        os += "SKIN";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::SKIN;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::USB_PORT) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::USB_PORT)) {
        os += (first ? "" : " | ");
        os += "USB_PORT";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::USB_PORT;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::POWER_AMPLIFIER) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::POWER_AMPLIFIER)) {
        os += (first ? "" : " | ");
        os += "POWER_AMPLIFIER";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::POWER_AMPLIFIER;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::BCL_VOLTAGE) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::BCL_VOLTAGE)) {
        os += (first ? "" : " | ");
        os += "BCL_VOLTAGE";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::BCL_VOLTAGE;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::BCL_CURRENT) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::BCL_CURRENT)) {
        os += (first ? "" : " | ");
        os += "BCL_CURRENT";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::BCL_CURRENT;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::BCL_PERCENTAGE) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::BCL_PERCENTAGE)) {
        os += (first ? "" : " | ");
        os += "BCL_PERCENTAGE";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::BCL_PERCENTAGE;
    }
    if ((o & ::android::hardware::thermal::V2_0::TemperatureType::NPU) == static_cast<int32_t>(::android::hardware::thermal::V2_0::TemperatureType::NPU)) {
        os += (first ? "" : " | ");
        os += "NPU";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::TemperatureType::NPU;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::thermal::V2_0::TemperatureType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::UNKNOWN) {
        return "UNKNOWN";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::CPU) {
        return "CPU";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::GPU) {
        return "GPU";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::BATTERY) {
        return "BATTERY";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::SKIN) {
        return "SKIN";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::USB_PORT) {
        return "USB_PORT";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::POWER_AMPLIFIER) {
        return "POWER_AMPLIFIER";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::BCL_VOLTAGE) {
        return "BCL_VOLTAGE";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::BCL_CURRENT) {
        return "BCL_CURRENT";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::BCL_PERCENTAGE) {
        return "BCL_PERCENTAGE";
    }
    if (o == ::android::hardware::thermal::V2_0::TemperatureType::NPU) {
        return "NPU";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::thermal::V2_0::CoolingType>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::thermal::V2_0::CoolingType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::thermal::V2_0::CoolingType::FAN) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::CoolingType::FAN)) {
        os += (first ? "" : " | ");
        os += "FAN";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::CoolingType::FAN;
    }
    if ((o & ::android::hardware::thermal::V2_0::CoolingType::BATTERY) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::CoolingType::BATTERY)) {
        os += (first ? "" : " | ");
        os += "BATTERY";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::CoolingType::BATTERY;
    }
    if ((o & ::android::hardware::thermal::V2_0::CoolingType::CPU) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::CoolingType::CPU)) {
        os += (first ? "" : " | ");
        os += "CPU";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::CoolingType::CPU;
    }
    if ((o & ::android::hardware::thermal::V2_0::CoolingType::GPU) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::CoolingType::GPU)) {
        os += (first ? "" : " | ");
        os += "GPU";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::CoolingType::GPU;
    }
    if ((o & ::android::hardware::thermal::V2_0::CoolingType::MODEM) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::CoolingType::MODEM)) {
        os += (first ? "" : " | ");
        os += "MODEM";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::CoolingType::MODEM;
    }
    if ((o & ::android::hardware::thermal::V2_0::CoolingType::NPU) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::CoolingType::NPU)) {
        os += (first ? "" : " | ");
        os += "NPU";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::CoolingType::NPU;
    }
    if ((o & ::android::hardware::thermal::V2_0::CoolingType::COMPONENT) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::CoolingType::COMPONENT)) {
        os += (first ? "" : " | ");
        os += "COMPONENT";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::CoolingType::COMPONENT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::thermal::V2_0::CoolingType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::thermal::V2_0::CoolingType::FAN) {
        return "FAN";
    }
    if (o == ::android::hardware::thermal::V2_0::CoolingType::BATTERY) {
        return "BATTERY";
    }
    if (o == ::android::hardware::thermal::V2_0::CoolingType::CPU) {
        return "CPU";
    }
    if (o == ::android::hardware::thermal::V2_0::CoolingType::GPU) {
        return "GPU";
    }
    if (o == ::android::hardware::thermal::V2_0::CoolingType::MODEM) {
        return "MODEM";
    }
    if (o == ::android::hardware::thermal::V2_0::CoolingType::NPU) {
        return "NPU";
    }
    if (o == ::android::hardware::thermal::V2_0::CoolingType::COMPONENT) {
        return "COMPONENT";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::thermal::V2_0::ThrottlingSeverity>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::thermal::V2_0::ThrottlingSeverity> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::thermal::V2_0::ThrottlingSeverity::NONE) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::ThrottlingSeverity::NONE)) {
        os += (first ? "" : " | ");
        os += "NONE";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::ThrottlingSeverity::NONE;
    }
    if ((o & ::android::hardware::thermal::V2_0::ThrottlingSeverity::LIGHT) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::ThrottlingSeverity::LIGHT)) {
        os += (first ? "" : " | ");
        os += "LIGHT";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::ThrottlingSeverity::LIGHT;
    }
    if ((o & ::android::hardware::thermal::V2_0::ThrottlingSeverity::MODERATE) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::ThrottlingSeverity::MODERATE)) {
        os += (first ? "" : " | ");
        os += "MODERATE";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::ThrottlingSeverity::MODERATE;
    }
    if ((o & ::android::hardware::thermal::V2_0::ThrottlingSeverity::SEVERE) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::ThrottlingSeverity::SEVERE)) {
        os += (first ? "" : " | ");
        os += "SEVERE";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::ThrottlingSeverity::SEVERE;
    }
    if ((o & ::android::hardware::thermal::V2_0::ThrottlingSeverity::CRITICAL) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::ThrottlingSeverity::CRITICAL)) {
        os += (first ? "" : " | ");
        os += "CRITICAL";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::ThrottlingSeverity::CRITICAL;
    }
    if ((o & ::android::hardware::thermal::V2_0::ThrottlingSeverity::EMERGENCY) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::ThrottlingSeverity::EMERGENCY)) {
        os += (first ? "" : " | ");
        os += "EMERGENCY";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::ThrottlingSeverity::EMERGENCY;
    }
    if ((o & ::android::hardware::thermal::V2_0::ThrottlingSeverity::SHUTDOWN) == static_cast<uint32_t>(::android::hardware::thermal::V2_0::ThrottlingSeverity::SHUTDOWN)) {
        os += (first ? "" : " | ");
        os += "SHUTDOWN";
        first = false;
        flipped |= ::android::hardware::thermal::V2_0::ThrottlingSeverity::SHUTDOWN;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::thermal::V2_0::ThrottlingSeverity o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::thermal::V2_0::ThrottlingSeverity::NONE) {
        return "NONE";
    }
    if (o == ::android::hardware::thermal::V2_0::ThrottlingSeverity::LIGHT) {
        return "LIGHT";
    }
    if (o == ::android::hardware::thermal::V2_0::ThrottlingSeverity::MODERATE) {
        return "MODERATE";
    }
    if (o == ::android::hardware::thermal::V2_0::ThrottlingSeverity::SEVERE) {
        return "SEVERE";
    }
    if (o == ::android::hardware::thermal::V2_0::ThrottlingSeverity::CRITICAL) {
        return "CRITICAL";
    }
    if (o == ::android::hardware::thermal::V2_0::ThrottlingSeverity::EMERGENCY) {
        return "EMERGENCY";
    }
    if (o == ::android::hardware::thermal::V2_0::ThrottlingSeverity::SHUTDOWN) {
        return "SHUTDOWN";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::thermal::V2_0::TemperatureThreshold& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".type = ";
    os += ::android::hardware::thermal::V2_0::toString(o.type);
    os += ", .name = ";
    os += ::android::hardware::toString(o.name);
    os += ", .hotThrottlingThresholds = ";
    os += ::android::hardware::toString(o.hotThrottlingThresholds);
    os += ", .coldThrottlingThresholds = ";
    os += ::android::hardware::toString(o.coldThrottlingThresholds);
    os += ", .vrThrottlingThreshold = ";
    os += ::android::hardware::toString(o.vrThrottlingThreshold);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::thermal::V2_0::TemperatureThreshold& lhs, const ::android::hardware::thermal::V2_0::TemperatureThreshold& rhs) {
    if (lhs.type != rhs.type) {
        return false;
    }
    if (lhs.name != rhs.name) {
        return false;
    }
    if (lhs.hotThrottlingThresholds != rhs.hotThrottlingThresholds) {
        return false;
    }
    if (lhs.coldThrottlingThresholds != rhs.coldThrottlingThresholds) {
        return false;
    }
    if (lhs.vrThrottlingThreshold != rhs.vrThrottlingThreshold) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::thermal::V2_0::TemperatureThreshold& lhs, const ::android::hardware::thermal::V2_0::TemperatureThreshold& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::thermal::V2_0::Temperature& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".type = ";
    os += ::android::hardware::thermal::V2_0::toString(o.type);
    os += ", .name = ";
    os += ::android::hardware::toString(o.name);
    os += ", .value = ";
    os += ::android::hardware::toString(o.value);
    os += ", .throttlingStatus = ";
    os += ::android::hardware::thermal::V2_0::toString(o.throttlingStatus);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::thermal::V2_0::Temperature& lhs, const ::android::hardware::thermal::V2_0::Temperature& rhs) {
    if (lhs.type != rhs.type) {
        return false;
    }
    if (lhs.name != rhs.name) {
        return false;
    }
    if (lhs.value != rhs.value) {
        return false;
    }
    if (lhs.throttlingStatus != rhs.throttlingStatus) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::thermal::V2_0::Temperature& lhs, const ::android::hardware::thermal::V2_0::Temperature& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::thermal::V2_0::CoolingDevice& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".type = ";
    os += ::android::hardware::thermal::V2_0::toString(o.type);
    os += ", .name = ";
    os += ::android::hardware::toString(o.name);
    os += ", .value = ";
    os += ::android::hardware::toString(o.value);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::thermal::V2_0::CoolingDevice& lhs, const ::android::hardware::thermal::V2_0::CoolingDevice& rhs) {
    if (lhs.type != rhs.type) {
        return false;
    }
    if (lhs.name != rhs.name) {
        return false;
    }
    if (lhs.value != rhs.value) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::thermal::V2_0::CoolingDevice& lhs, const ::android::hardware::thermal::V2_0::CoolingDevice& rhs){
    return !(lhs == rhs);
}


}  // namespace V2_0
}  // namespace thermal
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::thermal::V2_0::TemperatureType, 11> hidl_enum_values<::android::hardware::thermal::V2_0::TemperatureType> = {
    ::android::hardware::thermal::V2_0::TemperatureType::UNKNOWN,
    ::android::hardware::thermal::V2_0::TemperatureType::CPU,
    ::android::hardware::thermal::V2_0::TemperatureType::GPU,
    ::android::hardware::thermal::V2_0::TemperatureType::BATTERY,
    ::android::hardware::thermal::V2_0::TemperatureType::SKIN,
    ::android::hardware::thermal::V2_0::TemperatureType::USB_PORT,
    ::android::hardware::thermal::V2_0::TemperatureType::POWER_AMPLIFIER,
    ::android::hardware::thermal::V2_0::TemperatureType::BCL_VOLTAGE,
    ::android::hardware::thermal::V2_0::TemperatureType::BCL_CURRENT,
    ::android::hardware::thermal::V2_0::TemperatureType::BCL_PERCENTAGE,
    ::android::hardware::thermal::V2_0::TemperatureType::NPU,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::thermal::V2_0::CoolingType, 7> hidl_enum_values<::android::hardware::thermal::V2_0::CoolingType> = {
    ::android::hardware::thermal::V2_0::CoolingType::FAN,
    ::android::hardware::thermal::V2_0::CoolingType::BATTERY,
    ::android::hardware::thermal::V2_0::CoolingType::CPU,
    ::android::hardware::thermal::V2_0::CoolingType::GPU,
    ::android::hardware::thermal::V2_0::CoolingType::MODEM,
    ::android::hardware::thermal::V2_0::CoolingType::NPU,
    ::android::hardware::thermal::V2_0::CoolingType::COMPONENT,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::thermal::V2_0::ThrottlingSeverity, 7> hidl_enum_values<::android::hardware::thermal::V2_0::ThrottlingSeverity> = {
    ::android::hardware::thermal::V2_0::ThrottlingSeverity::NONE,
    ::android::hardware::thermal::V2_0::ThrottlingSeverity::LIGHT,
    ::android::hardware::thermal::V2_0::ThrottlingSeverity::MODERATE,
    ::android::hardware::thermal::V2_0::ThrottlingSeverity::SEVERE,
    ::android::hardware::thermal::V2_0::ThrottlingSeverity::CRITICAL,
    ::android::hardware::thermal::V2_0::ThrottlingSeverity::EMERGENCY,
    ::android::hardware::thermal::V2_0::ThrottlingSeverity::SHUTDOWN,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_THERMAL_V2_0_TYPES_H
