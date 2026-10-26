#ifndef HIDL_GENERATED_ANDROID_HARDWARE_THERMAL_V1_0_ITHERMAL_H
#define HIDL_GENERATED_ANDROID_HARDWARE_THERMAL_V1_0_ITHERMAL_H

#include <android/hardware/thermal/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace thermal {
namespace V1_0 {

struct IThermal : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.thermal@1.0::IThermal"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getTemperatures
     */
    using getTemperatures_cb = std::function<void(const ::android::hardware::thermal::V1_0::ThermalStatus& status, const ::android::hardware::hidl_vec<::android::hardware::thermal::V1_0::Temperature>& temperatures)>;
    // @callflow(next="*") @entry @exit
    /**
     * Retrieves temperatures in Celsius.
     * 
     * @return status Status of the operation. If status code is FAILURE,
     *         the status.debugMessage must be populated with the human-readable
     *         error message.
     * @return temperatures If status code is SUCCESS, it's filled with the
     *         current temperatures. The order of temperatures of built-in
     *         devices (such as CPUs, GPUs and etc.) in the list must be kept
     *         the same regardless the number of calls to this method even if
     *         they go offline, if these devices exist on boot. The method
     *         always returns and never removes such temperatures.
     * 
     */
    virtual ::android::hardware::Return<void> getTemperatures(getTemperatures_cb _hidl_cb) = 0;

    /**
     * Return callback for getCpuUsages
     */
    using getCpuUsages_cb = std::function<void(const ::android::hardware::thermal::V1_0::ThermalStatus& status, const ::android::hardware::hidl_vec<::android::hardware::thermal::V1_0::CpuUsage>& cpuUsages)>;
    // @callflow(next="*") @entry @exit
    /**
     * Retrieves CPU usage information of each core: active and total times
     * in ms since first boot.
     * 
     * @return status Status of the operation. If status code is FAILURE,
     *         the status.debugMessage must be populated with the human-readable
     *         error message.
     * @return cpuUsages If status code is SUCCESS, it's filled with the current
     *         CPU usages. The order and number of CPUs in the list must be kept
     *         the same regardless the number of calls to this method.
     * 
     */
    virtual ::android::hardware::Return<void> getCpuUsages(getCpuUsages_cb _hidl_cb) = 0;

    /**
     * Return callback for getCoolingDevices
     */
    using getCoolingDevices_cb = std::function<void(const ::android::hardware::thermal::V1_0::ThermalStatus& status, const ::android::hardware::hidl_vec<::android::hardware::thermal::V1_0::CoolingDevice>& devices)>;
    // @callflow(next="*") @entry @exit
    /**
     * Retrieves the cooling devices information.
     * 
     * @return status Status of the operation. If status code is FAILURE,
     *         the status.debugMessage must be populated with the human-readable
     *         error message.
     * @return devices If status code is SUCCESS, it's filled with the current
     *         cooling device information. The order of built-in cooling
     *         devices in the list must be kept the same regardless the number
     *         of calls to this method even if they go offline, if these devices
     *         exist on boot. The method always returns and never removes from
     *         the list such cooling devices.
     * 
     */
    virtual ::android::hardware::Return<void> getCoolingDevices(getCoolingDevices_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::thermal::V1_0::IThermal>> castFrom(const ::android::sp<::android::hardware::thermal::V1_0::IThermal>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::thermal::V1_0::IThermal>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IThermal> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IThermal> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IThermal> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IThermal> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IThermal> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IThermal> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IThermal> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IThermal> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::thermal::V1_0::IThermal>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::thermal::V1_0::IThermal>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::thermal::V1_0::IThermal::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace thermal
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_THERMAL_V1_0_ITHERMAL_H
