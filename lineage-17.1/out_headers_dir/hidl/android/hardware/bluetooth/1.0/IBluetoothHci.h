#ifndef HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_V1_0_IBLUETOOTHHCI_H
#define HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_V1_0_IBLUETOOTHHCI_H

#include <android/hardware/bluetooth/1.0/IBluetoothHciCallbacks.h>
#include <android/hardware/bluetooth/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace bluetooth {
namespace V1_0 {

/**
 * The Host Controller Interface (HCI) is the layer defined by the Bluetooth
 * specification between the software that runs on the host and the Bluetooth
 * controller chip. This boundary is the natural choice for a Hardware
 * Abstraction Layer (HAL). Dealing only in HCI packets and events simplifies
 * the stack and abstracts away power management, initialization, and other
 * implementation-specific details related to the hardware.
 */
struct IBluetoothHci : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.bluetooth@1.0::IBluetoothHci"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    // @entry @callflow(next={"sendHciCommand", "sendAclData", "sendScoData", "close"})
    /**
     * Initialize the underlying HCI interface.
     * 
     * This method should be used to initialize any hardware interfaces
     * required to communicate with the Bluetooth hardware in the
     * device.
     * 
     * The |oninitializationComplete| callback must be invoked in response
     * to this function to indicate success before any other function
     * (sendHciCommand, sendAclData, * sendScoData) is invoked on this
     * interface.
     * 
     * @param callback implements IBluetoothHciCallbacks which will
     *    receive callbacks when incoming HCI packets are received
     *    from the controller to be sent to the host.
     */
    virtual ::android::hardware::Return<void> initialize(const ::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHciCallbacks>& callback) = 0;

    // @callflow(next={"sendHciCommand", "sendAclData", "sendScoData", "close"})
    /**
     * Send an HCI command (as specified in the Bluetooth Specification
     * V4.2, Vol 2, Part 5, Section 5.4.1) to the Bluetooth controller.
     * Commands must be executed in order.
     * 
     * @param command is the HCI command to be sent
     */
    virtual ::android::hardware::Return<void> sendHciCommand(const ::android::hardware::hidl_vec<uint8_t>& command) = 0;

    // @callflow(next={"sendHciCommand", "sendAclData", "sendScoData", "close"})
    /**
     * Send an HCI ACL data packet (as specified in the Bluetooth Specification
     * V4.2, Vol 2, Part 5, Section 5.4.2) to the Bluetooth controller.
     * Packets must be processed in order.
     * @param data HCI data packet to be sent
     */
    virtual ::android::hardware::Return<void> sendAclData(const ::android::hardware::hidl_vec<uint8_t>& data) = 0;

    // @callflow(next={"sendHciCommand", "sendAclData", "sendScoData", "close"})
    /**
     * Send an SCO data packet (as specified in the Bluetooth Specification
     * V4.2, Vol 2, Part 5, Section 5.4.3) to the Bluetooth controller.
     * Packets must be processed in order.
     * @param data HCI data packet to be sent
     */
    virtual ::android::hardware::Return<void> sendScoData(const ::android::hardware::hidl_vec<uint8_t>& data) = 0;

    // @exit
    /**
     * Close the HCI interface
     */
    virtual ::android::hardware::Return<void> close() = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHci>> castFrom(const ::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHci>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHci>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IBluetoothHci> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBluetoothHci> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IBluetoothHci> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBluetoothHci> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IBluetoothHci> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBluetoothHci> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IBluetoothHci> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IBluetoothHci> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHci>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::bluetooth::V1_0::IBluetoothHci>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::bluetooth::V1_0::IBluetoothHci::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_V1_0_IBLUETOOTHHCI_H
