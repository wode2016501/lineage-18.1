#ifndef HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_BUFFERPOOL_V2_0_IACCESSOR_H
#define HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_BUFFERPOOL_V2_0_IACCESSOR_H

#include <android/hardware/media/bufferpool/2.0/IConnection.h>
#include <android/hardware/media/bufferpool/2.0/IObserver.h>
#include <android/hardware/media/bufferpool/2.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace media {
namespace bufferpool {
namespace V2_0 {

/**
 * IAccessor creates IConnection which is used from IClientManager in order to
 * use functionality of the specified buffer pool.
 */
struct IAccessor : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.media.bufferpool@2.0::IAccessor"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for connect
     */
    using connect_cb = std::function<void(::android::hardware::media::bufferpool::V2_0::ResultStatus status, const ::android::sp<::android::hardware::media::bufferpool::V2_0::IConnection>& connection, int64_t connectionId, uint32_t msgId, const ::android::hardware::MQDescriptorSync<::android::hardware::media::bufferpool::V2_0::BufferStatusMessage>& toFmqDesc, const ::android::hardware::MQDescriptorUnsync<::android::hardware::media::bufferpool::V2_0::BufferInvalidationMessage>& fromFmqDesc)>;
    /**
     * Registers a new client and creates IConnection to the buffer pool for
     * the client. IConnection and FMQ are used by IClientManager in order to
     * communicate with the buffer pool. Via FMQ IClientManager sends
     * BufferStatusMesage(s) to the buffer pool.
     * 
     * FMQ is used to send buffer ownership status changes to a buffer pool
     * from a buffer pool client. A buffer pool synchronizes FMQ messages when
     * there is a hidl request from the clients. Every client has its own
     * connection and FMQ to communicate with the buffer pool. So sending an
     * FMQ message on behalf of other clients is not possible.
     * 
     * FMQ messages are sent when a buffer is acquired or released. Also, FMQ
     * messages are sent when a buffer is transferred from a client to another
     * client. FMQ has its own ID from a buffer pool. A client is specified
     * with the ID.
     * 
     * To transfer a buffer, a sender must send an FMQ message. The message
     * must include a receiver's ID and a transaction ID. A receiver must send
     * the transaction ID to fetch a buffer from a buffer pool. Since the
     * sender already registered the receiver via an FMQ message, The buffer
     * pool must verify the receiver with the transaction ID. In order to
     * prevent faking a receiver, a connection to a buffer pool from client is
     * made and kept private. Also part of transaction ID is a sender ID in
     * order to prevent fake transactions from other clients. This must be
     * verified with an FMQ message from a buffer pool.
     * 
     * @param observer The buffer pool event observer from the client.
     *     Observer is provided to ensure FMQ messages are processed even when
     *     client processes are idle. Buffer invalidation caused by
     *     reconfiguration does not call observer. Buffer invalidation caused
     *     by termination of pipeline call observer in order to ensure
     *     invalidation is done after pipeline completion.
     * 
     * @return status The status of the call.
     *     OK               - A connection is made successfully.
     *     NO_MEMORY        - Memory allocation failure occurred.
     *     ALREADY_EXISTS   - A connection was already made.
     *     CRITICAL_ERROR   - Other errors.
     * @return connection The IConnection have interfaces
     *     to get shared buffers from the buffer pool.
     * @return connectionId Id of IConnection. The Id identifies
     *     sender and receiver in FMQ messages during buffer transfer.
     * @return msgId Id of the most recent message from buffer pool.
     * @return toFmqDesc FMQ descriptor. The descriptor is used to
     *     post buffer status messages.
     * @return fromFmqDesc FMQ descriptor. The descriptor is used to
     *     receive buffer invalidation messages from the buffer pool.
     */
    virtual ::android::hardware::Return<void> connect(const ::android::sp<::android::hardware::media::bufferpool::V2_0::IObserver>& observer, connect_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::media::bufferpool::V2_0::IAccessor>> castFrom(const ::android::sp<::android::hardware::media::bufferpool::V2_0::IAccessor>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::media::bufferpool::V2_0::IAccessor>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IAccessor> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IAccessor> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IAccessor> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IAccessor> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IAccessor> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IAccessor> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IAccessor> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IAccessor> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::media::bufferpool::V2_0::IAccessor>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::media::bufferpool::V2_0::IAccessor>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::media::bufferpool::V2_0::IAccessor::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_0
}  // namespace bufferpool
}  // namespace media
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_BUFFERPOOL_V2_0_IACCESSOR_H
