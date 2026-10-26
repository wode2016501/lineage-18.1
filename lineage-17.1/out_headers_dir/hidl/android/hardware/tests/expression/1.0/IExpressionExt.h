#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_IEXPRESSIONEXT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_IEXPRESSIONEXT_H

#include <android/hardware/tests/expression/1.0/IExpression.h>
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

struct IExpressionExt : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.expression@1.0::IExpressionExt"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class NewEnum : int32_t;
    struct ArrayOfColors;
    struct AnotherArrayOfColors;

    enum class NewEnum : int32_t {
        ENUM_GOOD = 70 /* Constants:CONST_BAR */,
        ENUM_BETTER = 70 /* IExpression.Constants:CONST_BAR */,
        ENUM_BEST = 70 /* android.hardware.tests.expression@1.0::IExpression.Constants:CONST_BAR */,
    };

    typedef ::android::hardware::tests::expression::V1_0::IExpression::Constants AlsoConstants;

    typedef ::android::hardware::hidl_array<::android::hardware::tests::expression::V1_0::IExpression::Color, 16 /* (((Constants:MAX_ARRAY_SIZE << 1) - ((AlsoConstants:CONST_FOO + 1) * 8)) >> 1) */> SixteenColors;

    struct ArrayOfColors final {
        ::android::hardware::hidl_array<::android::hardware::tests::expression::V1_0::IExpression::Color, 32 /* ((Constants:MAX_ARRAY_SIZE << 1) - ((Constants:CONST_FOO + 1) * 8)) */> my32Colors __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors, my32Colors) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors) == 32, "wrong size");
    static_assert(__alignof(::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors) == 1, "wrong alignment");

    struct AnotherArrayOfColors final {
        ::android::hardware::hidl_array<::android::hardware::tests::expression::V1_0::IExpression::Color, 16 /* (((Constants:MAX_ARRAY_SIZE << 1) - ((AlsoConstants:CONST_FOO + 1) * 8)) >> 1) */> my16Colors __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors, my16Colors) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors) == 16, "wrong size");
    static_assert(__alignof(::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors) == 1, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    // @callflow(key=20 /* @1.0::IExpression.Constants:MAX_ARRAY_SIZE */)
    virtual ::android::hardware::Return<void> foo3(const ::android::hardware::hidl_array<int32_t, 20 /* IExpression.Constants:MAX_ARRAY_SIZE */>& array) = 0;

    virtual ::android::hardware::Return<void> foo2(const ::android::hardware::hidl_array<::android::hardware::tests::expression::V1_0::IExpression::Color, 16 /* (((Constants:MAX_ARRAY_SIZE << 1) - ((AlsoConstants:CONST_FOO + 1) * 8)) >> 1) */>& array) = 0;

    virtual ::android::hardware::Return<void> foo1(const ::android::hardware::hidl_array<int32_t, 5 /* (Constants:CONST_FOO + 5) */>& array) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::expression::V1_0::IExpressionExt>> castFrom(const ::android::sp<::android::hardware::tests::expression::V1_0::IExpressionExt>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::expression::V1_0::IExpressionExt>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IExpressionExt> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IExpressionExt> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IExpressionExt> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IExpressionExt> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IExpressionExt> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IExpressionExt> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IExpressionExt> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IExpressionExt> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum o);

constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& o);
static inline bool operator==(const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& rhs);
static inline bool operator!=(const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& rhs);

static inline std::string toString(const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& o);
static inline bool operator==(const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& rhs);
static inline bool operator!=(const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::tests::expression::V1_0::IExpressionExt>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_GOOD) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_GOOD)) {
        os += (first ? "" : " | ");
        os += "ENUM_GOOD";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_GOOD;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BETTER) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BETTER)) {
        os += (first ? "" : " | ");
        os += "ENUM_BETTER";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BETTER;
    }
    if ((o & ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BEST) == static_cast<int32_t>(::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BEST)) {
        os += (first ? "" : " | ");
        os += "ENUM_BEST";
        first = false;
        flipped |= ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BEST;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_GOOD) {
        return "ENUM_GOOD";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BETTER) {
        return "ENUM_BETTER";
    }
    if (o == ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BEST) {
        return "ENUM_BEST";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".my32Colors = ";
    os += ::android::hardware::toString(o.my32Colors);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& rhs) {
    if (lhs.my32Colors != rhs.my32Colors) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::ArrayOfColors& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".my16Colors = ";
    os += ::android::hardware::toString(o.my16Colors);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& rhs) {
    if (lhs.my16Colors != rhs.my16Colors) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& lhs, const ::android::hardware::tests::expression::V1_0::IExpressionExt::AnotherArrayOfColors& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::expression::V1_0::IExpressionExt>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::expression::V1_0::IExpressionExt::descriptor;
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
template<> constexpr std::array<::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum, 3> hidl_enum_values<::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum> = {
    ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_GOOD,
    ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BETTER,
    ::android::hardware::tests::expression::V1_0::IExpressionExt::NewEnum::ENUM_BEST,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_EXPRESSION_V1_0_IEXPRESSIONEXT_H
