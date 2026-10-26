#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_IEXPRESSION_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_IEXPRESSION_H

#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tests {
namespace expression {
namespace V1_0 {

struct IExpression : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.expression@1.0::IExpression"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class UInt64LiteralTypeGuessing : uint64_t;
    enum class SuffixedLiteralTypeGuessing : int32_t;
    enum class Int64LiteralTypeGuessing : int64_t;
    enum class Int32BitShifting : int32_t;
    enum class UInt32BitShifting : uint32_t;
    enum class Int64BitShifting : int64_t;
    enum class UInt64BitShifting : uint64_t;
    enum class Precedence : int32_t;
    enum class OperatorSanityCheck : int32_t;
    enum class NoElements : uint32_t;
    enum class OneElement : uint32_t;
    enum class TwoElement : uint32_t;
    enum class TwoCollidingElements : uint32_t;
    enum class ThreeFromInheritance : uint32_t;
    enum class ThreeFromDoubleInheritance : uint32_t;
    enum class ThreeCollidingFromInheritance : uint32_t;
    enum class EnumTagTest : uint32_t;
    enum class Grayscale : int8_t;
    enum class Color : int8_t;
    enum class Foo1 : int8_t;
    enum class Foo2 : int8_t;
    enum class Foo3 : int8_t;
    enum class Foo4 : int8_t;
    enum class Number : uint8_t;
    enum class Constants : int32_t;

    enum class UInt64LiteralTypeGuessing : uint64_t {
        noSuffixDec1 = 0ull,
        noSuffixDec2 = 1ull,
        noSuffixDec3 = 18446744073709551615ull /* (-1) */,
        noSuffixDec4 = 18446744073709551615ull /* (~0) */,
        noSuffixDec5 = 2147483647ull,
        noSuffixDec6 = 18446744071562067968ull /* (-2147483648) */,
        noSuffixDec7 = 2147483648ull,
        noSuffixDec8 = 18446744071562067967ull /* (-2147483649) */,
        noSuffixDec9 = 0ull /* (~(-1)) */,
        noSuffixHex1 = 2147483647ull /* 0x7fffffff */,
        noSuffixHex2 = 2147483648ull /* 0x80000000 */,
        noSuffixHex3 = 4294967295ull /* 0xffffffff */,
        longHex1 = 4294967295ull /* 0xffffffffl */,
        longHex2 = 68719476735ull /* 0Xfffffffff */,
        longHex3 = 9223372036854775807ull /* 0x7fffffffffffffff */,
        longHex4 = 9223372036854775808ull /* 0x8000000000000000 */,
        longHex5 = 18446744073709551615ull /* 0xFFFFFFFFFFFFFFFF */,
    };

    enum class SuffixedLiteralTypeGuessing : int32_t {
        decInt32_1 = 1 /* ((~(-1)) == 0) */,
        decInt32_2 = 1 /* ((-(1 << 31)) == (1 << 31)) */,
        decInt64_1 = 1 /* ((~(-1l)) == 0) */,
        decInt64_2 = 1 /* ((~4294967295) != 0) */,
        decInt64_3 = 1 /* ((~4294967295l) != 0) */,
        decInt64_4 = 1 /* ((-(1l << 63)) == (1l << 63)) */,
        hexInt32_1 = 1 /* ((-0x7fffffff) < 0) */,
        hexUInt32_1 = 1 /* ((-0x80000000) > 0) */,
        hexUInt32_2 = 1 /* ((~0xFFFFFFFF) == 0) */,
        hexInt64_1 = 1 /* ((-0x7FFFFFFFFFFFFFFF) < 0) */,
        hexUInt64_1 = 1 /* ((-0x8000000000000000) > 0) */,
    };

    enum class Int64LiteralTypeGuessing : int64_t {
        noSuffixDec11 = -2147483648ll /* (1 + 0x7fffffff) */,
        noSuffixDec12 = 2147483647ll /* (0x80000000 - 1) */,
    };

    enum class Int32BitShifting : int32_t {
        int32BitShift1 = -2147483648 /* (1 << 31) */,
    };

    enum class UInt32BitShifting : uint32_t {
        uint32BitShift1 = 2147483648u /* (1 << 31) */,
    };

    enum class Int64BitShifting : int64_t {
        int64BitShift1 = static_cast<int64_t>(-9223372036854775808ull) /* (1l << 63) */,
    };

    enum class UInt64BitShifting : uint64_t {
        uint64BitShift1 = 9223372036854775808ull /* (1l << 63) */,
    };

    enum class Precedence : int32_t {
        literal = 4,
        neg = -4 /* (-4) */,
        literalL = -4 /* (-4L) */,
        hex = -1 /* 0xffffffff */,
        hexLong = -1 /* 0xffffffffl */,
        hexLong2 = -1 /* 0xfffffffff */,
        simpleArithmetic = 5 /* (4 + 1) */,
        simpleArithmetic2 = 1 /* ((2 + 3) - 4) */,
        simpleArithmetic3 = 3 /* ((2 - 3) + 4) */,
        simpleBoolExpr = 0 /* (1 == 4) */,
        simpleLogical = 1 /* (1 && 1) */,
        simpleLogical2 = 1 /* (1 || (1 && 0)) */,
        simpleComp = 1 /* (1 < 2) */,
        boolExpr1 = 0 /* (!(((3 != 4) || (((2 < 3) <= 3) > 4)) >= 0)) */,
        boolExpr = 0 /* ((1 == 7) && (!(((3 != 4) || (((2 < 3) <= 3) > 4)) >= 0))) */,
        simpleBitShift = 4 /* (1 << 2) */,
        simpleBitShift2 = 2 /* (4 >> 1) */,
        simpleBitShiftNeg = 2 /* (4 << (-1)) */,
        simpleArithmeticRightShift = -1 /* ((1 << 31) >> 31) */,
        simpleBitExpr = 5 /* (1 | (16 >> 2)) */,
        simpleBitExpr2 = 30 /* (0x0f ^ (0x33 & 0x99)) */,
        bitExpr = 3 /* (((~42) & ((1 << 3) | (16 >> 2))) ^ 7) */,
        arithmeticExpr = 33 /* ((2 + 3) - ((4 * (-7)) / (10 % 3))) */,
        messyExpr = 2 /* (2 + ((-3) & (4 / 7))) */,
        paranExpr = 2 /* (1 + 1) */,
        ternary = 2 /* (1?2:3) */,
        ternary2 = 3 /* ((1 && 2)?3:4) */,
        complicatedTernary2 = 56 /* ((((1 - 1) && (2 + 3)) || 5)?(7 * 8):(-3)) */,
    };

