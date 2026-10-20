#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_LIGHT_V2_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_LIGHT_V2_0_TYPES_H

#include <android/hardware/light/2.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tests {
namespace extension {
namespace light {
namespace V2_0 {

// Forward declaration for forward reference support:
enum class Default : int32_t;
enum class Brightness : int32_t;
struct LightState;

enum class Default : int32_t {
    INTERPOLATION_OMEGA = 2,
};

/**
 * One possibility is renaming an old type. Another possibility is taking
 * advantages of the different namespaces.
 */
enum class Brightness : int32_t {
    /**
     * Light brightness is managed by a user setting.
     */
    USER = 0,
    /**
     * Light brightness is managed by a light sensor.
     */
    SENSOR = 1 /* (::android::hardware::light::V2_0::Brightness.USER implicitly + 1) */,
    /**
     * Use a low-persistence mode for display backlights.
     * 
     * When set, the device driver must switch to a mode optimized for low display
     * persistence that is intended to be used when the device is being treated as a
     * head mounted display (HMD). The actual display brightness in this mode is
     * implementation dependent, and any value set for color in LightState may be
     * overridden by the HAL implementation.
     * 
     * For an optimal HMD viewing experience, the display must meet the following
     * criteria in this mode:
     * - Gray-to-Gray, White-to-Black, and Black-to-White switching time must be ≤ 3 ms.
     * - The display must support low-persistence with ≤ 3.5 ms persistence.
     *   Persistence is defined as the amount of time for which a pixel is
     *   emitting light for a single frame.
     * - Any "smart panel" or other frame buffering options that increase display
     *   latency are disabled.
     * - Display brightness is set so that the display is still visible to the user
     *   under normal indoor lighting.
     * - The display must update at 60 Hz at least, but higher refresh rates are
     *   recommended for low latency.
     * 
     */
    LOW_PERSISTENCE = 2 /* (::android::hardware::light::V2_0::Brightness.SENSOR implicitly + 1) */,
    /**
     * Say we're really going to use the phone as a heater.
     */
    EXTREME = 3 /* (::android::hardware::light::V2_0::Brightness.LOW_PERSISTENCE implicitly + 1) */,
    /**
     * Sometimes at night, we need it to be day.
     */
    THE_SUN = 4 /* (::android::hardware::tests::extension::light::V2_0::Brightness.EXTREME implicitly + 1) */,
};

/**
 * Structs can't inherit eachother in hidl. Use composition instead. In this
 * case, I won't use inheritence because I want to replace Brightness with
 * the new enumeration.
 */
struct LightState final {
    ::android::hardware::light::V2_0::LightState state __attribute__ ((aligned(4)));
    int32_t interpolationOmega __attribute__ ((aligned(4)));
    ::android::hardware::tests::extension::light::V2_0::Brightness brightness __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::tests::extension::light::V2_0::LightState, state) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::tests::extension::light::V2_0::LightState, interpolationOmega) == 20, "wrong offset");
static_assert(offsetof(::android::hardware::tests::extension::light::V2_0::LightState, brightness) == 24, "wrong offset");
static_assert(sizeof(::android::hardware::tests::extension::light::V2_0::LightState) == 28, "wrong size");
static_assert(__alignof(::android::hardware::tests::extension::light::V2_0::LightState) == 4, "wrong alignment");

//
// type declarations for package
//

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::extension::light::V2_0::Default o);

constexpr int32_t operator|(const ::android::hardware::tests::extension::light::V2_0::Default lhs, const ::android::hardware::tests::extension::light::V2_0::Default rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::extension::light::V2_0::Default rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::extension::light::V2_0::Default lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::extension::light::V2_0::Default lhs, const ::android::hardware::tests::extension::light::V2_0::Default rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::extension::light::V2_0::Default rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::extension::light::V2_0::Default lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::extension::light::V2_0::Default e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::extension::light::V2_0::Default e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::extension::light::V2_0::Brightness o);

