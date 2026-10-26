#ifndef HIDL_GENERATED_ANDROID_HARDWARE_POWER_V1_3_IPOWER_H
#define HIDL_GENERATED_ANDROID_HARDWARE_POWER_V1_3_IPOWER_H

#include <android/hardware/power/1.2/IPower.h>
#include <android/hardware/power/1.3/types.h>

#include <android/hidl/manager/1.0/IServiceNotification.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace power {
namespace V1_3 {

struct IPower : public ::android::hardware::power::V1_2::IPower {
    /**
     * Type tag for use in template logic that indicates this is a 'pure' class.
     */
    typedef android::hardware::details::i_tag _hidl_tag;

    /**
     * Fully qualified interface name: "android.hardware.power@1.3::IPower"
     */
    static const char* descriptor;

    /**
     * Returns whether this object's implementation is outside of the current process.
     */
    virtual bool isRemote() const override { return false; }

    /**
     * setInteractive() performs power management actions upon the
     * system entering interactive state (that is, the system is awake
     * and ready for interaction, often with UI devices such as
     * display and touchscreen enabled) or non-interactive state (the
     * system appears asleep, display usually turned off). The
     * non-interactive state may be entered after a period of
     * inactivity in order to conserve battery power during
     * such inactive periods.
     * 
     * Typical actions are to turn on or off devices and adjust
     * cpufreq parameters. This function may also call the
     * appropriate interfaces to allow the kernel to suspend the
     * system to low-power sleep state when entering non-interactive
     * state, and to disallow low-power suspend when the system is in
     * interactive state. When low-power suspend state is allowed, the
     * kernel may suspend the system whenever no wakelocks are held.
     * 
     * For example,
     * This function can be called to enter non-interactive state after
     * turning off the screen (if present) and called to enter
     * interactive state prior to turning on the screen.
     * 
     * @param interactive is true when the system is transitioning to an
     * interactive state and false when transitioning to a
     * non-interactive state.
     */
    virtual ::android::hardware::Return<void> setInteractive(bool interactive) = 0;

    /**
     * powerHint() is called to pass hints on power requirements which
     * may result in adjustment of power/performance parameters of the
     * cpufreq governor and other controls.
     * 
     * A particular platform may choose to ignore any hint.
     * 
     * @param hint PowerHint which is passed
     * @param data contains additional information about the hint
     * and is described along with the comments for each of the hints.
     */
    virtual ::android::hardware::Return<void> powerHint(::android::hardware::power::V1_0::PowerHint hint, int32_t data) = 0;

    /**
     * setFeature() is called to turn on or off a particular feature
     * depending on the state parameter.
     * 
     * @param feature Feature which needs to be set
     * @param activate true/false to enable/disable the feature
     */
    virtual ::android::hardware::Return<void> setFeature(::android::hardware::power::V1_0::Feature feature, bool activate) = 0;

    /**
     * Return callback for getPlatformLowPowerStats
     */
    using getPlatformLowPowerStats_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::power::V1_0::PowerStatePlatformSleepState>& states, ::android::hardware::power::V1_0::Status retval)>;
    /**
     * Platform-level sleep state stats:
     * Report cumulative info on the statistics on platform-level sleep states
     * since boot.
     * 
     * Higher the index in the returned <states> vector deeper the state is
     * i.e. lesser steady-state power is consumed by the platform to be
     * resident in that state.
     * 
     * @return states of power states the device supports
     * @return retval SUCCESS on success or FILESYSTEM_ERROR on filesystem
     * nodes access error.
     */
    virtual ::android::hardware::Return<void> getPlatformLowPowerStats(getPlatformLowPowerStats_cb _hidl_cb) = 0;

    /**
     * Return callback for getSubsystemLowPowerStats
     */
    using getSubsystemLowPowerStats_cb = std::function<void(const ::android::hardware::hidl_vec<::android::hardware::power::V1_1::PowerStateSubsystem>& subsystems, ::android::hardware::power::V1_0::Status retval)>;
    /**
     * Subsystem-level sleep state stats:
     * Report cumulative info on the statistics on subsystem-level sleep states
     * since boot.
     * 
     * @return subsystems supported on this device and their sleep states
     * @return retval SUCCESS on success or FILESYSTEM_ERROR on filesystem
     * nodes access error.
     */
    virtual ::android::hardware::Return<void> getSubsystemLowPowerStats(getSubsystemLowPowerStats_cb _hidl_cb) = 0;

