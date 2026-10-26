#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IFOO_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IFOO_H

#include <android/hardware/tests/foo/1.0/IFooCallback.h>
#include <android/hardware/tests/foo/1.0/IMyTypes.h>
#include <android/hardware/tests/foo/1.0/ISimple.h>
#include <android/hardware/tests/foo/1.0/ITheirTypes.h>
#include <android/hardware/tests/foo/1.0/types.h>
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
namespace foo {
namespace V1_0 {

struct IFoo : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.foo@1.0::IFoo"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class SomeBaseEnum : uint8_t;
    enum class SomeEnum : uint8_t;
    enum class BitField : uint8_t;
    struct Fumble;
    struct Goober;
    struct Quux;
    struct MultiDimensional;
    struct StringMatrix3x5;
    struct StringMatrix5x3;
    struct MyStruct;
    struct MyHandle;
    struct MyMask;
    struct Everything;
    struct WithFmq;
    enum class Discriminator : uint8_t;
    union Union;
    struct ContainsUnion;
    struct InnerTestStruct;
    struct S1;
    enum class InnerTestEnum : int32_t;
    struct S2;

    enum class SomeBaseEnum : uint8_t {
        bar = 66,
    };

    enum class SomeEnum : uint8_t {
        bar = 66,
        quux = 33,
        goober = 192,
        blah = 192 /* goober */,
    };

    enum class BitField : uint8_t {
        V0 = 1 /* (1 << 0) */,
        V1 = 2 /* (1 << 1) */,
        V2 = 4 /* (1 << 2) */,
        V3 = 8 /* (1 << 3) */,
        VALL = 15 /* (((V0 | V1) | V2) | V3) */,
    };

