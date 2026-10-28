#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CONTEXTHUB_V1_0_ICONTEXTHUBCALLBACK_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CONTEXTHUB_V1_0_ICONTEXTHUBCALLBACK_H

#include <android/hardware/contexthub/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace contexthub {
namespace V1_0 {

struct IContexthubCallback : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.contexthub@1.0::IContexthubCallback"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * This callback is passed by the Contexthub service to the HAL
     * implementation to allow the HAL to send asynchronous messages back
     * to the service and registered clients of the ContextHub service.
     * 
     * @params msg : message
     * 
     */
    virtual ::android::hardware::Return<void> handleClientMsg(const ::android::hardware::contexthub::V1_0::ContextHubMsg& msg) = 0;

    /**
     * This callback is passed by the Contexthub service to the HAL
     * implementation to allow the HAL to send the response for a
     * transaction.
     * 
     * @params txnId : transaction id whose result is being sent
     *                 passed in by the service at start of transacation.
     *         result: result of transaction.
     * 
     */
    virtual ::android::hardware::Return<void> handleTxnResult(uint32_t txnId, ::android::hardware::contexthub::V1_0::TransactionResult result) = 0;

    /**
     * This callback is passed by the Contexthub service to the HAL
     * implementation to allow the HAL to send an asynchronous event
     * to the ContextHub service.
     * 
     * @params msg : message
     * 
     */
    virtual ::android::hardware::Return<void> handleHubEvent(::android::hardware::contexthub::V1_0::AsyncEventType evt) = 0;

    /**
     * This callback is passed by the Contexthub service to the HAL
     * implementation to allow the HAL to send a notification to the service
     * that a nanp-app has aborted.
     * This method must be called when a nanoapp invokes chreAbort(...)).
     * 
     * @params appId : app identifier
     *               : abortCode code passed by the nanoApp.
     * 
     * Also see chreAbort(...)
     * 
     */
    virtual ::android::hardware::Return<void> handleAppAbort(uint64_t appId, uint32_t abortCode) = 0;

    /**
     * This callback is passed by the Contexthub service to the HAL
     * implementation to allow the HAL to send information about the
     * currently loaded and active nanoapps on the hub.
     * 
     * @params appInfo : vector of HubAppinfo structure for each nanoApp
     *                   on the hub that can be enabled, disabled and
     *                   unloaded by the service. Any nanoApps that cannot
     *                   be controlled by the service must not be reported.
     *                   All nanoApps that can be controlled by the service
     *                   must be reported.
     */
    virtual ::android::hardware::Return<void> handleAppsInfo(const ::android::hardware::hidl_vec<::android::hardware::contexthub::V1_0::HubAppInfo>& appInfo) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::contexthub::V1_0::IContexthubCallback>> castFrom(const ::android::sp<::android::hardware::contexthub::V1_0::IContexthubCallback>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::contexthub::V1_0::IContexthubCallback>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IContexthubCallback> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IContexthubCallback> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IContexthubCallback> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IContexthubCallback> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IContexthubCallback> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IContexthubCallback> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IContexthubCallback> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IContexthubCallback> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::contexthub::V1_0::IContexthubCallback>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::contexthub::V1_0::IContexthubCallback>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::contexthub::V1_0::IContexthubCallback::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace contexthub
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CONTEXTHUB_V1_0_ICONTEXTHUBCALLBACK_H
