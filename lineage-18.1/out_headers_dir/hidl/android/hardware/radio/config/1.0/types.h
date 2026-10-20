#ifndef HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_0_TYPES_H

#include <android/hardware/radio/1.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {
namespace V1_0 {

// Forward declaration for forward reference support:
enum class SlotState : int32_t;
struct SimSlotStatus;

enum class SlotState : int32_t {
    /**
     * Physical slot is inactive
     */
    INACTIVE = 0 /* 0x00 */,
    /**
     * Physical slot is active
     */
    ACTIVE = 1 /* 0x01 */,
};

struct SimSlotStatus final {
    ::android::hardware::radio::V1_0::CardState cardState __attribute__ ((aligned(4)));
    ::android::hardware::radio::config::V1_0::SlotState slotState __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string atr __attribute__ ((aligned(8)));
    uint32_t logicalSlotId __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string iccid __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, cardState) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, slotState) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, atr) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, logicalSlotId) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::radio::config::V1_0::SimSlotStatus, iccid) == 32, "wrong offset");
static_assert(sizeof(::android::hardware::radio::config::V1_0::SimSlotStatus) == 48, "wrong size");
static_assert(__alignof(::android::hardware::radio::config::V1_0::SimSlotStatus) == 8, "wrong alignment");

//
// type declarations for package
//

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::radio::config::V1_0::SlotState o);

constexpr int32_t operator|(const ::android::hardware::radio::config::V1_0::SlotState lhs, const ::android::hardware::radio::config::V1_0::SlotState rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::radio::config::V1_0::SlotState rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::radio::config::V1_0::SlotState lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::radio::config::V1_0::SlotState lhs, const ::android::hardware::radio::config::V1_0::SlotState rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::radio::config::V1_0::SlotState rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::radio::config::V1_0::SlotState lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::radio::config::V1_0::SlotState e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::radio::config::V1_0::SlotState e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::radio::config::V1_0::SimSlotStatus& o);
static inline bool operator==(const ::android::hardware::radio::config::V1_0::SimSlotStatus& lhs, const ::android::hardware::radio::config::V1_0::SimSlotStatus& rhs);
static inline bool operator!=(const ::android::hardware::radio::config::V1_0::SimSlotStatus& lhs, const ::android::hardware::radio::config::V1_0::SimSlotStatus& rhs);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::radio::config::V1_0::SlotState>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::radio::config::V1_0::SlotState> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::radio::config::V1_0::SlotState::INACTIVE) == static_cast<int32_t>(::android::hardware::radio::config::V1_0::SlotState::INACTIVE)) {
        os += (first ? "" : " | ");
        os += "INACTIVE";
        first = false;
        flipped |= ::android::hardware::radio::config::V1_0::SlotState::INACTIVE;
    }
    if ((o & ::android::hardware::radio::config::V1_0::SlotState::ACTIVE) == static_cast<int32_t>(::android::hardware::radio::config::V1_0::SlotState::ACTIVE)) {
        os += (first ? "" : " | ");
        os += "ACTIVE";
        first = false;
        flipped |= ::android::hardware::radio::config::V1_0::SlotState::ACTIVE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::radio::config::V1_0::SlotState o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::radio::config::V1_0::SlotState::INACTIVE) {
        return "INACTIVE";
    }
    if (o == ::android::hardware::radio::config::V1_0::SlotState::ACTIVE) {
        return "ACTIVE";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::radio::config::V1_0::SimSlotStatus& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".cardState = ";
    os += ::android::hardware::radio::V1_0::toString(o.cardState);
    os += ", .slotState = ";
    os += ::android::hardware::radio::config::V1_0::toString(o.slotState);
    os += ", .atr = ";
    os += ::android::hardware::toString(o.atr);
    os += ", .logicalSlotId = ";
    os += ::android::hardware::toString(o.logicalSlotId);
    os += ", .iccid = ";
    os += ::android::hardware::toString(o.iccid);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::radio::config::V1_0::SimSlotStatus& lhs, const ::android::hardware::radio::config::V1_0::SimSlotStatus& rhs) {
    if (lhs.cardState != rhs.cardState) {
        return false;
    }
    if (lhs.slotState != rhs.slotState) {
        return false;
    }
    if (lhs.atr != rhs.atr) {
        return false;
    }
    if (lhs.logicalSlotId != rhs.logicalSlotId) {
        return false;
    }
    if (lhs.iccid != rhs.iccid) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::radio::config::V1_0::SimSlotStatus& lhs, const ::android::hardware::radio::config::V1_0::SimSlotStatus& rhs){
    return !(lhs == rhs);
}


}  // namespace V1_0
}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::radio::config::V1_0::SlotState, 2> hidl_enum_values<::android::hardware::radio::config::V1_0::SlotState> = {
    ::android::hardware::radio::config::V1_0::SlotState::INACTIVE,
    ::android::hardware::radio::config::V1_0::SlotState::ACTIVE,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_0_TYPES_H