    struct Fumble final {
        ::android::hardware::tests::foo::V1_0::Outer::Inner data __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Fumble, data) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::Fumble) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::Fumble) == 4, "wrong alignment");

    typedef ::android::hardware::tests::foo::V1_0::IFoo::Fumble Gumble;

    struct Goober final {
        int32_t q __attribute__ ((aligned(4)));
        ::android::hardware::hidl_string name __attribute__ ((aligned(8)));
        ::android::hardware::hidl_string address __attribute__ ((aligned(8)));
        ::android::hardware::hidl_array<double, 10> numbers __attribute__ ((aligned(8)));
        ::android::hardware::tests::foo::V1_0::IFoo::Fumble fumble __attribute__ ((aligned(4)));
        ::android::hardware::tests::foo::V1_0::IFoo::Fumble gumble __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Goober, q) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Goober, name) == 8, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Goober, address) == 24, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Goober, numbers) == 40, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Goober, fumble) == 120, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Goober, gumble) == 124, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::Goober) == 128, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::Goober) == 8, "wrong alignment");

    typedef ::android::hardware::hidl_array<float, 3> ThreeFloats;

    typedef ::android::hardware::hidl_array<float, 5> FiveFloats;

    struct Quux final {
        ::android::hardware::hidl_string first __attribute__ ((aligned(8)));
        ::android::hardware::hidl_string last __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Quux, first) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Quux, last) == 16, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::Quux) == 32, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::Quux) == 8, "wrong alignment");

    typedef ::android::hardware::hidl_array<::android::hardware::tests::foo::V1_0::IFoo::Quux, 3> ThreeQuuxes;

    struct MultiDimensional final {
        ::android::hardware::hidl_array<::android::hardware::tests::foo::V1_0::IFoo::Quux, 5, 3> quuxMatrix __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional, quuxMatrix) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional) == 480, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional) == 8, "wrong alignment");

    typedef ::android::hardware::hidl_array<::android::hardware::hidl_string, 3> ThreeStrings;

    typedef ::android::hardware::hidl_array<::android::hardware::hidl_string, 5> FiveStrings;

    struct StringMatrix3x5 final {
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 3, 5> s __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5, s) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5) == 240, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5) == 8, "wrong alignment");

    struct StringMatrix5x3 final {
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 5, 3> s __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3, s) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3) == 240, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3) == 8, "wrong alignment");

    struct MyStruct final {
        ::android::hardware::tests::foo::V1_0::IMyTypes::SomeStruct innerStruct __attribute__ ((aligned(1)));
        ::android::hardware::hidl_array<float, 10> myFloatArray __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::MyStruct, innerStruct) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::MyStruct, myFloatArray) == 4, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::MyStruct) == 44, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::MyStruct) == 4, "wrong alignment");

    struct MyHandle final {
        ::android::hardware::hidl_handle h __attribute__ ((aligned(8)));
        int32_t guard __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::MyHandle, h) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::MyHandle, guard) == 16, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::MyHandle) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::MyHandle) == 8, "wrong alignment");

    struct MyMask final {
        ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> value __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::MyMask, value) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::MyMask) == 1, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::MyMask) == 1, "wrong alignment");

    typedef ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> Mask;

    struct Everything final {
        // Forward declaration for forward reference support:
        union U;

        union U final {
            int8_t number __attribute__ ((aligned(1)));
            ::android::hardware::hidl_array<int8_t, 1, 2> multidimArray __attribute__ ((aligned(1)));
            ::android::hardware::tests::foo::V1_0::IFoo::Fumble anotherStruct __attribute__ ((aligned(4)));
            ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> bf __attribute__ ((aligned(1)));
        };

        static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Everything::U, number) == 0, "wrong offset");
        static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Everything::U, multidimArray) == 0, "wrong offset");
        static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Everything::U, anotherStruct) == 0, "wrong offset");
        static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Everything::U, bf) == 0, "wrong offset");
        static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::Everything::U) == 4, "wrong size");
        static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::Everything::U) == 4, "wrong alignment");

        ::android::hardware::tests::foo::V1_0::IFoo::Everything::U u;
        int8_t number;
        ::android::hardware::hidl_handle h;
        ::android::hardware::MQDescriptorSync<uint8_t> descSync;
        ::android::hardware::MQDescriptorUnsync<uint8_t> descUnsync;
        ::android::hardware::hidl_memory mem;
        void* p;
        ::android::hardware::hidl_string s;
        ::android::hardware::hidl_vec<::android::hardware::hidl_string> vs;
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 2, 2> multidimArray;
        ::android::hardware::hidl_array<::android::hardware::hidl_string, 3> sArray;
        ::android::hardware::tests::foo::V1_0::IFoo::Quux anotherStruct;
        ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> bf;
    };

    struct WithFmq final {
        // Forward declaration for forward reference support:
        struct ScatterGather;
        struct ContainsPointer;

        struct ScatterGather final {
            ::android::hardware::MQDescriptorSync<uint8_t> descSync __attribute__ ((aligned(8)));
        };

        static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ScatterGather, descSync) == 0, "wrong offset");
        static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ScatterGather) == 32, "wrong size");
        static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ScatterGather) == 8, "wrong alignment");

        struct ContainsPointer final {
            ::android::hardware::MQDescriptorSync<uint8_t> descSync __attribute__ ((aligned(8)));
            ::android::sp<::android::hidl::base::V1_0::IBase> foo __attribute__ ((aligned(8)));
        };

        static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ContainsPointer, descSync) == 0, "wrong offset");
        static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ContainsPointer, foo) == 32, "wrong offset");
        static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ContainsPointer) == 40, "wrong size");
        static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ContainsPointer) == 8, "wrong alignment");

        ::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ScatterGather scatterGathered __attribute__ ((aligned(8)));
        ::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ContainsPointer containsPointer __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq, scatterGathered) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq, containsPointer) == 32, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq) == 72, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::WithFmq) == 8, "wrong alignment");

    enum class Discriminator : uint8_t {
        BOOL = 0,
        INT = 1 /* (::android::hardware::tests::foo::V1_0::IFoo::Discriminator.BOOL implicitly + 1) */,
    };

    union Union final {
        bool boolValue __attribute__ ((aligned(1)));
        int64_t intValue __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Union, boolValue) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::Union, intValue) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::Union) == 8, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::Union) == 8, "wrong alignment");

    struct ContainsUnion final {
        ::android::hardware::tests::foo::V1_0::IFoo::Discriminator discriminator __attribute__ ((aligned(1)));
        ::android::hardware::tests::foo::V1_0::IFoo::Union value __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::ContainsUnion, discriminator) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::ContainsUnion, value) == 8, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::ContainsUnion) == 16, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::ContainsUnion) == 8, "wrong alignment");

    typedef ::android::hardware::hidl_array<int32_t, 5, 6, 7> multidimArrayOne;

    typedef ::android::hardware::hidl_array<int32_t, 8, 9, 10, 5, 6, 7> multidimArrayTwo;

    typedef ::android::hardware::hidl_array<int32_t, 2, 3, 4, 8, 9, 10, 5, 6, 7> multidimArrayThree;

    struct InnerTestStruct final {
    };

    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct) == 1, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct) == 1, "wrong alignment");

    typedef ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct InnerTestStructTypedef;

    struct S1 final {
        // Forward declaration for forward reference support:
        struct InnerTestStruct;

        struct InnerTestStruct final {
        };

        static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct) == 1, "wrong alignment");

        ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct foo __attribute__ ((aligned(1)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::S1, foo) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::S1) == 1, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::S1) == 1, "wrong alignment");

    enum class InnerTestEnum : int32_t {
        VALUE = 0,
    };

    typedef ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum InnerTestEnumTypedef;

    struct S2 final {
        // Forward declaration for forward reference support:
        enum class InnerTestEnum : int32_t;

        enum class InnerTestEnum : int32_t {
            VALUE = 1,
        };

        ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum foo __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFoo::S2, foo) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFoo::S2) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFoo::S2) == 4, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for convertToBoolIfSmall
     */
    using convertToBoolIfSmall_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::tests::foo::V1_0::IFoo::ContainsUnion>& c)>;
    /**
     * If d is INT, converts all values to bools which are small enough (0 or 1).
     * If d is BOOL, should leave all values as BOOLs.
     * 
     * @param d discriminator for all values in u
     * @param u values to be expanded
     * @return c must have same length as u unless there is an error in which case it will be empty.
     */
    virtual ::android::hardware::Return<void> convertToBoolIfSmall(::android::hardware::tests::foo::V1_0::IFoo::Discriminator d, const ::android::hardware::hidl_vec<::android::hardware::tests::foo::V1_0::IFoo::Union>& u, convertToBoolIfSmall_cb _hidl_cb) = 0;

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

    virtual ::android::hardware::Return<void> callMe(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb) = 0;

    virtual ::android::hardware::Return<::android::hardware::tests::foo::V1_0::IFoo::SomeEnum> useAnEnum(::android::hardware::tests::foo::V1_0::IFoo::SomeEnum zzz) = 0;

    virtual ::android::hardware::Return<void> haveAGooberVec(const ::android::hardware::hidl_vec<::android::hardware::tests::foo::V1_0::IFoo::Goober>& param) = 0;

    virtual ::android::hardware::Return<void> haveAGoober(const ::android::hardware::tests::foo::V1_0::IFoo::Goober& g) = 0;

    virtual ::android::hardware::Return<void> haveAGooberArray(const ::android::hardware::hidl_array<::android::hardware::tests::foo::V1_0::IFoo::Goober, 20>& lots) = 0;

    virtual ::android::hardware::Return<void> haveATypeFromAnotherFile(const ::android::hardware::tests::foo::V1_0::Abc& def) = 0;

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
     * Return callback for transposeMe
     */
    using transposeMe_cb = std::function<void(const ::android::hardware::hidl_array<float, 5, 3>& out)>;
    virtual ::android::hardware::Return<void> transposeMe(const ::android::hardware::hidl_array<float, 3, 5>& in, transposeMe_cb _hidl_cb) = 0;

    /**
     * Return callback for callingDrWho
     */
    using callingDrWho_cb = std::function<void(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& out)>;
    virtual ::android::hardware::Return<void> callingDrWho(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& in, callingDrWho_cb _hidl_cb) = 0;

    /**
     * Return callback for transpose
     */
    using transpose_cb = std::function<void(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& out)>;
    virtual ::android::hardware::Return<void> transpose(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& in, transpose_cb _hidl_cb) = 0;

    /**
     * Return callback for transpose2
     */
    using transpose2_cb = std::function<void(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 3, 5>& out)>;
    virtual ::android::hardware::Return<void> transpose2(const ::android::hardware::hidl_array<::android::hardware::hidl_string, 5, 3>& in, transpose2_cb _hidl_cb) = 0;

    /**
     * Return callback for sendVec
     */
    using sendVec_cb = std::function<void(const ::android::hardware::hidl_vec<uint8_t>& data)>;
    virtual ::android::hardware::Return<void> sendVec(const ::android::hardware::hidl_vec<uint8_t>& data, sendVec_cb _hidl_cb) = 0;

    /**
     * Return callback for sendVecVec
     */
    using sendVecVec_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_vec<uint8_t>>& vecvec)>;
    virtual ::android::hardware::Return<void> sendVecVec(sendVecVec_cb _hidl_cb) = 0;

    /**
     * Return callback for haveAVectorOfInterfaces
     */
    using haveAVectorOfInterfaces_cb = std::function<void(const ::android::hardware::hidl_vec<::android::sp<::android::hardware::tests::foo::V1_0::ISimple>>& out)>;
    virtual ::android::hardware::Return<void> haveAVectorOfInterfaces(const ::android::hardware::hidl_vec<::android::sp<::android::hardware::tests::foo::V1_0::ISimple>>& in, haveAVectorOfInterfaces_cb _hidl_cb) = 0;

    /**
     * Return callback for haveAVectorOfGenericInterfaces
     */
    using haveAVectorOfGenericInterfaces_cb = std::function<void(const ::android::hardware::hidl_vec<::android::sp<::android::hidl::base::V1_0::IBase>>& out)>;
    virtual ::android::hardware::Return<void> haveAVectorOfGenericInterfaces(const ::android::hardware::hidl_vec<::android::sp<::android::hidl::base::V1_0::IBase>>& in, haveAVectorOfGenericInterfaces_cb _hidl_cb) = 0;

    /**
     * Return callback for echoNullInterface
     */
    using echoNullInterface_cb = std::function<void(bool receivedNull, const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb)>;
    virtual ::android::hardware::Return<void> echoNullInterface(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb, echoNullInterface_cb _hidl_cb) = 0;

    /**
     * Return callback for createMyHandle
     */
    using createMyHandle_cb = std::function<void(const ::android::hardware::tests::foo::V1_0::IFoo::MyHandle& h)>;
    virtual ::android::hardware::Return<void> createMyHandle(createMyHandle_cb _hidl_cb) = 0;

    /**
     * Return callback for createHandles
     */
    using createHandles_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& handles)>;
    virtual ::android::hardware::Return<void> createHandles(uint32_t size, createHandles_cb _hidl_cb) = 0;

    virtual ::android::hardware::Return<void> closeHandles() = 0;

    /**
     * Return callback for repeatWithFmq
     */
    using repeatWithFmq_cb = std::function<void(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq& withFmq)>;
    virtual ::android::hardware::Return<void> repeatWithFmq(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq& withFmq, repeatWithFmq_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::foo::V1_0::IFoo>> castFrom(const ::android::sp<::android::hardware::tests::foo::V1_0::IFoo>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::foo::V1_0::IFoo>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IFoo> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IFoo> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IFoo> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IFoo> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IFoo> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IFoo> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IFoo> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IFoo> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum o);

constexpr uint8_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum lhs, const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum lhs, const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::SomeEnum o);

