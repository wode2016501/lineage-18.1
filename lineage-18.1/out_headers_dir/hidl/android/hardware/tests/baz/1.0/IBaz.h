#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_IBAZ_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_IBAZ_H

#include <android/hardware/tests/baz/1.0/IBase.h>
#include <android/hardware/tests/baz/1.0/IBazCallback.h>

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

struct IBaz : public ::android::hardware::tests::baz::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.baz@1.0::IBaz"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class BitField : uint8_t;
    struct BitFieldTester;
    enum class SomeOtherEnum : uint8_t;
    struct NastyNester;
    enum class SomeEnum : uint8_t;
    struct T;
    struct NestedStruct;
    struct Quux;
    struct Everything;
    struct MyHandle;
    struct StructWithInterface;

    enum class BitField : uint8_t {
        V0 = 1 /* (1 << 0) */,
        V1 = 2 /* (1 << 1) */,
        V2 = 4 /* (1 << 2) */,
        V3 = 8 /* (1 << 3) */,
        VALL = 15 /* (((V0 | V1) | V2) | V3) */,
    };

    struct BitFieldTester final {
        ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField> scalar __attribute__ ((aligned(1)));
        ::android::hardware::hidl_vec<::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField>> vector __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester, scalar) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester, vector) == 8, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester) == 8, "wrong alignment");

    enum class SomeOtherEnum : uint8_t {
        bar = 66,
    };

    typedef ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum thisIsAnAlias;

    typedef ::android::sp<::android::hardware::tests::baz::V1_0::IBaz> anIBazByAnyOtherName;

    struct NastyNester final {
        // Forward declaration for forward reference support:
        struct NestersNasty;

        struct NestersNasty final {
            // Forward declaration for forward reference support:
            struct NestersNastyNester;

            struct NestersNastyNester final {
                ::android::sp<::android::hardware::tests::baz::V1_0::IBaz> baz __attribute__ ((aligned(8)));
                ::android::hardware::hidl_vec<::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty> nasties __attribute__ ((aligned(8)));
            };

            static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty::NestersNastyNester, baz) == 0, "wrong offset");
            static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty::NestersNastyNester, nasties) == 8, "wrong offset");
            static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty::NestersNastyNester) == 24, "wrong size");
            static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty::NestersNastyNester) == 8, "wrong alignment");

        };

        static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty) == 1, "wrong alignment");

        ::android::sp<::android::hardware::tests::baz::V1_0::IBaz> baz __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester, baz) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester) == 8, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::NastyNester) == 8, "wrong alignment");

    enum class SomeEnum : uint8_t {
        bar = 66,
        quux = 33,
        goober = 192,
        blah = 192 /* goober */,
    };

    typedef ::android::hardware::hidl_array<int32_t, 3> ThreeInts;

    struct T final {
        ::android::hardware::hidl_array<int32_t, 5, 3> matrix5x3 __attribute__ ((aligned(4)));
        ::android::hardware::hidl_array<int32_t, 3, 5> matrix3x5 __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::T, matrix5x3) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::T, matrix3x5) == 60, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::T) == 120, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::T) == 4, "wrong alignment");

    struct NestedStruct final {
        int32_t a __attribute__ ((aligned(4)));
        ::android::hardware::hidl_vec<::android::hardware::tests::baz::V1_0::IBaz::T> matrices __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::NestedStruct, a) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::NestedStruct, matrices) == 8, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::NestedStruct) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::NestedStruct) == 8, "wrong alignment");

    struct Quux final {
        ::android::hardware::hidl_string first __attribute__ ((aligned(8)));
        ::android::hardware::hidl_string last __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Quux, first) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Quux, last) == 16, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::Quux) == 32, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::Quux) == 8, "wrong alignment");

    struct Everything final {
        int8_t number __attribute__ ((aligned(1)));
        int32_t anotherNumber __attribute__ ((aligned(4)));
        ::android::hardware::hidl_string s __attribute__ ((aligned(8)));
        ::android::hardware::hidl_vec<::android::hardware::hidl_string> vs __attribute__ ((aligned(8)));
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 2, 2> multidimArray __attribute__ ((aligned(8)));
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 3> sArray __attribute__ ((aligned(8)));
        ::android::hardware::tests::baz::V1_0::IBaz::Quux anotherStruct __attribute__ ((aligned(8)));
        ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField> bf __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Everything, number) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Everything, anotherNumber) == 4, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Everything, s) == 8, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Everything, vs) == 24, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Everything, multidimArray) == 40, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Everything, sArray) == 104, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Everything, anotherStruct) == 152, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::Everything, bf) == 184, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::Everything) == 192, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::Everything) == 8, "wrong alignment");

    struct MyHandle final {
        ::android::hardware::hidl_handle h __attribute__ ((aligned(8)));
        int32_t guard __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::MyHandle, h) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::MyHandle, guard) == 16, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::MyHandle) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::MyHandle) == 8, "wrong alignment");

    struct StructWithInterface final {
        int32_t number __attribute__ ((aligned(4)));
        ::android::hardware::hidl_array<int8_t, 7> array __attribute__ ((aligned(1)));
        ::android::hardware::hidl_string oneString __attribute__ ((aligned(8)));
        ::android::hardware::hidl_vec<::android::hardware::hidl_string> vectorOfStrings __attribute__ ((aligned(8)));
        ::android::sp<::android::hardware::tests::baz::V1_0::IBase> dummy __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface, number) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface, array) == 4, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface, oneString) == 16, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface, vectorOfStrings) == 32, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface, dummy) == 48, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface) == 56, "wrong size");
    static_assert(__alignof(::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface) == 8, "wrong alignment");

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

    virtual ::android::hardware::Return<void> doThis(float param) = 0;

    virtual ::android::hardware::Return<int32_t> doThatAndReturnSomething(int64_t param) = 0;

    virtual ::android::hardware::Return<double> doQuiteABit(int32_t a, int64_t b, float c, double d) = 0;

    /**
     * Return callback for doSomethingElse
     */
    using doSomethingElse_cb = std::function<void(const ::android::hardware::hidl_array<int32_t, 32>& something)>;
    virtual ::android::hardware::Return<void> doSomethingElse(const ::android::hardware::hidl_array<int32_t, 15>& param, doSomethingElse_cb _hidl_cb) = 0;

    /**
     * Return callback for doStuffAndReturnAString
     */
    using doStuffAndReturnAString_cb = std::function<void(const ::android::hardware::hidl_string& something)>;
    virtual ::android::hardware::Return<void> doStuffAndReturnAString(doStuffAndReturnAString_cb _hidl_cb) = 0;

    /**
     * Return callback for mapThisVector
     */
    using mapThisVector_cb = std::function<void(const ::android::hardware::hidl_vec<int32_t>& something)>;
    virtual ::android::hardware::Return<void> mapThisVector(const ::android::hardware::hidl_vec<int32_t>& param, mapThisVector_cb _hidl_cb) = 0;

    virtual ::android::hardware::Return<void> callMe(const ::android::sp<::android::hardware::tests::baz::V1_0::IBazCallback>& cb) = 0;

    virtual ::android::hardware::Return<void> callMeLater(const ::android::sp<::android::hardware::tests::baz::V1_0::IBazCallback>& cb) = 0;

    virtual ::android::hardware::Return<void> iAmFreeNow() = 0;

    virtual ::android::hardware::Return<void> dieNow() = 0;

    virtual ::android::hardware::Return<::android::hardware::tests::baz::V1_0::IBaz::SomeEnum> useAnEnum(::android::hardware::tests::baz::V1_0::IBaz::SomeEnum zzz) = 0;

    /**
     * Return callback for haveSomeStrings
     */
    using haveSomeStrings_cb = std::function<void(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 2>& result)>;
    virtual ::android::hardware::Return<void> haveSomeStrings(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 3>& array, haveSomeStrings_cb _hidl_cb) = 0;

    /**
     * Return callback for haveAStringVec
     */
    using haveAStringVec_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& result)>;
    virtual ::android::hardware::Return<void> haveAStringVec(const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& vector, haveAStringVec_cb _hidl_cb) = 0;

    /**
     * Return callback for repeatBitfieldVec
     */
    using repeatBitfieldVec_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField>>& result)>;
    virtual ::android::hardware::Return<void> repeatBitfieldVec(const ::android::hardware::hidl_vec<::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField>>& vector, repeatBitfieldVec_cb _hidl_cb) = 0;

    /**
     * Return callback for returnABunchOfStrings
     */
    using returnABunchOfStrings_cb = std::function<void(const ::android::hardware::hidl_string& a, const ::android::hardware::hidl_string& b, const ::android::hardware::hidl_string& c)>;
    virtual ::android::hardware::Return<void> returnABunchOfStrings(returnABunchOfStrings_cb _hidl_cb) = 0;

    virtual ::android::hardware::Return<::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField>> returnABitField() = 0;

    virtual ::android::hardware::Return<uint32_t> size(uint32_t size) = 0;

    /**
     * Return callback for getNestedStructs
     */
    using getNestedStructs_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::tests::baz::V1_0::IBaz::NestedStruct>& data)>;
    virtual ::android::hardware::Return<void> getNestedStructs(getNestedStructs_cb _hidl_cb) = 0;

    /**
     * Return callback for haveSomeStructWithInterface
     */
    using haveSomeStructWithInterface_cb = std::function<void(const ::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface& swi)>;
    virtual ::android::hardware::Return<void> haveSomeStructWithInterface(const ::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface& swi, haveSomeStructWithInterface_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::baz::V1_0::IBaz>> castFrom(const ::android::sp<::android::hardware::tests::baz::V1_0::IBaz>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::baz::V1_0::IBaz>> castFrom(const ::android::sp<::android::hardware::tests::baz::V1_0::IBase>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::baz::V1_0::IBaz>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IBaz> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBaz> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBaz> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBaz> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBaz> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBaz> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBaz> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBaz> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::baz::V1_0::IBaz::BitField o);

constexpr uint8_t operator|(const ::android::hardware::tests::baz::V1_0::IBaz::BitField lhs, const ::android::hardware::tests::baz::V1_0::IBaz::BitField rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::baz::V1_0::IBaz::BitField rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::baz::V1_0::IBaz::BitField lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::baz::V1_0::IBaz::BitField lhs, const ::android::hardware::tests::baz::V1_0::IBaz::BitField rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::baz::V1_0::IBaz::BitField rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::baz::V1_0::IBaz::BitField lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::baz::V1_0::IBaz::BitField e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::baz::V1_0::IBaz::BitField e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& rhs);

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum o);

constexpr uint8_t operator|(const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum lhs, const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum lhs, const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty::NestersNastyNester& o);
// operator== and operator!= are not generated for NestersNastyNester

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty&);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester& o);
// operator== and operator!= are not generated for NastyNester

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::baz::V1_0::IBaz::SomeEnum o);

