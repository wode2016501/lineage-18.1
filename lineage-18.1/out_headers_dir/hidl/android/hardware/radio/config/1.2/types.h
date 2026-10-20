#ifndef HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_2_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_2_TYPES_H

#include <android/hardware/radio/config/1.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {
namespace V1_2 {

// Forward declaration for forward reference support:
struct SimSlotStatus;

struct SimSlotStatus final {
    ::android::hardware::radio::config::V1_0::SimSlotStatus base __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string eid __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::radio::config::V1_2::SimSlotStatus, base) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::radio::config::V1_2::SimSlotStatus, eid) == 48, "wrong offset");
static_assert(sizeof(::android::hardware::radio::config::V1_2::SimSlotStatus) == 64, "wrong size");
static_assert(__alignof(::android::hardware::radio::config::V1_2::SimSlotStatus) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::radio::config::V1_2::SimSlotStatus& o);
static inline bool operator==(const ::android::hardware::radio::config::V1_2::SimSlotStatus& lhs, const ::android::hardware::radio::config::V1_2::SimSlotStatus& rhs);
static inline bool operator!=(const ::android::hardware::radio::config::V1_2::SimSlotStatus& lhs, const ::android::hardware::radio::config::V1_2::SimSlotStatus& rhs);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::radio::config::V1_2::SimSlotStatus& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".base = ";
    os += ::android::hardware::radio::config::V1_0::toString(o.base);
    os += ", .eid = ";
    os += ::android::hardware::toString(o.eid);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::radio::config::V1_2::SimSlotStatus& lhs, const ::android::hardware::radio::config::V1_2::SimSlotStatus& rhs) {
    if (lhs.base != rhs.base) {
        return false;
    }
    if (lhs.eid != rhs.eid) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::radio::config::V1_2::SimSlotStatus& lhs, const ::android::hardware::radio::config::V1_2::SimSlotStatus& rhs){
    return !(lhs == rhs);
}


}  // namespace V1_2
}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_2_TYPES_H