constexpr uint8_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum lhs, const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum lhs, const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::BitField o);

constexpr uint8_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::BitField lhs, const ::android::hardware::tests::foo::V1_0::IFoo::BitField rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::BitField rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::BitField lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::BitField lhs, const ::android::hardware::tests::foo::V1_0::IFoo::BitField rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::BitField rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::BitField lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::BitField e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::BitField e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Goober& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::Goober& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Goober& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::Goober& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Goober& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Quux& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::Quux& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Quux& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::Quux& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Quux& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::MyHandle& o);
// operator== and operator!= are not generated for MyHandle

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Everything::U& o);
// operator== and operator!= are not generated for U

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Everything& o);
// operator== and operator!= are not generated for Everything

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ScatterGather& o);
// operator== and operator!= are not generated for ScatterGather

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ContainsPointer& o);
// operator== and operator!= are not generated for ContainsPointer

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq& o);
// operator== and operator!= are not generated for WithFmq

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::Discriminator o);

constexpr uint8_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::Discriminator e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Union& o);
// operator== and operator!= are not generated for Union

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::ContainsUnion& o);
// operator== and operator!= are not generated for ContainsUnion

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct&);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct&);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct& rhs);

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::S1& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::S1& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S1& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::S1& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S1& rhs);

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum o);

