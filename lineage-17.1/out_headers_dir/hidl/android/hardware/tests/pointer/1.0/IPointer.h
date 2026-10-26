#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IPOINTER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IPOINTER_H

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
namespace pointer {
namespace V1_0 {

struct IPointer : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.pointer@1.0::IPointer"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct S;
    struct A;
    struct Sam;
    struct Ada;
    struct Bob;
    struct Cin;
    struct Dom;
    struct Ptr;

    struct S final {
        int32_t data __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::pointer::V1_0::IPointer::S, data) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::pointer::V1_0::IPointer::S) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::pointer::V1_0::IPointer::S) == 4, "wrong alignment");

    struct A final {
        ::android::hardware::tests::pointer::V1_0::IPointer::S s __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::pointer::V1_0::IPointer::A, s) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::pointer::V1_0::IPointer::A) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::pointer::V1_0::IPointer::A) == 4, "wrong alignment");

    struct Sam final {
        int32_t data __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::pointer::V1_0::IPointer::Sam, data) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::pointer::V1_0::IPointer::Sam) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::pointer::V1_0::IPointer::Sam) == 4, "wrong alignment");

    struct Ada final {
        ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr;
    };

    struct Bob final {
        ::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr;
        ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr;
    };

    struct Cin final {
        ::android::hardware::tests::pointer::V1_0::IPointer::Ada a;
        ::android::hardware::tests::pointer::V1_0::IPointer::Bob const* b_ptr;
    };

    struct Dom final {
        ::android::hardware::tests::pointer::V1_0::IPointer::Cin c;
    };

    typedef int32_t const* Int32Ptr;

    typedef ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* SamPtr;

    struct Ptr final {
        ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada const*, 5> ptr_array;
        ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada, 5> const* array_ptr;
        int32_t const* int_ptr;
        ::android::hardware::hidl_array<int32_t, 5> const* int_array_ptr;
        ::android::hardware::hidl_array<int32_t const*, 5> int_ptr_array;
        ::android::hardware::hidl_string const* str_ref;
        ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada const*> a_ptr_vec;
        ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ptr;
    };

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    virtual ::android::hardware::Return<void> foo1(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr) = 0;

    virtual ::android::hardware::Return<void> foo2(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a) = 0;

    virtual ::android::hardware::Return<void> foo3(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a, const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& b) = 0;

    virtual ::android::hardware::Return<void> foo4(::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr) = 0;

    virtual ::android::hardware::Return<void> foo5(const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a, const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& b) = 0;

    virtual ::android::hardware::Return<void> foo6(::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr) = 0;

    virtual ::android::hardware::Return<void> foo7(::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr, ::android::hardware::tests::pointer::V1_0::IPointer::Bob const* b_ptr) = 0;

    virtual ::android::hardware::Return<void> foo8(const ::android::hardware::tests::pointer::V1_0::IPointer::Dom& d) = 0;

    virtual ::android::hardware::Return<void> foo9(::android::hardware::hidl_string const* str_ref) = 0;

    virtual ::android::hardware::Return<void> foo10(const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*>& s_ptr_vec) = 0;

    virtual ::android::hardware::Return<void> foo11(::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam> const* s_vec_ptr) = 0;

    virtual ::android::hardware::Return<void> foo12(::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Sam, 5> const* s_array_ref) = 0;

    virtual ::android::hardware::Return<void> foo13(const ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*, 5>& s_ref_array) = 0;

    virtual ::android::hardware::Return<void> foo14(::android::hardware::tests::pointer::V1_0::IPointer::Sam const* const* const* s_3ptr) = 0;

    virtual ::android::hardware::Return<void> foo15(int32_t const* const* const* i_3ptr) = 0;

    virtual ::android::hardware::Return<void> foo16(const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr& p) = 0;

    virtual ::android::hardware::Return<void> foo17(::android::hardware::tests::pointer::V1_0::IPointer::Ptr const* p) = 0;

    virtual ::android::hardware::Return<void> foo18(::android::hardware::hidl_string const* str_ref, ::android::hardware::hidl_string const* str_ref2, const ::android::hardware::hidl_string& str) = 0;

    virtual ::android::hardware::Return<void> foo19(::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ref, const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada>& a_vec, ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ref2) = 0;

    virtual ::android::hardware::Return<void> foo20(const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*>& s_ptr_vec) = 0;

    virtual ::android::hardware::Return<void> foo21(::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada, 1, 2, 3> const* a_array_ptr) = 0;

    virtual ::android::hardware::Return<void> foo22(const ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada const*, 1, 2, 3>& a_ptr_array) = 0;

    /**
     * Return callback for bar1
     */
    using bar1_cb = std::function<void(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, ::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr)>;
    virtual ::android::hardware::Return<void> bar1(bar1_cb _hidl_cb) = 0;

    /**
     * Return callback for bar2
     */
    using bar2_cb = std::function<void(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a)>;
    virtual ::android::hardware::Return<void> bar2(bar2_cb _hidl_cb) = 0;

    /**
     * Return callback for bar3
     */
    using bar3_cb = std::function<void(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& s, const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a, const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& b)>;
    virtual ::android::hardware::Return<void> bar3(bar3_cb _hidl_cb) = 0;

    /**
     * Return callback for bar4
     */
    using bar4_cb = std::function<void(::android::hardware::tests::pointer::V1_0::IPointer::Sam const* s_ptr)>;
    virtual ::android::hardware::Return<void> bar4(bar4_cb _hidl_cb) = 0;

    /**
     * Return callback for bar5
     */
    using bar5_cb = std::function<void(const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& a, const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& b)>;
    virtual ::android::hardware::Return<void> bar5(bar5_cb _hidl_cb) = 0;

    /**
     * Return callback for bar6
     */
    using bar6_cb = std::function<void(::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr)>;
    virtual ::android::hardware::Return<void> bar6(bar6_cb _hidl_cb) = 0;

    /**
     * Return callback for bar7
     */
    using bar7_cb = std::function<void(::android::hardware::tests::pointer::V1_0::IPointer::Ada const* a_ptr, ::android::hardware::tests::pointer::V1_0::IPointer::Bob const* b_ptr)>;
    virtual ::android::hardware::Return<void> bar7(bar7_cb _hidl_cb) = 0;

    /**
     * Return callback for bar8
     */
    using bar8_cb = std::function<void(const ::android::hardware::tests::pointer::V1_0::IPointer::Dom& d)>;
    virtual ::android::hardware::Return<void> bar8(bar8_cb _hidl_cb) = 0;

    /**
     * Return callback for bar9
     */
    using bar9_cb = std::function<void(::android::hardware::hidl_string const* str_ref)>;
    virtual ::android::hardware::Return<void> bar9(bar9_cb _hidl_cb) = 0;

    /**
     * Return callback for bar10
     */
    using bar10_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*>& s_ptr_vec)>;
    virtual ::android::hardware::Return<void> bar10(bar10_cb _hidl_cb) = 0;

    /**
     * Return callback for bar11
     */
    using bar11_cb = std::function<void(::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam> const* s_vec_ptr)>;
    virtual ::android::hardware::Return<void> bar11(bar11_cb _hidl_cb) = 0;

    /**
     * Return callback for bar12
     */
    using bar12_cb = std::function<void(::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Sam, 5> const* s_array_ref)>;
    virtual ::android::hardware::Return<void> bar12(bar12_cb _hidl_cb) = 0;

    /**
     * Return callback for bar13
     */
    using bar13_cb = std::function<void(const ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*, 5>& s_ref_array)>;
    virtual ::android::hardware::Return<void> bar13(bar13_cb _hidl_cb) = 0;

    /**
     * Return callback for bar14
     */
    using bar14_cb = std::function<void(::android::hardware::tests::pointer::V1_0::IPointer::Sam const* const* const* s_3ptr)>;
    virtual ::android::hardware::Return<void> bar14(bar14_cb _hidl_cb) = 0;

    /**
     * Return callback for bar15
     */
    using bar15_cb = std::function<void(int32_t const* const* const* i_3ptr)>;
    virtual ::android::hardware::Return<void> bar15(bar15_cb _hidl_cb) = 0;

    /**
     * Return callback for bar16
     */
    using bar16_cb = std::function<void(const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr& p)>;
    virtual ::android::hardware::Return<void> bar16(bar16_cb _hidl_cb) = 0;

    /**
     * Return callback for bar17
     */
    using bar17_cb = std::function<void(::android::hardware::tests::pointer::V1_0::IPointer::Ptr const* p)>;
    virtual ::android::hardware::Return<void> bar17(bar17_cb _hidl_cb) = 0;

    /**
     * Return callback for bar18
     */
    using bar18_cb = std::function<void(::android::hardware::hidl_string const* str_ref, ::android::hardware::hidl_string const* str_ref2, const ::android::hardware::hidl_string& str)>;
    virtual ::android::hardware::Return<void> bar18(bar18_cb _hidl_cb) = 0;

    /**
     * Return callback for bar19
     */
    using bar19_cb = std::function<void(::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ref, const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada>& a_vec, ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Ada> const* a_vec_ref2)>;
    virtual ::android::hardware::Return<void> bar19(bar19_cb _hidl_cb) = 0;

    /**
     * Return callback for bar20
     */
    using bar20_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IPointer::Sam const*>& s_ptr_vec)>;
    virtual ::android::hardware::Return<void> bar20(bar20_cb _hidl_cb) = 0;

    /**
     * Return callback for bar21
     */
    using bar21_cb = std::function<void(::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada, 1, 2, 3> const* a_array_ptr)>;
    virtual ::android::hardware::Return<void> bar21(bar21_cb _hidl_cb) = 0;

    /**
     * Return callback for bar22
     */
    using bar22_cb = std::function<void(const ::android::hardware::hidl_array<::android::hardware::tests::pointer::V1_0::IPointer::Ada const*, 1, 2, 3>& a_ptr_array)>;
    virtual ::android::hardware::Return<void> bar22(bar22_cb _hidl_cb) = 0;

    virtual ::android::hardware::Return<int32_t> getErrors() = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::pointer::V1_0::IPointer>> castFrom(const ::android::sp<::android::hardware::tests::pointer::V1_0::IPointer>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::pointer::V1_0::IPointer>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IPointer> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IPointer> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IPointer> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IPointer> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IPointer> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IPointer> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IPointer> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IPointer> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::S& o);
