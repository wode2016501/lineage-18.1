#ifndef HIDL_GENERATED_ANDROID_HARDWARE_SECURE_ELEMENT_V1_2_ISECUREELEMENT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_SECURE_ELEMENT_V1_2_ISECUREELEMENT_H

#include <android/hardware/secure_element/1.0/types.h>
#include <android/hardware/secure_element/1.1/ISecureElement.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace secure_element {
namespace V1_2 {

struct ISecureElement : public ::android::hardware::secure_element::V1_1::ISecureElement {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.secure_element@1.2::ISecureElement"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Initializes the Secure Element. This may include updating the applet
     * and/or vendor-specific initialization.
     * 
     * HAL service must send onStateChange() with connected equal to true
     * after all the initialization has been successfully completed.
     * Clients must wait for a onStateChange(true) before opening channels.
     * 
     * @param clientCallback callback used to sent status of the SE back to the
     *                       client
     */
    virtual ::android::hardware::Return<void> init(const ::android::sp<::android::hardware::secure_element::V1_0::ISecureElementHalCallback>& clientCallback) = 0;

    /**
     * Return callback for getAtr
     */
    using getAtr_cb = std::function<void(const ::android::hardware::hidl_vec<uint8_t>& response)>;
    /**
     * Returns Answer to Reset as per ISO/IEC 7816
     * 
     * @return response containing the response. Empty vector if Secure Element
     *                  doesn't support ATR.
     */
    virtual ::android::hardware::Return<void> getAtr(getAtr_cb _hidl_cb) = 0;

    /**
     * Returns the current state of the card.
     * 
     * This is particularly useful for removable
     * Secure Elements like UICC, Secure Elements on SD cards etc.
     * 
     * @return present true if present, false otherwise
     */
    virtual ::android::hardware::Return<bool> isCardPresent() = 0;

    /**
     * Return callback for transmit
     */
    using transmit_cb = std::function<void(const ::android::hardware::hidl_vec<uint8_t>& response)>;
    /**
     * Transmits an APDU command (as per ISO/IEC 7816) to the SE.
     * 
     * @param data APDU command to be sent
     * @return response to the command. In case of error in communicating with
     *                  the secure element, an empty vector is returned.
     */
    virtual ::android::hardware::Return<void> transmit(const ::android::hardware::hidl_vec<uint8_t>& data, transmit_cb _hidl_cb) = 0;

    /**
     * Return callback for openLogicalChannel
     */
    using openLogicalChannel_cb = std::function<void(const ::android::hardware::secure_element::V1_0::LogicalChannelResponse& response, ::android::hardware::secure_element::V1_0::SecureElementStatus status)>;
    /**
     * Opens a logical channel with the Secure Element, selecting the applet
     * represented by the Application ID (AID).
     * 
     * @param aid AID to uniquely identify the applet on the Secure Element
     * @param p2 P2 paramter of SELECT APDU as per ISO 7816-4
     * @return status SecureElementStatus::SUCCESS on success,
     *                SecureElementStatus::CHANNEL_NOT_AVAILABLE if secure
     *                element has reached the maximum limit on the number of
     *                channels it can support,
     *                SecureElementStatus::NO_SUCH_ELEMENT_ERROR if AID provided
     *                doesn't match any applet on the secure element and
     *                SecureElementStatus::UNSUPPORTED_OPERATION if operation
     *                provided by the P2 parameter is not permitted by the
     *                applet.
     *                SecureElementStatus::IOERROR if there was an error
     *                communicating with the Secure Element.
     * @return response On success, response to SELECT command is returned
     *                        empty vector on failure.
     */
    virtual ::android::hardware::Return<void> openLogicalChannel(const ::android::hardware::hidl_vec<uint8_t>& aid, uint8_t p2, openLogicalChannel_cb _hidl_cb) = 0;

    /**
     * Return callback for openBasicChannel
     */
    using openBasicChannel_cb = std::function<void(const ::android::hardware::hidl_vec<uint8_t>& selectResponse, ::android::hardware::secure_element::V1_0::SecureElementStatus status)>;
    /**
     * Opens a basic channel with the Secure Element, selecting the applet
     * represented by the Application ID (AID).
     * 
     * @param aid AID to uniquely identify the applet on the Secure Element
     * @param p2 P2 paramter of SELECT APDU as per ISO 7816-4
     * @return status SecureElementStatus::SUCCESS on success,
     *                SecureElementStatus::CHANNEL_NOT_AVAILABLE if secure
     *                element has reached the maximum limit on the number of
     *                channels it can support,
     *                SecureElementStatus::NO_SUCH_ELEMENT_ERROR if AID provided
     *                doesn't match any applet on the secure element and
     *                SecureElementStatus::UNSUPPORTED_OPERATION if operation
     *                provided by the P2 parameter is not permitted by the
     *                applet.
     *                SecureElementStatus::IOERROR if there was an error
     *                communicating with the Secure Element.
     * @return selectResponse On success, response to SELECT command is returned
     *                        empty vector on failure.
     */
    virtual ::android::hardware::Return<void> openBasicChannel(const ::android::hardware::hidl_vec<uint8_t>& aid, uint8_t p2, openBasicChannel_cb _hidl_cb) = 0;

    /**
     * Closes the channel indicated by the channelNumber.
     * 
     * Closing a basic channel, i.e with channelNumber 0 must return
     * SecureElementStatus::FAILED.
     * 
     * @param channelNumber to be closed
     * @return status SecureElementStatus::SUCCESS on success and
     *                SecureElementStatus::FAILED on error.
     */
    virtual ::android::hardware::Return<::android::hardware::secure_element::V1_0::SecureElementStatus> closeChannel(uint8_t channelNumber) = 0;

    /**
     * Initializes the Secure Element. This may include updating the applet
     * and/or vendor-specific initialization.
     * 
     * HAL service must send onStateChange() with connected equal to true
     * after all the initialization has been successfully completed.
     * Clients must wait for a onStateChange(true) before opening channels.
     * 
     * @param clientCallback callback used to sent status of the SE back to the
     *                       client
     */
    virtual ::android::hardware::Return<void> init_1_1(const ::android::sp<::android::hardware::secure_element::V1_1::ISecureElementHalCallback>& clientCallback) = 0;

    /**
     * Reset the Secure Element.
     * 
     * HAL should trigger reset to the secure element. It could hardware power cycle or
     * a soft reset depends on hardware design.
     * HAL service must send onStateChange() with connected equal to true
     * after resetting and all the re-initialization has been successfully completed.
     * 
     * @return SecureElementStatus::SUCCESS on success and SecureElementStatus::FAILED on error.
     */
    virtual ::android::hardware::Return<::android::hardware::secure_element::V1_0::SecureElementStatus> reset() = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::secure_element::V1_2::ISecureElement>> castFrom(const ::android::sp<::android::hardware::secure_element::V1_2::ISecureElement>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::secure_element::V1_2::ISecureElement>> castFrom(const ::android::sp<::android::hardware::secure_element::V1_1::ISecureElement>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::secure_element::V1_2::ISecureElement>> castFrom(const ::android::sp<::android::hardware::secure_element::V1_0::ISecureElement>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::secure_element::V1_2::ISecureElement>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<ISecureElement> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISecureElement> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<ISecureElement> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISecureElement> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<ISecureElement> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISecureElement> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<ISecureElement> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<ISecureElement> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::secure_element::V1_2::ISecureElement>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::secure_element::V1_2::ISecureElement>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::secure_element::V1_2::ISecureElement::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_2
}  // namespace secure_element
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_SECURE_ELEMENT_V1_2_ISECUREELEMENT_H
