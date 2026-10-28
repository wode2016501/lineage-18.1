#ifndef HIDL_GENERATED_ANDROID_HARDWARE_TV_CEC_V2_0_IHDMICEC_H
#define HIDL_GENERATED_ANDROID_HARDWARE_TV_CEC_V2_0_IHDMICEC_H

#include <android/hardware/tv/cec/2.0/IHdmiCecCallback.h>
#include <android/hardware/tv/cec/2.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace tv {
namespace cec {
namespace V2_0 {

/**
 * HDMI-CEC HAL interface definition.
 */
struct IHdmiCec : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.tv.cec@2.0::IHdmiCec"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    // @callflow(next="*")
    /**
     * Passes Primary Device Type that must be used in this system.
     * 
     * HAL must use it to allocate logical address as specified in CEC section
     * 11.3.2 of the CEC spec 2.0b. Then CEC commands addressed the given
     * logical address can be filtered in.
     * This method shall be able to be called up to twice to support two Primary
     * Device Type as specified in CEC Table 11-8 of the CEC spec 2.0b.
     * 
     * @param deviceType that must be used in this system. It must be a valid
     *        value in CecDeviceType for the call to succeed.
     * @return result Result status of the operation. SUCCESS if successful,
     *         FAILURE_INVALID_ARGS if the given device type is invalid,
     *         FAILURE_BUSY if device or resource is busy
     */
    virtual ::android::hardware::Return<::android::hardware::tv::cec::V2_0::Result> addDeviceType(::android::hardware::tv::cec::V2_0::CecDeviceType deviceType) = 0;

    // @callflow(next="addDeviceType") @exit
    /**
     * Clears all Primary Device Types.
     * 
     * It is used when the system plan to reconfigure Primary Device Type,
     * hence to tell HAL to release all logical address associated to them,
     * and change the state back to the beginning.
     */
    virtual ::android::hardware::Return<void> clearDeviceTypes() = 0;

    // @callflow(next="addDeviceType")
    /**
     * Set All Device Types for a Primary Device Type.
     * 
     * This value must be used in REPORT_FEATURES message to response
     * GIVE_FEATURES message in HAL.
     * 
     * @param allDeviceTypes device all device types for a Primary Device Type.
     */
    virtual ::android::hardware::Return<void> setAllDeviceTypes(::android::hardware::hidl_bitfield<::android::hardware::tv::cec::V2_0::CecAllDeviceTypeValue> allDeviceTypes) = 0;

    // @callflow(next="addDeviceType")
    /**
     * Set Device Features for a Primary Device Type.
     * 
     * This value must be used in REPORT_FEATURES message to response
     * GIVE_FEATURES message in HAL.
     * 
     * @param deviceType The device Primary Device Type.
     * @param deviceFeatures device features for a Primary Device Type.
     */
    virtual ::android::hardware::Return<void> setDeviceFeatures(::android::hardware::tv::cec::V2_0::CecDeviceType deviceType, ::android::hardware::hidl_bitfield<::android::hardware::tv::cec::V2_0::CecDeviceFeature> deviceFeatures) = 0;

    // @callflow(next="addDeviceType")
    /**
     * Set Remote Control Profile for a Primary Device Type.
     * 
     * This value must be used in REPORT_FEATURES message to response
     * GIVE_FEATURES message in HAL.
     * 
     * @param deviceType The device Primary Device Type.
     * @param rcProliles remote control profiles for a Primary Device Type.
     */
    virtual ::android::hardware::Return<void> setRcProfile(::android::hardware::tv::cec::V2_0::CecDeviceType deviceType, const ::android::hardware::tv::cec::V2_0::CecRcProfile& rcProfile) = 0;

    /**
     * Return callback for readDeviceInfo
     */
    using readDeviceInfo_cb = std::function<void(::android::hardware::tv::cec::V2_0::Result result, const ::android::hardware::tv::cec::V2_0::CecDeviceInfo& deviceInfo)>;
    // @callflow(next="onTopologyChangeEvent")
    /**
     * Retrieve CEC device information.
     * 
     * CEC section 11.3 of the CEC spec 2.0b specify that a device should not
     * ask for static information that another device has already supplied.
     * Therefore, CEC 2.0 software stack need a map to store all cec
     * devices’ information of current CEC network.
     * The device information is broadcasted by a device after it allocates a
     * logical address.  Messages used to send out these information are
     * REPORT_FEATURES, REPORT_PHYSICAL_ADDRESS, DEVICE_VENDOR_ID.
     * The spec also requires less than 1 second between REPORT_FEATURES and
     * REPORT_PHYSICAL_ADDRESS message, and less than 2 second between
     * REPORT_PHYSICAL_ADDRESS and DEVICE_VENDOR_ID. An Implementation of
     * device information map in hal can help to meet the timing constraints.
     * Logical addressing is part of the process to build this map, so the
     * implementation shall include allocating logical address too.
     * Whenever a device plug/unplug, the topology of CEC network changes.
     * The hal implementation shall update devices’ information map, and
     * send out onTopologyEvent to Android system. Then Android system
     * will use readDeviceInfo to retreive latest devices’ information of CEC
     * network.
     * If SYSTEM_CEC_CONTROL is false, the hal implementation need continue to
     * maintain and update device information map, and send out pending
     * onTopologyEvent to Android system when SYSTEM_CEC_CONTROL is
     * changed to true.
     * 
     * @param logicalAddress logical address of CEC device.
     * @param physicalAddress physical address of CEC device.
     * @return CecDeviceInfo from device information map.
     * @return result Result status of the operation. SUCCESS if successful,
     *         FAILURE_INVALID_ARGS if logical or physical address is invalid.
     *         FAILURE_INVALID_STATE if device information isn't available yet.
     */
    virtual ::android::hardware::Return<void> readDeviceInfo(::android::hardware::tv::cec::V2_0::CecLogicalAddress logicalAddress, uint16_t physicalAddress, readDeviceInfo_cb _hidl_cb) = 0;

