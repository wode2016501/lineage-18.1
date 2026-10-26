#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IBAR_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IBAR_H

#include <android/hardware/tests/foo/1.0/IFoo.h>
#include <android/hardware/tests/foo/1.0/ISimple.h>
#include <android/hardware/tests/foo/1.0/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tests {
namespace bar {
namespace V1_0 {

struct IBar : public ::android::hardware::tests::foo::V1_0::IFoo {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.bar@1.0::IBar"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct SomethingRelated;

    typedef ::android::sp<::android::hardware::tests::foo::V1_0::IFoo> FunkyAlias;

    typedef ::android::hardware::tests::foo::V1_0::Unrelated Related;

    struct SomethingRelated final {
        ::android::hardware::tests::foo::V1_0::Unrelated myRelated __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::bar::V1_0::IBar::SomethingRelated, myRelated) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::bar::V1_0::IBar::SomethingRelated) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::bar::V1_0::IBar::SomethingRelated) == 4, "wrong alignment");

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

    virtual ::android::hardware::Return<void> thisIsNew() = 0;

    /**
     * Return callback for expectNullHandle
     */
    using expectNullHandle_cb = std::function<void(bool hIsNull, bool xyzHasNull)>;
    virtual ::android::hardware::Return<void> expectNullHandle(const ::android::hardware::hidl_handle& h, const ::android::hardware::tests::foo::V1_0::Abc& xyz, expectNullHandle_cb _hidl_cb) = 0;

    /**
     * Return callback for takeAMask
     */
    using takeAMask_cb = std::function<void(::android::hardware::tests::foo::V1_0::IFoo::BitField bf, uint8_t first, uint8_t second, uint8_t third)>;
    virtual ::android::hardware::Return<void> takeAMask(::android::hardware::tests::foo::V1_0::IFoo::BitField bf, ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> first, const ::android::hardware::tests::foo::V1_0::IFoo::MyMask& second, ::android::hardware::hidl_bitfield<::android::hardware::tests::foo::V1_0::IFoo::BitField> third, takeAMask_cb _hidl_cb) = 0;

    virtual ::android::hardware::Return<::android::sp<::android::hardware::tests::foo::V1_0::ISimple>> haveAInterface(const ::android::sp<::android::hardware::tests::foo::V1_0::ISimple>& i) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::bar::V1_0::IBar>> castFrom(const ::android::sp<::android::hardware::tests::bar::V1_0::IBar>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::bar::V1_0::IBar>> castFrom(const ::android::sp<::android::hardware::tests::foo::V1_0::IFoo>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::bar::V1_0::IBar>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IBar> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBar> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBar> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBar> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBar> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBar> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBar> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBar> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& o);
static inline bool operator==(const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& lhs, const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& rhs);
static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& lhs, const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::tests::bar::V1_0::IBar>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".myRelated = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.myRelated);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& lhs, const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& rhs) {
    if (lhs.myRelated != rhs.myRelated) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& lhs, const ::android::hardware::tests::bar::V1_0::IBar::SomethingRelated& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::bar::V1_0::IBar>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::bar::V1_0::IBar::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace bar
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IBAR_H