constexpr int32_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum lhs, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum lhs, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum o);

constexpr int32_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::S2& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::S2& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S2& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::S2& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S2& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::tests::foo::V1_0::IFoo>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum::bar) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum::bar)) {
        os += (first ? "" : " | ");
        os += "bar";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum::bar;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum::bar) {
        return "bar";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::IFoo::SomeEnum>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::SomeEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::bar) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::bar)) {
        os += (first ? "" : " | ");
        os += "bar";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::bar;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::quux) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::quux)) {
        os += (first ? "" : " | ");
        os += "quux";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::quux;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::goober) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::goober)) {
        os += (first ? "" : " | ");
        os += "goober";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::goober;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::blah) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::blah)) {
        os += (first ? "" : " | ");
        os += "blah";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::blah;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::SomeEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::bar) {
        return "bar";
    }
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::quux) {
        return "quux";
    }
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::goober) {
        return "goober";
    }
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::blah) {
        return "blah";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::IFoo::BitField>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::BitField::V0) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::BitField::V0)) {
        os += (first ? "" : " | ");
        os += "V0";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::BitField::V0;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::BitField::V1) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::BitField::V1)) {
        os += (first ? "" : " | ");
        os += "V1";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::BitField::V1;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::BitField::V2) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::BitField::V2)) {
        os += (first ? "" : " | ");
        os += "V2";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::BitField::V2;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::BitField::V3) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::BitField::V3)) {
        os += (first ? "" : " | ");
        os += "V3";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::BitField::V3;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::BitField::VALL) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::BitField::VALL)) {
        os += (first ? "" : " | ");
        os += "VALL";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::BitField::VALL;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::BitField o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::BitField::V0) {
        return "V0";
    }
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::BitField::V1) {
        return "V1";
    }
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::BitField::V2) {
        return "V2";
    }
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::BitField::V3) {
        return "V3";
    }
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::BitField::VALL) {
        return "VALL";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Fumble& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Goober& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".q = ";
    os += ::android::hardware::toString(o.q);
    os += ", .name = ";
    os += ::android::hardware::toString(o.name);
    os += ", .address = ";
    os += ::android::hardware::toString(o.address);
    os += ", .numbers = ";
    os += ::android::hardware::toString(o.numbers);
    os += ", .fumble = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.fumble);
    os += ", .gumble = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.gumble);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::Goober& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Goober& rhs) {
    if (lhs.q != rhs.q) {
        return false;
    }
    if (lhs.name != rhs.name) {
        return false;
    }
    if (lhs.address != rhs.address) {
        return false;
    }
    if (lhs.numbers != rhs.numbers) {
        return false;
    }
    if (lhs.fumble != rhs.fumble) {
        return false;
    }
    if (lhs.gumble != rhs.gumble) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::Goober& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Goober& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Quux& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".first = ";
    os += ::android::hardware::toString(o.first);
    os += ", .last = ";
    os += ::android::hardware::toString(o.last);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::Quux& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Quux& rhs) {
    if (lhs.first != rhs.first) {
        return false;
    }
    if (lhs.last != rhs.last) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::Quux& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::Quux& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".quuxMatrix = ";
    os += ::android::hardware::toString(o.quuxMatrix);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& rhs) {
    if (lhs.quuxMatrix != rhs.quuxMatrix) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MultiDimensional& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".s = ";
    os += ::android::hardware::toString(o.s);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& rhs) {
    if (lhs.s != rhs.s) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix3x5& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".s = ";
    os += ::android::hardware::toString(o.s);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& rhs) {
    if (lhs.s != rhs.s) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::StringMatrix5x3& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".innerStruct = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.innerStruct);
    os += ", .myFloatArray = ";
    os += ::android::hardware::toString(o.myFloatArray);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& rhs) {
    if (lhs.innerStruct != rhs.innerStruct) {
        return false;
    }
    if (lhs.myFloatArray != rhs.myFloatArray) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MyStruct& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::MyHandle& o) {
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

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".value = ";
    os += ::android::hardware::tests::foo::V1_0::toString<::android::hardware::tests::foo::V1_0::IFoo::BitField>(o.value);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& rhs) {
    if (lhs.value != rhs.value) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Everything::U& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".number = ";
    os += ::android::hardware::toString(o.number);
    os += ", .multidimArray = ";
    os += ::android::hardware::toString(o.multidimArray);
    os += ", .anotherStruct = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.anotherStruct);
    os += ", .bf = ";
    os += ::android::hardware::tests::foo::V1_0::toString<::android::hardware::tests::foo::V1_0::IFoo::BitField>(o.bf);
    os += "}"; return os;
}