    enum class OperatorSanityCheck : int32_t {
        plus = 1 /* ((1 + 2) == 3) */,
        minus = 1 /* ((8 - 9) == (-1)) */,
        product = 1 /* ((9 * 9) == 81) */,
        division = 1 /* ((29 / 3) == 9) */,
        mod = 1 /* ((29 % 3) == 2) */,
        bit_or = 1 /* ((0xC0010000 | 0xF00D) == 0xC001F00D) */,
        bit_or2 = 1 /* ((10 | 6) == 14) */,
        bit_and = 1 /* ((10 & 6) == 2) */,
        bit_xor = 1 /* ((10 ^ 6) == 12) */,
        lt1 = 1 /* (6 < 10) */,
        lt2 = 1 /* ((10 < 10) == 0) */,
        gt1 = 1 /* ((6 > 10) == 0) */,
        gt2 = 1 /* ((10 > 10) == 0) */,
        gte1 = 1 /* (19 >= 10) */,
        gte2 = 1 /* (10 >= 10) */,
        lte1 = 1 /* (5 <= 10) */,
        lte2 = 1 /* ((19 <= 10) == 0) */,
        ne1 = 1 /* (19 != 10) */,
        ne2 = 1 /* ((10 != 10) == 0) */,
        lshift = 1 /* ((22 << 1) == 44) */,
        rshift = 1 /* ((11 >> 1) == 5) */,
        logor1 = 1 /* ((1 || 0) == 1) */,
        logor2 = 1 /* ((1 || 1) == 1) */,
        logor3 = 1 /* ((0 || 0) == 0) */,
        logor4 = 1 /* ((0 || 1) == 1) */,
        logand1 = 1 /* ((1 && 0) == 0) */,
        logand2 = 1 /* ((1 && 1) == 1) */,
        logand3 = 1 /* ((0 && 0) == 0) */,
        logand4 = 1 /* ((0 && 1) == 0) */,
    };

    enum class NoElements : uint32_t {
    };

    enum class OneElement : uint32_t {
        A = 0u,
    };

    enum class TwoElement : uint32_t {
        A = 0u,
        B = 1u /* (::android::hardware::tests::expression::V1_0::IExpression::TwoElement.A implicitly + 1) */,
    };

    enum class TwoCollidingElements : uint32_t {
        A = 1u,
        B = 1u,
    };

    enum class ThreeFromInheritance : uint32_t {
        A = 0u,
        B = 1u /* (::android::hardware::tests::expression::V1_0::IExpression::TwoElement.A implicitly + 1) */,
        C = 2u /* (::android::hardware::tests::expression::V1_0::IExpression::TwoElement.B implicitly + 1) */,
    };

    enum class ThreeFromDoubleInheritance : uint32_t {
        A = 0u,
        B = 1u /* (::android::hardware::tests::expression::V1_0::IExpression::TwoElement.A implicitly + 1) */,
        C = 2u /* (::android::hardware::tests::expression::V1_0::IExpression::TwoElement.B implicitly + 1) */,
    };

    enum class ThreeCollidingFromInheritance : uint32_t {
        A = 1u,
        B = 1u,
        C = 2u /* (::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements.B implicitly + 1) */,
    };

    enum class EnumTagTest : uint32_t {
        a = 1u /* (NoElements#len == 0) */,
        b = 1u /* (OneElement#len == 1) */,
        c = 1u /* (TwoElement#len == 2) */,
        d = 1u /* (TwoCollidingElements#len == 2) */,
        e = 1u /* (ThreeFromInheritance#len == 3) */,
        f = 1u /* (ThreeFromDoubleInheritance#len == 3) */,
        g = 1u /* (ThreeCollidingFromInheritance#len == 3) */,
        h = 1u /* (EnumTagTest#len == 8) */,
    };

    enum class Grayscale : int8_t {
        WHITE = 126,
        GRAY = 127 /* (::android::hardware::tests::expression::V1_0::IExpression::Grayscale.WHITE implicitly + 1) */,
        DARK_GRAY = -128 /* (::android::hardware::tests::expression::V1_0::IExpression::Grayscale.GRAY implicitly + 1) */,
        BLACK = -127 /* (::android::hardware::tests::expression::V1_0::IExpression::Grayscale.DARK_GRAY implicitly + 1) */,
    };

    enum class Color : int8_t {
        WHITE = 126,
        GRAY = 127 /* (::android::hardware::tests::expression::V1_0::IExpression::Grayscale.WHITE implicitly + 1) */,
        DARK_GRAY = -128 /* (::android::hardware::tests::expression::V1_0::IExpression::Grayscale.GRAY implicitly + 1) */,
        BLACK = -127 /* (::android::hardware::tests::expression::V1_0::IExpression::Grayscale.DARK_GRAY implicitly + 1) */,
        RED = -126 /* (::android::hardware::tests::expression::V1_0::IExpression::Grayscale.BLACK implicitly + 1) */,
        RUBY = 0,
        GREEN = 1 /* (::android::hardware::tests::expression::V1_0::IExpression::Color.RUBY implicitly + 1) */,
        BLUE = 5,
        CYAN = 6 /* (::android::hardware::tests::expression::V1_0::IExpression::Color.BLUE implicitly + 1) */,
        ORANGE = 7 /* (::android::hardware::tests::expression::V1_0::IExpression::Color.CYAN implicitly + 1) */,
        ROSE = 126 /* WHITE */,
    };

    enum class Foo1 : int8_t {
    };

    enum class Foo2 : int8_t {
    };

    enum class Foo3 : int8_t {
        BAR1 = 0,
        BAR2 = 10,
    };

    enum class Foo4 : int8_t {
        BAR1 = 0,
        BAR2 = 10,
        BAR3 = 11 /* (::android::hardware::tests::expression::V1_0::IExpression::Foo3.BAR2 implicitly + 1) */,
        BAR4 = 21 /* (BAR2 + BAR3) */,
    };

