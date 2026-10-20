#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IFOOCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IFOOCALLBACK_H

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

struct IFooCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.foo@1.0::IFooCallback"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct InvokeInfo;

    struct InvokeInfo final {
        bool invoked __attribute__ ((aligned(1)));
        int64_t callerBlockedNs __attribute__ ((aligned(8)));
        int64_t timeNs __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo, invoked) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo, callerBlockedNs) == 8, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo, timeNs) == 16, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    virtual ::android::hardware::Return<void> heyItsYou(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb) = 0;

    virtual ::android::hardware::Return<bool> heyItsYouIsntIt(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& cb) = 0;

    virtual ::android::hardware::Return<void> heyItsTheMeaningOfLife(uint8_t tmol) = 0;

    /**
     * Return callback for reportResults
     */
    using reportResults_cb = std::function<void(int64_t leftNs, const ::android::hardware::hidl_array<::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo, 3>& invokeInfo)>;
    virtual ::android::hardware::Return<void> reportResults(int64_t ns, reportResults_cb _hidl_cb) = 0;

    virtual ::android::hardware::Return<void> youBlockedMeFor(const ::android::hardware::hidl_array<int64_t, 3>& callerBlockedInfo) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>> castFrom(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IFooCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IFooCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IFooCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IFooCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IFooCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IFooCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IFooCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IFooCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& o);
static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& lhs, const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& rhs);
static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& lhs, const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".invoked = ";
    os += ::android::hardware::toString(o.invoked);
    os += ", .callerBlockedNs = ";
    os += ::android::hardware::toString(o.callerBlockedNs);
    os += ", .timeNs = ";
    os += ::android::hardware::toString(o.timeNs);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& lhs, const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& rhs) {
    if (lhs.invoked != rhs.invoked) {
        return false;
    }
    if (lhs.callerBlockedNs != rhs.callerBlockedNs) {
        return false;
    }
    if (lhs.timeNs != rhs.timeNs) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& lhs, const ::android::hardware::tests::foo::V1_0::IFooCallback::InvokeInfo& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::foo::V1_0::IFooCallback::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_FOO_V1_0_IFOOCALLBACK_H
