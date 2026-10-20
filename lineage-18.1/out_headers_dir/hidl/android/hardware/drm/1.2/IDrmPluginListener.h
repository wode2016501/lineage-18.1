#ifndef HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_2_IDRMPLUGINLISTENER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_2_IDRMPLUGINLISTENER_H

#include <android/hardware/drm/1.0/IDrmPluginListener.h>
#include <android/hardware/drm/1.0/types.h>
#include <android/hardware/drm/1.2/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_2 {

/**
 * IDrmPluginListener is a listener interface for Drm events sent from an
 * IDrmPlugin instance.
 */
struct IDrmPluginListener : public ::android::hardware::drm::V1_0::IDrmPluginListener {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.drm@1.2::IDrmPluginListener"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Legacy event sending method, it sends events of various types using a
     * single overloaded set of parameters. This form is deprecated.
     * 
     * @param eventType the type of the event
     * @param sessionId identifies the session the event originated from
     * @param data event-specific data blob
     */
    virtual ::android::hardware::Return<void> sendEvent(::android::hardware::drm::V1_0::EventType eventType, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& data) = 0;

    /**
     * Send a license expiration update to the listener. The expiration
     * update indicates how long the current keys are valid before they
     * need to be renewed.
     * 
     * @param sessionId identifies the session the event originated from
     * @param expiryTimeInMS the time when the keys need to be renewed.
     * The time is in milliseconds, relative to the Unix epoch. A time
     * of 0 indicates that the keys never expire.
     */
    virtual ::android::hardware::Return<void> sendExpirationUpdate(const ::android::hardware::hidl_vec<uint8_t>& sessionId, int64_t expiryTimeInMS) = 0;

    /**
     * Send a keys change event to the listener. The keys change event
     * indicates the status of each key in the session. Keys can be
     * indicated as being usable, expired, outputnotallowed or statuspending.
     * 
     * @param sessionId identifies the session the event originated from
     * @param keyStatusList indicates the status for each key ID in the
     * session.
     * @param hasNewUsableKey indicates if the event includes at least one
     * key that has become usable.
     */
    virtual ::android::hardware::Return<void> sendKeysChange(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_0::KeyStatus>& keyStatusList, bool hasNewUsableKey) = 0;

    /**
     * Some device crypto hardware is incapable of retaining crypto
     * session state across suspend and resume cycles. A
     * SessionLostState event must be signaled when a session has
     * become invalid for this reason. This event must not be used to
     * indicate a failure in the crypto system. Closing the session
     * and opening a new one must allow the application to resume
     * normal use of the drm hal module.
     * 
     * @param sessionId identifies the session that has been invalidated
     */
    virtual ::android::hardware::Return<void> sendSessionLostState(const ::android::hardware::hidl_vec<uint8_t>& sessionId) = 0;

    /**
     * Send a keys change event to the listener. The keys change event
     * indicates the status of each key in the session. Keys can be
     * indicated as being usable, expired, outputnotallowed or statuspending.
     * 
     * This method only differs from @1.0 version by the addition of new
     * KeyStatusType(s) in keyStatusList.
     * 
     * @param sessionId identifies the session the event originated from
     * @param keyStatusList indicates the status for each key ID in the
     * session.
     * @param hasNewUsableKey indicates if the event includes at least one
     * key that has become usable.
     */
    virtual ::android::hardware::Return<void> sendKeysChange_1_2(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<::android::hardware::drm::V1_2::KeyStatus>& keyStatusList, bool hasNewUsableKey) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_2::IDrmPluginListener>> castFrom(const ::android::sp<::android::hardware::drm::V1_2::IDrmPluginListener>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_2::IDrmPluginListener>> castFrom(const ::android::sp<::android::hardware::drm::V1_0::IDrmPluginListener>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::drm::V1_2::IDrmPluginListener>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IDrmPluginListener> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IDrmPluginListener> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IDrmPluginListener> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IDrmPluginListener> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IDrmPluginListener> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IDrmPluginListener> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IDrmPluginListener> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IDrmPluginListener> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::drm::V1_2::IDrmPluginListener>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::drm::V1_2::IDrmPluginListener>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::drm::V1_2::IDrmPluginListener::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_2
}  // namespace drm
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_2_IDRMPLUGINLISTENER_H