    enum class Number : uint8_t {
        MAX = 255,
        MAX_PLUS_1 = 0 /* (::android::hardware::tests::expression::V1_0::IExpression::Number.MAX implicitly + 1) */,
        MAX_PLUS_2 = 1 /* (::android::hardware::tests::expression::V1_0::IExpression::Number.MAX_PLUS_1 implicitly + 1) */,
    };

    enum class Constants : int32_t {
        CONST_FOO = 0,
        CONST_BAR = 70,
        MAX_ARRAY_SIZE = 20,
        MAX_ARRAY_SIZE2 = 21 /* (::android::hardware::tests::expression::V1_0::IExpression::Constants.MAX_ARRAY_SIZE implicitly + 1) */,
        MAX_ARRAY_SIZE3 = 40 /* (MAX_ARRAY_SIZE + MAX_ARRAY_SIZE) */,
        MY_INT32_MAX_MINUS_1 = 2147483646 /* 0x7FFFFFFE */,
        MY_INT32_MAX = 2147483647 /* (::android::hardware::tests::expression::V1_0::IExpression::Constants.MY_INT32_MAX_MINUS_1 implicitly + 1) */,
        MY_INT32_MIN = -2147483648 /* (::android::hardware::tests::expression::V1_0::IExpression::Constants.MY_INT32_MAX implicitly + 1) */,
        MY_INT32_MIN_PLUS_1 = -2147483647 /* (::android::hardware::tests::expression::V1_0::IExpression::Constants.MY_INT32_MIN implicitly + 1) */,
    };

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    // @callflow(key=1 /* (Constants:CONST_FOO + 1) */)
    virtual ::android::hardware::Return<void> foo1(const ::android::hardware::hidl_array<int32_t, 1 /* (Constants:CONST_FOO + 1) */>& array) = 0;

    virtual ::android::hardware::Return<void> foo2(const ::android::hardware::hidl_array<int32_t, 13 /* (5 + 8) */>& array) = 0;

    virtual ::android::hardware::Return<void> foo3(const ::android::hardware::hidl_array<int32_t, 20 /* Constants:MAX_ARRAY_SIZE */>& array) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::expression::V1_0::IExpression>> castFrom(const ::android::sp<::android::hardware::tests::expression::V1_0::IExpression>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::expression::V1_0::IExpression>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IExpression> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IExpression> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IExpression> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IExpression> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IExpression> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IExpression> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IExpression> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IExpression> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(uint64_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing o);

constexpr uint64_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing rhs) {
    return static_cast<uint64_t>(static_cast<uint64_t>(lhs) | static_cast<uint64_t>(rhs));
}
constexpr uint64_t operator|(const uint64_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing rhs) {
    return static_cast<uint64_t>(lhs | static_cast<uint64_t>(rhs));
}
constexpr uint64_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing lhs, const uint64_t rhs) {
    return static_cast<uint64_t>(static_cast<uint64_t>(lhs) | rhs);
}
constexpr uint64_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing rhs) {
    return static_cast<uint64_t>(static_cast<uint64_t>(lhs) & static_cast<uint64_t>(rhs));
}
constexpr uint64_t operator&(const uint64_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing rhs) {
    return static_cast<uint64_t>(lhs & static_cast<uint64_t>(rhs));
}
constexpr uint64_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing lhs, const uint64_t rhs) {
    return static_cast<uint64_t>(static_cast<uint64_t>(lhs) & rhs);
}
constexpr uint64_t &operator|=(uint64_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing e) {
    v |= static_cast<uint64_t>(e);
    return v;
}
constexpr uint64_t &operator&=(uint64_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing e) {
    v &= static_cast<uint64_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing o);

constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing lhs, const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing lhs, const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int64_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing o);

constexpr int64_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing rhs) {
    return static_cast<int64_t>(static_cast<int64_t>(lhs) | static_cast<int64_t>(rhs));
}
constexpr int64_t operator|(const int64_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing rhs) {
    return static_cast<int64_t>(lhs | static_cast<int64_t>(rhs));
}
constexpr int64_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing lhs, const int64_t rhs) {
    return static_cast<int64_t>(static_cast<int64_t>(lhs) | rhs);
}
constexpr int64_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing rhs) {
    return static_cast<int64_t>(static_cast<int64_t>(lhs) & static_cast<int64_t>(rhs));
}
constexpr int64_t operator&(const int64_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing rhs) {
    return static_cast<int64_t>(lhs & static_cast<int64_t>(rhs));
}
constexpr int64_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing lhs, const int64_t rhs) {
    return static_cast<int64_t>(static_cast<int64_t>(lhs) & rhs);
}
constexpr int64_t &operator|=(int64_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing e) {
    v |= static_cast<int64_t>(e);
    return v;
}
constexpr int64_t &operator&=(int64_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing e) {
    v &= static_cast<int64_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting o);

constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int64_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting o);

constexpr int64_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting rhs) {
    return static_cast<int64_t>(static_cast<int64_t>(lhs) | static_cast<int64_t>(rhs));
}
constexpr int64_t operator|(const int64_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting rhs) {
    return static_cast<int64_t>(lhs | static_cast<int64_t>(rhs));
}
constexpr int64_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting lhs, const int64_t rhs) {
    return static_cast<int64_t>(static_cast<int64_t>(lhs) | rhs);
}
constexpr int64_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting rhs) {
    return static_cast<int64_t>(static_cast<int64_t>(lhs) & static_cast<int64_t>(rhs));
}
constexpr int64_t operator&(const int64_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting rhs) {
    return static_cast<int64_t>(lhs & static_cast<int64_t>(rhs));
}
constexpr int64_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting lhs, const int64_t rhs) {
    return static_cast<int64_t>(static_cast<int64_t>(lhs) & rhs);
}
constexpr int64_t &operator|=(int64_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting e) {
    v |= static_cast<int64_t>(e);
    return v;
}
constexpr int64_t &operator&=(int64_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting e) {
    v &= static_cast<int64_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint64_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting o);

