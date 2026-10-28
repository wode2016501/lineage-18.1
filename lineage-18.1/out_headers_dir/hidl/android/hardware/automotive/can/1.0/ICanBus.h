#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_CAN_V1_0_ICANBUS_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_CAN_V1_0_ICANBUS_H

#include <android/hardware/automotive/can/1.0/ICanErrorListener.h>
#include <android/hardware/automotive/can/1.0/ICanMessageListener.h>
#include <android/hardware/automotive/can/1.0/ICloseHandle.h>
#include <android/hardware/automotive/can/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace automotive {
namespace can {
namespace V1_0 {

/**
 * Represents a CAN bus interface that's up and configured.
 * 
 * Configuration part is done in ICanController.
 */
struct ICanBus : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.automotive.can@1.0::ICanBus"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Send CAN message.
     * 
     * @param message CAN message to send out
     * @return result OK in the case of success
     *                PAYLOAD_TOO_LONG if the payload is too long
     *                INTERFACE_DOWN if the bus is down
     *                TRANSMISSION_FAILURE in case of transmission failure
     */
    virtual ::android::hardware::Return<::android::hardware::automotive::can::V1_0::Result> send(const ::android::hardware::automotive::can::V1_0::CanMessage& message) = 0;

    /**
     * Return callback for listen
     */
    using listen_cb = std::function<void(::android::hardware::automotive::can::V1_0::Result result, const ::android::sp<::android::hardware::automotive::can::V1_0::ICloseHandle>& close)>;
    /**
     * Requests HAL implementation to listen for specific CAN messages.
     * 
     * HAL is responsible for maintaining listener set and sending out messages
     * to each listener that matches given filter against received message.
     * 
     * Empty filter list means no filtering. If two or more listeners requested
     * different filters, HAL server must merge these to fulfill the superset of
     * these filters. HAL must not send out a message to a listener which filter
     * doesn't match given message id.
     * 
     * If filtering is not supported at the hardware level (what's strongly
     * recommended), it must be covered in the HAL.
     * 
     * @param filter The set of requested filters
     * @param listener The interface to receive the messages on
     * @return result OK in the case of success
     *                INTERFACE_DOWN if the bus is down
     * @return close A handle to call in order to remove the listener
     */
    virtual ::android::hardware::Return<void> listen(const ::android::hardware::hidl_vec<::android::hardware::automotive::can::V1_0::CanMessageFilter>& filter, const ::android::sp<::android::hardware::automotive::can::V1_0::ICanMessageListener>& listener, listen_cb _hidl_cb) = 0;

    /**
     * Adds a new listener for CAN bus or interface errors.
     * 
     * If the error is fatal, the client is supposed to drop any references to
     * this specific ICanBus instance (see ICanErrorListener).
     * 
     * @param listener The interface to receive the error events on
     * @return close A handle to call in order to remove the listener
     */
    virtual ::android::hardware::Return<::android::sp<::android::hardware::automotive::can::V1_0::ICloseHandle>> listenForErrors(const ::android::sp<::android::hardware::automotive::can::V1_0::ICanErrorListener>& listener) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::can::V1_0::ICanBus>> castFrom(const ::android::sp<::android::hardware::automotive::can::V1_0::ICanBus>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::automotive::can::V1_0::ICanBus>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ICanBus> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ICanBus> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ICanBus> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ICanBus> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ICanBus> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ICanBus> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ICanBus> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ICanBus> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::automotive::can::V1_0::ICanBus>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::automotive::can::V1_0::ICanBus>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::automotive::can::V1_0::ICanBus::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace can
}  // namespace automotive
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUTOMOTIVE_CAN_V1_0_ICANBUS_H