constexpr int32_t operator|(const ::android::hardware::tests::extension::light::V2_0::Brightness lhs, const ::android::hardware::tests::extension::light::V2_0::Brightness rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::extension::light::V2_0::Brightness rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::extension::light::V2_0::Brightness lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::extension::light::V2_0::Brightness lhs, const ::android::hardware::tests::extension::light::V2_0::Brightness rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::extension::light::V2_0::Brightness rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::extension::light::V2_0::Brightness lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::extension::light::V2_0::Brightness e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::extension::light::V2_0::Brightness e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::extension::light::V2_0::LightState& o);
static inline bool operator==(const ::android::hardware::tests::extension::light::V2_0::LightState& lhs, const ::android::hardware::tests::extension::light::V2_0::LightState& rhs);
static inline bool operator!=(const ::android::hardware::tests::extension::light::V2_0::LightState& lhs, const ::android::hardware::tests::extension::light::V2_0::LightState& rhs);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::tests::extension::light::V2_0::Default>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::extension::light::V2_0::Default> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::extension::light::V2_0::Default::INTERPOLATION_OMEGA) == static_cast<int32_t>(::android::hardware::tests::extension::light::V2_0::Default::INTERPOLATION_OMEGA)) {
        os += (first ? "" : " | ");
        os += "INTERPOLATION_OMEGA";
        first = false;
        flipped |= ::android::hardware::tests::extension::light::V2_0::Default::INTERPOLATION_OMEGA;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::extension::light::V2_0::Default o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::extension::light::V2_0::Default::INTERPOLATION_OMEGA) {
        return "INTERPOLATION_OMEGA";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::extension::light::V2_0::Brightness>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::extension::light::V2_0::Brightness> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::extension::light::V2_0::Brightness::USER) == static_cast<int32_t>(::android::hardware::tests::extension::light::V2_0::Brightness::USER)) {
        os += (first ? "" : " | ");
        os += "USER";
        first = false;
        flipped |= ::android::hardware::tests::extension::light::V2_0::Brightness::USER;
    }
    if ((o & ::android::hardware::tests::extension::light::V2_0::Brightness::SENSOR) == static_cast<int32_t>(::android::hardware::tests::extension::light::V2_0::Brightness::SENSOR)) {
        os += (first ? "" : " | ");
        os += "SENSOR";
        first = false;
        flipped |= ::android::hardware::tests::extension::light::V2_0::Brightness::SENSOR;
    }
    if ((o & ::android::hardware::tests::extension::light::V2_0::Brightness::LOW_PERSISTENCE) == static_cast<int32_t>(::android::hardware::tests::extension::light::V2_0::Brightness::LOW_PERSISTENCE)) {
        os += (first ? "" : " | ");
        os += "LOW_PERSISTENCE";
        first = false;
        flipped |= ::android::hardware::tests::extension::light::V2_0::Brightness::LOW_PERSISTENCE;
    }
    if ((o & ::android::hardware::tests::extension::light::V2_0::Brightness::EXTREME) == static_cast<int32_t>(::android::hardware::tests::extension::light::V2_0::Brightness::EXTREME)) {
        os += (first ? "" : " | ");
        os += "EXTREME";
        first = false;
        flipped |= ::android::hardware::tests::extension::light::V2_0::Brightness::EXTREME;
    }
    if ((o & ::android::hardware::tests::extension::light::V2_0::Brightness::THE_SUN) == static_cast<int32_t>(::android::hardware::tests::extension::light::V2_0::Brightness::THE_SUN)) {
        os += (first ? "" : " | ");
        os += "THE_SUN";
        first = false;
        flipped |= ::android::hardware::tests::extension::light::V2_0::Brightness::THE_SUN;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::extension::light::V2_0::Brightness o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::extension::light::V2_0::Brightness::USER) {
        return "USER";
    }
    if (o == ::android::hardware::tests::extension::light::V2_0::Brightness::SENSOR) {
        return "SENSOR";
    }
    if (o == ::android::hardware::tests::extension::light::V2_0::Brightness::LOW_PERSISTENCE) {
        return "LOW_PERSISTENCE";
    }
    if (o == ::android::hardware::tests::extension::light::V2_0::Brightness::EXTREME) {
        return "EXTREME";
    }
    if (o == ::android::hardware::tests::extension::light::V2_0::Brightness::THE_SUN) {
        return "THE_SUN";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::extension::light::V2_0::LightState& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".state = ";
    os += ::android::hardware::light::V2_0::toString(o.state);
    os += ", .interpolationOmega = ";
    os += ::android::hardware::toString(o.interpolationOmega);
    os += ", .brightness = ";
    os += ::android::hardware::tests::extension::light::V2_0::toString(o.brightness);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::extension::light::V2_0::LightState& lhs, const ::android::hardware::tests::extension::light::V2_0::LightState& rhs) {
    if (lhs.state != rhs.state) {
        return false;
    }
    if (lhs.interpolationOmega != rhs.interpolationOmega) {
        return false;
    }
    if (lhs.brightness != rhs.brightness) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::extension::light::V2_0::LightState& lhs, const ::android::hardware::tests::extension::light::V2_0::LightState& rhs){
    return !(lhs == rhs);
}


}  // namespace V2_0
}  // namespace light
}  // namespace extension
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::extension::light::V2_0::Default, 1> hidl_enum_values<::android::hardware::tests::extension::light::V2_0::Default> = {
    ::android::hardware::tests::extension::light::V2_0::Default::INTERPOLATION_OMEGA,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::extension::light::V2_0::Brightness, 5> hidl_enum_values<::android::hardware::tests::extension::light::V2_0::Brightness> = {
    ::android::hardware::tests::extension::light::V2_0::Brightness::USER,
    ::android::hardware::tests::extension::light::V2_0::Brightness::SENSOR,
    ::android::hardware::tests::extension::light::V2_0::Brightness::LOW_PERSISTENCE,
    ::android::hardware::tests::extension::light::V2_0::Brightness::EXTREME,
    ::android::hardware::tests::extension::light::V2_0::Brightness::THE_SUN,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXTENSION_LIGHT_V2_0_TYPES_H