constexpr uint8_t operator|(const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum lhs, const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum lhs, const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::T& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::T& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::T& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::T& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::T& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::Quux& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::Quux& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::Quux& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::Quux& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::Quux& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::Everything& o);
static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::Everything& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::Everything& rhs);
static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::Everything& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::Everything& rhs);

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::MyHandle& o);
// operator== and operator!= are not generated for MyHandle

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface& o);
// operator== and operator!= are not generated for StructWithInterface

static inline std::string toString(const ::android::sp<::android::hardware::tests::baz::V1_0::IBaz>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::tests::baz::V1_0::IBaz::BitField>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::BitField> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::BitField::V0) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::BitField::V0)) {
        os += (first ? "" : " | ");
        os += "V0";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::BitField::V0;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::BitField::V1) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::BitField::V1)) {
        os += (first ? "" : " | ");
        os += "V1";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::BitField::V1;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::BitField::V2) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::BitField::V2)) {
        os += (first ? "" : " | ");
        os += "V2";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::BitField::V2;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::BitField::V3) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::BitField::V3)) {
        os += (first ? "" : " | ");
        os += "V3";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::BitField::V3;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::BitField::VALL) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::BitField::VALL)) {
        os += (first ? "" : " | ");
        os += "VALL";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::BitField::VALL;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::baz::V1_0::IBaz::BitField o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::BitField::V0) {
        return "V0";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::BitField::V1) {
        return "V1";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::BitField::V2) {
        return "V2";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::BitField::V3) {
        return "V3";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::BitField::VALL) {
        return "VALL";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".scalar = ";
    os += ::android::hardware::tests::baz::V1_0::toString<::android::hardware::tests::baz::V1_0::IBaz::BitField>(o.scalar);
    os += ", .vector = ";
    os += ::android::hardware::toString(o.vector);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& rhs) {
    if (lhs.scalar != rhs.scalar) {
        return false;
    }
    if (lhs.vector != rhs.vector) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::BitFieldTester& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum::bar) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum::bar)) {
        os += (first ? "" : " | ");
        os += "bar";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum::bar;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum::bar) {
        return "bar";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty::NestersNastyNester& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".baz = ";
    os += ::android::hardware::tests::baz::V1_0::toString(o.baz);
    os += ", .nasties = ";
    os += ::android::hardware::toString(o.nasties);
    os += "}"; return os;
}

