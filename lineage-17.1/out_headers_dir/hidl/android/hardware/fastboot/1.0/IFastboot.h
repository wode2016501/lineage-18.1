#ifndef HIDL_GENERATED_ANDROID_HARDWARE_FASTBOOT_V1_0_IFASTBOOT_H
#define HIDL_GENERATED_ANDROID_HARDWARE_FASTBOOT_V1_0_IFASTBOOT_H

#include <android/hardware/fastboot/1.0/types.h>
#include <android/hidl/base/1.0/IBase.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace fastboot {
namespace V1_0 {

/**
 * IFastboot interface implements vendor specific fastboot commands.
 */
struct IFastboot : public ::android::hidl::base::V1_0::IBase {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.fastboot@1.0::IFastboot"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * Return callback for getPartitionType
     */
    using getPartitionType_cb = std::function<void(::android::hardware::fastboot::V1_0::FileSystemType type, const ::android::hardware::fastboot::V1_0::Result& result)>;
    /**
     * Returns the file system type of the partition. This is only required for
     * physical partitions that need to be wiped and reformatted.
     * 
     * @return type Can be ext4, f2fs or raw.
     * @return result SUCCESS if the operation is successful,
     *     FAILURE_UNKNOWN if the partition is invalid or does not require
     *     reformatting.
     */
    virtual ::android::hardware::Return<void> getPartitionType(const ::android::hardware::hidl_string& partitionName, getPartitionType_cb _hidl_cb) = 0;

    /**
     * Return callback for doOemCommand
     */
    using doOemCommand_cb = std::function<void(const ::android::hardware::fastboot::V1_0::Result& result)>;
    /**
     * Executes a fastboot OEM command.
     * 
     * @param oemCmdArgs The oem command that is passed to the fastboot HAL.
     * @return result Returns the status SUCCESS if the operation is successful,
     *     INVALID_ARGUMENT for bad arguments,
     *     FAILURE_UNKNOWN for an invalid/unsupported command.
     */
    virtual ::android::hardware::Return<void> doOemCommand(const ::android::hardware::hidl_string& oemCmd, doOemCommand_cb _hidl_cb) = 0;

    /**
     * Return callback for getVariant
     */
    using getVariant_cb = std::function<void(const ::android::hardware::hidl_string& variant, const ::android::hardware::fastboot::V1_0::Result& result)>;
    /**
     * Returns an OEM-defined string indicating the variant of the device, for
     * example, US and ROW.
     * 
     * @return variant Indicates the device variant.
     * @return result Returns the status SUCCESS if the operation is successful,
     *     FAILURE_UNKNOWN otherwise.
     */
    virtual ::android::hardware::Return<void> getVariant(getVariant_cb _hidl_cb) = 0;

    /**
     * Return callback for getOffModeChargeState
     */
    using getOffModeChargeState_cb = std::function<void(bool state, const ::android::hardware::fastboot::V1_0::Result& result)>;
    /**
     * Returns whether off-mode-charging is enabled. If enabled, the device
     * autoboots into a special mode when power is applied.
     * 
     * @return state Returns whether off mode charging is enabled.
     * @return result Returns the status SUCCESS if the operation is successful,
     *     FAILURE_UNKNOWN otherwise.
     */
    virtual ::android::hardware::Return<void> getOffModeChargeState(getOffModeChargeState_cb _hidl_cb) = 0;

    /**
     * Return callback for getBatteryVoltageFlashingThreshold
     */
    using getBatteryVoltageFlashingThreshold_cb = std::function<void(int32_t batteryVoltage, const ::android::hardware::fastboot::V1_0::Result& result)>;
    /**
     * Returns the minimum battery voltage required for flashing in mV.
     * 
     * @return batteryVoltage Minimum batterery voltage (in mV) required for
     *     flashing to be successful.
     * @return result Returns the status SUCCESS if the operation is successful,
     *     FAILURE_UNKNOWN otherwise.
     */
    virtual ::android::hardware::Return<void> getBatteryVoltageFlashingThreshold(getBatteryVoltageFlashingThreshold_cb _hidl_cb) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::fastboot::V1_0::IFastboot>> castFrom(const ::android::sp<::android::hardware::fastboot::V1_0::IFastboot>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::fastboot::V1_0::IFastboot>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IFastboot> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IFastboot> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IFastboot> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IFastboot> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IFastboot> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IFastboot> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IFastboot> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IFastboot> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::fastboot::V1_0::IFastboot>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::fastboot::V1_0::IFastboot>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::fastboot::V1_0::IFastboot::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_0
}  // namespace fastboot
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_FASTBOOT_V1_0_IFASTBOOT_H