static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IPointer::S& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::S& rhs);
static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IPointer::S& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::S& rhs);

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::A& o);
static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IPointer::A& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::A& rhs);
static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IPointer::A& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::A& rhs);

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& o);
static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& rhs);
static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& rhs);

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& o);
// operator== and operator!= are not generated for Ada

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& o);
// operator== and operator!= are not generated for Bob

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Cin& o);
// operator== and operator!= are not generated for Cin

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Dom& o);
// operator== and operator!= are not generated for Dom

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr& o);
// operator== and operator!= are not generated for Ptr

static inline std::string toString(const ::android::sp<::android::hardware::tests::pointer::V1_0::IPointer>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::S& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IPointer::S& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::S& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IPointer::S& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::S& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::A& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".s = ";
    os += ::android::hardware::tests::pointer::V1_0::toString(o.s);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IPointer::A& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::A& rhs) {
    if (lhs.s != rhs.s) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IPointer::A& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::A& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& lhs, const ::android::hardware::tests::pointer::V1_0::IPointer::Sam& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Ada& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".s_ptr = ";
    os += ::android::hardware::toString(o.s_ptr);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Ada

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Bob& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".a_ptr = ";
    os += ::android::hardware::toString(o.a_ptr);
    os += ", .s_ptr = ";
    os += ::android::hardware::toString(o.s_ptr);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Bob

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Cin& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".a = ";
    os += ::android::hardware::tests::pointer::V1_0::toString(o.a);
    os += ", .b_ptr = ";
    os += ::android::hardware::toString(o.b_ptr);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Cin

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Dom& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".c = ";
    os += ::android::hardware::tests::pointer::V1_0::toString(o.c);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Dom

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IPointer::Ptr& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".ptr_array = ";
    os += ::android::hardware::toString(o.ptr_array);
    os += ", .array_ptr = ";
    os += ::android::hardware::toString(o.array_ptr);
    os += ", .int_ptr = ";
    os += ::android::hardware::toString(o.int_ptr);
    os += ", .int_array_ptr = ";
    os += ::android::hardware::toString(o.int_array_ptr);
    os += ", .int_ptr_array = ";
    os += ::android::hardware::toString(o.int_ptr_array);
    os += ", .str_ref = ";
    os += ::android::hardware::toString(o.str_ref);
    os += ", .a_ptr_vec = ";
    os += ::android::hardware::toString(o.a_ptr_vec);
    os += ", .a_vec_ptr = ";
    os += ::android::hardware::toString(o.a_vec_ptr);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Ptr

static inline std::string toString(const ::android::sp<::android::hardware::tests::pointer::V1_0::IPointer>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::pointer::V1_0::IPointer::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace pointer
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IPOINTER_H
