#ifndef HIDL_GENERATED_ANDROID_HARDWARE_USB_GADGET_V1_1_IUSBGADGET_H
#define HIDL_GENERATED_ANDROID_HARDWARE_USB_GADGET_V1_1_IUSBGADGET_H

#include <android/hardware/usb/gadget/1.0/IUsbGadget.h>
#include <android/hardware/usb/gadget/1.0/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace usb {
namespace gadget {
namespace V1_1 {

struct IUsbGadget : public ::android::hardware::usb::gadget::V1_0::IUsbGadget {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.usb.gadget@1.1::IUsbGadget"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * This function is used to set the current USB gadget configuration.
     * Usb gadget needs to teared down if an USB configuration is already
     * active.
     * 
     * @param functions list of functions defined by GadgetFunction to be
     *                  included in the gadget composition.
     * @param callback IUsbGadgetCallback::setCurrentUsbFunctionsCb used to
     *                 propagate back the status.
     * @param timeout The maximum time (in milliseconds) within which the
     *                IUsbGadgetCallback needs to be returned.
     */
    virtual ::android::hardware::Return<void> setCurrentUsbFunctions(::android::hardware::hidl_bitfield<::android::hardware::usb::gadget::V1_0::GadgetFunction> functions, const ::android::sp<::android::hardware::usb::gadget::V1_0::IUsbGadgetCallback>& callback, uint64_t timeout) = 0;

    /**
     * This function is used to query the USB functions included in the
     * current USB configuration.
     * 
     * @param callback IUsbGadgetCallback::getCurrentUsbFunctionsCb used to
     *                 propagate the current functions list.
     */
    virtual ::android::hardware::Return<void> getCurrentUsbFunctions(const ::android::sp<::android::hardware::usb::gadget::V1_0::IUsbGadgetCallback>& callback) = 0;

    /**
     * This function is used to reset USB gadget driver.
     * Performs USB data connection reset. The connection will disconnect and
     * reconnect.
     * 
     * return status indicate success or not.
     */
    virtual ::android::hardware::Return<::android::hardware::usb::gadget::V1_0::Status> reset() = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::usb::gadget::V1_1::IUsbGadget>> castFrom(const ::android::sp<::android::hardware::usb::gadget::V1_1::IUsbGadget>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::usb::gadget::V1_1::IUsbGadget>> castFrom(const ::android::sp<::android::hardware::usb::gadget::V1_0::IUsbGadget>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::usb::gadget::V1_1::IUsbGadget>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IUsbGadget> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IUsbGadget> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IUsbGadget> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IUsbGadget> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IUsbGadget> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IUsbGadget> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IUsbGadget> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IUsbGadget> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::usb::gadget::V1_1::IUsbGadget>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::usb::gadget::V1_1::IUsbGadget>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::usb::gadget::V1_1::IUsbGadget::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_1
}  // namespace gadget
}  // namespace usb
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_USB_GADGET_V1_1_IUSBGADGET_H
