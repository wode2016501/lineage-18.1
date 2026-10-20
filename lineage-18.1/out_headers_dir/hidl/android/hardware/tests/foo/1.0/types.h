#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tests {
namespace foo {
namespace V1_0 {

// Forward declaration for forward reference support:
struct Abc;
struct Def;
struct Outer;
struct Unrelated;
struct EnumIterators;

struct Abc final {
    ::android::hardware::hidl_string x __attribute__ ((aligned(8)));
    float y __attribute__ ((aligned(4)));
    ::android::hardware::hidl_handle z __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::tests::foo::V1_0::Abc, x) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::tests::foo::V1_0::Abc, y) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::tests::foo::V1_0::Abc, z) == 24, "wrong offset");
static_assert(sizeof(::android::hardware::tests::foo::V1_0::Abc) == 40, "wrong size");
static_assert(__alignof(::android::hardware::tests::foo::V1_0::Abc) == 8, "wrong alignment");

struct Def final {
    ::android::hardware::hidl_string g __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::tests::foo::V1_0::Def, g) == 0, "wrong offset");
static_assert(sizeof(::android::hardware::tests::foo::V1_0::Def) == 16, "wrong size");
static_assert(__alignof(::android::hardware::tests::foo::V1_0::Def) == 8, "wrong alignment");

struct Outer final {
    // Forward declaration for forward reference support:
    struct Inner;

    struct Inner final {
        // Forward declaration for forward reference support:
        struct Deep;

        struct Deep final {
            int32_t data __attribute__ ((aligned(4)));
        };

        static_assert(offsetof(::android::hardware::tests::foo::V1_0::Outer::Inner::Deep, data) == 0, "wrong offset");
        static_assert(sizeof(::android::hardware::tests::foo::V1_0::Outer::Inner::Deep) == 4, "wrong size");
        static_assert(__alignof(::android::hardware::tests::foo::V1_0::Outer::Inner::Deep) == 4, "wrong alignment");

        int32_t data __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::Outer::Inner, data) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::Outer::Inner) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::Outer::Inner) == 4, "wrong alignment");

};

static_assert(sizeof(::android::hardware::tests::foo::V1_0::Outer) == 1, "wrong size");
static_assert(__alignof(::android::hardware::tests::foo::V1_0::Outer) == 1, "wrong alignment");

struct Unrelated final {
    ::android::hardware::tests::foo::V1_0::Outer::Inner great __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::tests::foo::V1_0::Unrelated, great) == 0, "wrong offset");
static_assert(sizeof(::android::hardware::tests::foo::V1_0::Unrelated) == 4, "wrong size");
static_assert(__alignof(::android::hardware::tests::foo::V1_0::Unrelated) == 4, "wrong alignment");

struct EnumIterators final {
    // Forward declaration for forward reference support:
    enum class Empty : uint32_t;
    enum class Parent : uint32_t;
    enum class EmptyChild : uint32_t;
    enum class Grandchild : uint32_t;
    enum class SkipsValues : uint32_t;
    enum class MultipleValues : uint32_t;

    enum class Empty : uint32_t {
    };

    enum class Parent : uint32_t {
        A = 0u,
    };

    enum class EmptyChild : uint32_t {
        A = 0u,
    };

    enum class Grandchild : uint32_t {
        A = 0u,
        B = 1u /* (::android::hardware::tests::foo::V1_0::EnumIterators::Parent.A implicitly + 1) */,
    };

    enum class SkipsValues : uint32_t {
        A = 7u,
        B = 8u /* (::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues.A implicitly + 1) */,
        C = 100u,
        D = 101u /* (::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues.C implicitly + 1) */,
        E = 102u /* (::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues.D implicitly + 1) */,
    };

    enum class MultipleValues : uint32_t {
        A = 7u,
        B = 7u,
        C = 8u,
        D = 7u,
    };

};

static_assert(sizeof(::android::hardware::tests::foo::V1_0::EnumIterators) == 1, "wrong size");
static_assert(__alignof(::android::hardware::tests::foo::V1_0::EnumIterators) == 1, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Abc& o);
// operator== and operator!= are not generated for Abc

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Def& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Def& lhs, const ::android::hardware::tests::foo::V1_0::Def& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Def& lhs, const ::android::hardware::tests::foo::V1_0::Def& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& lhs, const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& lhs, const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Outer::Inner& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Outer::Inner& lhs, const ::android::hardware::tests::foo::V1_0::Outer::Inner& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Outer::Inner& lhs, const ::android::hardware::tests::foo::V1_0::Outer::Inner& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Outer&);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Outer& lhs, const ::android::hardware::tests::foo::V1_0::Outer& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Outer& lhs, const ::android::hardware::tests::foo::V1_0::Outer& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Unrelated& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Unrelated& lhs, const ::android::hardware::tests::foo::V1_0::Unrelated& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Unrelated& lhs, const ::android::hardware::tests::foo::V1_0::Unrelated& rhs);

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::Empty o);

constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::Empty e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::Parent o);

constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::Parent e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild o);

constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild o);

constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues o);

constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues o);

constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::EnumIterators&);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::EnumIterators& lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::EnumIterators& lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators& rhs);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Abc& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".x = ";
    os += ::android::hardware::toString(o.x);
    os += ", .y = ";
    os += ::android::hardware::toString(o.y);
    os += ", .z = ";
    os += ::android::hardware::toString(o.z);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Abc

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Def& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".g = ";
    os += ::android::hardware::toString(o.g);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Def& lhs, const ::android::hardware::tests::foo::V1_0::Def& rhs) {
    if (lhs.g != rhs.g) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Def& lhs, const ::android::hardware::tests::foo::V1_0::Def& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& lhs, const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& lhs, const ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Outer::Inner& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Outer::Inner& lhs, const ::android::hardware::tests::foo::V1_0::Outer::Inner& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Outer::Inner& lhs, const ::android::hardware::tests::foo::V1_0::Outer::Inner& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Outer&) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Outer& /* lhs */, const ::android::hardware::tests::foo::V1_0::Outer& /* rhs */) {
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Outer& lhs, const ::android::hardware::tests::foo::V1_0::Outer& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::Unrelated& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".great = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.great);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::Unrelated& lhs, const ::android::hardware::tests::foo::V1_0::Unrelated& rhs) {
    if (lhs.great != rhs.great) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::Unrelated& lhs, const ::android::hardware::tests::foo::V1_0::Unrelated& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::EnumIterators::Empty>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::EnumIterators::Empty> flipped = 0;
    bool first = true;
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::Empty o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::EnumIterators::Parent>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::EnumIterators::Parent> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::Parent::A) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::Parent::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::Parent::A;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::Parent o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::Parent::A) {
        return "A";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild::A) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild::A;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild::A) {
        return "A";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::A) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::A;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::B) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::B)) {
        os += (first ? "" : " | ");
        os += "B";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::B;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::A) {
        return "A";
    }
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::B) {
        return "B";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::A) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::A;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::B) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::B)) {
        os += (first ? "" : " | ");
        os += "B";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::B;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::C) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::C)) {
        os += (first ? "" : " | ");
        os += "C";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::C;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::D) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::D)) {
        os += (first ? "" : " | ");
        os += "D";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::D;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::E) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::E)) {
        os += (first ? "" : " | ");
        os += "E";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::E;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::A) {
        return "A";
    }
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::B) {
        return "B";
    }
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::C) {
        return "C";
    }
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::D) {
        return "D";
    }
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::E) {
        return "E";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::A) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::A;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::B) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::B)) {
        os += (first ? "" : " | ");
        os += "B";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::B;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::C) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::C)) {
        os += (first ? "" : " | ");
        os += "C";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::C;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::D) == static_cast<uint32_t>(::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::D)) {
        os += (first ? "" : " | ");
        os += "D";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::D;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::A) {
        return "A";
    }
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::B) {
        return "B";
    }
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::C) {
        return "C";
    }
    if (o == ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::D) {
        return "D";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::EnumIterators&) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::EnumIterators& /* lhs */, const ::android::hardware::tests::foo::V1_0::EnumIterators& /* rhs */) {
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::EnumIterators& lhs, const ::android::hardware::tests::foo::V1_0::EnumIterators& rhs){
    return !(lhs == rhs);
}


}  // namespace V1_0
}  // namespace foo
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::EnumIterators::Empty, 0> hidl_enum_values<::android::hardware::tests::foo::V1_0::EnumIterators::Empty> = {
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::EnumIterators::Parent, 1> hidl_enum_values<::android::hardware::tests::foo::V1_0::EnumIterators::Parent> = {
    ::android::hardware::tests::foo::V1_0::EnumIterators::Parent::A,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild, 1> hidl_enum_values<::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild> = {
    ::android::hardware::tests::foo::V1_0::EnumIterators::EmptyChild::A,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild, 2> hidl_enum_values<::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild> = {
    ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::A,
    ::android::hardware::tests::foo::V1_0::EnumIterators::Grandchild::B,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues, 5> hidl_enum_values<::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues> = {
    ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::A,
    ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::B,
    ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::C,
    ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::D,
    ::android::hardware::tests::foo::V1_0::EnumIterators::SkipsValues::E,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues, 4> hidl_enum_values<::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues> = {
    ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::A,
    ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::B,
    ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::C,
    ::android::hardware::tests::foo::V1_0::EnumIterators::MultipleValues::D,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_TYPES_H