    /**
     * powerHintAsync() is called to pass hints on power requirements which
     * may result in adjustment of power/performance parameters of the
     * cpufreq governor and other controls.
     * 
     * A particular platform may choose to ignore any hint.
     * 
     * @param hint PowerHint which is passed
     * @param data contains additional information about the hint
     * and is described along with the comments for each of the hints.
     */
    virtual ::android::hardware::Return<void> powerHintAsync(::android::hardware::power::V1_0::PowerHint hint, int32_t data) = 0;

    /**
     * called to pass hints on power requirements which
     * may result in adjustment of power/performance parameters of the
     * cpufreq governor and other controls.
     * 
     * A particular platform may choose to ignore any hint.
     * 
     * @param hint PowerHint which is passed
     * @param data contains additional information about the hint
     * and is described along with the comments for each of the hints.
     */
    virtual ::android::hardware::Return<void> powerHintAsync_1_2(::android::hardware::power::V1_2::PowerHint hint, int32_t data) = 0;

    /**
     * Called to pass hints on power requirements which
     * may result in adjustment of power/performance parameters of the
     * cpufreq governor and other controls.
     * 
     * A particular platform may choose to ignore any hint.
     * 
     * @param hint PowerHint which is passed
     * @param data contains additional information about the hint
     *     and is described along with the comments for each of the hints.
     */
    virtual ::android::hardware::Return<void> powerHintAsync_1_3(::android::hardware::power::V1_3::PowerHint hint, int32_t data) = 0;

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
    static ::android::hardware::Return<::android::sp<::android::hardware::power::V1_3::IPower>> castFrom(const ::android::sp<::android::hardware::power::V1_3::IPower>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::power::V1_3::IPower>> castFrom(const ::android::sp<::android::hardware::power::V1_2::IPower>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::power::V1_3::IPower>> castFrom(const ::android::sp<::android::hardware::power::V1_1::IPower>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::power::V1_3::IPower>> castFrom(const ::android::sp<::android::hardware::power::V1_0::IPower>& parent, bool emitError = false);
    /**
     * This performs a checked cast based on what the underlying implementation actually is.
     */
    static ::android::hardware::Return<::android::sp<::android::hardware::power::V1_3::IPower>> castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError = false);

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
    static ::android::sp<IPower> tryGetService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IPower> tryGetService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return tryGetService(str, getStub); }
    /**
     * Deprecated. See tryGetService(std::string, bool)
     */
    static ::android::sp<IPower> tryGetService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return tryGetService(str, getStub); }
    /**
     * Calls tryGetService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IPower> tryGetService(bool getStub) { return tryGetService("default", getStub); }
    /**
     * This gets the service of this type with the specified instance name. If the
     * service is not in the VINTF manifest on a Trebilized device, this will return
     * nullptr. If the service is not available, this will wait for the service to
     * become available. If the service is a lazy service, this will start the service
     * and return when it becomes available. If getStub is true, this will try to
     * return an unwrapped passthrough implementation in the same process. This is
     * useful when getting an implementation from the same partition/compilation group.
     */
    static ::android::sp<IPower> getService(const std::string &serviceName="default", bool getStub=false);
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IPower> getService(const char serviceName[], bool getStub=false)  { std::string str(serviceName ? serviceName : "");      return getService(str, getStub); }
    /**
     * Deprecated. See getService(std::string, bool)
     */
    static ::android::sp<IPower> getService(const ::android::hardware::hidl_string& serviceName, bool getStub=false)  { std::string str(serviceName.c_str());      return getService(str, getStub); }
    /**
     * Calls getService("default", bool). This is the recommended instance name for singleton services.
     */
    static ::android::sp<IPower> getService(bool getStub) { return getService("default", getStub); }
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

static inline std::string toString(const ::android::sp<::android::hardware::power::V1_3::IPower>& o);

//
// type header definitions for package
//

static inline std::string toString(const ::android::sp<::android::hardware::power::V1_3::IPower>& o) {
    std::string os = "[class or subclass of ";
    os += ::android::hardware::power::V1_3::IPower::descriptor;
    os += "]";
    os += o->isRemote() ? "@remote" : "@local";
    return os;
}


}  // namespace V1_3
}  // namespace power
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_POWER_V1_3_IPOWER_H
