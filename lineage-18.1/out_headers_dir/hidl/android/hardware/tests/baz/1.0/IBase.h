#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_IBASE_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_IBASE_H

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
namespace baz {
namespace V1_0 {

struct IBase : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.baz@1.0::IBase"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class SomeBaseEnum : int32_t;
    struct Foo;
    struct MoreThanOneArrayField;
    struct StringMatrix3x5;
    struct StringMatrix5x3;
    struct VectorOfArray;
    enum class BitField : uint8_t;
    struct MyMask;
    struct LotsOfPrimitiveArrays;

    enum class SomeBaseEnum : int32_t {
        grrr = 1,
    };

    struct Foo final {
        // Forward declaration for forward reference support:
        struct Bar;
        enum class FooEnum : int8_t;

        struct Bar final {
            float z __attribute__ ((aligned(4)));
            ::android::hardware::hidl_string s __attribute__ ((aligned(8)));
        };

        static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::Foo::Bar, z) == 0, "wrong offset");
        static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::Foo::Bar, s) == 8, "wrong offset");
        static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBase::Foo::Bar) == 24, "wrong size");
        static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBase::Foo::Bar) == 8, "wrong alignment");

        enum class FooEnum : int8_t {
            first = 1,
            second = 2,
        };

        int32_t x __attribute__ ((aligned(4)));
        ::android::hardware::hidl_vec<::android::hardware::tests::baz::V1_0::IBase::Foo::Bar> aaa __attribute__ ((aligned(8)));
        ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar y __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::Foo, x) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::Foo, aaa) == 8, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::Foo, y) == 24, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBase::Foo) == 48, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBase::Foo) == 8, "wrong alignment");

    struct MoreThanOneArrayField final {
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 3> one __attribute__ ((aligned(8)));
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 5> two __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField, one) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField, two) == 48, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField) == 128, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField) == 8, "wrong alignment");

    typedef ::android::hardware::hidl_array<::android::hardware::hidl_string, 3> ThreeStrings;

    typedef ::android::hardware::hidl_array<::android::hardware::hidl_string, 5> FiveStrings;

    struct StringMatrix3x5 final {
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 3, 5> s __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5, s) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5) == 240, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5) == 8, "wrong alignment");

    struct StringMatrix5x3 final {
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 5, 3> s __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3, s) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3) == 240, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3) == 8, "wrong alignment");

    typedef ::android::hardware::hidl_array<uint8_t, 6> MacAddress;

    struct VectorOfArray final {
        ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 6>> addresses __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::VectorOfArray, addresses) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBase::VectorOfArray) == 16, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBase::VectorOfArray) == 8, "wrong alignment");

    enum class BitField : uint8_t {
        V0 = 1 /* (1 << 0) */,
        V1 = 2 /* (1 << 1) */,
        V2 = 4 /* (1 << 2) */,
        V3 = 8 /* (1 << 3) */,
    };

    struct MyMask final {
        ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> value __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::MyMask, value) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBase::MyMask) == 1, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBase::MyMask) == 1, "wrong alignment");

    typedef ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> Mask;

    typedef ::android::hardware::hidl_array<uint8_t, 128> ByteOneDim;

    typedef ::android::hardware::hidl_array<uint8_t, 8, 128> ByteTwoDim;

    typedef ::android::hardware::hidl_array<uint8_t, 8, 16, 128> ByteThreeDim;

    typedef ::android::hardware::hidl_array<bool, 128> BooleanOneDim;

    typedef ::android::hardware::hidl_array<bool, 8, 128> BooleanTwoDim;

    typedef ::android::hardware::hidl_array<bool, 8, 16, 128> BooleanThreeDim;

    typedef ::android::hardware::hidl_array<double, 128> DoubleOneDim;

    typedef ::android::hardware::hidl_array<double, 8, 128> DoubleTwoDim;

    typedef ::android::hardware::hidl_array<double, 8, 16, 128> DoubleThreeDim;

    struct LotsOfPrimitiveArrays final {
        ::android::hardware::hidl_array<uint8_t, 128> byte1 __attribute__ ((aligned(1)));
        ::android::hardware::hidl_array<uint8_t, 8, 128> byte2 __attribute__ ((aligned(1)));
        ::android::hardware::hidl_array<uint8_t, 8, 16, 128> byte3 __attribute__ ((aligned(1)));
        ::android::hardware::hidl_array<bool, 128> boolean1 __attribute__ ((aligned(1)));
        ::android::hardware::hidl_array<bool, 8, 128> boolean2 __attribute__ ((aligned(1)));
        ::android::hardware::hidl_array<bool, 8, 16, 128> boolean3 __attribute__ ((aligned(1)));
        ::android::hardware::hidl_array<double, 128> double1 __attribute__ ((aligned(8)));
        ::android::hardware::hidl_array<double, 8, 128> double2 __attribute__ ((aligned(8)));
        ::android::hardware::hidl_array<double, 8, 16, 128> double3 __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, byte1) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, byte2) == 128, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, byte3) == 1152, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, boolean1) == 17536, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, boolean2) == 17664, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, boolean3) == 18688, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, double1) == 35072, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, double2) == 36096, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays, double3) == 44288, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays) == 175360, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    virtual ::android::hardware::Return<void> someBaseMethod() = 0;

    virtual ::android::hardware::Return<bool> someBoolMethod(bool x) = 0;

    /**
     * Return callback for someBoolArrayMethod
     */
    using someBoolArrayMethod_cb = std::function<void(const ::android::hardware::hidl_array<bool, 4>& y)>;
    virtual ::android::hardware::Return<void> someBoolArrayMethod(const ::android::hardware::hidl_array<bool, 3>& x, someBoolArrayMethod_cb _hidl_cb) = 0;

    /**
     * Return callback for someBoolVectorMethod
     */
    using someBoolVectorMethod_cb = std::function<void(const ::android::hardware::hidl_vec<bool>& y)>;
    virtual ::android::hardware::Return<void> someBoolVectorMethod(const ::android::hardware::hidl_vec<bool>& x, someBoolVectorMethod_cb _hidl_cb) = 0;

    /**
     * Return callback for someOtherBaseMethod
     */
    using someOtherBaseMethod_cb = std::function<void(const ::android::hardware::tests::baz::V1_0::IBase::Foo& result)>;
    virtual ::android::hardware::Return<void> someOtherBaseMethod(const ::android::hardware::tests::baz::V1_0::IBase::Foo& foo, someOtherBaseMethod_cb _hidl_cb) = 0;

    /**
     * Return callback for someMethodWithFooArrays
     */
    using someMethodWithFooArrays_cb = std::function<void(const ::android::hardware::hidl_array<::android::hardware::tests::baz::V1_0::IBase::Foo, 2>& fooOutput)>;
    virtual ::android::hardware::Return<void> someMethodWithFooArrays(const ::android::hardware::hidl_array<::android::hardware::tests::baz::V1_0::IBase::Foo, 2>& fooInput, someMethodWithFooArrays_cb _hidl_cb) = 0;

    /**
     * Return callback for someMethodWithFooVectors
     */
    using someMethodWithFooVectors_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::tests::baz::V1_0::IBase::Foo>& fooOutput)>;
    virtual ::android::hardware::Return<void> someMethodWithFooVectors(const ::android::hardware::hidl_vec<::android::hardware::tests::baz::V1_0::IBase::Foo>& fooInput, someMethodWithFooVectors_cb _hidl_cb) = 0;

    /**
     * Return callback for someMethodWithVectorOfArray
     */
    using someMethodWithVectorOfArray_cb = std::function<void(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& out)>;
    virtual ::android::hardware::Return<void> someMethodWithVectorOfArray(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& in, someMethodWithVectorOfArray_cb _hidl_cb) = 0;

    /**
     * Return callback for someMethodTakingAVectorOfArray
     */
    using someMethodTakingAVectorOfArray_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 6>>& out)>;
    virtual ::android::hardware::Return<void> someMethodTakingAVectorOfArray(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 6>>& in, someMethodTakingAVectorOfArray_cb _hidl_cb) = 0;

    /**
     * Return callback for transpose
     */
    using transpose_cb = std::function<void(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& out)>;
    virtual ::android::hardware::Return<void> transpose(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& in, transpose_cb _hidl_cb) = 0;

    /**
     * Return callback for transpose2
     */
    using transpose2_cb = std::function<void(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 3, 5>& out)>;
    virtual ::android::hardware::Return<void> transpose2(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 5, 3>& in, transpose2_cb _hidl_cb) = 0;

    /**
     * Return callback for takeAMask
     */
    using takeAMask_cb = std::function<void(::android::hardware::tests::baz::V1_0::IBase::BitField out, uint8_t f, uint8_t s, uint8_t t)>;
    virtual ::android::hardware::Return<void> takeAMask(::android::hardware::tests::baz::V1_0::IBase::BitField bf, ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> first, const ::android::hardware::tests::baz::V1_0::IBase::MyMask& second, ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> third, takeAMask_cb _hidl_cb) = 0;

    /**
     * Return callback for testArrays
     */
    using testArrays_cb = std::function<void(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& out)>;
    virtual ::android::hardware::Return<void> testArrays(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& in, testArrays_cb _hidl_cb) = 0;

    /**
     * Return callback for testByteVecs
     */
    using testByteVecs_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 128>>& out)>;
    virtual ::android::hardware::Return<void> testByteVecs(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 128>>& in, testByteVecs_cb _hidl_cb) = 0;

    /**
     * Return callback for testBooleanVecs
     */
    using testBooleanVecs_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<bool, 128>>& out)>;
    virtual ::android::hardware::Return<void> testBooleanVecs(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<bool, 128>>& in, testBooleanVecs_cb _hidl_cb) = 0;

    /**
     * Return callback for testDoubleVecs
     */
    using testDoubleVecs_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<double, 128>>& out)>;
    virtual ::android::hardware::Return<void> testDoubleVecs(const ::android::hardware::hidl_vec<::android::hardware::hidl_array<double, 128>>& in, testDoubleVecs_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::baz::V1_0::IBase>> castFrom(const ::android::sp<::android::hardware::tests::baz::V1_0::IBase>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::baz::V1_0::IBase>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IBase> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBase> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBase> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBase> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBase> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBase> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBase> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBase> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum o);

constexpr int32_t operator|(const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum lhs, const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum lhs, const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& rhs);

template<typename>
static inline std::string toString(int8_t o);
static inline std::string toString(::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum o);

constexpr int8_t operator|(const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const int8_t lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum rhs) {
    return static_cast<int8_t>(lhs | static_cast<int8_t>(rhs));
}
constexpr int8_t operator|(const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) | rhs);
}
constexpr int8_t operator&(const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const int8_t lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum rhs) {
    return static_cast<int8_t>(lhs & static_cast<int8_t>(rhs));
}
constexpr int8_t operator&(const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum lhs, const int8_t rhs) {
    return static_cast<int8_t>(static_cast<int8_t>(lhs) & rhs);
}
constexpr int8_t &operator|=(int8_t& v, const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum e) {
    v |= static_cast<int8_t>(e);
    return v;
}
constexpr int8_t &operator&=(int8_t& v, const ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum e) {
    v &= static_cast<int8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::Foo& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::Foo& lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::Foo& lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& lhs, const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& lhs, const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& lhs, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& lhs, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& lhs, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& lhs, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& lhs, const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& lhs, const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& rhs);

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::baz::V1_0::IBase::BitField o);

