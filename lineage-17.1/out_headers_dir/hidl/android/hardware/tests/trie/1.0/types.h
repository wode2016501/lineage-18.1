#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_TRIE_V1_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_TRIE_V1_0_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tests {
namespace trie {
namespace V1_0 {

// Forward declaration for forward reference support:
struct TrieNode;
struct TrieEdge;
struct A;
struct B;
struct S;
enum class E1 : int32_t;
enum class E2 : int32_t;

// Order of inner types was changed for forward reference support.

struct TrieNode final {
    ::android::hardware::hidl_vec<::android::hardware::tests::trie::V1_0::TrieEdge> next __attribute__ ((aligned(8)));
    bool isTerminal __attribute__ ((aligned(1)));
};

static_assert(offsetof(::android::hardware::tests::trie::V1_0::TrieNode, next) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::tests::trie::V1_0::TrieNode, isTerminal) == 16, "wrong offset");
static_assert(sizeof(::android::hardware::tests::trie::V1_0::TrieNode) == 24, "wrong size");
static_assert(__alignof(::android::hardware::tests::trie::V1_0::TrieNode) == 8, "wrong alignment");

struct TrieEdge final {
    int8_t character __attribute__ ((aligned(1)));
    ::android::hardware::tests::trie::V1_0::TrieNode node __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::tests::trie::V1_0::TrieEdge, character) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::tests::trie::V1_0::TrieEdge, node) == 8, "wrong offset");
static_assert(sizeof(::android::hardware::tests::trie::V1_0::TrieEdge) == 32, "wrong size");
static_assert(__alignof(::android::hardware::tests::trie::V1_0::TrieEdge) == 8, "wrong alignment");

struct A final {
    ::android::hardware::tests::trie::V1_0::B const* b;
};

struct B final {
    ::android::hardware::tests::trie::V1_0::A const* a;
};

typedef ::android::hardware::tests::trie::V1_0::S const* refS;

struct S final {
    ::android::hardware::tests::trie::V1_0::S const* f;
};

enum class E1 : int32_t {
    OK = 201 /* (E2:ACCEPT + ANOTHER) */,
    ANOTHER = 100,
};

enum class E2 : int32_t {
    OK = 201 /* (E2:ACCEPT + ANOTHER) */,
    ANOTHER = 100,
    ACCEPT = 101 /* (::android::hardware::tests::trie::V1_0::E1.ANOTHER implicitly + 1) */,
};

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::TrieNode& o);
static inline bool operator==(const ::android::hardware::tests::trie::V1_0::TrieNode& lhs, const ::android::hardware::tests::trie::V1_0::TrieNode& rhs);
static inline bool operator!=(const ::android::hardware::tests::trie::V1_0::TrieNode& lhs, const ::android::hardware::tests::trie::V1_0::TrieNode& rhs);

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::TrieEdge& o);
static inline bool operator==(const ::android::hardware::tests::trie::V1_0::TrieEdge& lhs, const ::android::hardware::tests::trie::V1_0::TrieEdge& rhs);
static inline bool operator!=(const ::android::hardware::tests::trie::V1_0::TrieEdge& lhs, const ::android::hardware::tests::trie::V1_0::TrieEdge& rhs);

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::A& o);
// operator== and operator!= are not generated for A

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::B& o);
// operator== and operator!= are not generated for B

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::S& o);
// operator== and operator!= are not generated for S

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::trie::V1_0::E1 o);

constexpr int32_t operator|(const ::android::hardware::tests::trie::V1_0::E1 lhs, const ::android::hardware::tests::trie::V1_0::E1 rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::trie::V1_0::E1 rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::trie::V1_0::E1 lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::trie::V1_0::E1 lhs, const ::android::hardware::tests::trie::V1_0::E1 rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::trie::V1_0::E1 rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::trie::V1_0::E1 lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::trie::V1_0::E1 e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::trie::V1_0::E1 e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::trie::V1_0::E2 o);

