#ifndef HIDL_GENERATED_ANDROID_HARDWARE_USB_V1_2_IUSBCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_USB_V1_2_IUSBCALLBACK_H

#include <android/hardware/usb/1.0/types.h>
#include <android/hardware/usb/1.1/IUsbCallback.h>
#include <android/hardware/usb/1.2/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace usb {
namespace V1_2 {

/**
 * Callback object used for all the IUsb async methods which expects a result.
 * Caller is expected to register the callback object using setCallback method
 * to receive updates on the PortStatus.
 */
struct IUsbCallback : public ::android::hardware::usb::V1_1::IUsbCallback {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.usb@1.2::IUsbCallback"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Used to convey the current port status to the caller.
     * Called either when PortState changes due to the port partner (or)
     * when caller requested for the PortStatus update through queryPortStatus.
     * 
     * @param currentPortStatus vector object of current status of all the
     * typeC ports in the device.
     * @param retval SUCCESS when query was done successfully.
     * ERROR otherwise.
     */
    virtual ::android::hardware::Return<void> notifyPortStatusChange(const ::android::hardware::hidl_vec<::android::hardware::usb::V1_0::PortStatus>& currentPortStatus, ::android::hardware::usb::V1_0::Status retval) = 0;

    /**
     * Used to notify the result of the switchRole call to the caller.
     * 
     * @param portName name of the port for which the roleswap is requested.
     * @param newRole the new role requested by the caller.
     * @param retval SUCCESS if the role switch succeeded. FAILURE otherwise.
     */
    virtual ::android::hardware::Return<void> notifyRoleSwitchStatus(const ::android::hardware::hidl_string& portName, const ::android::hardware::usb::V1_0::PortRole& newRole, ::android::hardware::usb::V1_0::Status retval) = 0;

    /**
     * Used to convey the current port status to the caller.
     * Must be called either when PortState changes due to the port partner or
     * when caller requested for the PortStatus update through queryPortStatus.
     * 
     * @param currentPortStatus vector object of current status(PortStatus_1_1
     * of all the typeC ports in the device.
     * @param retval SUCCESS when the required information was enquired form
     *               kernel and the PortStatus_1_1 object was built.
     *               ERROR otherwise.
     */
    virtual ::android::hardware::Return<void> notifyPortStatusChange_1_1(const ::android::hardware::hidl_vec<::android::hardware::usb::V1_1::PortStatus_1_1>& currentPortStatus, ::android::hardware::usb::V1_0::Status retval) = 0;

    /**
     * Used to convey the current port status to the caller.
     * Must be called either when PortState changes due to the port partner or
     * when caller requested for the PortStatus update through queryPortStatus.
     * 
     * @param currentPortStatus vector object of current status(PortStatus
     * of all the typeC ports in the device.
     * @param retval SUCCESS when the required information was enquired form
     *               kernel and the PortStatus_1_2 object was built.
     *               ERROR otherwise.
     */
    virtual ::android::hardware::Return<void> notifyPortStatusChange_1_2(const ::android::hardware::hidl_vec<::android::hardware::usb::V1_2::PortStatus>& currentPortStatus, ::android::hardware::usb::V1_0::Status retval) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::usb::V1_2::IUsbCallback>> castFrom(const ::android::sp<::android::hardware::usb::V1_2::IUsbCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::usb::V1_2::IUsbCallback>> castFrom(const ::android::sp<::android::hardware::usb::V1_1::IUsbCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::usb::V1_2::IUsbCallback>> castFrom(const ::android::sp<::android::hardware::usb::V1_0::IUsbCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::usb::V1_2::IUsbCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IUsbCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IUsbCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IUsbCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IUsbCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IUsbCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IUsbCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IUsbCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IUsbCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::usb::V1_2::IUsbCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::usb::V1_2::IUsbCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::usb::V1_2::IUsbCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_2
}  // namespace usb
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_USB_V1_2_IUSBCALLBACK_H