// operator== and operator!= are not generated for U

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Everything& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".u = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.u);
    os += ", .number = ";
    os += ::android::hardware::toString(o.number);
    os += ", .h = ";
    os += ::android::hardware::toString(o.h);
    os += ", .descSync = ";
    os += ::android::hardware::toString(o.descSync);
    os += ", .descUnsync = ";
    os += ::android::hardware::toString(o.descUnsync);
    os += ", .mem = ";
    os += ::android::hardware::toString(o.mem);
    os += ", .p = ";
    os += ::android::hardware::toString(o.p);
    os += ", .s = ";
    os += ::android::hardware::toString(o.s);
    os += ", .vs = ";
    os += ::android::hardware::toString(o.vs);
    os += ", .multidimArray = ";
    os += ::android::hardware::toString(o.multidimArray);
    os += ", .sArray = ";
    os += ::android::hardware::toString(o.sArray);
    os += ", .anotherStruct = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.anotherStruct);
    os += ", .bf = ";
    os += ::android::hardware::tests::foo::V1_0::toString<::android::hardware::tests::foo::V1_0::IFoo::BitField>(o.bf);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Everything

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ScatterGather& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".descSync = ";
    os += ::android::hardware::toString(o.descSync);
    os += "}"; return os;
}

// operator== and operator!= are not generated for ScatterGather

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq::ContainsPointer& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".descSync = ";
    os += ::android::hardware::toString(o.descSync);
    os += ", .foo = ";
    os += ::android::hidl::base::V1_0::toString(o.foo);
    os += "}"; return os;
}