// operator== and operator!= are not generated for NestersNastyNester

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty&) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty& /* lhs */, const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty& /* rhs */) {
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester::NestersNasty& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::NastyNester& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".baz = ";
    os += ::android::hardware::tests::baz::V1_0::toString(o.baz);
    os += "}"; return os;
}

// operator== and operator!= are not generated for NastyNester

template<>
inline std::string toString<::android::hardware::tests::baz::V1_0::IBaz::SomeEnum>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::baz::V1_0::IBaz::SomeEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::bar) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::bar)) {
        os += (first ? "" : " | ");
        os += "bar";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::bar;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::quux) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::quux)) {
        os += (first ? "" : " | ");
        os += "quux";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::quux;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::goober) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::goober)) {
        os += (first ? "" : " | ");
        os += "goober";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::goober;
    }
    if ((o & ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::blah) == static_cast<uint8_t>(::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::blah)) {
        os += (first ? "" : " | ");
        os += "blah";
        first = false;
        flipped |= ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::blah;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::baz::V1_0::IBaz::SomeEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::bar) {
        return "bar";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::quux) {
        return "quux";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::goober) {
        return "goober";
    }
    if (o == ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::blah) {
        return "blah";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::T& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".matrix5x3 = ";
    os += ::android::hardware::toString(o.matrix5x3);
    os += ", .matrix3x5 = ";
    os += ::android::hardware::toString(o.matrix3x5);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::T& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::T& rhs) {
    if (lhs.matrix5x3 != rhs.matrix5x3) {
        return false;
    }
    if (lhs.matrix3x5 != rhs.matrix3x5) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::T& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::T& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".a = ";
    os += ::android::hardware::toString(o.a);
    os += ", .matrices = ";
    os += ::android::hardware::toString(o.matrices);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& rhs) {
    if (lhs.a != rhs.a) {
        return false;
    }
    if (lhs.matrices != rhs.matrices) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::NestedStruct& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::Quux& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".first = ";
    os += ::android::hardware::toString(o.first);
    os += ", .last = ";
    os += ::android::hardware::toString(o.last);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::Quux& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::Quux& rhs) {
    if (lhs.first != rhs.first) {
        return false;
    }
    if (lhs.last != rhs.last) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::Quux& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::Quux& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::Everything& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".number = ";
    os += ::android::hardware::toString(o.number);
    os += ", .anotherNumber = ";
    os += ::android::hardware::toString(o.anotherNumber);
    os += ", .s = ";
    os += ::android::hardware::toString(o.s);
    os += ", .vs = ";
    os += ::android::hardware::toString(o.vs);
    os += ", .multidimArray = ";
    os += ::android::hardware::toString(o.multidimArray);
    os += ", .sArray = ";
    os += ::android::hardware::toString(o.sArray);
    os += ", .anotherStruct = ";
    os += ::android::hardware::tests::baz::V1_0::toString(o.anotherStruct);
    os += ", .bf = ";
    os += ::android::hardware::tests::baz::V1_0::toString<::android::hardware::tests::baz::V1_0::IBaz::BitField>(o.bf);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::baz::V1_0::IBaz::Everything& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::Everything& rhs) {
    if (lhs.number != rhs.number) {
        return false;
    }
    if (lhs.anotherNumber != rhs.anotherNumber) {
        return false;
    }
    if (lhs.s != rhs.s) {
        return false;
    }
    if (lhs.vs != rhs.vs) {
        return false;
    }
    if (lhs.multidimArray != rhs.multidimArray) {
        return false;
    }
    if (lhs.sArray != rhs.sArray) {
        return false;
    }
    if (lhs.anotherStruct != rhs.anotherStruct) {
        return false;
    }
    if (lhs.bf != rhs.bf) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::baz::V1_0::IBaz::Everything& lhs, const ::android::hardware::tests::baz::V1_0::IBaz::Everything& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::MyHandle& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".h = ";
    os += ::android::hardware::toString(o.h);
    os += ", .guard = ";
    os += ::android::hardware::toString(o.guard);
    os += "}"; return os;
}

