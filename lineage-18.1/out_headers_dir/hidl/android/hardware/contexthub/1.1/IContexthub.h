#ifndef HIDL_GENERATED_ANDROID_HARDWARE_CONTEXTHUB_V1_1_ICONTEXTHUB_H
#define HIDL_GENERATED_ANDROID_HARDWARE_CONTEXTHUB_V1_1_ICONTEXTHUB_H

#include <android/hardware/contexthub/1.0/IContexthub.h>
#include <android/hardware/contexthub/1.1/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace contexthub {
namespace V1_1 {

struct IContexthub : public ::android::hardware::contexthub::V1_0::IContexthub {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.contexthub@1.1::IContexthub"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getHubs
     */
    using getHubs_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::contexthub::V1_0::ContextHub>& hubs)>;
    /**
     * Enumerate all available context hubs on the system.
     * 
     * @return hubs list of hubs on this system.
     */
    virtual ::android::hardware::Return<void> getHubs(getHubs_cb _hidl_cb) = 0;

    /**
     * Register a callback for the HAL implementation to send asynchronous
     * messages to the service from a context hub. There can be a maximum of
     * one callback registered with the HAL. A call to this function when a
     * callback has already been registered must override the previous
     * registration.
     * 
     * @param hubId    identifier for the hub
     *        callback an implementation of the IContextHubCallbacks
     * 
     * @return result OK on success
     *                BAD_VALUE if parameters are not sane
     * 
     */
    virtual ::android::hardware::Return<::android::hardware::contexthub::V1_0::Result> registerCallback(uint32_t hubId, const ::android::sp<::android::hardware::contexthub::V1_0::IContexthubCallback>& cb) = 0;

    /**
     * Send a message to a hub
     * 
     * @param hubId identifier for hub to send message to
     *        msg   message to be sent
     * 
     * @return result OK if successful, error code otherwise
     *                BAD_VALUE if parameters are not sane
     *                TRANSACTION_FAILED if message send failed
     */
    virtual ::android::hardware::Return<::android::hardware::contexthub::V1_0::Result> sendMessageToHub(uint32_t hubId, const ::android::hardware::contexthub::V1_0::ContextHubMsg& msg) = 0;

    /**
     * Loads a nanoApp. After loading, the nanoApp's init method must be called.
     * After the init method for nanoApp returns success, this must be indicated
     * to the service by an asynchronous call to handleTxnResult.
     * 
     * Loading a nanoapp must not take more than 30 seconds.
     * 
     * Depending on the implementation, nanoApps loaded via this API may or may
     * not persist across reboots of the hub. If they do persist, the
     * implementation must initially place nanoApps in the disabled state upon a
     * reboot, and not start them until a call is made to enableNanoApp(). In
     * this case, the app must also be unloaded upon a factory reset of the
     * device.
     * 
     * @param hubId identifer of the contextHub
     *        appBinary contains the binary representation of the nanoApp, plus
     *                  metadata
     *        transactionId transactionId for this call
     * 
     * @return result OK if transation started
     *                BAD_VALUE if parameters are not sane
     *                TRANSACTION_PENDING if hub is busy with another
     *                                    load/unload transaction
     *                TRANSACTION_FAILED if load failed synchronously
     * 
     */
    virtual ::android::hardware::Return<::android::hardware::contexthub::V1_0::Result> loadNanoApp(uint32_t hubId, const ::android::hardware::contexthub::V1_0::NanoAppBinary& appBinary, uint32_t transactionId) = 0;

    /**
     * Unloads a nanoApp. Before the unload, the apps deinit method is called.
     * After this, success must be indicated to the service through an
     * asynchronous call to handleTxnResult.
     * 
     * Unloading a nanoapp must not take more than 5 seconds.
     * 
     * @param hubId identifer of the contextHub
     *        appId appIdentifier returned by the HAL
     *        msg   message to be sent
     * 
     * @return result OK if transation started
     *                BAD_VALUE if parameters are not sane
     *                TRANSACTION_PENDING if hub is busy with another
     *                                    load/unload transaction
     *                TRANSACTION_FAILED if unload failed synchronously
     * 
     */
    virtual ::android::hardware::Return<::android::hardware::contexthub::V1_0::Result> unloadNanoApp(uint32_t hubId, uint64_t appId, uint32_t transactionId) = 0;

    /**
     * Enables a nanoApp. The app's init method is called.
     * After this, success must be indicated to the service through an
     * asynchronous message.
     * 
     * Enabling a nanoapp must not take more than 5 seconds.
     * 
     * @param hubId identifer of the contextHub
     *        appId appIdentifier returned by the HAL
     *        msg   message to be sent
     * 
     * @return result OK if transation started
     *                BAD_VALUE if parameters are not sane
     *                TRANSACTION_PENDING if hub is busy with another
     *                                    load/unload transaction
     *                FAILED_TRANSACTION if load fails immediately
     * 
     */
    virtual ::android::hardware::Return<::android::hardware::contexthub::V1_0::Result> enableNanoApp(uint32_t hubId, uint64_t appId, uint32_t transactionId) = 0;

    /**
     * Disables a nanoApp. The app's deinit method is called.
     * After this, success must be indicated to the service through an
     * asynchronous message.
     * 
     * Disabling a nanoapp must not take more than 5 seconds.
     * 
     * @param hubId identifer of the contextHub
     *        appId appIdentifier returned by the HAL
     *        msg   message to be sent
     * 
     * @return result OK if transation started
     *                BAD_VALUE if parameters are not sane
     *                TRANSACTION_PENDING if hub is busy with another
     *                                    load/unload transaction
     *                FAILED_TRANSACTION if load fails immediately
     * 
     */
    virtual ::android::hardware::Return<::android::hardware::contexthub::V1_0::Result> disableNanoApp(uint32_t hubId, uint64_t appId, uint32_t transactionId) = 0;

    /**
     * Queries for Loaded apps on the hub
     * 
     * @param hubId identifer of the contextHub
     * 
     * @return apps all nanoApps on the hub.
     *              All nanoApps that can be modified by the service must
     *              be returned. A non-modifiable nanoapps must not be
     *              returned. A modifiable nanoApp is one that can be
     *              unloaded/disabled/enabled by the service.
     * 
     */
    virtual ::android::hardware::Return<::android::hardware::contexthub::V1_0::Result> queryApps(uint32_t hubId) = 0;

    /**
     * Notification sent by the framework to indicate that the user
     * has changed a setting.
     * 
     * @param setting User setting that has been modified.
     * @param newValue The update value of the user setting.
     */
    virtual ::android::hardware::Return<void> onSettingChanged(::android::hardware::contexthub::V1_1::Setting setting, ::android::hardware::contexthub::V1_1::SettingValue newValue) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::contexthub::V1_1::IContexthub>> castFrom(const ::android::sp<::android::hardware::contexthub::V1_1::IContexthub>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::contexthub::V1_1::IContexthub>> castFrom(const ::android::sp<::android::hardware::contexthub::V1_0::IContexthub>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::contexthub::V1_1::IContexthub>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IContexthub> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IContexthub> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IContexthub> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IContexthub> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IContexthub> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IContexthub> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IContexthub> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IContexthub> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::contexthub::V1_1::IContexthub>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::contexthub::V1_1::IContexthub>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::contexthub::V1_1::IContexthub::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_1
}  // namespace contexthub
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_CONTEXTHUB_V1_1_ICONTEXTHUB_H
