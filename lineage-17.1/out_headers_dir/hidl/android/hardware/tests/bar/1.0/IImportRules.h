#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IIMPORTRULES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IIMPORTRULES_H

#include <android/hardware/tests/bar/1.0/types.h>
#include <android/hardware/tests/foo/1.0/IFooCallback.h>
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
namespace bar {
namespace V1_0 {

struct IImportRules : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.bar@1.0::IImportRules"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct Outer;

    struct Outer final {
        // Forward declaration for forward reference support:
        struct Inner;

        struct Inner final {
            int32_t data __attribute__ ((aligned(4)));
        };

        static_assert(offsetof(::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner, data) == 0, "wrong offset");
        static_assert(sizeof(::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner) == 4, "wrong size");
        static_assert(__alignof(::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner) == 4, "wrong alignment");

        ::android::hardware::hidl_string data __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::tests::bar::V1_0::IImportRules::Outer, data) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::bar::V1_0::IImportRules::Outer) == 16, "wrong size");
    static_assert(__alignof(::android::hardware::tests::bar::V1_0::IImportRules::Outer) == 8, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    virtual ::android::hardware::Return<void> rule0a(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) = 0;

    virtual ::android::hardware::Return<void> rule0a1(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) = 0;

    virtual ::android::hardware::Return<void> rule0b(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) = 0;

    virtual ::android::hardware::Return<void> rule0b1(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) = 0;

    virtual ::android::hardware::Return<void> rule0c(const ::android::hardware::tests::foo::V1_0::Outer& o) = 0;

    virtual ::android::hardware::Return<void> rule0d(const ::android::hardware::tests::foo::V1_0::Outer& o) = 0;

    virtual ::android::hardware::Return<void> rule0e(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& o) = 0;

    virtual ::android::hardware::Return<void> rule0f(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& o) = 0;

    virtual ::android::hardware::Return<void> rule0g(const ::android::hardware::tests::foo::V1_0::Outer::Inner& o) = 0;

    virtual ::android::hardware::Return<void> rule0h(const ::android::hardware::tests::foo::V1_0::Outer::Inner& o) = 0;

    virtual ::android::hardware::Return<void> rule1a(const ::android::hardware::tests::bar::V1_0::Def& abc) = 0;

    virtual ::android::hardware::Return<void> rule1b(const ::android::hardware::tests::foo::V1_0::Def& abc) = 0;

    virtual ::android::hardware::Return<void> rule2a(const ::android::hardware::tests::foo::V1_0::Unrelated& related) = 0;

    virtual ::android::hardware::Return<void> rule2b(const ::android::sp<::android::hardware::tests::foo::V1_0::IFooCallback>& fooCallback) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::bar::V1_0::IImportRules>> castFrom(const ::android::sp<::android::hardware::tests::bar::V1_0::IImportRules>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::bar::V1_0::IImportRules>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IImportRules> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IImportRules> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IImportRules> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IImportRules> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IImportRules> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IImportRules> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IImportRules> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IImportRules> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& o);
static inline bool operator==(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& lhs, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& rhs);
static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& lhs, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& rhs);

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o);
static inline bool operator==(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& lhs, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& rhs);
static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& lhs, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::tests::bar::V1_0::IImportRules>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& lhs, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& lhs, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer::Inner& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& lhs, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& lhs, const ::android::hardware::tests::bar::V1_0::IImportRules::Outer& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::bar::V1_0::IImportRules>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::bar::V1_0::IImportRules::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IIMPORTRULES_H