constexpr uint64_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting rhs) {
    return static_cast<uint64_t>(static_cast<uint64_t>(lhs) | static_cast<uint64_t>(rhs));
}
constexpr uint64_t operator|(const uint64_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting rhs) {
    return static_cast<uint64_t>(lhs | static_cast<uint64_t>(rhs));
}
constexpr uint64_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting lhs, const uint64_t rhs) {
    return static_cast<uint64_t>(static_cast<uint64_t>(lhs) | rhs);
}
constexpr uint64_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting rhs) {
    return static_cast<uint64_t>(static_cast<uint64_t>(lhs) & static_cast<uint64_t>(rhs));
}
constexpr uint64_t operator&(const uint64_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting rhs) {
    return static_cast<uint64_t>(lhs & static_cast<uint64_t>(rhs));
}
constexpr uint64_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting lhs, const uint64_t rhs) {
    return static_cast<uint64_t>(static_cast<uint64_t>(lhs) & rhs);
}
constexpr uint64_t &operator|=(uint64_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting e) {
    v |= static_cast<uint64_t>(e);
    return v;
}
constexpr uint64_t &operator&=(uint64_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting e) {
    v &= static_cast<uint64_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Precedence o);

constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Precedence lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Precedence rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Precedence rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Precedence lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Precedence lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Precedence rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Precedence rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Precedence lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Precedence e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Precedence e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck o);

constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck lhs, const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck lhs, const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::NoElements o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::NoElements lhs, const ::android::hardware::tests::expression::V1_0::IExpression::NoElements rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::NoElements rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::NoElements lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::NoElements lhs, const ::android::hardware::tests::expression::V1_0::IExpression::NoElements rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::NoElements rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::NoElements lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::NoElements e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::NoElements e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::OneElement o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::OneElement lhs, const ::android::hardware::tests::expression::V1_0::IExpression::OneElement rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::OneElement rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::OneElement lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::OneElement lhs, const ::android::hardware::tests::expression::V1_0::IExpression::OneElement rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::OneElement rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::OneElement lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::OneElement e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::OneElement e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::TwoElement o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement lhs, const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement lhs, const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::TwoElement e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements lhs, const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements lhs, const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest o);

constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest lhs, const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest lhs, const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int8_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Grayscale o);

constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale rhs) {
    return static_cast<int8_t>(lhs | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | rhs);
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale rhs) {
    return static_cast<int8_t>(lhs & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & rhs);
}
constexpr int8_t &operator|=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale e) {
    v |= static_cast<int8_t>(e);
    return v;
}
constexpr int8_t &operator&=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Grayscale e) {
    v &= static_cast<int8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int8_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Color o);

constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Color lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Color rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Color rhs) {
    return static_cast<int8_t>(lhs | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Color lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | rhs);
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Color lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Color rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Color rhs) {
    return static_cast<int8_t>(lhs & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Color lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & rhs);
}
constexpr int8_t &operator|=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Color e) {
    v |= static_cast<int8_t>(e);
    return v;
}
constexpr int8_t &operator&=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Color e) {
    v &= static_cast<int8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int8_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Foo1 o);

constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 rhs) {
    return static_cast<int8_t>(lhs | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | rhs);
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 rhs) {
    return static_cast<int8_t>(lhs & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & rhs);
}
constexpr int8_t &operator|=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 e) {
    v |= static_cast<int8_t>(e);
    return v;
}
constexpr int8_t &operator&=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Foo1 e) {
    v &= static_cast<int8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int8_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Foo2 o);

constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 rhs) {
    return static_cast<int8_t>(lhs | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | rhs);
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 rhs) {
    return static_cast<int8_t>(lhs & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & rhs);
}
constexpr int8_t &operator|=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 e) {
    v |= static_cast<int8_t>(e);
    return v;
}
constexpr int8_t &operator&=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Foo2 e) {
    v &= static_cast<int8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int8_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Foo3 o);

constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 rhs) {
    return static_cast<int8_t>(lhs | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | rhs);
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 rhs) {
    return static_cast<int8_t>(lhs & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & rhs);
}
constexpr int8_t &operator|=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 e) {
    v |= static_cast<int8_t>(e);
    return v;
}
constexpr int8_t &operator&=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Foo3 e) {
    v &= static_cast<int8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int8_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Foo4 o);

constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 rhs) {
    return static_cast<int8_t>(lhs | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | rhs);
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const int8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 rhs) {
    return static_cast<int8_t>(lhs & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & rhs);
}
constexpr int8_t &operator|=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 e) {
    v |= static_cast<int8_t>(e);
    return v;
}
constexpr int8_t &operator&=(int8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Foo4 e) {
    v &= static_cast<int8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Number o);

constexpr uint8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Number lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Number rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Number rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Number lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Number lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Number rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Number rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Number lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Number e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Number e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Constants o);

constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Constants lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Constants rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Constants rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpression::Constants lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Constants lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Constants rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpression::Constants rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpression::Constants lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Constants e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpression::Constants e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::expression::V1_0::IExpression>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing>(uint64_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec1) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec1)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec2) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec2)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec3) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec3)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec4) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec4)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec4";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec4;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec5) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec5)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec5";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec5;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec6) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec6)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec6";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec6;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec7) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec7)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec7";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec7;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec8) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec8)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec8";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec8;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec9) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec9)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec9";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec9;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex1) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex1)) {
        os += (first ? "" : " | ");
        os += "noSuffixHex1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex2) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex2)) {
        os += (first ? "" : " | ");
        os += "noSuffixHex2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex3) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex3)) {
        os += (first ? "" : " | ");
        os += "noSuffixHex3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex1) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex1)) {
        os += (first ? "" : " | ");
        os += "longHex1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex2) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex2)) {
        os += (first ? "" : " | ");
        os += "longHex2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex3) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex3)) {
        os += (first ? "" : " | ");
        os += "longHex3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex4) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex4)) {
        os += (first ? "" : " | ");
        os += "longHex4";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex4;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex5) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex5)) {
        os += (first ? "" : " | ");
        os += "longHex5";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex5;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec1) {
        return "noSuffixDec1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec2) {
        return "noSuffixDec2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec3) {
        return "noSuffixDec3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec4) {
        return "noSuffixDec4";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec5) {
        return "noSuffixDec5";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec6) {
        return "noSuffixDec6";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec7) {
        return "noSuffixDec7";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec8) {
        return "noSuffixDec8";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec9) {
        return "noSuffixDec9";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex1) {
        return "noSuffixHex1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex2) {
        return "noSuffixHex2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex3) {
        return "noSuffixHex3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex1) {
        return "longHex1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex2) {
        return "longHex2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex3) {
        return "longHex3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex4) {
        return "longHex4";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex5) {
        return "longHex5";
    }
    std::string os;
    os += toHexString(static_cast<uint64_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_1)) {
        os += (first ? "" : " | ");
        os += "decInt32_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_2)) {
        os += (first ? "" : " | ");
        os += "decInt32_2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_1)) {
        os += (first ? "" : " | ");
        os += "decInt64_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_2)) {
        os += (first ? "" : " | ");
        os += "decInt64_2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_3) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_3)) {
        os += (first ? "" : " | ");
        os += "decInt64_3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_4) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_4)) {
        os += (first ? "" : " | ");
        os += "decInt64_4";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_4;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt32_1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt32_1)) {
        os += (first ? "" : " | ");
        os += "hexInt32_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt32_1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_1)) {
        os += (first ? "" : " | ");
        os += "hexUInt32_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_2)) {
        os += (first ? "" : " | ");
        os += "hexUInt32_2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt64_1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt64_1)) {
        os += (first ? "" : " | ");
        os += "hexInt64_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt64_1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt64_1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt64_1)) {
        os += (first ? "" : " | ");
        os += "hexUInt64_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt64_1;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_1) {
        return "decInt32_1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_2) {
        return "decInt32_2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_1) {
        return "decInt64_1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_2) {
        return "decInt64_2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_3) {
        return "decInt64_3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_4) {
        return "decInt64_4";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt32_1) {
        return "hexInt32_1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_1) {
        return "hexUInt32_1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_2) {
        return "hexUInt32_2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt64_1) {
        return "hexInt64_1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt64_1) {
        return "hexUInt64_1";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing>(int64_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec11) == static_cast<int64_t>(::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec11)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec11";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec11;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec12) == static_cast<int64_t>(::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec12)) {
        os += (first ? "" : " | ");
        os += "noSuffixDec12";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec12;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec11) {
        return "noSuffixDec11";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec12) {
        return "noSuffixDec12";
    }
    std::string os;
    os += toHexString(static_cast<int64_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting::int32BitShift1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting::int32BitShift1)) {
        os += (first ? "" : " | ");
        os += "int32BitShift1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting::int32BitShift1;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting::int32BitShift1) {
        return "int32BitShift1";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting::uint32BitShift1) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting::uint32BitShift1)) {
        os += (first ? "" : " | ");
        os += "uint32BitShift1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting::uint32BitShift1;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting::uint32BitShift1) {
        return "uint32BitShift1";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting>(int64_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting::int64BitShift1) == static_cast<int64_t>(::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting::int64BitShift1)) {
        os += (first ? "" : " | ");
        os += "int64BitShift1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting::int64BitShift1;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting::int64BitShift1) {
        return "int64BitShift1";
    }
    std::string os;
    os += toHexString(static_cast<int64_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting>(uint64_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting::uint64BitShift1) == static_cast<uint64_t>(::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting::uint64BitShift1)) {
        os += (first ? "" : " | ");
        os += "uint64BitShift1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting::uint64BitShift1;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting::uint64BitShift1) {
        return "uint64BitShift1";
    }
    std::string os;
    os += toHexString(static_cast<uint64_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Precedence>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Precedence> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::literal) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::literal)) {
        os += (first ? "" : " | ");
        os += "literal";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::literal;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::neg) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::neg)) {
        os += (first ? "" : " | ");
        os += "neg";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::neg;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::literalL) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::literalL)) {
        os += (first ? "" : " | ");
        os += "literalL";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::literalL;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hex) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::hex)) {
        os += (first ? "" : " | ");
        os += "hex";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hex;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong)) {
        os += (first ? "" : " | ");
        os += "hexLong";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong2)) {
        os += (first ? "" : " | ");
        os += "hexLong2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic)) {
        os += (first ? "" : " | ");
        os += "simpleArithmetic";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic2)) {
        os += (first ? "" : " | ");
        os += "simpleArithmetic2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic3) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic3)) {
        os += (first ? "" : " | ");
        os += "simpleArithmetic3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBoolExpr) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBoolExpr)) {
        os += (first ? "" : " | ");
        os += "simpleBoolExpr";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBoolExpr;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical)) {
        os += (first ? "" : " | ");
        os += "simpleLogical";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical2)) {
        os += (first ? "" : " | ");
        os += "simpleLogical2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleComp) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleComp)) {
        os += (first ? "" : " | ");
        os += "simpleComp";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleComp;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr1)) {
        os += (first ? "" : " | ");
        os += "boolExpr1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr)) {
        os += (first ? "" : " | ");
        os += "boolExpr";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift)) {
        os += (first ? "" : " | ");
        os += "simpleBitShift";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift2)) {
        os += (first ? "" : " | ");
        os += "simpleBitShift2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShiftNeg) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShiftNeg)) {
        os += (first ? "" : " | ");
        os += "simpleBitShiftNeg";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShiftNeg;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmeticRightShift) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmeticRightShift)) {
        os += (first ? "" : " | ");
        os += "simpleArithmeticRightShift";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmeticRightShift;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr)) {
        os += (first ? "" : " | ");
        os += "simpleBitExpr";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr2)) {
        os += (first ? "" : " | ");
        os += "simpleBitExpr2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::bitExpr) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::bitExpr)) {
        os += (first ? "" : " | ");
        os += "bitExpr";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::bitExpr;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::arithmeticExpr) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::arithmeticExpr)) {
        os += (first ? "" : " | ");
        os += "arithmeticExpr";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::arithmeticExpr;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::messyExpr) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::messyExpr)) {
        os += (first ? "" : " | ");
        os += "messyExpr";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::messyExpr;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::paranExpr) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::paranExpr)) {
        os += (first ? "" : " | ");
        os += "paranExpr";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::paranExpr;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary)) {
        os += (first ? "" : " | ");
        os += "ternary";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary2)) {
        os += (first ? "" : " | ");
        os += "ternary2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Precedence::complicatedTernary2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Precedence::complicatedTernary2)) {
        os += (first ? "" : " | ");
        os += "complicatedTernary2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Precedence::complicatedTernary2;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Precedence o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::literal) {
        return "literal";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::neg) {
        return "neg";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::literalL) {
        return "literalL";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hex) {
        return "hex";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong) {
        return "hexLong";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong2) {
        return "hexLong2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic) {
        return "simpleArithmetic";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic2) {
        return "simpleArithmetic2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic3) {
        return "simpleArithmetic3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBoolExpr) {
        return "simpleBoolExpr";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical) {
        return "simpleLogical";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical2) {
        return "simpleLogical2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleComp) {
        return "simpleComp";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr1) {
        return "boolExpr1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr) {
        return "boolExpr";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift) {
        return "simpleBitShift";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift2) {
        return "simpleBitShift2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShiftNeg) {
        return "simpleBitShiftNeg";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmeticRightShift) {
        return "simpleArithmeticRightShift";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr) {
        return "simpleBitExpr";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr2) {
        return "simpleBitExpr2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::bitExpr) {
        return "bitExpr";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::arithmeticExpr) {
        return "arithmeticExpr";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::messyExpr) {
        return "messyExpr";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::paranExpr) {
        return "paranExpr";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary) {
        return "ternary";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary2) {
        return "ternary2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Precedence::complicatedTernary2) {
        return "complicatedTernary2";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::plus) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::plus)) {
        os += (first ? "" : " | ");
        os += "plus";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::plus;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::minus) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::minus)) {
        os += (first ? "" : " | ");
        os += "minus";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::minus;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::product) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::product)) {
        os += (first ? "" : " | ");
        os += "product";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::product;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::division) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::division)) {
        os += (first ? "" : " | ");
        os += "division";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::division;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::mod) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::mod)) {
        os += (first ? "" : " | ");
        os += "mod";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::mod;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or)) {
        os += (first ? "" : " | ");
        os += "bit_or";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or2)) {
        os += (first ? "" : " | ");
        os += "bit_or2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_and) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_and)) {
        os += (first ? "" : " | ");
        os += "bit_and";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_and;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_xor) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_xor)) {
        os += (first ? "" : " | ");
        os += "bit_xor";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_xor;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt1)) {
        os += (first ? "" : " | ");
        os += "lt1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt2)) {
        os += (first ? "" : " | ");
        os += "lt2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt1)) {
        os += (first ? "" : " | ");
        os += "gt1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt2)) {
        os += (first ? "" : " | ");
        os += "gt2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte1)) {
        os += (first ? "" : " | ");
        os += "gte1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte2)) {
        os += (first ? "" : " | ");
        os += "gte2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte1)) {
        os += (first ? "" : " | ");
        os += "lte1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte2)) {
        os += (first ? "" : " | ");
        os += "lte2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne1)) {
        os += (first ? "" : " | ");
        os += "ne1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne2)) {
        os += (first ? "" : " | ");
        os += "ne2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lshift) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lshift)) {
        os += (first ? "" : " | ");
        os += "lshift";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lshift;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::rshift) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::rshift)) {
        os += (first ? "" : " | ");
        os += "rshift";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::rshift;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor1)) {
        os += (first ? "" : " | ");
        os += "logor1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor2)) {
        os += (first ? "" : " | ");
        os += "logor2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor3) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor3)) {
        os += (first ? "" : " | ");
        os += "logor3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor4) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor4)) {
        os += (first ? "" : " | ");
        os += "logor4";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor4;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand1)) {
        os += (first ? "" : " | ");
        os += "logand1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand2)) {
        os += (first ? "" : " | ");
        os += "logand2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand3) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand3)) {
        os += (first ? "" : " | ");
        os += "logand3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand4) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand4)) {
        os += (first ? "" : " | ");
        os += "logand4";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand4;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::plus) {
        return "plus";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::minus) {
        return "minus";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::product) {
        return "product";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::division) {
        return "division";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::mod) {
        return "mod";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or) {
        return "bit_or";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or2) {
        return "bit_or2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_and) {
        return "bit_and";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_xor) {
        return "bit_xor";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt1) {
        return "lt1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt2) {
        return "lt2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt1) {
        return "gt1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt2) {
        return "gt2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte1) {
        return "gte1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte2) {
        return "gte2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte1) {
        return "lte1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte2) {
        return "lte2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne1) {
        return "ne1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne2) {
        return "ne2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lshift) {
        return "lshift";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::rshift) {
        return "rshift";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor1) {
        return "logor1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor2) {
        return "logor2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor3) {
        return "logor3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor4) {
        return "logor4";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand1) {
        return "logand1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand2) {
        return "logand2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand3) {
        return "logand3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand4) {
        return "logand4";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::NoElements>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::NoElements> flipped = 0;
    bool first = true;
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::NoElements o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::OneElement>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::OneElement> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::OneElement::A) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::OneElement::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::OneElement::A;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::OneElement o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::OneElement::A) {
        return "A";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::TwoElement>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::TwoElement> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::TwoElement::A) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::TwoElement::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::TwoElement::A;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::TwoElement::B) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::TwoElement::B)) {
        os += (first ? "" : " | ");
        os += "B";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::TwoElement::B;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::TwoElement o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::TwoElement::A) {
        return "A";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::TwoElement::B) {
        return "B";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::A) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::A;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::B) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::B)) {
        os += (first ? "" : " | ");
        os += "B";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::B;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::A) {
        return "A";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::B) {
        return "B";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::A) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::A;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::B) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::B)) {
        os += (first ? "" : " | ");
        os += "B";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::B;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::C) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::C)) {
        os += (first ? "" : " | ");
        os += "C";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::C;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::A) {
        return "A";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::B) {
        return "B";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::C) {
        return "C";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::A) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::A;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::B) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::B)) {
        os += (first ? "" : " | ");
        os += "B";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::B;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::C) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::C)) {
        os += (first ? "" : " | ");
        os += "C";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::C;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::A) {
        return "A";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::B) {
        return "B";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::C) {
        return "C";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::A) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::A)) {
        os += (first ? "" : " | ");
        os += "A";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::A;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::B) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::B)) {
        os += (first ? "" : " | ");
        os += "B";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::B;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::C) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::C)) {
        os += (first ? "" : " | ");
        os += "C";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::C;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::A) {
        return "A";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::B) {
        return "B";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::C) {
        return "C";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::a) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::a)) {
        os += (first ? "" : " | ");
        os += "a";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::a;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::b) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::b)) {
        os += (first ? "" : " | ");
        os += "b";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::b;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::c) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::c)) {
        os += (first ? "" : " | ");
        os += "c";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::c;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::d) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::d)) {
        os += (first ? "" : " | ");
        os += "d";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::d;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::e) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::e)) {
        os += (first ? "" : " | ");
        os += "e";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::e;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::f) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::f)) {
        os += (first ? "" : " | ");
        os += "f";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::f;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::g) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::g)) {
        os += (first ? "" : " | ");
        os += "g";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::g;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::h) == static_cast<uint32_t>(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::h)) {
        os += (first ? "" : " | ");
        os += "h";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::h;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::a) {
        return "a";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::b) {
        return "b";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::c) {
        return "c";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::d) {
        return "d";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::e) {
        return "e";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::f) {
        return "f";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::g) {
        return "g";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::h) {
        return "h";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Grayscale>(int8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Grayscale> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::WHITE) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Grayscale::WHITE)) {
        os += (first ? "" : " | ");
        os += "WHITE";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::WHITE;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::GRAY) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Grayscale::GRAY)) {
        os += (first ? "" : " | ");
        os += "GRAY";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::GRAY;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::DARK_GRAY) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Grayscale::DARK_GRAY)) {
        os += (first ? "" : " | ");
        os += "DARK_GRAY";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::DARK_GRAY;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::BLACK) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Grayscale::BLACK)) {
        os += (first ? "" : " | ");
        os += "BLACK";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::BLACK;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Grayscale o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::WHITE) {
        return "WHITE";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::GRAY) {
        return "GRAY";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::DARK_GRAY) {
        return "DARK_GRAY";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::BLACK) {
        return "BLACK";
    }
    std::string os;
    os += toHexString(static_cast<int8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Color>(int8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Color> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::WHITE) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::WHITE)) {
        os += (first ? "" : " | ");
        os += "WHITE";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::WHITE;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::GRAY) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::GRAY)) {
        os += (first ? "" : " | ");
        os += "GRAY";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::GRAY;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::DARK_GRAY) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::DARK_GRAY)) {
        os += (first ? "" : " | ");
        os += "DARK_GRAY";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::DARK_GRAY;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::BLACK) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::BLACK)) {
        os += (first ? "" : " | ");
        os += "BLACK";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::BLACK;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::RED) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::RED)) {
        os += (first ? "" : " | ");
        os += "RED";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::RED;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::RUBY) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::RUBY)) {
        os += (first ? "" : " | ");
        os += "RUBY";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::RUBY;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::GREEN) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::GREEN)) {
        os += (first ? "" : " | ");
        os += "GREEN";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::GREEN;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::BLUE) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::BLUE)) {
        os += (first ? "" : " | ");
        os += "BLUE";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::BLUE;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::CYAN) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::CYAN)) {
        os += (first ? "" : " | ");
        os += "CYAN";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::CYAN;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::ORANGE) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::ORANGE)) {
        os += (first ? "" : " | ");
        os += "ORANGE";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::ORANGE;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Color::ROSE) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Color::ROSE)) {
        os += (first ? "" : " | ");
        os += "ROSE";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Color::ROSE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Color o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::WHITE) {
        return "WHITE";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::GRAY) {
        return "GRAY";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::DARK_GRAY) {
        return "DARK_GRAY";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::BLACK) {
        return "BLACK";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::RED) {
        return "RED";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::RUBY) {
        return "RUBY";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::GREEN) {
        return "GREEN";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::BLUE) {
        return "BLUE";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::CYAN) {
        return "CYAN";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::ORANGE) {
        return "ORANGE";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Color::ROSE) {
        return "ROSE";
    }
    std::string os;
    os += toHexString(static_cast<int8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Foo1>(int8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Foo1> flipped = 0;
    bool first = true;
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Foo1 o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    os += toHexString(static_cast<int8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Foo2>(int8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Foo2> flipped = 0;
    bool first = true;
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Foo2 o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    os += toHexString(static_cast<int8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Foo3>(int8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Foo3> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR1) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR1)) {
        os += (first ? "" : " | ");
        os += "BAR1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR2) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR2)) {
        os += (first ? "" : " | ");
        os += "BAR2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR2;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Foo3 o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR1) {
        return "BAR1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR2) {
        return "BAR2";
    }
    std::string os;
    os += toHexString(static_cast<int8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Foo4>(int8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Foo4> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR1) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR1)) {
        os += (first ? "" : " | ");
        os += "BAR1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR2) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR2)) {
        os += (first ? "" : " | ");
        os += "BAR2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR3) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR3)) {
        os += (first ? "" : " | ");
        os += "BAR3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR4) == static_cast<int8_t>(::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR4)) {
        os += (first ? "" : " | ");
        os += "BAR4";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR4;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Foo4 o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR1) {
        return "BAR1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR2) {
        return "BAR2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR3) {
        return "BAR3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR4) {
        return "BAR4";
    }
    std::string os;
    os += toHexString(static_cast<int8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Number>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Number> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX) == static_cast<uint8_t>(::android::hardware::tests::expression::V1_0::IExpression::Number::MAX)) {
        os += (first ? "" : " | ");
        os += "MAX";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_1) == static_cast<uint8_t>(::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_1)) {
        os += (first ? "" : " | ");
        os += "MAX_PLUS_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_2) == static_cast<uint8_t>(::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_2)) {
        os += (first ? "" : " | ");
        os += "MAX_PLUS_2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_2;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Number o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX) {
        return "MAX";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_1) {
        return "MAX_PLUS_1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_2) {
        return "MAX_PLUS_2";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpression::Constants>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpression::Constants> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_FOO) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_FOO)) {
        os += (first ? "" : " | ");
        os += "CONST_FOO";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_FOO;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_BAR) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_BAR)) {
        os += (first ? "" : " | ");
        os += "CONST_BAR";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_BAR;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE)) {
        os += (first ? "" : " | ");
        os += "MAX_ARRAY_SIZE";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE2) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE2)) {
        os += (first ? "" : " | ");
        os += "MAX_ARRAY_SIZE2";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE2;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE3) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE3)) {
        os += (first ? "" : " | ");
        os += "MAX_ARRAY_SIZE3";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE3;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX_MINUS_1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX_MINUS_1)) {
        os += (first ? "" : " | ");
        os += "MY_INT32_MAX_MINUS_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX_MINUS_1;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX)) {
        os += (first ? "" : " | ");
        os += "MY_INT32_MAX";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN)) {
        os += (first ? "" : " | ");
        os += "MY_INT32_MIN";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN_PLUS_1) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN_PLUS_1)) {
        os += (first ? "" : " | ");
        os += "MY_INT32_MIN_PLUS_1";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN_PLUS_1;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpression::Constants o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_FOO) {
        return "CONST_FOO";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_BAR) {
        return "CONST_BAR";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE) {
        return "MAX_ARRAY_SIZE";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE2) {
        return "MAX_ARRAY_SIZE2";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE3) {
        return "MAX_ARRAY_SIZE3";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX_MINUS_1) {
        return "MY_INT32_MAX_MINUS_1";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX) {
        return "MY_INT32_MAX";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN) {
        return "MY_INT32_MIN";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN_PLUS_1) {
        return "MY_INT32_MIN_PLUS_1";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::expression::V1_0::IExpression>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::expression::V1_0::IExpression::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace expression
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing, 17> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing> = {
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec1,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec2,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec3,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec4,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec5,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec6,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec7,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec8,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixDec9,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex1,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex2,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::noSuffixHex3,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex1,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex2,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex3,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex4,
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64LiteralTypeGuessing::longHex5,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing, 11> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing> = {
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_1,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt32_2,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_1,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_2,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_3,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::decInt64_4,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt32_1,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_1,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt32_2,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexInt64_1,
    ::android::hardware::tests::expression::V1_0::IExpression::SuffixedLiteralTypeGuessing::hexUInt64_1,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing, 2> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec11,
    ::android::hardware::tests::expression::V1_0::IExpression::Int64LiteralTypeGuessing::noSuffixDec12,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting, 1> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Int32BitShifting::int32BitShift1,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting, 1> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting> = {
    ::android::hardware::tests::expression::V1_0::IExpression::UInt32BitShifting::uint32BitShift1,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting, 1> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Int64BitShifting::int64BitShift1,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting, 1> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting> = {
    ::android::hardware::tests::expression::V1_0::IExpression::UInt64BitShifting::uint64BitShift1,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Precedence, 28> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Precedence> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::literal,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::neg,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::literalL,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hex,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::hexLong2,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic2,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmetic3,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBoolExpr,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleLogical2,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleComp,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr1,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::boolExpr,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShift2,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitShiftNeg,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleArithmeticRightShift,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::simpleBitExpr2,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::bitExpr,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::arithmeticExpr,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::messyExpr,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::paranExpr,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::ternary2,
    ::android::hardware::tests::expression::V1_0::IExpression::Precedence::complicatedTernary2,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck, 29> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck> = {
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::plus,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::minus,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::product,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::division,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::mod,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_or2,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_and,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::bit_xor,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt1,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lt2,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt1,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gt2,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte1,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::gte2,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte1,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lte2,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne1,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::ne2,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::lshift,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::rshift,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor1,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor2,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor3,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logor4,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand1,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand2,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand3,
    ::android::hardware::tests::expression::V1_0::IExpression::OperatorSanityCheck::logand4,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::NoElements, 0> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::NoElements> = {
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::OneElement, 1> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::OneElement> = {
    ::android::hardware::tests::expression::V1_0::IExpression::OneElement::A,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::TwoElement, 2> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::TwoElement> = {
    ::android::hardware::tests::expression::V1_0::IExpression::TwoElement::A,
    ::android::hardware::tests::expression::V1_0::IExpression::TwoElement::B,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements, 2> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements> = {
    ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::A,
    ::android::hardware::tests::expression::V1_0::IExpression::TwoCollidingElements::B,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance, 3> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance> = {
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::A,
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::B,
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromInheritance::C,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance, 3> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance> = {
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::A,
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::B,
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeFromDoubleInheritance::C,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance, 3> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance> = {
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::A,
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::B,
    ::android::hardware::tests::expression::V1_0::IExpression::ThreeCollidingFromInheritance::C,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest, 8> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest> = {
    ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::a,
    ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::b,
    ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::c,
    ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::d,
    ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::e,
    ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::f,
    ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::g,
    ::android::hardware::tests::expression::V1_0::IExpression::EnumTagTest::h,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Grayscale, 4> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Grayscale> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::WHITE,
    ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::GRAY,
    ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::DARK_GRAY,
    ::android::hardware::tests::expression::V1_0::IExpression::Grayscale::BLACK,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Color, 11> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Color> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Color::WHITE,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::GRAY,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::DARK_GRAY,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::BLACK,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::RED,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::RUBY,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::GREEN,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::BLUE,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::CYAN,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::ORANGE,
    ::android::hardware::tests::expression::V1_0::IExpression::Color::ROSE,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Foo1, 0> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Foo1> = {
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Foo2, 0> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Foo2> = {
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Foo3, 2> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Foo3> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR1,
    ::android::hardware::tests::expression::V1_0::IExpression::Foo3::BAR2,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Foo4, 4> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Foo4> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR1,
    ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR2,
    ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR3,
    ::android::hardware::tests::expression::V1_0::IExpression::Foo4::BAR4,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Number, 3> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Number> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX,
    ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_1,
    ::android::hardware::tests::expression::V1_0::IExpression::Number::MAX_PLUS_2,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpression::Constants, 9> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpression::Constants> = {
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_FOO,
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::CONST_BAR,
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE,
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE2,
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::MAX_ARRAY_SIZE3,
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX_MINUS_1,
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MAX,
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN,
    ::android::hardware::tests::expression::V1_0::IExpression::Constants::MY_INT32_MIN_PLUS_1,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_IEXPRESSION_H