// operator== and operator!= are not generated for MyHandle

static inline std::string toString(const ::android::hardware::tests::baz::V1_0::IBaz::StructWithInterface& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".number = ";
    os += ::android::hardware::toString(o.number);
    os += ", .array = ";
    os += ::android::hardware::toString(o.array);
    os += ", .oneString = ";
    os += ::android::hardware::toString(o.oneString);
    os += ", .vectorOfStrings = ";
    os += ::android::hardware::toString(o.vectorOfStrings);
    os += ", .dummy = ";
    os += ::android::hardware::tests::baz::V1_0::toString(o.dummy);
    os += "}"; return os;
}

// operator== and operator!= are not generated for StructWithInterface

static inline std::string toString(const ::android::sp<::android::hardware::tests::baz::V1_0::IBaz>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::baz::V1_0::IBaz::descriptor;
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
template<> constexpr std::array<::android::hardware::tests::baz::V1_0::IBaz::BitField, 5> hidl_enum_values<::android::hardware::tests::baz::V1_0::IBaz::BitField> = {
    ::android::hardware::tests::baz::V1_0::IBaz::BitField::V0,
    ::android::hardware::tests::baz::V1_0::IBaz::BitField::V1,
    ::android::hardware::tests::baz::V1_0::IBaz::BitField::V2,
    ::android::hardware::tests::baz::V1_0::IBaz::BitField::V3,
    ::android::hardware::tests::baz::V1_0::IBaz::BitField::VALL,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum, 1> hidl_enum_values<::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum> = {
    ::android::hardware::tests::baz::V1_0::IBaz::SomeOtherEnum::bar,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::baz::V1_0::IBaz::SomeEnum, 4> hidl_enum_values<::android::hardware::tests::baz::V1_0::IBaz::SomeEnum> = {
    ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::bar,
    ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::quux,
    ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::goober,
    ::android::hardware::tests::baz::V1_0::IBaz::SomeEnum::blah,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAZ_V1_0_IBAZ_H