// operator== and operator!= are not generated for ContainsPointer

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::WithFmq& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".scatterGathered = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.scatterGathered);
    os += ", .containsPointer = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.containsPointer);
    os += "}"; return os;
}

// operator== and operator!= are not generated for WithFmq

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::IFoo::Discriminator>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::Discriminator> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::Discriminator::BOOL) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::Discriminator::BOOL)) {
        os += (first ? "" : " | ");
        os += "BOOL";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::Discriminator::BOOL;
    }
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::Discriminator::INT) == static_cast<uint8_t>(::android::hardware::tests::foo::V1_0::IFoo::Discriminator::INT)) {
        os += (first ? "" : " | ");
        os += "INT";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::Discriminator::INT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::Discriminator o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::Discriminator::BOOL) {
        return "BOOL";
    }
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::Discriminator::INT) {
        return "INT";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::Union& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".boolValue = ";
    os += ::android::hardware::toString(o.boolValue);
    os += ", .intValue = ";
    os += ::android::hardware::toString(o.intValue);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Union

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::ContainsUnion& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".discriminator = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.discriminator);
    os += ", .value = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.value);
    os += "}"; return os;
}

// operator== and operator!= are not generated for ContainsUnion

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct&) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct& /* lhs */, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct& /* rhs */) {
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::InnerTestStruct& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct&) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct& /* lhs */, const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct& /* rhs */) {
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S1::InnerTestStruct& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::S1& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".foo = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.foo);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::S1& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S1& rhs) {
    if (lhs.foo != rhs.foo) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::S1& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S1& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum::VALUE) == static_cast<int32_t>(::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum::VALUE)) {
        os += (first ? "" : " | ");
        os += "VALUE";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum::VALUE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum::VALUE) {
        return "VALUE";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

template<>
inline std::string toString<::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum::VALUE) == static_cast<int32_t>(::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum::VALUE)) {
        os += (first ? "" : " | ");
        os += "VALUE";
        first = false;
        flipped |= ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum::VALUE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum::VALUE) {
        return "VALUE";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFoo::S2& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".foo = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.foo);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFoo::S2& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S2& rhs) {
    if (lhs.foo != rhs.foo) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFoo::S2& lhs, const ::android::hardware::tests::foo::V1_0::IFoo::S2& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::foo::V1_0::IFoo>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::foo::V1_0::IFoo::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
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
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum, 1> hidl_enum_values<::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum> = {
    ::android::hardware::tests::foo::V1_0::IFoo::SomeBaseEnum::bar,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::IFoo::SomeEnum, 4> hidl_enum_values<::android::hardware::tests::foo::V1_0::IFoo::SomeEnum> = {
    ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::bar,
    ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::quux,
    ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::goober,
    ::android::hardware::tests::foo::V1_0::IFoo::SomeEnum::blah,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::IFoo::BitField, 5> hidl_enum_values<::android::hardware::tests::foo::V1_0::IFoo::BitField> = {
    ::android::hardware::tests::foo::V1_0::IFoo::BitField::V0,
    ::android::hardware::tests::foo::V1_0::IFoo::BitField::V1,
    ::android::hardware::tests::foo::V1_0::IFoo::BitField::V2,
    ::android::hardware::tests::foo::V1_0::IFoo::BitField::V3,
    ::android::hardware::tests::foo::V1_0::IFoo::BitField::VALL,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::IFoo::Discriminator, 2> hidl_enum_values<::android::hardware::tests::foo::V1_0::IFoo::Discriminator> = {
    ::android::hardware::tests::foo::V1_0::IFoo::Discriminator::BOOL,
    ::android::hardware::tests::foo::V1_0::IFoo::Discriminator::INT,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum, 1> hidl_enum_values<::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum> = {
    ::android::hardware::tests::foo::V1_0::IFoo::InnerTestEnum::VALUE,
};
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum, 1> hidl_enum_values<::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum> = {
    ::android::hardware::tests::foo::V1_0::IFoo::S2::InnerTestEnum::VALUE,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IFOO_H
