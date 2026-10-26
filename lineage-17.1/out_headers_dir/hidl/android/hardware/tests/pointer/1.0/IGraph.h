#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IGRAPH_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IGRAPH_H

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

struct IGraph : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.pointer@1.0::IGraph"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    struct Node;
    struct Edge;
    struct Graph;
    struct Theta;
    struct Alpha;
    struct Beta;
    struct Gamma;

    struct Node final {
        int32_t data __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::pointer::V1_0::IGraph::Node, data) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::pointer::V1_0::IGraph::Node) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::pointer::V1_0::IGraph::Node) == 4, "wrong alignment");

    struct Edge final {
        ::android::hardware::tests::pointer::V1_0::IGraph::Node const* left;
        ::android::hardware::tests::pointer::V1_0::IGraph::Node const* right;
    };

    struct Graph final {
        ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IGraph::Node> nodes;
        ::android::hardware::hidl_vec<::android::hardware::tests::pointer::V1_0::IGraph::Edge> edges;
    };

    struct Theta final {
        int32_t data __attribute__ ((aligned(4)));
    };

    static_assert(offsetof(::android::hardware::tests::pointer::V1_0::IGraph::Theta, data) == 0, "wrong offset");
    static_assert(sizeof(::android::hardware::tests::pointer::V1_0::IGraph::Theta) == 4, "wrong size");
    static_assert(__alignof(::android::hardware::tests::pointer::V1_0::IGraph::Theta) == 4, "wrong alignment");

    struct Alpha final {
        ::android::hardware::tests::pointer::V1_0::IGraph::Theta const* s_ptr;
    };

    struct Beta final {
        ::android::hardware::tests::pointer::V1_0::IGraph::Theta const* s_ptr;
    };

    struct Gamma final {
        ::android::hardware::tests::pointer::V1_0::IGraph::Alpha const* a_ptr;
        ::android::hardware::tests::pointer::V1_0::IGraph::Beta const* b_ptr;
    };

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    virtual ::android::hardware::Return<void> passANode(const ::android::hardware::tests::pointer::V1_0::IGraph::Node& n) = 0;

    virtual ::android::hardware::Return<void> passAGraph(const ::android::hardware::tests::pointer::V1_0::IGraph::Graph& g) = 0;

    virtual ::android::hardware::Return<void> passTwoGraphs(::android::hardware::tests::pointer::V1_0::IGraph::Graph const* g1, ::android::hardware::tests::pointer::V1_0::IGraph::Graph const* g2) = 0;

    /**
     * Return callback for giveAGraph
     */
    using giveAGraph_cb = std::function<void(const ::android::hardware::tests::pointer::V1_0::IGraph::Graph& g)>;
    virtual ::android::hardware::Return<void> giveAGraph(giveAGraph_cb _hidl_cb) = 0;

    virtual ::android::hardware::Return<void> passAGamma(const ::android::hardware::tests::pointer::V1_0::IGraph::Gamma& c) = 0;

    virtual ::android::hardware::Return<void> passASimpleRef(::android::hardware::tests::pointer::V1_0::IGraph::Alpha const* a) = 0;

    virtual ::android::hardware::Return<void> passASimpleRefS(::android::hardware::tests::pointer::V1_0::IGraph::Theta const* s) = 0;

    /**
     * Return callback for giveASimpleRef
     */
    using giveASimpleRef_cb = std::function<void(::android::hardware::tests::pointer::V1_0::IGraph::Alpha const* a)>;
    virtual ::android::hardware::Return<void> giveASimpleRef(giveASimpleRef_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::pointer::V1_0::IGraph>> castFrom(const ::android::sp<::android::hardware::tests::pointer::V1_0::IGraph>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::pointer::V1_0::IGraph>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IGraph> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGraph> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IGraph> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGraph> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IGraph> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGraph> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IGraph> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IGraph> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Node& o);
static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IGraph::Node& lhs, const ::android::hardware::tests::pointer::V1_0::IGraph::Node& rhs);
static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IGraph::Node& lhs, const ::android::hardware::tests::pointer::V1_0::IGraph::Node& rhs);

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Edge& o);
// operator== and operator!= are not generated for Edge

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Graph& o);
// operator== and operator!= are not generated for Graph

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& o);
static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& lhs, const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& rhs);
static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& lhs, const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& rhs);

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Alpha& o);
// operator== and operator!= are not generated for Alpha

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Beta& o);
// operator== and operator!= are not generated for Beta

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Gamma& o);
// operator== and operator!= are not generated for Gamma

static inline std::string toString(const ::android::sp<::android::hardware::tests::pointer::V1_0::IGraph>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Node& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IGraph::Node& lhs, const ::android::hardware::tests::pointer::V1_0::IGraph::Node& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IGraph::Node& lhs, const ::android::hardware::tests::pointer::V1_0::IGraph::Node& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Edge& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".left = ";
    os += ::android::hardware::toString(o.left);
    os += ", .right = ";
    os += ::android::hardware::toString(o.right);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Edge

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Graph& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".nodes = ";
    os += ::android::hardware::toString(o.nodes);
    os += ", .edges = ";
    os += ::android::hardware::toString(o.edges);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Graph

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".data = ";
    os += ::android::hardware::toString(o.data);
    os += "}"; return os;
}

static inline bool operator==(const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& lhs, const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& rhs) {
    if (lhs.data != rhs.data) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& lhs, const ::android::hardware::tests::pointer::V1_0::IGraph::Theta& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Alpha& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".s_ptr = ";
    os += ::android::hardware::toString(o.s_ptr);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Alpha

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Beta& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".s_ptr = ";
    os += ::android::hardware::toString(o.s_ptr);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Beta

static inline std::string toString(const ::android::hardware::tests::pointer::V1_0::IGraph::Gamma& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".a_ptr = ";
    os += ::android::hardware::toString(o.a_ptr);
    os += ", .b_ptr = ";
    os += ::android::hardware::toString(o.b_ptr);
    os += "}"; return os;
}

// operator== and operator!= are not generated for Gamma

static inline std::string toString(const ::android::sp<::android::hardware::tests::pointer::V1_0::IGraph>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::pointer::V1_0::IGraph::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_POINTER_V1_0_IGRAPH_H
