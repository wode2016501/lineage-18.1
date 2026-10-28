#ifndef HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_4_IWIFIRTTCONTROLLER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_4_IWIFIRTTCONTROLLER_H

#include <android/hardware/wifi/1.0/IWifiRttController.h>
#include <android/hardware/wifi/1.0/types.h>
#include <android/hardware/wifi/1.4/IWifiRttControllerEventCallback.h>
#include <android/hardware/wifi/1.4/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_4 {

/**
 * Interface used to perform RTT(Round trip time) operations.
 */
struct IWifiRttController : public ::android::hardware::wifi::V1_0::IWifiRttController {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.wifi@1.4::IWifiRttController"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getBoundIface
     */
    using getBoundIface_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status, const ::android::sp<::android::hardware::wifi::V1_0::IWifiIface>& boundIface)>;
    /**
     * Get the iface on which the RTT operations must be performed.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|
     * @return boundIface HIDL interface object representing the iface if bound
     *         to a specific iface, null otherwise
     */
    virtual ::android::hardware::Return<void> getBoundIface(getBoundIface_cb _hidl_cb) = 0;

    /**
     * Return callback for registerEventCallback
     */
    using registerEventCallback_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * Requests notifications of significant events on this rtt controller.
     * Multiple calls to this must register multiple callbacks each of which must
     * receive all events.
     * 
     * @param callback An instance of the |IWifiRttControllerEventCallback| HIDL
     *        interface object.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|
     */
    virtual ::android::hardware::Return<void> registerEventCallback(const ::android::sp<::android::hardware::wifi::V1_0::IWifiRttControllerEventCallback>& callback, registerEventCallback_cb _hidl_cb) = 0;

    /**
     * Return callback for rangeRequest
     */
    using rangeRequest_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * API to request RTT measurement.
     * 
     * @param cmdId command Id to use for this invocation.
     * @param rttConfigs Vector of |RttConfig| parameters.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> rangeRequest(uint32_t cmdId, const ::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::RttConfig>& rttConfigs, rangeRequest_cb _hidl_cb) = 0;

    /**
     * Return callback for rangeCancel
     */
    using rangeCancel_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * API to cancel RTT measurements.
     * 
     * @param cmdId command Id corresponding to the original request.
     * @param addrs Vector of addresses for which to cancel.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> rangeCancel(uint32_t cmdId, const ::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 6>>& addrs, rangeCancel_cb _hidl_cb) = 0;

    /**
     * Return callback for getCapabilities
     */
    using getCapabilities_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status, const ::android::hardware::wifi::V1_0::RttCapabilities& capabilities)>;
    /**
     * RTT capabilities of the device.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     * @return capabilities Instance of |RttCapabilities|.
     */
    virtual ::android::hardware::Return<void> getCapabilities(getCapabilities_cb _hidl_cb) = 0;

    /**
     * Return callback for setLci
     */
    using setLci_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * API to configure the LCI(Location civic information).
     * Used in RTT Responder mode only.
     * 
     * @param cmdId command Id to use for this invocation.
     * @param lci Instance of |RttLciInformation|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> setLci(uint32_t cmdId, const ::android::hardware::wifi::V1_0::RttLciInformation& lci, setLci_cb _hidl_cb) = 0;

    /**
     * Return callback for setLcr
     */
    using setLcr_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * API to configure the LCR(Location civic records).
     * Used in RTT Responder mode only.
     * 
     * @param cmdId command Id to use for this invocation.
     * @param lcr Instance of |RttLcrInformation|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> setLcr(uint32_t cmdId, const ::android::hardware::wifi::V1_0::RttLcrInformation& lcr, setLcr_cb _hidl_cb) = 0;

    /**
     * Return callback for getResponderInfo
     */
    using getResponderInfo_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status, const ::android::hardware::wifi::V1_0::RttResponder& info)>;
    /**
     * Get RTT responder information e.g. WiFi channel to enable responder on.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     * @return info Instance of |RttResponderInfo|.
     */
    virtual ::android::hardware::Return<void> getResponderInfo(getResponderInfo_cb _hidl_cb) = 0;

    /**
     * Return callback for enableResponder
     */
    using enableResponder_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * Enable RTT responder mode.
     * 
     * @param cmdId command Id to use for this invocation.
     * @parm channelHint Hint of the channel information where RTT responder must
     *       be enabled on.
     * @param maxDurationInSeconds Timeout of responder mode.
     * @param info Instance of |RttResponderInfo|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> enableResponder(uint32_t cmdId, const ::android::hardware::wifi::V1_0::WifiChannelInfo& channelHint, uint32_t maxDurationSeconds, const ::android::hardware::wifi::V1_0::RttResponder& info, enableResponder_cb _hidl_cb) = 0;

    /**
     * Return callback for disableResponder
     */
    using disableResponder_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * Disable RTT responder mode.
     * 
     * @param cmdId command Id corresponding to the original request.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> disableResponder(uint32_t cmdId, disableResponder_cb _hidl_cb) = 0;

    /**
     * Return callback for registerEventCallback_1_4
     */
    using registerEventCallback_1_4_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * Requests notifications of significant events on this rtt controller.
     * Multiple calls to this must register multiple callbacks each of which must
     * receive all events.
     * 
     * @param callback An instance of the |IWifiRttControllerEventCallback| HIDL
     *        interface object.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_IFACE_INVALID|
     */
    virtual ::android::hardware::Return<void> registerEventCallback_1_4(const ::android::sp<::android::hardware::wifi::V1_4::IWifiRttControllerEventCallback>& callback, registerEventCallback_1_4_cb _hidl_cb) = 0;

    /**
     * Return callback for rangeRequest_1_4
     */
    using rangeRequest_1_4_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * API to request RTT measurement.
     * 
     * @param cmdId command Id to use for this invocation.
     * @param rttConfigs Vector of |RttConfig| parameters.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> rangeRequest_1_4(uint32_t cmdId, const ::android::hardware::hidl_vec<::android::hardware::wifi::V1_4::RttConfig>& rttConfigs, rangeRequest_1_4_cb _hidl_cb) = 0;

    /**
     * Return callback for getCapabilities_1_4
     */
    using getCapabilities_1_4_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status, const ::android::hardware::wifi::V1_4::RttCapabilities& capabilities)>;
    /**
     * RTT capabilities of the device.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     * @return capabilities Instance of |RttCapabilities|.
     */
    virtual ::android::hardware::Return<void> getCapabilities_1_4(getCapabilities_1_4_cb _hidl_cb) = 0;

    /**
     * Return callback for getResponderInfo_1_4
     */
    using getResponderInfo_1_4_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status, const ::android::hardware::wifi::V1_4::RttResponder& info)>;
    /**
     * Get RTT responder information e.g. WiFi channel to enable responder on.
     * 
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     * @return info Instance of |RttResponderInfo|.
     */
    virtual ::android::hardware::Return<void> getResponderInfo_1_4(getResponderInfo_1_4_cb _hidl_cb) = 0;

    /**
     * Return callback for enableResponder_1_4
     */
    using enableResponder_1_4_cb = std::function<void(const ::android::hardware::wifi::V1_0::WifiStatus& status)>;
    /**
     * Enable RTT responder mode.
     * 
     * @param cmdId command Id to use for this invocation.
     * @parm channelHint Hint of the channel information where RTT responder must
     *       be enabled on.
     * @param maxDurationInSeconds Timeout of responder mode.
     * @param info Instance of |RttResponderInfo|.
     * @return status WifiStatus of the operation.
     *         Possible status codes:
     *         |WifiStatusCode.SUCCESS|,
     *         |WifiStatusCode.ERROR_WIFI_RTT_CONTROLLER_INVALID|,
     *         |WifiStatusCode.ERROR_INVALID_ARGS|,
     *         |WifiStatusCode.ERROR_NOT_AVAILABLE|,
     *         |WifiStatusCode.ERROR_UNKNOWN|
     */
    virtual ::android::hardware::Return<void> enableResponder_1_4(uint32_t cmdId, const ::android::hardware::wifi::V1_0::WifiChannelInfo& channelHint, uint32_t maxDurationInSeconds, const ::android::hardware::wifi::V1_4::RttResponder& info, enableResponder_1_4_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_4::IWifiRttController>> castFrom(const ::android::sp<::android::hardware::wifi::V1_4::IWifiRttController>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_4::IWifiRttController>> castFrom(const ::android::sp<::android::hardware::wifi::V1_0::IWifiRttController>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::wifi::V1_4::IWifiRttController>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IWifiRttController> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IWifiRttController> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IWifiRttController> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IWifiRttController> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IWifiRttController> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IWifiRttController> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IWifiRttController> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IWifiRttController> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::wifi::V1_4::IWifiRttController>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::wifi::V1_4::IWifiRttController>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::wifi::V1_4::IWifiRttController::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_4
}  // namespace wifi
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_WIFI_V1_4_IWIFIRTTCONTROLLER_H