    // @callflow(next="*")
    /**
     * Transmits HDMI-CEC message to other HDMI device.
     * 
     * The method must be designed to return in a certain amount of time and not
     * hanging forever. This method MUST complete with in 1 second.
     * 
     * It must try retransmission at least once as specified in the section '7.1
     * Frame Re-transmissions' of the CEC Spec 1.4b.
     * 
     * @param message CEC message to be sent to other HDMI device.
     * @return result Result status of the operation. SUCCESS if successful,
     *         NACK if the sent message is not acknowledged,
     *         BUSY if the CEC bus is busy.
     */
    virtual ::android::hardware::Return<::android::hardware::tv::cec::V2_0::SendMessageResult> sendMessage(const ::android::hardware::tv::cec::V2_0::CecMessage& message) = 0;

    // @callflow(next="*") @entry
    /**
     * Set the callback
     * 
     * It is used by the framework to receive CecMessages, HDMI hotplug event
     * and topology update event. Only one callback client is supported.
     * 
     * @param callback Callback object to pass hdmi events to the system. The
     *        previously registered callback must be replaced with this one.
     */
    virtual ::android::hardware::Return<void> setCallback(const ::android::sp<::android::hardware::tv::cec::V2_0::IHdmiCecCallback>& callback) = 0;

    /**
     * Return callback for getPortInfo
     */
    using getPortInfo_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::tv::cec::V2_0::HdmiPortInfo>& infos)>;
    // @callflow(next="*")
    /**
     * Gets the hdmi port information of underlying hardware.
     * 
     * @return infos The list of HDMI port information
     */
    virtual ::android::hardware::Return<void> getPortInfo(getPortInfo_cb _hidl_cb) = 0;

    // @callflow(next="*")
    /**
     * Sets flags controlling the way HDMI-CEC service works down to HAL
     * implementation. Those flags must be used in case the feature needs update
     * in HAL itself, firmware or microcontroller.
     * 
     * @param key The key of the option to be updated with a new value.
     * @param value Value to be set.
     */
    virtual ::android::hardware::Return<void> setOption(::android::hardware::tv::cec::V2_0::OptionKey key, bool value) = 0;

    // @callflow(next="*")
    /**
     * Passes the updated language information of Android system. Contains
     * three-letter code as defined in ISO/FDIS 639-2. Must be used for HAL to
     * respond to <Get Menu Language> while in standby mode.
     * 
     * @param language Three-letter code defined in ISO/FDIS 639-2. Must be
     *        lowercase letters. (e.g., eng for English)
     */
    virtual ::android::hardware::Return<void> setLanguage(const ::android::hardware::hidl_string& language) = 0;

    // @callflow(next="*")
    /**
     * Configures ARC circuit in the hardware logic to start or stop the
     * feature.
     * 
     * @param portId Port id to be configured.
     * @param enable Flag must be either true to start the feature or false to
     *        stop it.
     */
    virtual ::android::hardware::Return<void> enableAudioReturnChannel(uint32_t portId, bool enable) = 0;

    // @callflow(next="*")
    /**
     * Gets the connection status of the specified port.
     * 
     * It's specified in CEC section 10.8 of the CEC spec 2.0b
     * 
     * @param portId Port id to be inspected for the connection status.
     * @return status True if a device is connected, otherwise false.
     */
    virtual ::android::hardware::Return<bool> isConnected(uint32_t portId) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::tv::cec::V2_0::IHdmiCec>> castFrom(const ::android::sp<::android::hardware::tv::cec::V2_0::IHdmiCec>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::tv::cec::V2_0::IHdmiCec>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IHdmiCec> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IHdmiCec> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IHdmiCec> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IHdmiCec> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IHdmiCec> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IHdmiCec> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IHdmiCec> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IHdmiCec> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::tv::cec::V2_0::IHdmiCec>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::tv::cec::V2_0::IHdmiCec>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::tv::cec::V2_0::IHdmiCec::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V2_0
}  // namespace cec
}  // namespace tv
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_TV_CEC_V2_0_IHDMICEC_H
