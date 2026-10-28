#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CONFIRMATIONUI_V1_0_ICONFIRMATIONRESULTCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CONFIRMATIONUI_V1_0_ICONFIRMATIONRESULTCALLBACK_H

#include <android/hardware/confirmationui/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace confirmationui {
namespace V1_0 {

/**
 * Callback interface passed to IConfirmationUI::promptUserConfirmation().
 * Informs the caller about the result of the prompt operation.
 */
struct IConfirmationResultCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.confirmationui@1.0::IConfirmationResultCallback"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * This callback is called by the confirmation provider when it stops prompting the user.
     * Iff the user has confirmed the prompted text, error is ErrorCode::OK and the
     * parameters formattedMessage and confirmationToken hold the values needed to request
     * a signature from keymaster.
     * In all other cases formattedMessage and confirmationToken must be of length 0.
     * 
     * @param error - OK: IFF the user has confirmed the prompt.
     *              - Canceled: If the user has pressed the cancel button.
     *              - Aborted: If IConfirmationUI::abort() was called.
     *              - SystemError: If an unexpected System error occurred that prevented the TUI
     *                             from being shut down gracefully.
     * @param formattedMessage holds the prompt text and extra data.
     *                         The message is CBOR (RFC 7049) encoded and has the following format:
     *                         CBOR_MAP{ "prompt", <promptText>, "extra", <extraData> }
     *                         The message is a CBOR encoded map (type 5) with the keys
     *                         "prompt" and "extra". The keys are encoded as CBOR text string
     *                         (type 3). The value <promptText> is encoded as CBOR text string
     *                         (type 3), and the value <extraData> is encoded as CBOR byte string
     *                         (type 2). The map must have exactly one key value pair for each of
     *                         the keys "prompt" and "extra". Other keys are not allowed.
     *                         The value of "prompt" is given by the proptText argument to
     *                         IConfirmationUI::promptUserConfirmation and must not be modified
     *                         by the implementation.
     *                         The value of "extra" is given by the extraData argument to
     *                         IConfirmationUI::promptUserConfirmation and must not be modified
     *                         or interpreted by the implementation.
     * 
     * @param confirmationToken a 32-byte HMAC-SHA256 value, computed over
     *                          "confirmation token" || <formattedMessage>
     *                          i.e. the literal UTF-8 encoded string "confirmation token", without
     *                          the "", concatenated with the formatted message as returned in the
     *                          formattedMessage argument. The HMAC is keyed with a 256-bit secret
     *                          which is shared with Keymaster. In test mode the test key MUST be
     *                          used (see types.hal TestModeCommands and TestKeyBits).
     */
    virtual ::android::hardware::Return<void> result(::android::hardware::confirmationui::V1_0::ResponseCode error, const ::android::hardware::hidl_vec<uint8_t>& formattedMessage, const ::android::hardware::hidl_vec<uint8_t>& confirmationToken) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>> castFrom(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IConfirmationResultCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IConfirmationResultCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IConfirmationResultCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IConfirmationResultCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IConfirmationResultCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IConfirmationResultCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IConfirmationResultCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IConfirmationResultCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::confirmationui::V1_0::IConfirmationResultCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::confirmationui::V1_0::IConfirmationResultCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace confirmationui
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CONFIRMATIONUI_V1_0_ICONFIRMATIONRESULTCALLBACK_H