constexpr int32_t operator|(const ::android::hardware::tests::trie::V1_0::E2 lhs, const ::android::hardware::tests::trie::V1_0::E2 rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::trie::V1_0::E2 rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::trie::V1_0::E2 lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::trie::V1_0::E2 lhs, const ::android::hardware::tests::trie::V1_0::E2 rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::trie::V1_0::E2 rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::trie::V1_0::E2 lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::trie::V1_0::E2 e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::trie::V1_0::E2 e) {
    v &= static_cast<int32_t>(e);
    return v;
}

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::TrieNode& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".next = ";
    os += ::android::hardware::toString(o.next);
    os += ", .isTerminal = ";
    os += ::android::hardware::toString(o.isTerminal);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::trie::V1_0::TrieNode& lhs, const ::android::hardware::tests::trie::V1_0::TrieNode& rhs) {
    if (lhs.next != rhs.next) {
        return false;
    }
    if (lhs.isTerminal != rhs.isTerminal) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::trie::V1_0::TrieNode& lhs, const ::android::hardware::tests::trie::V1_0::TrieNode& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::TrieEdge& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".character = ";
    os += ::android::hardware::toString(o.character);
    os += ", .node = ";
    os += ::android::hardware::tests::trie::V1_0::toString(o.node);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::trie::V1_0::TrieEdge& lhs, const ::android::hardware::tests::trie::V1_0::TrieEdge& rhs) {
    if (lhs.character != rhs.character) {
        return false;
    }
    if (lhs.node != rhs.node) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::trie::V1_0::TrieEdge& lhs, const ::android::hardware::tests::trie::V1_0::TrieEdge& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::A& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".b = ";
    os += ::android::hardware::toString(o.b);
    os += "}"; return os;
}

// operator== and operator!= are not generated for A

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::B& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".a = ";
    os += ::android::hardware::toString(o.a);
    os += "}"; return os;
}

// operator== and operator!= are not generated for B

static inline std::string toString(const ::android::hardware::tests::trie::V1_0::S& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".f = ";
    os += ::android::hardware::toString(o.f);
    os += "}"; return os;
}

// operator== and operator!= are not generated for S

template<>
inline std::string toString<::android::hardware::tests::trie::V1_0::E1>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::trie::V1_0::E1> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::trie::V1_0::E1::OK) == static_cast<int32_t>(::android::hardware::tests::trie::V1_0::E1::OK)) {
        os += (first ? "" : " | ");
        os += "OK";
        first = false;
        flipped |= ::android::hardware::tests::trie::V1_0::E1::OK;
    }
    if ((o & ::android::hardware::tests::trie::V1_0::E1::ANOTHER) == static_cast<int32_t>(::android::hardware::tests::trie::V1_0::E1::ANOTHER)) {
        os += (first ? "" : " | ");
        os += "ANOTHER";
        first = false;
        flipped |= ::android::hardware::tests::trie::V1_0::E1::ANOTHER;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::trie::V1_0::E1 o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::trie::V1_0::E1::OK) {
        return "OK";
    }
    if (o == ::android::hardware::tests::trie::V1_0::E1::ANOTHER) {
        return "ANOTHER";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::trie::V1_0::E2>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::trie::V1_0::E2> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::trie::V1_0::E2::OK) == static_cast<int32_t>(::android::hardware::tests::trie::V1_0::E2::OK)) {
        os += (first ? "" : " | ");
        os += "OK";
        first = false;
        flipped |= ::android::hardware::tests::trie::V1_0::E2::OK;
    }
    if ((o & ::android::hardware::tests::trie::V1_0::E2::ANOTHER) == static_cast<int32_t>(::android::hardware::tests::trie::V1_0::E2::ANOTHER)) {
        os += (first ? "" : " | ");
        os += "ANOTHER";
        first = false;
        flipped |= ::android::hardware::tests::trie::V1_0::E2::ANOTHER;
    }
    if ((o & ::android::hardware::tests::trie::V1_0::E2::ACCEPT) == static_cast<int32_t>(::android::hardware::tests::trie::V1_0::E2::ACCEPT)) {
        os += (first ? "" : " | ");
        os += "ACCEPT";
        first = false;
        flipped |= ::android::hardware::tests::trie::V1_0::E2::ACCEPT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::trie::V1_0::E2 o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::trie::V1_0::E2::OK) {
        return "OK";
    }
    if (o == ::android::hardware::tests::trie::V1_0::E2::ANOTHER) {
        return "ANOTHER";
    }
    if (o == ::android::hardware::tests::trie::V1_0::E2::ACCEPT) {
        return "ACCEPT";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}


}  // namespace V1_0
}  // namespace trie
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::trie::V1_0::E1, 2> hidl_enum_values<::android::hardware::tests::trie::V1_0::E1> = {
    ::android::hardware::tests::trie::V1_0::E1::OK,
    ::android::hardware::tests::trie::V1_0::E1::ANOTHER,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::trie::V1_0::E2, 3> hidl_enum_values<::android::hardware::tests::trie::V1_0::E2> = {
    ::android::hardware::tests::trie::V1_0::E2::OK,
    ::android::hardware::tests::trie::V1_0::E2::ANOTHER,
    ::android::hardware::tests::trie::V1_0::E2::ACCEPT,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_TRIE_V1_0_TYPES_H
