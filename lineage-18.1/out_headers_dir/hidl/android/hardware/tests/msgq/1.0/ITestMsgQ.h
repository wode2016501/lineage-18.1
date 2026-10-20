#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_ITESTMSGQ_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_ITESTMSGQ_H

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
namespace msgq {
namespace V1_0 {

struct ITestMsgQ : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.msgq@1.0::ITestMsgQ"
     */
    static const char* descriptor;

    // Forward declaration for forward reference support:
    enum class EventFlagBits : uint32_t;

    enum class EventFlagBits : uint32_t {
        FMQ_NOT_EMPTY = 1u /* (1 << 0) */,
        FMQ_NOT_FULL = 2u /* (1 << 1) */,
    };

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * This method requests the service to set up a synchronous read/write
     * wait-free FMQ using the input descriptor with the client as reader.
     * 
     * @param mqDesc This structure describes the FMQ that was set up by the
     * client. Server uses this descriptor to set up a FMQ object at its end.
     * 
     * @return ret True if the setup is successful.
     */
    virtual ::android::hardware::Return<bool> configureFmqSyncReadWrite(const ::android::hardware::MQDescriptorSync<uint16_t>& mqDesc) = 0;

    /**
     * Return callback for getFmqUnsyncWrite
     */
    using getFmqUnsyncWrite_cb = std::function<void(bool ret, const ::android::hardware::MQDescriptorUnsync<uint16_t>& mqDesc)>;
    /**
     * This method requests the service to return an MQDescriptor to
     * an unsynchronized FMQ set up by the server. If 'configureFmq' is
     * true, then the server sets up a new unsynchronized FMQ. This
     * method is to be used to test multiple reader processes.
     * 
     * @param configureFmq The server sets up a new unsynchronized FMQ if
     * this parameter is true.
     * 
     * @return ret True if successful.
     * @return mqDesc This structure describes the unsynchronized FMQ that was
     * set up by the service. Client can use it to set up the FMQ at its end.
     */
    virtual ::android::hardware::Return<void> getFmqUnsyncWrite(bool configureFmq, getFmqUnsyncWrite_cb _hidl_cb) = 0;

    /**
     * This method request the service to write into the synchronized read/write
     * flavor of the FMQ.
     * 
     * @param count Number to messages to write.
     * 
     * @return ret True if the write operation was successful.
     */
    virtual ::android::hardware::Return<bool> requestWriteFmqSync(int32_t count) = 0;

    /**
     * This method request the service to read from the synchronized read/write
     * FMQ.
     * 
     * @param count Number to messages to read.
     * 
     * @return ret True if the read operation was successful.
     */
    virtual ::android::hardware::Return<bool> requestReadFmqSync(int32_t count) = 0;

    /**
     * This method request the service to write into the unsynchronized flavor
     * of FMQ.
     * 
     * @param count Number to messages to write.
     * 
     * @return ret True if the write operation was successful.
     */
    virtual ::android::hardware::Return<bool> requestWriteFmqUnsync(int32_t count) = 0;

    /**
     * This method request the service to read from the unsynchronized flavor of
     * FMQ.
     * 
     * @param count Number to messages to read.
     * 
     * @return ret Will be True if the read operation was successful.
     */
    virtual ::android::hardware::Return<bool> requestReadFmqUnsync(int32_t count) = 0;

    /**
     * This method requests the service to trigger a blocking read.
     * 
     * @param count Number of messages to read.
     * 
     */
    virtual ::android::hardware::Return<void> requestBlockingRead(int32_t count) = 0;

    /**
     * This method requests the service to trigger a blocking read using
     * default Event Flag notification bits defined by the MessageQueue class.
     * 
     * @param count Number of messages to read.
     * 
     */
    virtual ::android::hardware::Return<void> requestBlockingReadDefaultEventFlagBits(int32_t count) = 0;

    /**
     * This method requests the service to repeatedly trigger blocking reads.
     * 
     * @param count Number of messages to read in a single blocking read.
     * @param numIter Number of blocking reads to trigger.
     * 
     */
    virtual ::android::hardware::Return<void> requestBlockingReadRepeat(int32_t count, int32_t numIter) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::msgq::V1_0::ITestMsgQ>> castFrom(const ::android::sp<::android::hardware::tests::msgq::V1_0::ITestMsgQ>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::msgq::V1_0::ITestMsgQ>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ITestMsgQ> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ITestMsgQ> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ITestMsgQ> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ITestMsgQ> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ITestMsgQ> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ITestMsgQ> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ITestMsgQ> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ITestMsgQ> getService(bool getStub) { return getService("default", getStub); }
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
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits o);

constexpr uint32_t operator|(const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits lhs, const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits lhs, const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::msgq::V1_0::ITestMsgQ>& o);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_EMPTY) == static_cast<uint32_t>(::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_EMPTY)) {
        os += (first ? "" : " | ");
        os += "FMQ_NOT_EMPTY";
        first = false;
        flipped |= ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_EMPTY;
    }
    if ((o & ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_FULL) == static_cast<uint32_t>(::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_FULL)) {
        os += (first ? "" : " | ");
        os += "FMQ_NOT_FULL";
        first = false;
        flipped |= ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_FULL;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_EMPTY) {
        return "FMQ_NOT_EMPTY";
    }
    if (o == ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_FULL) {
        return "FMQ_NOT_FULL";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline std::string toString(const ::android::sp<::android::hardware::tests::msgq::V1_0::ITestMsgQ>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::msgq::V1_0::ITestMsgQ::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace msgq
}  // namespace tests
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
template<> constexpr std::array<::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits, 2> hidl_enum_values<::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits> = {
    ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_EMPTY,
    ::android::hardware::tests::msgq::V1_0::ITestMsgQ::EventFlagBits::FMQ_NOT_FULL,
};
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_ITESTMSGQ_H
