#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_0_IWIFI_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_0_IWIFI_H

#include <android/hardware/wifi/1.0/IWifiChip.h>
#include <android/hardware/wifi/1.0/IWifiEventCallback.h>
#include <android/hardware/wifi/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_0 {

/**
 * This is the root of the HAL module and is the interface returned when
 * loading an implementation of the Wi-Fi HAL. There must be at most one
 * module loaded in the system.
 */
struct IWifi : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.wifi@1.0::IWifi"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for registerEventCallback
     */
    using registerEventCallback_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    // @entry @callflow(next="*")
    /**
     * Requests notifications of significant events for the HAL. Multiple calls to
     * this must register multiple callbacks each of which must receive all
     * events. |IWifiEventCallback| object registration must be independent of the
     * state of the rest of the HAL and must persist though stops/starts. These
     * objects must be deleted when the corresponding client process is dead.
     * 
     * @param callback An instance of the |IWifiEventCallback| HIDL interface
     *        object.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.UNKNOWN|
     */
    virtual ::android::hardware::Return<void> registerEventCallback(const ::android::sp<::android::hardware::wifi::V1_0::IWifiEventCallback>& callback, registerEventCallback_cb _hidl_cb) = 0;

    /**
     * Get the current state of the HAL.
     * 
     * @return started true if started, false otherwise.
     */
    virtual ::android::hardware::Return<bool> isStarted() = 0;

    /**
     * Return callback for start
     */
    using start_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    // @entry @callflow(next={"registerEventCallback", "start", "stop", "getChip"})
    /**
     * Perform any setup that is required to make use of the module. If the module
     * is already started then this must be a noop.
     * Must trigger |IWifiEventCallback.onStart| on success.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.NOT_AVAILABLE|,
     *         |WifiStatusCode.UNKNOWN|
     */
    virtual ::android::hardware::Return<void> start(start_cb _hidl_cb) = 0;

    /**
     * Return callback for stop
     */
    using stop_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    // @exit @callflow(next={"registerEventCallback", "start", "stop"})
    /**
     * Tear down any state, ongoing commands, etc. If the module is already
     * stopped then this must be a noop. If the HAL is already stopped or it
     * succeeds then onStop must be called. After calling this all IWifiChip
     * objects will be considered invalid.
     * Must trigger |IWifiEventCallback.onStop| on success.
     * Must trigger |IWifiEventCallback.onFailure| on failure.
     * 
     * Calling stop then start is a valid way of resetting state in the HAL,
     * driver, firmware.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.NOT_STARTED|,
     *         |WifiStatusCode.UNKNOWN|
     */
    virtual ::android::hardware::Return<void> stop(stop_cb _hidl_cb) = 0;

    /**
     * Return callback for getChipIds
     */
    using getChipIds_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status, const ::android::hardware::hidl_vec<uint32_t>& chipIds)>;
    // @callflow(next="*")
    /**
     * Retrieve the list of all chip Id's on the device.
     * The corresponding |IWifiChip| object for any chip can be
     * retrieved using |getChip| method.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.NOT_STARTED|,
     *         |WifiStatusCode.UNKNOWN|
     * @return chipIds List of all chip Id's on the device.
     */
    virtual ::android::hardware::Return<void> getChipIds(getChipIds_cb _hidl_cb) = 0;

    /**
     * Return callback for getChip
     */
    using getChip_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status, const ::android::sp<::android::hardware::wifi::V1_0::IWifiChip>& chip)>;
    // @callflow(next="*")
    /**
     * Gets a HIDL interface object for the chip corresponding to the
     * provided chipId.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.NOT_STARTED|,
     *         |WifiStatusCode.UNKNOWN|
     * @return chip HIDL interface object representing the chip.
     */
    virtual ::android::hardware::Return<void> getChip(uint32_t chipId, getChip_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifi>> castFrom(const ::android::sp<::android::hardware::wifi::V1_0::IWifi>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_0::IWifi>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IWifi> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IWifi> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IWifi> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IWifi> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IWifi> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IWifi> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IWifi> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IWifi> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::wifi::V1_0::IWifi>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::wifi::V1_0::IWifi>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::wifi::V1_0::IWifi::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace wifi
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_0_IWIFI_H
