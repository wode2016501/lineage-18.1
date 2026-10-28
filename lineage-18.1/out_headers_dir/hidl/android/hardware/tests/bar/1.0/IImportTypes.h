#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IIMPORTTYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IIMPORTTYPES_H

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

struct IImportTypes : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.bar@1.0::IImportTypes"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct GoodStruct;

    typedef ::android::hardware::tests::foo::V1_0::Unrelated Related;

    struct GoodStruct final {
        ::android::hardware::tests::foo::V1_0::Outer outer __attribute__ ((aligned(1)));
        ::android::hardware::tests::foo::V1_0::Outer::Inner inner __attribute__ ((aligned(4)));
        ::android::hardware::tests::foo::V1_0::Outer::Inner::Deep deep __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct, outer) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct, inner) == 4, "wrong offset");
    static_assert(offsetof(::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct, deep) == 8, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct) == 12, "wrong size");
    static_assert(__alignof(::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct) == 4, "wrong alignment");

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::bar::V1_0::IImportTypes>> castFrom(const ::android::sp<::android::hardware::tests::bar::V1_0::IImportTypes>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::bar::V1_0::IImportTypes>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IImportTypes> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IImportTypes> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IImportTypes> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IImportTypes> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IImportTypes> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IImportTypes> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IImportTypes> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IImportTypes> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& o);
static inline bool operator==(const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& lhs, const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& rhs);
static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& lhs, const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& rhs);

static inline std::string toString(const ::android::sp<::android::hardware::tests::bar::V1_0::IImportTypes>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".outer = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.outer);
    os += ", .inner = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.inner);
    os += ", .deep = ";
    os += ::android::hardware::tests::foo::V1_0::toString(o.deep);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& lhs, const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& rhs) {
    if (lhs.outer != rhs.outer) {
        return false;
    }
    if (lhs.inner != rhs.inner) {
        return false;
    }
    if (lhs.deep != rhs.deep) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& lhs, const ::android::hardware::tests::bar::V1_0::IImportTypes::GoodStruct& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::bar::V1_0::IImportTypes>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::bar::V1_0::IImportTypes::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_BAR_V1_0_IIMPORTTYPES_H
