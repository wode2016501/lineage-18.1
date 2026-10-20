#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_IBENCHMARKMSGQ_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_IBENCHMARKMSGQ_H

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

struct IBenchmarkMsgQ : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tests.msgq@1.0::IBenchmarkMsgQ"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for configureClientInboxSyncReadWrite
     */
    using configureClientInboxSyncReadWrite_cb = std::function<void(bool ret, const ::android::hardware::MQDescriptorSync<uint8_t>& mqDescIn)>;
    /**
     * This method requests the service to set up Synchronous read/write
     * wait-free FMQ with the client as reader.
     * @return ret Will be true if the setup was successful, false otherwise.
     * @return mqDescIn This structure describes the FMQ that was set up
     * by the service. Client can use it to set up the FMQ at its end.
     */
    virtual ::android::hardware::Return<void> configureClientInboxSyncReadWrite(configureClientInboxSyncReadWrite_cb _hidl_cb) = 0;

    /**
     * Return callback for configureClientOutboxSyncReadWrite
     */
    using configureClientOutboxSyncReadWrite_cb = std::function<void(bool ret, const ::android::hardware::MQDescriptorSync<uint8_t>& mqDescOut)>;
    /**
     * This method requests the service to set up Synchronous read/write
     * wait-free FMQ with the client as writer.
     * @return ret Will be true if the setup was successful, false otherwise.
     * @return mqDescOut This structure describes the FMQ that was set up
     * by the service. Client can use it to set up the FMQ at its end.
     */
    virtual ::android::hardware::Return<void> configureClientOutboxSyncReadWrite(configureClientOutboxSyncReadWrite_cb _hidl_cb) = 0;

    /**
     * This method request the service to write into the FMQ.
     * @param count Number to messages to write.
     * @return ret Will be true if the write operation was successful,
     * false otherwise.
     */
    virtual ::android::hardware::Return<bool> requestWrite(int32_t count) = 0;

    /**
     * This method request the service to read from the FMQ.
     * @param count Number to messages to read.
     * @ret Will be true if the read operation was successful, false otherwise.
     */
    virtual ::android::hardware::Return<bool> requestRead(int32_t count) = 0;

    /**
     * This method kicks off a benchmarking experiment where
     * the client writes a message into its outbox FMQ,
     * the service reads it and writes it into the client's
     * inbox FMQ and the client reads the message.
     * The average time taken for the experiment is measured.
     * @param numIter The number of iterations to run the experiment.
     */
    virtual ::android::hardware::Return<void> benchmarkPingPong(uint32_t numIter) = 0;

    /**
     * This method kicks off a benchmarking experiment where
     * the service writes into an FMQ and the client reads the same.
     * @param numIter The number of iterations to run the experiment.
     */
    virtual ::android::hardware::Return<void> benchmarkServiceWriteClientRead(uint32_t numIter) = 0;

    /**
     * This method sends a vector of time duration(in ns).
     * @param timeData vector of time instants measured by client.
     * Each entry is the number of ns between the epoch and a
     * std::chrono::time_point.
     */
    virtual ::android::hardware::Return<void> sendTimeData(const ::android::hardware::hidl_vec<int64_t>& timeData) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ>> castFrom(const ::android::sp<::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IBenchmarkMsgQ> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBenchmarkMsgQ> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBenchmarkMsgQ> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBenchmarkMsgQ> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBenchmarkMsgQ> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBenchmarkMsgQ> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBenchmarkMsgQ> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBenchmarkMsgQ> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tests::msgq::V1_0::IBenchmarkMsgQ::descriptor;
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


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TESTS_MSGQ_V1_0_IBENCHMARKMSGQ_H