constexpr uint8_t operator|(const ::android::hardware::tests::baz::V1_0::IBase::BitField lhs, const ::android::hardware::tests::baz::V1_0::IBase::BitField rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::baz::V1_0::IBase::BitField rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::baz::V1_0::IBase::BitField lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::baz::V1_0::IBase::BitField lhs, const ::android::hardware::tests::baz::V1_0::IBase::BitField rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::baz::V1_0::IBase::BitField rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::baz::V1_0::IBase::BitField lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::baz::V1_0::IBase::BitField e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::baz::V1_0::IBase::BitField e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::MyMask& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::MyMask& lhs, const ::android::hardware::tests::baz::V1_0::IBase::MyMask& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::MyMask& lhs, const ::android::hardware::tests::baz::V1_0::IBase::MyMask& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& lhs, const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& lhs, const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::tests::baz::V1_0::IBase>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum::grrr) == static_cast<int32_t>(::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum::grrr)) {
        os += (first ? "" : " | ");
        os += "grrr";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum::grrr;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum::grrr) {
        return "grrr";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".z = ";
    os += ::android::hardware::toString(o.z);
    os += ", .s = ";
    os += ::android::hardware::toString(o.s);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& rhs) {
    if (lhs.z != rhs.z) {
        return false;
    }
    if (lhs.s != rhs.s) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo::Bar& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum>(int8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::first) == static_cast<int8_t>(::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::first)) {
        os += (first ? "" : " | ");
        os += "first";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::first;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::second) == static_cast<int8_t>(::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::second)) {
        os += (first ? "" : " | ");
        os += "second";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::second;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::first) {
        return "first";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::second) {
        return "second";
    }
    std::string os;
    os += toHexString(static_cast<int8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::Foo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".x = ";
    os += ::android::hardware::toString(o.x);
    os += ", .aaa = ";
    os += ::android::hardware::toString(o.aaa);
    os += ", .y = ";
    os += ::android::hardware::tests::baz::V1_0::toString(o.y);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::Foo& lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo& rhs) {
    if (lhs.x != rhs.x) {
        return false;
    }
    if (lhs.aaa != rhs.aaa) {
        return false;
    }
    if (lhs.y != rhs.y) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::Foo& lhs, const ::android::hardware::tests::baz::V1_0::IBase::Foo& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".one = ";
    os += ::android::hardware::toString(o.one);
    os += ", .two = ";
    os += ::android::hardware::toString(o.two);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& lhs, const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& rhs) {
    if (lhs.one != rhs.one) {
        return false;
    }
    if (lhs.two != rhs.two) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& lhs, const ::android::hardware::tests::baz::V1_0::IBase::MoreThanOneArrayField& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".s = ";
    os += ::android::hardware::toString(o.s);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& lhs, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& rhs) {
    if (lhs.s != rhs.s) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& lhs, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix3x5& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".s = ";
    os += ::android::hardware::toString(o.s);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& lhs, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& rhs) {
    if (lhs.s != rhs.s) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& lhs, const ::android::hardware::tests::baz::V1_0::IBase::StringMatrix5x3& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".addresses = ";
    os += ::android::hardware::toString(o.addresses);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& lhs, const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& rhs) {
    if (lhs.addresses != rhs.addresses) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& lhs, const ::android::hardware::tests::baz::V1_0::IBase::VectorOfArray& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::tests::baz::V1_0::IBase::BitField>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBase::BitField> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::baz::V1_0::IBase::BitField::V0) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBase::BitField::V0)) {
        os += (first ? "" : " | ");
        os += "V0";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBase::BitField::V0;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBase::BitField::V1) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBase::BitField::V1)) {
        os += (first ? "" : " | ");
        os += "V1";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBase::BitField::V1;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBase::BitField::V2) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBase::BitField::V2)) {
        os += (first ? "" : " | ");
        os += "V2";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBase::BitField::V2;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBase::BitField::V3) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBase::BitField::V3)) {
        os += (first ? "" : " | ");
        os += "V3";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBase::BitField::V3;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::baz::V1_0::IBase::BitField o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::baz::V1_0::IBase::BitField::V0) {
        return "V0";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBase::BitField::V1) {
        return "V1";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBase::BitField::V2) {
        return "V2";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBase::BitField::V3) {
        return "V3";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::MyMask& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".value = ";
    os += ::android::hardware::tests::baz::V1_0::toString<::android::hardware::tests::baz::V1_0::IBase::BitField>(o.value);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::MyMask& lhs, const ::android::hardware::tests::baz::V1_0::IBase::MyMask& rhs) {
    if (lhs.value != rhs.value) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::MyMask& lhs, const ::android::hardware::tests::baz::V1_0::IBase::MyMask& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".byte1 = ";
    os += ::android::hardware::toString(o.byte1);
    os += ", .byte2 = ";
    os += ::android::hardware::toString(o.byte2);
    os += ", .byte3 = ";
    os += ::android::hardware::toString(o.byte3);
    os += ", .boolean1 = ";
    os += ::android::hardware::toString(o.boolean1);
    os += ", .boolean2 = ";
    os += ::android::hardware::toString(o.boolean2);
    os += ", .boolean3 = ";
    os += ::android::hardware::toString(o.boolean3);
    os += ", .double1 = ";
    os += ::android::hardware::toString(o.double1);
    os += ", .double2 = ";
    os += ::android::hardware::toString(o.double2);
    os += ", .double3 = ";
    os += ::android::hardware::toString(o.double3);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& lhs, const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& rhs) {
    if (lhs.byte1 != rhs.byte1) {
        return false;
    }
    if (lhs.byte2 != rhs.byte2) {
        return false;
    }
    if (lhs.byte3 != rhs.byte3) {
        return false;
    }
    if (lhs.boolean1 != rhs.boolean1) {
        return false;
    }
    if (lhs.boolean2 != rhs.boolean2) {
        return false;
    }
    if (lhs.boolean3 != rhs.boolean3) {
        return false;
    }
    if (lhs.double1 != rhs.double1) {
        return false;
    }
    if (lhs.double2 != rhs.double2) {
        return false;
    }
    if (lhs.double3 != rhs.double3) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& lhs, const ::android::hardware::tests::baz::V1_0::IBase::LotsOfPrimitiveArrays& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::baz::V1_0::IBase>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::baz::V1_0::IBase::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace baz
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum, 1> hidl_enum_values<::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum> = {
    ::android::hardware::tests::baz::V1_0::IBase::SomeBaseEnum::grrr,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum, 2> hidl_enum_values<::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum> = {
    ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::first,
    ::android::hardware::tests::baz::V1_0::IBase::Foo::FooEnum::second,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::baz::V1_0::IBase::BitField, 4> hidl_enum_values<::android::hardware::tests::baz::V1_0::IBase::BitField> = {
    ::android::hardware::tests::baz::V1_0::IBase::BitField::V0,
    ::android::hardware::tests::baz::V1_0::IBase::BitField::V1,
    ::android::hardware::tests::baz::V1_0::IBase::BitField::V2,
    ::android::hardware::tests::baz::V1_0::IBase::BitField::V3,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_IBASE_H
