#ifndef HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_1_IRADIOCONFIG_H
#define HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_1_IRADIOCONFIG_H

#include <android/hardware/radio/config/1.0/IRadioConfig.h>
#include <android/hardware/radio/config/1.1/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {
namespace V1_1 {

/**
 * Note: IRadioConfig 1.1 is an intermediate layer between Android P and Android Q.
 * It's specifically designed for CBRS related interfaces. All other interfaces
 * for Q are added in IRadioConfig 1.2.
 * 
 * This interface is used by telephony and telecom to talk to cellular radio for the purpose of
 * radio configuration, and it is not associated with any specific modem or slot.
 * All the functions have minimum one parameter:
 * serial: which corresponds to serial no. of request. Serial numbers must only be memorized for the
 * duration of a method call. If clients provide colliding serials (including passing the same
 * serial to different methods), multiple responses (one for each method call) must still be served.
 */
struct IRadioConfig : public ::android::hardware::radio::config::V1_0::IRadioConfig {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.radio.config@1.1::IRadioConfig"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Set response functions for radio config requests & radio config indications.
     * 
     * @param radioConfigResponse Object containing radio config response functions
     * @param radioConfigIndication Object containing radio config indications
     */
    virtual ::android::hardware::Return<void> setResponseFunctions(const ::android::sp<::android::hardware::radio::config::V1_0::IRadioConfigResponse>& radioConfigResponse, const ::android::sp<::android::hardware::radio::config::V1_0::IRadioConfigIndication>& radioConfigIndication) = 0;

    /**
     * Get SIM Slot status.
     * 
     * Request provides the slot status of all active and inactive SIM slots and whether card is
     * present in the slots or not.
     * 
     * @param serial Serial number of request.
     * 
     * Response callback is IRadioConfigResponse.getSimSlotsStatusResponse()
     */
    virtual ::android::hardware::Return<void> getSimSlotsStatus(int32_t serial) = 0;

    /**
     * Set SIM Slot mapping.
     * 
     * Maps the logical slots to the physical slots. Logical slot is the slot that is seen by modem.
     * Physical slot is the actual physical slot. Request maps the physical slot to logical slot.
     * Logical slots that are already mapped to the requested physical slot are not impacted.
     * 
     * Example no. of logical slots 1 and physical slots 2:
     * The only logical slot (index 0) can be mapped to first physical slot (value 0) or second
     * physical slot(value 1), while the other physical slot remains unmapped and inactive.
     * slotMap[0] = 1 or slotMap[0] = 0
     * 
     * Example no. of logical slots 2 and physical slots 2:
     * First logical slot (index 0) can be mapped to physical slot 1 or 2 and other logical slot
     * can be mapped to other physical slot. Each logical slot must be mapped to a physical slot.
     * slotMap[0] = 0 and slotMap[1] = 1 or slotMap[0] = 1 and slotMap[1] = 0
     * 
     * @param serial Serial number of request
     * @param slotMap Logical to physical slot mapping, size == no. of radio instances. Index is
     *        mapping to logical slot and value to physical slot, need to provide all the slots
     *        mapping when sending request in case of multi slot device.
     *        EX: uint32_t slotMap[logical slot] = physical slot
     *        index 0 is the first logical_slot number of logical slots is equal to number of Radio
     *        instances and number of physical slots is equal to size of slotStatus in
     *        getSimSlotsStatusResponse
     * 
     * Response callback is IRadioConfigResponse.setSimSlotsMappingResponse()
     */
    virtual ::android::hardware::Return<void> setSimSlotsMapping(int32_t serial, const ::android::hardware::hidl_vec<uint32_t>& slotMap) = 0;

    /**
     * Request current phone capability.
     * 
     * @param serial Serial number of request.
     * 
     * Response callback is IRadioResponse.getPhoneCapabilityResponse() which
     * will return <@1.1::PhoneCapability>.
     */
    virtual ::android::hardware::Return<void> getPhoneCapability(int32_t serial) = 0;

    /**
     * Set preferred data modem Id.
     * In a multi-SIM device, notify modem layer which logical modem will be used primarily
     * for data. It helps modem with resource optimization and decisions of what data connections
     * should be satisfied.
     * 
     * @param serial Serial number of request.
     * @param modem Id the logical modem ID, which should match one of modem IDs returned
     * from getPhoneCapability().
     * 
     * Response callback is IRadioConfigResponse.setPreferredDataModemResponse()
     */
    virtual ::android::hardware::Return<void> setPreferredDataModem(int32_t serial, uint8_t modemId) = 0;

    /**
     * Set modems configurations by specifying the number of live modems (i.e modems that are
     * enabled and actively working as part of a working telephony stack).
     * 
     * Example: this interface can be used to switch to single/multi sim mode by specifying
     * the number of live modems as 1, 2, etc
     * 
     * Note: by setting the number of live modems in this API, that number of modems will
     * subsequently get enabled/disabled
     * 
     * @param serial serial number of request.
     * @param modemsConfig ModemsConfig object including the number of live modems
     * 
     * Response callback is IRadioResponse.setModemsConfigResponse()
     */
    virtual ::android::hardware::Return<void> setModemsConfig(int32_t serial, const ::android::hardware::radio::config::V1_1::ModemsConfig& modemsConfig) = 0;

    /**
     * Get modems configurations. This interface is used to get modem configurations
     * which includes the number of live modems (i.e modems that are
     * enabled and actively working as part of a working telephony stack)
     * 
     * Note: in order to get the overall number of modems available on the phone,
     * refer to getPhoneCapability API
     * 
     * @param serial Serial number of request.
     * 
     * Response callback is IRadioResponse.getModemsConfigResponse() which
     * will return <@1.1::ModemsConfig>.
     */
    virtual ::android::hardware::Return<void> getModemsConfig(int32_t serial) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::config::V1_1::IRadioConfig>> castFrom(const ::android::sp<::android::hardware::radio::config::V1_1::IRadioConfig>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::config::V1_1::IRadioConfig>> castFrom(const ::android::sp<::android::hardware::radio::config::V1_0::IRadioConfig>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::radio::config::V1_1::IRadioConfig>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IRadioConfig> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IRadioConfig> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IRadioConfig> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IRadioConfig> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IRadioConfig> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IRadioConfig> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IRadioConfig> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IRadioConfig> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::radio::config::V1_1::IRadioConfig>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::radio::config::V1_1::IRadioConfig>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::radio::config::V1_1::IRadioConfig::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_1
}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_RADIO_CONFIG_V1_1_IRADIOCONFIG_H
